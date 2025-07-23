
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateStandingSliceAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, oldTopFaceEquatorRow);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		newLeftFaceMiddleColumn,
		oldTopFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"top face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateStandingSliceAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, oldLeftFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		newBottomFaceEquatorRow,
		oldLeftFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"left face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateStandingSliceAnticlockwise_bottomFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, oldBottomFaceEquatorRow);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		newRightFaceMiddleColumn,
		oldBottomFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"bottom face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateStandingSliceAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, oldRightFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		newTopFaceEquatorRow,
		oldRightFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"right face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateStandingSliceAnticlockwise_topFaceEquatorRow_reversed_leftFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, oldTopFaceEquatorRow);
	reverseSpan(oldTopFaceEquatorRow);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		oldTopFaceEquatorRow,
		newLeftFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"top face equator row wasn't reversed");
}


Test(Cube, rotateStandingSliceAnticlockwise_bottomFaceEquatorRow_reversed_rightFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, oldBottomFaceEquatorRow);
	reverseSpan(oldBottomFaceEquatorRow);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		oldBottomFaceEquatorRow,
		newRightFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face equator row wasn't reversed");
}


Test(Cube, rotateStandingSliceAnticlockwise_rightFaceMiddleColumn_notReversed_topFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, oldRightFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		oldRightFaceMiddleColumn,
		newTopFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"right face middle column was reversed");
}


Test(Cube, rotateStandingSliceAnticlockwise_leftFaceMiddleColumn_notReversed_bottomFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, oldLeftFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		oldLeftFaceMiddleColumn,
		newBottomFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"left face middle column was reversed");
}
