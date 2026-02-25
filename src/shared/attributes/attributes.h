
#ifndef LIB_RUBIKS_CORE_INTERNAL_ATTRIBUTES_HEADER
#define LIB_RUBIKS_CORE_INTERNAL_ATTRIBUTES_HEADER


#if defined(__GNUC__) || defined(__GNUG__)
#   include "gcc.h"
#elif defined(__clang__)
#   include "clang.h"
#elif defined(_MSC_VER)
#   include "msvc.h"
#elif defined(__MINGW32__)
#   include "mingw.h"
#else
#   error "Unknown compiler"
#endif


#endif /* LIB_RUBIKS_CORE_INTERNAL_ATTRIBUTES_HEADER */
