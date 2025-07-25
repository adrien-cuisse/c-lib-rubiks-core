
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateLeftSliceDown_frontFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
    test_span_moved(
        Cube_frontFace, leftColumn,
        Cube_rotateLeftSliceDown,
        Cube_bottomFace, leftColumn,
        "front face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateLeftSliceDown_bottomFaceLeftColumn_movesTo_backFaceLeftColumn)
{
    test_span_moved(
        Cube_bottomFace, leftColumn,
        Cube_rotateLeftSliceDown,
        Cube_backFace, leftColumn,
        "bottom face left column wasn't moved to the back face left column");
}


Test(Cube, rotateLeftSliceDown_backFaceLeftColumn_movesTo_topFaceLeftColumn)
{
    test_span_moved(
        Cube_backFace, leftColumn,
        Cube_rotateLeftSliceDown,
        Cube_topFace, leftColumn,
        "back face left column wasn't moved to the top face left column");
}


Test(Cube, rotateLeftSliceDown_topFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
    test_span_moved(
        Cube_topFace, leftColumn,
        Cube_rotateLeftSliceDown,
        Cube_frontFace, leftColumn,
        "top face left column wasn't moved to the front face left column");
}


Test(Cube, rotateLeftSliceDown_leftFaceIsRotatedClockwise)
{
    test_face_rotated_clockwise(
        Cube_leftFace,
        Cube_rotateLeftSliceDown,
        "left face wasn't rotated");
}


Test(Cube, rotateLeftSliceDown_frontFaceLeftColumn_movesTo_bottomFaceLeftColumn_notReversed_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, leftColumn,
        Cube_rotateLeftSliceDown,
        Cube_bottomFace, leftColumn,
        "source span (front face left column) was reversed");
}


Test(Cube, rotateLeftSliceDown_bottomFaceLeftColumn_movesTo_backFaceLeftColumn_notReversed_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, leftColumn,
        Cube_rotateLeftSliceDown,
        Cube_backFace, leftColumn,
        "source span (bottom face left column) was reversed");
}


Test(Cube, rotateLeftSliceDown_backFaceLeftColumn_movesTo_topFaceLeftColumn_notReversed_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, leftColumn,
        Cube_rotateLeftSliceDown,
        Cube_topFace, leftColumn,
        "source span (back face left column) was reversed");
}


Test(Cube, rotateLeftSliceDown_topFaceLeftColumn_movesTo_frontFaceLeftColumn_notReversed_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, leftColumn,
        Cube_rotateLeftSliceDown,
        Cube_frontFace, leftColumn,
        "source span (top face left column) was reversed");
}
