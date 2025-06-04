
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
	cr_assert_eq(newRightFace, oldFrontFace, "front face wasn't moved to the right");
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
	cr_assert_eq(newBackFace, oldRightFace, "right face wasn't moved to the back");
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
	cr_assert_eq(newLeftFace, oldBackFace, "back face wasn't moved to the left");
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
	cr_assert_eq(newFrontFace, oldLeftFace, "left face wasn't moved to the front");
}


Test(Cube, rotateCubeRight_rightFaceIsRotatedTwice)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	Cube_rotateRight(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceBeforeRotation[FACE_SIZE - 1 - rowIndex][FACE_SIZE - 1 - columnIndex],
				faceAfterRotation[rowIndex][columnIndex]);
		}
	}
}


Test(Cube, rotateCubeRight_bottomFaceIsRotatedAntiClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceBeforeRotation);

	// when
	Cube_rotateRight(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceAfterRotation);
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


Test(Cube, rotateCubeRight_backFaceIsRotatedTwice)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceBeforeRotation);

	// when
	Cube_rotateRight(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceBeforeRotation[FACE_SIZE - 1 - rowIndex][FACE_SIZE - 1 - columnIndex],
				faceAfterRotation[rowIndex][columnIndex]);
		}
	}
}


Test(Cube, rotateCubeRight_topFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceBeforeRotation);

	// when
	Cube_rotateRight(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceAfterRotation);
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
