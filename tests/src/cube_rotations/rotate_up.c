
#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateUp_frontFaceGoesTop)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_front_face = rbc_cube_front_face(cube);

	// when
	rbc_rotate_cube_up(cube);

	// then
	struct rbc_face * new_top_face = rbc_cube_top_face(cube);
	cr_assert_eq(
		new_top_face,
		old_front_face,
		"front face wasn't moved to the top");
}


Test(Cube, rotateUp_topFaceGoesBack)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_top_face = rbc_cube_top_face(cube);

	// when
	rbc_rotate_cube_up(cube);

	// then
	struct rbc_face * new_back_face = rbc_cube_back_face(cube);
	cr_assert_eq(
		new_back_face,
		old_top_face,
		"top face wasn't moved to the back");
}


Test(Cube, rotateUp_backFaceGoesBottom)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_back_face = rbc_cube_back_face(cube);

	// when
	rbc_rotate_cube_up(cube);

	// then
	struct rbc_face * new_bottom_face = rbc_cube_bottom_face(cube);
	cr_assert_eq(
		new_bottom_face,
		old_back_face,
		"back face wasn't moved to the bottom");
}


Test(Cube, rotateUp_bottomFaceGoesFront)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	struct rbc_face * old_bottom_face = rbc_cube_bottom_face(cube);

	// when
	rbc_rotate_cube_up(cube);

	// then
	struct rbc_face * new_front_face = rbc_cube_front_face(cube);
	cr_assert_eq(
		new_front_face,
		old_bottom_face,
		"bottom face wasn't moved to the front");
}


Test(Cube, rotateUp_leftFaceIsRotatedAntiClockwise)
{
	test_face_rotated_anticlockwise(
		rbc_cube_left_face,
		rbc_rotate_cube_up,
		"left face wasn't rotated");
}


Test(Cube, rotateUp_rightFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rbc_cube_right_face,
		rbc_rotate_cube_up,
		"right face wasn't rotated");
}
