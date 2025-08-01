
#ifndef ASSERTS_HEADER
#define ASSERTS_HEADER

#include "../../include/Cube.h"




/**
 * The label of each color
 */
#define COLORS_LABEL "BGORWY"


/**
 * Tests if a face is rotated clockwise
 *
 * @param get_face - Face * (* get_face)(Cube const *) -
 * 	function pointer taking the cube and returning the face to check
 *
 * @param apply_rotation - void (* apply_rotation)(Cube *) -
 * 	function pointer to the rotation to apply, taking the cube as
 * 	argument and returning nothing
 *
 * @param failure_message - char const * failure_message -
 * 	the error message to print on failure, expected/actual face content
 * 	will be added
 */
#define test_face_rotated_clockwise( \
		get_face, \
		apply_rotation, \
		failure_message) \
	do { \
		/* given */ \
		Cube * cube = createScrambledCube(); \
		Face * face = get_face(cube); \
		Color before_rotation[FACE_SIZE][FACE_SIZE]; \
		readFace(face, before_rotation); \
		\
		/* when */ \
		apply_rotation(cube); \
		\
		/* then */ \
		Color expected_after_rotation[FACE_SIZE][FACE_SIZE] = \
		{ \
			{ before_rotation[2][0], before_rotation[1][0], before_rotation[0][0] }, \
			{ before_rotation[2][1], before_rotation[1][1], before_rotation[0][1] }, \
			{ before_rotation[2][2], before_rotation[1][2], before_rotation[0][2] } \
		}; \
		Color actual_after_rotation[FACE_SIZE][FACE_SIZE]; \
		readFace(face, actual_after_rotation); \
		cr_assert_arr_eq( \
			expected_after_rotation, \
			actual_after_rotation, \
			FACE_SIZE * FACE_SIZE * sizeof(Color), \
			"%s clockwise\n" \
			"          [%c,%c,%c]          [%c,%c,%c]\n" \
			"expected: [%c,%c,%c], actual: [%c,%c,%c]\n" \
			"          [%c,%c,%c]          [%c,%c,%c]", \
			failure_message, \
			COLORS_LABEL[ expected_after_rotation[0][0] ], \
			COLORS_LABEL[ expected_after_rotation[0][1] ], \
			COLORS_LABEL[ expected_after_rotation[0][2] ], \
			COLORS_LABEL[ actual_after_rotation[0][0] ], \
			COLORS_LABEL[ actual_after_rotation[0][1] ], \
			COLORS_LABEL[ actual_after_rotation[0][2] ], \
			COLORS_LABEL[ expected_after_rotation[1][0] ], \
			COLORS_LABEL[ expected_after_rotation[1][1] ], \
			COLORS_LABEL[ expected_after_rotation[1][2] ], \
			COLORS_LABEL[ actual_after_rotation[1][0] ], \
			COLORS_LABEL[ actual_after_rotation[1][1] ], \
			COLORS_LABEL[ actual_after_rotation[1][2] ], \
			COLORS_LABEL[ expected_after_rotation[2][0] ], \
			COLORS_LABEL[ expected_after_rotation[2][1] ], \
			COLORS_LABEL[ expected_after_rotation[2][2] ], \
			COLORS_LABEL[ actual_after_rotation[2][0] ], \
			COLORS_LABEL[ actual_after_rotation[2][1] ], \
			COLORS_LABEL[ actual_after_rotation[2][2] ]); \
	} while (0)


/**
 * Tests if a face is rotated anticlockwise
 *
 * @param get_face - Face * (* get_face)(Cube const *) -
 * 	function pointer taking the cube and returning the face to check
 *
 * @param apply_rotation - void (* apply_rotation)(Cube *) -
 * 	function pointer to the rotation to apply, taking the cube as
 * 	argument and returning nothing
 *
 * @param failure_message - char const * failure_message -
 * 	the error message to print on failure, expected/actual face content
 * 	will be added
 */
#define test_face_rotated_anticlockwise( \
		get_face, \
		apply_rotation, \
		failure_message) \
	do { \
		/* given */ \
		Cube * cube = createScrambledCube(); \
		Face * face = get_face(cube); \
		Color before_rotation[FACE_SIZE][FACE_SIZE]; \
		readFace(face, before_rotation); \
		\
		/* when */ \
		apply_rotation(cube); \
		\
		/* then */ \
		Color expected_after_rotation[FACE_SIZE][FACE_SIZE] = \
		{ \
			{ before_rotation[0][2], before_rotation[1][2], before_rotation[2][2] }, \
			{ before_rotation[0][1], before_rotation[1][1], before_rotation[2][1] }, \
			{ before_rotation[0][0], before_rotation[1][0], before_rotation[2][0] } \
		}; \
		Color actual_after_rotation[FACE_SIZE][FACE_SIZE]; \
		readFace(face, actual_after_rotation); \
		cr_assert_arr_eq( \
			expected_after_rotation, \
			actual_after_rotation, \
			FACE_SIZE * FACE_SIZE * sizeof(Color), \
			"%s anticlockwise\n" \
			"          [%c,%c,%c]          [%c,%c,%c]\n" \
			"expected: [%c,%c,%c], actual: [%c,%c,%c]\n" \
			"          [%c,%c,%c]          [%c,%c,%c]", \
			failure_message, \
			COLORS_LABEL[ expected_after_rotation[0][0] ], \
			COLORS_LABEL[ expected_after_rotation[0][1] ], \
			COLORS_LABEL[ expected_after_rotation[0][2] ], \
			COLORS_LABEL[ actual_after_rotation[0][0] ], \
			COLORS_LABEL[ actual_after_rotation[0][1] ], \
			COLORS_LABEL[ actual_after_rotation[0][2] ], \
			COLORS_LABEL[ expected_after_rotation[1][0] ], \
			COLORS_LABEL[ expected_after_rotation[1][1] ], \
			COLORS_LABEL[ expected_after_rotation[1][2] ], \
			COLORS_LABEL[ actual_after_rotation[1][0] ], \
			COLORS_LABEL[ actual_after_rotation[1][1] ], \
			COLORS_LABEL[ actual_after_rotation[1][2] ], \
			COLORS_LABEL[ expected_after_rotation[2][0] ], \
			COLORS_LABEL[ expected_after_rotation[2][1] ], \
			COLORS_LABEL[ expected_after_rotation[2][2] ], \
			COLORS_LABEL[ actual_after_rotation[2][0] ], \
			COLORS_LABEL[ actual_after_rotation[2][1] ], \
			COLORS_LABEL[ actual_after_rotation[2][2] ]); \
	} while (0)


/**
 * The name of each color
 */
#define COLORS_NAME \
	(char const * []) { \
		[BLUE] = "BLUE", \
		[GREEN] = "GREEN", \
		[ORANGE] = "ORANGE", \
		[RED] = "RED", \
		[WHITE] = "WHITE", \
		[YELLOW] = "YELLOW", \
	}


/**
 * Tests if a span moves to the correct position
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
#define test_span_moved( \
		get_source_face, \
		read_source_span, \
		apply_slice_rotation, \
		get_destination_face, \
		read_destination_span, \
		failure_message) \
	do { \
		/* given */ \
		Cube * cube = Cube_create(); \
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
			"%s, expected %s span on dest but got %s span", \
			failure_message, \
			COLORS_NAME[source_span[0]], \
			COLORS_NAME[destination_span[0]]); \
	} while (0)


/**
 * Tests if a span moves to the correct position with the same cells
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
 * Tests if a span moves to the correct position with the reverse cells
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
