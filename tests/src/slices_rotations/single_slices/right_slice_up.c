
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateRightSliceUp_frontFaceRightColumn_movesTo_topFaceRightColumn)
{
    test_span_moved(
        Cube_frontFace, rightColumn,
        Cube_rotateRightSliceUp,
        Cube_topFace, rightColumn,
        "front face right column wasn't moved to the top face right column");
}


Test(Cube, rotateRightSliceUp_topFaceRightColumn_movesTo_backFaceRightColumn)
{
    test_span_moved(
        Cube_topFace, rightColumn,
        Cube_rotateRightSliceUp,
        Cube_backFace, rightColumn,
        "top face right column wasn't moved to the back face right column");
}


Test(Cube, rotateRightSliceUp_backFaceRightColumn_movesTo_bottomFaceRightColumn)
{
    test_span_moved(
        Cube_backFace, rightColumn,
        Cube_rotateRightSliceUp,
        Cube_bottomFace, rightColumn,
        "back face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateRightSliceUp_bottomFaceRightColumn_movesTo_frontFaceRightColumn)
{
    test_span_moved(
        Cube_bottomFace, rightColumn,
        Cube_rotateRightSliceUp,
        Cube_frontFace, rightColumn,
        "bottom face right column wasn't moved to the front face right column");
}


Test(Cube, rotateRightSliceUp_rightFaceIsRotatedClockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, beforeRotation);

	// when
	Cube_rotateRightSliceUp(cube);

	// then
	assert_faceRotatedClockwise(beforeRotation, rightFace, "right");
}


Test(Cube, rotateRightSliceUp_frontFaceRightColumn_movesTo_topFaceRightColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, rightColumn,
        Cube_rotateRightSliceUp,
        Cube_topFace, rightColumn,
        "source span (front face right column) was reversed");
}


Test(Cube, rotateRightSliceUp_topFaceRightColumn_movesTo_backFaceRightColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, rightColumn,
        Cube_rotateRightSliceUp,
        Cube_backFace, rightColumn,
        "source span (top face right column) was reversed");
}


Test(Cube, rotateRightSliceUp_backFaceRightColumn_movesTo_bottomFaceRightColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, rightColumn,
        Cube_rotateRightSliceUp,
        Cube_bottomFace, rightColumn,
        "source span (back face right column) was reversed");
}


Test(Cube, rotateRightSliceUp_bottomFaceRightColumn_movesTo_frontFaceRightColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, rightColumn,
        Cube_rotateRightSliceUp,
        Cube_frontFace, rightColumn,
        "source span (bottom face right column) was reversed");
}
