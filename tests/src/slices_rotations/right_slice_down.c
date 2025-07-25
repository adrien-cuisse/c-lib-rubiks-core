
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateRightSliceDown_frontFaceRightColumn_movesTo_bottomFaceRightColumn)
{
    test_span_moved(
        Cube_frontFace, rightColumn,
        Cube_rotateRightSliceDown,
        Cube_bottomFace, rightColumn,
        "front face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateRightSliceDown_bottomFaceRightColumn_movesTo_backFaceRightColumn)
{
    test_span_moved(
        Cube_bottomFace, rightColumn,
        Cube_rotateRightSliceDown,
        Cube_backFace, rightColumn,
        "bottom face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateRightSliceDown_backFaceRightColumn_movesTo_topFaceRightColumn)
{
    test_span_moved(
        Cube_backFace, rightColumn,
        Cube_rotateRightSliceDown,
        Cube_topFace, rightColumn,
        "back face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateRightSliceDown_topFaceRightColumn_movesTo_frontFaceRightColumn)
{
    test_span_moved(
        Cube_topFace, rightColumn,
        Cube_rotateRightSliceDown,
        Cube_frontFace, rightColumn,
        "top face middle column wasn't moved to the front face middle column");
}


Test(Cube, rotateRightSliceDown_rightFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * rightFace = Cube_rightFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(rightFace, beforeRotation);

	// when
	Cube_rotateRightSliceDown(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, rightFace, "right");
}


Test(Cube, rotateRightSliceDown_frontFaceRightColumn_movesTo_bottomFaceRightColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, rightColumn,
        Cube_rotateRightSliceDown,
        Cube_bottomFace, rightColumn,
        "source span (front face right column) was reversed");
}


Test(Cube, rotateRightSliceDown_bottomFaceRightColumn_movesTo_backFaceRightColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, rightColumn,
        Cube_rotateRightSliceDown,
        Cube_backFace, rightColumn,
        "source span (bottom face right column) was reversed");
}


Test(Cube, rotateRightSliceDown_backFaceRightColumn_movesTo_topFaceRightColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, rightColumn,
        Cube_rotateRightSliceDown,
        Cube_topFace, rightColumn,
        "source span (back face right column) was reversed");
}


Test(Cube, rotateRightSliceDown_topFaceRightColumn_movesTo_frontFaceRightColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, rightColumn,
        Cube_rotateRightSliceDown,
        Cube_frontFace, rightColumn,
        "source span (top face right column) was reversed");
}
