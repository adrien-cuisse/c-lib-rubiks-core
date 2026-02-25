
#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateRight_frontFaceGoesRight)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	struct rbc_face * old_front_face = rubiks_cube_front_face(cube);

	// when
	rubiks_cube_rotate_right(cube);

	// then
	struct rbc_face * new_right_face = rubiks_cube_right_face(cube);
	cr_assert_eq(
		new_right_face,
		old_front_face,
		"front face wasn't moved to the right");
}


Test(Cube, rotateRight_rightFaceGoesBack)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	struct rbc_face * old_right_face = rubiks_cube_right_face(cube);

	// when
	rubiks_cube_rotate_right(cube);

	// then
	struct rbc_face * new_back_face = rubiks_cube_back_face(cube);
	cr_assert_eq(
		new_back_face,
		old_right_face,
		"right face wasn't moved to the back");
}


Test(Cube, rotateRight_backFaceGoesLeft)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	struct rbc_face * old_back_face = rubiks_cube_back_face(cube);

	// when
	rubiks_cube_rotate_right(cube);

	// then
	struct rbc_face * new_left_face = rubiks_cube_left_face(cube);
	cr_assert_eq(
		new_left_face,
		old_back_face,
		"back face wasn't moved to the left");
}


Test(Cube, rotateRight_leftFaceGoesFront)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	struct rbc_face * old_left_face = rubiks_cube_left_face(cube);

	// when
	rubiks_cube_rotate_right(cube);

	// then
	struct rbc_face * new_front_face = rubiks_cube_front_face(cube);
	cr_assert_eq(
		new_front_face,
		old_left_face,
		"left face wasn't moved to the front");
}


Test(Cube, rotateRight_bottomFaceIsRotatedAntiClockwise)
{
	test_face_rotated_anticlockwise(
		rubiks_cube_bottom_face,
		rubiks_cube_rotate_right,
		"bottom face wasn't rotated");
}


Test(Cube, rotateRight_topFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_top_face,
		rubiks_cube_rotate_right,
		"top face wasn't rotated");
}
