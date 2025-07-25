
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateLeftSlicesDown_frontFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, leftColumn,
        Cube_rotateLeftSlicesDown,
        Cube_bottomFace, leftColumn,
        "front face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateLeftSlicesDown_frontFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, middleColumn,
        Cube_rotateLeftSlicesDown,
        Cube_bottomFace, middleColumn,
        "front face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateLeftSlicesDown_bottomFaceLeftColumn_movesTo_backFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, leftColumn,
        Cube_rotateLeftSlicesDown,
        Cube_backFace, leftColumn,
        "bottom face left column wasn't moved to the back face left column");
}


Test(Cube, rotateLeftSlicesDown_bottomFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, middleColumn,
        Cube_rotateLeftSlicesDown,
        Cube_backFace, middleColumn,
        "bottom face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateLeftSlicesDown_backFaceLeftColumn_movesTo_topFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, leftColumn,
        Cube_rotateLeftSlicesDown,
        Cube_topFace, leftColumn,
        "back face left column wasn't moved to the top face left column");
}


Test(Cube, rotateLeftSlicesDown_backFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, middleColumn,
        Cube_rotateLeftSlicesDown,
        Cube_topFace, middleColumn,
        "back face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateLeftSlicesDown_topFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, leftColumn,
        Cube_rotateLeftSlicesDown,
        Cube_frontFace, leftColumn,
        "top face left column wasn't moved to the front face left column");
}


Test(Cube, rotateLeftSlicesDown_topFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, middleColumn,
        Cube_rotateLeftSlicesDown,
        Cube_frontFace, middleColumn,
        "top face middle column wasn't moved to the front face middle column");
}
