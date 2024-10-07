
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
	Color * oldFrontFaceTopSlice = _Face->topSlice(frontFace);
	// when
	_Cube->turnTopSliceLeft(cube);
	// then
	Face * leftFace = _Cube->leftFace(cube);
	Color * newLeftFaceTopSlice = _Face->topSlice(leftFace);
	cr_assert_arr_eq(
		newLeftFaceTopSlice,
		oldFrontFaceTopSlice,
		3,
		"top slice wasn't moved to the left");
}


Test(Cube, turnTopSliceLeft_leftSliceComesToTheBack)
{
	// given
	Cube * cube = _Cube->create();
	Face * leftFace = _Cube->leftFace(cube);
	Color * oldLeftFaceTopSlice = _Face->topSlice(leftFace);
	// when
	_Cube->turnTopSliceLeft(cube);
	// then
	Face * backFace = _Cube->backFace(cube);
	Color * newBackFaceTopSlice = _Face->topSlice(backFace);
	cr_assert_arr_eq(
		newBackFaceTopSlice,
		oldLeftFaceTopSlice,
		3,
		"WIP: top slice wasn't moved to the left");
}
