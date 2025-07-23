
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateFrontSlicesClockwise_topFaceBottomRow_movesTo_rightFaceLeftColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	bottomRow(topFace, oldTopFaceBottomRow);

	// when
	Cube_rotateFrontSlicesClockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceLeftColumn[FACE_SIZE];
	leftColumn(rightFace, newRightFaceLeftColumn);
	cr_assert_arr_eq(
		oldTopFaceBottomRow,
		newRightFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"top face bottom row wasn't moved to the right face left column");
}


Test(Cube, rotateFrontSlicesClockwise_topFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, oldTopFaceEquatorRow);

	// when
	Cube_rotateFrontSlicesClockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		oldTopFaceEquatorRow,
		newRightFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"top face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateFrontSlicesClockwise_rightFaceLeftColumn_movesTo_bottomFaceTopRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceLeftColumn[FACE_SIZE];
	leftColumn(rightFace, oldRightFaceLeftColumn);

	// when
	Cube_rotateFrontSlicesClockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceTopRow[FACE_SIZE];
	topRow(bottomFace, newBottomFaceTopRow);
	reverseSpan(newBottomFaceTopRow);
	cr_assert_arr_eq(
		oldRightFaceLeftColumn,
		newBottomFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"right face left column wasn't moved to the bottom face top row (reversed)");
}


Test(Cube, rotateFrontSlicesClockwise_rightFaceMiddleColumn_movesTo_bottomFaceEquatorRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, oldRightFaceMiddleColumn);

	// when
	Cube_rotateFrontSlicesClockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, newBottomFaceEquatorRow);
	reverseSpan(newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		oldRightFaceMiddleColumn,
		newBottomFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"right face middle column wasn't moved to the bottom face equator row (reversed)");
}


Test(Cube, rotateFrontSlicesClockwise_bottomFaceTopRow_movesTo_leftFaceRightColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	topRow(bottomFace, oldBottomFaceTopRow);

	// when
	Cube_rotateFrontSlicesClockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceRightColumn[FACE_SIZE];
	rightColumn(leftFace, newLeftFaceRightColumn);
	cr_assert_arr_eq(
		oldBottomFaceTopRow,
		newLeftFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face top row wasn't moved to the left face right column");
}


Test(Cube, rotateFrontSlicesClockwise_bottomFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, oldBottomFaceEquatorRow);

	// when
	Cube_rotateFrontSlicesClockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		oldBottomFaceEquatorRow,
		newLeftFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateFrontSlicesClockwise_leftFaceRightColumn_movesTo_topFaceBottomRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceRightColumn[FACE_SIZE];
	rightColumn(leftFace, oldLeftFaceRightColumn);

	// when
	Cube_rotateFrontSlicesClockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceBottomRow[FACE_SIZE];
	bottomRow(topFace, newTopFaceBottomRow);
	reverseSpan(newTopFaceBottomRow);
	cr_assert_arr_eq(
		oldLeftFaceRightColumn,
		newTopFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"left face right column wasn't moved to the top face bottom row (reversed)");
}


Test(Cube, rotateFrontSlicesClockwise_leftFaceMiddleColumn_movesTo_topFaceEquatorRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, oldLeftFaceMiddleColumn);

	// when
	Cube_rotateFrontSlicesClockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, newTopFaceEquatorRow);
	reverseSpan(newTopFaceEquatorRow);
	cr_assert_arr_eq(
		oldLeftFaceMiddleColumn,
		newTopFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"left face middle column wasn't moved to the top face equator row (reversed)");
}
