
#ifndef VISIBILITY_HEADER
#define VISIBILITY_HEADER

#if defined(__clang__) /* CLANG */
#	define RUBIKS_API __attribute__((visibility("default")))
#elif defined(__GNUC__) || defined(__GNUG__) /* GCC */
#	define RUBIKS_API __attribute__((visibility("default")))
#elif defined(_MSC_VER) /* MSVC */
#	error "Visibility not implemented for MSVC"
#elif defined(__MINGW32__) /* MinGW */
#	error "Visibility not implemented for MinGW"
#endif

#endif /* VISIBILITY_HEADER */
