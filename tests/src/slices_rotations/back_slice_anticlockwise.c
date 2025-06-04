
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateBackSliceAnticlockwise_topFaceTopRow_movesTo_leftFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceTopRow[FACE_SIZE];
	topRow(topFace, oldTopFaceTopRow);

	// when
	Cube_rotateBackSliceAnticlockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceLeftColumn[FACE_SIZE];
	leftColumn(leftFace, newLeftFaceLeftColumn);
	cr_assert_arr_eq(
		newLeftFaceLeftColumn,
		oldTopFaceTopRow,
		FACE_SIZE,
		"top face top row wasn't moved to the left face left column");
}


Test(Cube, rotateBackSliceAnticlockwise_leftFaceLeftColumn_movesTo_bottomFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceLeftColumn[FACE_SIZE];
	leftColumn(leftFace, oldLeftFaceLeftColumn);

	// when
	Cube_rotateBackSliceAnticlockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceBottomRow[FACE_SIZE];
	bottomRow(bottomFace, newBottomFaceBottomRow);
	cr_assert_arr_eq(
		newBottomFaceBottomRow,
		oldLeftFaceLeftColumn,
		FACE_SIZE,
		"left face left column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateBackSliceAnticlockwise_bottomFaceBottomRow_movesTo_rightFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceBottomRow[FACE_SIZE];
	bottomRow(bottomFace, oldBottomFaceBottomRow);

	// when
	Cube_rotateBackSliceAnticlockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceRightColumn[FACE_SIZE];
	rightColumn(rightFace, newRightFaceRightColumn);
	cr_assert_arr_eq(
		newRightFaceRightColumn,
		oldBottomFaceBottomRow,
		FACE_SIZE,
		"bottom face bottom row wasn't moved to the right face right column");
}


Test(Cube, rotateBackSliceAnticlockwise_rightFaceRightColumn_movesTo_topFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceRightColumn[FACE_SIZE];
	rightColumn(rightFace, oldRightFaceRightColumn);

	// when
	Cube_rotateBackSliceAnticlockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceTopRow[FACE_SIZE];
	topRow(topFace, newTopFaceTopRow);
	cr_assert_arr_eq(
		newTopFaceTopRow,
		oldRightFaceRightColumn,
		FACE_SIZE,
		"right face right column wasn't moved to the top face top row");
}


Test(Cube, rotateBackSliceAnticlockwise_backFaceIsRotatedClockwise)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, beforeRotation);

	// when
	Cube_rotateBackSliceAnticlockwise(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, backFace, "back");
}


Test(Cube, rotateBackSliceAnticlockwise_bottomFaceBottomRow_reversed_rightFaceRightColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceBottomRow[FACE_SIZE];
	bottomRow(bottomFace, oldBottomFaceBottomRow);
	reverseSpan(oldBottomFaceBottomRow);

	// when
	Cube_rotateBackSliceAnticlockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceRightColumn[FACE_SIZE];
	rightColumn(rightFace, newRightFaceRightColumn);
	cr_assert_arr_eq(
		oldBottomFaceBottomRow,
		newRightFaceRightColumn,
		FACE_SIZE,
		"bottom face bottom row wasn't reversed");
}


Test(Cube, rotateBackSliceAnticlockwise_topFaceTopRow_reversed_leftFaceLeftColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceTopRow[FACE_SIZE];
	topRow(topFace, oldTopFaceTopRow);
	reverseSpan(oldTopFaceTopRow);

	// when
	Cube_rotateBackSliceAnticlockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceLeftColumn[FACE_SIZE];
	leftColumn(leftFace, newLeftFaceLeftColumn);
	cr_assert_arr_eq(
		oldTopFaceTopRow,
		newLeftFaceLeftColumn,
		FACE_SIZE,
		"top face top row wasn't reversed");
}
