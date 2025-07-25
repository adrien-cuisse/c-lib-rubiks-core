
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateTopSliceLeft_frontFaceTopRow_movesTo_leftFaceTopRow)
{
    test_span_moved(
        Cube_frontFace, topRow,
        Cube_rotateTopSliceLeft,
        Cube_leftFace, topRow,
        "front face top row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSliceLeft_leftFaceTopRow_movesTo_backFaceBottomRow)
{
    test_span_moved(
        Cube_leftFace, topRow,
        Cube_rotateTopSliceLeft,
        Cube_backFace, bottomRow,
        "left face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSliceLeft_backFaceBottomRow_movesTo_rightFaceTopRow)
{
    test_span_moved(
        Cube_backFace, bottomRow,
        Cube_rotateTopSliceLeft,
        Cube_rightFace, topRow,
        "back face bottom row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSliceLeft_rightFaceTopRow_movesTo_frontFaceTopRow)
{
    test_span_moved(
        Cube_rightFace, topRow,
        Cube_rotateTopSliceLeft,
        Cube_frontFace, topRow,
        "right face top row wasn't moved to the front face top row");
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


Test(Cube, rotateTopSliceLeft_leftFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, topRow,
        Cube_rotateTopSliceLeft,
        Cube_backFace, bottomRow,
        "source span (left face top row) wasn't reversed");
}


Test(Cube, rotateTopSliceLeft_backFaceBottomRow_movesTo_rightFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, bottomRow,
        Cube_rotateTopSliceLeft,
        Cube_rightFace, topRow,
        "source span (back face bottom row) wasn't reversed");
}


Test(Cube, rotateTopSliceLeft_rightFaceTopRow_movesTo_frontFaceTopRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, topRow,
        Cube_rotateTopSliceLeft,
        Cube_frontFace, topRow,
        "source span (right face top row) was reversed");
}


Test(Cube, rotateTopSliceLeft_frontFaceTopRow_movesTo_leftFaceTopRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, topRow,
        Cube_rotateTopSliceLeft,
        Cube_leftFace, topRow,
        "source span (front face top row) was reversed");
}
