
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateBottomSlicesLeft_frontFaceBottomRow_movesTo_leftFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceBottomRow[FACE_SIZE];
	bottomRow(frontFace, oldFrontFaceBottomRow);

	// when
	Cube_rotateBottomSlicesLeft(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, newLeftFaceBottomRow);
	cr_assert_arr_eq(
		oldFrontFaceBottomRow,
		newLeftFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"front face bottom row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSlicesLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, oldFrontFaceEquatorRow);

	// when
	Cube_rotateBottomSlicesLeft(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		oldFrontFaceEquatorRow,
		newLeftFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"front face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateBottomSlicesLeft_leftFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, oldLeftFaceBottomRow);

	// when
	Cube_rotateBottomSlicesLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceTopRow[FACE_SIZE];
	topRow(backFace, newBackFaceTopRow);
	reverseSpan(newBackFaceTopRow);
	cr_assert_arr_eq(
		oldLeftFaceBottomRow,
		newBackFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"left face bottom row wasn't moved to the back face top row (reversed)");
}


Test(Cube, rotateBottomSlicesLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, oldLeftFaceEquatorRow);

	// when
	Cube_rotateBottomSlicesLeft(cube);

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


Test(Cube, rotateBottomSlicesLeft_backFaceTopRow_movesTo_rightFaceBottomRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	topRow(backFace, oldBackFaceTopRow);

	// when
	Cube_rotateBottomSlicesLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, newRightFaceBottomRow);
	reverseSpan(newRightFaceBottomRow);
	cr_assert_arr_eq(
		oldBackFaceTopRow,
		newRightFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"back face top row wasn't moved to the right face bottom row (reversed)");
}


Test(Cube, rotateBottomSlicesLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, oldBackFaceEquatorRow);

	// when
	Cube_rotateBottomSlicesLeft(cube);

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


Test(Cube, rotateBottomSlicesLeft_rightFaceBottomRow_movesTo_frontFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, oldRightFaceBottomRow);

	// when
	Cube_rotateBottomSlicesLeft(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceBottomRow[FACE_SIZE];
	bottomRow(frontFace, newFrontFaceBottomRow);
	cr_assert_arr_eq(
		oldRightFaceBottomRow,
		newFrontFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"right face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateBottomSlicesLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, oldRightFaceEquatorRow);

	// when
	Cube_rotateBottomSlicesLeft(cube);

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
