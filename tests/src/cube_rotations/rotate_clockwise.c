
#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateClockwise_topFaceGoesRight)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	Face * old_top_face = rubiks_cube_top_face(cube);

	// when
	rubiks_cube_rotate_clockwise(cube);

	// then
	Face * new_right_face = rubiks_cube_right_face(cube);
	cr_assert_eq(
		new_right_face,
		old_top_face,
		"top face wasn't moved to the right");
}


Test(Cube, rotateClockwise_rightFaceGoesBottom)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	Face * old_right_face = rubiks_cube_right_face(cube);

	// when
	rubiks_cube_rotate_clockwise(cube);

	// then
	Face * new_bottom_face = rubiks_cube_bottom_face(cube);
	cr_assert_eq(
		new_bottom_face,
		old_right_face,
		"right face wasn't moved to the bottom");
}


Test(Cube, rotateClockwise_bottomFaceGoesLeft)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	Face * old_bottom_face = rubiks_cube_bottom_face(cube);

	// when
	rubiks_cube_rotate_clockwise(cube);

	// then
	Face * new_left_face = rubiks_cube_left_face(cube);
	cr_assert_eq(
		new_left_face,
		old_bottom_face,
		"bottom face wasn't moved to the left");
}


Test(Cube, rotateClockwise_leftFaceGoesTop)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	Face * old_left_face = rubiks_cube_left_face(cube);

	// when
	rubiks_cube_rotate_clockwise(cube);

	// then
	Face * new_top_face = rubiks_cube_top_face(cube);
	cr_assert_eq(
		new_top_face,
		old_left_face,
		"left face wasn't moved to the top");
}


Test(Cube, rotateClockwise_frontFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_front_face,
		rubiks_cube_rotate_clockwise,
		"front face wasn't rotated");
}


Test(Cube, rotateClockwise_backFaceIsRotatedAntiClockwise)
{
	test_face_rotated_anticlockwise(
		rubiks_cube_back_face,
		rubiks_cube_rotate_clockwise,
		"back face wasn't rotated");
}
