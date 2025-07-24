
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


/**
 * The labels of each color
 */
#define COLORS_LABEL \
	(Color[]) { \
		[BLUE] = 'B', \
		[GREEN] = 'G', \
		[ORANGE] = 'O', \
		[RED] = 'R', \
		[WHITE] = 'W', \
		[YELLOW] = 'Y', \
	}


/**
 * Tests if a span has been moved to the correct position with the same cells
 * 	order (rows are from left to right, columns are from top to bottom)
 *
 * @param get_source_face - Face * (* get_source_face)(Cube const *) -
 * 	function pointer taking the cube and returning the face where the span is
 * 	before applying the rotation
 *
 * @param read_source_span - void (* read_source_span)(Face const *, Color[FACE_SIZE]) -
 * 	function pointer taking the face where the span is before applying the
 * 	rotation, and the buffer to write the span content in, and returning nothing
 *
 * @param apply_slice_rotation - void (* apply_slice_rotation)(Cube *) -
 * 	function pointer to the slice rotation to apply, taking the cube as
 * 	argument and returning nothing
 *
 * @param get_destination_face - Face * (* get_destination_face)(Cube const *) -
 * 	function pointer taking the cube and returning the face where the span
 * 	should be after applying the rotation
 *
 * @param read_destination_span - void (* read_destination_span)(Face const *, Color[FACE_SIZE]) -
 * 	function pointer taking the face where the span is after applying the
 * 	rotation, and the buffer to write the span content in, and returning nothing
 *
 * @param failure_message - char const * failure_message -
 * 	the error message to print on failure, spans content will be added
 */
#define test_span_moved_and_not_reversed( \
		get_source_face, \
		read_source_span, \
		apply_slice_rotation, \
		get_destination_face, \
		read_destination_span, \
		failure_message) \
	do { \
		/* given */ \
		Cube * cube = createScrambledCube(); \
		Face * source_face = get_source_face(cube); \
		Color source_span[FACE_SIZE]; \
		read_source_span(source_face, source_span); \
		\
		/* when */ \
		apply_slice_rotation(cube); \
		\
		/* then */ \
		Face * destination_face = get_destination_face(cube); \
		Color destination_span[FACE_SIZE]; \
		read_destination_span(destination_face, destination_span); \
		cr_assert_arr_eq( \
			source_span, \
			destination_span, \
			FACE_SIZE * sizeof(Color), \
			"%s, expected dest=[%c,%c,%c] but got dest=[%c,%c,%c]", \
			failure_message, \
			COLORS_LABEL[source_span[0]], \
			COLORS_LABEL[source_span[1]], \
			COLORS_LABEL[source_span[2]], \
			COLORS_LABEL[destination_span[0]], \
			COLORS_LABEL[destination_span[1]], \
			COLORS_LABEL[destination_span[2]]); \
	} while (0)


/**
 * Tests if a span has been moved to the correct position with the reverse
 * 	cells order (rows are from left to right, columns are from top to bottom)
 *
 * @param get_source_face - Face * (* get_source_face)(Cube const *) -
 * 	function pointer taking the cube and returning the face where the span is
 * 	before applying the rotation
 *
 * @param read_source_span - void (* read_source_span)(Face const *, Color[FACE_SIZE]) -
 * 	function pointer taking the face where the span is before applying the
 * 	rotation, and the buffer to write the span content in, and returning nothing
 *
 * @param apply_slice_rotation - void (* apply_slice_rotation)(Cube *) -
 * 	function pointer to the slice rotation to apply, taking the cube as
 * 	argument and returning nothing
 *
 * @param get_destination_face - Face * (* get_destination_face)(Cube const *) -
 * 	function pointer taking the cube and returning the face where the span
 * 	should be after applying the rotation
 *
 * @param read_destination_span - void (* read_destination_span)(Face const *, Color[FACE_SIZE]) -
 * 	function pointer taking the face where the span is after applying the
 * 	rotation, and the buffer to write the span content in, and returning nothing
 *
 * @param failure_message - char const * failure_message -
 * 	the error message to print on failure, spans content will be added
 */
#define test_span_moved_and_reversed( \
		get_source_face, \
		read_source_span, \
		apply_slice_rotation, \
		get_destination_face, \
		read_destination_span, \
		failure_message) \
	do { \
		/* given */ \
		Cube * cube = createScrambledCube(); \
		Face * source_face = get_source_face(cube); \
		Color source_span[FACE_SIZE]; \
		read_source_span(source_face, source_span); \
		reverseSpan(source_span); \
		\
		/* when */ \
		apply_slice_rotation(cube); \
		\
		/* then */ \
		Face * destination_face = get_destination_face(cube); \
		Color destination_span[FACE_SIZE]; \
		read_destination_span(destination_face, destination_span); \
		cr_assert_arr_eq( \
			source_span, \
			destination_span, \
			FACE_SIZE * sizeof(Color), \
			"%s (reversed), expected dest=[%c,%c,%c] but got dest=[%c,%c,%c]", \
			failure_message, \
			COLORS_LABEL[source_span[0]], \
			COLORS_LABEL[source_span[1]], \
			COLORS_LABEL[source_span[2]], \
			COLORS_LABEL[destination_span[0]], \
			COLORS_LABEL[destination_span[1]], \
			COLORS_LABEL[destination_span[2]]); \
	} while (0)




#endif /* ASSERTS_HEADER */
