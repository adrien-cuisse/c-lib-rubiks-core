
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateStandingSliceAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
	test_span_moved(
		rubiks_cube_top_face, equator_row,
		rubiks_cube_rotate_standing_slice_anticlockwise,
		rubiks_cube_left_face, middle_column,
		"top face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateStandingSliceAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
	test_span_moved(
		rubiks_cube_left_face, middle_column,
		rubiks_cube_rotate_standing_slice_anticlockwise,
		rubiks_cube_bottom_face, equator_row,
		"left face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateStandingSliceAnticlockwise_bottomFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
	test_span_moved(
		rubiks_cube_bottom_face, equator_row,
		rubiks_cube_rotate_standing_slice_anticlockwise,
		rubiks_cube_right_face, middle_column,
		"bottom face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateStandingSliceAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
	test_span_moved(
		rubiks_cube_right_face, middle_column,
		rubiks_cube_rotate_standing_slice_anticlockwise,
		rubiks_cube_top_face, equator_row,
		"right face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateStandingSliceAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_top_face, equator_row,
		rubiks_cube_rotate_standing_slice_anticlockwise,
		rubiks_cube_left_face, middle_column,
		"source span (top face equator row) wasn't reversed");
}


Test(Cube, rotateStandingSliceAnticlockwise_bottomFaceEquatorRow_movesTo_rightFaceMiddleColumn_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_bottom_face, equator_row,
		rubiks_cube_rotate_standing_slice_anticlockwise,
		rubiks_cube_right_face, middle_column,
		"source span (bottom face equator row) wasn't reversed");
}


Test(Cube, rotateStandingSliceAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_right_face, middle_column,
		rubiks_cube_rotate_standing_slice_anticlockwise,
		rubiks_cube_top_face, equator_row,
		"source span (right face middle column) was reversed");
}


Test(Cube, rotateStandingSliceAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_left_face, middle_column,
		rubiks_cube_rotate_standing_slice_anticlockwise,
		rubiks_cube_bottom_face, equator_row,
		"source span (left face middle column) was reversed");
}
