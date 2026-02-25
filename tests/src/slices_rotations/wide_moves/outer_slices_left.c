
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateOuterSlicesLeft_frontFaceTopRow_movesTo_leftFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, top_row,
		rbc_rotate_cube_outer_slices_left,
		rbc_cube_left_face, top_row,
		"front face top row wasn't moved to the left face top row");
}


Test(Cube, rotateOuterSlicesLeft_frontFaceBottomRow_movesTo_leftFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, bottom_row,
		rbc_rotate_cube_outer_slices_left,
		rbc_cube_left_face, bottom_row,
		"front face bottom row wasn't moved to the left face bottom row");
}


Test(Cube, rotateOuterSlicesLeft_leftFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_left_face, top_row,
		rbc_rotate_cube_outer_slices_left,
		rbc_cube_back_face, bottom_row,
		"left face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateOuterSlicesLeft_leftFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_left_face, bottom_row,
		rbc_rotate_cube_outer_slices_left,
		rbc_cube_back_face, top_row,
		"left face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateOuterSlicesLeft_backFaceBottomRow_movesTo_rightFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_back_face, bottom_row,
		rbc_rotate_cube_outer_slices_left,
		rbc_cube_right_face, top_row,
		"back face bottom row wasn't moved to the right face top row");
}


Test(Cube, rotateOuterSlicesLeft_backFaceTopRow_movesTo_rightFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_back_face, top_row,
		rbc_rotate_cube_outer_slices_left,
		rbc_cube_right_face, bottom_row,
		"back face top row wasn't moved to the right face bottom row");
}


Test(Cube, rotateOuterSlicesLeft_rightFaceTopRow_movesTo_frontFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_right_face, top_row,
		rbc_rotate_cube_outer_slices_left,
		rbc_cube_front_face, top_row,
		"right face top row wasn't moved to the front face top row");
}


Test(Cube, rotateOuterSlicesLeft_rightFaceBottomRow_movesTo_frontFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_right_face, bottom_row,
		rbc_rotate_cube_outer_slices_left,
		rbc_cube_front_face, bottom_row,
		"right face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateOuterSlicesLeft_topFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rbc_cube_top_face,
		rbc_rotate_cube_outer_slices_left,
		"top face wasn't rotated");
}


Test(Cube, rotateOuterSlicesLeft_bottomFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rbc_cube_bottom_face,
		rbc_rotate_cube_outer_slices_left,
		"bottom face wasn't rotated");
}
