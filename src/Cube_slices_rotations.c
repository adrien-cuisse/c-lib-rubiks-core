
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


static void reverseLine(Color line[FACE_SIZE])
{
	Color swap = line[0];
	line[0] = line[2];
	line[2] = swap;
}


static void moveReversedLine(Cube * this, Line from, Line to)
{
	Color line[FACE_SIZE];
	getLine(this, from, line);
	reverseLine(line);
	setLine(this, to, line);
}


static void rotateSliceLeft(Cube * this, Slice slice)
{
	int cycleIndex;

	FacePosition fromFace;
	FacePosition toFace;

	Color lineBackup[FACE_SIZE];

	getLine(this, slice[3], lineBackup);

	for (cycleIndex = 3; cycleIndex > 0; cycleIndex--)
	{
		fromFace = slice[cycleIndex - 1].face;
		toFace = slice[cycleIndex].face;

		if (fromFace == LEFT_FACE && toFace == BACK_FACE)
			moveReversedLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
		else if (fromFace == BACK_FACE && toFace == RIGHT_FACE)
			moveReversedLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
		else
			moveLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
	}

	fromFace = slice[3].face;
	toFace = slice[0].face;
	if (fromFace == LEFT_FACE && toFace == TOP_FACE)
		reverseLine(lineBackup);

	setLine(this, slice[0], lineBackup);
}


static void rotateSliceRight(Cube * this, Slice slice)
{
	int cycleIndex;

	FacePosition fromFace;
	FacePosition toFace;

	Color lineBackup[FACE_SIZE];

	getLine(this, slice[3], lineBackup);

	for (cycleIndex = 3; cycleIndex > 0; cycleIndex--)
	{
		fromFace = slice[cycleIndex - 1].face;
		toFace = slice[cycleIndex].face;

		if (fromFace == RIGHT_FACE && toFace == BACK_FACE)
			moveReversedLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
		else if (fromFace == BACK_FACE && toFace == LEFT_FACE)
			moveReversedLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
		else
			moveLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
	}

	fromFace = slice[3].face;
	toFace = slice[0].face;
	if (fromFace == LEFT_FACE && toFace == TOP_FACE)
		reverseLine(lineBackup);

	setLine(this, slice[0], lineBackup);
}


void Cube_rotateTopSliceLeft(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, TOP_ROW, -1 },
		{ BACK_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, TOP_ROW, -1 }
	};
	rotateSliceLeft(this, slice);
	Face_rotateClockwise(Cube_topFace(this));
}


void Cube_rotateTopSliceRight(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, TOP_ROW, -1 },
		{ BACK_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, TOP_ROW, -1 }
	};
	rotateSliceRight(this, slice);
	Face_rotateAnticlockwise(Cube_topFace(this));
}


void Cube_rotateEquatorSliceLeft(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, EQUATOR_ROW, -1 },
		{ BACK_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, EQUATOR_ROW, -1 }
	};
	rotateSliceLeft(this, slice);
}


void Cube_rotateEquatorSliceRight(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, EQUATOR_ROW, -1 },
		{ BACK_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, EQUATOR_ROW, -1 }
	};
	rotateSliceRight(this, slice);
}


void Cube_rotateBottomSliceLeft(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, BOTTOM_ROW, -1 },
		{ BACK_FACE, TOP_ROW, -1},
		{ RIGHT_FACE, BOTTOM_ROW, -1 }
	};
	rotateSliceLeft(this, slice);
	Face_rotateAnticlockwise(Cube_bottomFace(this));
}


void Cube_rotateBottomSliceRight(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, BOTTOM_ROW, -1 },
		{ BACK_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, BOTTOM_ROW, -1 }
	};
	rotateSliceRight(this, slice);
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


static void rotateSliceClockwise(Cube * this, Slice slice)
{
	int cycleIndex;

	FacePosition fromFace;
	FacePosition toFace;

	Color lineBackup[FACE_SIZE];

	getLine(this, slice[3], lineBackup);

	for (cycleIndex = 3; cycleIndex > 0; cycleIndex--)
	{
		fromFace = slice[cycleIndex - 1].face;
		toFace = slice[cycleIndex].face;

		if (fromFace == RIGHT_FACE && toFace == BOTTOM_FACE)
			moveReversedLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
		else if (fromFace == LEFT_FACE && toFace == TOP_FACE)
			moveReversedLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
		else
			moveLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
	}

	fromFace = slice[3].face;
	toFace = slice[0].face;
	if (fromFace == LEFT_FACE && toFace == TOP_FACE)
		reverseLine(lineBackup);

	setLine(this, slice[0], lineBackup);
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
	rotateSliceClockwise(this, slice);
	Face_rotateClockwise(Cube_frontFace(this));
}


static void rotateSliceAnticlockwise(Cube * this, Slice slice)
{
	int cycleIndex;

	FacePosition fromFace;
	FacePosition toFace;

	Color lineBackup[FACE_SIZE];

	getLine(this, slice[3], lineBackup);

	for (cycleIndex = 3; cycleIndex > 0; cycleIndex--)
	{
		fromFace = slice[cycleIndex - 1].face;
		toFace = slice[cycleIndex].face;

		if (fromFace == TOP_FACE && toFace == LEFT_FACE)
			moveReversedLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
		else if (fromFace == BOTTOM_FACE && toFace == RIGHT_FACE)
			moveReversedLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
		else
			moveLine(this, slice[cycleIndex - 1], slice[cycleIndex]);
	}

	fromFace = slice[3].face;
	toFace = slice[0].face;
	if (fromFace == LEFT_FACE && toFace == TOP_FACE)
		reverseLine(lineBackup);

	setLine(this, slice[0], lineBackup);
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
	rotateSliceAnticlockwise(this, slice);
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
	rotateSliceClockwise(this, slice);
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
	rotateSliceAnticlockwise(this, slice);
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
	rotateSliceClockwise(this, slice);
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
	rotateSliceAnticlockwise(this, slice);
	Face_rotateClockwise(Cube_backFace(this));
}
