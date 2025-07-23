
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
		FACE_SIZE * sizeof(Color),
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
		FACE_SIZE * sizeof(Color),
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
		FACE_SIZE * sizeof(Color),
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
		FACE_SIZE * sizeof(Color),
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


Test(Cube, rotateBottomSliceLeft_leftFaceBottomRow_reversed_backFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, oldLeftFaceBottomRow);
	reverseSpan(oldLeftFaceBottomRow);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceTopRow[FACE_SIZE];
	topRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		oldLeftFaceBottomRow,
		newBackFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"left face bottom row wasn't reversed");
}


Test(Cube, rotateBottomSliceLeft_backFaceTopRow_reversed_rightFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	topRow(backFace, oldBackFaceTopRow);
	reverseSpan(oldBackFaceTopRow);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		oldBackFaceTopRow,
		newBackFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"back face top row wasn't reversed");
}


Test(Cube, rotateBottomSliceLeft_rightFaceBottomRow_notReversed_frontFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
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
		oldRightFaceBottomRow,
		newFrontFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"right face bottom row was reversed");
}


Test(Cube, rotateBottomSliceLeft_frontFaceBottomRow_notReversed_leftFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
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
		oldFrontFaceBottomRow,
		newLeftFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"front face bottom row was reversed");
}
