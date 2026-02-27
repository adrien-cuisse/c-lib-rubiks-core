
#include "../../include/Cube.h"

#include <criterion/criterion.h>




Test(Cube, isInitializedWithBlueFaceInFront)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	// when
	struct rbc_face * front_face = rbc_cube_front_face(cube);
	// then
	enum rbc_color front_face_color = rbc_face_color(front_face);
	cr_assert_eq(front_face_color, RBC_BLUE, "front face is not blue");
}


Test(Cube, isInitializedWithRedFaceOnTheLeft)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	// when
	struct rbc_face * left_face = rbc_cube_left_face(cube);
	// then
	enum rbc_color left_face_color = rbc_face_color(left_face);
	cr_assert_eq(left_face_color, RBC_RED, "left face is not red");
}


Test(Cube, isInitializedWithOrangeFaceOnTheRight)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	// when
	struct rbc_face * right_face = rbc_cube_right_face(cube);
	// then
	enum rbc_color right_face_color = rbc_face_color(right_face);
	cr_assert_eq(right_face_color, RBC_ORANGE, "right face is not orange");
}


Test(Cube, isInitializedWithWhiteFaceOnTop)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	// when
	struct rbc_face * top_face = rbc_cube_top_face(cube);
	// then
	enum rbc_color top_face_color = rbc_face_color(top_face);
	cr_assert_eq(top_face_color, RBC_WHITE, "top face is not white");
}


Test(Cube, isInitializedWithYellowFaceAtBottom)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	// when
	struct rbc_face * bottom_face = rbc_cube_bottom_face(cube);
	// then
	enum rbc_color bottom_face_color = rbc_face_color(bottom_face);
	cr_assert_eq(bottom_face_color, RBC_YELLOW, "bottom face is not yellow");
}


Test(Cube, isInitializedWithGreenFaceOnTheBack)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	// when
	struct rbc_face * back_face = rbc_cube_back_face(cube);
	// then
	enum rbc_color back_face_color = rbc_face_color(back_face);
	cr_assert_eq(back_face_color, RBC_GREEN, "back face is not green");
}


Test(Cube, orientate_badFrontColor_notRotated)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	enum rbc_color old_front_face_color = rbc_face_color(rbc_cube_front_face(cube));

	// when
	enum rbc_color back_face_color = rbc_face_color(rbc_cube_back_face(cube));
	rbc_orientate_cube(cube, 42, back_face_color);

	// then
	enum rbc_color new_front_face_color = rbc_face_color(rbc_cube_front_face(cube));
	cr_assert_eq(old_front_face_color, new_front_face_color);
}


Test(Cube, orientate_badTopColor_notRotated)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	enum rbc_color old_top_face_color = rbc_face_color(rbc_cube_top_face(cube));

	// when
	enum rbc_color back_face_color = rbc_face_color(rbc_cube_back_face(cube));
	rbc_orientate_cube(cube, back_face_color, 42);

	// then
	enum rbc_color new_top_face_color = rbc_face_color(rbc_cube_top_face(cube));
	cr_assert_eq(old_top_face_color, new_top_face_color);
}


Test(Cube, orientate_sameColorOnBothFaces_notRotated)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	enum rbc_color old_front_face_color = rbc_face_color(rbc_cube_front_face(cube));

	// when
	enum rbc_color back_face_color = rbc_face_color(rbc_cube_back_face(cube));
	rbc_orientate_cube(cube, back_face_color, back_face_color);

	// then
	enum rbc_color new_front_face_color = rbc_face_color(rbc_cube_front_face(cube));
	cr_assert_eq(old_front_face_color, new_front_face_color);
}


Test(Cube, orientate_oppositeColors_notRotated)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	enum rbc_color old_front_face_color = rbc_face_color(rbc_cube_front_face(cube));

	// when
	enum rbc_color left_face_color = rbc_face_color(rbc_cube_left_face(cube));
	enum rbc_color right_face_color = rbc_face_color(rbc_cube_right_face(cube));
	rbc_orientate_cube(cube, left_face_color, right_face_color);

	// then
	enum rbc_color new_front_face_color = rbc_face_color(rbc_cube_front_face(cube));
	cr_assert_eq(old_front_face_color, new_front_face_color);
}


Test(Cube, orientate_validColors_correctFrontFace)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	enum rbc_color old_back_face_color = rbc_face_color(rbc_cube_back_face(cube));

	// when
	enum rbc_color old_bottom_face_color = rbc_face_color(rbc_cube_bottom_face(cube));
	rbc_orientate_cube(cube, old_back_face_color, old_bottom_face_color);

	// then
	enum rbc_color new_front_face_color = rbc_face_color(rbc_cube_front_face(cube));
	cr_assert_eq(old_back_face_color, new_front_face_color);
}


Test(Cube, orientate_validColors_correctTopFace)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();
	enum rbc_color old_bottom_face_color = rbc_face_color(rbc_cube_bottom_face(cube));

	// when
	enum rbc_color old_back_face_color = rbc_face_color(rbc_cube_back_face(cube));
	rbc_orientate_cube(cube, old_back_face_color, old_bottom_face_color);

	// then
	enum rbc_color new_top_face_color = rbc_face_color(rbc_cube_top_face(cube));
	cr_assert_eq(old_bottom_face_color, new_top_face_color);
}
