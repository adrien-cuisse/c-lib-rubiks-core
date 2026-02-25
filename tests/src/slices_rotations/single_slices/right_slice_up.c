
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateRightSliceUp_frontFaceRightColumn_movesTo_topFaceRightColumn)
{
	test_span_moved(
		rubiks_cube_front_face, right_column,
		rubiks_cube_rotate_right_slice_up,
		rubiks_cube_top_face, right_column,
		"front face right column wasn't moved to the top face right column");
}


Test(Cube, rotateRightSliceUp_topFaceRightColumn_movesTo_backFaceRightColumn)
{
	test_span_moved(
		rubiks_cube_top_face, right_column,
		rubiks_cube_rotate_right_slice_up,
		rubiks_cube_back_face, right_column,
		"top face right column wasn't moved to the back face right column");
}


Test(Cube, rotateRightSliceUp_backFaceRightColumn_movesTo_bottomFaceRightColumn)
{
	test_span_moved(
		rubiks_cube_back_face, right_column,
		rubiks_cube_rotate_right_slice_up,
		rubiks_cube_bottom_face, right_column,
		"back face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateRightSliceUp_bottomFaceRightColumn_movesTo_frontFaceRightColumn)
{
	test_span_moved(
		rubiks_cube_bottom_face, right_column,
		rubiks_cube_rotate_right_slice_up,
		rubiks_cube_front_face, right_column,
		"bottom face right column wasn't moved to the front face right column");
}


Test(Cube, rotateRightSliceUp_rightFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_right_face,
		rubiks_cube_rotate_right_slice_up,
		"right face wasn't rotated");
}


Test(Cube, rotateRightSliceUp_frontFaceRightColumn_movesTo_topFaceRightColumn_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, right_column,
		rubiks_cube_rotate_right_slice_up,
		rubiks_cube_top_face, right_column,
		"source span (front face right column) was reversed");
}


Test(Cube, rotateRightSliceUp_topFaceRightColumn_movesTo_backFaceRightColumn_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, right_column,
		rubiks_cube_rotate_right_slice_up,
		rubiks_cube_back_face, right_column,
		"source span (top face right column) was reversed");
}


Test(Cube, rotateRightSliceUp_backFaceRightColumn_movesTo_bottomFaceRightColumn_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_back_face, right_column,
		rubiks_cube_rotate_right_slice_up,
		rubiks_cube_bottom_face, right_column,
		"source span (back face right column) was reversed");
}


Test(Cube, rotateRightSliceUp_bottomFaceRightColumn_movesTo_frontFaceRightColumn_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, right_column,
		rubiks_cube_rotate_right_slice_up,
		rubiks_cube_front_face, right_column,
		"source span (bottom face right column) was reversed");
}
