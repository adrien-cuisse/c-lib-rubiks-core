
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateStandingSliceAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
    test_span_moved(
        Cube_topFace, equatorRow,
        Cube_rotateStandingSliceAnticlockwise,
        Cube_leftFace, middleColumn,
        "top face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateStandingSliceAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
    test_span_moved(
        Cube_leftFace, middleColumn,
        Cube_rotateStandingSliceAnticlockwise,
        Cube_bottomFace, equatorRow,
        "left face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateStandingSliceAnticlockwise_bottomFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
    test_span_moved(
        Cube_bottomFace, equatorRow,
        Cube_rotateStandingSliceAnticlockwise,
        Cube_rightFace, middleColumn,
        "bottom face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateStandingSliceAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
    test_span_moved(
        Cube_rightFace, middleColumn,
        Cube_rotateStandingSliceAnticlockwise,
        Cube_topFace, equatorRow,
        "right face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateStandingSliceAnticlockwise_topFaceEquatorRow_movesTo_leftFaceMiddleColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_topFace, equatorRow,
        Cube_rotateStandingSliceAnticlockwise,
        Cube_leftFace, middleColumn,
        "source span (top face equator row) wasn't reversed");
}


Test(Cube, rotateStandingSliceAnticlockwise_bottomFaceEquatorRow_movesTo_rightFaceMiddleColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_bottomFace, equatorRow,
        Cube_rotateStandingSliceAnticlockwise,
        Cube_rightFace, middleColumn,
        "source span (bottom face equator row) wasn't reversed");
}


Test(Cube, rotateStandingSliceAnticlockwise_rightFaceMiddleColumn_movesTo_topFaceEquatorRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, middleColumn,
        Cube_rotateStandingSliceAnticlockwise,
        Cube_topFace, equatorRow,
        "source span (right face middle column) was reversed");
}


Test(Cube, rotateStandingSliceAnticlockwise_leftFaceMiddleColumn_movesTo_bottomFaceEquatorRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, middleColumn,
        Cube_rotateStandingSliceAnticlockwise,
        Cube_bottomFace, equatorRow,
        "source span (left face middle column) was reversed");
}
