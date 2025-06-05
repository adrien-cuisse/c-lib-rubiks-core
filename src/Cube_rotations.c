
#include "Face.h"
#include "Cube.h"




/**
 * Applies a rotation on the cube, faces are simply moved on the 2D pattern
 *
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

	Face_rotateClockwise(Cube_bottomFace(this));
	Face_rotateAnticlockwise(Cube_topFace(this));

	rotateCube(this, rotation);
}


void Cube_rotateRight(Cube * this)
{
	Rotation rotation = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };

	Face_rotateAnticlockwise(Cube_bottomFace(this));
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

	Face_rotateClockwise(Cube_frontFace(this));
	Face_rotateAnticlockwise(Cube_backFace(this));

	rotateCube(this, rotation);
}


void Cube_rotateAnticlockwise(Cube * this)
{
	Rotation rotation = { TOP_FACE, LEFT_FACE, BOTTOM_FACE, RIGHT_FACE };

	Face_rotateAnticlockwise(Cube_frontFace(this));
	Face_rotateClockwise(Cube_backFace(this));

	rotateCube(this, rotation);
}
