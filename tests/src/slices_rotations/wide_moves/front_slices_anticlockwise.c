
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateFrontSlicesAnticlockwise_topFaceBottomRow_movesTo_leftFaceRightColumn_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_top_face, bottom_row,
		rbc_rotate_cube_front_slices_anticlockwise,
		rbc_cube_left_face, right_column,
		"top face bottom row wasn't moved to the left face right column");
}


Test(Cube, rotateFrontSlicesAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_top_face, equator_row,
		rbc_rotate_cube_front_slices_anticlockwise,
		rbc_cube_left_face, middle_column,
		"top face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateFrontSlicesAnticlockwise_leftFaceRightColumn_movesTo_bottomFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_left_face, right_column,
		rbc_rotate_cube_front_slices_anticlockwise,
		rbc_cube_bottom_face, top_row,
		"left face right column wasn't moved to the bottom face top row");
}


Test(Cube, rotateFrontSlicesAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_left_face, middle_column,
		rbc_rotate_cube_front_slices_anticlockwise,
		rbc_cube_bottom_face, equator_row,
		"left face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateFrontSlicesAnticlockwise_bottomFaceTopRow_movesTo_rightFaceLeftColumn_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_bottom_face, top_row,
		rbc_rotate_cube_front_slices_anticlockwise,
		rbc_cube_right_face, left_column,
		"bottom face top row wasn't moved to the right face left column");
}


Test(Cube, rotateFrontSlicesAnticlockwise_bottomFaceEquatorRow_movesTo_rightFaceMiddleColumn_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_bottom_face, equator_row,
		rbc_rotate_cube_front_slices_anticlockwise,
		rbc_cube_right_face, middle_column,
		"bottom face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateFrontSlicesAnticlockwise_rightFaceLeftColumn_movesTo_topFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_right_face, left_column,
		rbc_rotate_cube_front_slices_anticlockwise,
		rbc_cube_top_face, bottom_row,
		"right face left column wasn't moved to the top face bottom row");
}


Test(Cube, rotateFrontSlicesAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_right_face, middle_column,
		rbc_rotate_cube_front_slices_anticlockwise,
		rbc_cube_top_face, equator_row,
		"right face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateFrontSlicesAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rbc_cube_front_face,
		rbc_rotate_cube_front_slices_anticlockwise,
		"front face wasn't rotated");
}
