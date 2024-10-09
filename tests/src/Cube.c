
#include <criterion/criterion.h>

#include "../../src/Cube.h"




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
		"front face top row wasn't moved to the left face");
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
	Color newBackFaceTopRow[FACE_SIZE];
	_Face->topRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		newBackFaceTopRow,
		oldLeftFaceTopRow,
		FACE_SIZE,
		"left face top row wasn't moved to the back face");
}


Test(Cube, turnTopSliceLeft_backRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	_Face->topRow(backFace, oldBackFaceTopRow);
	// when
	_Cube->turnTopSliceLeft(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceTopRow[FACE_SIZE];
	_Face->topRow(rightFace, newRightFaceTopRow);
	cr_assert_arr_eq(
		newRightFaceTopRow,
		oldBackFaceTopRow,
		FACE_SIZE,
		"back face top row wasn't moved to the right face");
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
		"right face top row wasn't moved to the front face");
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
		"front face top row wasn't moved to the right face");
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
	Color newBackFaceTopRow[FACE_SIZE];
	_Face->topRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		newBackFaceTopRow,
		oldRightFaceTopRow,
		FACE_SIZE,
		"right face top row wasn't moved to the back face");
}


Test(Cube, turnTopSliceRight_backRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	_Face->topRow(backFace, oldBackFaceTopRow);
	// when
	_Cube->turnTopSliceRight(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	_Face->topRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		newLeftFaceTopRow,
		oldBackFaceTopRow,
		FACE_SIZE,
		"back face top row wasn't moved to the left face");
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
		"left face top row wasn't moved to the front face");
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
		"front face equator row wasn't moved to the left face");
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
		"left face equator row wasn't moved to the back face");
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
		"back face equator row wasn't moved to the right face");
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
		"right face equator row wasn't moved to the front face");
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
		"front face equator row wasn't moved to the right face");
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
		"right face equator row wasn't moved to the back face");
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
		"back face equator row wasn't moved to the left face");
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
		"left face equator row wasn't moved to the front face");
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
		"front face bottom row wasn't moved to the left face");
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
	Color newBackFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		newBackFaceBottomRow,
		oldLeftFaceBottomRow,
		FACE_SIZE,
		"left face bottom row wasn't moved to the back face");
}


Test(Cube, turnBottomSliceLeft_backRowGoesRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(backFace, oldBackFaceBottomRow);
	// when
	_Cube->turnBottomSliceLeft(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(rightFace, newRightFaceBottomRow);
	cr_assert_arr_eq(
		newRightFaceBottomRow,
		oldBackFaceBottomRow,
		FACE_SIZE,
		"back face bottom row wasn't moved to the right face");
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
		"right face bottom row wasn't moved to the front face");
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
		"front face bottom row wasn't moved to the right face");
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
	Color newBackFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		newBackFaceBottomRow,
		oldRightFaceBottomRow,
		FACE_SIZE,
		"right face bottom row wasn't moved to the back face");
}


Test(Cube, turnBottomSliceRight_backRowGoesLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(backFace, oldBackFaceBottomRow);
	// when
	_Cube->turnBottomSliceRight(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceBottomRow[FACE_SIZE];
	_Face->bottomRow(leftFace, newLeftFaceBottomRow);
	cr_assert_arr_eq(
		newLeftFaceBottomRow,
		oldBackFaceBottomRow,
		FACE_SIZE,
		"back face bottom row wasn't moved to the left face");
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
		"left face bottom row wasn't moved to the front face");
}


Test(Cube, turnLeftSliceUp_frontRowGoesTop)
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
		"front face left column wasn't moved to the top face");
}


Test(Cube, turnLeftSliceUp_topRowGoesBack)
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
		"top face left column wasn't moved to the back face");
}


Test(Cube, turnLeftSliceUp_backRowGoesBottom)
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
		"back face left column wasn't moved to the bottom face");
}


Test(Cube, turnLeftSliceUp_bottomRowGoesFront)
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
		"bottom face left column wasn't moved to the front face");
}


Test(Cube, turnLeftSliceDown_frontRowGoesBottom)
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
		"front face left column wasn't moved to the bottom face");
}


Test(Cube, turnLeftSliceDown_bottomRowGoesBack)
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
		"bottom face left column wasn't moved to the back face");
}


Test(Cube, turnLeftSliceDown_backRowGoesTop)
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
		"back face left column wasn't moved to the top face");
}


Test(Cube, turnLeftSliceDown_topRowGoesFront)
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
		"top face left column wasn't moved to the front face");
}


Test(Cube, turnMiddleSliceUp_frontRowGoesTop)
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
		"front face middle column wasn't moved to the top face");
}


Test(Cube, turnMiddleSliceUp_topRowGoesBack)
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
		"top face middle column wasn't moved to the back face");
}


Test(Cube, turnMiddleSliceUp_backRowGoesBottom)
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
		"back face middle column wasn't moved to the bottom face");
}


Test(Cube, turnMiddleSliceUp_bottomRowGoesFront)
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
		"bottom face middle column wasn't moved to the bottom front");
}
