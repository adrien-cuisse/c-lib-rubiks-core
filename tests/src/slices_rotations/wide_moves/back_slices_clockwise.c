
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateBackSlicesClockwise_topFaceTopRow_movesTo_rightFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, topRow,
        Cube_rotateBackSlicesClockwise,
        Cube_rightFace, rightColumn,
        "top face top row wasn't moved to the right face right column");
}


Test(Cube, rotateBackSlicesClockwise_topFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, equatorRow,
        Cube_rotateBackSlicesClockwise,
        Cube_rightFace, middleColumn,
        "top face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateBackSlicesClockwise_rightFaceRightColumn_movesTo_bottomFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, rightColumn,
        Cube_rotateBackSlicesClockwise,
        Cube_bottomFace, bottomRow,
        "right face right column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateBackSlicesClockwise_rightFaceMiddleColumn_movesTo_bottomFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, middleColumn,
        Cube_rotateBackSlicesClockwise,
        Cube_bottomFace, equatorRow,
        "right face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateBackSlicesClockwise_bottomFaceBottomRow_movesTo_leftFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, bottomRow,
        Cube_rotateBackSlicesClockwise,
        Cube_leftFace, leftColumn,
        "bottom face bottom row wasn't moved to the left face left column");
}


Test(Cube, rotateBackSlicesClockwise_bottomFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, equatorRow,
        Cube_rotateBackSlicesClockwise,
        Cube_leftFace, middleColumn,
        "bottom face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateBackSlicesClockwise_leftFaceLeftColumn_movesTo_topFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, leftColumn,
        Cube_rotateBackSlicesClockwise,
        Cube_topFace, topRow,
        "left face left column wasn't moved to the top face top row");
}


Test(Cube, rotateBackSlicesClockwise_leftFaceMiddleColumn_movesTo_topFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, middleColumn,
        Cube_rotateBackSlicesClockwise,
        Cube_topFace, equatorRow,
        "left face middle column wasn't moved to the top face equator row");
}
