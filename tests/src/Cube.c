
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


Test(Cube, rotateTopSliceLeft_frontRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	readFaceTopRow(frontFace, oldFrontFaceTopRow);
	// when
	Cube_rotateTopSliceLeft(cube);
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


Test(Cube, rotateTopSliceLeft_leftRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	readFaceTopRow(leftFace, oldLeftFaceTopRow);
	// when
	Cube_rotateTopSliceLeft(cube);
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


Test(Cube, rotateTopSliceLeft_backRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(backFace, oldBackFaceBottomRow);
	// when
	Cube_rotateTopSliceLeft(cube);
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


Test(Cube, rotateTopSliceLeft_rightRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	readFaceTopRow(rightFace, oldRightFaceTopRow);
	// when
	Cube_rotateTopSliceLeft(cube);
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


Test(Cube, rotateTopSliceRight_frontRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceTopRow[FACE_SIZE];
	readFaceTopRow(frontFace, oldFrontFaceTopRow);
	// when
	Cube_rotateTopSliceRight(cube);
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


Test(Cube, rotateTopSliceRight_rightRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceTopRow[FACE_SIZE];
	readFaceTopRow(rightFace, oldRightFaceTopRow);
	// when
	Cube_rotateTopSliceRight(cube);
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


Test(Cube, rotateTopSliceRight_backRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(backFace, oldBackFaceBottomRow);
	// when
	Cube_rotateTopSliceRight(cube);
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


Test(Cube, rotateTopSliceRight_leftRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceTopRow[FACE_SIZE];
	readFaceTopRow(leftFace, oldLeftFaceTopRow);
	// when
	Cube_rotateTopSliceRight(cube);
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


Test(Cube, rotateEquatorSliceLeft_frontRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(frontFace, oldFrontFaceEquatorRow);
	// when
	Cube_rotateEquatorSliceLeft(cube);
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


Test(Cube, rotateEquatorSliceLeft_leftRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(leftFace, oldLeftFaceEquatorRow);
	// when
	Cube_rotateEquatorSliceLeft(cube);
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


Test(Cube, rotateEquatorSliceLeft_backRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(backFace, oldBackFaceEquatorRow);
	// when
	Cube_rotateEquatorSliceLeft(cube);
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


Test(Cube, rotateEquatorSliceLeft_rightRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(rightFace, oldRightFaceEquatorRow);
	// when
	Cube_rotateEquatorSliceLeft(cube);
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


Test(Cube, rotateEquatorSliceRight_frontRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(frontFace, oldFrontFaceEquatorRow);
	// when
	Cube_rotateEquatorSliceRight(cube);
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


Test(Cube, rotateEquatorSliceRight_rightRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(rightFace, oldRightFaceEquatorRow);
	// when
	Cube_rotateEquatorSliceRight(cube);
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


Test(Cube, rotateEquatorSliceRight_backRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(backFace, oldBackFaceEquatorRow);
	// when
	Cube_rotateEquatorSliceRight(cube);
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


Test(Cube, rotateEquatorSliceRight_leftRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(leftFace, oldLeftFaceEquatorRow);
	// when
	Cube_rotateEquatorSliceRight(cube);
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


Test(Cube, rotateBottomSliceLeft_frontRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(frontFace, oldFrontFaceBottomRow);
	// when
	Cube_rotateBottomSliceLeft(cube);
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


Test(Cube, rotateBottomSliceLeft_leftRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(leftFace, oldLeftFaceBottomRow);
	// when
	Cube_rotateBottomSliceLeft(cube);
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


Test(Cube, rotateBottomSliceLeft_backRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	readFaceTopRow(backFace, oldBackFaceTopRow);
	// when
	Cube_rotateBottomSliceLeft(cube);
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


Test(Cube, rotateBottomSliceLeft_rightRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(rightFace, oldRightFaceBottomRow);
	// when
	Cube_rotateBottomSliceLeft(cube);
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


Test(Cube, rotateBottomSliceRight_frontRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(frontFace, oldFrontFaceBottomRow);
	// when
	Cube_rotateBottomSliceRight(cube);
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


Test(Cube, rotateBottomSliceRight_rightRowGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(rightFace, oldRightFaceBottomRow);
	// when
	Cube_rotateBottomSliceRight(cube);
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


Test(Cube, rotateBottomSliceRight_backRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceTopRow[FACE_SIZE];
	readFaceTopRow(backFace, oldBackFaceTopRow);
	// when
	Cube_rotateBottomSliceRight(cube);
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


Test(Cube, rotateBottomSliceRight_leftRowGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(leftFace, oldLeftFaceBottomRow);
	// when
	Cube_rotateBottomSliceRight(cube);
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


Test(Cube, rotateLeftSliceUp_frontColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(frontFace, oldFrontFaceLeftColumn);
	// when
	Cube_rotateLeftSliceUp(cube);
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


Test(Cube, rotateLeftSliceUp_topColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(topFace, oldTopFaceLeftColumn);
	// when
	Cube_rotateLeftSliceUp(cube);
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


Test(Cube, rotateLeftSliceUp_backColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(backFace, oldBackFaceLeftColumn);
	// when
	Cube_rotateLeftSliceUp(cube);
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


Test(Cube, rotateLeftSliceUp_bottomColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(bottomFace, oldBottomFaceLeftColumn);
	// when
	Cube_rotateLeftSliceUp(cube);
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


Test(Cube, rotateLeftSliceDown_frontColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(frontFace, oldFrontFaceLeftColumn);
	// when
	Cube_rotateLeftSliceDown(cube);
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


Test(Cube, rotateLeftSliceDown_bottomColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(bottomFace, oldBottomFaceLeftColumn);
	// when
	Cube_rotateLeftSliceDown(cube);
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


Test(Cube, rotateLeftSliceDown_backColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(backFace, oldBackFaceLeftColumn);
	// when
	Cube_rotateLeftSliceDown(cube);
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


Test(Cube, rotateLeftSliceDown_topColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(topFace, oldTopFaceLeftColumn);
	// when
	Cube_rotateLeftSliceDown(cube);
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


Test(Cube, rotateMiddleSliceUp_frontColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	Cube_rotateMiddleSliceUp(cube);
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


Test(Cube, rotateMiddleSliceUp_topColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(topFace, oldTopFaceMiddleColumn);
	// when
	Cube_rotateMiddleSliceUp(cube);
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


Test(Cube, rotateMiddleSliceUp_backColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(backFace, oldBackFaceMiddleColumn);
	// when
	Cube_rotateMiddleSliceUp(cube);
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


Test(Cube, rotateMiddleSliceUp_bottomColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	Cube_rotateMiddleSliceUp(cube);
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


Test(Cube, rotateMiddleSliceDown_frontColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	Cube_rotateMiddleSliceDown(cube);
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


Test(Cube, rotateMiddleSliceDown_bottomColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	Cube_rotateMiddleSliceDown(cube);
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


Test(Cube, rotateMiddleSliceDown_backColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(backFace, oldBackFaceMiddleColumn);
	// when
	Cube_rotateMiddleSliceDown(cube);
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


Test(Cube, rotateMiddleSliceDown_topColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(topFace, oldTopFaceMiddleColumn);
	// when
	Cube_rotateMiddleSliceDown(cube);
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


Test(Cube, rotateRightSliceUp_frontColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	Cube_rotateRightSliceUp(cube);
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


Test(Cube, rotateRightSliceUp_topColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(topFace, oldTopFaceMiddleColumn);
	// when
	Cube_rotateRightSliceUp(cube);
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


Test(Cube, rotateRightSliceUp_backColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(backFace, oldBackFaceMiddleColumn);
	// when
	Cube_rotateRightSliceUp(cube);
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


Test(Cube, rotateRightSliceUp_bottomColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	Cube_rotateRightSliceUp(cube);
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


Test(Cube, rotateRightSliceDown_frontColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * frontFace = Cube_frontFace(cube);
	Color oldFrontFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(frontFace, oldFrontFaceMiddleColumn);
	// when
	Cube_rotateRightSliceDown(cube);
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


Test(Cube, rotateRightSliceDown_bottomColumnGoesBack)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(bottomFace, oldBottomFaceMiddleColumn);
	// when
	Cube_rotateRightSliceDown(cube);
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


Test(Cube, rotateRightSliceDown_backColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color oldBackFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(backFace, oldBackFaceMiddleColumn);
	// when
	Cube_rotateRightSliceDown(cube);
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


Test(Cube, rotateRightSliceDown_topColumnGoesFront)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceMiddleColumn[FACE_SIZE];
	readFaceRightColumn(topFace, oldTopFaceMiddleColumn);
	// when
	Cube_rotateRightSliceDown(cube);
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


Test(Cube, rotateFrontSliceClockwise_topRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(topFace, oldTopFaceBottomRow);
	// when
	Cube_rotateFrontSliceClockwise(cube);
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


Test(Cube, rotateFrontSliceClockwise_rightColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(rightFace, oldRightFaceLeftColumn);
	// when
	Cube_rotateFrontSliceClockwise(cube);
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

Test(Cube, rotateFrontSliceClockwise_bottomRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	readFaceTopRow(bottomFace, oldBottomFaceTopRow);
	// when
	Cube_rotateFrontSliceClockwise(cube);
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


Test(Cube, rotateFrontSliceClockwise_leftColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(leftFace, oldLeftFaceRightColumn);
	// when
	Cube_rotateFrontSliceClockwise(cube);
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


Test(Cube, rotateFrontSliceAnticlockwise_topRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(topFace, oldTopFaceBottomRow);
	// when
	Cube_rotateFrontSliceAnticlockwise(cube);
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


Test(Cube, rotateFrontSliceAnticlockwise_leftColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(leftFace, oldLeftFaceRightColumn);
	// when
	Cube_rotateFrontSliceAnticlockwise(cube);
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


Test(Cube, rotateFrontSliceAnticlockwise_bottomRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceTopRow[FACE_SIZE];
	readFaceTopRow(bottomFace, oldBottomFaceTopRow);
	// when
	Cube_rotateFrontSliceAnticlockwise(cube);
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


Test(Cube, rotateFrontSliceAnticlockwise_rightColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(rightFace, oldRightFaceLeftColumn);
	// when
	Cube_rotateFrontSliceAnticlockwise(cube);
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


Test(Cube, rotateStandingSliceClockwise_topRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(topFace, oldTopFaceEquatorRow);
	// when
	Cube_rotateStandingSliceClockwise(cube);
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


Test(Cube, rotateStandingSliceClockwise_rightColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(rightFace, oldRightFaceMiddleColumn);
	// when
	Cube_rotateStandingSliceClockwise(cube);
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


Test(Cube, rotateStandingSliceClockwise_bottomRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(bottomFace, oldBottomFaceEquatorRow);
	// when
	Cube_rotateStandingSliceClockwise(cube);
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


Test(Cube, rotateStandingSliceClockwise_leftColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(leftFace, oldLeftFaceMiddleColumn);
	// when
	Cube_rotateStandingSliceClockwise(cube);
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


Test(Cube, rotateStandingSliceAnticlockwise_topRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(topFace, oldTopFaceEquatorRow);
	// when
	Cube_rotateStandingSliceAnticlockwise(cube);
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


Test(Cube, rotateStandingSliceAnticlockwise_leftColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(leftFace, oldLeftFaceMiddleColumn);
	// when
	Cube_rotateStandingSliceAnticlockwise(cube);
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


Test(Cube, rotateStandingSliceAnticlockwise_bottomRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceEquatorRow[FACE_SIZE];
	readFaceEquatorRow(bottomFace, oldBottomFaceEquatorRow);
	// when
	Cube_rotateStandingSliceAnticlockwise(cube);
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


Test(Cube, rotateStandingSliceAnticlockwise_rightColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceMiddleColumn[FACE_SIZE];
	readFaceMiddleColumn(rightFace, oldRightFaceMiddleColumn);
	// when
	Cube_rotateStandingSliceAnticlockwise(cube);
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


Test(Cube, rotateBackSliceClockwise_topRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceTopRow[FACE_SIZE];
	readFaceTopRow(topFace, oldTopFaceTopRow);
	// when
	Cube_rotateBackSliceClockwise(cube);
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


Test(Cube, rotateBackSliceClockwise_rightColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(rightFace, oldRightFaceRightColumn);
	// when
	Cube_rotateBackSliceClockwise(cube);
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


Test(Cube, rotateBackSliceClockwise_bottomRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(bottomFace, oldBottomFaceBottomRow);
	// when
	Cube_rotateBackSliceClockwise(cube);
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


Test(Cube, rotateBackSliceClockwise_leftColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(leftFace, oldLeftFaceLeftColumn);
	// when
	Cube_rotateBackSliceClockwise(cube);
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


Test(Cube, rotateBackSliceAnticlockwise_topRowGoesLeft)
{
	// given
	Cube * cube = Cube_create();
	Face * topFace = Cube_topFace(cube);
	Color oldTopFaceTopRow[FACE_SIZE];
	readFaceTopRow(topFace, oldTopFaceTopRow);
	// when
	Cube_rotateBackSliceAnticlockwise(cube);
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


Test(Cube, rotateBackSliceAnticlockwise_leftColumnGoesBottom)
{
	// given
	Cube * cube = Cube_create();
	Face * leftFace = Cube_leftFace(cube);
	Color oldLeftFaceLeftColumn[FACE_SIZE];
	readFaceLeftColumn(leftFace, oldLeftFaceLeftColumn);
	// when
	Cube_rotateBackSliceAnticlockwise(cube);
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


Test(Cube, rotateBackSliceAnticlockwise_bottomRowGoesRight)
{
	// given
	Cube * cube = Cube_create();
	Face * bottomFace = Cube_bottomFace(cube);
	Color oldBottomFaceBottomRow[FACE_SIZE];
	readFaceBottomRow(bottomFace, oldBottomFaceBottomRow);
	// when
	Cube_rotateBackSliceAnticlockwise(cube);
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


Test(Cube, rotateBackSliceAnticlockwise_rightColumnGoesTop)
{
	// given
	Cube * cube = Cube_create();
	Face * rightFace = Cube_rightFace(cube);
	Color oldRightFaceRightColumn[FACE_SIZE];
	readFaceRightColumn(rightFace, oldRightFaceRightColumn);
	// when
	Cube_rotateBackSliceAnticlockwise(cube);
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


Test(Cube, rotateTopSliceLeft_topFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_topFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateTopSliceLeft(cube);

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


Test(Cube, rotateTopSliceRight_topFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_topFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateTopSliceRight(cube);

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


Test(Cube, rotateBottomSliceLeft_bottomFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_bottomFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateBottomSliceLeft(cube);

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


Test(Cube, rotateBottomSliceRight_bottomFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_bottomFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateBottomSliceRight(cube);

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


Test(Cube, rotateLeftSliceUp_leftFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_leftFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateLeftSliceUp(cube);

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


Test(Cube, rotateLeftSliceDown_leftFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_leftFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateLeftSliceDown(cube);

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


Test(Cube, rotateRightSliceUp_rightFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_rightFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateRightSliceUp(cube);

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


Test(Cube, rotateRightSliceDown_rightFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_rightFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateRightSliceDown(cube);

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


Test(Cube, rotateFrontSliceClockwise_frontFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_frontFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateFrontSliceClockwise(cube);

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


Test(Cube, rotateFrontSliceAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_frontFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateFrontSliceAnticlockwise(cube);

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


Test(Cube, rotateBackSliceClockwise_backFaceIsRotatedAnticlockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_backFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateBackSliceClockwise(cube);

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


Test(Cube, rotateBackSliceAnticlockwise_backFaceIsRotatedClockwise)
{
	int rowIndex;
	int columnIndex;

	// given
	Cube * cube = createScrambledCube();
	Color cellsBeforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(Cube_backFace(cube), cellsBeforeRotation);

	// when
	Cube_rotateBackSliceAnticlockwise(cube);

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
		Cube_rotateTopSliceLeft(cube);
		Cube_rotateLeftSliceUp(cube);
		Cube_rotateFrontSliceClockwise(cube);

		Cube_rotateBottomSliceRight(cube);
		Cube_rotateRightSliceDown(cube);
		Cube_rotateBackSliceAnticlockwise(cube);
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
