
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateFrontSliceClockwise_topFaceBottomRow_movesTo_rightFaceLeftColumn)
{
    test_span_moved(
        Cube_topFace, bottomRow,
        Cube_rotateFrontSliceClockwise,
        Cube_rightFace, leftColumn,
        "top face bottom row wasn't moved to the right face left column");
}


Test(Cube, rotateFrontSliceClockwise_rightFaceLeftColumn_movesTo_bottomFaceTopRow)
{
    test_span_moved(
        Cube_rightFace, leftColumn,
        Cube_rotateFrontSliceClockwise,
        Cube_bottomFace, topRow,
        "right face left column wasn't moved to the bottom face top row");
}


Test(Cube, rotateFrontSliceClockwise_bottomFaceTopRow_movesTo_leftFaceRightColumn)
{
    test_span_moved(
        Cube_bottomFace, topRow,
        Cube_rotateFrontSliceClockwise,
        Cube_leftFace, rightColumn,
        "bottom face top row wasn't moved to the left face right column");
}


Test(Cube, rotateFrontSliceClockwise_leftFaceRightColumn_movesTo_topFaceBottomRow)
{
    test_span_moved(
        Cube_leftFace, rightColumn,
        Cube_rotateFrontSliceClockwise,
        Cube_topFace, bottomRow,
        "left face right column wasn't moved to the top face bottom row");
}


Test(Cube, rotateFrontSliceClockwise_frontFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, beforeRotation);

	// when
	Cube_rotateFrontSliceClockwise(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, frontFace, "front");
}


Test(Cube, rotateFrontSliceClockwise_rightFaceLeftColumn_movesTo_bottomFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, leftColumn,
        Cube_rotateFrontSliceClockwise,
        Cube_bottomFace, topRow,
        "source span (right face left column) wasn't reversed");
}


Test(Cube, rotateFrontSliceClockwise_leftFaceRightColumn_movesTo_topFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, rightColumn,
        Cube_rotateFrontSliceClockwise,
        Cube_topFace, bottomRow,
        "source span (left face right column) wasn't reversed");
}


Test(Cube, rotateFrontSliceClockwise_bottomFaceTopRow_movesTo_leftFaceRightColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, topRow,
        Cube_rotateFrontSliceClockwise,
        Cube_leftFace, rightColumn,
        "source span (bottom face top row) was reversed");
}


Test(Cube, rotateFrontSliceClockwise_topFaceBottomRow_movesTo_rightFaceLeftColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, bottomRow,
        Cube_rotateFrontSliceClockwise,
        Cube_rightFace, leftColumn,
        "source span (top face bottom row) was reversed");
}
