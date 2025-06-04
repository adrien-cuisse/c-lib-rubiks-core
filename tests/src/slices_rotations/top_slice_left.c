
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateTopSliceLeft_frontFaceTopRow_movesTo_leftFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, oldFrontFaceTopRow);

	// when
	Cube_rotateTopSliceLeft(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		newLeftFaceTopRow,
		oldFrontFaceTopRow,
		FACE_SIZE,
		"front face top row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSliceLeft_leftFaceTopRow_movesTo_backFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, oldLeftFaceTopRow);

	// when
	Cube_rotateTopSliceLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		newBackFaceBottomRow,
		oldLeftFaceTopRow,
		FACE_SIZE,
		"left face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSliceLeft_backFaceBottomRow_movesTo_rightFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, oldBackFaceBottomRow);

	// when
	Cube_rotateTopSliceLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, newRightFaceTopRow);
	cr_assert_arr_eq(
		newRightFaceTopRow,
		oldBackFaceBottomRow,
		FACE_SIZE,
		"back face bottom row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSliceLeft_rightFaceTopRow_movesTo_frontFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, oldRightFaceTopRow);

	// when
	Cube_rotateTopSliceLeft(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, newFrontFaceTopRow);
	cr_assert_arr_eq(
		newFrontFaceTopRow,
		oldRightFaceTopRow,
		FACE_SIZE,
		"right face top row wasn't moved to the front face top row");
}


Test(Cube, rotateTopSliceLeft_topFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, beforeRotation);

	// when
	Cube_rotateTopSliceLeft(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, topFace, "top");
}
