
#include <criterion/criterion.h>

#include "../../../../include/Cube.h"

#include "../../asserts.h"
#include "../../utils.h"




Test(Cube, rotateTopSlicesLeft_frontFaceTopRow_movesTo_leftFaceTopRow)
{
	test_span_moved_and_not_reversed(
		Cube_frontFace, topRow,
		Cube_rotateTopSlicesLeft,
		Cube_leftFace, topRow,
		"front face top row wasn't moved to the left face top row");
}


Test(Cube, rotateTopSlicesLeft_frontFaceEquatorRow_movesTo_leftFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		Cube_frontFace, equatorRow,
		Cube_rotateTopSlicesLeft,
		Cube_leftFace, equatorRow,
		"front face equator row wasn't moved to the left face equator row");
}


Test(Cube, rotateTopSlicesLeft_leftFaceTopRow_movesTo_backFaceBottomRow_reversed)
{
	test_span_moved_and_reversed(
		Cube_leftFace, topRow,
		Cube_rotateTopSlicesLeft,
		Cube_backFace, bottomRow,
		"left face top row wasn't moved to the back face bottom row");
}


Test(Cube, rotateTopSlicesLeft_leftFaceEquatorRow_movesTo_backFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		Cube_leftFace, equatorRow,
		Cube_rotateTopSlicesLeft,
		Cube_backFace, equatorRow,
		"left face equator row wasn't moved to the back face equator row");
}


Test(Cube, rotateTopSlicesLeft_backFaceBottomRow_movesTo_rightFaceTopRow_reversed)
{
	test_span_moved_and_reversed(
		Cube_backFace, bottomRow,
		Cube_rotateTopSlicesLeft,
		Cube_rightFace, topRow,
		"back face bottom row wasn't moved to the right face top row");
}


Test(Cube, rotateTopSlicesLeft_backFaceEquatorRow_movesTo_rightFaceEquatorRow_reversed)
{
	test_span_moved_and_reversed(
		Cube_backFace, equatorRow,
		Cube_rotateTopSlicesLeft,
		Cube_rightFace, equatorRow,
		"back face equator row wasn't moved to the right face equator row");
}


Test(Cube, rotateTopSlicesLeft_rightFaceTopRow_movesTo_frontFaceTopRow)
{
	test_span_moved_and_not_reversed(
		Cube_rightFace, topRow,
		Cube_rotateTopSlicesLeft,
		Cube_frontFace, topRow,
		"right face top row wasn't moved to the front face top row");
}


Test(Cube, rotateTopSlicesLeft_rightFaceEquatorRow_movesTo_frontFaceEquatorRow)
{
	test_span_moved_and_not_reversed(
		Cube_rightFace, equatorRow,
		Cube_rotateTopSlicesLeft,
		Cube_frontFace, equatorRow,
		"right face equator row wasn't moved to the front face equator row");
}


Test(Cube, rotateTopSlicesLeft_topFaceIsRotatedClockwise)
{
    test_face_rotated_clockwise(
        Cube_topFace,
        Cube_rotateTopSlicesLeft,
        "top face wasn't rotated");
}
