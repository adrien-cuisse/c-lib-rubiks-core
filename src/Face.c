
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Face.h"




struct Face
{
	Color cells[FACE_SIZE][FACE_SIZE];
};




/* --- Public API start --- */

Color Face_color(Face const * this)
{
	/* center cells are fixed */
	return Face_equatorCenterCell(this);
}


static Color cell(Face const * this, Row row, Column column)
{
	return this->cells[row][column];
}


Color Face_topLeftCell(Face const * this)
{
	return cell(this, TOP_ROW, LEFT_COLUMN);
}


Color Face_topCenterCell(Face const * this)
{
	return cell(this, TOP_ROW, MIDDLE_COLUMN);
}


Color Face_topRightCell(Face const * this)
{
	return cell(this, TOP_ROW, RIGHT_COLUMN);
}


Color Face_equatorLeftCell(Face const * this)
{
	return cell(this, EQUATOR_ROW, LEFT_COLUMN);
}


Color Face_equatorCenterCell(Face const * this)
{
	return cell(this, EQUATOR_ROW, MIDDLE_COLUMN);
}


Color Face_equatorRightCell(Face const * this)
{
	return cell(this, EQUATOR_ROW, RIGHT_COLUMN);
}


Color Face_bottomLeftCell(Face const * this)
{
	return cell(this, BOTTOM_ROW, LEFT_COLUMN);
}


Color Face_bottomCenterCell(Face const * this)
{
	return cell(this, BOTTOM_ROW, MIDDLE_COLUMN);
}


Color Face_bottomRightCell(Face const * this)
{
	return cell(this, BOTTOM_ROW, RIGHT_COLUMN);
}

/* --- Public API end --- */




/* --- Private API start --- */

static void applyColorOnRow(Face * this, Color color, Row row)
{
	int columnIndex;
	Color cells[FACE_SIZE];

	for (columnIndex = LEFT_COLUMN; columnIndex <= RIGHT_COLUMN; columnIndex++)
		cells[columnIndex] = color;

	Face_setRow(this, cells, row);
}


static void applyColor(Face * this, Color color)
{
	Row row;
	for (row = TOP_ROW; row <= BOTTOM_ROW; row++)
		applyColorOnRow(this, color, row);
}


Face * Face_create(Color color)
{
	Face * this = calloc(1, sizeof(* this));
	if (this == NULL)
	{
		fputs("Face allocation failed", stderr);
		exit(EXIT_FAILURE);
	}

	applyColor(this, color);

	return this;
}


void Face_delete(Face ** this)
{
	if ((this == NULL) || (* this == NULL))
		return;

	free(* this);
	* this = NULL;
}


void Face_copyRow(Face const * this, Color buffer[FACE_SIZE], Row row)
{
	size_t rowSizeInBytes = FACE_SIZE * sizeof(this->cells[row][0]);
	memcpy(buffer, this->cells[row], rowSizeInBytes);
}


void Face_setRow(Face * face, Color const cells[FACE_SIZE], Row row)
{
	size_t rowSizeInBytes = FACE_SIZE * sizeof(cells[0]);
	memcpy(face->cells[row], cells, rowSizeInBytes);
}


void Face_copyColumn(Face const * this, Color buffer[FACE_SIZE], Column column)
{
	Row row;
	for (row = TOP_ROW; row <= BOTTOM_ROW; row++)
		buffer[row] = this->cells[row][column];
}


void Face_setColumn(Face * face, Color const cells[FACE_SIZE], Column column)
{
	Row row;
	for (row = TOP_ROW; row <= BOTTOM_ROW; row++)
		face->cells[row][column] = cells[row];
}


void Face_rotateClockwise(Face * this)
{
	Color newRightColumn[FACE_SIZE];
	Color newMiddleColumn[FACE_SIZE];
	Color newLeftColumn[FACE_SIZE];

	Face_copyRow(this, newRightColumn, TOP_ROW);
	Face_copyRow(this, newMiddleColumn, EQUATOR_ROW);
	Face_copyRow(this, newLeftColumn, BOTTOM_ROW);

	Face_setColumn(this, newRightColumn, RIGHT_COLUMN);
	Face_setColumn(this, newMiddleColumn, MIDDLE_COLUMN);
	Face_setColumn(this, newLeftColumn, LEFT_COLUMN);
}


void Face_rotateAnticlockwise(Face * this)
{
	Color newTopRow[FACE_SIZE];
	Color newEquatorRow[FACE_SIZE];
	Color newBottomRow[FACE_SIZE];

	Face_copyColumn(this, newTopRow, RIGHT_COLUMN);
	Face_copyColumn(this, newEquatorRow, MIDDLE_COLUMN);
	Face_copyColumn(this, newBottomRow, LEFT_COLUMN);

	Face_setRow(this, newTopRow, TOP_ROW);
	Face_setRow(this, newEquatorRow, EQUATOR_ROW);
	Face_setRow(this, newBottomRow, BOTTOM_ROW);
}

/* --- Private API end --- */
