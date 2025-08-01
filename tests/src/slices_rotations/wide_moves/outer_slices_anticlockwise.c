
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateOuterSlicesAnticlockwise_topFaceBottomRow_movesTo_leftFaceRightColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_topFace, bottomRow,
        Cube_rotateOuterSlicesAnticlockwise,
        Cube_leftFace, rightColumn,
        "top face bottom row wasn't moved to the left face right column");
}


Test(Cube, rotateOuterSlicesAnticlockwise_topFaceTopRow_movesTo_leftFaceLeftColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_topFace, topRow,
        Cube_rotateOuterSlicesAnticlockwise,
        Cube_leftFace, leftColumn,
        "top face top row wasn't moved to the left face left column");
}


Test(Cube, rotateOuterSlicesAnticlockwise_leftFaceRightColumn_movesTo_bottomFaceTopRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, rightColumn,
        Cube_rotateOuterSlicesAnticlockwise,
        Cube_bottomFace, topRow,
        "left face right column wasn't moved to the bottom face top row");
}


Test(Cube, rotateOuterSlicesAnticlockwise_leftFaceLeftColumn_movesTo_bottomFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, leftColumn,
        Cube_rotateOuterSlicesAnticlockwise,
        Cube_bottomFace, bottomRow,
        "left face left column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateOuterSlicesAnticlockwise_bottomFaceTopRow_movesTo_rightFaceLeftColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_bottomFace, topRow,
        Cube_rotateOuterSlicesAnticlockwise,
        Cube_rightFace, leftColumn,
        "bottom face top row wasn't moved to the right face left column");
}


Test(Cube, rotateOuterSlicesAnticlockwise_bottomFaceBottomRow_movesTo_rightFaceRightColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_bottomFace, bottomRow,
        Cube_rotateOuterSlicesAnticlockwise,
        Cube_rightFace, rightColumn,
        "bottom face bottom row wasn't moved to the right face right column");
}


Test(Cube, rotateOuterSlicesAnticlockwise_rightFaceLeftColumn_movesTo_topFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, leftColumn,
        Cube_rotateOuterSlicesAnticlockwise,
        Cube_topFace, bottomRow,
        "right face left column wasn't moved to the top face bottom row");
}


Test(Cube, rotateOuterSlicesAnticlockwise_rightFaceRightColumn_movesTo_topFaceTopRow)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, rightColumn,
        Cube_rotateOuterSlicesAnticlockwise,
        Cube_topFace, topRow,
        "right face right column wasn't moved to the top face top row");
}


Test(Cube, rotateOuterSlicesAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
    test_face_rotated_anticlockwise(
        Cube_frontFace,
        Cube_rotateOuterSlicesAnticlockwise,
        "front face wasn't rotated");
}


Test(Cube, rotateOuterSlicesAnticlockwise_backFaceIsRotatedClockwise)
{
    test_face_rotated_clockwise(
        Cube_backFace,
        Cube_rotateOuterSlicesAnticlockwise,
        "back face wasn't rotated");
}
