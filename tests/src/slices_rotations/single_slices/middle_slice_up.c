
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateMiddleSliceUp_frontFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
    test_span_moved(
        Cube_frontFace, middleColumn,
        Cube_rotateMiddleSliceUp,
        Cube_topFace, middleColumn,
        "front face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateMiddleSliceUp_topFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
    test_span_moved(
        Cube_topFace, middleColumn,
        Cube_rotateMiddleSliceUp,
        Cube_backFace, middleColumn,
        "top face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateMiddleSliceUp_backFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
    test_span_moved(
        Cube_backFace, middleColumn,
        Cube_rotateMiddleSliceUp,
        Cube_bottomFace, middleColumn,
        "back face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateMiddleSliceUp_bottomFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
    test_span_moved(
        Cube_bottomFace, middleColumn,
        Cube_rotateMiddleSliceUp,
        Cube_frontFace, middleColumn,
        "bottom face middle column wasn't moved to the front face middle column");
}


Test(Cube, rotateMiddleSliceUp_frontFaceMiddleColumn_movesTo_topFaceMiddleColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, middleColumn,
        Cube_rotateMiddleSliceUp,
        Cube_topFace, middleColumn,
        "source span (front face middle column) was reversed");
}


Test(Cube, rotateMiddleSliceUp_topFaceMiddleColumn_movesTo_backFaceMiddleColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, middleColumn,
        Cube_rotateMiddleSliceUp,
        Cube_backFace, middleColumn,
        "source span (top face middle column) was reversed");
}


Test(Cube, rotateMiddleSliceUp_backFaceMiddleColumn_movesTo_bottomFaceMiddleColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, middleColumn,
        Cube_rotateMiddleSliceUp,
        Cube_bottomFace, middleColumn,
        "source span (back face middle column) was reversed");
}


Test(Cube, rotateMiddleSliceUp_bottomFaceMiddleColumn_movesTo_frontFaceMiddleColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, middleColumn,
        Cube_rotateMiddleSliceUp,
        Cube_frontFace, middleColumn,
        "source span (bottom face middle column) was reversed");
}
