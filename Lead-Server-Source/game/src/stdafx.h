#pragma once

// Basic features
#include "debug_allocator.h"

#include "../../libthecore/include/stdafx.h"

#include "common/singleton.h"
#include "common/utils.h"
#include "common/service.h"

#include <algorithm>
#include <math.h>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <float.h>

#ifdef __GNUC__
    #define TR1_NS std
#else
    #include <boost/unordered_map.hpp>
    #include <boost/unordered_set.hpp>
    #define TR1_NS boost
    #define isdigit iswdigit
    #define isspace iswspace
#endif

#include "typedef.h"
#include "locale.hpp"
#include "event.h"

#define PASSES_PER_SEC(sec) ((sec) * passes_per_sec)

#ifndef M_PI
#define M_PI    3.14159265358979323846 /* pi */
#endif
#ifndef M_PI_2
#define M_PI_2  1.57079632679489661923 /* pi/2 */
#endif

#define IN
#define OUT

#ifndef __WIN32__
extern "C" {
    inline FILE* __iob_func(void) {
        static FILE* iob[3] = { stdin, stdout, stderr };
        return iob[0];
    }
} 
#endif
