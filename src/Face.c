
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Color.h"
#include "Face.h"


/** The 3 horizontal slices composing the face (Y axis) */
#define TOP_SLICE 0
#define MIDDLE_SLICE 1
#define BOTTOM_SLICE 2


/** The position of a cell in a slice (X axis) */
#define LEFT 0
#define CENTER 1
#define RIGHT 2




struct Face
{
	Color cells[3][3];
};




static Face * createFace(Color color);


static void deleteFace(Face ** this);


static Color getColor(Face const * this);


static Color getTopLeftCell(Face const * this);


static Color getTopCenterCell(Face const * this);


static Color getTopRightCell(Face const * this);


static Color getMiddleLeftCell(Face const * this);


static Color getMiddleCenterCell(Face const * this);


static Color getMiddleRightCell(Face const * this);


static Color getBottomLeftCell(Face const * this);


static Color getBottomCenterCell(Face const * this);


static Color getBottomRightCell(Face const * this);


static void paintSlice(Face * const this, int sliceIndex, Color color)
{
	int cellIndex;

	for (cellIndex = LEFT; cellIndex <= RIGHT; cellIndex++)
			this->cells[sliceIndex][cellIndex] = color;
}


static void paintSlices(Face * const this, Color color)
{
	int sliceIndex;

	for (sliceIndex = TOP_SLICE; sliceIndex <= BOTTOM_SLICE; sliceIndex++)
		paintSlice(this, sliceIndex, color);
}


static Face * createFace(Color color)
{
	Face * this = calloc(1, sizeof(* this));
	if (this == NULL)
	{
		fputs("Face allocation failed", stderr);
		exit(EXIT_FAILURE);
	}

	paintSlices(this, color);

	return this;
}


static void deleteFace(Face ** this)
{
	if ((this == NULL) || (* this == NULL))
		return;

	free(* this);
	* this = NULL;
}


static Color getColor(Face const * const this)
{
	/* center cells are fixed */
	return getMiddleCenterCell(this);
}


static Color getTopLeftCell(Face const * const this)
{
	return this->cells[TOP_SLICE][LEFT];
}


static Color getTopCenterCell(Face const * const this)
{
	return this->cells[TOP_SLICE][CENTER];
}


static Color getTopRightCell(Face const * const this)
{
	return this->cells[TOP_SLICE][RIGHT];
}


static Color getMiddleLeftCell(Face const * const this)
{
	return this->cells[MIDDLE_SLICE][LEFT];
}


static Color getMiddleCenterCell(Face const * const this)
{
	return this->cells[MIDDLE_SLICE][CENTER];
}


static Color getMiddleRightCell(Face const * const this)
{
	return this->cells[MIDDLE_SLICE][RIGHT];
}


static Color getBottomLeftCell(Face const * const this)
{
	return this->cells[BOTTOM_SLICE][LEFT];
}


static Color getBottomCenterCell(Face const * const this)
{
	return this->cells[BOTTOM_SLICE][CENTER];
}


static Color getBottomRightCell(Face const * const this)
{
	return this->cells[BOTTOM_SLICE][RIGHT];
}




static FaceMethods methods =
{
	createFace,
	deleteFace,
	getColor,
	getTopLeftCell,
	getTopCenterCell,
	getTopRightCell,
	getMiddleLeftCell,
	getMiddleCenterCell,
	getMiddleRightCell,
	getBottomLeftCell,
	getBottomCenterCell,
	getBottomRightCell
};
FaceMethods const * const _Face = & methods;
