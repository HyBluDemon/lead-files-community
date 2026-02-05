CXX      = clang++
BIN      = ./libpoly.a

#CFLAGS   = -m32 -Wall -O2 -pipe -fno-exceptions -fno-rtti
CFLAGS = -m32 -march=i686 -msse2 -g -O1 -pipe -frtti -fexceptions -pthread -D_THREAD_SAFE -fno-stack-protector -fno-strict-aliasing

SRCS     = Base.cc Poly.cc SymTable.cc Symbol.cc
OBJFILES = $(SRCS:.cc=.o)

default: $(BIN)

$(BIN): $(OBJFILES)
	ar cru $(BIN) $(OBJFILES)
	ranlib $(BIN)

clean:
	rm -f *.o $(BIN)

%.o: %.cc
	$(CXX) $(CFLAGS) -c $< -o $@
