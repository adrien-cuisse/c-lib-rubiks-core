
#include "../../include/Cube.h"




struct rbc_cube * create_scrambled_cube(void)
{
	struct rbc_cube * cube = rubiks_cube_create();

	// official terminology:
	// D2 F2 R2 D2 L2 U F2 U' F' U F2 U' R2 B' F R' D2 F' D' L
	//
	// D2
	rubiks_cube_rotate_bottom_slice_right(cube);
	rubiks_cube_rotate_bottom_slice_right(cube);
	// F2
	rubiks_cube_rotate_front_slice_clockwise(cube);
	rubiks_cube_rotate_front_slice_clockwise(cube);
	// R2
	rubiks_cube_rotate_right_slice_up(cube);
	rubiks_cube_rotate_right_slice_up(cube);
	// D2
	rubiks_cube_rotate_bottom_slice_right(cube);
	rubiks_cube_rotate_bottom_slice_right(cube);
	// L2
	rubiks_cube_rotate_left_slice_down(cube);
	rubiks_cube_rotate_left_slice_down(cube);
	// U
	rubiks_cube_rotate_top_slice_left(cube);
	// F2
	rubiks_cube_rotate_front_slice_clockwise(cube);
	rubiks_cube_rotate_front_slice_clockwise(cube);
	// U'
	rubiks_cube_rotate_top_slice_right(cube);
	// F'
	rubiks_cube_rotate_front_slice_anticlockwise(cube);
	// U
	rubiks_cube_rotate_top_slice_left(cube);
	// F2
	rubiks_cube_rotate_front_slice_clockwise(cube);
	rubiks_cube_rotate_front_slice_clockwise(cube);
	// U'
	rubiks_cube_rotate_top_slice_right(cube);
	// R2
	rubiks_cube_rotate_right_slice_up(cube);
	rubiks_cube_rotate_right_slice_up(cube);
	// B'
	rubiks_cube_rotate_back_slice_clockwise(cube);
	// F
	rubiks_cube_rotate_front_slice_clockwise(cube);
	// R'
	rubiks_cube_rotate_right_slice_down(cube);
	// D2
	rubiks_cube_rotate_bottom_slice_right(cube);
	rubiks_cube_rotate_bottom_slice_right(cube);
	// F'
	rubiks_cube_rotate_front_slice_anticlockwise(cube);
	// D'
	rubiks_cube_rotate_bottom_slice_left(cube);
	// L
	rubiks_cube_rotate_left_slice_down(cube);

	//	+-------+-------+-------+
	//	| G W Y | R Y W | R W B |
	//	| B R O | W B G | Y O G |
	//	| O Y G | Y R O | W B Y |
	//	+-------+-------+-------+
	//			| O W G |
	//			| R Y R |
	//			| B G O |
	//			+-------+
	//			| W R B |
	//			| Y G O |
	//			| W B R |
	//			+-------+
	//			| R O Y |
	//			| B W G |
	//			| G O B |
	//			+-------+

	//			+-------+
	//			| R O Y |
	//			| B W G |
	//			| G O B |
	//	+-------+-------+-------+-------+
	//	| G W Y | R Y W | R W B | R B W |
	//	| B R O | W B G | Y O G | O G Y |
	//	| O Y G | Y R O | W B Y | B R W |
	//	+-------+-------+-------+-------+
	//			| O W G |
	//			| R Y R |
	//			| B G O |
	//			+-------+

	return cube;
}


void top_row(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE])
{
	buffer[0] = rubiks_face_top_left_cell(face);
	buffer[1] = rubiks_face_top_center_cell(face);
	buffer[2] = rubiks_face_top_right_cell(face);
}


void equator_row(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE])
{
	buffer[0] = rubiks_face_equator_left_cell(face);
	buffer[1] = rubiks_face_equator_center_cell(face);
	buffer[2] = rubiks_face_equator_right_cell(face);
}


void bottom_row(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE])
{
	buffer[0] = rubiks_face_bottom_left_cell(face);
	buffer[1] = rubiks_face_bottom_center_cell(face);
	buffer[2] = rubiks_face_bottom_right_cell(face);
}


void left_column(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE])
{
	buffer[0] = rubiks_face_top_left_cell(face);
	buffer[1] = rubiks_face_equator_left_cell(face);
	buffer[2] = rubiks_face_bottom_left_cell(face);
}


void middle_column(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE])
{
	buffer[0] = rubiks_face_top_center_cell(face);
	buffer[1] = rubiks_face_equator_center_cell(face);
	buffer[2] = rubiks_face_bottom_center_cell(face);
}


void right_column(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE])
{
	buffer[0] = rubiks_face_top_right_cell(face);
	buffer[1] = rubiks_face_equator_right_cell(face);
	buffer[2] = rubiks_face_bottom_right_cell(face);
}


void read_face(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE][FACE_SIZE])
{
	top_row(face, buffer[0]);
	equator_row(face, buffer[1]);
	bottom_row(face, buffer[2]);
}


void reverse_span(enum rbc_color buffer[FACE_SIZE])
{
	enum rbc_color swap = buffer[0];
	buffer[0] = buffer[2];
	buffer[2] = swap;
}
