
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateBackSlicesClockwise_topFaceTopRow_movesTo_rightFaceRightColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceTopRow[FACE_SIZE];
	topRow(topFace, oldTopFaceTopRow);

	// when
	Cube_rotateBackSlicesClockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceRightColumn[FACE_SIZE];
	rightColumn(rightFace, newRightFaceRightColumn);
	cr_assert_arr_eq(
		oldTopFaceTopRow,
		newRightFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"top face top row wasn't moved to the right face right column");
}


Test(Cube, rotateBackSlicesClockwise_topFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, oldTopFaceEquatorRow);

	// when
	Cube_rotateBackSlicesClockwise(cube);

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


Test(Cube, rotateBackSlicesClockwise_rightFaceRightColumn_movesTo_bottomFaceBottomRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceRightColumn[FACE_SIZE];
	rightColumn(rightFace, oldRightFaceRightColumn);

	// when
	Cube_rotateBackSlicesClockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceBottomRow[FACE_SIZE];
	bottomRow(bottomFace, newBottomFaceBottomRow);
	reverseSpan(newBottomFaceBottomRow);
	cr_assert_arr_eq(
		oldRightFaceRightColumn,
		newBottomFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"right face right column wasn't moved to the bottom face bottom row (reversed)");
}


Test(Cube, rotateBackSlicesClockwise_rightFaceMiddleColumn_movesTo_bottomFaceEquatorRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, oldRightFaceMiddleColumn);

	// when
	Cube_rotateBackSlicesClockwise(cube);

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


Test(Cube, rotateBackSlicesClockwise_bottomFaceBottomRow_movesTo_leftFaceLeftColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceBottomRow[FACE_SIZE];
	bottomRow(bottomFace, oldBottomFaceBottomRow);

	// when
	Cube_rotateBackSlicesClockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceLeftColumn[FACE_SIZE];
	leftColumn(leftFace, newLeftFaceLeftColumn);
	cr_assert_arr_eq(
		oldBottomFaceBottomRow,
		newLeftFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face bottom row wasn't moved to the left face left column");
}


Test(Cube, rotateBackSlicesClockwise_bottomFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, oldBottomFaceEquatorRow);

	// when
	Cube_rotateBackSlicesClockwise(cube);

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


Test(Cube, rotateBackSlicesClockwise_leftFaceLeftColumn_movesTo_topFaceTopRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceLeftColumn[FACE_SIZE];
	leftColumn(leftFace, oldLeftFaceLeftColumn);

	// when
	Cube_rotateBackSlicesClockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceTopRow[FACE_SIZE];
	topRow(topFace, newTopFaceTopRow);
	reverseSpan(newTopFaceTopRow);
	cr_assert_arr_eq(
		oldLeftFaceLeftColumn,
		newTopFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"left face left column wasn't moved to the top face top row (reversed)");
}


Test(Cube, rotateBackSlicesClockwise_leftFaceMiddleColumn_movesTo_topFaceEquatorRow_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, oldLeftFaceMiddleColumn);

	// when
	Cube_rotateBackSlicesClockwise(cube);

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
