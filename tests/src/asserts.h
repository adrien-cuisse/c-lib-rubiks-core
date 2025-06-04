
#ifndef ASSERTS_HEADER
#define ASSERTS_HEADER

#include "../../include/Cube.h"



/**
 * Asserts that the [face] has been rotated clockwise
 *
 * @param faceBeforeRotation - the 2D array of cells, before rotation
 *
 * @param face - the actual face object
 *
 * @param faceLabel - either "top", "front", "bottom", "back", "left" or "right"
 *
 */
#define assert_faceRotatedClockwise(faceBeforeRotation, face, faceLabel) \
	_assert_faceRotatedClockwise( \
		(faceBeforeRotation), \
		(face), \
		(faceLabel), \
		__FILE__, \
		__LINE__)
void _assert_faceRotatedClockwise(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line);


/**
 * Asserts that the [face] has been rotated anticlockwise
 *
 * @param faceBeforeRotation - the 2D array of cells, before rotation
 *
 * @param face - the actual face object
 *
 * @param faceLabel - either "top", "front", "bottom", "back", "left" or "right"
 */
#define assert_faceRotatedAnticlockwise(faceBeforeRotation, face, faceLabel) \
	_assert_faceRotatedAnticlockwise( \
		(faceBeforeRotation), \
		(face), \
		(faceLabel), \
		__FILE__, \
		__LINE__)
void _assert_faceRotatedAnticlockwise(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line);


/**
 * Asserts that the [face] has been flipped (ie., rotated twice)
 *
 * @param faceBeforeRotation - the 2D array of cells, before rotation
 *
 * @param face - the actual face object
 *
 * @param faceLabel - either "top", "front", "bottom", "back", "left" or "right"
 */
#define assert_faceFlipped(faceBeforeRotation, face, faceLabel) \
	_assert_faceFlipped( \
		(faceBeforeRotation), \
		(face), \
		(faceLabel), \
		__FILE__, \
		__LINE__)
void _assert_faceFlipped(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line);




#endif /* ASSERTS_HEADER */
