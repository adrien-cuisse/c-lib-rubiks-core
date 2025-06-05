
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateFrontSliceClockwise_topFaceBottomRow_movesTo_rightFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	bottomRow(topFace, oldTopFaceBottomRow);

	// when
	Cube_rotateFrontSliceClockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceLeftColumn[FACE_SIZE];
	leftColumn(rightFace, newRightFaceLeftColumn);
	cr_assert_arr_eq(
		newRightFaceLeftColumn,
		oldTopFaceBottomRow,
		FACE_SIZE,
		"top face bottom row wasn't moved to the right face left column");
}


Test(Cube, rotateFrontSliceClockwise_rightFaceLeftColumn_movesTo_bottomFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceLeftColumn[FACE_SIZE];
	leftColumn(rightFace, oldRightFaceLeftColumn);

	// when
	Cube_rotateFrontSliceClockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceTopRow[FACE_SIZE];
	topRow(bottomFace, newBottomFaceTopRow);
	cr_assert_arr_eq(
		newBottomFaceTopRow,
		oldRightFaceLeftColumn,
		FACE_SIZE,
		"right face left column wasn't moved to the bottom face top row");
}


Test(Cube, rotateFrontSliceClockwise_bottomFaceTopRow_movesTo_leftFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	topRow(bottomFace, oldBottomFaceTopRow);

	// when
	Cube_rotateFrontSliceClockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceRightColumn[FACE_SIZE];
	rightColumn(leftFace, newLeftFaceRightColumn);
	cr_assert_arr_eq(
		newLeftFaceRightColumn,
		oldBottomFaceTopRow,
		FACE_SIZE,
		"bottom face top row wasn't moved to the left face right column");
}


Test(Cube, rotateFrontSliceClockwise_leftFaceRightColumn_movesTo_topFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceRightColumn[FACE_SIZE];
	rightColumn(leftFace, oldLeftFaceRightColumn);

	// when
	Cube_rotateFrontSliceClockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceBottomRow[FACE_SIZE];
	bottomRow(topFace, newTopFaceBottomRow);
	cr_assert_arr_eq(
		newTopFaceBottomRow,
		oldLeftFaceRightColumn,
		FACE_SIZE,
		"left face right column wasn't moved to the top face bottom row");
}


Test(Cube, rotateFrontSliceClockwise_frontFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, beforeRotation);

	// when
	Cube_rotateFrontSliceClockwise(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, frontFace, "front");
}


Test(Cube, rotateFrontSliceClockwise_rightFaceLeftColumn_reversed_bottomFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceLeftColumn[FACE_SIZE];
	leftColumn(rightFace, oldRightFaceLeftColumn);
	reverseSpan(oldRightFaceLeftColumn);

	// when
	Cube_rotateFrontSliceClockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceTopRow[FACE_SIZE];
	topRow(bottomFace, newBottomFaceTopRow);
	cr_assert_arr_eq(
		oldRightFaceLeftColumn,
		newBottomFaceTopRow,
		FACE_SIZE,
		"right face left column wasn't reversed");
}


Test(Cube, rotateFrontSliceClockwise_leftFaceRightColumn_reversed_topFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceRightColumn[FACE_SIZE];
	rightColumn(leftFace, oldLeftFaceRightColumn);
	reverseSpan(oldLeftFaceRightColumn);

	// when
	Cube_rotateFrontSliceClockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceBottomRow[FACE_SIZE];
	bottomRow(topFace, newTopFaceBottomRow);
	cr_assert_arr_eq(
		oldLeftFaceRightColumn,
		newTopFaceBottomRow,
		FACE_SIZE,
		"left face right column wasn't reversed");
}


Test(Cube, rotateFrontSliceClockwise_bottomFaceTopRow_notReversed_leftFaceRightColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	topRow(bottomFace, oldBottomFaceTopRow);

	// when
	Cube_rotateFrontSliceClockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceRightColumn[FACE_SIZE];
	rightColumn(leftFace, newLeftFaceRightColumn);
	cr_assert_arr_eq(
		oldBottomFaceTopRow,
		newLeftFaceRightColumn,
		FACE_SIZE,
		"bottom face top row was reversed");
}


Test(Cube, rotateFrontSliceClockwise_topFaceBottomRow_notReversed_rightFaceLeftColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	bottomRow(topFace, oldTopFaceBottomRow);

	// when
	Cube_rotateFrontSliceClockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceLeftColumn[FACE_SIZE];
	leftColumn(rightFace, newRightFaceLeftColumn);
	cr_assert_arr_eq(
		oldTopFaceBottomRow,
		newRightFaceLeftColumn,
		FACE_SIZE,
		"top face bottom row was reversed");
}
