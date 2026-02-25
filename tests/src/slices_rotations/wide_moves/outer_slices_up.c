
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateOuterSlicesUp_frontFaceLeftColumn_movesTo_topFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, left_column,
		rubiks_cube_rotate_outer_slices_up,
		rubiks_cube_top_face, left_column,
		"front face left column wasn't moved to the top face left column");
}


Test(Cube, rotateOuterSlicesUp_frontFaceRightColumn_movesTo_topFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, right_column,
		rubiks_cube_rotate_outer_slices_up,
		rubiks_cube_top_face, right_column,
		"front face right column wasn't moved to the top face right column");
}


Test(Cube, rotateOuterSlicesUp_topFaceLeftColumn_movesTo_backFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, left_column,
		rubiks_cube_rotate_outer_slices_up,
		rubiks_cube_back_face, left_column,
		"top face left column wasn't moved to the back face left column");
}


Test(Cube, rotateOuterSlicesUp_topFaceRightColumn_movesTo_backFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, right_column,
		rubiks_cube_rotate_outer_slices_up,
		rubiks_cube_back_face, right_column,
		"top face right column wasn't moved to the back face right column");
}


Test(Cube, rotateOuterSlicesUp_backFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_back_face, left_column,
		rubiks_cube_rotate_outer_slices_up,
		rubiks_cube_bottom_face, left_column,
		"back face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateOuterSlicesUp_backFaceRightColumn_movesTo_bottomFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_back_face, right_column,
		rubiks_cube_rotate_outer_slices_up,
		rubiks_cube_bottom_face, right_column,
		"back face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateOuterSlicesUp_bottomFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, left_column,
		rubiks_cube_rotate_outer_slices_up,
		rubiks_cube_front_face, left_column,
		"bottom face left column wasn't moved to the front face left column");
}


Test(Cube, rotateOuterSlicesUp_bottomFaceRightColumn_movesTo_frontFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, right_column,
		rubiks_cube_rotate_outer_slices_up,
		rubiks_cube_front_face, right_column,
		"bottom face right column wasn't moved to the front face right column");
}


Test(Cube, rotateOuterSlicesUp_leftFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rubiks_cube_left_face,
		rubiks_cube_rotate_outer_slices_up,
		"left face wasn't rotated");
}


Test(Cube, rotateOuterSlicesUp_rightFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_right_face,
		rubiks_cube_rotate_outer_slices_up,
		"right face wasn't rotated");
}

