
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateOuterSlicesClockwise_topFaceBottomRow_movesTo_rightFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, bottom_row,
		rubiks_cube_rotate_outer_slices_clockwise,
		rubiks_cube_right_face, left_column,
		"top face bottom row wasn't moved to the right face left column");
}


Test(Cube, rotateOuterSlicesClockwise_topFaceTopRow_movesTo_rightFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, top_row,
		rubiks_cube_rotate_outer_slices_clockwise,
		rubiks_cube_right_face, right_column,
		"top face top row wasn't moved to the right face right column");
}


Test(Cube, rotateOuterSlicesClockwise_rightFaceLeftColumn_movesTo_bottomFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, left_column,
		rubiks_cube_rotate_outer_slices_clockwise,
		rubiks_cube_bottom_face, top_row,
		"right face left column wasn't moved to the bottom face top row");
}


Test(Cube, rotateOuterSlicesClockwise_rightFaceRightColumn_movesTo_bottomFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, right_column,
		rubiks_cube_rotate_outer_slices_clockwise,
		rubiks_cube_bottom_face, bottom_row,
		"right face right column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateOuterSlicesClockwise_bottomFaceTopRow_movesTo_leftFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, top_row,
		rubiks_cube_rotate_outer_slices_clockwise,
		rubiks_cube_left_face, right_column,
		"bottom face top row wasn't moved to the left face right column");
}


Test(Cube, rotateOuterSlicesClockwise_bottomFaceBottomRow_movesTo_leftFaceLeftColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, bottom_row,
		rubiks_cube_rotate_outer_slices_clockwise,
		rubiks_cube_left_face, left_column,
		"bottom face bottom row wasn't moved to the left face left column");
}


Test(Cube, rotateOuterSlicesClockwise_leftFaceRightColumn_movesTo_topFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_left_face, right_column,
		rubiks_cube_rotate_outer_slices_clockwise,
		rubiks_cube_top_face, bottom_row,
		"left face right column wasn't moved to the top face bottom row");
}


Test(Cube, rotateOuterSlicesClockwise_leftFaceLeftColumn_movesTo_topFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_left_face, left_column,
		rubiks_cube_rotate_outer_slices_clockwise,
		rubiks_cube_top_face, top_row,
		"left face left column wasn't moved to the top face top row");
}


Test(Cube, rotateOuterSlicesClockwise_frontFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_front_face,
		rubiks_cube_rotate_outer_slices_clockwise,
		"front face wasn't rotated");
}


Test(Cube, rotateOuterSlicesClockwise_backFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rubiks_cube_back_face,
		rubiks_cube_rotate_outer_slices_clockwise,
		"back face wasn't rotated");
}
