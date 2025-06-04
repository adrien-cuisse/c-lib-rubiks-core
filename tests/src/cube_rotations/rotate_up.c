
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateUp_frontFaceGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * oldFrontFace = Cube_frontFace(cube);
	// when
	Cube_rotateUp(cube);
	// then
	Face * newTopFace = Cube_topFace(cube);
	cr_assert_eq(newTopFace, oldFrontFace, "front face wasn't moved to the top");
}


Test(Cube, rotateUp_topFaceGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * oldTopFace = Cube_topFace(cube);
	// when
	Cube_rotateUp(cube);
	// then
	Face * newBackFace = Cube_backFace(cube);
	cr_assert_eq(newBackFace, oldTopFace, "top face wasn't moved to the back");
}


Test(Cube, rotateUp_backFaceGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBackFace = Cube_backFace(cube);
	// when
	Cube_rotateUp(cube);
	// then
	Face * newBottomFace = Cube_bottomFace(cube);
	cr_assert_eq(newBottomFace, oldBackFace, "back face wasn't moved to the bottom");
}


Test(Cube, rotateUp_bottomFaceGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBottomFace = Cube_bottomFace(cube);
	// when
	Cube_rotateUp(cube);
	// then
	Face * newFrontFace = Cube_frontFace(cube);
	cr_assert_eq(newFrontFace, oldBottomFace, "bottom face wasn't moved to the front");
}


Test(Cube, rotateCubeUp_leftFaceIsRotatedAntiClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	Cube_rotateUp(cube);

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


Test(Cube, rotateCubeUp_rightFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	Cube_rotateUp(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceAfterRotation);
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
