
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateTopSlicesLeft_frontFaceTopRow_movesTo_leftFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, oldFrontFaceTopRow);

	// when
	Cube_rotateTopSlicesLeft(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		oldFrontFaceTopRow,
		newLeftFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"front face top row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSlicesLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, oldFrontFaceEquatorRow);

	// when
	Cube_rotateTopSlicesLeft(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		oldFrontFaceEquatorRow,
		newLeftFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"front face equator row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSlicesLeft_leftFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, oldLeftFaceTopRow);

	// when
	Cube_rotateTopSlicesLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, newBackFaceBottomRow);
	reverseSpan(newBackFaceBottomRow);
	cr_assert_arr_eq(
		oldLeftFaceTopRow,
		newBackFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"left face top row wasn't moved to the back face bottom row (reversed)");
}


Test(Cube, rotateTopSlicesLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, oldLeftFaceEquatorRow);

	// when
	Cube_rotateTopSlicesLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, newBackFaceEquatorRow);
	reverseSpan(newBackFaceEquatorRow);
	cr_assert_arr_eq(
		oldLeftFaceEquatorRow,
		newBackFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"left face equator row wasn't moved to the back face equator row (reversed)");
}


Test(Cube, rotateTopSlicesLeft_backFaceBottomRow_movesTo_rightFaceTopRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, oldBackFaceBottomRow);

	// when
	Cube_rotateTopSlicesLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, newRightFaceTopRow);
	reverseSpan(newRightFaceTopRow);
	cr_assert_arr_eq(
		oldBackFaceBottomRow,
		newRightFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"back face bottom row wasn't moved to the right face top row (reversed)");
}


Test(Cube, rotateTopSlicesLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, oldBackFaceEquatorRow);

	// when
	Cube_rotateTopSlicesLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, newRightFaceEquatorRow);
	reverseSpan(newRightFaceEquatorRow);
	cr_assert_arr_eq(
		oldBackFaceEquatorRow,
		newRightFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"back face equator row wasn't moved to the right face equator row (reversed)");
}


Test(Cube, rotateTopSlicesLeft_rightFaceTopRow_movesTo_frontFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, oldRightFaceTopRow);

	// when
	Cube_rotateTopSlicesLeft(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, newFrontFaceTopRow);
	cr_assert_arr_eq(
		oldRightFaceTopRow,
		newFrontFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"right face top row wasn't moved to the front face top row");
}


Test(Cube, rotateTopSlicesLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, oldRightFaceEquatorRow);

	// when
	Cube_rotateTopSlicesLeft(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, newFrontFaceEquatorRow);
	cr_assert_arr_eq(
		oldRightFaceEquatorRow,
		newFrontFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"right face equator row wasn't moved to the front face equator row");
}
