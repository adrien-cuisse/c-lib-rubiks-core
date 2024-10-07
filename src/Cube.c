
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cube.h"
#include "Face.h"


/** The 3 horizontal slices composing the face (Y axis) */
#define TOP_SLICE 0
#define MIDDLE_SLICE 1
#define BOTTOM_SLICE 2


/** The position of a cell in a slice (X axis) */
#define LEFT 0
#define CENTER 1
#define RIGHT 2


/** The position of each face in the T-shaped pattern of the unfolded cube */
#define LEFT 0
#define FRONT 1
#define RIGHT 2
#define BOTTOM 3
#define BACK 4
#define TOP 5




struct Face
{
	Color cells[3][3];
};


struct Cube
{
	Face * faces[6];
};




static void paintSlice(Face * const this, int sliceIndex, Color color);


static void paintSlices(Face * const this, Color color);


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


static Color * getTopSlice(Face const * this);


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
 * 		eg: {TOP, RIGHT, BOTTOM, LEFT} will put TOP face where RIGHT face is
 */
static void rotateCamera(Cube * this, int faceIndexesCycle[4]);


static void rotateCameraLeft(Cube * this);


static void rotateCameraRight(Cube * this);


static void rotateCameraUp(Cube * this);


static void rotateCameraDown(Cube * this);


static void rotateCameraClockwise(Cube * this);


static void rotateCameraAnticlockwise(Cube * this);


static void turnTopSliceLeft(Cube * this);




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


static Color * getTopSlice(Face const * this)
{
	Color * slice = calloc(3, sizeof(slice[0]));
	if (slice == NULL)
	{
		fputs("Slice allocation failed", stderr);
		exit(EXIT_FAILURE);
	}

	memcpy(slice, this->cells[TOP_SLICE], 3 * sizeof(this->cells[TOP_SLICE][0]));

	return slice;
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
	this->faces[LEFT] = _Face->create(RED);
	this->faces[FRONT] = _Face->create(BLUE);
	this->faces[RIGHT] = _Face->create(ORANGE);
	this->faces[TOP] = _Face->create(WHITE);
	this->faces[BOTTOM] = _Face->create(YELLOW);
	this->faces[BACK] = _Face->create(GREEN);
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
	return this->faces[LEFT];
}


static Face * getFrontFace(Cube const * const this)
{
	return this->faces[FRONT];
}


static Face * getRightFace(Cube const * const this)
{
	return this->faces[RIGHT];
}


static Face * getTopFace(Cube const * const this)
{
	return this->faces[TOP];
}


static Face * getBottomFace(Cube const * const this)
{
	return this->faces[BOTTOM];
}


static Face * getBackFace(Cube const * const this)
{
	return this->faces[BACK];
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
	int cycle[4] = { FRONT, RIGHT, BACK, LEFT };
	rotateCamera(this, cycle);
}


static void rotateCameraRight(Cube * const this)
{
	int cycle[4] = { FRONT, LEFT, BACK, RIGHT };
	rotateCamera(this, cycle);
}


static void rotateCameraUp(Cube * const this)
{
	int cycle[4] = { FRONT, BOTTOM, BACK, TOP };
	rotateCamera(this, cycle);
}


static void rotateCameraDown(Cube * const this)
{
	int cycle[4] = { FRONT, TOP, BACK, BOTTOM };
	rotateCamera(this, cycle);
}


static void rotateCameraClockwise(Cube * const this)
{
	int cycle[4] = { TOP, LEFT, BOTTOM, RIGHT };
	rotateCamera(this, cycle);
}


static void rotateCameraAnticlockwise(Cube * const this)
{
	int cycle[4] = { TOP, RIGHT, BOTTOM, LEFT };
	rotateCamera(this, cycle);
}


static void turnTopSliceLeft(Cube * this)
{
	memcpy(
		this->faces[LEFT]->cells[TOP_SLICE],
		this->faces[FRONT]->cells[TOP_SLICE],
		3 * sizeof(this->faces[FRONT]->cells[TOP_SLICE][0]));
}




static FaceMethods faceMethods =
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
	getBottomRightCell,

	getTopSlice
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

	turnTopSliceLeft
};
CubeMethods const * const _Cube = & cubeMethods;
