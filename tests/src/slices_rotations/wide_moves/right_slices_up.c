
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateRightSlicesUp_frontFaceRightColumn_movesTo_topFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, right_column,
		rbc_rotate_cube_right_slices_up,
		rbc_cube_top_face, right_column,
		"front face right column wasn't moved to the top face right column");
}


Test(Cube, rotateRightSlicesUp_frontFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, middle_column,
		rbc_rotate_cube_right_slices_up,
		rbc_cube_top_face, middle_column,
		"front face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateRightSlicesUp_topFaceRightColumn_movesTo_backFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_top_face, right_column,
		rbc_rotate_cube_right_slices_up,
		rbc_cube_back_face, right_column,
		"top face right column wasn't moved to the back face right column");
}


Test(Cube, rotateRightSlicesUp_topFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_top_face, middle_column,
		rbc_rotate_cube_right_slices_up,
		rbc_cube_back_face, middle_column,
		"top face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateRightSlicesUp_backFaceRightColumn_movesTo_bottomFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_back_face, right_column,
		rbc_rotate_cube_right_slices_up,
		rbc_cube_bottom_face, right_column,
		"back face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateRightSlicesUp_backFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_back_face, middle_column,
		rbc_rotate_cube_right_slices_up,
		rbc_cube_bottom_face, middle_column,
		"back face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateRightSlicesUp_bottomFaceRightColumn_movesTo_frontFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_bottom_face, right_column,
		rbc_rotate_cube_right_slices_up,
		rbc_cube_front_face, right_column,
		"bottom face right column wasn't moved to the front face right column");
}


Test(Cube, rotateRightSlicesUp_bottomFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_bottom_face, middle_column,
		rbc_rotate_cube_right_slices_up,
		rbc_cube_front_face, middle_column,
		"bottom face middle column wasn't moved to the front face middle column");
}


Test(Cube, rotateRightSlicesUp_rightFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rbc_cube_right_face,
		rbc_rotate_cube_right_slices_up,
		"right face wasn't rotated");
}
