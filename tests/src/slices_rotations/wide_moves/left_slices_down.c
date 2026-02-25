
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateLeftSlicesDown_frontFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, left_column,
		rbc_rotate_cube_left_slices_down,
		rbc_cube_bottom_face, left_column,
		"front face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateLeftSlicesDown_frontFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, middle_column,
		rbc_rotate_cube_left_slices_down,
		rbc_cube_bottom_face, middle_column,
		"front face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateLeftSlicesDown_bottomFaceLeftColumn_movesTo_backFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_bottom_face, left_column,
		rbc_rotate_cube_left_slices_down,
		rbc_cube_back_face, left_column,
		"bottom face left column wasn't moved to the back face left column");
}


Test(Cube, rotateLeftSlicesDown_bottomFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_bottom_face, middle_column,
		rbc_rotate_cube_left_slices_down,
		rbc_cube_back_face, middle_column,
		"bottom face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateLeftSlicesDown_backFaceLeftColumn_movesTo_topFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_back_face, left_column,
		rbc_rotate_cube_left_slices_down,
		rbc_cube_top_face, left_column,
		"back face left column wasn't moved to the top face left column");
}


Test(Cube, rotateLeftSlicesDown_backFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_back_face, middle_column,
		rbc_rotate_cube_left_slices_down,
		rbc_cube_top_face, middle_column,
		"back face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateLeftSlicesDown_topFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_top_face, left_column,
		rbc_rotate_cube_left_slices_down,
		rbc_cube_front_face, left_column,
		"top face left column wasn't moved to the front face left column");
}


Test(Cube, rotateLeftSlicesDown_topFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_top_face, middle_column,
		rbc_rotate_cube_left_slices_down,
		rbc_cube_front_face, middle_column,
		"top face middle column wasn't moved to the front face middle column");
}


Test(Cube, rotateLeftSlicesDown_leftFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rbc_cube_left_face,
		rbc_rotate_cube_left_slices_down,
		"left face wasn't rotated");
}
