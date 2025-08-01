
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateBottomSlicesRight_frontFaceBottomRow_movesTo_rightFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, bottomRow,
        Cube_rotateBottomSlicesRight,
        Cube_rightFace, bottomRow,
        "front face bottom row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSlicesRight_frontFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, equatorRow,
        Cube_rotateBottomSlicesRight,
        Cube_rightFace, equatorRow,
        "front face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateBottomSlicesRight_rightFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, bottomRow,
        Cube_rotateBottomSlicesRight,
        Cube_backFace, topRow,
        "right face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSlicesRight_rightFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, equatorRow,
        Cube_rotateBottomSlicesRight,
        Cube_backFace, equatorRow,
        "right face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateBottomSlicesRight_backFaceTopRow_movesTo_leftFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, topRow,
        Cube_rotateBottomSlicesRight,
        Cube_leftFace, bottomRow,
        "back face top row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSlicesRight_backFaceEquatorRow_movesTo_leftFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, equatorRow,
        Cube_rotateBottomSlicesRight,
        Cube_leftFace, equatorRow,
        "back face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateBottomSlicesRight_leftFaceBottomRow_movesTo_frontFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, bottomRow,
        Cube_rotateBottomSlicesRight,
        Cube_frontFace, bottomRow,
        "left face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateBottomSlicesRight_leftFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, equatorRow,
        Cube_rotateBottomSlicesRight,
        Cube_frontFace, equatorRow,
        "left face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateBottomSlicesRight_bottomFaceIsRotatedClockwise)
{
    test_face_rotated_clockwise(
        Cube_bottomFace,
        Cube_rotateBottomSlicesRight,
        "bottom face wasn't rotated");
}
