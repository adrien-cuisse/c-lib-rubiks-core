
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateOuterSlicesUp_frontFaceLeftColumn_movesTo_topFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, leftColumn,
        Cube_rotateOuterSlicesUp,
        Cube_topFace, leftColumn,
        "front face left column wasn't moved to the top face left column");
}


Test(Cube, rotateOuterSlicesUp_frontFaceRightColumn_movesTo_topFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, rightColumn,
        Cube_rotateOuterSlicesUp,
        Cube_topFace, rightColumn,
        "front face right column wasn't moved to the top face right column");
}


Test(Cube, rotateOuterSlicesUp_topFaceLeftColumn_movesTo_backFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, leftColumn,
        Cube_rotateOuterSlicesUp,
        Cube_backFace, leftColumn,
        "top face left column wasn't moved to the back face left column");
}


Test(Cube, rotateOuterSlicesUp_topFaceRightColumn_movesTo_backFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, rightColumn,
        Cube_rotateOuterSlicesUp,
        Cube_backFace, rightColumn,
        "top face right column wasn't moved to the back face right column");
}


Test(Cube, rotateOuterSlicesUp_backFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, leftColumn,
        Cube_rotateOuterSlicesUp,
        Cube_bottomFace, leftColumn,
        "back face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateOuterSlicesUp_backFaceRightColumn_movesTo_bottomFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, rightColumn,
        Cube_rotateOuterSlicesUp,
        Cube_bottomFace, rightColumn,
        "back face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateOuterSlicesUp_bottomFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, leftColumn,
        Cube_rotateOuterSlicesUp,
        Cube_frontFace, leftColumn,
        "bottom face left column wasn't moved to the front face left column");
}


Test(Cube, rotateOuterSlicesUp_bottomFaceRightColumn_movesTo_frontFaceRightColumn)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, rightColumn,
        Cube_rotateOuterSlicesUp,
        Cube_frontFace, rightColumn,
        "bottom face right column wasn't moved to the front face right column");
}
