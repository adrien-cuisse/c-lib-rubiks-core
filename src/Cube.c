
#include <stdlib.h>
#include <string.h>

#include "Face.h"
#include "Cube.h"




static void createAndPositionFaces(Cube * this)
{
	int faceIndex;

	this->faces[LEFT_FACE] = Face_create(RED);
	this->faces[FRONT_FACE] = Face_create(BLUE);
	this->faces[RIGHT_FACE] = Face_create(ORANGE);
	this->faces[TOP_FACE] = Face_create(WHITE);
	this->faces[BOTTOM_FACE] = Face_create(YELLOW);
	this->faces[BACK_FACE] = Face_create(GREEN);

	for (faceIndex = 0; faceIndex < 6; faceIndex++)
	{
		if (this->faces[faceIndex] == NULL)
		{
			Cube_delete(& this);
			return;
		}
	}
}


Cube * Cube_create(void)
{
	Cube * this = calloc(1, sizeof(* this));
	if (this != NULL)
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
