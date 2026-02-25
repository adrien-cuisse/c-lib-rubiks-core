
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateBottomSliceLeft_frontFaceBottomRow_movesTo_leftFaceBottomRow)
{
	test_span_moved(
		rbc_cube_front_face, bottom_row,
		rbc_rotate_cube_bottom_slice_left,
		rbc_cube_left_face, bottom_row,
		"front face bottom row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSliceLeft_leftFaceBottomRow_movesTo_backFaceTopRow)
{
	test_span_moved(
		rbc_cube_left_face, bottom_row,
		rbc_rotate_cube_bottom_slice_left,
		rbc_cube_back_face, top_row,
		"left face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSliceLeft_backFaceTopRow_movesTo_rightFaceBottomRow)
{
	test_span_moved(
		rbc_cube_back_face, top_row,
		rbc_rotate_cube_bottom_slice_left,
		rbc_cube_right_face, bottom_row,
		"back face top row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSliceLeft_rightFaceBottomRow_movesTo_frontFaceBottomRow)
{
	test_span_moved(
		rbc_cube_right_face, bottom_row,
		rbc_rotate_cube_bottom_slice_left,
		rbc_cube_front_face, bottom_row,
		"right face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateBottomSliceLeft_bottomFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rbc_cube_bottom_face,
		rbc_rotate_cube_bottom_slice_left,
		"bottom face wasn't rotated");
}


Test(Cube, rotateBottomSliceLeft_leftFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_left_face, bottom_row,
		rbc_rotate_cube_bottom_slice_left,
		rbc_cube_back_face, top_row,
		"source span (left face bottom row) wasn't reversed");
}


Test(Cube, rotateBottomSliceLeft_backFaceTopRow_movesTo_rightFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_back_face, top_row,
		rbc_rotate_cube_bottom_slice_left,
		rbc_cube_right_face, bottom_row,
		"source span (back face top row) wasn't reversed");
}


Test(Cube, rotateBottomSliceLeft_rightFaceBottomRow_movesTo_frontFaceBottomRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_right_face, bottom_row,
		rbc_rotate_cube_bottom_slice_left,
		rbc_cube_front_face, bottom_row,
		"source span (right face bottom row) was reversed");
}


Test(Cube, rotateBottomSliceLeft_frontFaceBottomRow_movesTo_leftFaceBottomRow_notReversed)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, bottom_row,
		rbc_rotate_cube_bottom_slice_left,
		rbc_cube_left_face, bottom_row,
		"source span (front face bottom row) was reversed");
}
