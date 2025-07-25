
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateBottomSliceLeft_frontFaceBottomRow_movesTo_leftFaceBottomRow)
{
    test_span_moved(
        Cube_frontFace, bottomRow,
        Cube_rotateBottomSliceLeft,
        Cube_leftFace, bottomRow,
        "front face bottom row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSliceLeft_leftFaceBottomRow_movesTo_backFaceTopRow)
{
    test_span_moved(
        Cube_leftFace, bottomRow,
        Cube_rotateBottomSliceLeft,
        Cube_backFace, topRow,
        "left face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSliceLeft_backFaceTopRow_movesTo_rightFaceBottomRow)
{
    test_span_moved(
        Cube_backFace, topRow,
        Cube_rotateBottomSliceLeft,
        Cube_rightFace, bottomRow,
        "back face top row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSliceLeft_rightFaceBottomRow_movesTo_frontFaceBottomRow)
{
    test_span_moved(
        Cube_rightFace, bottomRow,
        Cube_rotateBottomSliceLeft,
        Cube_frontFace, bottomRow,
        "right face bottom row wasn't moved to the front face bottom row");
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


Test(Cube, rotateBottomSliceLeft_leftFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, bottomRow,
        Cube_rotateBottomSliceLeft,
        Cube_backFace, topRow,
        "source span (left face bottom row) wasn't reversed");
}


Test(Cube, rotateBottomSliceLeft_backFaceTopRow_movesTo_rightFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, topRow,
        Cube_rotateBottomSliceLeft,
        Cube_rightFace, bottomRow,
        "source span (back face top row) wasn't reversed");
}


Test(Cube, rotateBottomSliceLeft_rightFaceBottomRow_movesTo_frontFaceBottomRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, bottomRow,
        Cube_rotateBottomSliceLeft,
        Cube_frontFace, bottomRow,
        "source span (right face bottom row) was reversed");
}


Test(Cube, rotateBottomSliceLeft_frontFaceBottomRow_movesTo_leftFaceBottomRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, bottomRow,
        Cube_rotateBottomSliceLeft,
        Cube_leftFace, bottomRow,
        "source span (front face bottom row) was reversed");
}
