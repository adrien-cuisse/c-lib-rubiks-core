
#include <stdio.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "../../src/Face.h"

// The color of a cell on the face, but the actual value doesn't matter
#define ANY_COLOR 42




Test(Face, create_allocatesMemory)
{
	// given
	Face * allocatedMemory = Face_create(0);
	// when
	// then
	cr_assert_not_null(allocatedMemory, "no memory was allocated");
}


Test(Face, delete_deallocatesMemory)
{
	// given
	Face * allocatedMemory = Face_create(0);
	// when
	Face_delete(& allocatedMemory);
	// then
	cr_assert_null(allocatedMemory, "memory was not deallocated");
}


Test(Face, create_topLeftCellHasGivenColor)
{
	// given
	Face * face = Face_create(ANY_COLOR);
	// when
	// then
	Color topLeftColor = Face_topLeftCell(face);
	cr_assert_eq(ANY_COLOR, topLeftColor, "top left cell has wrong color");
}


Test(Face, create_topCenterCellHasGivenColor)
{
	// given
	Face * face = Face_create(ANY_COLOR);
	// when
	// then
	Color topCenterColor = Face_topCenterCell(face);
	cr_assert_eq(ANY_COLOR, topCenterColor, "top center cell has wrong color");
}


Test(Face, create_topRightCellHasGivenColor)
{
	// given
	Face * face = Face_create(ANY_COLOR);
	// when
	// then
	Color topRightColor = Face_topRightCell(face);
	cr_assert_eq(ANY_COLOR, topRightColor, "top right cell has wrong color");
}


Test(Face, create_equatorLeftCellHasGivenColor)
{
	// given
	Face * face = Face_create(ANY_COLOR);
	// when
	// then
	Color equatorLeftColor = Face_equatorLeftCell(face);
	cr_assert_eq(ANY_COLOR, equatorLeftColor, "equator left cell has wrong color");
}


Test(Face, create_equatorCenterCellHasGivenColor)
{
	// given
	Face * face = Face_create(ANY_COLOR);
	// when
	// then
	Color equatorCenterColor = Face_equatorCenterCell(face);
	cr_assert_eq(ANY_COLOR, equatorCenterColor, "equator center cell has wrong color");
}


Test(Face, create_equatorRightCellHasGivenColor)
{
	// given
	Face * face = Face_create(ANY_COLOR);
	// when
	// then
	Color equatorRightColor = Face_equatorRightCell(face);
	cr_assert_eq(ANY_COLOR, equatorRightColor, "equator right cell has wrong color");
}


Test(Face, create_bottomLeftCellHasGivenColor)
{
	// given
	Face * face = Face_create(ANY_COLOR);
	// when
	// then
	Color bottomLeftColor = Face_bottomLeftCell(face);
	cr_assert_eq(ANY_COLOR, bottomLeftColor, "bottom left cell has wrong color");
}


Test(Face, create_bottomCenterCellHasGivenColor)
{
	// given
	Face * face = Face_create(ANY_COLOR);
	// when
	// then
	Color bottomCenterColor = Face_bottomCenterCell(face);
	cr_assert_eq(ANY_COLOR, bottomCenterColor, "bottom center cell has wrong color");
}


Test(Face, create_bottomRightCellHasGivenColor)
{
	// given
	Face * face = Face_create(ANY_COLOR);
	// when
	// then
	Color bottomRightColor = Face_bottomRightCell(face);
	cr_assert_eq(ANY_COLOR, bottomRightColor, "bottom right cell has wrong color");
}
