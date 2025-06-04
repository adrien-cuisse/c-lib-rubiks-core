
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateMiddleSliceUp_frontFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	middleColumn(frontFace, oldFrontFaceMiddleColumn);

	// when
	Cube_rotateMiddleSliceUp(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceMiddleColumn[FACE_SIZE];
	middleColumn(topFace, newTopFaceMiddleColumn);
	cr_assert_arr_eq(
		newTopFaceMiddleColumn,
		oldFrontFaceMiddleColumn,
		FACE_SIZE,
		"front face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateMiddleSliceUp_topFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	middleColumn(topFace, oldTopFaceMiddleColumn);

	// when
	Cube_rotateMiddleSliceUp(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceMiddleColumn[FACE_SIZE];
	middleColumn(backFace, newBackFaceMiddleColumn);
	cr_assert_arr_eq(
		newBackFaceMiddleColumn,
		oldTopFaceMiddleColumn,
		FACE_SIZE,
		"top face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateMiddleSliceUp_backFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	middleColumn(backFace, oldBackFaceMiddleColumn);

	// when
	Cube_rotateMiddleSliceUp(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceMiddleColumn[FACE_SIZE];
	middleColumn(bottomFace, newBottomFaceMiddleColumn);
	cr_assert_arr_eq(
		newBottomFaceMiddleColumn,
		oldBackFaceMiddleColumn,
		FACE_SIZE,
		"back face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateMiddleSliceUp_bottomFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	middleColumn(bottomFace, oldBottomFaceMiddleColumn);

	// when
	Cube_rotateMiddleSliceUp(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceMiddleColumn[FACE_SIZE];
	middleColumn(frontFace, newFrontFaceMiddleColumn);
	cr_assert_arr_eq(
		newFrontFaceMiddleColumn,
		oldBottomFaceMiddleColumn,
		FACE_SIZE,
		"bottom face middle column wasn't moved to the front face middle column");
}
