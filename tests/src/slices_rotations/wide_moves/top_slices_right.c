
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateTopSlicesRight_frontFaceTopRow_movesTo_rightFaceTopRow)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, topRow,
        Cube_rotateTopSlicesRight,
        Cube_rightFace, topRow,
        "front face top row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSlicesRight_frontFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, equatorRow,
        Cube_rotateTopSlicesRight,
        Cube_rightFace, equatorRow,
        "front face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateTopSlicesRight_rightFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, topRow,
        Cube_rotateTopSlicesRight,
        Cube_backFace, bottomRow,
        "right face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSlicesRight_rightFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, equatorRow,
        Cube_rotateTopSlicesRight,
        Cube_backFace, equatorRow,
        "right face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateTopSlicesRight_backFaceBottomRow_movesTo_leftFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, bottomRow,
        Cube_rotateTopSlicesRight,
        Cube_leftFace, topRow,
        "back face bottom row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSlicesRight_backFaceEquatorRow_movesTo_leftFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, equatorRow,
        Cube_rotateTopSlicesRight,
        Cube_leftFace, equatorRow,
        "back face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateTopSlicesRight_leftFaceTopRow_movesTo_frontFaceTopRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, topRow,
        Cube_rotateTopSlicesRight,
        Cube_frontFace, topRow,
        "left face top row wasn't moved to the front face top row");
}


Test(Cube, rotateTopSlicesRight_leftFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, equatorRow,
        Cube_rotateTopSlicesRight,
        Cube_frontFace, equatorRow,
        "left face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateTopSlicesRight_topFaceIsRotatedAnticlockwise)
{
    test_face_rotated_anticlockwise(
        Cube_topFace,
        Cube_rotateTopSlicesRight,
        "top face wasn't rotated");
}
