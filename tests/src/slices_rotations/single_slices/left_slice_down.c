
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateLeftSliceDown_frontFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
	test_span_moved(
		rubiks_cube_front_face, left_column,
		rubiks_cube_rotate_left_slice_down,
		rubiks_cube_bottom_face, left_column,
		"front face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateLeftSliceDown_bottomFaceLeftColumn_movesTo_backFaceLeftColumn)
{
	test_span_moved(
		rubiks_cube_bottom_face, left_column,
		rubiks_cube_rotate_left_slice_down,
		rubiks_cube_back_face, left_column,
		"bottom face left column wasn't moved to the back face left column");
}


Test(Cube, rotateLeftSliceDown_backFaceLeftColumn_movesTo_topFaceLeftColumn)
{
	test_span_moved(
		rubiks_cube_back_face, left_column,
		rubiks_cube_rotate_left_slice_down,
		rubiks_cube_top_face, left_column,
		"back face left column wasn't moved to the top face left column");
}


Test(Cube, rotateLeftSliceDown_topFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
	test_span_moved(
		rubiks_cube_top_face, left_column,
		rubiks_cube_rotate_left_slice_down,
		rubiks_cube_front_face, left_column,
		"top face left column wasn't moved to the front face left column");
}


Test(Cube, rotateLeftSliceDown_leftFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_left_face,
		rubiks_cube_rotate_left_slice_down,
		"left face wasn't rotated");
}


Test(Cube, rotateLeftSliceDown_frontFaceLeftColumn_movesTo_bottomFaceLeftColumn_notReversed_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, left_column,
		rubiks_cube_rotate_left_slice_down,
		rubiks_cube_bottom_face, left_column,
		"source span (front face left column) was reversed");
}


Test(Cube, rotateLeftSliceDown_bottomFaceLeftColumn_movesTo_backFaceLeftColumn_notReversed_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, left_column,
		rubiks_cube_rotate_left_slice_down,
		rubiks_cube_back_face, left_column,
		"source span (bottom face left column) was reversed");
}


Test(Cube, rotateLeftSliceDown_backFaceLeftColumn_movesTo_topFaceLeftColumn_notReversed_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_back_face, left_column,
		rubiks_cube_rotate_left_slice_down,
		rubiks_cube_top_face, left_column,
		"source span (back face left column) was reversed");
}


Test(Cube, rotateLeftSliceDown_topFaceLeftColumn_movesTo_frontFaceLeftColumn_notReversed_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, left_column,
		rubiks_cube_rotate_left_slice_down,
		rubiks_cube_front_face, left_column,
		"source span (top face left column) was reversed");
}
