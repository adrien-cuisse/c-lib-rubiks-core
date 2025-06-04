
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


Test(Cube, rotateCubeLeft_leftFaceIsRotatedTwice)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	Cube_rotateLeft(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceAfterRotation);
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


Test(Cube, rotateCubeLeft_bottomFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceBeforeRotation);

	// when
	Cube_rotateLeft(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceAfterRotation);
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


Test(Cube, rotateCubeLeft_backFaceIsRotatedTwice)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceBeforeRotation);

	// when
	Cube_rotateLeft(cube);

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


Test(Cube, rotateCubeLeft_topFaceIsRotatedAntiClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceBeforeRotation);

	// when
	Cube_rotateLeft(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceAfterRotation);
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
