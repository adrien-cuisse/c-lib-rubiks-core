
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateBackSliceAnticlockwise_topFaceTopRow_movesTo_leftFaceLeftColumn)
{
    test_span_moved(
        Cube_topFace, topRow,
        Cube_rotateBackSliceAnticlockwise,
        Cube_leftFace, leftColumn,
        "top face top row wasn't moved to the left face left column");
}


Test(Cube, rotateBackSliceAnticlockwise_leftFaceLeftColumn_movesTo_bottomFaceBottomRow)
{
    test_span_moved(
        Cube_leftFace, leftColumn,
        Cube_rotateBackSliceAnticlockwise,
        Cube_bottomFace, bottomRow,
        "left face left column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateBackSliceAnticlockwise_bottomFaceBottomRow_movesTo_rightFaceRightColumn)
{
    test_span_moved(
        Cube_bottomFace, bottomRow,
        Cube_rotateBackSliceAnticlockwise,
        Cube_rightFace, rightColumn,
        "bottom face bottom row wasn't moved to the right face right column");
}


Test(Cube, rotateBackSliceAnticlockwise_rightFaceRightColumn_movesTo_topFaceTopRow)
{
    test_span_moved(
        Cube_rightFace, rightColumn,
        Cube_rotateBackSliceAnticlockwise,
        Cube_topFace, topRow,
        "right face right column wasn't moved to the top face top row");
}


Test(Cube, rotateBackSliceAnticlockwise_backFaceIsRotatedClockwise)
{
	// given
	Cube * cube = Cube_create();
	Face * backFace = Cube_backFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(backFace, beforeRotation);

	// when
	Cube_rotateBackSliceAnticlockwise(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, backFace, "back");
}


Test(Cube, rotateBackSliceAnticlockwise_bottomFaceBottomRow_movesTo_rightFaceRightColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_bottomFace, bottomRow,
        Cube_rotateBackSliceAnticlockwise,
        Cube_rightFace, rightColumn,
        "source span (bottom face bottom row) wasn't reversed");
}


Test(Cube, rotateBackSliceAnticlockwise_topFaceTopRow_movesTo_leftFaceLeftColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_topFace, topRow,
        Cube_rotateBackSliceAnticlockwise,
        Cube_leftFace, leftColumn,
        "source span (top face top row) wasn't reversed");
}


Test(Cube, rotateBackSliceAnticlockwise_rightFaceRightColumn_movesTo_topFaceTopRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, rightColumn,
        Cube_rotateBackSliceAnticlockwise,
        Cube_topFace, topRow,
        "source span (right face right column) was reversed");
}


Test(Cube, rotateBackSliceAnticlockwise_leftFaceLeftColumn_movesTo_bottomFaceBottomRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, leftColumn,
        Cube_rotateBackSliceAnticlockwise,
        Cube_bottomFace, bottomRow,
        "source span (left face left column) was reversed");
}
