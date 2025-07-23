
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateBackSlicesAnticlockwise_topFaceTopRow_movesTo_leftFaceLeftColumn_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceTopRow[FACE_SIZE];
	topRow(topFace, oldTopFaceTopRow);

	// when
	Cube_rotateBackSlicesAnticlockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceLeftColumn[FACE_SIZE];
	leftColumn(leftFace, newLeftFaceLeftColumn);
	reverseSpan(newLeftFaceLeftColumn);
	cr_assert_arr_eq(
		oldTopFaceTopRow,
		newLeftFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"top face top row wasn't moved to the left face left column (reversed)");
}


Test(Cube, rotateBackSlicesAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, oldTopFaceEquatorRow);

	// when
	Cube_rotateBackSlicesAnticlockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, newLeftFaceMiddleColumn);
	reverseSpan(newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		oldTopFaceEquatorRow,
		newLeftFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"top face equator row wasn't moved to the left face middle column (reversed)");
}


Test(Cube, rotateBackSlicesAnticlockwise_leftFaceLeftColumn_movesTo_bottomFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceLeftColumn[FACE_SIZE];
	leftColumn(leftFace, oldLeftFaceLeftColumn);

	// when
	Cube_rotateBackSlicesAnticlockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceBottomRow[FACE_SIZE];
	bottomRow(bottomFace, newBottomFaceBottomRow);
	cr_assert_arr_eq(
		oldLeftFaceLeftColumn,
		newBottomFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"left face left column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateBackSlicesAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, oldLeftFaceMiddleColumn);

	// when
	Cube_rotateBackSlicesAnticlockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		oldLeftFaceMiddleColumn,
		newBottomFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"left face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateBackSlicesAnticlockwise_bottomFaceBottomRow_movesTo_rightFaceRightColumn_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceBottomRow[FACE_SIZE];
	bottomRow(bottomFace, oldBottomFaceBottomRow);

	// when
	Cube_rotateBackSlicesAnticlockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceRightColumn[FACE_SIZE];
	rightColumn(rightFace, newRightFaceRightColumn);
	reverseSpan(newRightFaceRightColumn);
	cr_assert_arr_eq(
		oldBottomFaceBottomRow,
		newRightFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face bottom row wasn't moved to the right face right column (reversed)");
}


Test(Cube, rotateBackSlicesAnticlockwise_bottomFaceEquatorRow_movesTo_rightFacemiddleColumn_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, oldBottomFaceEquatorRow);

	// when
	Cube_rotateBackSlicesAnticlockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, newRightFaceMiddleColumn);
	reverseSpan(newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		oldBottomFaceEquatorRow,
		newRightFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face equator row wasn't moved to the right face middle column (reversed)");
}


Test(Cube, rotateBackSlicesAnticlockwise_rightFaceRightColumn_movesTo_topFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceRightColumn[FACE_SIZE];
	rightColumn(rightFace, oldRightFaceRightColumn);

	// when
	Cube_rotateBackSlicesAnticlockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceTopRow[FACE_SIZE];
	topRow(topFace, newTopFaceTopRow);
	cr_assert_arr_eq(
		oldRightFaceRightColumn,
		newTopFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"right face right column wasn't moved to the top face top row");
}


Test(Cube, rotateBackSlicesAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, oldRightFaceMiddleColumn);

	// when
	Cube_rotateBackSlicesAnticlockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		oldRightFaceMiddleColumn,
		newTopFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"right face middle column wasn't moved to the top face equator row");
}
