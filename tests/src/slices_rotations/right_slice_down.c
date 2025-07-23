
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateRightSliceDown_frontFaceRightColumn_movesTo_bottomFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceRightColumn[FACE_SIZE];
	rightColumn(frontFace, oldFrontFaceRightColumn);

	// when
	Cube_rotateRightSliceDown(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceRightColumn[FACE_SIZE];
	rightColumn(bottomFace, newBottomFaceRightColumn);
	cr_assert_arr_eq(
		newBottomFaceRightColumn,
		oldFrontFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"front face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateRightSliceDown_bottomFaceRightColumn_movesTo_backFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceRightColumn[FACE_SIZE];
	rightColumn(bottomFace, oldBottomFaceRightColumn);

	// when
	Cube_rotateRightSliceDown(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceRightColumn[FACE_SIZE];
	rightColumn(backFace, newBackFaceRightColumn);
	cr_assert_arr_eq(
		newBackFaceRightColumn,
		oldBottomFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face right column wasn't moved to the back face right column");
}


Test(Cube, rotateRightSliceDown_backFaceRightColumn_movesTo_topFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceRightColumn[FACE_SIZE];
	rightColumn(backFace, oldBackFaceRightColumn);

	// when
	Cube_rotateRightSliceDown(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceRightColumn[FACE_SIZE];
	rightColumn(topFace, newTopFaceRightColumn);
	cr_assert_arr_eq(
		newTopFaceRightColumn,
		oldBackFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"back face right column wasn't moved to the top face right column");
}


Test(Cube, rotateRightSliceDown_topFaceRightColumn_movesTo_frontFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceRightColumn[FACE_SIZE];
	rightColumn(topFace, oldTopFaceRightColumn);

	// when
	Cube_rotateRightSliceDown(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceRightColumn[FACE_SIZE];
	rightColumn(frontFace, newFrontFaceRightColumn);
	cr_assert_arr_eq(
		newFrontFaceRightColumn,
		oldTopFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"top face right column wasn't moved to the front face right column");
}


Test(Cube, rotateRightSliceDown_rightFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, beforeRotation);

	// when
	Cube_rotateRightSliceDown(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, rightFace, "right");
}
