
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateFrontSlicesClockwise_topFaceBottomRow_movesTo_rightFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, bottom_row,
		rubiks_cube_rotate_front_slices_clockwise,
		rubiks_cube_right_face, left_column,
		"top face bottom row wasn't moved to the right face left column");
}


Test(Cube, rotateFrontSlicesClockwise_topFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, equator_row,
		rubiks_cube_rotate_front_slices_clockwise,
		rubiks_cube_right_face, middle_column,
		"top face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateFrontSlicesClockwise_rightFaceLeftColumn_movesTo_bottomFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, left_column,
		rubiks_cube_rotate_front_slices_clockwise,
		rubiks_cube_bottom_face, top_row,
		"right face left column wasn't moved to the bottom face top row");
}


Test(Cube, rotateFrontSlicesClockwise_rightFaceMiddleColumn_movesTo_bottomFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, middle_column,
		rubiks_cube_rotate_front_slices_clockwise,
		rubiks_cube_bottom_face, equator_row,
		"right face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateFrontSlicesClockwise_bottomFaceTopRow_movesTo_leftFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, top_row,
		rubiks_cube_rotate_front_slices_clockwise,
		rubiks_cube_left_face, right_column,
		"bottom face top row wasn't moved to the left face right column");
}


Test(Cube, rotateFrontSlicesClockwise_bottomFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, equator_row,
		rubiks_cube_rotate_front_slices_clockwise,
		rubiks_cube_left_face, middle_column,
		"bottom face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateFrontSlicesClockwise_leftFaceRightColumn_movesTo_topFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_left_face, right_column,
		rubiks_cube_rotate_front_slices_clockwise,
		rubiks_cube_top_face, bottom_row,
		"left face right column wasn't moved to the top face bottom row");
}


Test(Cube, rotateFrontSlicesClockwise_leftFaceMiddleColumn_movesTo_topFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_left_face, middle_column,
		rubiks_cube_rotate_front_slices_clockwise,
		rubiks_cube_top_face, equator_row,
		"left face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateFrontSlicesClockwise_frontFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_front_face,
		rubiks_cube_rotate_front_slices_clockwise,
		"front face wasn't rotated");
}
