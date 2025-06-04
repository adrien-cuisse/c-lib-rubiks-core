
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateEquatorSliceLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, oldFrontFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		newLeftFaceEquatorRow,
		oldFrontFaceEquatorRow,
		FACE_SIZE,
		"front face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateEquatorSliceLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, oldLeftFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, newBackFaceEquatorRow);
	cr_assert_arr_eq(
		newBackFaceEquatorRow,
		oldLeftFaceEquatorRow,
		FACE_SIZE,
		"left face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateEquatorSliceLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, oldBackFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		newRightFaceEquatorRow,
		oldBackFaceEquatorRow,
		FACE_SIZE,
		"back face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateEquatorSliceLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, oldRightFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, newFrontFaceEquatorRow);
	cr_assert_arr_eq(
		newFrontFaceEquatorRow,
		oldRightFaceEquatorRow,
		FACE_SIZE,
		"right face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateEquatorSliceLeft_leftFaceEquatorRow_reversed_backFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, oldLeftFaceEquatorRow);
	reverseSpan(oldLeftFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, newBackFaceEquatorRow);
	cr_assert_arr_eq(
		oldLeftFaceEquatorRow,
		newBackFaceEquatorRow,
		FACE_SIZE,
		"left face equator row wasn't reversed");
}


Test(Cube, rotateEquatorSliceLeft_backFaceEquatorRow_reversed_rightFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, oldBackFaceEquatorRow);
	reverseSpan(oldBackFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		oldBackFaceEquatorRow,
		newRightFaceEquatorRow,
		FACE_SIZE,
		"back face equator row wasn't reversed");
}
