
#include <stdio.h>

#include <criterion/criterion.h>
#include <criterion/parameterized.h>

#include "../../src/Face.h"

// The color of a cell on the face, but the actual value doesn't matter
#define ANY_COLOR 42




Test(Face, create_allocatesMemory)
{
	// given
	Face * allocatedMemory = _Face->create(0);
	// when
	// then
	cr_assert_not_null(allocatedMemory, "no memory was allocated");
}


Test(Face, delete_deallocatesMemory)
{
	// given
	Face * allocatedMemory = _Face->create(0);
	// when
	_Face->delete(& allocatedMemory);
	// then
	cr_assert_null(allocatedMemory, "memory was not deallocated");
}


Test(Face, create_topLeftCellHasGivenColor)
{
	// given
	Face * face = _Face->create(ANY_COLOR);
	// when
	// then
	Color topLeftColor = _Face->topLeftCell(face);
	cr_assert_eq(ANY_COLOR, topLeftColor, "top left cell has wrong color");
}


Test(Face, create_topCenterCellHasGivenColor)
{
	// given
	Face * face = _Face->create(ANY_COLOR);
	// when
	// then
	Color topCenterColor = _Face->topCenterCell(face);
	cr_assert_eq(ANY_COLOR, topCenterColor, "top center cell has wrong color");
}


Test(Face, create_topRightCellHasGivenColor)
{
	// given
	Face * face = _Face->create(ANY_COLOR);
	// when
	// then
	Color topRightColor = _Face->topRightCell(face);
	cr_assert_eq(ANY_COLOR, topRightColor, "top right cell has wrong color");
}


Test(Face, create_equatorLeftCellHasGivenColor)
{
	// given
	Face * face = _Face->create(ANY_COLOR);
	// when
	// then
	Color equatorLeftColor = _Face->equatorLeftCell(face);
	cr_assert_eq(ANY_COLOR, equatorLeftColor, "equator left cell has wrong color");
}


Test(Face, create_equatorCenterCellHasGivenColor)
{
	// given
	Face * face = _Face->create(ANY_COLOR);
	// when
	// then
	Color equatorCenterColor = _Face->equatorCenterCell(face);
	cr_assert_eq(ANY_COLOR, equatorCenterColor, "equator center cell has wrong color");
}


Test(Face, create_equatorRightCellHasGivenColor)
{
	// given
	Face * face = _Face->create(ANY_COLOR);
	// when
	// then
	Color equatorRightColor = _Face->equatorRightCell(face);
	cr_assert_eq(ANY_COLOR, equatorRightColor, "equator right cell has wrong color");
}


Test(Face, create_bottomLeftCellHasGivenColor)
{
	// given
	Face * face = _Face->create(ANY_COLOR);
	// when
	// then
	Color bottomLeftColor = _Face->bottomLeftCell(face);
	cr_assert_eq(ANY_COLOR, bottomLeftColor, "bottom left cell has wrong color");
}


Test(Face, create_bottomCenterCellHasGivenColor)
{
	// given
	Face * face = _Face->create(ANY_COLOR);
	// when
	// then
	Color bottomCenterColor = _Face->bottomCenterCell(face);
	cr_assert_eq(ANY_COLOR, bottomCenterColor, "bottom center cell has wrong color");
}


Test(Face, create_bottomRightCellHasGivenColor)
{
	// given
	Face * face = _Face->create(ANY_COLOR);
	// when
	// then
	Color bottomRightColor = _Face->bottomRightCell(face);
	cr_assert_eq(ANY_COLOR, bottomRightColor, "bottom right cell has wrong color");
}
