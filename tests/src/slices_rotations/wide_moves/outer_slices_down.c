
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateOuterSlicesDown_frontFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, leftColumn,
        Cube_rotateOuterSlicesDown,
        Cube_bottomFace, leftColumn,
        "front face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateOuterSlicesDown_frontFaceRightColumn_movesTo_bottomFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, rightColumn,
        Cube_rotateOuterSlicesDown,
        Cube_bottomFace, rightColumn,
        "front face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateOuterSlicesDown_bottomFaceLeftColumn_movesTo_backFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, leftColumn,
        Cube_rotateOuterSlicesDown,
        Cube_backFace, leftColumn,
        "bottom face left column wasn't moved to the back face left column");
}


Test(Cube, rotateOuterSlicesDown_bottomFaceRightColumn_movesTo_backFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, rightColumn,
        Cube_rotateOuterSlicesDown,
        Cube_backFace, rightColumn,
        "bottom face right column wasn't moved to the back face right column");
}


Test(Cube, rotateOuterSlicesDown_backFaceLeftColumn_movesTo_topFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, leftColumn,
        Cube_rotateOuterSlicesDown,
        Cube_topFace, leftColumn,
        "back face left column wasn't moved to the top face left column");
}


Test(Cube, rotateOuterSlicesDown_backFaceRightColumn_movesTo_topFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, rightColumn,
        Cube_rotateOuterSlicesDown,
        Cube_topFace, rightColumn,
        "back face right column wasn't moved to the top face right column");
}


Test(Cube, rotateOuterSlicesDown_topFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, leftColumn,
        Cube_rotateOuterSlicesDown,
        Cube_frontFace, leftColumn,
        "top face left column wasn't moved to the front face left column");
}


Test(Cube, rotateOuterSlicesDown_topFaceRightColumn_movesTo_frontFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, rightColumn,
        Cube_rotateOuterSlicesDown,
        Cube_frontFace, rightColumn,
        "top face right column wasn't moved to the front face right column");
}


Test(Cube, rotateOuterSlicesDown_leftFaceIsRotatedClockwise)
{
    test_face_rotated_clockwise(
        Cube_leftFace,
        Cube_rotateOuterSlicesDown,
        "left face wasn't rotated");
}


Test(Cube, rotateOuterSlicesDown_rightFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
        Cube_rightFace,
        Cube_rotateOuterSlicesDown,
        "right face wasn't rotated");
}
