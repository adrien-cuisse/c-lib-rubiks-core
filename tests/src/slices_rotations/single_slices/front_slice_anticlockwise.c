
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateFrontSliceAnticlockwise_topFaceBottomRow_movesTo_leftFaceRightColumn)
{
    test_span_moved(
        Cube_topFace, bottomRow,
        Cube_rotateFrontSliceAnticlockwise,
        Cube_leftFace, rightColumn,
        "top face bottom row wasn't moved to the left face right column");
}


Test(Cube, rotateFrontSliceAnticlockwise_leftFaceRightColumn_movesTo_bottomFaceTopRow)
{
    test_span_moved(
        Cube_leftFace, rightColumn,
        Cube_rotateFrontSliceAnticlockwise,
        Cube_bottomFace, topRow,
        "left face right column wasn't moved to the bottom face top row");
}


Test(Cube, rotateFrontSliceAnticlockwise_bottomFaceTopRow_movesTo_rightFaceLeftColumn)
{
    test_span_moved(
        Cube_bottomFace, topRow,
        Cube_rotateFrontSliceAnticlockwise,
        Cube_rightFace, leftColumn,
        "bottom face top row wasn't moved to the right face left column");
}


Test(Cube, rotateFrontSliceAnticlockwise_rightFaceLeftColumn_movesTo_topFaceBottomRow)
{
    test_span_moved(
        Cube_rightFace, leftColumn,
        Cube_rotateFrontSliceAnticlockwise,
        Cube_topFace, bottomRow,
        "right face left column wasn't moved to the top face bottom row");
}


Test(Cube, rotateFrontSliceAnticlockwise_frontFaceIsRotatedAnticlockwise)
{
	// given
	Cube * cube = createScrambledCube();
	Face * frontFace = Cube_frontFace(cube);
	Color beforeRotation[FACE_SIZE][FACE_SIZE];
	readFace(frontFace, beforeRotation);

	// when
	Cube_rotateFrontSliceAnticlockwise(cube);

	// then
	assert_faceRotatedAnticlockwise(beforeRotation, frontFace, "front");
}


Test(Cube, rotateFrontSliceAnticlockwise_bottomFaceTopRow_movesTo_rightFaceLeftColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_bottomFace, topRow,
        Cube_rotateFrontSliceAnticlockwise,
        Cube_rightFace, leftColumn,
        "source span (bottom face top row) wasn't reversed");
}


Test(Cube, rotateFrontSliceAnticlockwise_topFaceBottomRow_movesTo_leftFaceRightColumn_reversed)
{
    test_span_moved_and_reversed(
        Cube_topFace, bottomRow,
        Cube_rotateFrontSliceAnticlockwise,
        Cube_leftFace, rightColumn,
        "source span (top face bottom row) wasn't reversed");
}


Test(Cube, rotateFrontSliceAnticlockwise_rightFaceLeftColumn_movesTo_topFaceBottomRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_rightFace, leftColumn,
        Cube_rotateFrontSliceAnticlockwise,
        Cube_topFace, bottomRow,
        "source span (right face left column) was reversed");
}


Test(Cube, rotateFrontSliceAnticlockwise_leftFaceRightColumn_movesTo_bottomFaceTopRow_notReversed)
{
    test_span_moved_and_not_reversed(
        Cube_leftFace, rightColumn,
        Cube_rotateFrontSliceAnticlockwise,
        Cube_bottomFace, topRow,
        "source span (left face right column) was reversed");
}
