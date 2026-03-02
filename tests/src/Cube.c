
#include "../../include/Cube.h"

#include <criterion/criterion.h>




Test(Cube, blue_opposes_green)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();

	// when
	rbc_orientate_cube(cube, RBC_BLUE, RBC_WHITE);

	// then
	struct rbc_face * back_face = rbc_cube_back_face(cube);
	cr_assert_eq(RBC_GREEN, rbc_face_color(back_face));
}


Test(Cube, white_opposes_yellow)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();

	// when
	rbc_orientate_cube(cube, RBC_WHITE, RBC_BLUE);

	// then
	struct rbc_face * back_face = rbc_cube_back_face(cube);
	cr_assert_eq(RBC_YELLOW, rbc_face_color(back_face));
}


Test(Cube, red_opposes_orange)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();

	// when
	rbc_orientate_cube(cube, RBC_RED, RBC_BLUE);

	// then
	struct rbc_face * back_face = rbc_cube_back_face(cube);
	cr_assert_eq(RBC_ORANGE, rbc_face_color(back_face));
}


Test(Cube, blueWhiteRed_clockwiseAroundCorner)
{
	// given
	struct rbc_cube * cube = rbc_create_cube();

	// when
	rbc_orientate_cube(cube, RBC_BLUE, RBC_WHITE);

	// then
	struct rbc_face * left_face = rbc_cube_left_face(cube);
	cr_assert_eq(RBC_RED, rbc_face_color(left_face));
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
