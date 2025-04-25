
#include <criterion/criterion.h>

#include "../../include/Cube.h"





static Cube * createScrambledCube(void);


static void readFaceTopRow(Face const * face, Color buffer[FACE_SIZE]);


static void readFaceEquatorRow(Face const * face, Color buffer[FACE_SIZE]);


static void readFaceBottomRow(Face const * face, Color buffer[FACE_SIZE]);


static void readFaceLeftColumn(Face const * face, Color buffer[FACE_SIZE]);


static void readFaceMiddleColumn(Face const * face, Color buffer[FACE_SIZE]);


static void readFaceRightColumn(Face const * face, Color buffer[FACE_SIZE]);


static void readFace(Face const * face, Color storage[FACE_SIZE][FACE_SIZE]);




Test(Cube, create_allocatesMemory)
{
	// given
	Cube * allocatedMemory = Cube_create();
	// when
	// then
	cr_assert_not_null(allocatedMemory, "no memory was allocated");
}


Test(Cube, delete_deallocatesMemory)
{
	// given
	Cube * allocatedMemory = Cube_create();
	// when
	Cube_delete(& allocatedMemory);
	// then
	cr_assert_null(allocatedMemory, "memory was not deallocated");
}


Test(Cube, isInitializedWithBlueFaceInFront)
{
	// given
	Cube * cube = Cube_create();
	// when
	Face * frontFace = Cube_frontFace(cube);
	// then
	Color frontFaceColor = Face_color(frontFace);
	cr_assert_eq(frontFaceColor, BLUE, "front face is not blue");
}


Test(Cube, isInitializedWithRedFaceOnTheLeft)
{
	// given
	Cube * cube = Cube_create();
	// when
	Face * leftFace = Cube_leftFace(cube);
	// then
	Color leftFaceColor = Face_color(leftFace);
	cr_assert_eq(leftFaceColor, RED, "left face is not red");
}


Test(Cube, isInitializedWithOrangeFaceOnTheRight)
{
	// given
	Cube * cube = Cube_create();
	// when
	Face * rightFace = Cube_rightFace(cube);
	// then
	Color rightFaceColor = Face_color(rightFace);
	cr_assert_eq(rightFaceColor, ORANGE, "right face is not orange");
}


Test(Cube, isInitializedWithWhiteFaceOnTop)
{
	// given
	Cube * cube = Cube_create();
	// when
	Face * topFace = Cube_topFace(cube);
	// then
	Color topFaceColor = Face_color(topFace);
	cr_assert_eq(topFaceColor, WHITE, "top face is not white");
}


Test(Cube, isInitializedWithYellowFaceAtBottom)
{
	// given
	Cube * cube = Cube_create();
	// when
	Face * bottomFace = Cube_bottomFace(cube);
	// then
	Color bottomFaceColor = Face_color(bottomFace);
	cr_assert_eq(bottomFaceColor, YELLOW, "bottom face is not yellow");
}


Test(Cube, isInitializedWithGreenFaceOnTheBack)
{
	// given
	Cube * cube = Cube_create();
	// when
	Face * backFace = Cube_backFace(cube);
	// then
	Color backFaceColor = Face_color(backFace);
	cr_assert_eq(backFaceColor, GREEN, "back face is not green");
}


Test(Cube, rotateLeft_rightFaceGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * oldRightFace = Cube_rightFace(cube);
	// when
	Cube_rotateLeft(cube);
	// then
	Face * newFrontFace = Cube_frontFace(cube);
	cr_assert_eq(newFrontFace, oldRightFace, "right face wasn't moved to the front");
}


Test(Cube, rotateLeft_backFaceGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBackFace = Cube_backFace(cube);
	// when
	Cube_rotateLeft(cube);
	// then
	Face * newRightFace = Cube_rightFace(cube);
	cr_assert_eq(newRightFace, oldBackFace, "back face wasn't moved to the right");
}


Test(Cube, rotateLeft_leftFaceGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * oldLeftFace = Cube_leftFace(cube);
	// when
	Cube_rotateLeft(cube);
	// then
	Face * newBackFace = Cube_backFace(cube);
	cr_assert_eq(newBackFace, oldLeftFace, "left face wasn't moved to the back");
}


Test(Cube, rotateLeft_frontFaceGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * oldFrontFace = Cube_frontFace(cube);
	// when
	Cube_rotateLeft(cube);
	// then
	Face * newLeftFace = Cube_leftFace(cube);
	cr_assert_eq(newLeftFace, oldFrontFace, "front face wasn't moved to the left");
}


Test(Cube, rotateRight_frontFaceGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * oldFrontFace = Cube_frontFace(cube);
	// when
	Cube_rotateRight(cube);
	// then
	Face * newRightFace = Cube_rightFace(cube);
	cr_assert_eq(newRightFace, oldFrontFace, "front face wasn't moved to the right");
}


Test(Cube, rotateRight_rightFaceGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * oldRightFace = Cube_rightFace(cube);
	// when
	Cube_rotateRight(cube);
	// then
	Face * newBackFace = Cube_backFace(cube);
	cr_assert_eq(newBackFace, oldRightFace, "right face wasn't moved to the back");
}


Test(Cube, rotateRight_backFaceGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBackFace = Cube_backFace(cube);
	// when
	Cube_rotateRight(cube);
	// then
	Face * newLeftFace = Cube_leftFace(cube);
	cr_assert_eq(newLeftFace, oldBackFace, "back face wasn't moved to the left");
}


Test(Cube, rotateRight_leftFaceGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * oldLeftFace = Cube_leftFace(cube);
	// when
	Cube_rotateRight(cube);
	// then
	Face * newFrontFace = Cube_frontFace(cube);
	cr_assert_eq(newFrontFace, oldLeftFace, "left face wasn't moved to the front");
}


Test(Cube, rotateUp_frontFaceGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * oldFrontFace = Cube_frontFace(cube);
	// when
	Cube_rotateUp(cube);
	// then
	Face * newTopFace = Cube_topFace(cube);
	cr_assert_eq(newTopFace, oldFrontFace, "front face wasn't moved to the top");
}


Test(Cube, rotateUp_topFaceGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * oldTopFace = Cube_topFace(cube);
	// when
	Cube_rotateUp(cube);
	// then
	Face * newBackFace = Cube_backFace(cube);
	cr_assert_eq(newBackFace, oldTopFace, "top face wasn't moved to the back");
}


Test(Cube, rotateUp_backFaceGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBackFace = Cube_backFace(cube);
	// when
	Cube_rotateUp(cube);
	// then
	Face * newBottomFace = Cube_bottomFace(cube);
	cr_assert_eq(newBottomFace, oldBackFace, "back face wasn't moved to the bottom");
}


Test(Cube, rotateUp_bottomFaceGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBottomFace = Cube_bottomFace(cube);
	// when
	Cube_rotateUp(cube);
	// then
	Face * newFrontFace = Cube_frontFace(cube);
	cr_assert_eq(newFrontFace, oldBottomFace, "bottom face wasn't moved to the front");
}


Test(Cube, rotateDown_frontFaceGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * oldFrontFace = Cube_frontFace(cube);
	// when
	Cube_rotateDown(cube);
	// then
	Face * newBottomFace = Cube_bottomFace(cube);
	cr_assert_eq(newBottomFace, oldFrontFace, "front face wasn't moved to the bottom");
}


Test(Cube, rotateDown_bottomFaceGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBottomFace = Cube_bottomFace(cube);
	// when
	Cube_rotateDown(cube);
	// then
	Face * newBackFace = Cube_backFace(cube);
	cr_assert_eq(newBackFace, oldBottomFace, "bottom face wasn't moved to the back");
}


Test(Cube, rotateDown_backFaceGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBackFace = Cube_backFace(cube);
	// when
	Cube_rotateDown(cube);
	// then
	Face * newTopFace = Cube_topFace(cube);
	cr_assert_eq(newTopFace, oldBackFace, "back face wasn't moved to the top");
}


Test(Cube, rotateDown_topFaceGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * oldTopFace = Cube_topFace(cube);
	// when
	Cube_rotateDown(cube);
	// then
	Face * newFrontFace = Cube_frontFace(cube);
	cr_assert_eq(newFrontFace, oldTopFace, "top face wasn't moved to the front");
}


Test(Cube, rotateClockwise_topFaceGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * oldTopFace = Cube_topFace(cube);
	// when
	Cube_rotateClockwise(cube);
	// then
	Face * newRightFace = Cube_rightFace(cube);
	cr_assert_eq(newRightFace, oldTopFace, "top face wasn't moved to the right");
}


Test(Cube, rotateClockwise_rightFaceGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * oldRightFace = Cube_rightFace(cube);
	// when
	Cube_rotateClockwise(cube);
	// then
	Face * newBottomFace = Cube_bottomFace(cube);
	cr_assert_eq(newBottomFace, oldRightFace, "right face wasn't moved to the bottom");
}


Test(Cube, rotateClockwise_bottomFaceGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBottomFace = Cube_bottomFace(cube);
	// when
	Cube_rotateClockwise(cube);
	// then
	Face * newLeftFace = Cube_leftFace(cube);
	cr_assert_eq(newLeftFace, oldBottomFace, "bottom face wasn't moved to the left");
}


Test(Cube, rotateClockwise_leftFaceGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * oldLeftFace = Cube_leftFace(cube);
	// when
	Cube_rotateClockwise(cube);
	// then
	Face * newTopFace = Cube_topFace(cube);
	cr_assert_eq(newTopFace, oldLeftFace, "left face wasn't moved to the top");
}


Test(Cube, rotateAnticlockwise_topFaceGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * oldTopFace = Cube_topFace(cube);
	// when
	Cube_rotateAnticlockwise(cube);
	// then
	Face * newLeftFace = Cube_leftFace(cube);
	cr_assert_eq(newLeftFace, oldTopFace, "top face wasn't moved to the left");
}


Test(Cube, rotateAnticlockwise_leftFaceGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * oldLeftFace = Cube_leftFace(cube);
	// when
	Cube_rotateAnticlockwise(cube);
	// then
	Face * newBottomFace = Cube_bottomFace(cube);
	cr_assert_eq(newBottomFace, oldLeftFace, "left face wasn't moved to the bottom");
}


Test(Cube, rotateAnticlockwise_bottomFaceGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * oldBottomFace = Cube_bottomFace(cube);
	// when
	Cube_rotateAnticlockwise(cube);
	// then
	Face * newRightFace = Cube_rightFace(cube);
	cr_assert_eq(newRightFace, oldBottomFace, "bottom face wasn't moved to the right");
}


Test(Cube, rotateAnticlockwise_rightFaceGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * oldRightFace = Cube_rightFace(cube);
	// when
	Cube_rotateAnticlockwise(cube);
	// then
	Face * newTopFace = Cube_topFace(cube);
	cr_assert_eq(newTopFace, oldRightFace, "right face wasn't moved to the top");
}


Test(Cube, turnTopSliceLeft_frontRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	readFaceTopRow(frontFace, oldFrontFaceTopRow);
	// when
	Cube_turnTopSliceLeft(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	readFaceTopRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		newLeftFaceTopRow,
		oldFrontFaceTopRow,
		FACE_SIZE,
		"front face top row wasn't moved to the left face top row");
}


Test(Cube, turnTopSliceLeft_leftRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	readFaceTopRow(leftFace, oldLeftFaceTopRow);
	// when
	Cube_turnTopSliceLeft(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		newBackFaceBottomRow,
		oldLeftFaceTopRow,
		FACE_SIZE,
		"left face top row wasn't moved to the back face bottom row");
}


Test(Cube, turnTopSliceLeft_backRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(backFace, oldBackFaceBottomRow);
	// when
	Cube_turnTopSliceLeft(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceTopRow[FACE_SIZE];
	readFaceTopRow(rightFace, newRightFaceTopRow);
	cr_assert_arr_eq(
		newRightFaceTopRow,
		oldBackFaceBottomRow,
		FACE_SIZE,
		"back face bottom row wasn't moved to the right face top row");
}


Test(Cube, turnTopSliceLeft_rightRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	readFaceTopRow(rightFace, oldRightFaceTopRow);
	// when
	Cube_turnTopSliceLeft(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceTopRow[FACE_SIZE];
	readFaceTopRow(frontFace, newFrontFaceTopRow);
	cr_assert_arr_eq(
		newFrontFaceTopRow,
		oldRightFaceTopRow,
		FACE_SIZE,
		"right face top row wasn't moved to the front face top row");
}


Test(Cube, turnTopSliceRight_frontRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	readFaceTopRow(frontFace, oldFrontFaceTopRow);
	// when
	Cube_turnTopSliceRight(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceTopRow[FACE_SIZE];
	readFaceTopRow(rightFace, newRightFaceTopRow);
	cr_assert_arr_eq(
		newRightFaceTopRow,
		oldFrontFaceTopRow,
		FACE_SIZE,
		"front face top row wasn't moved to the right face top row");
}


Test(Cube, turnTopSliceRight_rightRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	readFaceTopRow(rightFace, oldRightFaceTopRow);
	// when
	Cube_turnTopSliceRight(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(backFace, newBackFaceBottomRow);
	cr_assert_arr_eq(
		newBackFaceBottomRow,
		oldRightFaceTopRow,
		FACE_SIZE,
		"right face top row wasn't moved to the back face bottom row");
}


Test(Cube, turnTopSliceRight_backRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(backFace, oldBackFaceBottomRow);
	// when
	Cube_turnTopSliceRight(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceTopRow[FACE_SIZE];
	readFaceTopRow(leftFace, newLeftFaceTopRow);
	cr_assert_arr_eq(
		newLeftFaceTopRow,
		oldBackFaceBottomRow,
		FACE_SIZE,
		"back face bottom row wasn't moved to the left face top row");
}


Test(Cube, turnTopSliceRight_leftRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	readFaceTopRow(leftFace, oldLeftFaceTopRow);
	// when
	Cube_turnTopSliceRight(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceTopRow[FACE_SIZE];
	readFaceTopRow(frontFace, newFrontFaceTopRow);
	cr_assert_arr_eq(
		newFrontFaceTopRow,
		oldLeftFaceTopRow,
		FACE_SIZE,
		"left face top row wasn't moved to the front face top row");
}


Test(Cube, turnEquatorSliceLeft_frontRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(frontFace, oldFrontFaceEquatorRow);
	// when
	Cube_turnEquatorSliceLeft(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(leftFace, newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		newLeftFaceEquatorRow,
		oldFrontFaceEquatorRow,
		FACE_SIZE,
		"front face equator row wasn't moved to the left face equator row");
}


Test(Cube, turnEquatorSliceLeft_leftRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(leftFace, oldLeftFaceEquatorRow);
	// when
	Cube_turnEquatorSliceLeft(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(backFace, newBackFaceEquatorRow);
	cr_assert_arr_eq(
		newBackFaceEquatorRow,
		oldLeftFaceEquatorRow,
		FACE_SIZE,
		"left face equator row wasn't moved to the back face equator row");
}


Test(Cube, turnEquatorSliceLeft_backRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(backFace, oldBackFaceEquatorRow);
	// when
	Cube_turnEquatorSliceLeft(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		newRightFaceEquatorRow,
		oldBackFaceEquatorRow,
		FACE_SIZE,
		"back face equator row wasn't moved to the right face equator row");
}


Test(Cube, turnEquatorSliceLeft_rightRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(rightFace, oldRightFaceEquatorRow);
	// when
	Cube_turnEquatorSliceLeft(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(frontFace, newFrontFaceEquatorRow);
	cr_assert_arr_eq(
		newFrontFaceEquatorRow,
		oldRightFaceEquatorRow,
		FACE_SIZE,
		"right face equator row wasn't moved to the front face equator row");
}


Test(Cube, turnEquatorSliceRight_frontRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(frontFace, oldFrontFaceEquatorRow);
	// when
	Cube_turnEquatorSliceRight(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(rightFace, newRightFaceEquatorRow);
	cr_assert_arr_eq(
		newRightFaceEquatorRow,
		oldFrontFaceEquatorRow,
		FACE_SIZE,
		"front face equator row wasn't moved to the right face equator row");
}


Test(Cube, turnEquatorSliceRight_rightRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(rightFace, oldRightFaceEquatorRow);
	// when
	Cube_turnEquatorSliceRight(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(backFace, newBackFaceEquatorRow);
	cr_assert_arr_eq(
		newBackFaceEquatorRow,
		oldRightFaceEquatorRow,
		FACE_SIZE,
		"right face equator row wasn't moved to the back face equator row");
}


Test(Cube, turnEquatorSliceRight_backRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(backFace, oldBackFaceEquatorRow);
	// when
	Cube_turnEquatorSliceRight(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(leftFace, newLeftFaceEquatorRow);
	cr_assert_arr_eq(
		newLeftFaceEquatorRow,
		oldBackFaceEquatorRow,
		FACE_SIZE,
		"back face equator row wasn't moved to the left face equator row");
}


Test(Cube, turnEquatorSliceRight_leftRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(leftFace, oldLeftFaceEquatorRow);
	// when
	Cube_turnEquatorSliceRight(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(frontFace, newFrontFaceEquatorRow);
	cr_assert_arr_eq(
		newFrontFaceEquatorRow,
		oldLeftFaceEquatorRow,
		FACE_SIZE,
		"left face equator row wasn't moved to the front face equator row");
}


Test(Cube, turnBottomSliceLeft_frontRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(frontFace, oldFrontFaceBottomRow);
	// when
	Cube_turnBottomSliceLeft(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(leftFace, newLeftFaceBottomRow);
	cr_assert_arr_eq(
		newLeftFaceBottomRow,
		oldFrontFaceBottomRow,
		FACE_SIZE,
		"front face bottom row wasn't moved to the left face bottom row");
}


Test(Cube, turnBottomSliceLeft_leftRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(leftFace, oldLeftFaceBottomRow);
	// when
	Cube_turnBottomSliceLeft(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceTopRow[FACE_SIZE];
	readFaceTopRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		newBackFaceTopRow,
		oldLeftFaceBottomRow,
		FACE_SIZE,
		"left face bottom row wasn't moved to the back face top row");
}


Test(Cube, turnBottomSliceLeft_backRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	readFaceTopRow(backFace, oldBackFaceTopRow);
	// when
	Cube_turnBottomSliceLeft(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(rightFace, newRightFaceBottomRow);
	cr_assert_arr_eq(
		newRightFaceBottomRow,
		oldBackFaceTopRow,
		FACE_SIZE,
		"back face top row wasn't moved to the right face bottom row");
}


Test(Cube, turnBottomSliceLeft_rightRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(rightFace, oldRightFaceBottomRow);
	// when
	Cube_turnBottomSliceLeft(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(frontFace, newFrontFaceBottomRow);
	cr_assert_arr_eq(
		newFrontFaceBottomRow,
		oldRightFaceBottomRow,
		FACE_SIZE,
		"right face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, turnBottomSliceRight_frontRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(frontFace, oldFrontFaceBottomRow);
	// when
	Cube_turnBottomSliceRight(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(rightFace, newRightFaceBottomRow);
	cr_assert_arr_eq(
		newRightFaceBottomRow,
		oldFrontFaceBottomRow,
		FACE_SIZE,
		"front face bottom row wasn't moved to the right face bottom row");
}


Test(Cube, turnBottomSliceRight_rightRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(rightFace, oldRightFaceBottomRow);
	// when
	Cube_turnBottomSliceRight(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceTopRow[FACE_SIZE];
	readFaceTopRow(backFace, newBackFaceTopRow);
	cr_assert_arr_eq(
		newBackFaceTopRow,
		oldRightFaceBottomRow,
		FACE_SIZE,
		"right face bottom row wasn't moved to the back face top row");
}


Test(Cube, turnBottomSliceRight_backRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	readFaceTopRow(backFace, oldBackFaceTopRow);
	// when
	Cube_turnBottomSliceRight(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(leftFace, newLeftFaceBottomRow);
	cr_assert_arr_eq(
		newLeftFaceBottomRow,
		oldBackFaceTopRow,
		FACE_SIZE,
		"back face top row wasn't moved to the left face bottom row");
}


Test(Cube, turnBottomSliceRight_leftRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(leftFace, oldLeftFaceBottomRow);
	// when
	Cube_turnBottomSliceRight(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(frontFace, newFrontFaceBottomRow);
	cr_assert_arr_eq(
		newFrontFaceBottomRow,
		oldLeftFaceBottomRow,
		FACE_SIZE,
		"left face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, turnLeftSliceUp_frontColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(frontFace, oldFrontFaceLeftColumn);
	// when
	Cube_turnLeftSliceUp(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(topFace, newTopFaceLeftColumn);
	cr_assert_arr_eq(
		newTopFaceLeftColumn,
		oldFrontFaceLeftColumn,
		FACE_SIZE,
		"front face left column wasn't moved to the top face left column");
}


Test(Cube, turnLeftSliceUp_topColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(topFace, oldTopFaceLeftColumn);
	// when
	Cube_turnLeftSliceUp(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(backFace, newBackFaceLeftColumn);
	cr_assert_arr_eq(
		newBackFaceLeftColumn,
		oldTopFaceLeftColumn,
		FACE_SIZE,
		"top face left column wasn't moved to the back face left column");
}


Test(Cube, turnLeftSliceUp_backColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(backFace, oldBackFaceLeftColumn);
	// when
	Cube_turnLeftSliceUp(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(bottomFace, newBottomFaceLeftColumn);
	cr_assert_arr_eq(
		newBottomFaceLeftColumn,
		oldBackFaceLeftColumn,
		FACE_SIZE,
		"back face left column wasn't moved to the bottom face left column");
}


Test(Cube, turnLeftSliceUp_bottomColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(bottomFace, oldBottomFaceLeftColumn);
	// when
	Cube_turnLeftSliceUp(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(frontFace, newFrontFaceLeftColumn);
	cr_assert_arr_eq(
		newFrontFaceLeftColumn,
		oldBottomFaceLeftColumn,
		FACE_SIZE,
		"bottom face left column wasn't moved to the front face left column");
}


Test(Cube, turnLeftSliceDown_frontColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(frontFace, oldFrontFaceLeftColumn);
	// when
	Cube_turnLeftSliceDown(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(bottomFace, newBottomFaceLeftColumn);
	cr_assert_arr_eq(
		newBottomFaceLeftColumn,
		oldFrontFaceLeftColumn,
		FACE_SIZE,
		"front face left column wasn't moved to the bottom face left column");
}


Test(Cube, turnLeftSliceDown_bottomColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(bottomFace, oldBottomFaceLeftColumn);
	// when
	Cube_turnLeftSliceDown(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(backFace, newBackFaceLeftColumn);
	cr_assert_arr_eq(
		newBackFaceLeftColumn,
		oldBottomFaceLeftColumn,
		FACE_SIZE,
		"bottom face left column wasn't moved to the back face left column");
}


Test(Cube, turnLeftSliceDown_backColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(backFace, oldBackFaceLeftColumn);
	// when
	Cube_turnLeftSliceDown(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(topFace, newTopFaceLeftColumn);
	cr_assert_arr_eq(
		newTopFaceLeftColumn,
		oldBackFaceLeftColumn,
		FACE_SIZE,
		"back face left column wasn't moved to the top face left column");
}


Test(Cube, turnLeftSliceDown_topColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(topFace, oldTopFaceLeftColumn);
	// when
	Cube_turnLeftSliceDown(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(frontFace, newFrontFaceLeftColumn);
	cr_assert_arr_eq(
		newFrontFaceLeftColumn,
		oldTopFaceLeftColumn,
		FACE_SIZE,
		"top face left column wasn't moved to the front face left column");
}


Test(Cube, turnMiddleSliceUp_frontColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	Cube_turnMiddleSliceUp(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(topFace, newTopFaceMiddleColumn);
	cr_assert_arr_eq(
		newTopFaceMiddleColumn,
		oldFrontFaceMiddleColumn,
		FACE_SIZE,
		"front face middle column wasn't moved to the top face middle column");
}


Test(Cube, turnMiddleSliceUp_topColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(topFace, oldTopFaceMiddleColumn);
	// when
	Cube_turnMiddleSliceUp(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(backFace, newBackFaceMiddleColumn);
	cr_assert_arr_eq(
		newBackFaceMiddleColumn,
		oldTopFaceMiddleColumn,
		FACE_SIZE,
		"top face middle column wasn't moved to the back face middle column");
}


Test(Cube, turnMiddleSliceUp_backColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(backFace, oldBackFaceMiddleColumn);
	// when
	Cube_turnMiddleSliceUp(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(bottomFace, newBottomFaceMiddleColumn);
	cr_assert_arr_eq(
		newBottomFaceMiddleColumn,
		oldBackFaceMiddleColumn,
		FACE_SIZE,
		"back face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, turnMiddleSliceUp_bottomColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	Cube_turnMiddleSliceUp(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(frontFace, newFrontFaceMiddleColumn);
	cr_assert_arr_eq(
		newFrontFaceMiddleColumn,
		oldBottomFaceMiddleColumn,
		FACE_SIZE,
		"bottom face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, turnMiddleSliceDown_frontColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	Cube_turnMiddleSliceDown(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(bottomFace, newBottomFaceMiddleColumn);
	cr_assert_arr_eq(
		newBottomFaceMiddleColumn,
		oldFrontFaceMiddleColumn,
		FACE_SIZE,
		"front face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, turnMiddleSliceDown_bottomColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	Cube_turnMiddleSliceDown(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(backFace, newBackFaceMiddleColumn);
	cr_assert_arr_eq(
		newBackFaceMiddleColumn,
		oldBottomFaceMiddleColumn,
		FACE_SIZE,
		"bottom face middle column wasn't moved to the back face middle column");
}


Test(Cube, turnMiddleSliceDown_backColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(backFace, oldBackFaceMiddleColumn);
	// when
	Cube_turnMiddleSliceDown(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(topFace, newTopFaceMiddleColumn);
	cr_assert_arr_eq(
		newTopFaceMiddleColumn,
		oldBackFaceMiddleColumn,
		FACE_SIZE,
		"back face middle column wasn't moved to the top face middle column");
}


Test(Cube, turnMiddleSliceDown_topColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(topFace, oldTopFaceMiddleColumn);
	// when
	Cube_turnMiddleSliceDown(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(frontFace, newFrontFaceMiddleColumn);
	cr_assert_arr_eq(
		newFrontFaceMiddleColumn,
		oldTopFaceMiddleColumn,
		FACE_SIZE,
		"top face middle column wasn't moved to the front face middle column");
}


Test(Cube, turnRightSliceUp_frontColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	Cube_turnRightSliceUp(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(topFace, newTopFaceMiddleColumn);
	cr_assert_arr_eq(
		newTopFaceMiddleColumn,
		oldFrontFaceMiddleColumn,
		FACE_SIZE,
		"front face right column wasn't moved to the top face right column");
}


Test(Cube, turnRightSliceUp_topColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(topFace, oldTopFaceMiddleColumn);
	// when
	Cube_turnRightSliceUp(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(backFace, newBackFaceMiddleColumn);
	cr_assert_arr_eq(
		newBackFaceMiddleColumn,
		oldTopFaceMiddleColumn,
		FACE_SIZE,
		"top face right column wasn't moved to the back face right column");
}


Test(Cube, turnRightSliceUp_backColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(backFace, oldBackFaceMiddleColumn);
	// when
	Cube_turnRightSliceUp(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(bottomFace, newBottomFaceMiddleColumn);
	cr_assert_arr_eq(
		newBottomFaceMiddleColumn,
		oldBackFaceMiddleColumn,
		FACE_SIZE,
		"back face right column wasn't moved to the bottom face right column");
}


Test(Cube, turnRightSliceUp_bottomColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	Cube_turnRightSliceUp(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(frontFace, newFrontFaceMiddleColumn);
	cr_assert_arr_eq(
		newFrontFaceMiddleColumn,
		oldBottomFaceMiddleColumn,
		FACE_SIZE,
		"bottom face right column wasn't moved to the front face right column");
}


Test(Cube, turnRightSliceDown_frontColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	Cube_turnRightSliceDown(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(bottomFace, newBottomFaceMiddleColumn);
	cr_assert_arr_eq(
		newBottomFaceMiddleColumn,
		oldFrontFaceMiddleColumn,
		FACE_SIZE,
		"front face right column wasn't moved to the bottom face right column");
}


Test(Cube, turnRightSliceDown_bottomColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	Cube_turnRightSliceDown(cube);
	// then
	Face * backFace = Cube_backFace(cube);
	Color newBackFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(backFace, newBackFaceMiddleColumn);
	cr_assert_arr_eq(
		newBackFaceMiddleColumn,
		oldBottomFaceMiddleColumn,
		FACE_SIZE,
		"bottom face right column wasn't moved to the back face right column");
}


Test(Cube, turnRightSliceDown_backColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(backFace, oldBackFaceMiddleColumn);
	// when
	Cube_turnRightSliceDown(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(topFace, newTopFaceMiddleColumn);
	cr_assert_arr_eq(
		newTopFaceMiddleColumn,
		oldBackFaceMiddleColumn,
		FACE_SIZE,
		"back face right column wasn't moved to the top face right column");
}


Test(Cube, turnRightSliceDown_topColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(topFace, oldTopFaceMiddleColumn);
	// when
	Cube_turnRightSliceDown(cube);
	// then
	Face * frontFace = Cube_frontFace(cube);
	Color newFrontFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(frontFace, newFrontFaceMiddleColumn);
	cr_assert_arr_eq(
		newFrontFaceMiddleColumn,
		oldTopFaceMiddleColumn,
		FACE_SIZE,
		"top face right column wasn't moved to the front face right column");
}


Test(Cube, turnFrontSliceClockwise_topRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(topFace, oldTopFaceBottomRow);
	// when
	Cube_turnFrontSliceClockwise(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(rightFace, newRightFaceLeftColumn);
	cr_assert_arr_eq(
		newRightFaceLeftColumn,
		oldTopFaceBottomRow,
		FACE_SIZE,
		"top face bottom row wasn't moved to the right face left column");
}


Test(Cube, turnFrontSliceClockwise_rightColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(rightFace, oldRightFaceLeftColumn);
	// when
	Cube_turnFrontSliceClockwise(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceTopRow[FACE_SIZE];
	readFaceTopRow(bottomFace, newBottomFaceTopRow);
	cr_assert_arr_eq(
		newBottomFaceTopRow,
		oldRightFaceLeftColumn,
		FACE_SIZE,
		"right face left column wasn't moved to the bottom face top row");
}

Test(Cube, turnFrontSliceClockwise_bottomRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	readFaceTopRow(bottomFace, oldBottomFaceTopRow);
	// when
	Cube_turnFrontSliceClockwise(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(leftFace, newLeftFaceRightColumn);
	cr_assert_arr_eq(
		newLeftFaceRightColumn,
		oldBottomFaceTopRow,
		FACE_SIZE,
		"bottom face top row wasn't moved to the left face right column");
}


Test(Cube, turnFrontSliceClockwise_leftColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(leftFace, oldLeftFaceRightColumn);
	// when
	Cube_turnFrontSliceClockwise(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(topFace, newTopFaceBottomRow);
	cr_assert_arr_eq(
		newTopFaceBottomRow,
		oldLeftFaceRightColumn,
		FACE_SIZE,
		"left face right column wasn't moved to the top face bottom row");
}


Test(Cube, turnFrontSliceAnticlockwise_topRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(topFace, oldTopFaceBottomRow);
	// when
	Cube_turnFrontSliceAnticlockwise(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(leftFace, newLeftFaceRightColumn);
	cr_assert_arr_eq(
		newLeftFaceRightColumn,
		oldTopFaceBottomRow,
		FACE_SIZE,
		"top face bottom row wasn't moved to the left face right column");
}


Test(Cube, turnFrontSliceAnticlockwise_leftColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(leftFace, oldLeftFaceRightColumn);
	// when
	Cube_turnFrontSliceAnticlockwise(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceTopRow[FACE_SIZE];
	readFaceTopRow(bottomFace, newBottomFaceTopRow);
	cr_assert_arr_eq(
		newBottomFaceTopRow,
		oldLeftFaceRightColumn,
		FACE_SIZE,
		"left face right column wasn't moved to the bottom face top row");
}


Test(Cube, turnFrontSliceAnticlockwise_bottomRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	readFaceTopRow(bottomFace, oldBottomFaceTopRow);
	// when
	Cube_turnFrontSliceAnticlockwise(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(rightFace, newRightFaceLeftColumn);
	cr_assert_arr_eq(
		newRightFaceLeftColumn,
		oldBottomFaceTopRow,
		FACE_SIZE,
		"bottom face top row wasn't moved to the right face left column");
}


Test(Cube, turnFrontSliceAnticlockwise_rightColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(rightFace, oldRightFaceLeftColumn);
	// when
	Cube_turnFrontSliceAnticlockwise(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(topFace, newTopFaceBottomRow);
	cr_assert_arr_eq(
		newTopFaceBottomRow,
		oldRightFaceLeftColumn,
		FACE_SIZE,
		"right face left column wasn't moved to the top face bottom row");
}


Test(Cube, turnStandingSliceClockwise_topRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(topFace, oldTopFaceEquatorRow);
	// when
	Cube_turnStandingSliceClockwise(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(rightFace, newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		newRightFaceMiddleColumn,
		oldTopFaceEquatorRow,
		FACE_SIZE,
		"top face equator row wasn't moved to the right face middle column");
}


Test(Cube, turnStandingSliceClockwise_rightColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(rightFace, oldRightFaceMiddleColumn);
	// when
	Cube_turnStandingSliceClockwise(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		newBottomFaceEquatorRow,
		oldRightFaceMiddleColumn,
		FACE_SIZE,
		"right face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, turnStandingSliceClockwise_bottomRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(bottomFace, oldBottomFaceEquatorRow);
	// when
	Cube_turnStandingSliceClockwise(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(leftFace, newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		newLeftFaceMiddleColumn,
		oldBottomFaceEquatorRow,
		FACE_SIZE,
		"bottom face equator row wasn't moved to the left face middle column");
}


Test(Cube, turnStandingSliceClockwise_leftColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(leftFace, oldLeftFaceMiddleColumn);
	// when
	Cube_turnStandingSliceClockwise(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		newTopFaceEquatorRow,
		oldLeftFaceMiddleColumn,
		FACE_SIZE,
		"left face middle column wasn't moved to the top face equator row");
}


Test(Cube, turnStandingSliceAnticlockwise_topRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(topFace, oldTopFaceEquatorRow);
	// when
	Cube_turnStandingSliceAnticlockwise(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(leftFace, newLeftFaceMiddleColumn);
	cr_assert_arr_eq(
		newLeftFaceMiddleColumn,
		oldTopFaceEquatorRow,
		FACE_SIZE,
		"top face equator row wasn't moved to the left face middle column");
}


Test(Cube, turnStandingSliceAnticlockwise_leftColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(leftFace, oldLeftFaceMiddleColumn);
	// when
	Cube_turnStandingSliceAnticlockwise(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(bottomFace, newBottomFaceEquatorRow);
	cr_assert_arr_eq(
		newBottomFaceEquatorRow,
		oldLeftFaceMiddleColumn,
		FACE_SIZE,
		"left face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, turnStandingSliceAnticlockwise_bottomRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(bottomFace, oldBottomFaceEquatorRow);
	// when
	Cube_turnStandingSliceAnticlockwise(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(rightFace, newRightFaceMiddleColumn);
	cr_assert_arr_eq(
		newRightFaceMiddleColumn,
		oldBottomFaceEquatorRow,
		FACE_SIZE,
		"bottom face equator row wasn't moved to the right face middle column");
}


Test(Cube, turnStandingSliceAnticlockwise_rightColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(rightFace, oldRightFaceMiddleColumn);
	// when
	Cube_turnStandingSliceAnticlockwise(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(topFace, newTopFaceEquatorRow);
	cr_assert_arr_eq(
		newTopFaceEquatorRow,
		oldRightFaceMiddleColumn,
		FACE_SIZE,
		"right face middle column wasn't moved to the top face equator row");
}


Test(Cube, turnBackSliceClockwise_topRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceTopRow[FACE_SIZE];
	readFaceTopRow(topFace, oldTopFaceTopRow);
	// when
	Cube_turnBackSliceClockwise(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(rightFace, newRightFaceRightColumn);
	cr_assert_arr_eq(
		newRightFaceRightColumn,
		oldTopFaceTopRow,
		FACE_SIZE,
		"top face top row wasn't moved to the right face right column");
}


Test(Cube, turnBackSliceClockwise_rightColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(rightFace, oldRightFaceRightColumn);
	// when
	Cube_turnBackSliceClockwise(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(bottomFace, newBottomFaceBottomRow);
	cr_assert_arr_eq(
		newBottomFaceBottomRow,
		oldRightFaceRightColumn,
		FACE_SIZE,
		"right face right column wasn't moved to the bottom face bottom row");
}


Test(Cube, turnBackSliceClockwise_bottomRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(bottomFace, oldBottomFaceBottomRow);
	// when
	Cube_turnBackSliceClockwise(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(leftFace, newLeftFaceLeftColumn);
	cr_assert_arr_eq(
		newLeftFaceLeftColumn,
		oldBottomFaceBottomRow,
		FACE_SIZE,
		"bottom face bottom row wasn't moved to the left face left column");
}


Test(Cube, turnBackSliceClockwise_leftColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(leftFace, oldLeftFaceLeftColumn);
	// when
	Cube_turnBackSliceClockwise(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceTopRow[FACE_SIZE];
	readFaceTopRow(topFace, newTopFaceTopRow);
	cr_assert_arr_eq(
		newTopFaceTopRow,
		oldLeftFaceLeftColumn,
		FACE_SIZE,
		"left face left column wasn't moved to the top face top row");
}


Test(Cube, turnBackSliceAnticlockwise_topRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceTopRow[FACE_SIZE];
	readFaceTopRow(topFace, oldTopFaceTopRow);
	// when
	Cube_turnBackSliceAnticlockwise(cube);
	// then
	Face * leftFace = Cube_leftFace(cube);
	Color newLeftFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(leftFace, newLeftFaceLeftColumn);
	cr_assert_arr_eq(
		newLeftFaceLeftColumn,
		oldTopFaceTopRow,
		FACE_SIZE,
		"top face top row wasn't moved to the left face left column");
}


Test(Cube, turnBackSliceAnticlockwise_leftColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(leftFace, oldLeftFaceLeftColumn);
	// when
	Cube_turnBackSliceAnticlockwise(cube);
	// then
	Face * bottomFace = Cube_bottomFace(cube);
	Color newBottomFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(bottomFace, newBottomFaceBottomRow);
	cr_assert_arr_eq(
		newBottomFaceBottomRow,
		oldLeftFaceLeftColumn,
		FACE_SIZE,
		"left face left column wasn't moved to the bottom face bottom row");
}


Test(Cube, turnBackSliceAnticlockwise_bottomRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(bottomFace, oldBottomFaceBottomRow);
	// when
	Cube_turnBackSliceAnticlockwise(cube);
	// then
	Face * rightFace = Cube_rightFace(cube);
	Color newRightFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(rightFace, newRightFaceRightColumn);
	cr_assert_arr_eq(
		newRightFaceRightColumn,
		oldBottomFaceBottomRow,
		FACE_SIZE,
		"bottom face bottom row wasn't moved to the right face right column");
}


Test(Cube, turnBackSliceAnticlockwise_rightColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(rightFace, oldRightFaceRightColumn);
	// when
	Cube_turnBackSliceAnticlockwise(cube);
	// then
	Face * topFace = Cube_topFace(cube);
	Color newTopFaceTopRow[FACE_SIZE];
	readFaceTopRow(topFace, newTopFaceTopRow);
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
	readFace(Cube_topFace(cube), cellsBeforeRotation);

	// when
	Cube_turnTopSliceLeft(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_topFace(cube), cellsAfterRotation);
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
	readFace(Cube_topFace(cube), cellsBeforeRotation);

	// when
	Cube_turnTopSliceRight(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_topFace(cube), cellsAfterRotation);
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
	readFace(Cube_bottomFace(cube), cellsBeforeRotation);

	// when
	Cube_turnBottomSliceLeft(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_bottomFace(cube), cellsAfterRotation);
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
	readFace(Cube_bottomFace(cube), cellsBeforeRotation);

	// when
	Cube_turnBottomSliceRight(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_bottomFace(cube), cellsAfterRotation);
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
	readFace(Cube_leftFace(cube), cellsBeforeRotation);

	// when
	Cube_turnLeftSliceUp(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_leftFace(cube), cellsAfterRotation);
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
	readFace(Cube_leftFace(cube), cellsBeforeRotation);

	// when
	Cube_turnLeftSliceDown(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_leftFace(cube), cellsAfterRotation);
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
	readFace(Cube_rightFace(cube), cellsBeforeRotation);

	// when
	Cube_turnRightSliceUp(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_rightFace(cube), cellsAfterRotation);
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
	readFace(Cube_rightFace(cube), cellsBeforeRotation);

	// when
	Cube_turnRightSliceDown(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_rightFace(cube), cellsAfterRotation);
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
	readFace(Cube_frontFace(cube), cellsBeforeRotation);

	// when
	Cube_turnFrontSliceClockwise(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_frontFace(cube), cellsAfterRotation);
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
	readFace(Cube_frontFace(cube), cellsBeforeRotation);

	// when
	Cube_turnFrontSliceAnticlockwise(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_frontFace(cube), cellsAfterRotation);
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
	readFace(Cube_backFace(cube), cellsBeforeRotation);

	// when
	Cube_turnBackSliceClockwise(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_backFace(cube), cellsAfterRotation);
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
	readFace(Cube_backFace(cube), cellsBeforeRotation);

	// when
	Cube_turnBackSliceAnticlockwise(cube);

	// then
	Color cellsAfterRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_backFace(cube), cellsAfterRotation);
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
	Face * leftFace = Cube_leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	Cube_rotateLeft(cube);

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
	Face * bottomFace = Cube_bottomFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceBeforeRotation);

	// when
	Cube_rotateLeft(cube);

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
	Face * backFace = Cube_backFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceBeforeRotation);

	// when
	Cube_rotateLeft(cube);

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
	Face * topFace = Cube_topFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceBeforeRotation);

	// when
	Cube_rotateLeft(cube);

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
	Face * rightFace = Cube_rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	Cube_rotateRight(cube);

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
	Face * bottomFace = Cube_bottomFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceBeforeRotation);

	// when
	Cube_rotateRight(cube);

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
	Face * backFace = Cube_backFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceBeforeRotation);

	// when
	Cube_rotateRight(cube);

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
	Face * topFace = Cube_topFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceBeforeRotation);

	// when
	Cube_rotateRight(cube);

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
	Face * leftFace = Cube_leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	Cube_rotateUp(cube);

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
	Face * rightFace = Cube_rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	Cube_rotateUp(cube);

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
	Face * leftFace = Cube_leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	Cube_rotateDown(cube);

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
	Face * rightFace = Cube_rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	Cube_rotateDown(cube);

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
	Face * leftFace = Cube_leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	Cube_rotateClockwise(cube);

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
	Face * frontFace = Cube_frontFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, faceBeforeRotation);

	// when
	Cube_rotateClockwise(cube);

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
	Face * rightFace = Cube_rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	Cube_rotateClockwise(cube);

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
	Face * bottomFace = Cube_bottomFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceBeforeRotation);

	// when
	Cube_rotateClockwise(cube);

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
	Face * backFace = Cube_backFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceBeforeRotation);

	// when
	Cube_rotateClockwise(cube);

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
	Face * topFace = Cube_topFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceBeforeRotation);

	// when
	Cube_rotateClockwise(cube);

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
	Face * leftFace = Cube_leftFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

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
	Face * frontFace = Cube_frontFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

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
	Face * rightFace = Cube_rightFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

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
	Face * bottomFace = Cube_bottomFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

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
	Face * backFace = Cube_backFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

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
	Face * topFace = Cube_topFace(cube);
	Color faceBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, faceBeforeRotation);

	// when
	Cube_rotateAnticlockwise(cube);

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
	Cube * cube = Cube_create();

	int rotationsLeft = 7;
	while (rotationsLeft--)
	{
		Cube_turnTopSliceLeft(cube);
		Cube_turnLeftSliceUp(cube);
		Cube_turnFrontSliceClockwise(cube);

		Cube_turnBottomSliceRight(cube);
		Cube_turnRightSliceDown(cube);
		Cube_turnBackSliceAnticlockwise(cube);
	}

	return cube;
}


static void readFaceTopRow(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topLeftCell(face);
	buffer[1] = Face_topCenterCell(face);
	buffer[2] = Face_topRightCell(face);
}

static void readFaceEquatorRow(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_equatorLeftCell(face);
	buffer[1] = Face_equatorCenterCell(face);
	buffer[2] = Face_equatorRightCell(face);
}


static void readFaceBottomRow(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_bottomLeftCell(face);
	buffer[1] = Face_bottomCenterCell(face);
	buffer[2] = Face_bottomRightCell(face);
}


static void readFaceLeftColumn(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topLeftCell(face);
	buffer[1] = Face_equatorLeftCell(face);
	buffer[2] = Face_bottomLeftCell(face);
}


static void readFaceMiddleColumn(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topCenterCell(face);
	buffer[1] = Face_equatorCenterCell(face);
	buffer[2] = Face_bottomCenterCell(face);
}


static void readFaceRightColumn(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topRightCell(face);
	buffer[1] = Face_equatorRightCell(face);
	buffer[2] = Face_bottomRightCell(face);
}


static void readFace(Face const * face, Color storage[FACE_SIZE][FACE_SIZE])
{
	size_t rowSizeInBytes = FACE_SIZE * sizeof(storage[0][0]);
	Color buffer[FACE_SIZE];

	readFaceTopRow(face, buffer);
	memcpy(storage[0], buffer, rowSizeInBytes);

	readFaceEquatorRow(face, buffer);
	memcpy(storage[1], buffer, rowSizeInBytes);

	readFaceBottomRow(face, buffer);
	memcpy(storage[2], buffer, rowSizeInBytes);
}
