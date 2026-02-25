
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateBackSliceAnticlockwise_topFaceTopRow_movesTo_leftFaceLeftColumn)
{
	test_span_moved(
		rubiks_cube_top_face, top_row,
		rubiks_cube_rotate_back_slice_anticlockwise,
		rubiks_cube_left_face, left_column,
		"top face top row wasn't moved to the left face left column");
}


Test(Cube, rotateBackSliceAnticlockwise_leftFaceLeftColumn_movesTo_bottomFaceBottomRow)
{
	test_span_moved(
		rubiks_cube_left_face, left_column,
		rubiks_cube_rotate_back_slice_anticlockwise,
		rubiks_cube_bottom_face, bottom_row,
		"left face left column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateBackSliceAnticlockwise_bottomFaceBottomRow_movesTo_rightFaceRightColumn)
{
	test_span_moved(
		rubiks_cube_bottom_face, bottom_row,
		rubiks_cube_rotate_back_slice_anticlockwise,
		rubiks_cube_right_face, right_column,
		"bottom face bottom row wasn't moved to the right face right column");
}


Test(Cube, rotateBackSliceAnticlockwise_rightFaceRightColumn_movesTo_topFaceTopRow)
{
	test_span_moved(
		rubiks_cube_right_face, right_column,
		rubiks_cube_rotate_back_slice_anticlockwise,
		rubiks_cube_top_face, top_row,
		"right face right column wasn't moved to the top face top row");
}


Test(Cube, rotateBackSliceAnticlockwise_backFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_back_face,
		rubiks_cube_rotate_back_slice_anticlockwise,
		"back face wasn't rotated");
}


Test(Cube, rotateBackSliceAnticlockwise_bottomFaceBottomRow_movesTo_rightFaceRightColumn_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_bottom_face, bottom_row,
		rubiks_cube_rotate_back_slice_anticlockwise,
		rubiks_cube_right_face, right_column,
		"source span (bottom face bottom row) wasn't reversed");
}


Test(Cube, rotateBackSliceAnticlockwise_topFaceTopRow_movesTo_leftFaceLeftColumn_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_top_face, top_row,
		rubiks_cube_rotate_back_slice_anticlockwise,
		rubiks_cube_left_face, left_column,
		"source span (top face top row) wasn't reversed");
}


Test(Cube, rotateBackSliceAnticlockwise_rightFaceRightColumn_movesTo_topFaceTopRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_right_face, right_column,
		rubiks_cube_rotate_back_slice_anticlockwise,
		rubiks_cube_top_face, top_row,
		"source span (right face right column) was reversed");
}


Test(Cube, rotateBackSliceAnticlockwise_leftFaceLeftColumn_movesTo_bottomFaceBottomRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_left_face, left_column,
		rubiks_cube_rotate_back_slice_anticlockwise,
		rubiks_cube_bottom_face, bottom_row,
		"source span (left face left column) was reversed");
}
