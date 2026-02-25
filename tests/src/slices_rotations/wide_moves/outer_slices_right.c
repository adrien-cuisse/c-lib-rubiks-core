
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateOuterSlicesRight_frontFaceTopRow_movesTo_rightFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, top_row,
		rubiks_cube_rotate_outer_slices_right,
		rubiks_cube_right_face, top_row,
		"front face top row wasn't moved to the right face top row");
}


Test(Cube, rotateOuterSlicesRight_frontFaceBottomRow_movesTo_rightFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, bottom_row,
		rubiks_cube_rotate_outer_slices_right,
		rubiks_cube_right_face, bottom_row,
		"front face bottom row wasn't moved to the right face bottom row");
}


Test(Cube, rotateOuterSlicesRight_rightFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, top_row,
		rubiks_cube_rotate_outer_slices_right,
		rubiks_cube_back_face, bottom_row,
		"right face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateOuterSlicesRight_rightFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, bottom_row,
		rubiks_cube_rotate_outer_slices_right,
		rubiks_cube_back_face, top_row,
		"right face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateOuterSlicesRight_backFaceBottomRow_movesTo_leftFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_back_face, bottom_row,
		rubiks_cube_rotate_outer_slices_right,
		rubiks_cube_left_face, top_row,
		"back face bottom row wasn't moved to the left face top row");
}


Test(Cube, rotateOuterSlicesRight_backFaceTopRow_movesTo_leftFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_back_face, top_row,
		rubiks_cube_rotate_outer_slices_right,
		rubiks_cube_left_face, bottom_row,
		"back face top row wasn't moved to the left face bottom row");
}


Test(Cube, rotateOuterSlicesRight_leftFaceTopRow_movesTo_frontFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_left_face, top_row,
		rubiks_cube_rotate_outer_slices_right,
		rubiks_cube_front_face, top_row,
		"left face top row wasn't moved to the front face top row");
}


Test(Cube, rotateOuterSlicesRight_leftFaceBottomRow_movesTo_frontFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_left_face, bottom_row,
		rubiks_cube_rotate_outer_slices_right,
		rubiks_cube_front_face, bottom_row,
		"left face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateOuterSlicesRight_topFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rubiks_cube_top_face,
		rubiks_cube_rotate_outer_slices_right,
		"top face wasn't rotated");
}


Test(Cube, rotateOuterSlicesRight_bottomFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_bottom_face,
		rubiks_cube_rotate_outer_slices_right,
		"bottom face wasn't rotated");
}
