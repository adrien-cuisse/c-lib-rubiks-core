
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateRightSlicesUp_frontFaceRightColumn_movesTo_topFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, rightColumn,
        Cube_rotateRightSlicesUp,
        Cube_topFace, rightColumn,
        "front face right column wasn't moved to the top face right column");
}


Test(Cube, rotateRightSlicesUp_frontFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, middleColumn,
        Cube_rotateRightSlicesUp,
        Cube_topFace, middleColumn,
        "front face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateRightSlicesUp_topFaceRightColumn_movesTo_backFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, rightColumn,
        Cube_rotateRightSlicesUp,
        Cube_backFace, rightColumn,
        "top face right column wasn't moved to the back face right column");
}


Test(Cube, rotateRightSlicesUp_topFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, middleColumn,
        Cube_rotateRightSlicesUp,
        Cube_backFace, middleColumn,
        "top face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateRightSlicesUp_backFaceRightColumn_movesTo_bottomFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, rightColumn,
        Cube_rotateRightSlicesUp,
        Cube_bottomFace, rightColumn,
        "back face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateRightSlicesUp_backFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, middleColumn,
        Cube_rotateRightSlicesUp,
        Cube_bottomFace, middleColumn,
        "back face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateRightSlicesUp_bottomFaceRightColumn_movesTo_frontFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, rightColumn,
        Cube_rotateRightSlicesUp,
        Cube_frontFace, rightColumn,
        "bottom face right column wasn't moved to the front face right column");
}


Test(Cube, rotateRightSlicesUp_bottomFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, middleColumn,
        Cube_rotateRightSlicesUp,
        Cube_frontFace, middleColumn,
        "bottom face middle column wasn't moved to the front face middle column");
}
