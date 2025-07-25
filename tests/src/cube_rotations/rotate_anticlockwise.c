
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateAnticlockwise_topFaceGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * oldTopFace = Cube_topFace(cube);

	// when
	Cube_rotateAnticlockwise(cube);

	// then
	Face * newLeftFace = Cube_leftFace(cube);
	cr_assert_eq(
		newLeftFace,
		oldTopFace,
		"top face wasn't moved to the left");
}


Test(Cube, rotateAnticlockwise_leftFaceGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * oldLeftFace = Cube_leftFace(cube);

	// when
	Cube_rotateAnticlockwise(cube);

	// then
	Face * newBottomFace = Cube_bottomFace(cube);
	cr_assert_eq(
		newBottomFace,
		oldLeftFace,
		"left face wasn't moved to the bottom");
}


Test(Cube, rotateAnticlockwise_bottomFaceGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBottomFace = Cube_bottomFace(cube);

	// when
	Cube_rotateAnticlockwise(cube);

	// then
	Face * newRightFace = Cube_rightFace(cube);
	cr_assert_eq(
		newRightFace,
		oldBottomFace,
		"bottom face wasn't moved to the right");
}


Test(Cube, rotateAnticlockwise_rightFaceGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * oldRightFace = Cube_rightFace(cube);

	// when
	Cube_rotateAnticlockwise(cube);

	// then
	Face * newTopFace = Cube_topFace(cube);
	cr_assert_eq(
		newTopFace,
		oldRightFace,
		"right face wasn't moved to the top");
}


Test(Cube, rotateCubeAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
        Cube_frontFace,
        Cube_rotateAnticlockwise,
        "front face wasn't rotated");
}


Test(Cube, rotateCubeAnticlockwise_backFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
        Cube_backFace,
        Cube_rotateAnticlockwise,
        "back face wasn't rotated");
}
