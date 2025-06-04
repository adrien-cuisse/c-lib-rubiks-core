
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateBottomSliceRight_frontFaceBottomRow_movesTo_rightFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceBottomRow[FACE_SIZE];
	bottomRow(frontFace, oldFrontFaceBottomRow);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, newRightFaceBottomRow);
	cr_assert_arr_eq(
		newRightFaceBottomRow,
		oldFrontFaceBottomRow,
		FACE_SIZE,
		"front face bottom row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSliceRight_rightFaceBottomRow_movesTo_backFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, oldRightFaceBottomRow);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceTopRow[FACE_SIZE];
	topRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		newBackFaceTopRow,
		oldRightFaceBottomRow,
		FACE_SIZE,
		"right face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSliceRight_backFaceTopRow_movesTo_leftFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	topRow(backFace, oldBackFaceTopRow);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, newLeftFaceBottomRow);
	cr_assert_arr_eq(
		newLeftFaceBottomRow,
		oldBackFaceTopRow,
		FACE_SIZE,
		"back face top row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSliceRight_leftFaceBottomRow_movesTo_frontFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, oldLeftFaceBottomRow);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceBottomRow[FACE_SIZE];
	bottomRow(frontFace, newFrontFaceBottomRow);
	cr_assert_arr_eq(
		newFrontFaceBottomRow,
		oldLeftFaceBottomRow,
		FACE_SIZE,
		"left face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateBottomSliceRight_bottomFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, beforeRotation);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, bottomFace, "bottom");
}


Test(Cube, rotateBottomSliceRight_rightFaceBottomRow_reversed_backFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, oldRightFaceBottomRow);
	reverseSpan(oldRightFaceBottomRow);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceTopRow[FACE_SIZE];
	topRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		oldRightFaceBottomRow,
		newBackFaceTopRow,
		FACE_SIZE,
		"right face bottom row wasn't reversed");
}


Test(Cube, rotateBottomSliceRight_backFaceTopRow_reversed_leftFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	topRow(backFace, oldBackFaceTopRow);
	reverseSpan(oldBackFaceTopRow);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, newLeftFaceBottomRow);
	cr_assert_arr_eq(
		oldBackFaceTopRow,
		newLeftFaceBottomRow,
		FACE_SIZE,
		"back face top row wasn't reversed");
}
