
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateRight_frontFaceGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * oldFrontFace = Cube_frontFace(cube);

	// when
	Cube_rotateRight(cube);

	// then
	Face * newRightFace = Cube_rightFace(cube);
	cr_assert_eq(
		newRightFace,
		oldFrontFace,
		"front face wasn't moved to the right");
}


Test(Cube, rotateRight_rightFaceGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * oldRightFace = Cube_rightFace(cube);

	// when
	Cube_rotateRight(cube);

	// then
	Face * newBackFace = Cube_backFace(cube);
	cr_assert_eq(
		newBackFace,
		oldRightFace,
		"right face wasn't moved to the back");
}


Test(Cube, rotateRight_backFaceGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBackFace = Cube_backFace(cube);

	// when
	Cube_rotateRight(cube);

	// then
	Face * newLeftFace = Cube_leftFace(cube);
	cr_assert_eq(
		newLeftFace,
		oldBackFace,
		"back face wasn't moved to the left");
}


Test(Cube, rotateRight_leftFaceGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * oldLeftFace = Cube_leftFace(cube);

	// when
	Cube_rotateRight(cube);

	// then
	Face * newFrontFace = Cube_frontFace(cube);
	cr_assert_eq(
		newFrontFace,
		oldLeftFace,
		"left face wasn't moved to the front");
}


Test(Cube, rotateCubeRight_bottomFaceIsRotatedAntiClockwise)
{
	test_face_rotated_anticlockwise(
        Cube_bottomFace,
        Cube_rotateRight,
        "bottom face wasn't rotated");
}


Test(Cube, rotateCubeRight_topFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
        Cube_topFace,
        Cube_rotateRight,
        "top face wasn't rotated");
}
