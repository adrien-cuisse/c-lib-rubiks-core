
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateFrontSlicesAnticlockwise_topFaceBottomRow_movesTo_leftFaceRightColumn_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	bottomRow(topFace, oldTopFaceBottomRow);

	// when
	Cube_rotateFrontSlicesAnticlockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceRightColumn[FACE_SIZE];
	rightColumn(leftFace, newLeftFaceRightColumn);
	reverseSpan(newLeftFaceRightColumn);
	cr_assert_arr_eq(
		oldTopFaceBottomRow,
		newLeftFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"top face bottom row wasn't moved to the left face right column (reversed)");
}


Test(Cube, rotateFrontSlicesAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, oldTopFaceEquatorRow);

	// when
	Cube_rotateFrontSlicesAnticlockwise(cube);

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


Test(Cube, rotateFrontSlicesAnticlockwise_leftFaceRightColumn_movesTo_bottomFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceRightColumn[FACE_SIZE];
	rightColumn(leftFace, oldLeftFaceRightColumn);

	// when
	Cube_rotateFrontSlicesAnticlockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceTopRow[FACE_SIZE];
	topRow(bottomFace, newBottomFaceTopRow);
	cr_assert_arr_eq(
		oldLeftFaceRightColumn,
		newBottomFaceTopRow,
		FACE_SIZE * sizeof(Color),
		"left face right column wasn't moved to the bottom face top row");
}


Test(Cube, rotateFrontSlicesAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, oldLeftFaceMiddleColumn);

	// when
	Cube_rotateFrontSlicesAnticlockwise(cube);

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


Test(Cube, rotateFrontSlicesAnticlockwise_bottomFaceTopRow_movesTo_rightFaceLeftColumn_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	topRow(bottomFace, oldBottomFaceTopRow);

	// when
	Cube_rotateFrontSlicesAnticlockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceLeftColumn[FACE_SIZE];
	leftColumn(rightFace, newRightFaceLeftColumn);
	reverseSpan(newRightFaceLeftColumn);
	cr_assert_arr_eq(
		oldBottomFaceTopRow,
		newRightFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face top row wasn't moved to the right face left column (reversed)");
}


Test(Cube, rotateFrontSlicesAnticlockwise_bottomFaceEquatorRow_movesTo_rightFaceMiddleColumn_reversed)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, oldBottomFaceEquatorRow);

	// when
	Cube_rotateFrontSlicesAnticlockwise(cube);

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


Test(Cube, rotateFrontSlicesAnticlockwise_rightFaceLeftColumn_movesTo_topFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceLeftColumn[FACE_SIZE];
	leftColumn(rightFace, oldRightFaceLeftColumn);

	// when
	Cube_rotateFrontSlicesAnticlockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceBottomRow[FACE_SIZE];
	bottomRow(topFace, newTopFaceBottomRow);
	cr_assert_arr_eq(
		oldRightFaceLeftColumn,
		newTopFaceBottomRow,
		FACE_SIZE * sizeof(Color),
		"right face left column was moved to the top face bottom row");
}


Test(Cube, rotateFrontSlicesAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, oldRightFaceMiddleColumn);

	// when
	Cube_rotateFrontSlicesAnticlockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		oldRightFaceMiddleColumn,
		newTopFaceEquatorRow,
		FACE_SIZE * sizeof(Color),
		"right face middle column was moved to the top face equator row");
}
