
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateFrontSliceClockwise_topFaceBottomRow_movesTo_rightFaceLeftColumn)
{
	test_span_moved(
		rbc_cube_top_face, bottom_row,
		rbc_rotate_cube_front_slice_clockwise,
		rbc_cube_right_face, left_column,
		"top face bottom row wasn't moved to the right face left column");
}


Test(Cube, rotateFrontSliceClockwise_rightFaceLeftColumn_movesTo_bottomFaceTopRow)
{
	test_span_moved(
		rbc_cube_right_face, left_column,
		rbc_rotate_cube_front_slice_clockwise,
		rbc_cube_bottom_face, top_row,
		"right face left column wasn't moved to the bottom face top row");
}


Test(Cube, rotateFrontSliceClockwise_bottomFaceTopRow_movesTo_leftFaceRightColumn)
{
	test_span_moved(
		rbc_cube_bottom_face, top_row,
		rbc_rotate_cube_front_slice_clockwise,
		rbc_cube_left_face, right_column,
		"bottom face top row wasn't moved to the left face right column");
}


Test(Cube, rotateFrontSliceClockwise_leftFaceRightColumn_movesTo_topFaceBottomRow)
{
	test_span_moved(
		rbc_cube_left_face, right_column,
		rbc_rotate_cube_front_slice_clockwise,
		rbc_cube_top_face, bottom_row,
		"left face right column wasn't moved to the top face bottom row");
}


Test(Cube, rotateFrontSliceClockwise_frontFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rbc_cube_front_face,
		rbc_rotate_cube_front_slice_clockwise,
		"front face wasn't rotated");
}


Test(Cube, rotateFrontSliceClockwise_rightFaceLeftColumn_movesTo_bottomFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_right_face, left_column,
		rbc_rotate_cube_front_slice_clockwise,
		rbc_cube_bottom_face, top_row,
		"source span (right face left column) wasn't reversed");
}


Test(Cube, rotateFrontSliceClockwise_leftFaceRightColumn_movesTo_topFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_left_face, right_column,
		rbc_rotate_cube_front_slice_clockwise,
		rbc_cube_top_face, bottom_row,
		"source span (left face right column) wasn't reversed");
}


Test(Cube, rotateFrontSliceClockwise_bottomFaceTopRow_movesTo_leftFaceRightColumn_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_bottom_face, top_row,
		rbc_rotate_cube_front_slice_clockwise,
		rbc_cube_left_face, right_column,
		"source span (bottom face top row) was reversed");
}


Test(Cube, rotateFrontSliceClockwise_topFaceBottomRow_movesTo_rightFaceLeftColumn_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_top_face, bottom_row,
		rbc_rotate_cube_front_slice_clockwise,
		rbc_cube_right_face, left_column,
		"source span (top face bottom row) was reversed");
}
