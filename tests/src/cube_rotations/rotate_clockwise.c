

#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateClockwise_topFaceGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * oldTopFace = Cube_topFace(cube);

	// when
	Cube_rotateClockwise(cube);

	// then
	Face * newRightFace = Cube_rightFace(cube);
	cr_assert_eq(newRightFace, oldTopFace, "top face wasn't moved to the right");
}


Test(Cube, rotateClockwise_rightFaceGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * oldRightFace = Cube_rightFace(cube);

	// when
	Cube_rotateClockwise(cube);

	// then
	Face * newBottomFace = Cube_bottomFace(cube);
	cr_assert_eq(newBottomFace, oldRightFace, "right face wasn't moved to the bottom");
}


Test(Cube, rotateClockwise_bottomFaceGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBottomFace = Cube_bottomFace(cube);

	// when
	Cube_rotateClockwise(cube);

	// then
	Face * newLeftFace = Cube_leftFace(cube);
	cr_assert_eq(newLeftFace, oldBottomFace, "bottom face wasn't moved to the left");
}


Test(Cube, rotateClockwise_leftFaceGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * oldLeftFace = Cube_leftFace(cube);

	// when
	Cube_rotateClockwise(cube);

	// then
	Face * newTopFace = Cube_topFace(cube);
	cr_assert_eq(newTopFace, oldLeftFace, "left face wasn't moved to the top");
}


Test(Cube, rotateCubeClockwise_frontFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
        Cube_frontFace,
        Cube_rotateClockwise,
        "front face wasn't rotated");
}


Test(Cube, rotateCubeClockwise_backFaceIsRotatedAntiClockwise)
{
	test_face_rotated_anticlockwise(
        Cube_backFace,
        Cube_rotateClockwise,
        "back face wasn't rotated");
}
