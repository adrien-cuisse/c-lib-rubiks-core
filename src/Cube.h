
#ifndef CUBE_INTERNAL_HEADER
#define CUBE_INTERNAL_HEADER

#include "attributes.h"

#include "../include/Face.h"
#include "../include/Cube.h"




/**
 * The position of each Face in the T-shaped 2D pattern of the unfolded 3D cube
 */
typedef enum
{
	LEFT_FACE,
	FRONT_FACE,
	RIGHT_FACE,
	BOTTOM_FACE,
	BACK_FACE,
	TOP_FACE
} FacePosition;


/**
 * A cycle of 4 faces
 */
typedef FacePosition Rotation[4];


/**
 * A 3D Cube made of 6 2D faces
 */
struct Cube
{
	/**
	 * The 2D faces composing the cube
	 */
	Face * faces[6];
};




#endif /* CUBE_INTERNAL_HEADER */

