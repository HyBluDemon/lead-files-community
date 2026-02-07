import os
import platform
import subprocess
import sys
import shutil
import argparse
import glob

VERSIONS = {
    "MARIADB": {
        "ver": "3.3.8",
        "url": "https://downloads.mariadb.com/Connectors/c/connector-c-3.3.8/mariadb-connector-c-3.3.8-src.tar.gz"
    },
    "PNG": {
        "ver": "1.6.40",
        "url": "https://download.sourceforge.net/libpng/libpng-1.6.40.tar.gz"
    },
    "JPEG": {
        "ver": "3.0.1",
        "url": "https://download.sourceforge.net/libjpeg-turbo/libjpeg-turbo-3.0.1.tar.gz"
    },
    "DEVIL": {
        "ver": "1.8.0",
        "url": "https://github.com/DentonW/DevIL/archive/refs/tags/v1.8.0.tar.gz"
    },
    "CRYPTOPP": {
        "ver": "8.9.0",
        "url": "https://github.com/weidai11/cryptopp/archive/refs/tags/CRYPTOPP_8_9_0.tar.gz"
    }
}

BASE_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), "../../"))
EXTERN_DIR = os.path.join(BASE_DIR, "Lead-Extern")
EXTERN_LIB = os.path.join(EXTERN_DIR, "lib")
EXTERN_INC = os.path.join(EXTERN_DIR, "include")
TMP_DIR = "/tmp/metin2_extern_build"
CPU_COUNT = os.cpu_count() or 1

def run_command(cmd, env=None):
    result = subprocess.run(cmd, env=env)
    if result.returncode != 0:
        sys.exit(1)

def cleanup_tmp():
    if os.path.exists(TMP_DIR):
        shutil.rmtree(TMP_DIR)
    os.makedirs(TMP_DIR, exist_ok=True)

def move_headers(src_dir, lib_subdir):
    dest = os.path.join(EXTERN_INC, lib_subdir)
    os.makedirs(dest, exist_ok=True)
    for root, dirs, files in os.walk(src_dir):
        for file in files:
            if file.endswith((".h", ".hpp", ".inc")):
                shutil.copy(os.path.join(root, file), dest)

def get_dir(pattern):
    for entry in glob.glob(pattern):
        if os.path.isdir(entry):
            return entry
    return None

def build_mariadb():
    data = VERSIONS["MARIADB"]
    os.chdir(TMP_DIR)
    archive = os.path.basename(data["url"])
    run_command(["wget", data["url"]])
    run_command(["tar", "-xf", archive])
    src = get_dir("mariadb-connector-c-*-src")
    cmake_file = os.path.join(src, "CMakeLists.txt")
    with open(cmake_file, "r") as f: lines = f.readlines()
    with open(cmake_file, "w") as f:
        for line in lines:
            if "CMAKE_MINIMUM_REQUIRED" in line.upper(): f.write("CMAKE_MINIMUM_REQUIRED(VERSION 3.5)\n")
            else: f.write(line)
    bld = os.path.join(src, "build")
    os.makedirs(bld, exist_ok=True)
    os.chdir(bld)
    run_command([
        "cmake", "..",
        "-DCMAKE_C_FLAGS=-m32 -fPIC -Wno-error=deprecated-non-prototype -Wno-deprecated-non-prototype",
        "-DCMAKE_POSITION_INDEPENDENT_CODE=ON",
        "-DSTATIC_LIB=ON", "-DBUILD_SHARED_LIBS=OFF", "-DWITH_SSL=OPENSSL",
        "-DOPENSSL_ROOT_DIR=/usr/lib32", "-DWITH_UNIT_TESTS=OFF", "-DWITH_MYSQLCOMPAT=ON"
    ])
    run_command(["make", f"-j{CPU_COUNT}", "mariadbclient"])
    shutil.copy("libmariadb/libmariadbclient.a", os.path.join(EXTERN_LIB, "mysqlclient.a"))
    move_headers(os.path.join("..", "include"), "mysql")
    move_headers(os.path.join(".", "include"), "mysql")

def build_png():
    data = VERSIONS["PNG"]
    os.chdir(TMP_DIR)
    archive = os.path.basename(data["url"])
    run_command(["wget", data["url"]])
    run_command(["tar", "-xf", archive])
    src = get_dir("libpng-*")
    os.chdir(src)
    run_command(["./configure", "CFLAGS=-m32 -fPIC -Wno-error", "LDFLAGS=-m32", "--enable-static", "--disable-shared", f"--prefix={TMP_DIR}/png_out"])
    run_command(["gmake", f"-j{CPU_COUNT}"])
    run_command(["gmake", "install"])
    shutil.copy(os.path.join(TMP_DIR, "png_out", "lib", "libpng16.a"), os.path.join(EXTERN_LIB, "libpng.a"))
    move_headers(os.path.join(TMP_DIR, "png_out", "include"), "libpng")

def build_jpeg():
    data = VERSIONS["JPEG"]
    os.chdir(TMP_DIR)
    archive = os.path.basename(data["url"])
    run_command(["wget", data["url"]])
    run_command(["tar", "-xf", archive])
    src = get_dir("libjpeg-turbo-*")
    os.chdir(src)
    os.makedirs("build", exist_ok=True)
    os.chdir("build")
    run_command([
        "cmake", "..", 
        "-DCMAKE_C_FLAGS=-m32 -fPIC", 
        "-DCMAKE_POSITION_INDEPENDENT_CODE=ON",
        "-DENABLE_SHARED=OFF", 
        f"-DCMAKE_INSTALL_PREFIX={TMP_DIR}/jpeg_out"
    ])
    run_command(["make", f"-j{CPU_COUNT}", "install"])
    shutil.copy(os.path.join(TMP_DIR, "jpeg_out", "lib", "libjpeg.a"), os.path.join(EXTERN_LIB, "libjpeg-turbo.a"))
    move_headers(os.path.join(TMP_DIR, "jpeg_out", "include"), "libjpeg-turbo")

def build_devil():
    data = VERSIONS["DEVIL"]
    os.chdir(TMP_DIR)
    archive = f"DevIL-{data['ver']}.tar.gz"
    run_command(["wget", data["url"], "-O", archive])
    run_command(["tar", "-xf", archive])
    root_src = get_dir("DevIL-*")
    src = os.path.join(TMP_DIR, root_src, "DevIL")
    os.chdir(src)
    bld = os.path.join(src, "build")
    os.makedirs(bld, exist_ok=True)
    os.chdir(bld)
    cmake_cmd = [
        "cmake", "..",
        "-DCMAKE_C_FLAGS=-m32 -fPIC -I" + os.path.join(EXTERN_INC, "libpng") + " -I" + os.path.join(EXTERN_INC, "libjpeg-turbo"),
        "-DCMAKE_CXX_FLAGS=-m32 -fPIC -Wno-everything -I" + os.path.join(EXTERN_INC, "libpng") + " -I" + os.path.join(EXTERN_INC, "libjpeg-turbo"),
        "-DCMAKE_POSITION_INDEPENDENT_CODE=ON",
        "-DBUILD_SHARED_LIBS=OFF",
        "-DILU_ENABLED=OFF", "-DILUT_ENABLED=OFF",
        "-DIL_NO_EXR=ON", "-DIL_NO_LCMS=ON", "-DIL_NO_MNG=ON", "-DIL_NO_TIFF=ON", "-DIL_NO_JP2=ON", "-DIL_NO_SQUISH=ON",
        f"-DCMAKE_INSTALL_PREFIX={TMP_DIR}/devil_out",
        f"-DPNG_LIBRARY={EXTERN_LIB}/libpng.a",
        f"-DPNG_PNG_INCLUDE_DIR={EXTERN_INC}/libpng",
        f"-DJPEG_LIBRARY={EXTERN_LIB}/libjpeg-turbo.a",
        f"-DJPEG_INCLUDE_DIR={EXTERN_INC}/libjpeg-turbo",
        "-DCMAKE_IGNORE_PATH=/usr/local/lib;/usr/lib;/usr/local/include;/usr/include"
    ]
    run_command(cmake_cmd)
    run_command(["make", f"-j{CPU_COUNT}", "install"])
    shutil.copy(os.path.join(TMP_DIR, "devil_out", "lib", "libIL.a"), os.path.join(EXTERN_LIB, "libIL.a"))
    move_headers(os.path.join(TMP_DIR, "devil_out", "include"), "IL")

def build_cryptopp():
    data = VERSIONS["CRYPTOPP"]
    os.chdir(TMP_DIR)
    archive = os.path.basename(data["url"])
    run_command(["wget", data["url"]])
    run_command(["tar", "-xf", archive])
    src = get_dir("cryptopp-CRYPTOPP_*")
    os.chdir(src)
    run_command(["gmake", "static", "CXXFLAGS=-m32 -fPIC -O2 -Wno-everything", f"-j{CPU_COUNT}"])
    shutil.copy("libcryptopp.a", os.path.join(EXTERN_LIB, "libcryptopp.a"))
    move_headers(".", "cryptopp")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--skip", nargs='+', choices=['mariadb', 'png', 'jpeg', 'devil', 'cryptopp'])
    parser.add_argument("--only", choices=['mariadb', 'png', 'jpeg', 'devil', 'cryptopp'])
    args = parser.parse_args()
    if platform.system() != "FreeBSD" or os.getuid() != 0:
        sys.exit(1)
    os.makedirs(EXTERN_LIB, exist_ok=True)
    os.makedirs(EXTERN_INC, exist_ok=True)
    run_command(["pkg", "install", "-y", "cmake", "openssl", "gmake", "pkgconf", "wget", "libtool"])
    cleanup_tmp()
    try:
        targets = []
        if args.only: targets = [args.only]
        else:
            skip = args.skip if args.skip else []
            if 'mariadb' not in skip: targets.append('mariadb')
            if 'png' not in skip: targets.append('png')
            if 'jpeg' not in skip: targets.append('jpeg')
            if 'devil' not in skip: targets.append('devil')
            if 'cryptopp' not in skip: targets.append('cryptopp')
        for t in targets:
            if t == 'mariadb': build_mariadb()
            elif t == 'png': build_png()
            elif t == 'jpeg': build_jpeg()
            elif t == 'devil': build_devil()
            elif t == 'cryptopp': build_cryptopp()
    finally:
        cleanup_tmp()
