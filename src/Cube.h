
#ifndef CUBE_INTERNAL_HEADER
#define CUBE_INTERNAL_HEADER

#include "../include/Face.h"
#include "../include/Cube.h"




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


struct Cube
{
	Face * faces[6];
};




#endif /* CUBE_INTERNAL_HEADER */

