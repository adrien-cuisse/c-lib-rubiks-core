
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateBottomSlicesLeft_frontFaceBottomRow_movesTo_leftFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, bottomRow,
        Cube_rotateBottomSlicesLeft,
        Cube_leftFace, bottomRow,
        "front face bottom row wasn't moved to the left face bottom row");
}


Test(Cube, rotateBottomSlicesLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, equatorRow,
        Cube_rotateBottomSlicesLeft,
        Cube_leftFace, equatorRow,
        "front face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateBottomSlicesLeft_leftFaceBottomRow_movesTo_backFaceTopRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, bottomRow,
        Cube_rotateBottomSlicesLeft,
        Cube_backFace, topRow,
        "left face bottom row wasn't moved to the back face top row");
}


Test(Cube, rotateBottomSlicesLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, equatorRow,
        Cube_rotateBottomSlicesLeft,
        Cube_backFace, equatorRow,
        "left face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateBottomSlicesLeft_backFaceTopRow_movesTo_rightFaceBottomRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, topRow,
        Cube_rotateBottomSlicesLeft,
        Cube_rightFace, bottomRow,
        "back face top row wasn't moved to the right face bottom row");
}


Test(Cube, rotateBottomSlicesLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, equatorRow,
        Cube_rotateBottomSlicesLeft,
        Cube_rightFace, equatorRow,
        "back face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateBottomSlicesLeft_rightFaceBottomRow_movesTo_frontFaceBottomRow)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, bottomRow,
        Cube_rotateBottomSlicesLeft,
        Cube_frontFace, bottomRow,
        "right face bottom row wasn't moved to the front face bottom row");
}


Test(Cube, rotateBottomSlicesLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, equatorRow,
        Cube_rotateBottomSlicesLeft,
        Cube_frontFace, equatorRow,
        "right face equator row wasn't moved to the front face equator row");
}
