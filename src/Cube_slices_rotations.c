
#include "Face.h"
#include "Cube.h"




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
 * @param this - the cube containing the slice to rotate
 *
 * @param slice - the slice to rotate
 */
static void rotateSlice(Cube * this, Slice slice)
{
	int cycleIndex;

	Color lineBackup[FACE_SIZE];

	getLine(this, slice[3], lineBackup);

	for (cycleIndex = 3; cycleIndex > 0; cycleIndex--)
		moveLine(this, slice[cycleIndex - 1], slice[cycleIndex]);

	setLine(this, slice[0], lineBackup);
}


static void rotateHorizontalSlice(Cube * this, Row row, Rotation rotation)
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

	rotateSlice(this, slice);
}


static void rotateSliceLeft(Cube * this, Row row)
{
	Rotation rotation = { FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE };
	rotateHorizontalSlice(this, row, rotation);
}


static void rotateSliceRight(Cube * this, Row row)
{
	Rotation rotation = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };
	rotateHorizontalSlice(this, row, rotation);
}


void Cube_rotateTopSliceLeft(Cube * this)
{
	rotateSliceLeft(this, TOP_ROW);
	Face_rotateClockwise(Cube_topFace(this));
}


void Cube_rotateTopSliceRight(Cube * this)
{
	rotateSliceRight(this, TOP_ROW);
	Face_rotateAnticlockwise(Cube_topFace(this));
}


void Cube_rotateEquatorSliceLeft(Cube * this)
{
	rotateSliceLeft(this, EQUATOR_ROW);
}


void Cube_rotateEquatorSliceRight(Cube * this)
{
	rotateSliceRight(this, EQUATOR_ROW);
}


void Cube_rotateBottomSliceLeft(Cube * this)
{
	rotateSliceLeft(this, BOTTOM_ROW);
	Face_rotateAnticlockwise(Cube_bottomFace(this));
}


void Cube_rotateBottomSliceRight(Cube * this)
{
	rotateSliceRight(this, BOTTOM_ROW);
	Face_rotateClockwise(Cube_bottomFace(this));
}


static void rotateVerticalSlice(Cube * this, Column column, Rotation rotation)
{
	int cycleIndex;
	Slice slice;

	for (cycleIndex = 0; cycleIndex < 4; cycleIndex++)
	{
		slice[cycleIndex].face = rotation[cycleIndex];
		slice[cycleIndex].row = -1;
		slice[cycleIndex].column = column;
	}

	rotateSlice(this, slice);
}


static void rotateSliceUp(Cube * this, Column column)
{
	Rotation rotation = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };
	rotateVerticalSlice(this, column, rotation);
}


static void rotateSliceDown(Cube * this, Column column)
{
	Rotation rotation = { FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE };
	rotateVerticalSlice(this, column, rotation);
}


void Cube_rotateLeftSliceUp(Cube * this)
{
	rotateSliceUp(this, LEFT_COLUMN);
	Face_rotateAnticlockwise(Cube_leftFace(this));
}


void Cube_rotateLeftSliceDown(Cube * this)
{
	rotateSliceDown(this, LEFT_COLUMN);
	Face_rotateClockwise(Cube_leftFace(this));
}


void Cube_rotateMiddleSliceUp(Cube * this)
{
	rotateSliceUp(this, MIDDLE_COLUMN);
}


void Cube_rotateMiddleSliceDown(Cube * this)
{
	rotateSliceDown(this, MIDDLE_COLUMN);
}


void Cube_rotateRightSliceUp(Cube * this)
{
	rotateSliceUp(this, RIGHT_COLUMN);
	Face_rotateClockwise(Cube_rightFace(this));
}


void Cube_rotateRightSliceDown(Cube * this)
{
	rotateSliceDown(this, RIGHT_COLUMN);
	Face_rotateAnticlockwise(Cube_rightFace(this));
}


void Cube_rotateFrontSliceClockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN }
	};
	rotateSlice(this, slice);
	Face_rotateClockwise(Cube_frontFace(this));
}


void Cube_rotateFrontSliceAnticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN }
	};
	rotateSlice(this, slice);
	Face_rotateAnticlockwise(Cube_frontFace(this));
}


void Cube_rotateStandingSliceClockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN }
	};
	rotateSlice(this, slice);
}


void Cube_rotateStandingSliceAnticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN }
	};
	rotateSlice(this, slice);
}


void Cube_rotateBackSliceClockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN }
	};
	rotateSlice(this, slice);
	Face_rotateAnticlockwise(Cube_backFace(this));
}


void Cube_rotateBackSliceAnticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN }
	};
	rotateSlice(this, slice);
	Face_rotateClockwise(Cube_backFace(this));
}
