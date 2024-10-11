
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cube.h"
#include "Face.h"


/** The rows composing the face (Y axis), based on FACE_SIZE */
#define TOP_ROW 0
#define EQUATOR_ROW 1
#define BOTTOM_ROW 2


/** The columns composing the face (X axis), based on FACE_SIZE */
#define LEFT_COLUMN 0
#define MIDDLE_COLUMN 1
#define RIGHT_COLUMN 2


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




struct Face
{
	Color cells[FACE_SIZE][FACE_SIZE];
};


struct Cube
{
	Face * faces[6];
};




static void setRow(Face * face, Color row[FACE_SIZE], int rowIndex);


static void setColumn(Face * face, Color column[FACE_SIZE], int columnIndex);


static void applyColorOnRow(Face * this, Color color, int rowIndex);


static void applyColor(Face * this, Color color);


static Face * createFace(Color color);


static void deleteFace(Face ** this);


static Color getColor(Face const * this);


static Color getCell(Face const * this, int rowIndex, int columnIndex);


static Color getTopLeftCell(Face const * this);


static Color getTopCenterCell(Face const * this);


static Color getTopRightCell(Face const * this);


static Color getEquatorLeftCell(Face const * this);


static Color getEquatorCenterCell(Face const * this);


static Color getEquatorRightCell(Face const * this);


static Color getBottomLeftCell(Face const * this);


static Color getBottomCenterCell(Face const * this);


static Color getBottomRightCell(Face const * this);


static void getRow(
	Face const * this,
	Color storage[FACE_SIZE],
	int rowIndex);


static void getTopRow(Face const * this, Color storage[FACE_SIZE]);


static void getEquatorRow(Face const * this, Color storage[FACE_SIZE]);


static void getBottomRow(Face const * this, Color storage[FACE_SIZE]);


static void getColumn(
	Face const * this,
	Color storage[FACE_SIZE],
	int columnIndex);


static void getLeftColumn(Face const * this, Color storage[FACE_SIZE]);


static void getMiddleColumn(Face const * this, Color storage[FACE_SIZE]);


static void getRightColumn(Face const * this, Color storage[FACE_SIZE]);


static void rotateFaceClockwise(Face * this);


static void rotateFaceAnticlockwise(Face * this);


static void createAndPositionFaces(Cube * this);


static Cube * createCube(void);


static void deleteCube(Cube ** this);


static Face * getFace(Cube const * this, int faceIndex);


static Face * getLeftFace(Cube const * this);


static Face * getFrontFace(Cube const * this);


static Face * getRightFace(Cube const * this);


static Face * getTopFace(Cube const * this);


static Face * getBottomFace(Cube const * this);


static Face * getBackFace(Cube const * this);


/**
 * @param this - the cube to rotate
 * @param faceIndexesCycle - the cycle of index of faces to move in the
 * 		unfolded pattern, the face at position cycle[i] will take the place of
 * 		the face at position cycle[i+1]
 * 		eg: {TOP_FACE, RIGHT_FACE, BOTTOM_FACE, LEFT_FACE}
 * 			will put TOP_FACE face where RIGHT_FACE face is
 */
static void rotateCube(Cube * this, int faceIndexesCycle[4]);


static void rotateCubeLeft(Cube * this);


static void rotateCubeRight(Cube * this);


static void rotateCubeUp(Cube * this);


static void rotateCubeDown(Cube * this);


static void rotateCubeClockwise(Cube * this);


static void rotateCubeAnticlockwise(Cube * this);


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


static void turnTopSliceLeft(Cube * this);


static void turnTopSliceRight(Cube * this);


static void turnEquatorSliceLeft(Cube * this);


static void turnEquatorSliceRight(Cube * this);


static void turnBottomSliceLeft(Cube * this);


static void turnBottomSliceRight(Cube * this);


static void turnVerticalSlice(Cube * this, int columnIndex, int facesCycle[4]);


static void turnSliceUp(Cube * this, int columnIndex);


static void turnSliceDown(Cube * this, int columnIndex);


static void turnLeftSliceUp(Cube * this);


static void turnLeftSliceDown(Cube * this);


static void turnMiddleSliceUp(Cube * this);


static void turnMiddleSliceDown(Cube * this);


static void turnRightSliceUp(Cube * this);


static void turnRightSliceDown(Cube * this);


static void turnFrontSliceClockwise(Cube * this);


static void turnFrontSliceAnticlockwise(Cube * this);


static void turnStandingSliceClockwise(Cube * this);


static void turnStandingSliceAnticlockwise(Cube * this);


static void turnBackSliceClockwise(Cube * this);


static void turnBackSliceAnticlockwise(Cube * this);




static void setRow(Face * face, Color row[FACE_SIZE], int rowIndex)
{
	size_t sliceSizeInBytes = FACE_SIZE * sizeof(row[0]);
	memcpy(face->cells[rowIndex], row, sliceSizeInBytes);
}


static void setColumn(Face * face, Color column[FACE_SIZE], int columnIndex)
{
	int rowIndex;
	for (rowIndex = TOP_ROW; rowIndex <= BOTTOM_ROW; rowIndex++)
		face->cells[rowIndex][columnIndex] = column[rowIndex];
}


static void applyColorOnRow(Face * this, Color color, int rowIndex)
{
	int columnIndex;
	Color row[FACE_SIZE];

	for (columnIndex = LEFT_COLUMN; columnIndex <= RIGHT_COLUMN; columnIndex++)
		row[columnIndex] = color;

	setRow(this, row, rowIndex);
}


static void applyColor(Face * this, Color color)
{
	int rowIndex;
	for (rowIndex = TOP_ROW; rowIndex <= BOTTOM_ROW; rowIndex++)
		applyColorOnRow(this, color, rowIndex);
}


static Face * createFace(Color color)
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


static void deleteFace(Face ** this)
{
	if ((this == NULL) || (* this == NULL))
		return;

	free(* this);
	* this = NULL;
}


static Color getColor(Face const * this)
{
	/* center cells are fixed */
	return getEquatorCenterCell(this);
}


static Color getCell(Face const * this, int rowIndex, int columnIndex)
{
	return this->cells[rowIndex][columnIndex];
}


static Color getTopLeftCell(Face const * this)
{
	return getCell(this, TOP_ROW, LEFT_CELL);
}


static Color getTopCenterCell(Face const * this)
{
	return getCell(this, TOP_ROW, MIDDLE_CELL);
}


static Color getTopRightCell(Face const * this)
{
	return getCell(this, TOP_ROW, RIGHT_CELL);
}


static Color getEquatorLeftCell(Face const * this)
{
	return getCell(this, EQUATOR_ROW, LEFT_CELL);
}


static Color getEquatorCenterCell(Face const * this)
{
	return getCell(this, EQUATOR_ROW, MIDDLE_CELL);
}


static Color getEquatorRightCell(Face const * this)
{
	return getCell(this, EQUATOR_ROW, RIGHT_CELL);
}


static Color getBottomLeftCell(Face const * this)
{
	return getCell(this, BOTTOM_ROW, LEFT_CELL);
}


static Color getBottomCenterCell(Face const * this)
{
	return getCell(this, BOTTOM_ROW, MIDDLE_CELL);
}


static Color getBottomRightCell(Face const * this)
{
	return getCell(this, BOTTOM_ROW, RIGHT_CELL);
}


static void getRow(
	Face const * this,
	Color storage[FACE_SIZE],
	int rowIndex)
{
	size_t sliceSizeInBytes = FACE_SIZE * sizeof(this->cells[rowIndex][0]);
	memcpy(storage, this->cells[rowIndex], sliceSizeInBytes);
}


static void getTopRow(Face const * this, Color storage[FACE_SIZE])
{
	getRow(this, storage, TOP_ROW);
}


static void getEquatorRow(Face const * this, Color storage[FACE_SIZE])
{
	getRow(this, storage, EQUATOR_ROW);
}


void getBottomRow(Face const * this, Color storage[FACE_SIZE])
{
	getRow(this, storage, BOTTOM_ROW);
}


static void getColumn(
	Face const * this,
	Color storage[FACE_SIZE],
	int columnIndex)
{
	int rowIndex;
	for (rowIndex = TOP_ROW; rowIndex <= BOTTOM_ROW; rowIndex++)
		storage[rowIndex] = this->cells[rowIndex][columnIndex];
}


static void getLeftColumn(Face const * this, Color storage[FACE_SIZE])
{
	getColumn(this, storage, LEFT_COLUMN);
}


static void getMiddleColumn(Face const * this, Color storage[FACE_SIZE])
{
	getColumn(this, storage, MIDDLE_COLUMN);
}


static void getRightColumn(Face const * this, Color storage[FACE_SIZE])
{
	getColumn(this, storage, RIGHT_COLUMN);
}


static void rotateFaceClockwise(Face * this)
{
	Color newRightColumn[FACE_SIZE];
	Color newMiddleColumn[FACE_SIZE];
	Color newLeftColumn[FACE_SIZE];

	getRow(this, newRightColumn, TOP_ROW);
	getRow(this, newMiddleColumn, EQUATOR_ROW);
	getRow(this, newLeftColumn, BOTTOM_ROW);

	setColumn(this, newRightColumn, RIGHT_COLUMN);
	setColumn(this, newMiddleColumn, MIDDLE_COLUMN);
	setColumn(this, newLeftColumn, LEFT_COLUMN);
}


static void rotateFaceAnticlockwise(Face * this)
{
	Color newTopRow[FACE_SIZE];
	Color newEquatorRow[FACE_SIZE];
	Color newBottomRow[FACE_SIZE];

	getColumn(this, newTopRow, RIGHT_COLUMN);
	getColumn(this, newEquatorRow, MIDDLE_COLUMN);
	getColumn(this, newBottomRow, LEFT_COLUMN);

	setRow(this, newTopRow, TOP_ROW);
	setRow(this, newEquatorRow, EQUATOR_ROW);
	setRow(this, newBottomRow, BOTTOM_ROW);
}


static void createAndPositionFaces(Cube * this)
{
	/*
	 * official disposition:
	 * - blue opposes green,
	 * - white opposes yellow,
	 * - red opposes orange,
	 * - blue, white & red are in anti-clockwise order around a corner
	 */
	this->faces[LEFT_FACE] = _Face->create(RED);
	this->faces[FRONT_FACE] = _Face->create(BLUE);
	this->faces[RIGHT_FACE] = _Face->create(ORANGE);
	this->faces[TOP_FACE] = _Face->create(WHITE);
	this->faces[BOTTOM_FACE] = _Face->create(YELLOW);
	this->faces[BACK_FACE] = _Face->create(GREEN);
}


static Cube * createCube(void)
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


static void deleteCube(Cube ** this)
{
	if ((this == NULL) || (* this == NULL))
		return;

	free(* this);
	* this = NULL;
}


static Face * getFace(Cube const * this, int faceIndex)
{
	return this->faces[faceIndex];
}


static Face * getLeftFace(Cube const * this)
{
	return getFace(this, LEFT_FACE);
}


static Face * getFrontFace(Cube const * this)
{
	return getFace(this, FRONT_FACE);
}


static Face * getRightFace(Cube const * this)
{
	return getFace(this, RIGHT_FACE);
}


static Face * getTopFace(Cube const * this)
{
	return getFace(this, TOP_FACE);
}


static Face * getBottomFace(Cube const * this)
{
	return getFace(this, BOTTOM_FACE);
}


static Face * getBackFace(Cube const * this)
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


static void rotateCubeLeft(Cube * this)
{
	int cycle[4] = { FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE };

	rotateFaceClockwise(getLeftFace(this));
	rotateFaceClockwise(getLeftFace(this));
	rotateFaceClockwise(getBottomFace(this));
	rotateFaceClockwise(getBackFace(this));
	rotateFaceClockwise(getBackFace(this));
	rotateFaceAnticlockwise(getTopFace(this));

	rotateCube(this, cycle);
}


static void rotateCubeRight(Cube * this)
{
	int cycle[4] = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };

	rotateFaceAnticlockwise(getRightFace(this));
	rotateFaceAnticlockwise(getRightFace(this));
	rotateFaceAnticlockwise(getBottomFace(this));
	rotateFaceAnticlockwise(getBackFace(this));
	rotateFaceAnticlockwise(getBackFace(this));
	rotateFaceClockwise(getTopFace(this));

	rotateCube(this, cycle);
}


static void rotateCubeUp(Cube * this)
{
	int cycle[4] = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };

	rotateFaceAnticlockwise(getLeftFace(this));
	rotateFaceClockwise(getRightFace(this));

	rotateCube(this, cycle);
}


static void rotateCubeDown(Cube * this)
{
	int cycle[4] = { FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE };

	rotateFaceClockwise(getLeftFace(this));
	rotateFaceAnticlockwise(getRightFace(this));

	rotateCube(this, cycle);
}


static void rotateCubeClockwise(Cube * this)
{
	int cycle[4] = { TOP_FACE, RIGHT_FACE, BOTTOM_FACE, LEFT_FACE };

	rotateFaceClockwise(getLeftFace(this));
	rotateFaceClockwise(getFrontFace(this));
	rotateFaceClockwise(getRightFace(this));
	rotateFaceClockwise(getBottomFace(this));
	rotateFaceAnticlockwise(getBackFace(this));
	rotateFaceClockwise(getTopFace(this));

	rotateCube(this, cycle);
}


static void rotateCubeAnticlockwise(Cube * this)
{
	int cycle[4] = { TOP_FACE, LEFT_FACE, BOTTOM_FACE, RIGHT_FACE };

	rotateFaceAnticlockwise(getLeftFace(this));
	rotateFaceAnticlockwise(getFrontFace(this));
	rotateFaceAnticlockwise(getRightFace(this));
	rotateFaceAnticlockwise(getBottomFace(this));
	rotateFaceClockwise(getBackFace(this));
	rotateFaceAnticlockwise(getTopFace(this));

	rotateCube(this, cycle);
}


static void getLine(
	Face const * face,
	Color storage[FACE_SIZE],
	int coords[2])
{
	int isRow = (coords[1] == -1);
	if (isRow)
		getRow(face, storage, coords[0]);
	else
		getColumn(face, storage, coords[1]);
}


static void setLine(
	Face * face,
	Color storage[FACE_SIZE],
	int coords[2])
{
	int isRow = (coords[1] == -1);
	if (isRow)
		setRow(face, storage, coords[0]);
	else
		setColumn(face, storage, coords[1]);
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


static void turnTopSliceLeft(Cube * this)
{
	turnSliceLeft(this, TOP_ROW);
	rotateFaceClockwise(getFace(this, TOP_FACE));
}


static void turnTopSliceRight(Cube * this)
{
	turnSliceRight(this, TOP_ROW);
	rotateFaceAnticlockwise(getFace(this, TOP_FACE));
}


static void turnEquatorSliceLeft(Cube * this)
{
	turnSliceLeft(this, EQUATOR_ROW);
}


static void turnEquatorSliceRight(Cube * this)
{
	turnSliceRight(this, EQUATOR_ROW);
}


static void turnBottomSliceLeft(Cube * this)
{
	turnSliceLeft(this, BOTTOM_ROW);
	rotateFaceAnticlockwise(getFace(this, BOTTOM_FACE));
}


static void turnBottomSliceRight(Cube * this)
{
	turnSliceRight(this, BOTTOM_ROW);
	rotateFaceClockwise(getFace(this, BOTTOM_FACE));
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


static void turnLeftSliceUp(Cube * this)
{
	turnSliceUp(this, LEFT_COLUMN);
	rotateFaceAnticlockwise(getFace(this, LEFT_FACE));
}


static void turnLeftSliceDown(Cube * this)
{
	turnSliceDown(this, LEFT_COLUMN);
	rotateFaceClockwise(getFace(this, LEFT_FACE));
}


static void turnMiddleSliceUp(Cube * this)
{
	turnSliceUp(this, MIDDLE_COLUMN);
}


static void turnMiddleSliceDown(Cube * this)
{
	turnSliceDown(this, MIDDLE_COLUMN);
}


static void turnRightSliceUp(Cube * this)
{
	turnSliceUp(this, RIGHT_COLUMN);
	rotateFaceClockwise(getFace(this, RIGHT_FACE));
}


static void turnRightSliceDown(Cube * this)
{
	turnSliceDown(this, RIGHT_COLUMN);
	rotateFaceAnticlockwise(getFace(this, RIGHT_FACE));
}


static void turnFrontSliceClockwise(Cube * this)
{
	int linesCoordsCycle[4][3] =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN }
	};
	turnSlice(this, linesCoordsCycle);
	rotateFaceClockwise(getFace(this, FRONT_FACE));
}


static void turnFrontSliceAnticlockwise(Cube * this)
{
	int linesCoordsCycle[4][3] =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN }
	};
	turnSlice(this, linesCoordsCycle);
	rotateFaceAnticlockwise(getFace(this, FRONT_FACE));
}


static void turnStandingSliceClockwise(Cube * this)
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


static void turnStandingSliceAnticlockwise(Cube * this)
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


static void turnBackSliceClockwise(Cube * this)
{
	int linesCoordsCycle[4][3] =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN }
	};
	turnSlice(this, linesCoordsCycle);
	rotateFaceAnticlockwise(getFace(this, BACK_FACE));
}


static void turnBackSliceAnticlockwise(Cube * this)
{
	int linesCoordsCycle[4][3] =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN }
	};
	turnSlice(this, linesCoordsCycle);
	rotateFaceClockwise(getFace(this, BACK_FACE));
}




static FaceMethods faceMethods =
{
	createFace,
	deleteFace,

	getColor,

	getTopLeftCell,
	getTopCenterCell,
	getTopRightCell,
	getEquatorLeftCell,
	getEquatorCenterCell,
	getEquatorRightCell,
	getBottomLeftCell,
	getBottomCenterCell,
	getBottomRightCell,

	getTopRow,
	getEquatorRow,
	getBottomRow,

	getLeftColumn,
	getMiddleColumn,
	getRightColumn,

	rotateFaceClockwise,
	rotateFaceAnticlockwise
};
FaceMethods const * const _Face = & faceMethods;


static CubeMethods cubeMethods =
{
	createCube,
	deleteCube,

	getLeftFace,
	getFrontFace,
	getRightFace,
	getTopFace,
	getBottomFace,
	getBackFace,

	rotateCubeLeft,
	rotateCubeRight,
	rotateCubeUp,
	rotateCubeDown,
	rotateCubeClockwise,
	rotateCubeAnticlockwise,

	turnTopSliceLeft,
	turnTopSliceRight,
	turnEquatorSliceLeft,
	turnEquatorSliceRight,
	turnBottomSliceLeft,
	turnBottomSliceRight,

	turnLeftSliceUp,
	turnLeftSliceDown,
	turnMiddleSliceUp,
	turnMiddleSliceDown,
	turnRightSliceUp,
	turnRightSliceDown,

	turnFrontSliceClockwise,
	turnFrontSliceAnticlockwise,
	turnStandingSliceClockwise,
	turnStandingSliceAnticlockwise,
	turnBackSliceClockwise,
	turnBackSliceAnticlockwise
};
CubeMethods const * const _Cube = & cubeMethods;
