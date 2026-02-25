
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateTopSlicesRight_frontFaceTopRow_movesTo_rightFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, top_row,
		rubiks_cube_rotate_top_slices_right,
		rubiks_cube_right_face, top_row,
		"front face top row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSlicesRight_frontFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, equator_row,
		rubiks_cube_rotate_top_slices_right,
		rubiks_cube_right_face, equator_row,
		"front face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateTopSlicesRight_rightFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, top_row,
		rubiks_cube_rotate_top_slices_right,
		rubiks_cube_back_face, bottom_row,
		"right face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSlicesRight_rightFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, equator_row,
		rubiks_cube_rotate_top_slices_right,
		rubiks_cube_back_face, equator_row,
		"right face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateTopSlicesRight_backFaceBottomRow_movesTo_leftFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_back_face, bottom_row,
		rubiks_cube_rotate_top_slices_right,
		rubiks_cube_left_face, top_row,
		"back face bottom row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSlicesRight_backFaceEquatorRow_movesTo_leftFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_back_face, equator_row,
		rubiks_cube_rotate_top_slices_right,
		rubiks_cube_left_face, equator_row,
		"back face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateTopSlicesRight_leftFaceTopRow_movesTo_frontFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_left_face, top_row,
		rubiks_cube_rotate_top_slices_right,
		rubiks_cube_front_face, top_row,
		"left face top row wasn't moved to the front face top row");
}


Test(Cube, rotateTopSlicesRight_leftFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_left_face, equator_row,
		rubiks_cube_rotate_top_slices_right,
		rubiks_cube_front_face, equator_row,
		"left face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateTopSlicesRight_topFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rubiks_cube_top_face,
		rubiks_cube_rotate_top_slices_right,
		"top face wasn't rotated");
}
