
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateOuterSlicesClockwise_topFaceBottomRow_movesTo_rightFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, bottomRow,
        Cube_rotateOuterSlicesClockwise,
        Cube_rightFace, leftColumn,
        "top face bottom row wasn't moved to the right face left column");
}


Test(Cube, rotateOuterSlicesClockwise_topFaceTopRow_movesTo_rightFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, topRow,
        Cube_rotateOuterSlicesClockwise,
        Cube_rightFace, rightColumn,
        "top face top row wasn't moved to the right face right column");
}


Test(Cube, rotateOuterSlicesClockwise_rightFaceLeftColumn_movesTo_bottomFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, leftColumn,
        Cube_rotateOuterSlicesClockwise,
        Cube_bottomFace, topRow,
        "right face left column wasn't moved to the bottom face top row");
}


Test(Cube, rotateOuterSlicesClockwise_rightFaceRightColumn_movesTo_bottomFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, rightColumn,
        Cube_rotateOuterSlicesClockwise,
        Cube_bottomFace, bottomRow,
        "right face right column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateOuterSlicesClockwise_bottomFaceTopRow_movesTo_leftFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, topRow,
        Cube_rotateOuterSlicesClockwise,
        Cube_leftFace, rightColumn,
        "bottom face top row wasn't moved to the left face right column");
}


Test(Cube, rotateOuterSlicesClockwise_bottomFaceBottomRow_movesTo_leftFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, bottomRow,
        Cube_rotateOuterSlicesClockwise,
        Cube_leftFace, leftColumn,
        "bottom face bottom row wasn't moved to the left face left column");
}


Test(Cube, rotateOuterSlicesClockwise_leftFaceRightColumn_movesTo_topFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, rightColumn,
        Cube_rotateOuterSlicesClockwise,
        Cube_topFace, bottomRow,
        "left face right column wasn't moved to the top face bottom row");
}


Test(Cube, rotateOuterSlicesClockwise_leftFaceLeftColumn_movesTo_topFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, leftColumn,
        Cube_rotateOuterSlicesClockwise,
        Cube_topFace, topRow,
        "left face left column wasn't moved to the top face top row");
}


Test(Cube, rotateOuterSlicesClockwise_frontFaceIsRotatedClockwise)
{
    test_face_rotated_clockwise(
        Cube_frontFace,
        Cube_rotateOuterSlicesClockwise,
        "front face wasn't rotated");
}


Test(Cube, rotateOuterSlicesClockwise_backFaceIsRotatedAnticlockwise)
{
    test_face_rotated_anticlockwise(
        Cube_backFace,
        Cube_rotateOuterSlicesClockwise,
        "back face wasn't rotated");
}
