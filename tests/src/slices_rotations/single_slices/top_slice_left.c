
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateTopSliceLeft_frontFaceTopRow_movesTo_leftFaceTopRow)
{
	test_span_moved(
		rubiks_cube_front_face, top_row,
		rubiks_cube_rotate_top_slice_left,
		rubiks_cube_left_face, top_row,
		"front face top row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSliceLeft_leftFaceTopRow_movesTo_backFaceBottomRow)
{
	test_span_moved(
		rubiks_cube_left_face, top_row,
		rubiks_cube_rotate_top_slice_left,
		rubiks_cube_back_face, bottom_row,
		"left face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSliceLeft_backFaceBottomRow_movesTo_rightFaceTopRow)
{
	test_span_moved(
		rubiks_cube_back_face, bottom_row,
		rubiks_cube_rotate_top_slice_left,
		rubiks_cube_right_face, top_row,
		"back face bottom row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSliceLeft_rightFaceTopRow_movesTo_frontFaceTopRow)
{
	test_span_moved(
		rubiks_cube_right_face, top_row,
		rubiks_cube_rotate_top_slice_left,
		rubiks_cube_front_face, top_row,
		"right face top row wasn't moved to the front face top row");
}


Test(Cube, rotateTopSliceLeft_topFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_top_face,
		rubiks_cube_rotate_top_slice_left,
		"top face wasn't rotated");
}


Test(Cube, rotateTopSliceLeft_leftFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_left_face, top_row,
		rubiks_cube_rotate_top_slice_left,
		rubiks_cube_back_face, bottom_row,
		"source span (left face top row) wasn't reversed");
}


Test(Cube, rotateTopSliceLeft_backFaceBottomRow_movesTo_rightFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rubiks_cube_back_face, bottom_row,
		rubiks_cube_rotate_top_slice_left,
		rubiks_cube_right_face, top_row,
		"source span (back face bottom row) wasn't reversed");
}


Test(Cube, rotateTopSliceLeft_rightFaceTopRow_movesTo_frontFaceTopRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_right_face, top_row,
		rubiks_cube_rotate_top_slice_left,
		rubiks_cube_front_face, top_row,
		"source span (right face top row) was reversed");
}


Test(Cube, rotateTopSliceLeft_frontFaceTopRow_movesTo_leftFaceTopRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, top_row,
		rubiks_cube_rotate_top_slice_left,
		rubiks_cube_left_face, top_row,
		"source span (front face top row) was reversed");
}
