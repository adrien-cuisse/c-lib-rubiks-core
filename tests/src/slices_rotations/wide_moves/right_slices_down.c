
#include "../../asserts.h"
#include "../../utils.h"

#include <criterion/criterion.h>




Test(Cube, rotateRightSlicesDown_frontFaceRightColumn_movesTo_bottomFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, right_column,
		rubiks_cube_rotate_right_slices_down,
		rubiks_cube_bottom_face, right_column,
		"front face right column wasn't moved to the bottom face right column");
}


Test(Cube, rotateRightSlicesDown_frontFaceMiddleColumn_movesTo_bottomFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_front_face, middle_column,
		rubiks_cube_rotate_right_slices_down,
		rubiks_cube_bottom_face, middle_column,
		"front face middle column wasn't moved to the bottom face middle column");
}


Test(Cube, rotateRightSlicesDown_bottomFaceRightColumn_movesTo_backFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, right_column,
		rubiks_cube_rotate_right_slices_down,
		rubiks_cube_back_face, right_column,
		"bottom face right column wasn't moved to the back face right column");
}


Test(Cube, rotateRightSlicesDown_bottomFaceMiddleColumn_movesTo_backFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_bottom_face, middle_column,
		rubiks_cube_rotate_right_slices_down,
		rubiks_cube_back_face, middle_column,
		"bottom face middle column wasn't moved to the back face middle column");
}


Test(Cube, rotateRightSlicesDown_backFaceRightColumn_movesTo_topFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_back_face, right_column,
		rubiks_cube_rotate_right_slices_down,
		rubiks_cube_top_face, right_column,
		"back face right column wasn't moved to the top face right column");
}


Test(Cube, rotateRightSlicesDown_backFaceMiddleColumn_movesTo_topFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_back_face, middle_column,
		rubiks_cube_rotate_right_slices_down,
		rubiks_cube_top_face, middle_column,
		"back face middle column wasn't moved to the top face middle column");
}


Test(Cube, rotateRightSlicesDown_topFaceRightColumn_movesTo_frontFaceRightColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, right_column,
		rubiks_cube_rotate_right_slices_down,
		rubiks_cube_front_face, right_column,
		"top face right column wasn't moved to the front face right column");
}


Test(Cube, rotateRightSlicesDown_topFaceMiddleColumn_movesTo_frontFaceMiddleColumn)
{
	test_span_moved_and_not_reversed(
		rubiks_cube_top_face, middle_column,
		rubiks_cube_rotate_right_slices_down,
		rubiks_cube_front_face, middle_column,
		"top face middle column wasn't moved to the front face middle column");
}


Test(Cube, rotateRightSlicesDown_rightFaceIsRotatedAnticlockwise)
{
	test_face_rotated_anticlockwise(
		rubiks_cube_right_face,
		rubiks_cube_rotate_right_slices_down,
		"right face wasn't rotated");
}
