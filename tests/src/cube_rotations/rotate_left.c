
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateLeft_rightFaceGoesFront)
{
	// given
	Cube * cube = rubiks_cube_create();
	Face * old_right_face = rubiks_cube_right_face(cube);

	// when
	rubiks_cube_rotate_left(cube);

	// then
	Face * new_front_face = rubiks_cube_front_face(cube);
	cr_assert_eq(
		new_front_face,
		old_right_face,
		"right face wasn't moved to the front");
}


Test(Cube, rotateLeft_backFaceGoesRight)
{
	// given
	Cube * cube = rubiks_cube_create();
	Face * old_back_face = rubiks_cube_back_face(cube);

	// when
	rubiks_cube_rotate_left(cube);

	// then
	Face * new_right_face = rubiks_cube_right_face(cube);
	cr_assert_eq(
		new_right_face,
		old_back_face,
		"back face wasn't moved to the right");
}


Test(Cube, rotateLeft_leftFaceGoesBack)
{
	// given
	Cube * cube = rubiks_cube_create();
	Face * old_left_face = rubiks_cube_left_face(cube);

	// when
	rubiks_cube_rotate_left(cube);

	// then
	Face * new_back_face = rubiks_cube_back_face(cube);
	cr_assert_eq(
		new_back_face,
		old_left_face,
		"left face wasn't moved to the back");
}


Test(Cube, rotateLeft_frontFaceGoesLeft)
{
	// given
	Cube * cube = rubiks_cube_create();
	Face * old_front_face = rubiks_cube_front_face(cube);

	// when
	rubiks_cube_rotate_left(cube);

	// then
	Face * new_left_face = rubiks_cube_left_face(cube);
	cr_assert_eq(
		new_left_face,
		old_front_face,
		"front face wasn't moved to the left");
}


Test(Cube, rotateLeft_bottomFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
		rubiks_cube_bottom_face,
		rubiks_cube_rotate_left,
		"bottom face wasn't rotated");
}


Test(Cube, rotateLeft_topFaceIsRotatedAntiClockwise)
{
	test_face_rotated_anticlockwise(
		rubiks_cube_top_face,
		rubiks_cube_rotate_left,
		"top face wasn't rotated");
}
