
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateEquatorSliceRight_frontFaceEquatorRow_movesTo_rightFaceEquatorRow)
{
    test_span_moved(
        Cube_frontFace, equatorRow,
        Cube_rotateEquatorSliceRight,
        Cube_rightFace, equatorRow,
        "front face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateEquatorSliceRight_rightFaceEquatorRow_movesTo_backFaceEquatorRow)
{
    test_span_moved(
        Cube_rightFace, equatorRow,
        Cube_rotateEquatorSliceRight,
        Cube_backFace, equatorRow,
        "right face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateEquatorSliceRight_backFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
    test_span_moved(
        Cube_backFace, equatorRow,
        Cube_rotateEquatorSliceRight,
        Cube_leftFace, equatorRow,
        "back face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateEquatorSliceRight_leftFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
    test_span_moved(
        Cube_leftFace, equatorRow,
        Cube_rotateEquatorSliceRight,
        Cube_frontFace, equatorRow,
        "left face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateEquatorSliceRight_rightFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_rightFace, equatorRow,
        Cube_rotateEquatorSliceRight,
        Cube_backFace, equatorRow,
        "source span (right face equator row) wasn't reversed");
}


Test(Cube, rotateEquatorSliceRight_backFaceEquatorRow_movesTo_leftFaceEquatorRow_reversed)
{
    test_span_moved_and_reversed(
        Cube_backFace, equatorRow,
        Cube_rotateEquatorSliceRight,
        Cube_leftFace, equatorRow,
        "source span (back face equator row) wasn't reversed");
}


Test(Cube, rotateEquatorSliceRight_leftFaceEquatorRow_movesTo_frontFaceEquatorRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, equatorRow,
        Cube_rotateEquatorSliceRight,
        Cube_frontFace, equatorRow,
        "source span (left face equator row) was reversed");
}


Test(Cube, rotateEquatorSliceRight_frontFaceEquatorRow_movesTo_rightFaceEquatorRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, equatorRow,
        Cube_rotateEquatorSliceRight,
        Cube_rightFace, equatorRow,
        "source span (front face equator row) was reversed");
}
