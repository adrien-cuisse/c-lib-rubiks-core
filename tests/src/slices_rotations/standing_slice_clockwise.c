
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateStandingSliceClockwise_topFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, oldTopFaceEquatorRow);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		newRightFaceMiddleColumn,
		oldTopFaceEquatorRow,
		FACE_SIZE,
		"top face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateStandingSliceClockwise_rightFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, oldRightFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		newBottomFaceEquatorRow,
		oldRightFaceMiddleColumn,
		FACE_SIZE,
		"right face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateStandingSliceClockwise_bottomFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, oldBottomFaceEquatorRow);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		newLeftFaceMiddleColumn,
		oldBottomFaceEquatorRow,
		FACE_SIZE,
		"bottom face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateStandingSliceClockwise_leftFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, oldLeftFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		newTopFaceEquatorRow,
		oldLeftFaceMiddleColumn,
		FACE_SIZE,
		"left face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateStandingSliceClockwise_rightFaceMiddleColumn_reversed_bottomFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, oldRightFaceMiddleColumn);
	reverseSpan(oldRightFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		oldRightFaceMiddleColumn,
		newBottomFaceEquatorRow,
		FACE_SIZE,
		"right face middle column wasn't reversed");
}


Test(Cube, rotateStandingSliceClockwise_leftFaceMiddleColumn_reversed_topFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, oldLeftFaceMiddleColumn);
	reverseSpan(oldLeftFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		oldLeftFaceMiddleColumn,
		newTopFaceEquatorRow,
		FACE_SIZE,
		"left face middle column wasn't reversed");
}
