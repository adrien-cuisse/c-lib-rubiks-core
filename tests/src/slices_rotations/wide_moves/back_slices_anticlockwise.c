
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateBackSlicesAnticlockwise_topFaceTopRow_movesTo_leftFaceLeftColumn_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_top_face, top_row,
		rubiks_cube_rotate_back_slices_anticlockwise,
		rubiks_cube_left_face, left_column,
		"top face top row wasn't moved to the left face left column");
}


Test(Cube, rotateBackSlicesAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_top_face, equator_row,
		rubiks_cube_rotate_back_slices_anticlockwise,
		rubiks_cube_left_face, middle_column,
		"top face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateBackSlicesAnticlockwise_leftFaceLeftColumn_movesTo_bottomFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_left_face, left_column,
		rubiks_cube_rotate_back_slices_anticlockwise,
		rubiks_cube_bottom_face, bottom_row,
		"left face left column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateBackSlicesAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_left_face, middle_column,
		rubiks_cube_rotate_back_slices_anticlockwise,
		rubiks_cube_bottom_face, equator_row,
		"left face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateBackSlicesAnticlockwise_bottomFaceBottomRow_movesTo_rightFaceRightColumn_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_bottom_face, bottom_row,
		rubiks_cube_rotate_back_slices_anticlockwise,
		rubiks_cube_right_face, right_column,
		"bottom face bottom row wasn't moved to the right face right column");
}


Test(Cube, rotateBackSlicesAnticlockwise_bottomFaceEquatorRow_movesTo_rightFaceMiddleColumn_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_bottom_face, equator_row,
		rubiks_cube_rotate_back_slices_anticlockwise,
		rubiks_cube_right_face, middle_column,
		"bottom face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateBackSlicesAnticlockwise_rightFaceRightColumn_movesTo_topFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_right_face, right_column,
		rubiks_cube_rotate_back_slices_anticlockwise,
		rubiks_cube_top_face, top_row,
		"right face right column wasn't moved to the top face top row");
}


Test(Cube, rotateBackSlicesAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_right_face, middle_column,
		rubiks_cube_rotate_back_slices_anticlockwise,
		rubiks_cube_top_face, equator_row,
		"right face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateBackSlicesAnticlockwise_backFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_back_face,
		rubiks_cube_rotate_back_slices_anticlockwise,
		"back face wasn't rotated");
}
