
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateLeftSlicesUp_frontFaceLeftColumn_movesTo_topFaceLeftColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceLeftColumn[FACE_SIZE];
	leftColumn(frontFace, oldFrontFaceLeftColumn);

	// when
	Cube_rotateLeftSlicesUp(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceLeftColumn[FACE_SIZE];
	leftColumn(topFace, newTopFaceLeftColumn);
	cr_assert_arr_eq(
		oldFrontFaceLeftColumn,
		newTopFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"front face left column wasn't moved to the top face left column");
}


Test(Cube, rotateLeftSlicesUp_frontFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	middleColumn(frontFace, oldFrontFaceMiddleColumn);

	// when
	Cube_rotateLeftSlicesUp(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceMiddleColumn[FACE_SIZE];
	middleColumn(topFace, newTopFaceMiddleColumn);
	cr_assert_arr_eq(
		oldFrontFaceMiddleColumn,
		newTopFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"front face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateLeftSlicesUp_topFaceLeftColumn_movesTo_backFaceLeftColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceLeftColumn[FACE_SIZE];
	leftColumn(topFace, oldTopFaceLeftColumn);

	// when
	Cube_rotateLeftSlicesUp(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceLeftColumn[FACE_SIZE];
	leftColumn(backFace, newBackFaceLeftColumn);
	cr_assert_arr_eq(
		oldTopFaceLeftColumn,
		newBackFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"top face left column wasn't moved to the back face left column");
}


Test(Cube, rotateLeftSlicesUp_topFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	middleColumn(topFace, oldTopFaceMiddleColumn);

	// when
	Cube_rotateLeftSlicesUp(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceMiddleColumn[FACE_SIZE];
	middleColumn(backFace, newBackFaceMiddleColumn);
	cr_assert_arr_eq(
		oldTopFaceMiddleColumn,
		newBackFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"top face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateLeftSlicesUp_backFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceLeftColumn[FACE_SIZE];
	leftColumn(backFace, oldBackFaceLeftColumn);

	// when
	Cube_rotateLeftSlicesUp(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceLeftColumn[FACE_SIZE];
	leftColumn(bottomFace, newBottomFaceLeftColumn);
	cr_assert_arr_eq(
		oldBackFaceLeftColumn,
		newBottomFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"back face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateLeftSlicesUp_backFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	middleColumn(backFace, oldBackFaceMiddleColumn);

	// when
	Cube_rotateLeftSlicesUp(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceMiddleColumn[FACE_SIZE];
	middleColumn(bottomFace, newBottomFaceMiddleColumn);
	cr_assert_arr_eq(
		oldBackFaceMiddleColumn,
		newBottomFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"back face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateLeftSlicesUp_bottomFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceLeftColumn[FACE_SIZE];
	leftColumn(bottomFace, oldBottomFaceLeftColumn);

	// when
	Cube_rotateLeftSlicesUp(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceLeftColumn[FACE_SIZE];
	leftColumn(frontFace, newFrontFaceLeftColumn);
	cr_assert_arr_eq(
		oldBottomFaceLeftColumn,
		newFrontFaceLeftColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face left column wasn't moved to the front face left column");
}


Test(Cube, rotateLeftSlicesUp_bottomFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	middleColumn(bottomFace, oldBottomFaceMiddleColumn);

	// when
	Cube_rotateLeftSlicesUp(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceMiddleColumn[FACE_SIZE];
	middleColumn(frontFace, newFrontFaceMiddleColumn);
	cr_assert_arr_eq(
		oldBottomFaceMiddleColumn,
		newFrontFaceMiddleColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face middle column wasn't moved to the front face middle column");
}
