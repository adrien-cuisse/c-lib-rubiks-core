
#include "../../include/Cube.h"

#include <criterion/criterion.h>




Test(Cube, isInitializedWithBlueFaceInFront)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	// when
	struct rbc_face * front_face = rubiks_cube_front_face(cube);
	// then
	enum rbc_color front_face_color = rubiks_face_color(front_face);
	cr_assert_eq(front_face_color, BLUE, "front face is not blue");
}


Test(Cube, isInitializedWithRedFaceOnTheLeft)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	// when
	struct rbc_face * left_face = rubiks_cube_left_face(cube);
	// then
	enum rbc_color left_face_color = rubiks_face_color(left_face);
	cr_assert_eq(left_face_color, RED, "left face is not red");
}


Test(Cube, isInitializedWithOrangeFaceOnTheRight)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	// when
	struct rbc_face * right_face = rubiks_cube_right_face(cube);
	// then
	enum rbc_color right_face_color = rubiks_face_color(right_face);
	cr_assert_eq(right_face_color, ORANGE, "right face is not orange");
}


Test(Cube, isInitializedWithWhiteFaceOnTop)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	// when
	struct rbc_face * top_face = rubiks_cube_top_face(cube);
	// then
	enum rbc_color top_face_color = rubiks_face_color(top_face);
	cr_assert_eq(top_face_color, WHITE, "top face is not white");
}


Test(Cube, isInitializedWithYellowFaceAtBottom)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	// when
	struct rbc_face * bottom_face = rubiks_cube_bottom_face(cube);
	// then
	enum rbc_color bottom_face_color = rubiks_face_color(bottom_face);
	cr_assert_eq(bottom_face_color, YELLOW, "bottom face is not yellow");
}


Test(Cube, isInitializedWithGreenFaceOnTheBack)
{
	// given
	struct rbc_cube * cube = rubiks_cube_create();
	// when
	struct rbc_face * back_face = rubiks_cube_back_face(cube);
	// then
	enum rbc_color back_face_color = rubiks_face_color(back_face);
	cr_assert_eq(back_face_color, GREEN, "back face is not green");
}
