
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateBottomSliceLeft_frontFaceBottomRow_movesTo_leftFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceBottomRow[FACE_SIZE];
	bottomRow(frontFace, oldFrontFaceBottomRow);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, newLeftFaceBottomRow);
	cr_assert_arr_eq(
		newLeftFaceBottomRow,
		oldFrontFaceBottomRow,
		FACE_SIZE,
		"front face bottom row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSliceLeft_leftFaceBottomRow_movesTo_backFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, oldLeftFaceBottomRow);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceTopRow[FACE_SIZE];
	topRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		newBackFaceTopRow,
		oldLeftFaceBottomRow,
		FACE_SIZE,
		"left face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSliceLeft_backFaceTopRow_movesTo_rightFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	topRow(backFace, oldBackFaceTopRow);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, newRightFaceBottomRow);
	cr_assert_arr_eq(
		newRightFaceBottomRow,
		oldBackFaceTopRow,
		FACE_SIZE,
		"back face top row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSliceLeft_rightFaceBottomRow_movesTo_frontFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, oldRightFaceBottomRow);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceBottomRow[FACE_SIZE];
	bottomRow(frontFace, newFrontFaceBottomRow);
	cr_assert_arr_eq(
		newFrontFaceBottomRow,
		oldRightFaceBottomRow,
		FACE_SIZE,
		"right face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateBottomSliceLeft_bottomFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, beforeRotation);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, bottomFace, "bottom");
}
