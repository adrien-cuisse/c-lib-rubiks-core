
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


Test(Cube, rotateLeft_rightFaceComesOnTheFront)
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


Test(Cube, rotateLeft_backFaceComesOnTheRight)
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


Test(Cube, rotateLeft_leftFaceComesOnTheBack)
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


Test(Cube, rotateLeft_frontFaceComesOnTheLeft)
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


Test(Cube, rotateRight_frontFaceComesOnTheRight)
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


Test(Cube, rotateRight_rightFaceComesOnTheBack)
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


Test(Cube, rotateRight_backFaceComesOnTheLeft)
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


Test(Cube, rotateRight_leftFaceComesOnTheFront)
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


Test(Cube, rotateUp_frontFaceComesOnTheTop)
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


Test(Cube, rotateUp_topFaceComesOnTheBack)
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


Test(Cube, rotateUp_backFaceComesOnTheBottom)
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


Test(Cube, rotateUp_bottomFaceComesOnTheFront)
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


Test(Cube, rotateDown_frontFaceComesOnTheBottom)
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


Test(Cube, rotateDown_bottomFaceComesOnTheBack)
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


Test(Cube, rotateDown_backFaceComesOnTheTop)
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


Test(Cube, rotateDown_topFaceComesOnTheFront)
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


Test(Cube, rotateClockwise_topFaceComesOnTheRight)
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


Test(Cube, rotateClockwise_rightFaceComesOnTheBottom)
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


Test(Cube, rotateClockwise_bottomFaceComesOnTheLeft)
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


Test(Cube, rotateClockwise_leftFaceComesOnTheTop)
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


Test(Cube, rotateAnticlockwise_topFaceComesOnTheLeft)
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


Test(Cube, rotateAnticlockwise_leftFaceComesOnTheBottom)
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


Test(Cube, rotateAnticlockwise_bottomFaceComesOnTheRight)
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


Test(Cube, rotateAnticlockwise_rightFaceComesOnTheTop)
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


Test(Cube, turnTopSliceLeft_frontSliceComesToTheLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceTopSlice[FACE_SIZE];
	_Face->topSlice(frontFace, oldFrontFaceTopSlice);
	// when
	_Cube->turnTopSliceLeft(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceTopSlice[FACE_SIZE];
	_Face->topSlice(leftFace, newLeftFaceTopSlice);
	cr_assert_arr_eq(
		newLeftFaceTopSlice,
		oldFrontFaceTopSlice,
		FACE_SIZE,
		"front face top slice wasn't moved to the left face");
}


Test(Cube, turnTopSliceLeft_leftSliceComesToTheBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceTopSlice[FACE_SIZE];
	_Face->topSlice(leftFace, oldLeftFaceTopSlice);
	// when
	_Cube->turnTopSliceLeft(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceTopSlice[FACE_SIZE];
	_Face->topSlice(backFace, newBackFaceTopSlice);
	cr_assert_arr_eq(
		newBackFaceTopSlice,
		oldLeftFaceTopSlice,
		FACE_SIZE,
		"left face top slice wasn't moved to the back face");
}


Test(Cube, turnTopSliceLeft_backSliceComesToTheRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceTopSlice[FACE_SIZE];
	_Face->topSlice(backFace, oldBackFaceTopSlice);
	// when
	_Cube->turnTopSliceLeft(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceTopSlice[FACE_SIZE];
	_Face->topSlice(rightFace, newRightFaceTopSlice);
	cr_assert_arr_eq(
		newRightFaceTopSlice,
		oldBackFaceTopSlice,
		FACE_SIZE,
		"back face top slice wasn't moved to the right face");
}


Test(Cube, turnTopSliceLeft_rightSliceComesToTheFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceTopSlice[FACE_SIZE];
	_Face->topSlice(rightFace, oldRightFaceTopSlice);
	// when
	_Cube->turnTopSliceLeft(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceTopSlice[FACE_SIZE];
	_Face->topSlice(frontFace, newFrontFaceTopSlice);
	cr_assert_arr_eq(
		newFrontFaceTopSlice,
		oldRightFaceTopSlice,
		FACE_SIZE,
		"right face top slice wasn't moved to the front face");
}


Test(Cube, turnTopSliceRight_frontSliceComesToTheRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceTopSlice[FACE_SIZE];
	_Face->topSlice(frontFace, oldFrontFaceTopSlice);
	// when
	_Cube->turnTopSliceRight(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceTopSlice[FACE_SIZE];
	_Face->topSlice(rightFace, newRightFaceTopSlice);
	cr_assert_arr_eq(
		newRightFaceTopSlice,
		oldFrontFaceTopSlice,
		FACE_SIZE,
		"front face top slice wasn't moved to the right face");
}


Test(Cube, turnTopSliceRight_rightSliceComesToTheBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceTopSlice[FACE_SIZE];
	_Face->topSlice(rightFace, oldRightFaceTopSlice);
	// when
	_Cube->turnTopSliceRight(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceTopSlice[FACE_SIZE];
	_Face->topSlice(backFace, newBackFaceTopSlice);
	cr_assert_arr_eq(
		newBackFaceTopSlice,
		oldRightFaceTopSlice,
		FACE_SIZE,
		"right face top slice wasn't moved to the back face");
}


Test(Cube, turnTopSliceRight_backSliceComesToTheLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceTopSlice[FACE_SIZE];
	_Face->topSlice(backFace, oldBackFaceTopSlice);
	// when
	_Cube->turnTopSliceRight(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceTopSlice[FACE_SIZE];
	_Face->topSlice(leftFace, newLeftFaceTopSlice);
	cr_assert_arr_eq(
		newLeftFaceTopSlice,
		oldBackFaceTopSlice,
		FACE_SIZE,
		"back face top slice wasn't moved to the left face");
}


Test(Cube, turnTopSliceRight_leftSliceComesToTheFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceTopSlice[FACE_SIZE];
	_Face->topSlice(leftFace, oldLeftFaceTopSlice);
	// when
	_Cube->turnTopSliceRight(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceTopSlice[FACE_SIZE];
	_Face->topSlice(frontFace, newFrontFaceTopSlice);
	cr_assert_arr_eq(
		newFrontFaceTopSlice,
		oldLeftFaceTopSlice,
		FACE_SIZE,
		"left face top slice wasn't moved to the front face");
}


Test(Cube, turnMiddleSliceLeft_frontSliceComesToTheLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(frontFace, oldFrontFaceMiddleSlice);
	// when
	_Cube->turnMiddleSliceLeft(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(leftFace, newLeftFaceMiddleSlice);
	cr_assert_arr_eq(
		newLeftFaceMiddleSlice,
		oldFrontFaceMiddleSlice,
		FACE_SIZE,
		"front face middle slice wasn't moved to the left face");
}


Test(Cube, turnMiddleSliceLeft_leftSliceComesToTheBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(leftFace, oldLeftFaceMiddleSlice);
	// when
	_Cube->turnMiddleSliceLeft(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(backFace, newBackFaceMiddleSlice);
	cr_assert_arr_eq(
		newBackFaceMiddleSlice,
		oldLeftFaceMiddleSlice,
		FACE_SIZE,
		"left face middle slice wasn't moved to the back face");
}


Test(Cube, turnMiddleSliceLeft_backSliceComesToTheRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(backFace, oldBackFaceMiddleSlice);
	// when
	_Cube->turnMiddleSliceLeft(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(rightFace, newRightFaceMiddleSlice);
	cr_assert_arr_eq(
		newRightFaceMiddleSlice,
		oldBackFaceMiddleSlice,
		FACE_SIZE,
		"back face middle slice wasn't moved to the right face");
}


Test(Cube, turnMiddleSliceLeft_rightSliceComesToTheFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(rightFace, oldRightFaceMiddleSlice);
	// when
	_Cube->turnMiddleSliceLeft(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(frontFace, newFrontFaceMiddleSlice);
	cr_assert_arr_eq(
		newFrontFaceMiddleSlice,
		oldRightFaceMiddleSlice,
		FACE_SIZE,
		"right face middle slice wasn't moved to the front face");
}


Test(Cube, turnMiddleSliceRight_frontSliceComesToTheRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(frontFace, oldFrontFaceMiddleSlice);
	// when
	_Cube->turnMiddleSliceRight(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(rightFace, newRightFaceMiddleSlice);
	cr_assert_arr_eq(
		newRightFaceMiddleSlice,
		oldFrontFaceMiddleSlice,
		FACE_SIZE,
		"front face middle slice wasn't moved to the right face");
}


Test(Cube, turnMiddleSliceRight_rightSliceComesToTheBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(rightFace, oldRightFaceMiddleSlice);
	// when
	_Cube->turnMiddleSliceRight(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(backFace, newBackFaceMiddleSlice);
	cr_assert_arr_eq(
		newBackFaceMiddleSlice,
		oldRightFaceMiddleSlice,
		FACE_SIZE,
		"right face middle slice wasn't moved to the back face");
}


Test(Cube, turnMiddleSliceRight_backSliceComesToTheLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(backFace, oldBackFaceMiddleSlice);
	// when
	_Cube->turnMiddleSliceRight(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(leftFace, newLeftFaceMiddleSlice);
	cr_assert_arr_eq(
		newLeftFaceMiddleSlice,
		oldBackFaceMiddleSlice,
		FACE_SIZE,
		"back face middle slice wasn't moved to the left face");
}


Test(Cube, turnMiddleSliceRight_leftSliceComesToTheFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(leftFace, oldLeftFaceMiddleSlice);
	// when
	_Cube->turnMiddleSliceRight(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceMiddleSlice[FACE_SIZE];
	_Face->middleSlice(frontFace, newFrontFaceMiddleSlice);
	cr_assert_arr_eq(
		newFrontFaceMiddleSlice,
		oldLeftFaceMiddleSlice,
		FACE_SIZE,
		"left face middle slice wasn't moved to the front face");
}


Test(Cube, turnBottomSliceLeft_frontSliceComesToTheleft)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(frontFace, oldFrontFaceBottomSlice);
	// when
	_Cube->turnBottomSliceLeft(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(leftFace, newLeftFaceBottomSlice);
	cr_assert_arr_eq(
		newLeftFaceBottomSlice,
		oldFrontFaceBottomSlice,
		FACE_SIZE,
		"front face bottom slice wasn't moved to the left face");
}


Test(Cube, turnBottomSliceLeft_leftSliceComesToTheBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(leftFace, oldLeftFaceBottomSlice);
	// when
	_Cube->turnBottomSliceLeft(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(backFace, newBackFaceBottomSlice);
	cr_assert_arr_eq(
		newBackFaceBottomSlice,
		oldLeftFaceBottomSlice,
		FACE_SIZE,
		"left face bottom slice wasn't moved to the back face");
}


Test(Cube, turnBottomSliceLeft_backSliceComesToTheRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(backFace, oldBackFaceBottomSlice);
	// when
	_Cube->turnBottomSliceLeft(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(rightFace, newRightFaceBottomSlice);
	cr_assert_arr_eq(
		newRightFaceBottomSlice,
		oldBackFaceBottomSlice,
		FACE_SIZE,
		"back face bottom slice wasn't moved to the right face");
}


Test(Cube, turnBottomSliceLeft_rightSliceComesToTheFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(rightFace, oldRightFaceBottomSlice);
	// when
	_Cube->turnBottomSliceLeft(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(frontFace, newFrontFaceBottomSlice);
	cr_assert_arr_eq(
		newFrontFaceBottomSlice,
		oldRightFaceBottomSlice,
		FACE_SIZE,
		"right face bottom slice wasn't moved to the front face");
}


Test(Cube, turnBottomSliceRight_frontSliceComesToTheRight)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(frontFace, oldFrontFaceBottomSlice);
	// when
	_Cube->turnBottomSliceRight(cube);
	// then
	Face * rightFace = _Cube->rightFace(cube);
	Color newRightFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(rightFace, newRightFaceBottomSlice);
	cr_assert_arr_eq(
		newRightFaceBottomSlice,
		oldFrontFaceBottomSlice,
		FACE_SIZE,
		"front face bottom slice wasn't moved to the right face");
}


Test(Cube, turnBottomSliceRight_rightSliceComesToTheBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * rightFace = _Cube->rightFace(cube);
	Color oldRightFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(rightFace, oldRightFaceBottomSlice);
	// when
	_Cube->turnBottomSliceRight(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(backFace, newBackFaceBottomSlice);
	cr_assert_arr_eq(
		newBackFaceBottomSlice,
		oldRightFaceBottomSlice,
		FACE_SIZE,
		"right face bottom slice wasn't moved to the back face");
}


Test(Cube, turnBottomSliceRight_backSliceComesToTheLeft)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(backFace, oldBackFaceBottomSlice);
	// when
	_Cube->turnBottomSliceRight(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color newLeftFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(leftFace, newLeftFaceBottomSlice);
	cr_assert_arr_eq(
		newLeftFaceBottomSlice,
		oldBackFaceBottomSlice,
		FACE_SIZE,
		"back face bottom slice wasn't moved to the left face");
}


Test(Cube, turnBottomSliceRight_leftSliceComesToTheFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color oldLeftFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(leftFace, oldLeftFaceBottomSlice);
	// when
	_Cube->turnBottomSliceRight(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceBottomSlice[FACE_SIZE];
	_Face->bottomSlice(frontFace, newFrontFaceBottomSlice);
	cr_assert_arr_eq(
		newFrontFaceBottomSlice,
		oldLeftFaceBottomSlice,
		FACE_SIZE,
		"left face bottom slice wasn't moved to the front face");
}


Test(Cube, turnLeftSliceUp_frontSliceComesToTheTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(frontFace, oldFrontFaceLeftSlice);
	// when
	_Cube->turnLeftSliceUp(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(topFace, newTopFaceLeftSlice);
	cr_assert_arr_eq(
		newTopFaceLeftSlice,
		oldFrontFaceLeftSlice,
		FACE_SIZE,
		"front face left slice wasn't moved to the top face");
}


Test(Cube, turnLeftSliceUp_topSliceComesToTheBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(topFace, oldTopFaceLeftSlice);
	// when
	_Cube->turnLeftSliceUp(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(backFace, newBackFaceLeftSlice);
	cr_assert_arr_eq(
		newBackFaceLeftSlice,
		oldTopFaceLeftSlice,
		FACE_SIZE,
		"top face left slice wasn't moved to the back face");
}


Test(Cube, turnLeftSliceUp_backSliceComesToTheBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(backFace, oldBackFaceLeftSlice);
	// when
	_Cube->turnLeftSliceUp(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(bottomFace, newBottomFaceLeftSlice);
	cr_assert_arr_eq(
		newBottomFaceLeftSlice,
		oldBackFaceLeftSlice,
		FACE_SIZE,
		"back face left slice wasn't moved to the bottom face");
}


Test(Cube, turnLeftSliceUp_bottomSliceComesToTheFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(bottomFace, oldBottomFaceLeftSlice);
	// when
	_Cube->turnLeftSliceUp(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(frontFace, newFrontFaceLeftSlice);
	cr_assert_arr_eq(
		newFrontFaceLeftSlice,
		oldBottomFaceLeftSlice,
		FACE_SIZE,
		"bottom face left slice wasn't moved to the front face");
}


Test(Cube, turnLeftSliceDown_frontSliceComesToTheBottom)
{
	// given
	Cube * cube = _Cube->create();
	Face * frontFace = _Cube->frontFace(cube);
	Color oldFrontFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(frontFace, oldFrontFaceLeftSlice);
	// when
	_Cube->turnLeftSliceDown(cube);
	// then
	Face * bottomFace = _Cube->bottomFace(cube);
	Color newBottomFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(bottomFace, newBottomFaceLeftSlice);
	cr_assert_arr_eq(
		newBottomFaceLeftSlice,
		oldFrontFaceLeftSlice,
		FACE_SIZE,
		"front face left slice wasn't moved to the bottom face");
}


Test(Cube, turnLeftSliceDown_bottomSliceComesToTheBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * bottomFace = _Cube->bottomFace(cube);
	Color oldBottomFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(bottomFace, oldBottomFaceLeftSlice);
	// when
	_Cube->turnLeftSliceDown(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color newBackFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(backFace, newBackFaceLeftSlice);
	cr_assert_arr_eq(
		newBackFaceLeftSlice,
		oldBottomFaceLeftSlice,
		FACE_SIZE,
		"bottom face left slice wasn't moved to the back face");
}


Test(Cube, turnLeftSliceDown_backSliceComesToTheTop)
{
	// given
	Cube * cube = _Cube->create();
	Face * backFace = _Cube->backFace(cube);
	Color oldBackFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(backFace, oldBackFaceLeftSlice);
	// when
	_Cube->turnLeftSliceDown(cube);
	// then
	Face * topFace = _Cube->topFace(cube);
	Color newTopFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(topFace, newTopFaceLeftSlice);
	cr_assert_arr_eq(
		newTopFaceLeftSlice,
		oldBackFaceLeftSlice,
		FACE_SIZE,
		"back face left slice wasn't moved to the top face");
}


Test(Cube, turnLeftSliceDown_topSliceComesToTheFront)
{
	// given
	Cube * cube = _Cube->create();
	Face * topFace = _Cube->topFace(cube);
	Color oldTopFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(topFace, oldTopFaceLeftSlice);
	// when
	_Cube->turnLeftSliceDown(cube);
	// then
	Face * frontFace = _Cube->frontFace(cube);
	Color newFrontFaceLeftSlice[FACE_SIZE];
	_Face->leftSlice(frontFace, newFrontFaceLeftSlice);
	cr_assert_arr_eq(
		newFrontFaceLeftSlice,
		oldTopFaceLeftSlice,
		FACE_SIZE,
		"top face left slice wasn't moved to the front face");
}
