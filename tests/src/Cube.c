
#include <criterion/criterion.h>

#include "../../include/Cube.h"




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
