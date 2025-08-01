
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateRightSlicesDown_frontFaceRightColumn_movesTo_bottomFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, rightColumn,
        Cube_rotateRightSlicesDown,
        Cube_bottomFace, rightColumn,
        "front face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateRightSlicesDown_frontFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, middleColumn,
        Cube_rotateRightSlicesDown,
        Cube_bottomFace, middleColumn,
        "front face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateRightSlicesDown_bottomFaceRightColumn_movesTo_backFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, rightColumn,
        Cube_rotateRightSlicesDown,
        Cube_backFace, rightColumn,
        "bottom face right column wasn't moved to the back face right column");
}


Test(Cube, rotateRightSlicesDown_bottomFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, middleColumn,
        Cube_rotateRightSlicesDown,
        Cube_backFace, middleColumn,
        "bottom face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateRightSlicesDown_backFaceRightColumn_movesTo_topFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, rightColumn,
        Cube_rotateRightSlicesDown,
        Cube_topFace, rightColumn,
        "back face right column wasn't moved to the top face right column");
}


Test(Cube, rotateRightSlicesDown_backFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, middleColumn,
        Cube_rotateRightSlicesDown,
        Cube_topFace, middleColumn,
        "back face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateRightSlicesDown_topFaceRightColumn_movesTo_frontFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, rightColumn,
        Cube_rotateRightSlicesDown,
        Cube_frontFace, rightColumn,
        "top face right column wasn't moved to the front face right column");
}


Test(Cube, rotateRightSlicesDown_topFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, middleColumn,
        Cube_rotateRightSlicesDown,
        Cube_frontFace, middleColumn,
        "top face middle column wasn't moved to the front face middle column");
}


Test(Cube, rotateRightSlicesDown_rightFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
        Cube_rightFace,
        Cube_rotateRightSlicesDown,
        "right face wasn't rotated");
}
