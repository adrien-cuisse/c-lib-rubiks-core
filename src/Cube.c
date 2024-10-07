
#include <stdio.h>
#include <stdlib.h>

#include "Cube.h"
#include "Face.h"


/** The position of each face in the T-shaped pattern of the unfolded cube */
#define LEFT 0
#define FRONT 1
#define RIGHT 2
#define BOTTOM 3
#define BACK 4
#define TOP 5




struct Cube
{
	Face * faces[6];
};




static void createAndPositionFaces(Cube * this);


static Cube * createCube(void);


static void deleteCube(Cube ** this);


static Face * getLeftFace(Cube const * this);


static Face * getFrontFace(Cube const * this);


static Face * getRightFace(Cube const * this);


static Face * getTopFace(Cube const * this);


static Face * getBottomFace(Cube const * this);


static Face * getBackFace(Cube const * this);


static void rotateCameraLeft(Cube * this);


static void rotateCameraRight(Cube * this);


static void rotateCameraUp(Cube * this);


static void rotateCameraDown(Cube * this);


static void rotateCameraClockwise(Cube * this);


static void rotateCameraAnticlockwise(Cube * this);




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


static void rotateCameraLeft(Cube * const this)
{
	Face * oldFrontFace = this->faces[FRONT];

	this->faces[FRONT] = this->faces[RIGHT];
	this->faces[RIGHT] = this->faces[BACK];
	this->faces[BACK] = this->faces[LEFT];
	this->faces[LEFT] = oldFrontFace;
}


static void rotateCameraRight(Cube * const this)
{
	Face * oldFrontFace = this->faces[FRONT];

	this->faces[FRONT] = this->faces[LEFT];
	this->faces[LEFT] = this->faces[BACK];
	this->faces[BACK] = this->faces[RIGHT];
	this->faces[RIGHT] = oldFrontFace;
}


static void rotateCameraUp(Cube * const this)
{
	Face * oldFrontFace = this->faces[FRONT];

	this->faces[FRONT] = this->faces[BOTTOM];
	this->faces[BOTTOM] = this->faces[BACK];
	this->faces[BACK] = this->faces[TOP];
	this->faces[TOP] = oldFrontFace;
}


static void rotateCameraDown(Cube * const this)
{
	Face * oldFrontFace = this->faces[FRONT];

	this->faces[FRONT] = this->faces[TOP];
	this->faces[TOP] = this->faces[BACK];
	this->faces[BACK] = this->faces[BOTTOM];
	this->faces[BOTTOM] = oldFrontFace;
}


static void rotateCameraClockwise(Cube * const this)
{
	Face * oldTopFace = this->faces[TOP];

	this->faces[TOP] = this->faces[LEFT];
	this->faces[LEFT] = this->faces[BOTTOM];
	this->faces[BOTTOM] = this->faces[RIGHT];
	this->faces[RIGHT] = oldTopFace;
}


static void rotateCameraAnticlockwise(Cube * const this)
{
	Face * oldTopFace = this->faces[TOP];

	this->faces[TOP] = this->faces[RIGHT];
	this->faces[RIGHT] = this->faces[BOTTOM];
	this->faces[BOTTOM] = this->faces[LEFT];
	this->faces[LEFT] = oldTopFace;
}




static CubeMethods methods =
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
	rotateCameraAnticlockwise
};
CubeMethods const * const _Cube = & methods;
