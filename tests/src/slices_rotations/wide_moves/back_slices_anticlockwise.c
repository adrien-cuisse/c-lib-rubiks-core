
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateBackSlicesAnticlockwise_topFaceTopRow_movesTo_leftFaceLeftColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_topFace, topRow,
        Cube_rotateBackSlicesAnticlockwise,
        Cube_leftFace, leftColumn,
        "top face top row wasn't moved to the left face left column");
}


Test(Cube, rotateBackSlicesAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_topFace, equatorRow,
        Cube_rotateBackSlicesAnticlockwise,
        Cube_leftFace, middleColumn,
        "top face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateBackSlicesAnticlockwise_leftFaceLeftColumn_movesTo_bottomFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, leftColumn,
        Cube_rotateBackSlicesAnticlockwise,
        Cube_bottomFace, bottomRow,
        "left face left column wasn't moved to the bottom face bottom row");
}


Test(Cube, rotateBackSlicesAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, middleColumn,
        Cube_rotateBackSlicesAnticlockwise,
        Cube_bottomFace, equatorRow,
        "left face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateBackSlicesAnticlockwise_bottomFaceBottomRow_movesTo_rightFaceRightColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_bottomFace, bottomRow,
        Cube_rotateBackSlicesAnticlockwise,
        Cube_rightFace, rightColumn,
        "bottom face bottom row wasn't moved to the right face right column");
}


Test(Cube, rotateBackSlicesAnticlockwise_bottomFaceEquatorRow_movesTo_rightFaceMiddleColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_bottomFace, equatorRow,
        Cube_rotateBackSlicesAnticlockwise,
        Cube_rightFace, middleColumn,
        "bottom face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateBackSlicesAnticlockwise_rightFaceRightColumn_movesTo_topFaceTopRow)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, rightColumn,
        Cube_rotateBackSlicesAnticlockwise,
        Cube_topFace, topRow,
        "right face right column wasn't moved to the top face top row");
}


Test(Cube, rotateBackSlicesAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, middleColumn,
        Cube_rotateBackSlicesAnticlockwise,
        Cube_topFace, equatorRow,
        "right face middle column wasn't moved to the top face equator row");
}
