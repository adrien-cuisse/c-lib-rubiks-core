
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateBottomSlicesRight_frontFaceBottomRow_movesTo_rightFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, bottom_row,
		rubiks_cube_rotate_bottom_slices_right,
		rubiks_cube_right_face, bottom_row,
		"front face bottom row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSlicesRight_frontFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, equator_row,
		rubiks_cube_rotate_bottom_slices_right,
		rubiks_cube_right_face, equator_row,
		"front face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateBottomSlicesRight_rightFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, bottom_row,
		rubiks_cube_rotate_bottom_slices_right,
		rubiks_cube_back_face, top_row,
		"right face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSlicesRight_rightFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_right_face, equator_row,
		rubiks_cube_rotate_bottom_slices_right,
		rubiks_cube_back_face, equator_row,
		"right face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateBottomSlicesRight_backFaceTopRow_movesTo_leftFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_back_face, top_row,
		rubiks_cube_rotate_bottom_slices_right,
		rubiks_cube_left_face, bottom_row,
		"back face top row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSlicesRight_backFaceEquatorRow_movesTo_leftFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_back_face, equator_row,
		rubiks_cube_rotate_bottom_slices_right,
		rubiks_cube_left_face, equator_row,
		"back face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateBottomSlicesRight_leftFaceBottomRow_movesTo_frontFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_left_face, bottom_row,
		rubiks_cube_rotate_bottom_slices_right,
		rubiks_cube_front_face, bottom_row,
		"left face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateBottomSlicesRight_leftFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_left_face, equator_row,
		rubiks_cube_rotate_bottom_slices_right,
		rubiks_cube_front_face, equator_row,
		"left face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateBottomSlicesRight_bottomFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_bottom_face,
		rubiks_cube_rotate_bottom_slices_right,
		"bottom face wasn't rotated");
}
