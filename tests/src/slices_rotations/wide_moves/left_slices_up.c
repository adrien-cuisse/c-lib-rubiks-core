
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateLeftSlicesUp_frontFaceLeftColumn_movesTo_topFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, leftColumn,
        Cube_rotateLeftSlicesUp,
        Cube_topFace, leftColumn,
        "front face left column wasn't moved to the top face left column");
}


Test(Cube, rotateLeftSlicesUp_frontFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, middleColumn,
        Cube_rotateLeftSlicesUp,
        Cube_topFace, middleColumn,
        "front face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateLeftSlicesUp_topFaceLeftColumn_movesTo_backFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, leftColumn,
        Cube_rotateLeftSlicesUp,
        Cube_backFace, leftColumn,
        "top face left column wasn't moved to the back face left column");
}


Test(Cube, rotateLeftSlicesUp_topFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, middleColumn,
        Cube_rotateLeftSlicesUp,
        Cube_backFace, middleColumn,
        "top face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateLeftSlicesUp_backFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, leftColumn,
        Cube_rotateLeftSlicesUp,
        Cube_bottomFace, leftColumn,
        "back face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateLeftSlicesUp_backFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, middleColumn,
        Cube_rotateLeftSlicesUp,
        Cube_bottomFace, middleColumn,
        "back face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateLeftSlicesUp_bottomFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, leftColumn,
        Cube_rotateLeftSlicesUp,
        Cube_frontFace, leftColumn,
        "bottom face left column wasn't moved to the front face left column");
}


Test(Cube, rotateLeftSlicesUp_bottomFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, middleColumn,
        Cube_rotateLeftSlicesUp,
        Cube_frontFace, middleColumn,
        "bottom face middle column wasn't moved to the front face middle column");
}
