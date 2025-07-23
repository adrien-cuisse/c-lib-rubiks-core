
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateTopSlicesRight_frontFaceTopRow_movesTo_rightFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, oldFrontFaceTopRow);

	// when
	Cube_rotateTopSlicesRight(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, newRightFaceTopRow);
	cr_assert_arr_eq(
		oldFrontFaceTopRow,
		newRightFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"front face top row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSlicesRight_frontFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, oldFrontFaceEquatorRow);

	// when
	Cube_rotateTopSlicesRight(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		oldFrontFaceEquatorRow,
		newRightFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"front face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateTopSlicesRight_rightFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, oldRightFaceTopRow);

	// when
	Cube_rotateTopSlicesRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, newBackFaceBottomRow);
	reverseSpan(newBackFaceBottomRow);
	cr_assert_arr_eq(
		oldRightFaceTopRow,
		newBackFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"right face top row wasn't moved to the the back face bottom row (reversed)");
}


Test(Cube, rotateTopSlicesRight_rightFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, oldRightFaceEquatorRow);

	// when
	Cube_rotateTopSlicesRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, newBackFaceEquatorRow);
	reverseSpan(newBackFaceEquatorRow);
	cr_assert_arr_eq(
		oldRightFaceEquatorRow,
		newBackFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"right face equator row wasn't moved to the the back face equator row (reversed)");
}


Test(Cube, rotateTopSlicesRight_backFaceBottomRow_movesTo_leftFaceTopRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, oldBackFaceBottomRow);

	// when
	Cube_rotateTopSlicesRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, newLeftFaceTopRow);
	reverseSpan(newLeftFaceTopRow);
	cr_assert_arr_eq(
		oldBackFaceBottomRow,
		newLeftFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"back face bottom row wasn't moved to the the left face top row (reversed)");
}


Test(Cube, rotateTopSlicesRight_backFaceEquatorRow_movesTo_leftFaceEquatorRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, oldBackFaceEquatorRow);

	// when
	Cube_rotateTopSlicesRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, newLeftFaceEquatorRow);
	reverseSpan(newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		oldBackFaceEquatorRow,
		newLeftFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"back face equator row wasn't moved to the the left face equator row (reversed)");
}


Test(Cube, rotateTopSlicesRight_leftFaceTopRow_movesTo_frontFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, oldLeftFaceTopRow);

	// when
	Cube_rotateTopSlicesRight(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, newFrontFaceTopRow);
	cr_assert_arr_eq(
		oldLeftFaceTopRow,
		newFrontFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"left face top row wasn't moved to the the front face top row");
}


Test(Cube, rotateTopSlicesRight_leftFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, oldLeftFaceEquatorRow);

	// when
	Cube_rotateTopSlicesRight(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, newFrontFaceEquatorRow);
	cr_assert_arr_eq(
		oldLeftFaceEquatorRow,
		newFrontFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"left face equator row wasn't moved to the the front face equator row");
}
