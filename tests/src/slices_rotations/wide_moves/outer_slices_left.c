
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateOuterSlicesLeft_frontFaceTopRow_movesTo_leftFaceTopRow)
{
	test_span_moved_and_not_reversed(
		Cube_frontFace, topRow,
		Cube_rotateOuterSlicesLeft,
		Cube_leftFace, topRow,
		"front face top row wasn't moved to the left face top row");
}


Test(Cube, rotateOuterSlicesLeft_frontFaceBottomRow_movesTo_leftFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, bottomRow,
        Cube_rotateOuterSlicesLeft,
        Cube_leftFace, bottomRow,
        "front face bottom row wasn't moved to the left face bottom row");
}


Test(Cube, rotateOuterSlicesLeft_leftFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		Cube_leftFace, topRow,
		Cube_rotateOuterSlicesLeft,
		Cube_backFace, bottomRow,
		"left face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateOuterSlicesLeft_leftFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, bottomRow,
        Cube_rotateOuterSlicesLeft,
        Cube_backFace, topRow,
        "left face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateOuterSlicesLeft_backFaceBottomRow_movesTo_rightFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		Cube_backFace, bottomRow,
		Cube_rotateOuterSlicesLeft,
		Cube_rightFace, topRow,
		"back face bottom row wasn't moved to the right face top row");
}


Test(Cube, rotateOuterSlicesLeft_backFaceTopRow_movesTo_rightFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, topRow,
        Cube_rotateOuterSlicesLeft,
        Cube_rightFace, bottomRow,
        "back face top row wasn't moved to the right face bottom row");
}


Test(Cube, rotateOuterSlicesLeft_rightFaceTopRow_movesTo_frontFaceTopRow)
{
	test_span_moved_and_not_reversed(
		Cube_rightFace, topRow,
		Cube_rotateOuterSlicesLeft,
		Cube_frontFace, topRow,
		"right face top row wasn't moved to the front face top row");
}


Test(Cube, rotateOuterSlicesLeft_rightFaceBottomRow_movesTo_frontFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, bottomRow,
        Cube_rotateOuterSlicesLeft,
        Cube_frontFace, bottomRow,
        "right face bottom row wasn't moved to the front face bottom row");
}
