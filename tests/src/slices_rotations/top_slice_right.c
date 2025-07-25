
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateTopSliceRight_frontFaceTopRow_movesTo_rightFaceTopRow)
{
    test_span_moved(
        Cube_frontFace, topRow,
        Cube_rotateTopSliceRight,
        Cube_rightFace, topRow,
        "front face top row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSliceRight_rightFaceTopRow_movesTo_backFaceBottomRow)
{
    test_span_moved(
        Cube_rightFace, topRow,
        Cube_rotateTopSliceRight,
        Cube_backFace, bottomRow,
        "right face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSliceRight_backFaceBottomRow_movesTo_leftFaceTopRow)
{
    test_span_moved(
        Cube_backFace, bottomRow,
        Cube_rotateTopSliceRight,
        Cube_leftFace, topRow,
        "back face bottom row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSliceRight_leftFaceTopRow_movesTo_frontFaceTopRow)
{
    test_span_moved(
        Cube_leftFace, topRow,
        Cube_rotateTopSliceRight,
        Cube_frontFace, topRow,
        "left face top row wasn't moved to the front face top row");
}


Test(Cube, rotateTopSliceRight_topFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * topFace = Cube_topFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(topFace, beforeRotation);

	// when
	Cube_rotateTopSliceRight(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, topFace, "top");
}


Test(Cube, rotateTopSliceRight_rightFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, topRow,
        Cube_rotateTopSliceRight,
        Cube_backFace, bottomRow,
        "source span (right face top row) wasn't reversed");
}


Test(Cube, rotateTopSliceRight_backFaceBottomRow_movesTo_leftFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, bottomRow,
        Cube_rotateTopSliceRight,
        Cube_leftFace, topRow,
        "source span (back face bottom row) wasn't reversed");
}


Test(Cube, rotateTopSliceRight_leftFaceTopRow_movesTo_frontFaceTopRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, topRow,
        Cube_rotateTopSliceRight,
        Cube_frontFace, topRow,
        "source span (left face top row) was reversed");
}


Test(Cube, rotateTopSliceRight_frontFaceTopRow_movesTo_rightFaceTopRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, topRow,
        Cube_rotateTopSliceRight,
        Cube_rightFace, topRow,
        "source span (front face top row) was reversed");
}
