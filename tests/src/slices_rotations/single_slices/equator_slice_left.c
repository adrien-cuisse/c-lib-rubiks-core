
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateEquatorSliceLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
	test_span_moved(
		rubiks_cube_front_face, equator_row,
		rubiks_cube_rotate_equator_slice_left,
		rubiks_cube_left_face, equator_row,
		"front face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateEquatorSliceLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow)
{
	test_span_moved(
		rubiks_cube_left_face, equator_row,
		rubiks_cube_rotate_equator_slice_left,
		rubiks_cube_back_face, equator_row,
		"left face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateEquatorSliceLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
	test_span_moved(
		rubiks_cube_back_face, equator_row,
		rubiks_cube_rotate_equator_slice_left,
		rubiks_cube_right_face, equator_row,
		"back face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateEquatorSliceLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	test_span_moved(
		rubiks_cube_right_face, equator_row,
		rubiks_cube_rotate_equator_slice_left,
		rubiks_cube_front_face, equator_row,
		"right face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateEquatorSliceLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_left_face, equator_row,
		rubiks_cube_rotate_equator_slice_left,
		rubiks_cube_back_face, equator_row,
		"source span (left face equator row) wasn't reversed");
}


Test(Cube, rotateEquatorSliceLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_back_face, equator_row,
		rubiks_cube_rotate_equator_slice_left,
		rubiks_cube_right_face, equator_row,
		"source span (back face equator row) wasn't reversed");
}


Test(Cube, rotateEquatorSliceLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_right_face, equator_row,
		rubiks_cube_rotate_equator_slice_left,
		rubiks_cube_front_face, equator_row,
		"source span (right face equator row) was reversed");
}


Test(Cube, rotateEquatorSliceLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, equator_row,
		rubiks_cube_rotate_equator_slice_left,
		rubiks_cube_left_face, equator_row,
		"source span (front face equator row) was reversed");
}
