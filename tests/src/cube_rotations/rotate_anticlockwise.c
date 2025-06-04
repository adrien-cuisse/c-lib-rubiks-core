
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
	cr_assert_eq(newLeftFace, oldTopFace, "top face wasn't moved to the left");
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
	cr_assert_eq(newBottomFace, oldLeftFace, "left face wasn't moved to the bottom");
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
	cr_assert_eq(newRightFace, oldBottomFace, "bottom face wasn't moved to the right");
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
	cr_assert_eq(newTopFace, oldRightFace, "right face wasn't moved to the top");
}


Test(Cube, rotateCubeAnticlockwise_leftFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceAfterRotation);
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


Test(Cube, rotateCubeAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, faceAfterRotation);
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


Test(Cube, rotateCubeAnticlockwise_rightFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

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


Test(Cube, rotateCubeAnticlockwise_bottomFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

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


Test(Cube, rotateCubeAnticlockwise_backFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceAfterRotation);
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


Test(Cube, rotateCubeAnticlockwise_topFaceIsRotatedAntiClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

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
