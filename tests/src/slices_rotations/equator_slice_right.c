
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateEquatorSliceRight_frontFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, oldFrontFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		newRightFaceEquatorRow,
		oldFrontFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"front face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateEquatorSliceRight_rightFaceEquatorRow_movesTo_backFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, oldRightFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, newBackFaceEquatorRow);
	cr_assert_arr_eq(
		newBackFaceEquatorRow,
		oldRightFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"right face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateEquatorSliceRight_backFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, oldBackFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		newLeftFaceEquatorRow,
		oldBackFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"back face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateEquatorSliceRight_leftFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, oldLeftFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, newFrontFaceEquatorRow);
	cr_assert_arr_eq(
		newFrontFaceEquatorRow,
		oldLeftFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"left face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateEquatorSliceRight_rightFaceEquatorRow_reversed_backFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, oldRightFaceEquatorRow);
	reverseSpan(oldRightFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, newBackFaceEquatorRow);
	cr_assert_arr_eq(
		oldRightFaceEquatorRow,
		newBackFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"right face equator row wasn't reversed");
}


Test(Cube, rotateEquatorSliceRight_backFaceEquatorRow_reversed_leftFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, oldBackFaceEquatorRow);
	reverseSpan(oldBackFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		oldBackFaceEquatorRow,
		newLeftFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"left face equator row wasn't reversed");
}


Test(Cube, rotateEquatorSliceRight_leftFaceEquatorRow_notReversed_frontFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, oldLeftFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, newFrontFaceEquatorRow);
	cr_assert_arr_eq(
		oldLeftFaceEquatorRow,
		newFrontFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"left face equator row was reversed");
}


Test(Cube, rotateEquatorSliceRight_frontFaceEquatorRow_notReversed_rightFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, oldFrontFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		oldFrontFaceEquatorRow,
		newRightFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"front face equator row was reversed");
}
