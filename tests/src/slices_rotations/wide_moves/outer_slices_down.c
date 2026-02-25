
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateOuterSlicesDown_frontFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, left_column,
		rbc_rotate_cube_outer_slices_down,
		rbc_cube_bottom_face, left_column,
		"front face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateOuterSlicesDown_frontFaceRightColumn_movesTo_bottomFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, right_column,
		rbc_rotate_cube_outer_slices_down,
		rbc_cube_bottom_face, right_column,
		"front face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateOuterSlicesDown_bottomFaceLeftColumn_movesTo_backFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_bottom_face, left_column,
		rbc_rotate_cube_outer_slices_down,
		rbc_cube_back_face, left_column,
		"bottom face left column wasn't moved to the back face left column");
}


Test(Cube, rotateOuterSlicesDown_bottomFaceRightColumn_movesTo_backFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_bottom_face, right_column,
		rbc_rotate_cube_outer_slices_down,
		rbc_cube_back_face, right_column,
		"bottom face right column wasn't moved to the back face right column");
}


Test(Cube, rotateOuterSlicesDown_backFaceLeftColumn_movesTo_topFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_back_face, left_column,
		rbc_rotate_cube_outer_slices_down,
		rbc_cube_top_face, left_column,
		"back face left column wasn't moved to the top face left column");
}


Test(Cube, rotateOuterSlicesDown_backFaceRightColumn_movesTo_topFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_back_face, right_column,
		rbc_rotate_cube_outer_slices_down,
		rbc_cube_top_face, right_column,
		"back face right column wasn't moved to the top face right column");
}


Test(Cube, rotateOuterSlicesDown_topFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_top_face, left_column,
		rbc_rotate_cube_outer_slices_down,
		rbc_cube_front_face, left_column,
		"top face left column wasn't moved to the front face left column");
}


Test(Cube, rotateOuterSlicesDown_topFaceRightColumn_movesTo_frontFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rbc_cube_top_face, right_column,
		rbc_rotate_cube_outer_slices_down,
		rbc_cube_front_face, right_column,
		"top face right column wasn't moved to the front face right column");
}


Test(Cube, rotateOuterSlicesDown_leftFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rbc_cube_left_face,
		rbc_rotate_cube_outer_slices_down,
		"left face wasn't rotated");
}


Test(Cube, rotateOuterSlicesDown_rightFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rbc_cube_right_face,
		rbc_rotate_cube_outer_slices_down,
		"right face wasn't rotated");
}
