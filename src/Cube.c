
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




static void applyColorOnRow(Face * this, int rowIndex, Color color);


static void applyColor(Face * this, Color color);


static Face * createFace(Color color);


static void deleteFace(Face ** this);


static Color getColor(Face const * this);


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


static void createAndPositionFaces(Cube * this);


static Cube * createCube(void);


static void deleteCube(Cube ** this);


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
 * 		eg: {TOP_FACE, RIGHT_FACE, BOTTOM_FACE, LEFT_FACE} will put TOP_FACE face where RIGHT_FACE face is
 */
static void rotateCamera(Cube * this, int faceIndexesCycle[4]);


static void rotateCameraLeft(Cube * this);


static void rotateCameraRight(Cube * this);


static void rotateCameraUp(Cube * this);


static void rotateCameraDown(Cube * this);


static void rotateCameraClockwise(Cube * this);


static void rotateCameraAnticlockwise(Cube * this);


static void turnHorizontalSlice(Cube * this, int sliceIndex, int cycle[4]);


static void turnTopSliceLeft(Cube * this);


static void turnTopSliceRight(Cube * this);


static void turnEquatorSliceLeft(Cube * this);


static void turnEquatorSliceRight(Cube * this);


static void turnBottomSliceLeft(Cube * this);


static void turnBottomSliceRight(Cube * this);


static void turnVerticalSlice(Cube * this, int cellIndex, int facesCycle[4]);


static void turnLeftSliceUp(Cube * this);


static void turnLeftSliceDown(Cube * this);


static void turnMiddleSliceUp(Cube * this);




static void applyColorOnRow(Face * const this, int rowIndex, Color color)
{
	int columnIndex;

	for (columnIndex = LEFT_COLUMN; columnIndex <= RIGHT_COLUMN; columnIndex++)
		this->cells[rowIndex][columnIndex] = color;
}


static void applyColor(Face * const this, Color color)
{
	int rowIndex;

	for (rowIndex = TOP_ROW; rowIndex <= BOTTOM_ROW; rowIndex++)
		applyColorOnRow(this, rowIndex, color);
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


static Color getColor(Face const * const this)
{
	/* center cells are fixed */
	return getEquatorCenterCell(this);
}


static Color getTopLeftCell(Face const * const this)
{
	return this->cells[TOP_ROW][LEFT_CELL];
}


static Color getTopCenterCell(Face const * const this)
{
	return this->cells[TOP_ROW][MIDDLE_CELL];
}


static Color getTopRightCell(Face const * const this)
{
	return this->cells[TOP_ROW][RIGHT_CELL];
}


static Color getEquatorLeftCell(Face const * const this)
{
	return this->cells[EQUATOR_ROW][LEFT_CELL];
}


static Color getEquatorCenterCell(Face const * const this)
{
	return this->cells[EQUATOR_ROW][MIDDLE_CELL];
}


static Color getEquatorRightCell(Face const * const this)
{
	return this->cells[EQUATOR_ROW][RIGHT_CELL];
}


static Color getBottomLeftCell(Face const * const this)
{
	return this->cells[BOTTOM_ROW][LEFT_CELL];
}


static Color getBottomCenterCell(Face const * const this)
{
	return this->cells[BOTTOM_ROW][MIDDLE_CELL];
}


static Color getBottomRightCell(Face const * const this)
{
	return this->cells[BOTTOM_ROW][RIGHT_CELL];
}


static void getRow(
	Face const * const this,
	Color storage[FACE_SIZE],
	int rowIndex)
{
	size_t sliceSizeInBytes = FACE_SIZE * sizeof(this->cells[rowIndex][0]);
	memcpy(storage, this->cells[rowIndex], sliceSizeInBytes);
}

static void getTopRow(Face const * const this, Color storage[FACE_SIZE])
{
	getRow(this, storage, TOP_ROW);
}


static void getEquatorRow(Face const * const this, Color storage[FACE_SIZE])
{
	getRow(this, storage, EQUATOR_ROW);
}


void getBottomRow(Face const * const this, Color storage[FACE_SIZE])
{
	getRow(this, storage, BOTTOM_ROW);
}


static void getColumn(
	Face const * const this,
	Color storage[FACE_SIZE],
	int columnIndex)
{
	int rowIndex;
	for (rowIndex = TOP_ROW; rowIndex <= BOTTOM_ROW; rowIndex++)
		storage[rowIndex] = this->cells[rowIndex][columnIndex];
}


static void getLeftColumn(Face const * const this, Color storage[FACE_SIZE])
{
	getColumn(this, storage, LEFT_COLUMN);
}


static void getMiddleColumn(Face const * const this, Color storage[FACE_SIZE])
{
	getColumn(this, storage, MIDDLE_COLUMN);
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


static Face * getLeftFace(Cube const * const this)
{
	return this->faces[LEFT_FACE];
}


static Face * getFrontFace(Cube const * const this)
{
	return this->faces[FRONT_FACE];
}


static Face * getRightFace(Cube const * const this)
{
	return this->faces[RIGHT_FACE];
}


static Face * getTopFace(Cube const * const this)
{
	return this->faces[TOP_FACE];
}


static Face * getBottomFace(Cube const * const this)
{
	return this->faces[BOTTOM_FACE];
}


static Face * getBackFace(Cube const * const this)
{
	return this->faces[BACK_FACE];
}


static void rotateCamera(Cube * const this, int faceIndexesCycle[4])
{
	Face * backupFace = this->faces[faceIndexesCycle[0]];

	this->faces[faceIndexesCycle[0]] = this->faces[faceIndexesCycle[1]];
	this->faces[faceIndexesCycle[1]] = this->faces[faceIndexesCycle[2]];
	this->faces[faceIndexesCycle[2]] = this->faces[faceIndexesCycle[3]];
	this->faces[faceIndexesCycle[3]] = backupFace;
}


static void rotateCameraLeft(Cube * const this)
{
	int cycle[4] = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };
	rotateCamera(this, cycle);
}


static void rotateCameraRight(Cube * const this)
{
	int cycle[4] = { FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE };
	rotateCamera(this, cycle);
}


static void rotateCameraUp(Cube * const this)
{
	int cycle[4] = { FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE };
	rotateCamera(this, cycle);
}


static void rotateCameraDown(Cube * const this)
{
	int cycle[4] = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };
	rotateCamera(this, cycle);
}


static void rotateCameraClockwise(Cube * const this)
{
	int cycle[4] = { TOP_FACE, LEFT_FACE, BOTTOM_FACE, RIGHT_FACE };
	rotateCamera(this, cycle);
}


static void rotateCameraAnticlockwise(Cube * const this)
{
	int cycle[4] = { TOP_FACE, RIGHT_FACE, BOTTOM_FACE, LEFT_FACE };
	rotateCamera(this, cycle);
}


static void turnHorizontalSlice(Cube * this, int sliceIndex, int facesCycle[4])
{
	size_t sliceSizeInBytes =
		FACE_SIZE * sizeof(this->faces[FRONT_FACE]->cells[sliceIndex][0]);

	int cycleIndex;

	Color sliceBackup[FACE_SIZE];
	memcpy(
		sliceBackup,
		this->faces[facesCycle[3]]->cells[sliceIndex],
		sliceSizeInBytes);

	for (cycleIndex = 3; cycleIndex > 0; cycleIndex--)
	{
		memcpy(
			this->faces[facesCycle[cycleIndex]]->cells[sliceIndex],
			this->faces[facesCycle[cycleIndex - 1]]->cells[sliceIndex],
			sliceSizeInBytes);
	}

	memcpy(
		this->faces[facesCycle[0]]->cells[sliceIndex],
		sliceBackup,
		sliceSizeInBytes);
}

static void turnTopSliceLeft(Cube * this)
{
	int facesCycle[] = { FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE };
	turnHorizontalSlice(this, TOP_ROW, facesCycle);
}


static void turnTopSliceRight(Cube * this)
{
	int facesCycle[] = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };
	turnHorizontalSlice(this, TOP_ROW, facesCycle);
}


static void turnEquatorSliceLeft(Cube * this)
{
	int facesCycle[] = { FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE };
	turnHorizontalSlice(this, EQUATOR_ROW, facesCycle);
}


static void turnEquatorSliceRight(Cube * this)
{
	int facesCycle[] = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };
	turnHorizontalSlice(this, EQUATOR_ROW, facesCycle);
}


static void turnBottomSliceLeft(Cube * this)
{
	int facesCycle[] = { FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE };
	turnHorizontalSlice(this, BOTTOM_ROW, facesCycle);
}


static void turnBottomSliceRight(Cube * this)
{
	int facesCycle[] = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };
	turnHorizontalSlice(this, BOTTOM_ROW, facesCycle);
}


static void turnVerticalSlice(Cube * this, int cellIndex, int facesCycle[4])
{
	int sliceIndex;

	Color sliceBackup[FACE_SIZE];
	getColumn(this->faces[facesCycle[3]], sliceBackup, cellIndex);

	for (sliceIndex = TOP_ROW; sliceIndex < BOTTOM_ROW; sliceIndex++)
	{
		this->faces[facesCycle[3]]->cells[sliceIndex][cellIndex] =
		this->faces[facesCycle[2]]->cells[sliceIndex][cellIndex];

		this->faces[facesCycle[2]]->cells[sliceIndex][cellIndex] =
		this->faces[facesCycle[1]]->cells[sliceIndex][cellIndex];

		this->faces[facesCycle[1]]->cells[sliceIndex][cellIndex] =
		this->faces[facesCycle[0]]->cells[sliceIndex][cellIndex];

		this->faces[facesCycle[0]]->cells[sliceIndex][cellIndex] =
		sliceBackup[cellIndex];
	}
}


static void turnLeftSliceUp(Cube * this)
{
	int facesCycle[] = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };
	turnVerticalSlice(this, LEFT_CELL, facesCycle);
}


static void turnLeftSliceDown(Cube * this)
{
	int facesCycle[] = { FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE };
	turnVerticalSlice(this, LEFT_CELL, facesCycle);
}


static void turnMiddleSliceUp(Cube * this)
{
	int facesCycle[] = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };
	turnVerticalSlice(this, MIDDLE_COLUMN, facesCycle);
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
	getMiddleColumn
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

	rotateCameraLeft,
	rotateCameraRight,
	rotateCameraUp,
	rotateCameraDown,
	rotateCameraClockwise,
	rotateCameraAnticlockwise,

	turnTopSliceLeft,
	turnTopSliceRight,
	turnEquatorSliceLeft,
	turnEquatorSliceRight,
	turnBottomSliceLeft,
	turnBottomSliceRight,

	turnLeftSliceUp,
	turnLeftSliceDown,
	turnMiddleSliceUp
};
CubeMethods const * const _Cube = & cubeMethods;
