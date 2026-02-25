
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateOuterSlicesAnticlockwise_topFaceBottomRow_movesTo_leftFaceRightColumn_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_top_face, bottom_row,
		rbc_rotate_cube_outer_slices_anticlockwise,
		rbc_cube_left_face, right_column,
		"top face bottom row wasn't moved to the left face right column");
}


Test(Cube, rotateOuterSlicesAnticlockwise_topFaceTopRow_movesTo_leftFaceLeftColumn_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_top_face, top_row,
		rbc_rotate_cube_outer_slices_anticlockwise,
		rbc_cube_left_face, left_column,
		"top face top row wasn't moved to the left face left column");
}


Test(Cube, rotateOuterSlicesAnticlockwise_leftFaceRightColumn_movesTo_bottomFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_left_face, right_column,
		rbc_rotate_cube_outer_slices_anticlockwise,
		rbc_cube_bottom_face, top_row,
		"left face right column wasn't moved to the bottom face top row");
}


Test(Cube, rotateOuterSlicesAnticlockwise_leftFaceLeftColumn_movesTo_bottomFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_left_face, left_column,
		rbc_rotate_cube_outer_slices_anticlockwise,
		rbc_cube_bottom_face, bottom_row,
		"left face left column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateOuterSlicesAnticlockwise_bottomFaceTopRow_movesTo_rightFaceLeftColumn_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_bottom_face, top_row,
		rbc_rotate_cube_outer_slices_anticlockwise,
		rbc_cube_right_face, left_column,
		"bottom face top row wasn't moved to the right face left column");
}


Test(Cube, rotateOuterSlicesAnticlockwise_bottomFaceBottomRow_movesTo_rightFaceRightColumn_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_bottom_face, bottom_row,
		rbc_rotate_cube_outer_slices_anticlockwise,
		rbc_cube_right_face, right_column,
		"bottom face bottom row wasn't moved to the right face right column");
}


Test(Cube, rotateOuterSlicesAnticlockwise_rightFaceLeftColumn_movesTo_topFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_right_face, left_column,
		rbc_rotate_cube_outer_slices_anticlockwise,
		rbc_cube_top_face, bottom_row,
		"right face left column wasn't moved to the top face bottom row");
}


Test(Cube, rotateOuterSlicesAnticlockwise_rightFaceRightColumn_movesTo_topFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_right_face, right_column,
		rbc_rotate_cube_outer_slices_anticlockwise,
		rbc_cube_top_face, top_row,
		"right face right column wasn't moved to the top face top row");
}


Test(Cube, rotateOuterSlicesAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rbc_cube_front_face,
		rbc_rotate_cube_outer_slices_anticlockwise,
		"front face wasn't rotated");
}


Test(Cube, rotateOuterSlicesAnticlockwise_backFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rbc_cube_back_face,
		rbc_rotate_cube_outer_slices_anticlockwise,
		"back face wasn't rotated");
}
