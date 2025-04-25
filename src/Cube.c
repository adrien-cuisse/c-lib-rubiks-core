
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Cube.h"

#include "Face.h"


/** The slices composing the cube (Z axis), based on FACE_SIZE */
#define FRONT_SLICE 0
#define STANDING_SLICE 1
#define BACK_SLICE 2


/** The position of a cell in a row (X axis), based on FACE_SIZE */
#define LEFT_CELL 0
#define MIDDLE_CELL 1
#define RIGHT_CELL 2


/** The position of a cell in a column (Y axis), based on FACE_SIZE */
#define TOP_CELL 0
#define EQUATOR_CELL 1
#define BOTTOM_CELL 2


/** The position of each face in the T-shaped pattern of the unfolded cube */
#define LEFT_FACE 0
#define FRONT_FACE 1
#define RIGHT_FACE 2
#define BOTTOM_FACE 3
#define BACK_FACE 4
#define TOP_FACE 5




struct Cube
{
	Face * faces[6];
};




static void createAndPositionFaces(Cube * this);


static Face * getFace(Cube const * this, int faceIndex);


/**
 * @param this - the cube to rotate
 * @param faceIndexesCycle - the cycle of index of faces to move in the
 * 		unfolded pattern, the face at position cycle[i] will take the place of
 * 		the face at position cycle[i+1]
 * 		eg: {TOP_FACE, RIGHT_FACE, BOTTOM_FACE, LEFT_FACE}
 * 			will put TOP_FACE face where RIGHT_FACE face is
 */
static void rotateCube(Cube * this, int faceIndexesCycle[4]);


/**
 * @param face - the face to get a line from
 * @param storage - the buffer where to write the line
 * @param coords - [ordinate, abscissa],
 * 		one coord in range [0;FACE_SIZE[ and the other one set to -1, depending
 * 		if the line is a row or a column
 */
static void getLine(
	Face const * face,
	Color storage[FACE_SIZE],
	int coords[2]);


/**
 * @param face - the face to set a line to
 * @param storage - the line to set
 * @param coords - [ordinate, abscissa],
 * 		one coord in range [0;FACE_SIZE[ and the other one set to -1, depending
 * 		if the line is a row or a column
 */
static void setLine(
	Face * face,
	Color storage[FACE_SIZE],
	int coords[2]);


/**
 * @param this - the cube containing the slice to turn
 * @param linesCoordsCycle - 4 entries [face, ordinate, abscissa],
 * 		in each entry, either abscissa or ordinate must be set to -1, depending
 * 		if the line is a row or column, the other coord being the row/column
 * 		index in range [0;FACE_SIZE[
 * 		the line of each entry will be moved to the coord of the next entry
 */
static void turnSlice(Cube * this, int linesCoordsCycle[4][3]);


static void turnHorizontalSlice(Cube * this, int rowIndex, int cycle[4]);


static void turnSliceLeft(Cube * this, int rowIndex);


static void turnSliceRight(Cube * this, int rowIndex);


static void turnVerticalSlice(Cube * this, int columnIndex, int facesCycle[4]);


static void turnSliceUp(Cube * this, int columnIndex);


static void turnSliceDown(Cube * this, int columnIndex);




static void createAndPositionFaces(Cube * this)
{
	/*
	 * official disposition:
	 * - blue opposes green,
	 * - white opposes yellow,
	 * - red opposes orange,
	 * - blue, white & red are in anti-clockwise order around a corner
	 */
	this->faces[LEFT_FACE] = Face_create(RED);
	this->faces[FRONT_FACE] = Face_create(BLUE);
	this->faces[RIGHT_FACE] = Face_create(ORANGE);
	this->faces[TOP_FACE] = Face_create(WHITE);
	this->faces[BOTTOM_FACE] = Face_create(YELLOW);
	this->faces[BACK_FACE] = Face_create(GREEN);
}


Cube * Cube_create(void)
{
	Cube * this = calloc(1, sizeof(* this));
	if (this == NULL)
	{
		fputs("Cube allocation failed", stderr);
		exit(EXIT_FAILURE);
	}

	createAndPositionFaces(this);

	return this;
}


void Cube_delete(Cube ** this)
{
	int faceIndex;

	if ((this == NULL) || (* this == NULL))
		return;

	for (faceIndex = 0; faceIndex < 6; faceIndex++)
	{
		Face_delete(& (* this)->faces[faceIndex]);
		(* this)->faces[faceIndex] = NULL;
	};

	free(* this);
	* this = NULL;
}


static Face * getFace(Cube const * this, int faceIndex)
{
	return this->faces[faceIndex];
}


Face * Cube_leftFace(Cube const * this)
{
	return getFace(this, LEFT_FACE);
}


Face * Cube_frontFace(Cube const * this)
{
	return getFace(this, FRONT_FACE);
}


Face * Cube_rightFace(Cube const * this)
{
	return getFace(this, RIGHT_FACE);
}


Face * Cube_topFace(Cube const * this)
{
	return getFace(this, TOP_FACE);
}


Face * Cube_bottomFace(Cube const * this)
{
	return getFace(this, BOTTOM_FACE);
}


Face * Cube_backFace(Cube const * this)
{
	return getFace(this, BACK_FACE);
}


static void rotateCube(Cube * this, int faceIndexesCycle[4])
{
	Face * backupFace = this->faces[faceIndexesCycle[3]];

	this->faces[faceIndexesCycle[3]] = this->faces[faceIndexesCycle[2]];
	this->faces[faceIndexesCycle[2]] = this->faces[faceIndexesCycle[1]];
	this->faces[faceIndexesCycle[1]] = this->faces[faceIndexesCycle[0]];
	this->faces[faceIndexesCycle[0]] = backupFace;
}


void Cube_rotateLeft(Cube * this)
{
	int cycle[4] = { FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE };

	Face_rotateClockwise(Cube_leftFace(this));
	Face_rotateClockwise(Cube_leftFace(this));
	Face_rotateClockwise(Cube_bottomFace(this));
	Face_rotateClockwise(Cube_backFace(this));
	Face_rotateClockwise(Cube_backFace(this));
	Face_rotateAnticlockwise(Cube_topFace(this));

	rotateCube(this, cycle);
}


void Cube_rotateRight(Cube * this)
{
	int cycle[4] = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };

	Face_rotateAnticlockwise(Cube_rightFace(this));
	Face_rotateAnticlockwise(Cube_rightFace(this));
	Face_rotateAnticlockwise(Cube_bottomFace(this));
	Face_rotateAnticlockwise(Cube_backFace(this));
	Face_rotateAnticlockwise(Cube_backFace(this));
	Face_rotateClockwise(Cube_topFace(this));

	rotateCube(this, cycle);
}


void Cube_rotateUp(Cube * this)
{
	int cycle[4] = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };

	Face_rotateAnticlockwise(Cube_leftFace(this));
	Face_rotateClockwise(Cube_rightFace(this));

	rotateCube(this, cycle);
}


void Cube_rotateDown(Cube * this)
{
	int cycle[4] = { FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE };

	Face_rotateClockwise(Cube_leftFace(this));
	Face_rotateAnticlockwise(Cube_rightFace(this));

	rotateCube(this, cycle);
}


void Cube_rotateClockwise(Cube * this)
{
	int cycle[4] = { TOP_FACE, RIGHT_FACE, BOTTOM_FACE, LEFT_FACE };

	Face_rotateClockwise(Cube_leftFace(this));
	Face_rotateClockwise(Cube_frontFace(this));
	Face_rotateClockwise(Cube_rightFace(this));
	Face_rotateClockwise(Cube_bottomFace(this));
	Face_rotateAnticlockwise(Cube_backFace(this));
	Face_rotateClockwise(Cube_topFace(this));

	rotateCube(this, cycle);
}


void Cube_rotateAnticlockwise(Cube * this)
{
	int cycle[4] = { TOP_FACE, LEFT_FACE, BOTTOM_FACE, RIGHT_FACE };

	Face_rotateAnticlockwise(Cube_leftFace(this));
	Face_rotateAnticlockwise(Cube_frontFace(this));
	Face_rotateAnticlockwise(Cube_rightFace(this));
	Face_rotateAnticlockwise(Cube_bottomFace(this));
	Face_rotateClockwise(Cube_backFace(this));
	Face_rotateAnticlockwise(Cube_topFace(this));

	rotateCube(this, cycle);
}


static void getLine(
	Face const * face,
	Color storage[FACE_SIZE],
	int coords[2])
{
	int isRow = (coords[1] == -1);
	if (isRow)
		Face_copyRow(face, storage, coords[0]);
	else
		Face_copyColumn(face, storage, coords[1]);
}


static void setLine(
	Face * face,
	Color storage[FACE_SIZE],
	int coords[2])
{
	int isRow = (coords[1] == -1);
	if (isRow)
		Face_setRow(face, storage, coords[0]);
	else
		Face_setColumn(face, storage, coords[1]);
}


static void turnSlice(Cube * this, int linesCoordsCycle[4][3])
{
	int cycleIndex;

	Face * fromFace;
	Face * toFace;

	Color initialLineBackup[FACE_SIZE];
	Color line[FACE_SIZE];

	int * sourceCoords;
	int * destinationCoords;

	toFace = this->faces[linesCoordsCycle[3][0]];
	destinationCoords = & linesCoordsCycle[3][1];
	getLine(toFace, initialLineBackup, destinationCoords);

	for (cycleIndex = 3; cycleIndex > 0; cycleIndex--)
	{
		fromFace = this->faces[linesCoordsCycle[cycleIndex - 1][0]];
		sourceCoords = & linesCoordsCycle[cycleIndex - 1][1];
		getLine(fromFace, line, sourceCoords);

		setLine(toFace, line, destinationCoords);
		toFace = fromFace;
		destinationCoords = sourceCoords;
	}

	setLine(toFace, initialLineBackup, destinationCoords);
}


static void turnHorizontalSlice(Cube * this, int rowIndex, int facesCycle[4])
{
	int cycleIndex;
	int rowsCoordsCycle[4][3];

	for (cycleIndex = 0; cycleIndex < 4; cycleIndex++)
	{
		rowsCoordsCycle[cycleIndex][0] = facesCycle[cycleIndex];

		/* because of how we unfold the cube, we have only 3 faces aligned
			horizontally, the back face get its destination coord flipped,
			the top row becomes the bottom row, and the bottom row becomes
			the top row, this has no effect for the equator row */
		if (facesCycle[cycleIndex] == BACK_FACE)
			rowsCoordsCycle[cycleIndex][1] = 2 - rowIndex;
		else
			rowsCoordsCycle[cycleIndex][1] = rowIndex;

		rowsCoordsCycle[cycleIndex][2] = -1;
	}

	turnSlice(this, rowsCoordsCycle);
}


static void turnSliceLeft(Cube * this, int rowIndex)
{
	int facesCycle[] = { FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE };
	turnHorizontalSlice(this, rowIndex, facesCycle);
}


static void turnSliceRight(Cube * this, int rowIndex)
{
	int facesCycle[] = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };
	turnHorizontalSlice(this, rowIndex, facesCycle);
}


void Cube_turnTopSliceLeft(Cube * this)
{
	turnSliceLeft(this, TOP_ROW);
	Face_rotateClockwise(getFace(this, TOP_FACE));
}


void Cube_turnTopSliceRight(Cube * this)
{
	turnSliceRight(this, TOP_ROW);
	Face_rotateAnticlockwise(getFace(this, TOP_FACE));
}


void Cube_turnEquatorSliceLeft(Cube * this)
{
	turnSliceLeft(this, EQUATOR_ROW);
}


void Cube_turnEquatorSliceRight(Cube * this)
{
	turnSliceRight(this, EQUATOR_ROW);
}


void Cube_turnBottomSliceLeft(Cube * this)
{
	turnSliceLeft(this, BOTTOM_ROW);
	Face_rotateAnticlockwise(getFace(this, BOTTOM_FACE));
}


void Cube_turnBottomSliceRight(Cube * this)
{
	turnSliceRight(this, BOTTOM_ROW);
	Face_rotateClockwise(getFace(this, BOTTOM_FACE));
}


static void turnVerticalSlice(Cube * this, int columnIndex, int facesCycle[4])
{
	int cycleIndex;
	int columnsCoordsCycle[4][3];

	for (cycleIndex = 0; cycleIndex < 4; cycleIndex++)
	{
		columnsCoordsCycle[cycleIndex][0] = facesCycle[cycleIndex];
		columnsCoordsCycle[cycleIndex][1] = -1;
		columnsCoordsCycle[cycleIndex][2] = columnIndex;
	}

	turnSlice(this, columnsCoordsCycle);
}


static void turnSliceUp(Cube * this, int columnIndex)
{
	int facesCycle[] = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };
	turnVerticalSlice(this, columnIndex, facesCycle);
}


static void turnSliceDown(Cube * this, int columnIndex)
{
	int facesCycle[] = { FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE };
	turnVerticalSlice(this, columnIndex, facesCycle);
}


void Cube_turnLeftSliceUp(Cube * this)
{
	turnSliceUp(this, LEFT_COLUMN);
	Face_rotateAnticlockwise(getFace(this, LEFT_FACE));
}


void Cube_turnLeftSliceDown(Cube * this)
{
	turnSliceDown(this, LEFT_COLUMN);
	Face_rotateClockwise(getFace(this, LEFT_FACE));
}


void Cube_turnMiddleSliceUp(Cube * this)
{
	turnSliceUp(this, MIDDLE_COLUMN);
}


void Cube_turnMiddleSliceDown(Cube * this)
{
	turnSliceDown(this, MIDDLE_COLUMN);
}


void Cube_turnRightSliceUp(Cube * this)
{
	turnSliceUp(this, RIGHT_COLUMN);
	Face_rotateClockwise(getFace(this, RIGHT_FACE));
}


void Cube_turnRightSliceDown(Cube * this)
{
	turnSliceDown(this, RIGHT_COLUMN);
	Face_rotateAnticlockwise(getFace(this, RIGHT_FACE));
}


void Cube_turnFrontSliceClockwise(Cube * this)
{
	int linesCoordsCycle[4][3] =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN }
	};
	turnSlice(this, linesCoordsCycle);
	Face_rotateClockwise(getFace(this, FRONT_FACE));
}


void Cube_turnFrontSliceAnticlockwise(Cube * this)
{
	int linesCoordsCycle[4][3] =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN }
	};
	turnSlice(this, linesCoordsCycle);
	Face_rotateAnticlockwise(getFace(this, FRONT_FACE));
}


void Cube_turnStandingSliceClockwise(Cube * this)
{
	int linesCoordsCycle[4][3] =
	{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN }
	};
	turnSlice(this, linesCoordsCycle);
}


void Cube_turnStandingSliceAnticlockwise(Cube * this)
{
	int linesCoordsCycle[4][3] =
	{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN }
	};
	turnSlice(this, linesCoordsCycle);
}


void Cube_turnBackSliceClockwise(Cube * this)
{
	int linesCoordsCycle[4][3] =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN }
	};
	turnSlice(this, linesCoordsCycle);
	Face_rotateAnticlockwise(getFace(this, BACK_FACE));
}


void Cube_turnBackSliceAnticlockwise(Cube * this)
{
	int linesCoordsCycle[4][3] =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN }
	};
	turnSlice(this, linesCoordsCycle);
	Face_rotateClockwise(getFace(this, BACK_FACE));
}
