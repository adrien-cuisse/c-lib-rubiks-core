
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateFrontSlicesAnticlockwise_topFaceBottomRow_movesTo_leftFaceRightColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_topFace, bottomRow,
        Cube_rotateFrontSlicesAnticlockwise,
        Cube_leftFace, rightColumn,
        "top face bottom row wasn't moved to the left face right column");
}


Test(Cube, rotateFrontSlicesAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_topFace, equatorRow,
        Cube_rotateFrontSlicesAnticlockwise,
        Cube_leftFace, middleColumn,
        "top face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateFrontSlicesAnticlockwise_leftFaceRightColumn_movesTo_bottomFaceTopRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, rightColumn,
        Cube_rotateFrontSlicesAnticlockwise,
        Cube_bottomFace, topRow,
        "left face right column wasn't moved to the bottom face top row");
}


Test(Cube, rotateFrontSlicesAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, middleColumn,
        Cube_rotateFrontSlicesAnticlockwise,
        Cube_bottomFace, equatorRow,
        "left face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateFrontSlicesAnticlockwise_bottomFaceTopRow_movesTo_rightFaceLeftColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_bottomFace, topRow,
        Cube_rotateFrontSlicesAnticlockwise,
        Cube_rightFace, leftColumn,
        "bottom face top row wasn't moved to the right face left column");
}


Test(Cube, rotateFrontSlicesAnticlockwise_bottomFaceEquatorRow_movesTo_rightFaceMiddleColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_bottomFace, equatorRow,
        Cube_rotateFrontSlicesAnticlockwise,
        Cube_rightFace, middleColumn,
        "bottom face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateFrontSlicesAnticlockwise_rightFaceLeftColumn_movesTo_topFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, leftColumn,
        Cube_rotateFrontSlicesAnticlockwise,
        Cube_topFace, bottomRow,
        "right face left column wasn't moved to the top face bottom row");
}


Test(Cube, rotateFrontSlicesAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, middleColumn,
        Cube_rotateFrontSlicesAnticlockwise,
        Cube_topFace, equatorRow,
        "right face middle column wasn't moved to the top face equator row");
}
