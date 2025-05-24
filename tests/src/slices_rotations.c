

#include <criterion/criterion.h>

#include "../../include/Cube.h"




static Cube * createScrambledCube(void);


static void topRow(Face const * face, Color buffer[FACE_SIZE]);


static void equatorRow(Face const * face, Color buffer[FACE_SIZE]);


static void bottomRow(Face const * face, Color buffer[FACE_SIZE]);


static void leftColumn(Face const * face, Color buffer[FACE_SIZE]);


static void middleColumn(Face const * face, Color buffer[FACE_SIZE]);


static void rightColumn(Face const * face, Color buffer[FACE_SIZE]);


static void readFace(Face const * face, Color buffer[FACE_SIZE][FACE_SIZE]);


#define assert_faceRotatedClockwise(a,b,c) _assert_faceRotatedClockwise((a), (b), (c), __FILE__, __LINE__)
static void _assert_faceRotatedClockwise(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line);


#define assert_faceRotatedAnticlockwise(a,b,c) _assert_faceRotatedAnticlockwise((a), (b), (c), __FILE__, __LINE__)
static void _assert_faceRotatedAnticlockwise(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line);




Test(Cube, rotateTopSliceLeft_frontFaceTopRow_movesTo_leftFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, oldFrontFaceTopRow);

	// when
	Cube_rotateTopSliceLeft(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		newLeftFaceTopRow,
		oldFrontFaceTopRow,
		FACE_SIZE,
		"front face top row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSliceLeft_leftFaceTopRow_movesTo_backFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, oldLeftFaceTopRow);

	// when
	Cube_rotateTopSliceLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		newBackFaceBottomRow,
		oldLeftFaceTopRow,
		FACE_SIZE,
		"left face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSliceLeft_backFaceBottomRow_movesTo_rightFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, oldBackFaceBottomRow);

	// when
	Cube_rotateTopSliceLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, newRightFaceTopRow);
	cr_assert_arr_eq(
		newRightFaceTopRow,
		oldBackFaceBottomRow,
		FACE_SIZE,
		"back face bottom row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSliceLeft_rightFaceTopRow_movesTo_frontFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, oldRightFaceTopRow);

	// when
	Cube_rotateTopSliceLeft(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, newFrontFaceTopRow);
	cr_assert_arr_eq(
		newFrontFaceTopRow,
		oldRightFaceTopRow,
		FACE_SIZE,
		"right face top row wasn't moved to the front face top row");
}


Test(Cube, rotateTopSliceRight_frontFaceTopRow_movesTo_rightFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, oldFrontFaceTopRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, newRightFaceTopRow);
	cr_assert_arr_eq(
		newRightFaceTopRow,
		oldFrontFaceTopRow,
		FACE_SIZE,
		"front face top row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSliceRight_rightFaceTopRow_movesTo_backFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, oldRightFaceTopRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		newBackFaceBottomRow,
		oldRightFaceTopRow,
		FACE_SIZE,
		"right face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSliceRight_backFaceBottomRow_movesTo_leftFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, oldBackFaceBottomRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		newLeftFaceTopRow,
		oldBackFaceBottomRow,
		FACE_SIZE,
		"back face bottom row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSliceRight_leftFaceTopRow_movesTo_frontFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, oldLeftFaceTopRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceTopRow[FACE_SIZE];
	topRow(frontFace, newFrontFaceTopRow);
	cr_assert_arr_eq(
		newFrontFaceTopRow,
		oldLeftFaceTopRow,
		FACE_SIZE,
		"left face top row wasn't moved to the front face top row");
}


Test(Cube, rotateEquatorSliceLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, oldFrontFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		newLeftFaceEquatorRow,
		oldFrontFaceEquatorRow,
		FACE_SIZE,
		"front face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateEquatorSliceLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, oldLeftFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, newBackFaceEquatorRow);
	cr_assert_arr_eq(
		newBackFaceEquatorRow,
		oldLeftFaceEquatorRow,
		FACE_SIZE,
		"left face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateEquatorSliceLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, oldBackFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		newRightFaceEquatorRow,
		oldBackFaceEquatorRow,
		FACE_SIZE,
		"back face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateEquatorSliceLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, oldRightFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, newFrontFaceEquatorRow);
	cr_assert_arr_eq(
		newFrontFaceEquatorRow,
		oldRightFaceEquatorRow,
		FACE_SIZE,
		"right face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateEquatorSliceRight_frontFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, oldFrontFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		newRightFaceEquatorRow,
		oldFrontFaceEquatorRow,
		FACE_SIZE,
		"front face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateEquatorSliceRight_rightFaceEquatorRow_movesTo_backFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, oldRightFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, newBackFaceEquatorRow);
	cr_assert_arr_eq(
		newBackFaceEquatorRow,
		oldRightFaceEquatorRow,
		FACE_SIZE,
		"right face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateEquatorSliceRight_backFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, oldBackFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		newLeftFaceEquatorRow,
		oldBackFaceEquatorRow,
		FACE_SIZE,
		"back face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateEquatorSliceRight_leftFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, oldLeftFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceRight(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceEquatorRow[FACE_SIZE];
	equatorRow(frontFace, newFrontFaceEquatorRow);
	cr_assert_arr_eq(
		newFrontFaceEquatorRow,
		oldLeftFaceEquatorRow,
		FACE_SIZE,
		"left face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateBottomSliceLeft_frontFaceBottomRow_movesTo_leftFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceBottomRow[FACE_SIZE];
	bottomRow(frontFace, oldFrontFaceBottomRow);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, newLeftFaceBottomRow);
	cr_assert_arr_eq(
		newLeftFaceBottomRow,
		oldFrontFaceBottomRow,
		FACE_SIZE,
		"front face bottom row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSliceLeft_leftFaceBottomRow_movesTo_backFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, oldLeftFaceBottomRow);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceTopRow[FACE_SIZE];
	topRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		newBackFaceTopRow,
		oldLeftFaceBottomRow,
		FACE_SIZE,
		"left face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSliceLeft_backFaceTopRow_movesTo_rightFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	topRow(backFace, oldBackFaceTopRow);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, newRightFaceBottomRow);
	cr_assert_arr_eq(
		newRightFaceBottomRow,
		oldBackFaceTopRow,
		FACE_SIZE,
		"back face top row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSliceLeft_rightFaceBottomRow_movesTo_frontFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, oldRightFaceBottomRow);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceBottomRow[FACE_SIZE];
	bottomRow(frontFace, newFrontFaceBottomRow);
	cr_assert_arr_eq(
		newFrontFaceBottomRow,
		oldRightFaceBottomRow,
		FACE_SIZE,
		"right face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateBottomSliceRight_frontFaceBottomRow_movesTo_rightFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceBottomRow[FACE_SIZE];
	bottomRow(frontFace, oldFrontFaceBottomRow);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, newRightFaceBottomRow);
	cr_assert_arr_eq(
		newRightFaceBottomRow,
		oldFrontFaceBottomRow,
		FACE_SIZE,
		"front face bottom row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSliceRight_rightFaceBottomRow_movesTo_backFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	bottomRow(rightFace, oldRightFaceBottomRow);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceTopRow[FACE_SIZE];
	topRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		newBackFaceTopRow,
		oldRightFaceBottomRow,
		FACE_SIZE,
		"right face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSliceRight_backFaceTopRow_movesTo_leftFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	topRow(backFace, oldBackFaceTopRow);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, newLeftFaceBottomRow);
	cr_assert_arr_eq(
		newLeftFaceBottomRow,
		oldBackFaceTopRow,
		FACE_SIZE,
		"back face top row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSliceRight_leftFaceBottomRow_movesTo_frontFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	bottomRow(leftFace, oldLeftFaceBottomRow);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceBottomRow[FACE_SIZE];
	bottomRow(frontFace, newFrontFaceBottomRow);
	cr_assert_arr_eq(
		newFrontFaceBottomRow,
		oldLeftFaceBottomRow,
		FACE_SIZE,
		"left face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateLeftSliceUp_frontFaceLeftColumn_movesTo_topFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceLeftColumn[FACE_SIZE];
	leftColumn(frontFace, oldFrontFaceLeftColumn);

	// when
	Cube_rotateLeftSliceUp(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceLeftColumn[FACE_SIZE];
	leftColumn(topFace, newTopFaceLeftColumn);
	cr_assert_arr_eq(
		newTopFaceLeftColumn,
		oldFrontFaceLeftColumn,
		FACE_SIZE,
		"front face left column wasn't moved to the top face left column");
}


Test(Cube, rotateLeftSliceUp_topFaceLeftColumn_movesTo_backFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceLeftColumn[FACE_SIZE];
	leftColumn(topFace, oldTopFaceLeftColumn);

	// when
	Cube_rotateLeftSliceUp(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceLeftColumn[FACE_SIZE];
	leftColumn(backFace, newBackFaceLeftColumn);
	cr_assert_arr_eq(
		newBackFaceLeftColumn,
		oldTopFaceLeftColumn,
		FACE_SIZE,
		"top face left column wasn't moved to the back face left column");
}


Test(Cube, rotateLeftSliceUp_backFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceLeftColumn[FACE_SIZE];
	leftColumn(backFace, oldBackFaceLeftColumn);

	// when
	Cube_rotateLeftSliceUp(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceLeftColumn[FACE_SIZE];
	leftColumn(bottomFace, newBottomFaceLeftColumn);
	cr_assert_arr_eq(
		newBottomFaceLeftColumn,
		oldBackFaceLeftColumn,
		FACE_SIZE,
		"back face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateLeftSliceUp_bottomFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceLeftColumn[FACE_SIZE];
	leftColumn(bottomFace, oldBottomFaceLeftColumn);

	// when
	Cube_rotateLeftSliceUp(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceLeftColumn[FACE_SIZE];
	leftColumn(frontFace, newFrontFaceLeftColumn);
	cr_assert_arr_eq(
		newFrontFaceLeftColumn,
		oldBottomFaceLeftColumn,
		FACE_SIZE,
		"bottom face left column wasn't moved to the front face left column");
}


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
		FACE_SIZE,
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
		FACE_SIZE,
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
		FACE_SIZE,
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
		FACE_SIZE,
		"top face left column wasn't moved to the front face left column");
}


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


Test(Cube, rotateMiddleSliceDown_frontFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	middleColumn(frontFace, oldFrontFaceMiddleColumn);

	// when
	Cube_rotateMiddleSliceDown(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceMiddleColumn[FACE_SIZE];
	middleColumn(bottomFace, newBottomFaceMiddleColumn);
	cr_assert_arr_eq(
		newBottomFaceMiddleColumn,
		oldFrontFaceMiddleColumn,
		FACE_SIZE,
		"front face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateMiddleSliceDown_bottomFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	middleColumn(bottomFace, oldBottomFaceMiddleColumn);

	// when
	Cube_rotateMiddleSliceDown(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceMiddleColumn[FACE_SIZE];
	middleColumn(backFace, newBackFaceMiddleColumn);
	cr_assert_arr_eq(
		newBackFaceMiddleColumn,
		oldBottomFaceMiddleColumn,
		FACE_SIZE,
		"bottom face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateMiddleSliceDown_backFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	middleColumn(backFace, oldBackFaceMiddleColumn);

	// when
	Cube_rotateMiddleSliceDown(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceMiddleColumn[FACE_SIZE];
	middleColumn(topFace, newTopFaceMiddleColumn);
	cr_assert_arr_eq(
		newTopFaceMiddleColumn,
		oldBackFaceMiddleColumn,
		FACE_SIZE,
		"back face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateMiddleSliceDown_topFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	middleColumn(topFace, oldTopFaceMiddleColumn);

	// when
	Cube_rotateMiddleSliceDown(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceMiddleColumn[FACE_SIZE];
	middleColumn(frontFace, newFrontFaceMiddleColumn);
	cr_assert_arr_eq(
		newFrontFaceMiddleColumn,
		oldTopFaceMiddleColumn,
		FACE_SIZE,
		"top face middle column wasn't moved to the front face middle column");
}


Test(Cube, rotateRightSliceUp_frontFaceRightColumn_movesTo_topFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceRightColumn[FACE_SIZE];
	rightColumn(frontFace, oldFrontFaceRightColumn);

	// when
	Cube_rotateRightSliceUp(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceRightColumn[FACE_SIZE];
	rightColumn(topFace, newTopFaceRightColumn);
	cr_assert_arr_eq(
		newTopFaceRightColumn,
		oldFrontFaceRightColumn,
		FACE_SIZE,
		"front face right column wasn't moved to the top face right column");
}


Test(Cube, rotateRightSliceUp_topFaceRightColumn_movesTo_backFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceRightColumn[FACE_SIZE];
	rightColumn(topFace, oldTopFaceRightColumn);

	// when
	Cube_rotateRightSliceUp(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceRightColumn[FACE_SIZE];
	rightColumn(backFace, newBackFaceRightColumn);
	cr_assert_arr_eq(
		newBackFaceRightColumn,
		oldTopFaceRightColumn,
		FACE_SIZE,
		"top face right column wasn't moved to the back face right column");
}


Test(Cube, rotateRightSliceUp_backFaceRightColumn_movesTo_bottomFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceRightColumn[FACE_SIZE];
	rightColumn(backFace, oldBackFaceRightColumn);

	// when
	Cube_rotateRightSliceUp(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceRightColumn[FACE_SIZE];
	rightColumn(bottomFace, newBottomFaceRightColumn);
	cr_assert_arr_eq(
		newBottomFaceRightColumn,
		oldBackFaceRightColumn,
		FACE_SIZE,
		"back face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateRightSliceUp_bottomFaceRightColumn_movesTo_frontFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceRightColumn[FACE_SIZE];
	rightColumn(bottomFace, oldBottomFaceRightColumn);

	// when
	Cube_rotateRightSliceUp(cube);

	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceRightColumn[FACE_SIZE];
	rightColumn(frontFace, newFrontFaceRightColumn);
	cr_assert_arr_eq(
		newFrontFaceRightColumn,
		oldBottomFaceRightColumn,
		FACE_SIZE,
		"bottom face right column wasn't moved to the front face right column");
}


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
		FACE_SIZE,
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
		FACE_SIZE,
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
		FACE_SIZE,
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
		FACE_SIZE,
		"top face right column wasn't moved to the front face right column");
}


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


Test(Cube, rotateFrontSliceAnticlockwise_topFaceBottomRow_movesTo_leftFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	bottomRow(topFace, oldTopFaceBottomRow);

	// when
	Cube_rotateFrontSliceAnticlockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceRightColumn[FACE_SIZE];
	rightColumn(leftFace, newLeftFaceRightColumn);
	cr_assert_arr_eq(
		newLeftFaceRightColumn,
		oldTopFaceBottomRow,
		FACE_SIZE,
		"top face bottom row wasn't moved to the left face right column");
}


Test(Cube, rotateFrontSliceAnticlockwise_leftFaceRightColumn_movesTo_bottomFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceRightColumn[FACE_SIZE];
	rightColumn(leftFace, oldLeftFaceRightColumn);

	// when
	Cube_rotateFrontSliceAnticlockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceTopRow[FACE_SIZE];
	topRow(bottomFace, newBottomFaceTopRow);
	cr_assert_arr_eq(
		newBottomFaceTopRow,
		oldLeftFaceRightColumn,
		FACE_SIZE,
		"left face right column wasn't moved to the bottom face top row");
}


Test(Cube, rotateFrontSliceAnticlockwise_bottomFaceTopRow_movesTo_rightFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	topRow(bottomFace, oldBottomFaceTopRow);

	// when
	Cube_rotateFrontSliceAnticlockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceLeftColumn[FACE_SIZE];
	leftColumn(rightFace, newRightFaceLeftColumn);
	cr_assert_arr_eq(
		newRightFaceLeftColumn,
		oldBottomFaceTopRow,
		FACE_SIZE,
		"bottom face top row wasn't moved to the right face left column");
}


Test(Cube, rotateFrontSliceAnticlockwise_rightFaceLeftColumn_movesTo_topFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceLeftColumn[FACE_SIZE];
	leftColumn(rightFace, oldRightFaceLeftColumn);

	// when
	Cube_rotateFrontSliceAnticlockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceBottomRow[FACE_SIZE];
	bottomRow(topFace, newTopFaceBottomRow);
	cr_assert_arr_eq(
		newTopFaceBottomRow,
		oldRightFaceLeftColumn,
		FACE_SIZE,
		"right face left column wasn't moved to the top face bottom row");
}


Test(Cube, rotateStandingSliceClockwise_topFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, oldTopFaceEquatorRow);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		newRightFaceMiddleColumn,
		oldTopFaceEquatorRow,
		FACE_SIZE,
		"top face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateStandingSliceClockwise_rightFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, oldRightFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		newBottomFaceEquatorRow,
		oldRightFaceMiddleColumn,
		FACE_SIZE,
		"right face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateStandingSliceClockwise_bottomFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, oldBottomFaceEquatorRow);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		newLeftFaceMiddleColumn,
		oldBottomFaceEquatorRow,
		FACE_SIZE,
		"bottom face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateStandingSliceClockwise_leftFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, oldLeftFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		newTopFaceEquatorRow,
		oldLeftFaceMiddleColumn,
		FACE_SIZE,
		"left face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateStandingSliceAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, oldTopFaceEquatorRow);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		newLeftFaceMiddleColumn,
		oldTopFaceEquatorRow,
		FACE_SIZE,
		"top face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateStandingSliceAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, oldLeftFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		newBottomFaceEquatorRow,
		oldLeftFaceMiddleColumn,
		FACE_SIZE,
		"left face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateStandingSliceAnticlockwise_bottomFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, oldBottomFaceEquatorRow);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		newRightFaceMiddleColumn,
		oldBottomFaceEquatorRow,
		FACE_SIZE,
		"bottom face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateStandingSliceAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, oldRightFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		newTopFaceEquatorRow,
		oldRightFaceMiddleColumn,
		FACE_SIZE,
		"right face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateBackSliceClockwise_topFaceTopRow_movesTo_rightFaceRightColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceTopRow[FACE_SIZE];
	topRow(topFace, oldTopFaceTopRow);

	// when
	Cube_rotateBackSliceClockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceRightColumn[FACE_SIZE];
	rightColumn(rightFace, newRightFaceRightColumn);
	cr_assert_arr_eq(
		newRightFaceRightColumn,
		oldTopFaceTopRow,
		FACE_SIZE,
		"top face top row wasn't moved to the right face right column");
}


Test(Cube, rotateBackSliceClockwise_rightFaceRightColumn_movesTo_bottomFaceBottomRow)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceRightColumn[FACE_SIZE];
	rightColumn(rightFace, oldRightFaceRightColumn);

	// when
	Cube_rotateBackSliceClockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceBottomRow[FACE_SIZE];
	bottomRow(bottomFace, newBottomFaceBottomRow);
	cr_assert_arr_eq(
		newBottomFaceBottomRow,
		oldRightFaceRightColumn,
		FACE_SIZE,
		"right face right column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateBackSliceClockwise_bottomFaceBottomRow_movesTo_leftFaceLeftColumn)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceBottomRow[FACE_SIZE];
	bottomRow(bottomFace, oldBottomFaceBottomRow);

	// when
	Cube_rotateBackSliceClockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceLeftColumn[FACE_SIZE];
	leftColumn(leftFace, newLeftFaceLeftColumn);
	cr_assert_arr_eq(
		newLeftFaceLeftColumn,
		oldBottomFaceBottomRow,
		FACE_SIZE,
		"bottom face bottom row wasn't moved to the left face left column");
}


Test(Cube, rotateBackSliceClockwise_leftFaceLeftColumn_movesTo_topFaceTopRow)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceLeftColumn[FACE_SIZE];
	leftColumn(leftFace, oldLeftFaceLeftColumn);

	// when
	Cube_rotateBackSliceClockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceTopRow[FACE_SIZE];
	topRow(topFace, newTopFaceTopRow);
	cr_assert_arr_eq(
		newTopFaceTopRow,
		oldLeftFaceLeftColumn,
		FACE_SIZE,
		"left face left column wasn't moved to the top face top row");
}


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


Test(Cube, rotateTopSliceLeft_topFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, beforeRotation);

	// when
	Cube_rotateTopSliceLeft(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, topFace, "top");
}


Test(Cube, rotateTopSliceRight_topFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, beforeRotation);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, topFace, "top");
}


Test(Cube, rotateBottomSliceLeft_bottomFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, beforeRotation);

	// when
	Cube_rotateBottomSliceLeft(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, bottomFace, "bottom");
}


Test(Cube, rotateBottomSliceRight_bottomFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, beforeRotation);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, bottomFace, "bottom");
}


Test(Cube, rotateLeftSliceUp_leftFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, beforeRotation);

	// when
	Cube_rotateLeftSliceUp(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, leftFace, "left");
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


Test(Cube, rotateRightSliceUp_rightFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, beforeRotation);

	// when
	Cube_rotateRightSliceUp(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, rightFace, "right");
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


Test(Cube, rotateFrontSliceAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, beforeRotation);

	// when
	Cube_rotateFrontSliceAnticlockwise(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, frontFace, "front");
}


Test(Cube, rotateBackSliceClockwise_backFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, beforeRotation);

	// when
	Cube_rotateBackSliceClockwise(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, backFace, "back");
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


static void reverseSpan(Color buffer[FACE_SIZE])
{
	Color swap = buffer[0];
	buffer[0] = buffer[2];
	buffer[2] = swap;
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


Test(Cube, rotateFrontSliceAnticlockwise_topFaceBottomRow_reversed_leftFaceRightColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	bottomRow(topFace, oldTopFaceBottomRow);
	reverseSpan(oldTopFaceBottomRow);

	// when
	Cube_rotateFrontSliceAnticlockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceRightColumn[FACE_SIZE];
	rightColumn(leftFace, newLeftFaceRightColumn);
	cr_assert_arr_eq(
		oldTopFaceBottomRow,
		newLeftFaceRightColumn,
		FACE_SIZE,
		"top face bottom row wasn't reversed");
}


Test(Cube, rotateFrontSliceAnticlockwise_bottomFaceTopRow_reversed_rightFaceLeftColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	topRow(bottomFace, oldBottomFaceTopRow);
	reverseSpan(oldBottomFaceTopRow);

	// when
	Cube_rotateFrontSliceAnticlockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceLeftColumn[FACE_SIZE];
	leftColumn(rightFace, newRightFaceLeftColumn);
	cr_assert_arr_eq(
		oldBottomFaceTopRow,
		newRightFaceLeftColumn,
		FACE_SIZE,
		"bottom face top row wasn't reversed");
}


Test(Cube, rotateStandingSliceClockwise_rightFaceMiddleColumn_reversed_bottomFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, oldRightFaceMiddleColumn);
	reverseSpan(oldRightFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		oldRightFaceMiddleColumn,
		newBottomFaceEquatorRow,
		FACE_SIZE,
		"right face middle column wasn't reversed");
}


Test(Cube, rotateStandingSliceClockwise_leftFaceMiddleColumn_reversed_topFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, oldLeftFaceMiddleColumn);
	reverseSpan(oldLeftFaceMiddleColumn);

	// when
	Cube_rotateStandingSliceClockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		oldLeftFaceMiddleColumn,
		newTopFaceEquatorRow,
		FACE_SIZE,
		"left face middle column wasn't reversed");
}


Test(Cube, rotateStandingSliceAnticlockwise_topFaceEquatorRow_reversed_leftFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	equatorRow(topFace, oldTopFaceEquatorRow);
	reverseSpan(oldTopFaceEquatorRow);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	middleColumn(leftFace, newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		oldTopFaceEquatorRow,
		newLeftFaceMiddleColumn,
		FACE_SIZE,
		"top face equator row wasn't reversed");
}


Test(Cube, rotateStandingSliceAnticlockwise_bottomFaceEquatorRow_reversed_rightFaceMiddleColumn)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	equatorRow(bottomFace, oldBottomFaceEquatorRow);
	reverseSpan(oldBottomFaceEquatorRow);

	// when
	Cube_rotateStandingSliceAnticlockwise(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	middleColumn(rightFace, newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		oldBottomFaceEquatorRow,
		newRightFaceMiddleColumn,
		FACE_SIZE,
		"bottom face equator row wasn't reversed");
}


Test(Cube, rotateBackSliceClockwise_rightFaceRightColumn_reversed_bottomFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceRightColumn[FACE_SIZE];
	rightColumn(rightFace, oldRightFaceRightColumn);
	reverseSpan(oldRightFaceRightColumn);

	// when
	Cube_rotateBackSliceClockwise(cube);

	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceBottomRow[FACE_SIZE];
	bottomRow(bottomFace, newBottomFaceBottomRow);
	cr_assert_arr_eq(
		oldRightFaceRightColumn,
		newBottomFaceBottomRow,
		FACE_SIZE,
		"right face right column wasn't reversed");
}


Test(Cube, rotateBackSliceClockwise_leftFaceLeftColumn_reversed_topFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceLeftColumn[FACE_SIZE];
	leftColumn(leftFace, oldLeftFaceLeftColumn);
	reverseSpan(oldLeftFaceLeftColumn);

	// when
	Cube_rotateBackSliceClockwise(cube);

	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceTopRow[FACE_SIZE];
	topRow(topFace, newTopFaceTopRow);
	cr_assert_arr_eq(
		oldLeftFaceLeftColumn,
		newTopFaceTopRow,
		FACE_SIZE,
		"left face left column wasn't reversed");
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


Test(Cube, rotateEquatorSliceLeft_leftFaceEquatorRow_reversed_backFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	equatorRow(leftFace, oldLeftFaceEquatorRow);
	reverseSpan(oldLeftFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, newBackFaceEquatorRow);
	cr_assert_arr_eq(
		oldLeftFaceEquatorRow,
		newBackFaceEquatorRow,
		FACE_SIZE,
		"left face equator row wasn't reversed");
}


Test(Cube, rotateEquatorSliceLeft_backFaceEquatorRow_reversed_rightFaceEquatorRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	equatorRow(backFace, oldBackFaceEquatorRow);
	reverseSpan(oldBackFaceEquatorRow);

	// when
	Cube_rotateEquatorSliceLeft(cube);

	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	equatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		oldBackFaceEquatorRow,
		newRightFaceEquatorRow,
		FACE_SIZE,
		"back face equator row wasn't reversed");
}


Test(Cube, rotateTopSliceRight_rightFaceTopRow_reversed_backFaceBottomRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	topRow(rightFace, oldRightFaceTopRow);
	reverseSpan(oldRightFaceTopRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		oldRightFaceTopRow,
		newBackFaceBottomRow,
		FACE_SIZE,
		"right face top row wasn't reversed");
}


Test(Cube, rotateTopSliceRight_backFaceBottomRow_reversed_leftFaceTopRow)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	bottomRow(backFace, oldBackFaceBottomRow);
	reverseSpan(oldBackFaceBottomRow);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	topRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		oldBackFaceBottomRow,
		newLeftFaceTopRow,
		FACE_SIZE,
		"back face bottom row wasn't reversed");
}


static Cube * createScrambledCube(void)
{
	Cube * cube = Cube_create();

#if 1

	// official terminology:
	// D2 F2 R2 D2 L2 U F2 U' F' U F2 U' R2 B' F R' D2 F' D' L
	//
	// D2
	Cube_rotateBottomSliceRight(cube);
	Cube_rotateBottomSliceRight(cube);
	// F2
	Cube_rotateFrontSliceClockwise(cube);
	Cube_rotateFrontSliceClockwise(cube);
	// R2
	Cube_rotateRightSliceUp(cube);
	Cube_rotateRightSliceUp(cube);
	// D2
	Cube_rotateBottomSliceRight(cube);
	Cube_rotateBottomSliceRight(cube);
	// L2
	Cube_rotateLeftSliceDown(cube);
	Cube_rotateLeftSliceDown(cube);
	// U
	Cube_rotateTopSliceLeft(cube);
	// F2
	Cube_rotateFrontSliceClockwise(cube);
	Cube_rotateFrontSliceClockwise(cube);
	// U'
	Cube_rotateTopSliceRight(cube);
	// F'
	Cube_rotateFrontSliceAnticlockwise(cube);
	// U
	Cube_rotateTopSliceLeft(cube);
	// F2
	Cube_rotateFrontSliceClockwise(cube);
	Cube_rotateFrontSliceClockwise(cube);
	// U'
	Cube_rotateTopSliceRight(cube);
	// R2
	Cube_rotateRightSliceUp(cube);
	Cube_rotateRightSliceUp(cube);
	// B'
	Cube_rotateBackSliceClockwise(cube);
	// F
	Cube_rotateFrontSliceClockwise(cube);
	// R'
	Cube_rotateRightSliceDown(cube);
	// D2
	Cube_rotateBottomSliceRight(cube);
	Cube_rotateBottomSliceRight(cube);
	// F'
	Cube_rotateFrontSliceAnticlockwise(cube);
	// D'
	Cube_rotateBottomSliceLeft(cube);
	// L
	Cube_rotateLeftSliceDown(cube);

	//	+-------+-------+-------+
	//	| G W Y | R Y W | R W B |
    //	| B R O | W B G | Y O G |
    //	| O Y G | Y R O | W B Y |
    //	+-------+-------+-------+
    //	        | O W G |
    //	        | R Y R |
    //	        | B G O |
    //	        +-------+
    //	        | W R B |
    //	        | Y G O |
    //	        | W B R |
    //	        +-------+
    //	        | R O Y |
    //	        | B W G |
    //	        | G O B |
	//		    +-------+

#else

	int rotationsLeft = 7;
	while (rotationsLeft--)
	{
		Cube_rotateTopSliceLeft(cube);
		Cube_rotateLeftSliceUp(cube);
		Cube_rotateFrontSliceClockwise(cube);

		Cube_rotateBottomSliceRight(cube);
		Cube_rotateRightSliceDown(cube);
		Cube_rotateBackSliceAnticlockwise(cube);
	}

#endif

	return cube;
}


static void topRow(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topLeftCell(face);
	buffer[1] = Face_topCenterCell(face);
	buffer[2] = Face_topRightCell(face);
}


static void equatorRow(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_equatorLeftCell(face);
	buffer[1] = Face_equatorCenterCell(face);
	buffer[2] = Face_equatorRightCell(face);
}


static void bottomRow(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_bottomLeftCell(face);
	buffer[1] = Face_bottomCenterCell(face);
	buffer[2] = Face_bottomRightCell(face);
}


static void leftColumn(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topLeftCell(face);
	buffer[1] = Face_equatorLeftCell(face);
	buffer[2] = Face_bottomLeftCell(face);
}


static void middleColumn(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topCenterCell(face);
	buffer[1] = Face_equatorCenterCell(face);
	buffer[2] = Face_bottomCenterCell(face);
}


static void rightColumn(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topRightCell(face);
	buffer[1] = Face_equatorRightCell(face);
	buffer[2] = Face_bottomRightCell(face);
}


static void readFace(Face const * face, Color buffer[FACE_SIZE][FACE_SIZE])
{
	topRow(face, buffer[0]);
	equatorRow(face, buffer[1]);
	bottomRow(face, buffer[2]);
}


static void _assert_faceRotatedClockwise(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line)
{
	Color after[FACE_SIZE][FACE_SIZE];
	readFace(face, after);

	cr_assert_eq(
		before[1][1],
		after[1][1],
		"%s:%d :: %s face clockwise rotation: face changed color",
		file,
		line,
		facePosition);

	cr_assert_eq(
		before[0][0],
		after[0][2],
		"%s:%d :: %s face clockwise rotation -> top-left cell didn't go top-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[0][1],
		after[1][2],
		"%s:%d :: %s face clockwise rotation -> top-center cell didn't go equator-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[0][2],
		after[2][2],
		"%s:%d :: %s face clockwise rotation -> top-right cell didn't go bottom-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[1][0],
		after[0][1],
		"%s:%d :: %s face clockwise rotation -> equator-left cell didn't go top-center",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[1][2],
		after[2][1],
		"%s:%d :: %s face clockwise rotation -> equator-right cell didn't go bottom-center",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][0],
		after[0][0],
		"%s:%d :: %s face clockwise rotation -> bottom-left cell didn't go top-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][1],
		after[1][0],
		"%s:%d :: %s face clockwise rotation -> bottom-center cell didn't go equator-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][2],
		after[2][0],
		"%s:%d :: %s face clockwise rotation -> bottom-right cell didn't go bottom-left",
		file,
		line,
		facePosition);
}


static void _assert_faceRotatedAnticlockwise(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line)
{
	Color after[FACE_SIZE][FACE_SIZE];
	readFace(face, after);

	cr_assert_eq(
		before[1][1],
		after[1][1],
		"%s:%d :: %s face anticlockwise rotation: face changed color",
		file,
		line,
		facePosition);

	cr_assert_eq(
		before[0][0],
		after[2][0],
		"%s:%d :: %s face anticlockwise rotation: top-left cell didn't go bottom-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[0][1],
		after[1][0],
		"%s:%d :: %s face anticlockwise rotation: top-center cell didn't go equator-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[0][2],
		after[0][0],
		"%s:%d :: %s face anticlockwise rotation: top-right cell didn't go top-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[1][0],
		after[2][1],
		"%s:%d :: %s face anticlockwise rotation: equator-left cell didn't bottom-center",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[1][2],
		after[0][1],
		"%s:%d :: %s face anticlockwise rotation: equator-right cell didn't go top-center",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][0],
		after[2][2],
		"%s:%d :: %s face anticlockwise rotation: bottom-left cell didn't go bottom-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][1],
		after[1][2],
		"%s:%d :: %s face anticlockwise rotation: bottom-center cell didn't equator-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][2],
		after[0][2],
		"%s:%d :: %s face anticlockwise rotation: bottom-right cell didn't go top-right",
		file,
		line,
		facePosition);
}
