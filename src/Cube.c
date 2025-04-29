
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/Cube.h"

#include "Face.h"




/** The position of each Face in the T-shaped pattern of the unfolded cube */
typedef enum
{
	LEFT_FACE,
	FRONT_FACE,
	RIGHT_FACE,
	BOTTOM_FACE,
	BACK_FACE,
	TOP_FACE
} FacePosition;


typedef FacePosition Rotation[4];


/**
 * Coords of a 2D line
 *
 * One coord must be set to -1, i
 */
typedef struct
{
	FacePosition face;

	/**
	 * -1 if the line is a column
	 */
	Row row;

	/**
	 * -1 if the line is a row
	 */
	Column column;
} Line;


/** A 3D Slice is made of 4 2D Lines */
typedef Line Slice[4];


struct Cube
{
	Face * faces[6];
};




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
	FacePosition position;

	if ((this == NULL) || (* this == NULL))
		return;

	for (position = 0; position < 6; position++)
	{
		Face_delete(& (* this)->faces[position]);
		(* this)->faces[position] = NULL;
	}

	free(* this);
	* this = NULL;
}


static Face * getFace(Cube const * this, FacePosition position)
{
	return this->faces[position];
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


/**
 * @param this - the cube to rotate
 *
 * @param rotation - the rotation to apply
 */
static void rotateCube(Cube * this, Rotation rotation)
{
	Face * backupFace = this->faces[rotation[3]];

	this->faces[rotation[3]] = this->faces[rotation[2]];
	this->faces[rotation[2]] = this->faces[rotation[1]];
	this->faces[rotation[1]] = this->faces[rotation[0]];
	this->faces[rotation[0]] = backupFace;
}


void Cube_rotateLeft(Cube * this)
{
	Rotation rotation = { FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE };

	Face_rotateClockwise(Cube_leftFace(this));
	Face_rotateClockwise(Cube_leftFace(this));
	Face_rotateClockwise(Cube_bottomFace(this));
	Face_rotateClockwise(Cube_backFace(this));
	Face_rotateClockwise(Cube_backFace(this));
	Face_rotateAnticlockwise(Cube_topFace(this));

	rotateCube(this, rotation);
}


void Cube_rotateRight(Cube * this)
{
	Rotation rotation = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };

	Face_rotateAnticlockwise(Cube_rightFace(this));
	Face_rotateAnticlockwise(Cube_rightFace(this));
	Face_rotateAnticlockwise(Cube_bottomFace(this));
	Face_rotateAnticlockwise(Cube_backFace(this));
	Face_rotateAnticlockwise(Cube_backFace(this));
	Face_rotateClockwise(Cube_topFace(this));

	rotateCube(this, rotation);
}


void Cube_rotateUp(Cube * this)
{
	Rotation rotation = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };

	Face_rotateAnticlockwise(Cube_leftFace(this));
	Face_rotateClockwise(Cube_rightFace(this));

	rotateCube(this, rotation);
}


void Cube_rotateDown(Cube * this)
{
	Rotation rotation = { FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE };

	Face_rotateClockwise(Cube_leftFace(this));
	Face_rotateAnticlockwise(Cube_rightFace(this));

	rotateCube(this, rotation);
}


void Cube_rotateClockwise(Cube * this)
{
	Rotation rotation = { TOP_FACE, RIGHT_FACE, BOTTOM_FACE, LEFT_FACE };

	Face_rotateClockwise(Cube_leftFace(this));
	Face_rotateClockwise(Cube_frontFace(this));
	Face_rotateClockwise(Cube_rightFace(this));
	Face_rotateClockwise(Cube_bottomFace(this));
	Face_rotateAnticlockwise(Cube_backFace(this));
	Face_rotateClockwise(Cube_topFace(this));

	rotateCube(this, rotation);
}


void Cube_rotateAnticlockwise(Cube * this)
{
	Rotation rotation = { TOP_FACE, LEFT_FACE, BOTTOM_FACE, RIGHT_FACE };

	Face_rotateAnticlockwise(Cube_leftFace(this));
	Face_rotateAnticlockwise(Cube_frontFace(this));
	Face_rotateAnticlockwise(Cube_rightFace(this));
	Face_rotateAnticlockwise(Cube_bottomFace(this));
	Face_rotateClockwise(Cube_backFace(this));
	Face_rotateAnticlockwise(Cube_topFace(this));

	rotateCube(this, rotation);
}


/**
 * @param this - the cube to get a line from
 *
 * @param line - the coords of the line to read
 *
 * @param buffer - the buffer where to write the line
 */
static void getLine(Cube const * this, Line line, Color buffer[FACE_SIZE])
{
	int isRow = (line.column == (Column) -1);
	if (isRow)
		Face_copyRow(this->faces[line.face], buffer, line.row);
	else
		Face_copyColumn(this->faces[line.face], buffer, line.column);
}


/**
 * @param this - the cube to write a line to
 *
 * @param line - the coords of the line to write
 *
 * @param content - the content of the line to write
 */
static void setLine(Cube * this, Line line, Color content[FACE_SIZE])
{
	int isRow = (line.column == (Column) -1);
	if (isRow)
		Face_setRow(this->faces[line.face], content, line.row);
	else
		Face_setColumn(this->faces[line.face], content, line.column);
}


static void moveLine(Cube * this, Line from, Line to)
{
	Color line[FACE_SIZE];
	getLine(this, from, line);
	setLine(this, to, line);
}


/**
 * @param this - the cube containing the slice to turn
 *
 * @param slice - the slice to rotate
 */
static void turnSlice(Cube * this, Slice slice)
{
	int cycleIndex;

	Color lineBackup[FACE_SIZE];

	getLine(this, slice[3], lineBackup);

	for (cycleIndex = 3; cycleIndex > 0; cycleIndex--)
		moveLine(this, slice[cycleIndex - 1], slice[cycleIndex]);

	setLine(this, slice[0], lineBackup);
}


static void turnHorizontalSlice(Cube * this, Row row, Rotation rotation)
{
	int cycleIndex;
	Slice slice;

	for (cycleIndex = 0; cycleIndex < 4; cycleIndex++)
	{
		slice[cycleIndex].face = rotation[cycleIndex];

		/* because of how we unfold the cube, we have only 3 faces aligned
			horizontally, the back face get its destination coord flipped,
			the top row becomes the bottom row, and the bottom row becomes
			the top row, this has no effect for the equator row */
		if (rotation[cycleIndex] == BACK_FACE)
			slice[cycleIndex].row = 2 - row;
		else
			slice[cycleIndex].row = row;

		slice[cycleIndex].column = -1;
	}

	turnSlice(this, slice);
}


static void turnSliceLeft(Cube * this, Row row)
{
	Rotation rotation = { FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE };
	turnHorizontalSlice(this, row, rotation);
}


static void turnSliceRight(Cube * this, Row row)
{
	Rotation rotation = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };
	turnHorizontalSlice(this, row, rotation);
}


void Cube_turnTopSliceLeft(Cube * this)
{
	turnSliceLeft(this, TOP_ROW);
	Face_rotateClockwise(Cube_topFace(this));
}


void Cube_turnTopSliceRight(Cube * this)
{
	turnSliceRight(this, TOP_ROW);
	Face_rotateAnticlockwise(Cube_topFace(this));
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
	Face_rotateAnticlockwise(Cube_bottomFace(this));
}


void Cube_turnBottomSliceRight(Cube * this)
{
	turnSliceRight(this, BOTTOM_ROW);
	Face_rotateClockwise(Cube_bottomFace(this));
}


static void turnVerticalSlice(Cube * this, Column column, Rotation rotation)
{
	int cycleIndex;
	Slice slice;

	for (cycleIndex = 0; cycleIndex < 4; cycleIndex++)
	{
		slice[cycleIndex].face = rotation[cycleIndex];
		slice[cycleIndex].row = -1;
		slice[cycleIndex].column = column;
	}

	turnSlice(this, slice);
}


static void turnSliceUp(Cube * this, Column column)
{
	Rotation rotation = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };
	turnVerticalSlice(this, column, rotation);
}


static void turnSliceDown(Cube * this, Column column)
{
	Rotation rotation = { FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE };
	turnVerticalSlice(this, column, rotation);
}


void Cube_turnLeftSliceUp(Cube * this)
{
	turnSliceUp(this, LEFT_COLUMN);
	Face_rotateAnticlockwise(Cube_leftFace(this));
}


void Cube_turnLeftSliceDown(Cube * this)
{
	turnSliceDown(this, LEFT_COLUMN);
	Face_rotateClockwise(Cube_leftFace(this));
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
	Face_rotateClockwise(Cube_rightFace(this));
}


void Cube_turnRightSliceDown(Cube * this)
{
	turnSliceDown(this, RIGHT_COLUMN);
	Face_rotateAnticlockwise(Cube_rightFace(this));
}


void Cube_turnFrontSliceClockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN }
	};
	turnSlice(this, slice);
	Face_rotateClockwise(Cube_frontFace(this));
}


void Cube_turnFrontSliceAnticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN }
	};
	turnSlice(this, slice);
	Face_rotateAnticlockwise(Cube_frontFace(this));
}


void Cube_turnStandingSliceClockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN }
	};
	turnSlice(this, slice);
}


void Cube_turnStandingSliceAnticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN }
	};
	turnSlice(this, slice);
}


void Cube_turnBackSliceClockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN }
	};
	turnSlice(this, slice);
	Face_rotateAnticlockwise(Cube_backFace(this));
}


void Cube_turnBackSliceAnticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN }
	};
	turnSlice(this, slice);
	Face_rotateClockwise(Cube_backFace(this));
}
