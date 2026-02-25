
#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateAnticlockwise_topFaceGoesLeft)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_top_face = rbc_cube_top_face(cube);

	// when
	rbc_rotate_cube_anticlockwise(cube);

	// then
	struct rbc_face * new_left_face = rbc_cube_left_face(cube);
	cr_assert_eq(
		new_left_face,
		old_top_face,
		"top face wasn't moved to the left");
}


Test(Cube, rotateAnticlockwise_leftFaceGoesBottom)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_left_face = rbc_cube_left_face(cube);

	// when
	rbc_rotate_cube_anticlockwise(cube);

	// then
	struct rbc_face * new_bottom_face = rbc_cube_bottom_face(cube);
	cr_assert_eq(
		new_bottom_face,
		old_left_face,
		"left face wasn't moved to the bottom");
}


Test(Cube, rotateAnticlockwise_bottomFaceGoesRight)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_bottom_face = rbc_cube_bottom_face(cube);

	// when
	rbc_rotate_cube_anticlockwise(cube);

	// then
	struct rbc_face * new_right_face = rbc_cube_right_face(cube);
	cr_assert_eq(
		new_right_face,
		old_bottom_face,
		"bottom face wasn't moved to the right");
}


Test(Cube, rotateAnticlockwise_rightFaceGoesTop)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_right_face = rbc_cube_right_face(cube);

	// when
	rbc_rotate_cube_anticlockwise(cube);

	// then
	struct rbc_face * new_top_face = rbc_cube_top_face(cube);
	cr_assert_eq(
		new_top_face,
		old_right_face,
		"right face wasn't moved to the top");
}


Test(Cube, rotateAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rbc_cube_front_face,
		rbc_rotate_cube_anticlockwise,
		"front face wasn't rotated");
}


Test(Cube, rotateAnticlockwise_backFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rbc_cube_back_face,
		rbc_rotate_cube_anticlockwise,
		"back face wasn't rotated");
}
