
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateFrontSlicesClockwise_topFaceBottomRow_movesTo_rightFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, bottomRow,
        Cube_rotateFrontSlicesClockwise,
        Cube_rightFace, leftColumn,
        "top face bottom row wasn't moved to the right face left column");
}


Test(Cube, rotateFrontSlicesClockwise_topFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, equatorRow,
        Cube_rotateFrontSlicesClockwise,
        Cube_rightFace, middleColumn,
        "top face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateFrontSlicesClockwise_rightFaceLeftColumn_movesTo_bottomFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, leftColumn,
        Cube_rotateFrontSlicesClockwise,
        Cube_bottomFace, topRow,
        "right face left column wasn't moved to the bottom face top row");
}


Test(Cube, rotateFrontSlicesClockwise_rightFaceMiddleColumn_movesTo_bottomFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, middleColumn,
        Cube_rotateFrontSlicesClockwise,
        Cube_bottomFace, equatorRow,
        "right face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateFrontSlicesClockwise_bottomFaceTopRow_movesTo_leftFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, topRow,
        Cube_rotateFrontSlicesClockwise,
        Cube_leftFace, rightColumn,
        "bottom face top row wasn't moved to the left face right column");
}


Test(Cube, rotateFrontSlicesClockwise_bottomFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, equatorRow,
        Cube_rotateFrontSlicesClockwise,
        Cube_leftFace, middleColumn,
        "bottom face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateFrontSlicesClockwise_leftFaceRightColumn_movesTo_topFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, rightColumn,
        Cube_rotateFrontSlicesClockwise,
        Cube_topFace, bottomRow,
        "left face right column wasn't moved to the top face bottom row");
}


Test(Cube, rotateFrontSlicesClockwise_leftFaceMiddleColumn_movesTo_topFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, middleColumn,
        Cube_rotateFrontSlicesClockwise,
        Cube_topFace, equatorRow,
        "left face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateFrontSlicesClockwise_frontFaceIsRotatedClockwise)
{
    test_face_rotated_clockwise(
        Cube_frontFace,
        Cube_rotateFrontSlicesClockwise,
        "front face wasn't rotated");
}
