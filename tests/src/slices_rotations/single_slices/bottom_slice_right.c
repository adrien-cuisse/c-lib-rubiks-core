
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateBottomSliceRight_frontFaceBottomRow_movesTo_rightFaceBottomRow)
{
	test_span_moved(
		rubiks_cube_front_face, bottom_row,
		rubiks_cube_rotate_bottom_slice_right,
		rubiks_cube_right_face, bottom_row,
		"front face bottom row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSliceRight_rightFaceBottomRow_movesTo_backFaceTopRow)
{
	test_span_moved(
		rubiks_cube_right_face, bottom_row,
		rubiks_cube_rotate_bottom_slice_right,
		rubiks_cube_back_face, top_row,
		"right face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSliceRight_backFaceTopRow_movesTo_leftFaceBottomRow)
{
	test_span_moved(
		rubiks_cube_back_face, top_row,
		rubiks_cube_rotate_bottom_slice_right,
		rubiks_cube_left_face, bottom_row,
		"back face top row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSliceRight_leftFaceBottomRow_movesTo_frontFaceBottomRow)
{
	test_span_moved(
		rubiks_cube_left_face, bottom_row,
		rubiks_cube_rotate_bottom_slice_right,
		rubiks_cube_front_face, bottom_row,
		"left face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateBottomSliceRight_bottomFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_bottom_face,
		rubiks_cube_rotate_bottom_slice_right,
		"bottom face wasn't rotated");
}


Test(Cube, rotateBottomSliceRight_rightFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, bottom_row,
		rubiks_cube_rotate_bottom_slice_right,
		rubiks_cube_back_face, top_row,
		"source span (right face bottom row) wasn't reversed");
}


Test(Cube, rotateBottomSliceRight_backFaceTopRow_movesTo_leftFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_back_face, top_row,
		rubiks_cube_rotate_bottom_slice_right,
		rubiks_cube_left_face, bottom_row,
		"source span (back face top row) wasn't reversed");
}


Test(Cube, rotateBottomSliceRight_leftFaceBottomRow_movesTo_frontFaceBottomRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_left_face, bottom_row,
		rubiks_cube_rotate_bottom_slice_right,
		rubiks_cube_front_face, bottom_row,
		"source span (left face bottom row) was reversed");
}


Test(Cube, rotateBottomSliceRight_frontFaceBottomRow_movesTo_rightFaceBottomRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, bottom_row,
		rubiks_cube_rotate_bottom_slice_right,
		rubiks_cube_right_face, bottom_row,
		"source span (front face bottom row) was reversed");
}
