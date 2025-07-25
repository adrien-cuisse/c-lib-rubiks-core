
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateDown_frontFaceGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * oldFrontFace = Cube_frontFace(cube);

	// when
	Cube_rotateDown(cube);

	// then
	Face * newBottomFace = Cube_bottomFace(cube);
	cr_assert_eq(
		newBottomFace,
		oldFrontFace,
		"front face wasn't moved to the bottom");
}


Test(Cube, rotateDown_bottomFaceGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBottomFace = Cube_bottomFace(cube);

	// when
	Cube_rotateDown(cube);

	// then
	Face * newBackFace = Cube_backFace(cube);
	cr_assert_eq(
		newBackFace,
		oldBottomFace,
		"bottom face wasn't moved to the back");
}


Test(Cube, rotateDown_backFaceGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBackFace = Cube_backFace(cube);

	// when
	Cube_rotateDown(cube);

	// then
	Face * newTopFace = Cube_topFace(cube);
	cr_assert_eq(
		newTopFace,
		oldBackFace,
		"back face wasn't moved to the top");
}


Test(Cube, rotateDown_topFaceGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * oldTopFace = Cube_topFace(cube);

	// when
	Cube_rotateDown(cube);

	// then
	Face * newFrontFace = Cube_frontFace(cube);
	cr_assert_eq(
		newFrontFace,
		oldTopFace,
		"top face wasn't moved to the front");
}


Test(Cube, rotateCubeDown_leftFaceIsRotatedClockwise)
{
	test_face_rotated_clockwise(
        Cube_leftFace,
        Cube_rotateDown,
        "left face wasn't rotated");
}


Test(Cube, rotateCubeDown_rightFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
        Cube_rightFace,
        Cube_rotateDown,
        "right face wasn't rotated");
}
