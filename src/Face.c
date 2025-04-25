
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


static Color cell(Face const * this, int rowIndex, int columnIndex)
{
	return this->cells[rowIndex][columnIndex];
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

static void applyColorOnRow(Face * this, Color color, int rowIndex)
{
	int columnIndex;
	Color row[FACE_SIZE];

	for (columnIndex = LEFT_COLUMN; columnIndex <= RIGHT_COLUMN; columnIndex++)
		row[columnIndex] = color;

	Face_setRow(this, row, rowIndex);
}


static void applyColor(Face * this, Color color)
{
	int rowIndex;
	for (rowIndex = TOP_ROW; rowIndex <= BOTTOM_ROW; rowIndex++)
		applyColorOnRow(this, color, rowIndex);
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


void Face_copyRow(Face const * this, Color buffer[FACE_SIZE], int rowIndex)
{
	size_t rowSizeInBytes = FACE_SIZE * sizeof(this->cells[rowIndex][0]);
	memcpy(buffer, this->cells[rowIndex], rowSizeInBytes);
}

void Face_setRow(Face * face, Color row[FACE_SIZE], int rowIndex)
{
	size_t rowSizeInBytes = FACE_SIZE * sizeof(row[0]);
	memcpy(face->cells[rowIndex], row, rowSizeInBytes);
}


void Face_copyColumn(Face const * this, Color buffer[FACE_SIZE], int columnIndex)
{
	int rowIndex;
	for (rowIndex = TOP_ROW; rowIndex <= BOTTOM_ROW; rowIndex++)
		buffer[rowIndex] = this->cells[rowIndex][columnIndex];
}


void Face_setColumn(Face * face, Color column[FACE_SIZE], int columnIndex)
{
	int rowIndex;
	for (rowIndex = TOP_ROW; rowIndex <= BOTTOM_ROW; rowIndex++)
		face->cells[rowIndex][columnIndex] = column[rowIndex];
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


void Face_topRow(Face const * this, Color storage[FACE_SIZE])
{
	Face_copyRow(this, storage, TOP_ROW);
}


void Face_equatorRow(Face const * this, Color storage[FACE_SIZE])
{
	Face_copyRow(this, storage, EQUATOR_ROW);
}


void Face_bottomRow(Face const * this, Color storage[FACE_SIZE])
{
	Face_copyRow(this, storage, BOTTOM_ROW);
}


void Face_leftColumn(Face const * this, Color storage[FACE_SIZE])
{
	Face_copyColumn(this, storage, LEFT_COLUMN);
}


void Face_middleColumn(Face const * this, Color storage[FACE_SIZE])
{
	Face_copyColumn(this, storage, MIDDLE_COLUMN);
}


void Face_rightColumn(Face const * this, Color storage[FACE_SIZE])
{
	Face_copyColumn(this, storage, RIGHT_COLUMN);
}

/* --- Private API end --- */
