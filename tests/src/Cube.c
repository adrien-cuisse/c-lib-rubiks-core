
#include <criterion/criterion.h>

#include "../../include/Cube.h"




Test(Cube, isInitializedWithBlueFaceInFront)
{
	// given
	Cube * cube = rubiks_cube_create();
	// when
	Face * front_face = rubiks_cube_front_face(cube);
	// then
	Color front_face_color = rubiks_face_color(front_face);
	cr_assert_eq(front_face_color, BLUE, "front face is not blue");
}


Test(Cube, isInitializedWithRedFaceOnTheLeft)
{
	// given
	Cube * cube = rubiks_cube_create();
	// when
	Face * left_face = rubiks_cube_left_face(cube);
	// then
	Color left_face_color = rubiks_face_color(left_face);
	cr_assert_eq(left_face_color, RED, "left face is not red");
}


Test(Cube, isInitializedWithOrangeFaceOnTheRight)
{
	// given
	Cube * cube = rubiks_cube_create();
	// when
	Face * right_face = rubiks_cube_right_face(cube);
	// then
	Color right_face_color = rubiks_face_color(right_face);
	cr_assert_eq(right_face_color, ORANGE, "right face is not orange");
}


Test(Cube, isInitializedWithWhiteFaceOnTop)
{
	// given
	Cube * cube = rubiks_cube_create();
	// when
	Face * top_face = rubiks_cube_top_face(cube);
	// then
	Color top_face_color = rubiks_face_color(top_face);
	cr_assert_eq(top_face_color, WHITE, "top face is not white");
}


Test(Cube, isInitializedWithYellowFaceAtBottom)
{
	// given
	Cube * cube = rubiks_cube_create();
	// when
	Face * bottom_face = rubiks_cube_bottom_face(cube);
	// then
	Color bottom_face_color = rubiks_face_color(bottom_face);
	cr_assert_eq(bottom_face_color, YELLOW, "bottom face is not yellow");
}


Test(Cube, isInitializedWithGreenFaceOnTheBack)
{
	// given
	Cube * cube = rubiks_cube_create();
	// when
	Face * back_face = rubiks_cube_back_face(cube);
	// then
	Color back_face_color = rubiks_face_color(back_face);
	cr_assert_eq(back_face_color, GREEN, "back face is not green");
}
