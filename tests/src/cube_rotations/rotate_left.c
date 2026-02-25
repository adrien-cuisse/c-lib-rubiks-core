
#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateLeft_rightFaceGoesFront)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_right_face = rbc_cube_right_face(cube);

	// when
	rbc_rotate_cube_left(cube);

	// then
	struct rbc_face * new_front_face = rbc_cube_front_face(cube);
	cr_assert_eq(
		new_front_face,
		old_right_face,
		"right face wasn't moved to the front");
}


Test(Cube, rotateLeft_backFaceGoesRight)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_back_face = rbc_cube_back_face(cube);

	// when
	rbc_rotate_cube_left(cube);

	// then
	struct rbc_face * new_right_face = rbc_cube_right_face(cube);
	cr_assert_eq(
		new_right_face,
		old_back_face,
		"back face wasn't moved to the right");
}


Test(Cube, rotateLeft_leftFaceGoesBack)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_left_face = rbc_cube_left_face(cube);

	// when
	rbc_rotate_cube_left(cube);

	// then
	struct rbc_face * new_back_face = rbc_cube_back_face(cube);
	cr_assert_eq(
		new_back_face,
		old_left_face,
		"left face wasn't moved to the back");
}


Test(Cube, rotateLeft_frontFaceGoesLeft)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_front_face = rbc_cube_front_face(cube);

	// when
	rbc_rotate_cube_left(cube);

	// then
	struct rbc_face * new_left_face = rbc_cube_left_face(cube);
	cr_assert_eq(
		new_left_face,
		old_front_face,
		"front face wasn't moved to the left");
}


Test(Cube, rotateLeft_bottomFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rbc_cube_bottom_face,
		rbc_rotate_cube_left,
		"bottom face wasn't rotated");
}


Test(Cube, rotateLeft_topFaceIsRotatedAntiClockwise)
{
	test_face_rotated_anticlockwise(
		rbc_cube_top_face,
		rbc_rotate_cube_left,
		"top face wasn't rotated");
}
