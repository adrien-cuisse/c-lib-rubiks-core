
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateLeftSliceDown_frontFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceLeftColumn[FACE_SIZE];
	leftColumn(frontFace, oldFrontFaceLeftColumn);

	// when
	Cube_rotateLeftSliceDown(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceLeftColumn[FACE_SIZE];
	leftColumn(bottomFace, newBottomFaceLeftColumn);
	cr_assert_arr_eq(
		newBottomFaceLeftColumn,
		oldFrontFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"front face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateLeftSliceDown_bottomFaceLeftColumn_movesTo_backFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceLeftColumn[FACE_SIZE];
	leftColumn(bottomFace, oldBottomFaceLeftColumn);

	// when
	Cube_rotateLeftSliceDown(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceLeftColumn[FACE_SIZE];
	leftColumn(backFace, newBackFaceLeftColumn);
	cr_assert_arr_eq(
		newBackFaceLeftColumn,
		oldBottomFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face left column wasn't moved to the back face left column");
}


Test(Cube, rotateLeftSliceDown_backFaceLeftColumn_movesTo_topFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceLeftColumn[FACE_SIZE];
	leftColumn(backFace, oldBackFaceLeftColumn);

	// when
	Cube_rotateLeftSliceDown(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceLeftColumn[FACE_SIZE];
	leftColumn(topFace, newTopFaceLeftColumn);
	cr_assert_arr_eq(
		newTopFaceLeftColumn,
		oldBackFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"back face left column wasn't moved to the top face left column");
}


Test(Cube, rotateLeftSliceDown_topFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceLeftColumn[FACE_SIZE];
	leftColumn(topFace, oldTopFaceLeftColumn);

	// when
	Cube_rotateLeftSliceDown(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceLeftColumn[FACE_SIZE];
	leftColumn(frontFace, newFrontFaceLeftColumn);
	cr_assert_arr_eq(
		newFrontFaceLeftColumn,
		oldTopFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"top face left column wasn't moved to the front face left column");
}


Test(Cube, rotateLeftSliceDown_leftFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, beforeRotation);

	// when
	Cube_rotateLeftSliceDown(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, leftFace, "left");
}
