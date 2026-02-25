
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateMiddleSliceDown_frontFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
	test_span_moved(
		rbc_cube_front_face, middle_column,
		rbc_rotate_cube_middle_slice_down,
		rbc_cube_bottom_face, middle_column,
		"front face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateMiddleSliceDown_bottomFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
	test_span_moved(
		rbc_cube_bottom_face, middle_column,
		rbc_rotate_cube_middle_slice_down,
		rbc_cube_back_face, middle_column,
		"bottom face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateMiddleSliceDown_backFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
	test_span_moved(
		rbc_cube_back_face, middle_column,
		rbc_rotate_cube_middle_slice_down,
		rbc_cube_top_face, middle_column,
		"back face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateMiddleSliceDown_topFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
	test_span_moved(
		rbc_cube_top_face, middle_column,
		rbc_rotate_cube_middle_slice_down,
		rbc_cube_front_face, middle_column,
		"top face middle column wasn't moved to the front face middle column");
}


Test(Cube, rotateMiddleSliceDown_frontFaceMiddleColumn_movesTo_bottomFaceMiddleColumn_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, middle_column,
		rbc_rotate_cube_middle_slice_down,
		rbc_cube_bottom_face, middle_column,
		"source span (front face middle column) was reversed");
}


Test(Cube, rotateMiddleSliceDown_bottomFaceMiddleColumn_movesTo_backFaceMiddleColumn_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_bottom_face, middle_column,
		rbc_rotate_cube_middle_slice_down,
		rbc_cube_back_face, middle_column,
		"source span (bottom face middle column) was reversed");
}


Test(Cube, rotateMiddleSliceDown_backFaceMiddleColumn_movesTo_topFaceMiddleColumn_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_back_face, middle_column,
		rbc_rotate_cube_middle_slice_down,
		rbc_cube_top_face, middle_column,
		"source span (back face middle column) was reversed");
}


Test(Cube, rotateMiddleSliceDown_topFaceMiddleColumn_movesTo_frontFaceMiddleColumn_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_top_face, middle_column,
		rbc_rotate_cube_middle_slice_down,
		rbc_cube_front_face, middle_column,
		"source span (top face middle column) was reversed");
}
