
#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateDown_frontFaceGoesBottom)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	struct rbc_face * old_front_face = rubiks_cube_front_face(cube);

	// when
	rubiks_cube_rotate_down(cube);

	// then
	struct rbc_face * new_bottom_face = rubiks_cube_bottom_face(cube);
	cr_assert_eq(
		new_bottom_face,
		old_front_face,
		"front face wasn't moved to the bottom");
}


Test(Cube, rotateDown_bottomFaceGoesBack)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	struct rbc_face * old_bottom_face = rubiks_cube_bottom_face(cube);

	// when
	rubiks_cube_rotate_down(cube);

	// then
	struct rbc_face * new_back_face = rubiks_cube_back_face(cube);
	cr_assert_eq(
		new_back_face,
		old_bottom_face,
		"bottom face wasn't moved to the back");
}


Test(Cube, rotateDown_backFaceGoesTop)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	struct rbc_face * old_back_face = rubiks_cube_back_face(cube);

	// when
	rubiks_cube_rotate_down(cube);

	// then
	struct rbc_face * new_top_face = rubiks_cube_top_face(cube);
	cr_assert_eq(
		new_top_face,
		old_back_face,
		"back face wasn't moved to the top");
}


Test(Cube, rotateDown_topFaceGoesFront)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	struct rbc_face * old_top_face = rubiks_cube_top_face(cube);

	// when
	rubiks_cube_rotate_down(cube);

	// then
	struct rbc_face * new_front_face = rubiks_cube_front_face(cube);
	cr_assert_eq(
		new_front_face,
		old_top_face,
		"top face wasn't moved to the front");
}


Test(Cube, rotateDown_leftFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_left_face,
		rubiks_cube_rotate_down,
		"left face wasn't rotated");
}


Test(Cube, rotateDown_rightFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rubiks_cube_right_face,
		rubiks_cube_rotate_down,
		"right face wasn't rotated");
}
