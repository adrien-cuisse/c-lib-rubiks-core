
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateLeft_rightFaceGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * oldRightFace = Cube_rightFace(cube);

	// when
	Cube_rotateLeft(cube);

	// then
	Face * newFrontFace = Cube_frontFace(cube);
	cr_assert_eq(newFrontFace, oldRightFace, "right face wasn't moved to the front");
}


Test(Cube, rotateLeft_backFaceGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBackFace = Cube_backFace(cube);

	// when
	Cube_rotateLeft(cube);

	// then
	Face * newRightFace = Cube_rightFace(cube);
	cr_assert_eq(newRightFace, oldBackFace, "back face wasn't moved to the right");
}


Test(Cube, rotateLeft_leftFaceGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * oldLeftFace = Cube_leftFace(cube);

	// when
	Cube_rotateLeft(cube);

	// then
	Face * newBackFace = Cube_backFace(cube);
	cr_assert_eq(newBackFace, oldLeftFace, "left face wasn't moved to the back");
}


Test(Cube, rotateLeft_frontFaceGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * oldFrontFace = Cube_frontFace(cube);

	// when
	Cube_rotateLeft(cube);

	// then
	Face * newLeftFace = Cube_leftFace(cube);
	cr_assert_eq(newLeftFace, oldFrontFace, "front face wasn't moved to the left");
}


Test(Cube, rotateCubeLeft_bottomFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
        Cube_bottomFace,
        Cube_rotateLeft,
        "bottom face wasn't rotated");
}


Test(Cube, rotateCubeLeft_topFaceIsRotatedAntiClockwise)
{
	test_face_rotated_anticlockwise(
        Cube_topFace,
        Cube_rotateLeft,
        "top face wasn't rotated");
}
