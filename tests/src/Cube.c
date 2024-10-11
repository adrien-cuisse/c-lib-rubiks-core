
#include <criterion/criterion.h>

#include "../../src/Cube.h"




static Cube * createScrambledCube(void);


static void readFace(Face const * face, Color storage[FACE_SIZE][FACE_SIZE]);




Test(Cube, create_allocatesMemory)
{
	// given
	Cube * allocatedMemory = _Cube->create();
	// when
	// then
	cr_assert_not_null(allocatedMemory, "no memory was allocated");
}


Test(Cube, delete_deallocatesMemory)
{
	// given
	Cube * allocatedMemory = _Cube->create();
	// when
	_Cube->delete(& allocatedMemory);
	// then
	cr_assert_null(allocatedMemory, "memory was not deallocated");
}


Test(Cube, isInitializedWithBlueFaceInFront)
{
	// given
	Cube * cube = _Cube->create();
	// when
	Face * frontFace = _Cube->frontFace(cube);
	// then
	Color frontFaceColor = _Face->color(frontFace);
	cr_assert_eq(frontFaceColor, BLUE, "front face is not blue");
}


Test(Cube, isInitializedWithRedFaceOnTheLeft)
{
	// given
	Cube * cube = _Cube->create();
	// when
	Face * leftFace = _Cube->leftFace(cube);
	// then
	Color leftFaceColor = _Face->color(leftFace);
	cr_assert_eq(leftFaceColor, RED, "left face is not red");
}


Test(Cube, isInitializedWithOrangeFaceOnTheRight)
{
	// given
	Cube * cube = _Cube->create();
	// when
	Face * rightFace = _Cube->rightFace(cube);
	// then
	Color rightFaceColor = _Face->color(rightFace);
	cr_assert_eq(rightFaceColor, ORANGE, "right face is not orange");
}


Test(Cube, isInitializedWithWhiteFaceOnTop)
{
	// given
	Cube * cube = _Cube->create();
	// when
	Face * topFace = _Cube->topFace(cube);
	// then
	Color topFaceColor = _Face->color(topFace);
	cr_assert_eq(topFaceColor, WHITE, "top face is not white");
}


Test(Cube, isInitializedWithYellowFaceAtBottom)
{
	// given
	Cube * cube = _Cube->create();
	// when
	Face * bottomFace = _Cube->bottomFace(cube);
	// then
	Color bottomFaceColor = _Face->color(bottomFace);
	cr_assert_eq(bottomFaceColor, YELLOW, "bottom face is not yellow");
}


Test(Cube, isInitializedWithGreenFaceOnTheBack)
{
	// given
	Cube * cube = _Cube->create();
	// when
	Face * backFace = _Cube->backFace(cube);
	// then
	Color backFaceColor = _Face->color(backFace);
	cr_assert_eq(backFaceColor, GREEN, "back face is not green");
}


Test(Cube, rotateLeft_rightFaceGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldRightFace = _Cube->rightFace(cube);
	// when
	_Cube->rotateLeft(cube);
	// then
	Face * newFrontFace = _Cube->frontFace(cube);
	cr_assert_eq(newFrontFace, oldRightFace, "right face wasn't moved to the front");
}


Test(Cube, rotateLeft_backFaceGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldBackFace = _Cube->backFace(cube);
	// when
	_Cube->rotateLeft(cube);
	// then
	Face * newRightFace = _Cube->rightFace(cube);
	cr_assert_eq(newRightFace, oldBackFace, "back face wasn't moved to the right");
}


Test(Cube, rotateLeft_leftFaceGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldLeftFace = _Cube->leftFace(cube);
	// when
	_Cube->rotateLeft(cube);
	// then
	Face * newBackFace = _Cube->backFace(cube);
	cr_assert_eq(newBackFace, oldLeftFace, "left face wasn't moved to the back");
}


Test(Cube, rotateLeft_frontFaceGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldFrontFace = _Cube->frontFace(cube);
	// when
	_Cube->rotateLeft(cube);
	// then
	Face * newLeftFace = _Cube->leftFace(cube);
	cr_assert_eq(newLeftFace, oldFrontFace, "front face wasn't moved to the left");
}


Test(Cube, rotateRight_frontFaceGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldFrontFace = _Cube->frontFace(cube);
	// when
	_Cube->rotateRight(cube);
	// then
	Face * newRightFace = _Cube->rightFace(cube);
	cr_assert_eq(newRightFace, oldFrontFace, "front face wasn't moved to the right");
}


Test(Cube, rotateRight_rightFaceGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldRightFace = _Cube->rightFace(cube);
	// when
	_Cube->rotateRight(cube);
	// then
	Face * newBackFace = _Cube->backFace(cube);
	cr_assert_eq(newBackFace, oldRightFace, "right face wasn't moved to the back");
}


Test(Cube, rotateRight_backFaceGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldBackFace = _Cube->backFace(cube);
	// when
	_Cube->rotateRight(cube);
	// then
	Face * newLeftFace = _Cube->leftFace(cube);
	cr_assert_eq(newLeftFace, oldBackFace, "back face wasn't moved to the left");
}


Test(Cube, rotateRight_leftFaceGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldLeftFace = _Cube->leftFace(cube);
	// when
	_Cube->rotateRight(cube);
	// then
	Face * newFrontFace = _Cube->frontFace(cube);
	cr_assert_eq(newFrontFace, oldLeftFace, "left face wasn't moved to the front");
}


Test(Cube, rotateUp_frontFaceGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldFrontFace = _Cube->frontFace(cube);
	// when
	_Cube->rotateUp(cube);
	// then
	Face * newTopFace = _Cube->topFace(cube);
	cr_assert_eq(newTopFace, oldFrontFace, "front face wasn't moved to the top");
}


Test(Cube, rotateUp_topFaceGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldTopFace = _Cube->topFace(cube);
	// when
	_Cube->rotateUp(cube);
	// then
	Face * newBackFace = _Cube->backFace(cube);
	cr_assert_eq(newBackFace, oldTopFace, "top face wasn't moved to the back");
}


Test(Cube, rotateUp_backFaceGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldBackFace = _Cube->backFace(cube);
	// when
	_Cube->rotateUp(cube);
	// then
	Face * newBottomFace = _Cube->bottomFace(cube);
	cr_assert_eq(newBottomFace, oldBackFace, "back face wasn't moved to the bottom");
}


Test(Cube, rotateUp_bottomFaceGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldBottomFace = _Cube->bottomFace(cube);
	// when
	_Cube->rotateUp(cube);
	// then
	Face * newFrontFace = _Cube->frontFace(cube);
	cr_assert_eq(newFrontFace, oldBottomFace, "bottom face wasn't moved to the front");
}


Test(Cube, rotateDown_frontFaceGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldFrontFace = _Cube->frontFace(cube);
	// when
	_Cube->rotateDown(cube);
	// then
	Face * newBottomFace = _Cube->bottomFace(cube);
	cr_assert_eq(newBottomFace, oldFrontFace, "front face wasn't moved to the bottom");
}


Test(Cube, rotateDown_bottomFaceGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldBottomFace = _Cube->bottomFace(cube);
	// when
	_Cube->rotateDown(cube);
	// then
	Face * newBackFace = _Cube->backFace(cube);
	cr_assert_eq(newBackFace, oldBottomFace, "bottom face wasn't moved to the back");
}


Test(Cube, rotateDown_backFaceGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldBackFace = _Cube->backFace(cube);
	// when
	_Cube->rotateDown(cube);
	// then
	Face * newTopFace = _Cube->topFace(cube);
	cr_assert_eq(newTopFace, oldBackFace, "back face wasn't moved to the top");
}


Test(Cube, rotateDown_topFaceGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldTopFace = _Cube->topFace(cube);
	// when
	_Cube->rotateDown(cube);
	// then
	Face * newFrontFace = _Cube->frontFace(cube);
	cr_assert_eq(newFrontFace, oldTopFace, "top face wasn't moved to the front");
}


Test(Cube, rotateClockwise_topFaceGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldTopFace = _Cube->topFace(cube);
	// when
	_Cube->rotateClockwise(cube);
	// then
	Face * newRightFace = _Cube->rightFace(cube);
	cr_assert_eq(newRightFace, oldTopFace, "top face wasn't moved to the right");
}


Test(Cube, rotateClockwise_rightFaceGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldRightFace = _Cube->rightFace(cube);
	// when
	_Cube->rotateClockwise(cube);
	// then
	Face * newBottomFace = _Cube->bottomFace(cube);
	cr_assert_eq(newBottomFace, oldRightFace, "right face wasn't moved to the bottom");
}


Test(Cube, rotateClockwise_bottomFaceGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldBottomFace = _Cube->bottomFace(cube);
	// when
	_Cube->rotateClockwise(cube);
	// then
	Face * newLeftFace = _Cube->leftFace(cube);
	cr_assert_eq(newLeftFace, oldBottomFace, "bottom face wasn't moved to the left");
}


Test(Cube, rotateClockwise_leftFaceGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldLeftFace = _Cube->leftFace(cube);
	// when
	_Cube->rotateClockwise(cube);
	// then
	Face * newTopFace = _Cube->topFace(cube);
	cr_assert_eq(newTopFace, oldLeftFace, "left face wasn't moved to the top");
}


Test(Cube, rotateAnticlockwise_topFaceGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldTopFace = _Cube->topFace(cube);
	// when
	_Cube->rotateAnticlockwise(cube);
	// then
	Face * newLeftFace = _Cube->leftFace(cube);
	cr_assert_eq(newLeftFace, oldTopFace, "top face wasn't moved to the left");
}


Test(Cube, rotateAnticlockwise_leftFaceGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldLeftFace = _Cube->leftFace(cube);
	// when
	_Cube->rotateAnticlockwise(cube);
	// then
	Face * newBottomFace = _Cube->bottomFace(cube);
	cr_assert_eq(newBottomFace, oldLeftFace, "left face wasn't moved to the bottom");
}


Test(Cube, rotateAnticlockwise_bottomFaceGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldBottomFace = _Cube->bottomFace(cube);
	// when
	_Cube->rotateAnticlockwise(cube);
	// then
	Face * newRightFace = _Cube->rightFace(cube);
	cr_assert_eq(newRightFace, oldBottomFace, "bottom face wasn't moved to the right");
}


Test(Cube, rotateAnticlockwise_rightFaceGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * oldRightFace = _Cube->rightFace(cube);
	// when
	_Cube->rotateAnticlockwise(cube);
	// then
	Face * newTopFace = _Cube->topFace(cube);
	cr_assert_eq(newTopFace, oldRightFace, "right face wasn't moved to the top");
}


Test(Cube, turnTopSliceLeft_frontRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	_Face->topRow(frontFace, oldFrontFaceTopRow);
	// when
	_Cube->turnTopSliceLeft(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	_Face->topRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		newLeftFaceTopRow,
		oldFrontFaceTopRow,
		FACE_SIZE,
		"front face top row wasn't moved to the left face top row");
}


Test(Cube, turnTopSliceLeft_leftRowGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	_Face->topRow(leftFace, oldLeftFaceTopRow);
	// when
	_Cube->turnTopSliceLeft(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		newBackFaceBottomRow,
		oldLeftFaceTopRow,
		FACE_SIZE,
		"left face top row wasn't moved to the back face bottom row");
}


Test(Cube, turnTopSliceLeft_backRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(backFace, oldBackFaceBottomRow);
	// when
	_Cube->turnTopSliceLeft(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceTopRow[FACE_SIZE];
	_Face->topRow(rightFace, newRightFaceTopRow);
	cr_assert_arr_eq(
		newRightFaceTopRow,
		oldBackFaceBottomRow,
		FACE_SIZE,
		"back face bottom row wasn't moved to the right face top row");
}


Test(Cube, turnTopSliceLeft_rightRowGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	_Face->topRow(rightFace, oldRightFaceTopRow);
	// when
	_Cube->turnTopSliceLeft(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceTopRow[FACE_SIZE];
	_Face->topRow(frontFace, newFrontFaceTopRow);
	cr_assert_arr_eq(
		newFrontFaceTopRow,
		oldRightFaceTopRow,
		FACE_SIZE,
		"right face top row wasn't moved to the front face top row");
}


Test(Cube, turnTopSliceRight_frontRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	_Face->topRow(frontFace, oldFrontFaceTopRow);
	// when
	_Cube->turnTopSliceRight(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceTopRow[FACE_SIZE];
	_Face->topRow(rightFace, newRightFaceTopRow);
	cr_assert_arr_eq(
		newRightFaceTopRow,
		oldFrontFaceTopRow,
		FACE_SIZE,
		"front face top row wasn't moved to the right face top row");
}


Test(Cube, turnTopSliceRight_rightRowGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	_Face->topRow(rightFace, oldRightFaceTopRow);
	// when
	_Cube->turnTopSliceRight(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		newBackFaceBottomRow,
		oldRightFaceTopRow,
		FACE_SIZE,
		"right face top row wasn't moved to the back face bottom row");
}


Test(Cube, turnTopSliceRight_backRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(backFace, oldBackFaceBottomRow);
	// when
	_Cube->turnTopSliceRight(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	_Face->topRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		newLeftFaceTopRow,
		oldBackFaceBottomRow,
		FACE_SIZE,
		"back face bottom row wasn't moved to the left face top row");
}


Test(Cube, turnTopSliceRight_leftRowGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	_Face->topRow(leftFace, oldLeftFaceTopRow);
	// when
	_Cube->turnTopSliceRight(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceTopRow[FACE_SIZE];
	_Face->topRow(frontFace, newFrontFaceTopRow);
	cr_assert_arr_eq(
		newFrontFaceTopRow,
		oldLeftFaceTopRow,
		FACE_SIZE,
		"left face top row wasn't moved to the front face top row");
}


Test(Cube, turnEquatorSliceLeft_frontRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(frontFace, oldFrontFaceEquatorRow);
	// when
	_Cube->turnEquatorSliceLeft(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(leftFace, newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		newLeftFaceEquatorRow,
		oldFrontFaceEquatorRow,
		FACE_SIZE,
		"front face equator row wasn't moved to the left face equator row");
}


Test(Cube, turnEquatorSliceLeft_leftRowGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(leftFace, oldLeftFaceEquatorRow);
	// when
	_Cube->turnEquatorSliceLeft(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(backFace, newBackFaceEquatorRow);
	cr_assert_arr_eq(
		newBackFaceEquatorRow,
		oldLeftFaceEquatorRow,
		FACE_SIZE,
		"left face equator row wasn't moved to the back face equator row");
}


Test(Cube, turnEquatorSliceLeft_backRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(backFace, oldBackFaceEquatorRow);
	// when
	_Cube->turnEquatorSliceLeft(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		newRightFaceEquatorRow,
		oldBackFaceEquatorRow,
		FACE_SIZE,
		"back face equator row wasn't moved to the right face equator row");
}


Test(Cube, turnEquatorSliceLeft_rightRowGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(rightFace, oldRightFaceEquatorRow);
	// when
	_Cube->turnEquatorSliceLeft(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(frontFace, newFrontFaceEquatorRow);
	cr_assert_arr_eq(
		newFrontFaceEquatorRow,
		oldRightFaceEquatorRow,
		FACE_SIZE,
		"right face equator row wasn't moved to the front face equator row");
}


Test(Cube, turnEquatorSliceRight_frontRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(frontFace, oldFrontFaceEquatorRow);
	// when
	_Cube->turnEquatorSliceRight(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		newRightFaceEquatorRow,
		oldFrontFaceEquatorRow,
		FACE_SIZE,
		"front face equator row wasn't moved to the right face equator row");
}


Test(Cube, turnEquatorSliceRight_rightRowGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(rightFace, oldRightFaceEquatorRow);
	// when
	_Cube->turnEquatorSliceRight(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(backFace, newBackFaceEquatorRow);
	cr_assert_arr_eq(
		newBackFaceEquatorRow,
		oldRightFaceEquatorRow,
		FACE_SIZE,
		"right face equator row wasn't moved to the back face equator row");
}


Test(Cube, turnEquatorSliceRight_backRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(backFace, oldBackFaceEquatorRow);
	// when
	_Cube->turnEquatorSliceRight(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(leftFace, newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		newLeftFaceEquatorRow,
		oldBackFaceEquatorRow,
		FACE_SIZE,
		"back face equator row wasn't moved to the left face equator row");
}


Test(Cube, turnEquatorSliceRight_leftRowGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(leftFace, oldLeftFaceEquatorRow);
	// when
	_Cube->turnEquatorSliceRight(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(frontFace, newFrontFaceEquatorRow);
	cr_assert_arr_eq(
		newFrontFaceEquatorRow,
		oldLeftFaceEquatorRow,
		FACE_SIZE,
		"left face equator row wasn't moved to the front face equator row");
}


Test(Cube, turnBottomSliceLeft_frontRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(frontFace, oldFrontFaceBottomRow);
	// when
	_Cube->turnBottomSliceLeft(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(leftFace, newLeftFaceBottomRow);
	cr_assert_arr_eq(
		newLeftFaceBottomRow,
		oldFrontFaceBottomRow,
		FACE_SIZE,
		"front face bottom row wasn't moved to the left face bottom row");
}


Test(Cube, turnBottomSliceLeft_leftRowGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(leftFace, oldLeftFaceBottomRow);
	// when
	_Cube->turnBottomSliceLeft(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceTopRow[FACE_SIZE];
	_Face->topRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		newBackFaceTopRow,
		oldLeftFaceBottomRow,
		FACE_SIZE,
		"left face bottom row wasn't moved to the back face top row");
}


Test(Cube, turnBottomSliceLeft_backRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	_Face->topRow(backFace, oldBackFaceTopRow);
	// when
	_Cube->turnBottomSliceLeft(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(rightFace, newRightFaceBottomRow);
	cr_assert_arr_eq(
		newRightFaceBottomRow,
		oldBackFaceTopRow,
		FACE_SIZE,
		"back face top row wasn't moved to the right face bottom row");
}


Test(Cube, turnBottomSliceLeft_rightRowGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(rightFace, oldRightFaceBottomRow);
	// when
	_Cube->turnBottomSliceLeft(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(frontFace, newFrontFaceBottomRow);
	cr_assert_arr_eq(
		newFrontFaceBottomRow,
		oldRightFaceBottomRow,
		FACE_SIZE,
		"right face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, turnBottomSliceRight_frontRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(frontFace, oldFrontFaceBottomRow);
	// when
	_Cube->turnBottomSliceRight(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(rightFace, newRightFaceBottomRow);
	cr_assert_arr_eq(
		newRightFaceBottomRow,
		oldFrontFaceBottomRow,
		FACE_SIZE,
		"front face bottom row wasn't moved to the right face bottom row");
}


Test(Cube, turnBottomSliceRight_rightRowGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(rightFace, oldRightFaceBottomRow);
	// when
	_Cube->turnBottomSliceRight(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceTopRow[FACE_SIZE];
	_Face->topRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		newBackFaceTopRow,
		oldRightFaceBottomRow,
		FACE_SIZE,
		"right face bottom row wasn't moved to the back face top row");
}


Test(Cube, turnBottomSliceRight_backRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	_Face->topRow(backFace, oldBackFaceTopRow);
	// when
	_Cube->turnBottomSliceRight(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(leftFace, newLeftFaceBottomRow);
	cr_assert_arr_eq(
		newLeftFaceBottomRow,
		oldBackFaceTopRow,
		FACE_SIZE,
		"back face top row wasn't moved to the left face bottom row");
}


Test(Cube, turnBottomSliceRight_leftRowGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(leftFace, oldLeftFaceBottomRow);
	// when
	_Cube->turnBottomSliceRight(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(frontFace, newFrontFaceBottomRow);
	cr_assert_arr_eq(
		newFrontFaceBottomRow,
		oldLeftFaceBottomRow,
		FACE_SIZE,
		"left face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, turnLeftSliceUp_frontColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(frontFace, oldFrontFaceLeftColumn);
	// when
	_Cube->turnLeftSliceUp(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(topFace, newTopFaceLeftColumn);
	cr_assert_arr_eq(
		newTopFaceLeftColumn,
		oldFrontFaceLeftColumn,
		FACE_SIZE,
		"front face left column wasn't moved to the top face left column");
}


Test(Cube, turnLeftSliceUp_topColumnGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(topFace, oldTopFaceLeftColumn);
	// when
	_Cube->turnLeftSliceUp(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(backFace, newBackFaceLeftColumn);
	cr_assert_arr_eq(
		newBackFaceLeftColumn,
		oldTopFaceLeftColumn,
		FACE_SIZE,
		"top face left column wasn't moved to the back face left column");
}


Test(Cube, turnLeftSliceUp_backColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(backFace, oldBackFaceLeftColumn);
	// when
	_Cube->turnLeftSliceUp(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(bottomFace, newBottomFaceLeftColumn);
	cr_assert_arr_eq(
		newBottomFaceLeftColumn,
		oldBackFaceLeftColumn,
		FACE_SIZE,
		"back face left column wasn't moved to the bottom face left column");
}


Test(Cube, turnLeftSliceUp_bottomColumnGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(bottomFace, oldBottomFaceLeftColumn);
	// when
	_Cube->turnLeftSliceUp(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(frontFace, newFrontFaceLeftColumn);
	cr_assert_arr_eq(
		newFrontFaceLeftColumn,
		oldBottomFaceLeftColumn,
		FACE_SIZE,
		"bottom face left column wasn't moved to the front face left column");
}


Test(Cube, turnLeftSliceDown_frontColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(frontFace, oldFrontFaceLeftColumn);
	// when
	_Cube->turnLeftSliceDown(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(bottomFace, newBottomFaceLeftColumn);
	cr_assert_arr_eq(
		newBottomFaceLeftColumn,
		oldFrontFaceLeftColumn,
		FACE_SIZE,
		"front face left column wasn't moved to the bottom face left column");
}


Test(Cube, turnLeftSliceDown_bottomColumnGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(bottomFace, oldBottomFaceLeftColumn);
	// when
	_Cube->turnLeftSliceDown(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(backFace, newBackFaceLeftColumn);
	cr_assert_arr_eq(
		newBackFaceLeftColumn,
		oldBottomFaceLeftColumn,
		FACE_SIZE,
		"bottom face left column wasn't moved to the back face left column");
}


Test(Cube, turnLeftSliceDown_backColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(backFace, oldBackFaceLeftColumn);
	// when
	_Cube->turnLeftSliceDown(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(topFace, newTopFaceLeftColumn);
	cr_assert_arr_eq(
		newTopFaceLeftColumn,
		oldBackFaceLeftColumn,
		FACE_SIZE,
		"back face left column wasn't moved to the top face left column");
}


Test(Cube, turnLeftSliceDown_topColumnGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(topFace, oldTopFaceLeftColumn);
	// when
	_Cube->turnLeftSliceDown(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(frontFace, newFrontFaceLeftColumn);
	cr_assert_arr_eq(
		newFrontFaceLeftColumn,
		oldTopFaceLeftColumn,
		FACE_SIZE,
		"top face left column wasn't moved to the front face left column");
}


Test(Cube, turnMiddleSliceUp_frontColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	_Cube->turnMiddleSliceUp(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(topFace, newTopFaceMiddleColumn);
	cr_assert_arr_eq(
		newTopFaceMiddleColumn,
		oldFrontFaceMiddleColumn,
		FACE_SIZE,
		"front face middle column wasn't moved to the top face middle column");
}


Test(Cube, turnMiddleSliceUp_topColumnGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(topFace, oldTopFaceMiddleColumn);
	// when
	_Cube->turnMiddleSliceUp(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(backFace, newBackFaceMiddleColumn);
	cr_assert_arr_eq(
		newBackFaceMiddleColumn,
		oldTopFaceMiddleColumn,
		FACE_SIZE,
		"top face middle column wasn't moved to the back face middle column");
}


Test(Cube, turnMiddleSliceUp_backColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(backFace, oldBackFaceMiddleColumn);
	// when
	_Cube->turnMiddleSliceUp(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(bottomFace, newBottomFaceMiddleColumn);
	cr_assert_arr_eq(
		newBottomFaceMiddleColumn,
		oldBackFaceMiddleColumn,
		FACE_SIZE,
		"back face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, turnMiddleSliceUp_bottomColumnGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	_Cube->turnMiddleSliceUp(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(frontFace, newFrontFaceMiddleColumn);
	cr_assert_arr_eq(
		newFrontFaceMiddleColumn,
		oldBottomFaceMiddleColumn,
		FACE_SIZE,
		"bottom face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, turnMiddleSliceDown_frontColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	_Cube->turnMiddleSliceDown(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(bottomFace, newBottomFaceMiddleColumn);
	cr_assert_arr_eq(
		newBottomFaceMiddleColumn,
		oldFrontFaceMiddleColumn,
		FACE_SIZE,
		"front face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, turnMiddleSliceDown_bottomColumnGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	_Cube->turnMiddleSliceDown(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(backFace, newBackFaceMiddleColumn);
	cr_assert_arr_eq(
		newBackFaceMiddleColumn,
		oldBottomFaceMiddleColumn,
		FACE_SIZE,
		"bottom face middle column wasn't moved to the back face middle column");
}


Test(Cube, turnMiddleSliceDown_backColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(backFace, oldBackFaceMiddleColumn);
	// when
	_Cube->turnMiddleSliceDown(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(topFace, newTopFaceMiddleColumn);
	cr_assert_arr_eq(
		newTopFaceMiddleColumn,
		oldBackFaceMiddleColumn,
		FACE_SIZE,
		"back face middle column wasn't moved to the top face middle column");
}


Test(Cube, turnMiddleSliceDown_topColumnGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(topFace, oldTopFaceMiddleColumn);
	// when
	_Cube->turnMiddleSliceDown(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(frontFace, newFrontFaceMiddleColumn);
	cr_assert_arr_eq(
		newFrontFaceMiddleColumn,
		oldTopFaceMiddleColumn,
		FACE_SIZE,
		"top face middle column wasn't moved to the front face middle column");
}


Test(Cube, turnRightSliceUp_frontColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	_Cube->turnRightSliceUp(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(topFace, newTopFaceMiddleColumn);
	cr_assert_arr_eq(
		newTopFaceMiddleColumn,
		oldFrontFaceMiddleColumn,
		FACE_SIZE,
		"front face right column wasn't moved to the top face right column");
}


Test(Cube, turnRightSliceUp_topColumnGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(topFace, oldTopFaceMiddleColumn);
	// when
	_Cube->turnRightSliceUp(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(backFace, newBackFaceMiddleColumn);
	cr_assert_arr_eq(
		newBackFaceMiddleColumn,
		oldTopFaceMiddleColumn,
		FACE_SIZE,
		"top face right column wasn't moved to the back face right column");
}


Test(Cube, turnRightSliceUp_backColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(backFace, oldBackFaceMiddleColumn);
	// when
	_Cube->turnRightSliceUp(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(bottomFace, newBottomFaceMiddleColumn);
	cr_assert_arr_eq(
		newBottomFaceMiddleColumn,
		oldBackFaceMiddleColumn,
		FACE_SIZE,
		"back face right column wasn't moved to the bottom face right column");
}


Test(Cube, turnRightSliceUp_bottomColumnGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	_Cube->turnRightSliceUp(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(frontFace, newFrontFaceMiddleColumn);
	cr_assert_arr_eq(
		newFrontFaceMiddleColumn,
		oldBottomFaceMiddleColumn,
		FACE_SIZE,
		"bottom face right column wasn't moved to the front face right column");
}


Test(Cube, turnRightSliceDown_frontColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	_Cube->turnRightSliceDown(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(bottomFace, newBottomFaceMiddleColumn);
	cr_assert_arr_eq(
		newBottomFaceMiddleColumn,
		oldFrontFaceMiddleColumn,
		FACE_SIZE,
		"front face right column wasn't moved to the bottom face right column");
}


Test(Cube, turnRightSliceDown_bottomColumnGoesBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	_Cube->turnRightSliceDown(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(backFace, newBackFaceMiddleColumn);
	cr_assert_arr_eq(
		newBackFaceMiddleColumn,
		oldBottomFaceMiddleColumn,
		FACE_SIZE,
		"bottom face right column wasn't moved to the back face right column");
}


Test(Cube, turnRightSliceDown_backColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(backFace, oldBackFaceMiddleColumn);
	// when
	_Cube->turnRightSliceDown(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(topFace, newTopFaceMiddleColumn);
	cr_assert_arr_eq(
		newTopFaceMiddleColumn,
		oldBackFaceMiddleColumn,
		FACE_SIZE,
		"back face right column wasn't moved to the top face right column");
}


Test(Cube, turnRightSliceDown_topColumnGoesFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(topFace, oldTopFaceMiddleColumn);
	// when
	_Cube->turnRightSliceDown(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceMiddleColumn[FACE_SIZE];
	_Face->rightColumn(frontFace, newFrontFaceMiddleColumn);
	cr_assert_arr_eq(
		newFrontFaceMiddleColumn,
		oldTopFaceMiddleColumn,
		FACE_SIZE,
		"top face right column wasn't moved to the front face right column");
}


Test(Cube, turnFrontSliceClockwise_topRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(topFace, oldTopFaceBottomRow);
	// when
	_Cube->turnFrontSliceClockwise(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(rightFace, newRightFaceLeftColumn);
	cr_assert_arr_eq(
		newRightFaceLeftColumn,
		oldTopFaceBottomRow,
		FACE_SIZE,
		"top face bottom row wasn't moved to the right face left column");
}


Test(Cube, turnFrontSliceClockwise_rightColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(rightFace, oldRightFaceLeftColumn);
	// when
	_Cube->turnFrontSliceClockwise(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceTopRow[FACE_SIZE];
	_Face->topRow(bottomFace, newBottomFaceTopRow);
	cr_assert_arr_eq(
		newBottomFaceTopRow,
		oldRightFaceLeftColumn,
		FACE_SIZE,
		"right face left column wasn't moved to the bottom face top row");
}

Test(Cube, turnFrontSliceClockwise_bottomRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	_Face->topRow(bottomFace, oldBottomFaceTopRow);
	// when
	_Cube->turnFrontSliceClockwise(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceRightColumn[FACE_SIZE];
	_Face->rightColumn(leftFace, newLeftFaceRightColumn);
	cr_assert_arr_eq(
		newLeftFaceRightColumn,
		oldBottomFaceTopRow,
		FACE_SIZE,
		"bottom face top row wasn't moved to the left face right column");
}


Test(Cube, turnFrontSliceClockwise_leftColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceRightColumn[FACE_SIZE];
	_Face->rightColumn(leftFace, oldLeftFaceRightColumn);
	// when
	_Cube->turnFrontSliceClockwise(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(topFace, newTopFaceBottomRow);
	cr_assert_arr_eq(
		newTopFaceBottomRow,
		oldLeftFaceRightColumn,
		FACE_SIZE,
		"left face right column wasn't moved to the top face bottom row");
}


Test(Cube, turnFrontSliceAnticlockwise_topRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(topFace, oldTopFaceBottomRow);
	// when
	_Cube->turnFrontSliceAnticlockwise(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceRightColumn[FACE_SIZE];
	_Face->rightColumn(leftFace, newLeftFaceRightColumn);
	cr_assert_arr_eq(
		newLeftFaceRightColumn,
		oldTopFaceBottomRow,
		FACE_SIZE,
		"top face bottom row wasn't moved to the left face right column");
}


Test(Cube, turnFrontSliceAnticlockwise_leftColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceRightColumn[FACE_SIZE];
	_Face->rightColumn(leftFace, oldLeftFaceRightColumn);
	// when
	_Cube->turnFrontSliceAnticlockwise(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceTopRow[FACE_SIZE];
	_Face->topRow(bottomFace, newBottomFaceTopRow);
	cr_assert_arr_eq(
		newBottomFaceTopRow,
		oldLeftFaceRightColumn,
		FACE_SIZE,
		"left face right column wasn't moved to the bottom face top row");
}


Test(Cube, turnFrontSliceAnticlockwise_bottomRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	_Face->topRow(bottomFace, oldBottomFaceTopRow);
	// when
	_Cube->turnFrontSliceAnticlockwise(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(rightFace, newRightFaceLeftColumn);
	cr_assert_arr_eq(
		newRightFaceLeftColumn,
		oldBottomFaceTopRow,
		FACE_SIZE,
		"bottom face top row wasn't moved to the right face left column");
}


Test(Cube, turnFrontSliceAnticlockwise_rightColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(rightFace, oldRightFaceLeftColumn);
	// when
	_Cube->turnFrontSliceAnticlockwise(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(topFace, newTopFaceBottomRow);
	cr_assert_arr_eq(
		newTopFaceBottomRow,
		oldRightFaceLeftColumn,
		FACE_SIZE,
		"right face left column wasn't moved to the top face bottom row");
}


Test(Cube, turnStandingSliceClockwise_topRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(topFace, oldTopFaceEquatorRow);
	// when
	_Cube->turnStandingSliceClockwise(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(rightFace, newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		newRightFaceMiddleColumn,
		oldTopFaceEquatorRow,
		FACE_SIZE,
		"top face equator row wasn't moved to the right face middle column");
}


Test(Cube, turnStandingSliceClockwise_rightColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(rightFace, oldRightFaceMiddleColumn);
	// when
	_Cube->turnStandingSliceClockwise(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		newBottomFaceEquatorRow,
		oldRightFaceMiddleColumn,
		FACE_SIZE,
		"right face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, turnStandingSliceClockwise_bottomRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(bottomFace, oldBottomFaceEquatorRow);
	// when
	_Cube->turnStandingSliceClockwise(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(leftFace, newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		newLeftFaceMiddleColumn,
		oldBottomFaceEquatorRow,
		FACE_SIZE,
		"bottom face equator row wasn't moved to the left face middle column");
}


Test(Cube, turnStandingSliceClockwise_leftColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(leftFace, oldLeftFaceMiddleColumn);
	// when
	_Cube->turnStandingSliceClockwise(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		newTopFaceEquatorRow,
		oldLeftFaceMiddleColumn,
		FACE_SIZE,
		"left face middle column wasn't moved to the top face equator row");
}


Test(Cube, turnStandingSliceAnticlockwise_topRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(topFace, oldTopFaceEquatorRow);
	// when
	_Cube->turnStandingSliceAnticlockwise(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(leftFace, newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		newLeftFaceMiddleColumn,
		oldTopFaceEquatorRow,
		FACE_SIZE,
		"top face equator row wasn't moved to the left face middle column");
}


Test(Cube, turnStandingSliceAnticlockwise_leftColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(leftFace, oldLeftFaceMiddleColumn);
	// when
	_Cube->turnStandingSliceAnticlockwise(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		newBottomFaceEquatorRow,
		oldLeftFaceMiddleColumn,
		FACE_SIZE,
		"left face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, turnStandingSliceAnticlockwise_bottomRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(bottomFace, oldBottomFaceEquatorRow);
	// when
	_Cube->turnStandingSliceAnticlockwise(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(rightFace, newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		newRightFaceMiddleColumn,
		oldBottomFaceEquatorRow,
		FACE_SIZE,
		"bottom face equator row wasn't moved to the right face middle column");
}


Test(Cube, turnStandingSliceAnticlockwise_rightColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	_Face->middleColumn(rightFace, oldRightFaceMiddleColumn);
	// when
	_Cube->turnStandingSliceAnticlockwise(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	_Face->equatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		newTopFaceEquatorRow,
		oldRightFaceMiddleColumn,
		FACE_SIZE,
		"right face middle column wasn't moved to the top face equator row");
}


Test(Cube, turnBackSliceClockwise_topRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceTopRow[FACE_SIZE];
	_Face->topRow(topFace, oldTopFaceTopRow);
	// when
	_Cube->turnBackSliceClockwise(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceRightColumn[FACE_SIZE];
	_Face->rightColumn(rightFace, newRightFaceRightColumn);
	cr_assert_arr_eq(
		newRightFaceRightColumn,
		oldTopFaceTopRow,
		FACE_SIZE,
		"top face top row wasn't moved to the right face right column");
}


Test(Cube, turnBackSliceClockwise_rightColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceRightColumn[FACE_SIZE];
	_Face->rightColumn(rightFace, oldRightFaceRightColumn);
	// when
	_Cube->turnBackSliceClockwise(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(bottomFace, newBottomFaceBottomRow);
	cr_assert_arr_eq(
		newBottomFaceBottomRow,
		oldRightFaceRightColumn,
		FACE_SIZE,
		"right face right column wasn't moved to the bottom face bottom row");
}


Test(Cube, turnBackSliceClockwise_bottomRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(bottomFace, oldBottomFaceBottomRow);
	// when
	_Cube->turnBackSliceClockwise(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(leftFace, newLeftFaceLeftColumn);
	cr_assert_arr_eq(
		newLeftFaceLeftColumn,
		oldBottomFaceBottomRow,
		FACE_SIZE,
		"bottom face bottom row wasn't moved to the left face left column");
}


Test(Cube, turnBackSliceClockwise_leftColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(leftFace, oldLeftFaceLeftColumn);
	// when
	_Cube->turnBackSliceClockwise(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceTopRow[FACE_SIZE];
	_Face->topRow(topFace, newTopFaceTopRow);
	cr_assert_arr_eq(
		newTopFaceTopRow,
		oldLeftFaceLeftColumn,
		FACE_SIZE,
		"left face left column wasn't moved to the top face top row");
}


Test(Cube, turnBackSliceAnticlockwise_topRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceTopRow[FACE_SIZE];
	_Face->topRow(topFace, oldTopFaceTopRow);
	// when
	_Cube->turnBackSliceAnticlockwise(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(leftFace, newLeftFaceLeftColumn);
	cr_assert_arr_eq(
		newLeftFaceLeftColumn,
		oldTopFaceTopRow,
		FACE_SIZE,
		"top face top row wasn't moved to the left face left column");
}


Test(Cube, turnBackSliceAnticlockwise_leftColumnGoesBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceLeftColumn[FACE_SIZE];
	_Face->leftColumn(leftFace, oldLeftFaceLeftColumn);
	// when
	_Cube->turnBackSliceAnticlockwise(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(bottomFace, newBottomFaceBottomRow);
	cr_assert_arr_eq(
		newBottomFaceBottomRow,
		oldLeftFaceLeftColumn,
		FACE_SIZE,
		"left face left column wasn't moved to the bottom face bottom row");
}


Test(Cube, turnBackSliceAnticlockwise_bottomRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(bottomFace, oldBottomFaceBottomRow);
	// when
	_Cube->turnBackSliceAnticlockwise(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceRightColumn[FACE_SIZE];
	_Face->rightColumn(rightFace, newRightFaceRightColumn);
	cr_assert_arr_eq(
		newRightFaceRightColumn,
		oldBottomFaceBottomRow,
		FACE_SIZE,
		"bottom face bottom row wasn't moved to the right face right column");
}


Test(Cube, turnBackSliceAnticlockwise_rightColumnGoesTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceRightColumn[FACE_SIZE];
	_Face->rightColumn(rightFace, oldRightFaceRightColumn);
	// when
	_Cube->turnBackSliceAnticlockwise(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceTopRow[FACE_SIZE];
	_Face->topRow(topFace, newTopFaceTopRow);
	cr_assert_arr_eq(
		newTopFaceTopRow,
		oldRightFaceRightColumn,
		FACE_SIZE,
		"right face right column wasn't moved to the top face top row");
}


Test(Cube, turnTopSliceLeft_topFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->topFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnTopSliceLeft(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->topFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[2 - columnIndex][rowIndex],
				"top face was not rotated clockwise");
		}
	}
}


Test(Cube, turnTopSliceRight_topFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->topFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnTopSliceRight(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->topFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[columnIndex][2 - rowIndex],
				"top face was not rotated anticlockwise");
		}
	}
}


Test(Cube, turnBottomSliceLeft_bottomFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->bottomFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnBottomSliceLeft(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->bottomFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[columnIndex][2 - rowIndex],
				"bottom face was not rotated anticlockwise");
		}
	}
}


Test(Cube, turnBottomSliceRight_bottomFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->bottomFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnBottomSliceRight(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->bottomFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[2 - columnIndex][rowIndex],
				"bottom face was not rotated clockwise");
		}
	}
}


Test(Cube, turnLeftSliceUp_leftFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->leftFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnLeftSliceUp(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->leftFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[columnIndex][2 - rowIndex],
				"left face was not rotated anticlockwise");
		}
	}
}


Test(Cube, turnLeftSliceDown_leftFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->leftFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnLeftSliceDown(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->leftFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[2 - columnIndex][rowIndex],
				"left face was not rotated clockwise");
		}
	}
}


Test(Cube, turnRightSliceUp_rightFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->rightFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnRightSliceUp(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->rightFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[2 - columnIndex][rowIndex],
				"right face was not rotated clockwise");
		}
	}
}


Test(Cube, turnRightSliceDown_rightFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->rightFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnRightSliceDown(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->rightFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[columnIndex][2 - rowIndex],
				"right face was not rotated anticlockwise");
		}
	}
}


Test(Cube, turnFrontSliceClockwise_frontFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->frontFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnFrontSliceClockwise(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->frontFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[2 - columnIndex][rowIndex],
				"front face was not rotated clockwise");
		}
	}
}


Test(Cube, turnFrontSliceAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->frontFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnFrontSliceAnticlockwise(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->frontFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[columnIndex][2 - rowIndex],
				"front face was not rotated anticlockwise");
		}
	}
}


Test(Cube, turnBackSliceClockwise_backFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->backFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnBackSliceClockwise(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->backFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[columnIndex][2 - rowIndex],
				"back face was not rotated anticlockwise");
		}
	}
}


Test(Cube, turnBackSliceAnticlockwise_backFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->backFace(cube), cellsBeforeRotation);

	// when
	_Cube->turnBackSliceAnticlockwise(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(_Cube->backFace(cube), cellsAfterRotation);
	for (rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				cellsAfterRotation[rowIndex][columnIndex],
				cellsBeforeRotation[2 - columnIndex][rowIndex],
				"back face was not rotated clockwise");
		}
	}
}


Test(Cube, rotateCubeLeft_leftFaceIsRotatedTwice)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = _Cube->leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	_Cube->rotateLeft(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceBeforeRotation[FACE_SIZE - 1 - rowIndex][FACE_SIZE - 1 - columnIndex],
				faceAfterRotation[rowIndex][columnIndex]);
		}
	}
}



Test(Cube, rotateCubeLeft_bottomFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceBeforeRotation);

	// when
	_Cube->rotateLeft(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[FACE_SIZE - 1 - columnIndex][rowIndex]);
		}
	}
}


Test(Cube, rotateCubeLeft_backFaceIsRotatedTwice)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = _Cube->backFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceBeforeRotation);

	// when
	_Cube->rotateLeft(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceBeforeRotation[FACE_SIZE - 1 - rowIndex][FACE_SIZE - 1 - columnIndex],
				faceAfterRotation[rowIndex][columnIndex]);
		}
	}
}


Test(Cube, rotateCubeLeft_topFaceIsRotatedAntiClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = _Cube->topFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceBeforeRotation);

	// when
	_Cube->rotateLeft(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[columnIndex][FACE_SIZE - 1 - rowIndex]);
		}
	}
}


Test(Cube, rotateCubeRight_rightFaceIsRotatedTwice)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = _Cube->rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	_Cube->rotateRight(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceBeforeRotation[FACE_SIZE - 1 - rowIndex][FACE_SIZE - 1 - columnIndex],
				faceAfterRotation[rowIndex][columnIndex]);
		}
	}
}


Test(Cube, rotateCubeRight_bottomFaceIsRotatedAntiClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceBeforeRotation);

	// when
	_Cube->rotateRight(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[columnIndex][FACE_SIZE - 1 - rowIndex]);
		}
	}
}


Test(Cube, rotateCubeRight_backFaceIsRotatedTwice)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = _Cube->backFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceBeforeRotation);

	// when
	_Cube->rotateRight(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceBeforeRotation[FACE_SIZE - 1 - rowIndex][FACE_SIZE - 1 - columnIndex],
				faceAfterRotation[rowIndex][columnIndex]);
		}
	}
}


Test(Cube, rotateCubeRight_topFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = _Cube->topFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceBeforeRotation);

	// when
	_Cube->rotateRight(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[FACE_SIZE - 1 - columnIndex][rowIndex]);
		}
	}
}


Test(Cube, rotateCubeUp_leftFaceIsRotatedAntiClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = _Cube->leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	_Cube->rotateUp(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[columnIndex][FACE_SIZE - 1 - rowIndex]);
		}
	}
}


Test(Cube, rotateCubeUp_rightFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = _Cube->rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	_Cube->rotateUp(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[FACE_SIZE - 1 - columnIndex][rowIndex]);
		}
	}
}


Test(Cube, rotateCubeDown_leftFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = _Cube->leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	_Cube->rotateDown(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[FACE_SIZE - 1 - columnIndex][rowIndex]);
		}
	}
}
Test(Cube, rotateCubeDown_rightFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = _Cube->rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	_Cube->rotateDown(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[columnIndex][FACE_SIZE - 1 - rowIndex]);
		}
	}
}


Test(Cube, rotateCubeClockwise_leftFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = _Cube->leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	_Cube->rotateClockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[FACE_SIZE - 1 - columnIndex][rowIndex]);
		}
	}
}


Test(Cube, rotateCubeClockwise_frontFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = _Cube->frontFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, faceBeforeRotation);

	// when
	_Cube->rotateClockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[FACE_SIZE - 1 - columnIndex][rowIndex]);
		}
	}
}


Test(Cube, rotateCubeClockwise_rightFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = _Cube->rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	_Cube->rotateClockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[FACE_SIZE - 1 - columnIndex][rowIndex]);
		}
	}
}


Test(Cube, rotateCubeClockwise_bottomFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceBeforeRotation);

	// when
	_Cube->rotateClockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[FACE_SIZE - 1 - columnIndex][rowIndex]);
		}
	}
}


Test(Cube, rotateCubeClockwise_backFaceIsRotatedAntiClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = _Cube->backFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceBeforeRotation);

	// when
	_Cube->rotateClockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[columnIndex][FACE_SIZE - 1 - rowIndex]);
		}
	}
}


Test(Cube, rotateCubeClockwise_topFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = _Cube->topFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceBeforeRotation);

	// when
	_Cube->rotateClockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[FACE_SIZE - 1 - columnIndex][rowIndex]);
		}
	}
}


Test(Cube, rotateCubeAnticlockwise_leftFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = _Cube->leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	_Cube->rotateAnticlockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[columnIndex][FACE_SIZE - 1 - rowIndex]);
		}
	}
}


Test(Cube, rotateCubeAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = _Cube->frontFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, faceBeforeRotation);

	// when
	_Cube->rotateAnticlockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[columnIndex][FACE_SIZE - 1 - rowIndex]);
		}
	}
}


Test(Cube, rotateCubeAnticlockwise_rightFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = _Cube->rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	_Cube->rotateAnticlockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[columnIndex][FACE_SIZE - 1 - rowIndex]);
		}
	}
}


Test(Cube, rotateCubeAnticlockwise_bottomFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceBeforeRotation);

	// when
	_Cube->rotateAnticlockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[columnIndex][FACE_SIZE - 1 - rowIndex]);
		}
	}
}


Test(Cube, rotateCubeAnticlockwise_backFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * backFace = _Cube->backFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceBeforeRotation);

	// when
	_Cube->rotateAnticlockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[FACE_SIZE - 1 - columnIndex][rowIndex]);
		}
	}
}


Test(Cube, rotateCubeAnticlockwise_topFaceIsRotatedAntiClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = _Cube->topFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceBeforeRotation);

	// when
	_Cube->rotateAnticlockwise(cube);

	// then
	Color faceAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceAfterRotation);
	for (int rowIndex = 0; rowIndex < FACE_SIZE; rowIndex++)
	{
		for (int columnIndex = 0; columnIndex < FACE_SIZE; columnIndex++)
		{
			cr_assert_eq(
				faceAfterRotation[rowIndex][columnIndex],
				faceBeforeRotation[columnIndex][FACE_SIZE - 1 - rowIndex]);
		}
	}
}




static Cube * createScrambledCube(void)
{
	Cube * cube = _Cube->create();

	int rotationsLeft = 7;
	while (rotationsLeft--)
	{
		_Cube->turnTopSliceLeft(cube);
		_Cube->turnLeftSliceUp(cube);
		_Cube->turnFrontSliceClockwise(cube);

		_Cube->turnBottomSliceRight(cube);
		_Cube->turnRightSliceDown(cube);
		_Cube->turnBackSliceAnticlockwise(cube);
	}

	return cube;
}


static void readFace(Face const * face, Color storage[FACE_SIZE][FACE_SIZE])
{
	size_t rowSizeInBytes = FACE_SIZE * sizeof(storage[0][0]);
	Color buffer[FACE_SIZE];

	_Face->topRow(face, buffer);
	memcpy(storage[0], buffer, rowSizeInBytes);

	_Face->equatorRow(face, buffer);
	memcpy(storage[1], buffer, rowSizeInBytes);

	_Face->bottomRow(face, buffer);
	memcpy(storage[2], buffer, rowSizeInBytes);
}
