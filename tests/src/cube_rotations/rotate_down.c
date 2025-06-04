
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
	cr_assert_eq(newBottomFace, oldFrontFace, "front face wasn't moved to the bottom");
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
	cr_assert_eq(newBackFace, oldBottomFace, "bottom face wasn't moved to the back");
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
	cr_assert_eq(newTopFace, oldBackFace, "back face wasn't moved to the top");
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
	cr_assert_eq(newFrontFace, oldTopFace, "top face wasn't moved to the front");
}


Test(Cube, rotateCubeDown_leftFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	Cube_rotateDown(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[FACE_SIZE - 1 - columnIndex][rowIndex]);
		}
	}
}


Test(Cube, rotateCubeDown_rightFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	Cube_rotateDown(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[columnIndex][FACE_SIZE - 1 - rowIndex]);
		}
	}
}
