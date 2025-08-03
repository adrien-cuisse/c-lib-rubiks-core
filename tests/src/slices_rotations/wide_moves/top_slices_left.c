
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateTopSlicesLeft_frontFaceTopRow_movesTo_leftFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, top_row,
		rubiks_cube_rotate_top_slices_left,
		rubiks_cube_left_face, top_row,
		"front face top row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSlicesLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, equator_row,
		rubiks_cube_rotate_top_slices_left,
		rubiks_cube_left_face, equator_row,
		"front face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateTopSlicesLeft_leftFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_left_face, top_row,
		rubiks_cube_rotate_top_slices_left,
		rubiks_cube_back_face, bottom_row,
		"left face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSlicesLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_left_face, equator_row,
		rubiks_cube_rotate_top_slices_left,
		rubiks_cube_back_face, equator_row,
		"left face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateTopSlicesLeft_backFaceBottomRow_movesTo_rightFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_back_face, bottom_row,
		rubiks_cube_rotate_top_slices_left,
		rubiks_cube_right_face, top_row,
		"back face bottom row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSlicesLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_back_face, equator_row,
		rubiks_cube_rotate_top_slices_left,
		rubiks_cube_right_face, equator_row,
		"back face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateTopSlicesLeft_rightFaceTopRow_movesTo_frontFaceTopRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_right_face, top_row,
		rubiks_cube_rotate_top_slices_left,
		rubiks_cube_front_face, top_row,
		"right face top row wasn't moved to the front face top row");
}


Test(Cube, rotateTopSlicesLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_right_face, equator_row,
		rubiks_cube_rotate_top_slices_left,
		rubiks_cube_front_face, equator_row,
		"right face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateTopSlicesLeft_topFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_top_face,
		rubiks_cube_rotate_top_slices_left,
		"top face wasn't rotated");
}
