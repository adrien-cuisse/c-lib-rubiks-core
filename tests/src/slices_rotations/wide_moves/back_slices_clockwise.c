
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateBackSlicesClockwise_topFaceTopRow_movesTo_rightFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, top_row,
		rubiks_cube_rotate_back_slices_clockwise,
		rubiks_cube_right_face, right_column,
		"top face top row wasn't moved to the right face right column");
}


Test(Cube, rotateBackSlicesClockwise_topFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, equator_row,
		rubiks_cube_rotate_back_slices_clockwise,
		rubiks_cube_right_face, middle_column,
		"top face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateBackSlicesClockwise_rightFaceRightColumn_movesTo_bottomFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, right_column,
		rubiks_cube_rotate_back_slices_clockwise,
		rubiks_cube_bottom_face, bottom_row,
		"right face right column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateBackSlicesClockwise_rightFaceMiddleColumn_movesTo_bottomFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, middle_column,
		rubiks_cube_rotate_back_slices_clockwise,
		rubiks_cube_bottom_face, equator_row,
		"right face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateBackSlicesClockwise_bottomFaceBottomRow_movesTo_leftFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, bottom_row,
		rubiks_cube_rotate_back_slices_clockwise,
		rubiks_cube_left_face, left_column,
		"bottom face bottom row wasn't moved to the left face left column");
}


Test(Cube, rotateBackSlicesClockwise_bottomFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, equator_row,
		rubiks_cube_rotate_back_slices_clockwise,
		rubiks_cube_left_face, middle_column,
		"bottom face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateBackSlicesClockwise_leftFaceLeftColumn_movesTo_topFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_left_face, left_column,
		rubiks_cube_rotate_back_slices_clockwise,
		rubiks_cube_top_face, top_row,
		"left face left column wasn't moved to the top face top row");
}


Test(Cube, rotateBackSlicesClockwise_leftFaceMiddleColumn_movesTo_topFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_left_face, middle_column,
		rubiks_cube_rotate_back_slices_clockwise,
		rubiks_cube_top_face, equator_row,
		"left face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateBackSlicesClockwise_backFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rubiks_cube_back_face,
		rubiks_cube_rotate_back_slices_clockwise,
		"back face wasn't rotated");
}
