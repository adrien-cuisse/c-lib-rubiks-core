
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateBottomSliceRight_frontFaceBottomRow_movesTo_rightFaceBottomRow)
{
    test_span_moved(
        Cube_frontFace, bottomRow,
        Cube_rotateBottomSliceRight,
        Cube_rightFace, bottomRow,
        "front face bottom row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSliceRight_rightFaceBottomRow_movesTo_backFaceTopRow)
{
    test_span_moved(
        Cube_rightFace, bottomRow,
        Cube_rotateBottomSliceRight,
        Cube_backFace, topRow,
        "right face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSliceRight_backFaceTopRow_movesTo_leftFaceBottomRow)
{
    test_span_moved(
        Cube_backFace, topRow,
        Cube_rotateBottomSliceRight,
        Cube_leftFace, bottomRow,
        "back face top row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSliceRight_leftFaceBottomRow_movesTo_frontFaceBottomRow)
{
    test_span_moved(
        Cube_leftFace, bottomRow,
        Cube_rotateBottomSliceRight,
        Cube_frontFace, bottomRow,
        "left face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateBottomSliceRight_bottomFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * bottomFace = Cube_bottomFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(bottomFace, beforeRotation);

	// when
	Cube_rotateBottomSliceRight(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, bottomFace, "bottom");
}


Test(Cube, rotateBottomSliceRight_rightFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, bottomRow,
        Cube_rotateBottomSliceRight,
        Cube_backFace, topRow,
        "source span (right face bottom row) wasn't reversed");
}


Test(Cube, rotateBottomSliceRight_backFaceTopRow_movesTo_leftFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, topRow,
        Cube_rotateBottomSliceRight,
        Cube_leftFace, bottomRow,
        "source span (back face top row) wasn't reversed");
}


Test(Cube, rotateBottomSliceRight_leftFaceBottomRow_movesTo_frontFaceBottomRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, bottomRow,
        Cube_rotateBottomSliceRight,
        Cube_frontFace, bottomRow,
        "source span (left face bottom row) was reversed");
}


Test(Cube, rotateBottomSliceRight_frontFaceBottomRow_movesTo_rightFaceBottomRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, bottomRow,
        Cube_rotateBottomSliceRight,
        Cube_rightFace, bottomRow,
        "source span (front face bottom row) was reversed");
}
