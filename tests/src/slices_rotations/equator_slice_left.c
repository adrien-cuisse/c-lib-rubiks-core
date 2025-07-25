
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateEquatorSliceLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
    test_span_moved(
        Cube_frontFace, equatorRow,
        Cube_rotateEquatorSliceLeft,
        Cube_leftFace, equatorRow,
        "front face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateEquatorSliceLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow)
{
    test_span_moved(
        Cube_leftFace, equatorRow,
        Cube_rotateEquatorSliceLeft,
        Cube_backFace, equatorRow,
        "left face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateEquatorSliceLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
    test_span_moved(
        Cube_backFace, equatorRow,
        Cube_rotateEquatorSliceLeft,
        Cube_rightFace, equatorRow,
        "back face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateEquatorSliceLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
    test_span_moved(
        Cube_rightFace, equatorRow,
        Cube_rotateEquatorSliceLeft,
        Cube_frontFace, equatorRow,
        "right face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateEquatorSliceLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_leftFace, equatorRow,
        Cube_rotateEquatorSliceLeft,
        Cube_backFace, equatorRow,
        "source span (left face equator row) wasn't reversed");
}


Test(Cube, rotateEquatorSliceLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, equatorRow,
        Cube_rotateEquatorSliceLeft,
        Cube_rightFace, equatorRow,
        "source span (back face equator row) wasn't reversed");
}


Test(Cube, rotateEquatorSliceLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, equatorRow,
        Cube_rotateEquatorSliceLeft,
        Cube_frontFace, equatorRow,
        "source span (right face equator row) was reversed");
}


Test(Cube, rotateEquatorSliceLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, equatorRow,
        Cube_rotateEquatorSliceLeft,
        Cube_leftFace, equatorRow,
        "source span (front face equator row) was reversed");
}
