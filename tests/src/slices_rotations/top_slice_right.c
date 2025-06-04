
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateTopSliceRight_frontFaceTopRow_movesTo_rightFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, oldFrontFaceTopRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, newRightFaceTopRow);
	cr_assert_arr_eq(
		newRightFaceTopRow,
		oldFrontFaceTopRow,
		FACE_SIZE,
		"front face top row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSliceRight_rightFaceTopRow_movesTo_backFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, oldRightFaceTopRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		newBackFaceBottomRow,
		oldRightFaceTopRow,
		FACE_SIZE,
		"right face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSliceRight_backFaceBottomRow_movesTo_leftFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, oldBackFaceBottomRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		newLeftFaceTopRow,
		oldBackFaceBottomRow,
		FACE_SIZE,
		"back face bottom row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSliceRight_leftFaceTopRow_movesTo_frontFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, oldLeftFaceTopRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, newFrontFaceTopRow);
	cr_assert_arr_eq(
		newFrontFaceTopRow,
		oldLeftFaceTopRow,
		FACE_SIZE,
		"left face top row wasn't moved to the front face top row");
}


Test(Cube, rotateTopSliceRight_topFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, beforeRotation);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, topFace, "top");
}


Test(Cube, rotateTopSliceRight_rightFaceTopRow_reversed_backFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, oldRightFaceTopRow);
	reverseSpan(oldRightFaceTopRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		oldRightFaceTopRow,
		newBackFaceBottomRow,
		FACE_SIZE,
		"right face top row wasn't reversed");
}


Test(Cube, rotateTopSliceRight_backFaceBottomRow_reversed_leftFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, oldBackFaceBottomRow);
	reverseSpan(oldBackFaceBottomRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		oldBackFaceBottomRow,
		newLeftFaceTopRow,
		FACE_SIZE,
		"back face bottom row wasn't reversed");
}
