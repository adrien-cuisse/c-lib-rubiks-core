
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateTopSliceRight_frontFaceTopRow_movesTo_rightFaceTopRow)
{
	test_span_moved(
		rbc_cube_front_face, top_row,
		rbc_rotate_cube_top_slice_right,
		rbc_cube_right_face, top_row,
		"front face top row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSliceRight_rightFaceTopRow_movesTo_backFaceBottomRow)
{
	test_span_moved(
		rbc_cube_right_face, top_row,
		rbc_rotate_cube_top_slice_right,
		rbc_cube_back_face, bottom_row,
		"right face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSliceRight_backFaceBottomRow_movesTo_leftFaceTopRow)
{
	test_span_moved(
		rbc_cube_back_face, bottom_row,
		rbc_rotate_cube_top_slice_right,
		rbc_cube_left_face, top_row,
		"back face bottom row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSliceRight_leftFaceTopRow_movesTo_frontFaceTopRow)
{
	test_span_moved(
		rbc_cube_left_face, top_row,
		rbc_rotate_cube_top_slice_right,
		rbc_cube_front_face, top_row,
		"left face top row wasn't moved to the front face top row");
}


Test(Cube, rotateTopSliceRight_topFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rbc_cube_top_face,
		rbc_rotate_cube_top_slice_right,
		"top face wasn't rotated");
}


Test(Cube, rotateTopSliceRight_rightFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_right_face, top_row,
		rbc_rotate_cube_top_slice_right,
		rbc_cube_back_face, bottom_row,
		"source span (right face top row) wasn't reversed");
}


Test(Cube, rotateTopSliceRight_backFaceBottomRow_movesTo_leftFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_back_face, bottom_row,
		rbc_rotate_cube_top_slice_right,
		rbc_cube_left_face, top_row,
		"source span (back face bottom row) wasn't reversed");
}


Test(Cube, rotateTopSliceRight_leftFaceTopRow_movesTo_frontFaceTopRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_left_face, top_row,
		rbc_rotate_cube_top_slice_right,
		rbc_cube_front_face, top_row,
		"source span (left face top row) was reversed");
}


Test(Cube, rotateTopSliceRight_frontFaceTopRow_movesTo_rightFaceTopRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, top_row,
		rbc_rotate_cube_top_slice_right,
		rbc_cube_right_face, top_row,
		"source span (front face top row) was reversed");
}
