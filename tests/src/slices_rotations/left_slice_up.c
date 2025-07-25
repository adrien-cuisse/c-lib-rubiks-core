
#include <criterion/criterion.h>

#include "../../../include/Cube.h"

#include "../asserts.h"
#include "../utils.h"




Test(Cube, rotateLeftSliceUp_frontFaceLeftColumn_movesTo_topFaceLeftColumn)
{
    test_span_moved(
        Cube_frontFace, leftColumn,
        Cube_rotateLeftSliceUp,
        Cube_topFace, leftColumn,
        "front face left column wasn't moved to the top face left column");
}


Test(Cube, rotateLeftSliceUp_topFaceLeftColumn_movesTo_backFaceLeftColumn)
{
    test_span_moved(
        Cube_topFace, leftColumn,
        Cube_rotateLeftSliceUp,
        Cube_backFace, leftColumn,
        "top face left column wasn't moved to the back face left column");
}


Test(Cube, rotateLeftSliceUp_backFaceLeftColumn_movesTo_bottomFaceLeftColumn)
{
    test_span_moved(
        Cube_backFace, leftColumn,
        Cube_rotateLeftSliceUp,
        Cube_bottomFace, leftColumn,
        "back face left column wasn't moved to the bottom face left column");
}


Test(Cube, rotateLeftSliceUp_bottomFaceLeftColumn_movesTo_frontFaceLeftColumn)
{
    test_span_moved(
        Cube_bottomFace, leftColumn,
        Cube_rotateLeftSliceUp,
        Cube_frontFace, leftColumn,
        "bottom face left column wasn't moved to the front face left column");
}


Test(Cube, rotateLeftSliceUp_leftFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * leftFace = Cube_leftFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(leftFace, beforeRotation);

	// when
	Cube_rotateLeftSliceUp(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, leftFace, "left");
}


Test(Cube, rotateLeftSliceUp_frontFaceLeftColumn_movesTo_topFaceLeftColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_frontFace, leftColumn,
        Cube_rotateLeftSliceUp,
        Cube_topFace, leftColumn,
        "source span (front face left column) was reversed");
}


Test(Cube, rotateLeftSliceUp_topFaceLeftColumn_movesTo_backFaceLeftColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_topFace, leftColumn,
        Cube_rotateLeftSliceUp,
        Cube_backFace, leftColumn,
        "source span (top face left column) was reversed");
}


Test(Cube, rotateLeftSliceUp_backFaceLeftColumn_movesTo_bottomFaceLeftColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_backFace, leftColumn,
        Cube_rotateLeftSliceUp,
        Cube_bottomFace, leftColumn,
        "source span (back face left column) was reversed");
}


Test(Cube, rotateLeftSliceUp_bottomFaceLeftColumn_movesTo_frontFaceLeftColumn_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_bottomFace, leftColumn,
        Cube_rotateLeftSliceUp,
        Cube_frontFace, leftColumn,
        "source span (bottom face left column) was reversed");
}
