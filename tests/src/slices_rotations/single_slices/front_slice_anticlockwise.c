
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateFrontSliceAnticlockwise_topFaceBottomRow_movesTo_leftFaceRightColumn)
{
	test_span_moved(
		rbc_cube_top_face, bottom_row,
		rbc_rotate_cube_front_slice_anticlockwise,
		rbc_cube_left_face, right_column,
		"top face bottom row wasn't moved to the left face right column");
}


Test(Cube, rotateFrontSliceAnticlockwise_leftFaceRightColumn_movesTo_bottomFaceTopRow)
{
	test_span_moved(
		rbc_cube_left_face, right_column,
		rbc_rotate_cube_front_slice_anticlockwise,
		rbc_cube_bottom_face, top_row,
		"left face right column wasn't moved to the bottom face top row");
}


Test(Cube, rotateFrontSliceAnticlockwise_bottomFaceTopRow_movesTo_rightFaceLeftColumn)
{
	test_span_moved(
		rbc_cube_bottom_face, top_row,
		rbc_rotate_cube_front_slice_anticlockwise,
		rbc_cube_right_face, left_column,
		"bottom face top row wasn't moved to the right face left column");
}


Test(Cube, rotateFrontSliceAnticlockwise_rightFaceLeftColumn_movesTo_topFaceBottomRow)
{
	test_span_moved(
		rbc_cube_right_face, left_column,
		rbc_rotate_cube_front_slice_anticlockwise,
		rbc_cube_top_face, bottom_row,
		"right face left column wasn't moved to the top face bottom row");
}


Test(Cube, rotateFrontSliceAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rbc_cube_front_face,
		rbc_rotate_cube_front_slice_anticlockwise,
		"front face wasn't rotated");
}


Test(Cube, rotateFrontSliceAnticlockwise_bottomFaceTopRow_movesTo_rightFaceLeftColumn_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_bottom_face, top_row,
		rbc_rotate_cube_front_slice_anticlockwise,
		rbc_cube_right_face, left_column,
		"source span (bottom face top row) wasn't reversed");
}


Test(Cube, rotateFrontSliceAnticlockwise_topFaceBottomRow_movesTo_leftFaceRightColumn_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_top_face, bottom_row,
		rbc_rotate_cube_front_slice_anticlockwise,
		rbc_cube_left_face, right_column,
		"source span (top face bottom row) wasn't reversed");
}


Test(Cube, rotateFrontSliceAnticlockwise_rightFaceLeftColumn_movesTo_topFaceBottomRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_right_face, left_column,
		rbc_rotate_cube_front_slice_anticlockwise,
		rbc_cube_top_face, bottom_row,
		"source span (right face left column) was reversed");
}


Test(Cube, rotateFrontSliceAnticlockwise_leftFaceRightColumn_movesTo_bottomFaceTopRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_left_face, right_column,
		rbc_rotate_cube_front_slice_anticlockwise,
		rbc_cube_bottom_face, top_row,
		"source span (left face right column) was reversed");
}
