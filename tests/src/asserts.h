
#ifndef ASSERTS_HEADER
#define ASSERTS_HEADER

#include "../../include/Cube.h"




#define assert_faceRotatedClockwise(a,b,c) _assert_faceRotatedClockwise((a), (b), (c), __FILE__, __LINE__)
void _assert_faceRotatedClockwise(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line);


#define assert_faceRotatedAnticlockwise(a,b,c) _assert_faceRotatedAnticlockwise((a), (b), (c), __FILE__, __LINE__)
void _assert_faceRotatedAnticlockwise(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line);




#endif /* ASSERTS_HEADER */
