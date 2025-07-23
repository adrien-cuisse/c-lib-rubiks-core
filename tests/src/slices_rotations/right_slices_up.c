
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateRightSlicesUp_frontFaceRightColumn_movesTo_topFaceRightColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceRightColumn[FACE_SIZE];
	rightColumn(frontFace, oldFrontFaceRightColumn);

	// when
	Cube_rotateRightSlicesUp(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceRightColumn[FACE_SIZE];
	rightColumn(topFace, newTopFaceRightColumn);
	cr_assert_arr_eq(
		oldFrontFaceRightColumn,
		newTopFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"front face right column wasn't moved to the top face right column");
}


Test(Cube, rotateRightSlicesUp_frontFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	middleColumn(frontFace, oldFrontFaceMiddleColumn);

	// when
	Cube_rotateRightSlicesUp(cube);

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


Test(Cube, rotateRightSlicesUp_topFaceRightColumn_movesTo_backFaceRightColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceRightColumn[FACE_SIZE];
	rightColumn(topFace, oldTopFaceRightColumn);

	// when
	Cube_rotateRightSlicesUp(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceRightColumn[FACE_SIZE];
	rightColumn(backFace, newBackFaceRightColumn);
	cr_assert_arr_eq(
		oldTopFaceRightColumn,
		newBackFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"top face right column wasn't moved to the back face right column");
}


Test(Cube, rotateRightSlicesUp_topFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	middleColumn(topFace, oldTopFaceMiddleColumn);

	// when
	Cube_rotateRightSlicesUp(cube);

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


Test(Cube, rotateRightSlicesUp_backFaceRightColumn_movesTo_bottomFaceRightColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceRightColumn[FACE_SIZE];
	rightColumn(backFace, oldBackFaceRightColumn);

	// when
	Cube_rotateRightSlicesUp(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceRightColumn[FACE_SIZE];
	rightColumn(bottomFace, newBottomFaceRightColumn);
	cr_assert_arr_eq(
		oldBackFaceRightColumn,
		newBottomFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"back face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateRightSlicesUp_backFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	middleColumn(backFace, oldBackFaceMiddleColumn);

	// when
	Cube_rotateRightSlicesUp(cube);

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


Test(Cube, rotateRightSlicesUp_bottomFaceRightColumn_movesTo_frontFaceRightColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceRightColumn[FACE_SIZE];
	rightColumn(bottomFace, oldBottomFaceRightColumn);

	// when
	Cube_rotateRightSlicesUp(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceRightColumn[FACE_SIZE];
	rightColumn(frontFace, newFrontFaceRightColumn);
	cr_assert_arr_eq(
		oldBottomFaceRightColumn,
		newFrontFaceRightColumn,
		FACE_SIZE * sizeof(Color),
		"bottom face right column wasn't moved to the front face right column");
}


Test(Cube, rotateRightSlicesUp_bottomFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	middleColumn(bottomFace, oldBottomFaceMiddleColumn);

	// when
	Cube_rotateRightSlicesUp(cube);

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
