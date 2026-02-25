
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateBottomSlicesLeft_frontFaceBottomRow_movesTo_leftFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, bottom_row,
		rbc_rotate_cube_bottom_slices_left,
		rbc_cube_left_face, bottom_row,
		"front face bottom row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSlicesLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_front_face, equator_row,
		rbc_rotate_cube_bottom_slices_left,
		rbc_cube_left_face, equator_row,
		"front face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateBottomSlicesLeft_leftFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_left_face, bottom_row,
		rbc_rotate_cube_bottom_slices_left,
		rbc_cube_back_face, top_row,
		"left face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSlicesLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_left_face, equator_row,
		rbc_rotate_cube_bottom_slices_left,
		rbc_cube_back_face, equator_row,
		"left face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateBottomSlicesLeft_backFaceTopRow_movesTo_rightFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_back_face, top_row,
		rbc_rotate_cube_bottom_slices_left,
		rbc_cube_right_face, bottom_row,
		"back face top row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSlicesLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		rbc_cube_back_face, equator_row,
		rbc_rotate_cube_bottom_slices_left,
		rbc_cube_right_face, equator_row,
		"back face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateBottomSlicesLeft_rightFaceBottomRow_movesTo_frontFaceBottomRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_right_face, bottom_row,
		rbc_rotate_cube_bottom_slices_left,
		rbc_cube_front_face, bottom_row,
		"right face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateBottomSlicesLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		rbc_cube_right_face, equator_row,
		rbc_rotate_cube_bottom_slices_left,
		rbc_cube_front_face, equator_row,
		"right face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateBottomSlicesLeft_bottomFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rbc_cube_bottom_face,
		rbc_rotate_cube_bottom_slices_left,
		"bottom face wasn't rotated");
}
