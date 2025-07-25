
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateBackSliceClockwise_topFaceTopRow_movesTo_rightFaceRightColumn)
{
    test_span_moved(
        Cube_topFace, topRow,
        Cube_rotateBackSliceClockwise,
        Cube_rightFace, rightColumn,
        "top face top row wasn't moved to the right face right column");
}


Test(Cube, rotateBackSliceClockwise_rightFaceRightColumn_movesTo_bottomFaceBottomRow)
{
    test_span_moved(
        Cube_rightFace, rightColumn,
        Cube_rotateBackSliceClockwise,
        Cube_bottomFace, bottomRow,
        "right face right column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateBackSliceClockwise_bottomFaceBottomRow_movesTo_leftFaceLeftColumn)
{
    test_span_moved(
        Cube_bottomFace, bottomRow,
        Cube_rotateBackSliceClockwise,
        Cube_leftFace, leftColumn,
        "bottom face bottom row wasn't moved to the left face left column");
}


Test(Cube, rotateBackSliceClockwise_leftFaceLeftColumn_movesTo_topFaceTopRow)
{
    test_span_moved(
        Cube_leftFace, leftColumn,
        Cube_rotateBackSliceClockwise,
        Cube_topFace, topRow,
        "left face left column wasn't moved to the top face top row");
}


Test(Cube, rotateBackSliceClockwise_backFaceIsRotatedAnticlockwise)
{
    test_face_rotated_anticlockwise(
        Cube_backFace,
        Cube_rotateBackSliceClockwise,
        "back face wasn't rotated");
}


Test(Cube, rotateBackSliceClockwise_rightFaceRightColumn_movesTo_bottomFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, rightColumn,
        Cube_rotateBackSliceClockwise,
        Cube_bottomFace, bottomRow,
        "source span (right face right column) wasn't reversed");
}


Test(Cube, rotateBackSliceClockwise_leftFaceLeftColumn_movesTo_topFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, leftColumn,
        Cube_rotateBackSliceClockwise,
        Cube_topFace, topRow,
        "source span (left face left column) wasn't reversed");
}


Test(Cube, rotateBackSliceClockwise_bottomFaceBottomRow_movesTo_leftFaceLeftColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, bottomRow,
        Cube_rotateBackSliceClockwise,
        Cube_leftFace, leftColumn,
        "source span (bottom face bottom row) was reversed");
}


Test(Cube, rotateBackSliceClockwise_topFaceTopRow_movesTo_rightFaceRightColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, topRow,
        Cube_rotateBackSliceClockwise,
        Cube_rightFace, rightColumn,
        "source span (top face top row) was reversed");
}
