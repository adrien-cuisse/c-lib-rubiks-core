
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateStandingSliceClockwise_topFaceEquatorRow_movesTo_rightFaceMiddleColumn)
{
    test_span_moved(
        Cube_topFace, equatorRow,
        Cube_rotateStandingSliceClockwise,
        Cube_rightFace, middleColumn,
        "top face equator row wasn't moved to the right face middle column");
}


Test(Cube, rotateStandingSliceClockwise_rightFaceMiddleColumn_movesTo_bottomFaceEquatorRow)
{
    test_span_moved(
        Cube_rightFace, middleColumn,
        Cube_rotateStandingSliceClockwise,
        Cube_bottomFace, equatorRow,
        "right face middle column wasn't moved to the bottom face equator row");
}


Test(Cube, rotateStandingSliceClockwise_bottomFaceEquatorRow_movesTo_leftFaceMiddleColumn)
{
    test_span_moved(
        Cube_bottomFace, equatorRow,
        Cube_rotateStandingSliceClockwise,
        Cube_leftFace, middleColumn,
        "bottom face equator row wasn't moved to the left face middle column");
}


Test(Cube, rotateStandingSliceClockwise_leftFaceMiddleColumn_movesTo_topFaceEquatorRow)
{
    test_span_moved(
        Cube_leftFace, middleColumn,
        Cube_rotateStandingSliceClockwise,
        Cube_topFace, equatorRow,
        "left face middle column wasn't moved to the top face equator row");
}


Test(Cube, rotateStandingSliceClockwise_rightFaceMiddleColumn_movesTo_bottomFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, middleColumn,
        Cube_rotateStandingSliceClockwise,
        Cube_bottomFace, equatorRow,
        "source span (right face middle column) wasn't reversed");
}


Test(Cube, rotateStandingSliceClockwise_leftFaceMiddleColumn_movesTo_topFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, middleColumn,
        Cube_rotateStandingSliceClockwise,
        Cube_topFace, equatorRow,
        "source span (left face middle column) wasn't reversed");
}


Test(Cube, rotateStandingSliceClockwise_bottomFaceEquatorRow_movesTo_leftFaceMiddleColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, equatorRow,
        Cube_rotateStandingSliceClockwise,
        Cube_leftFace, middleColumn,
        "source span (bottom face equator row) was reversed");
}


Test(Cube, rotateStandingSliceClockwise_topFaceEquatorRow_movesTo_rightFaceMiddleColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, equatorRow,
        Cube_rotateStandingSliceClockwise,
        Cube_rightFace, middleColumn,
        "source span (top face equator row) was reversed");
}
