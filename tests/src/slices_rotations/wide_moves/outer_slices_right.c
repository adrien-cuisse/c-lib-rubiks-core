
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateOuterSlicesRight_frontFaceTopRow_movesTo_rightFaceTopRow)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, topRow,
        Cube_rotateOuterSlicesRight,
        Cube_rightFace, topRow,
        "front face top row wasn't moved to the right face top row");
}


Test(Cube, rotateOuterSlicesRight_frontFaceBottomRow_movesTo_rightFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, bottomRow,
        Cube_rotateOuterSlicesRight,
        Cube_rightFace, bottomRow,
        "front face bottom row wasn't moved to the right face bottom row");
}


Test(Cube, rotateOuterSlicesRight_rightFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, topRow,
        Cube_rotateOuterSlicesRight,
        Cube_backFace, bottomRow,
        "right face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateOuterSlicesRight_rightFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, bottomRow,
        Cube_rotateOuterSlicesRight,
        Cube_backFace, topRow,
        "right face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateOuterSlicesRight_backFaceBottomRow_movesTo_leftFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, bottomRow,
        Cube_rotateOuterSlicesRight,
        Cube_leftFace, topRow,
        "back face bottom row wasn't moved to the left face top row");
}


Test(Cube, rotateOuterSlicesRight_backFaceTopRow_movesTo_leftFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, topRow,
        Cube_rotateOuterSlicesRight,
        Cube_leftFace, bottomRow,
        "back face top row wasn't moved to the left face bottom row");
}


Test(Cube, rotateOuterSlicesRight_leftFaceTopRow_movesTo_frontFaceTopRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, topRow,
        Cube_rotateOuterSlicesRight,
        Cube_frontFace, topRow,
        "left face top row wasn't moved to the front face top row");
}


Test(Cube, rotateOuterSlicesRight_leftFaceBottomRow_movesTo_frontFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, bottomRow,
        Cube_rotateOuterSlicesRight,
        Cube_frontFace, bottomRow,
        "left face bottom row wasn't moved to the front face bottom row");
}
