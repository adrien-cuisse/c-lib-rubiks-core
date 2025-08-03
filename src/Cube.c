
#include <stdlib.h>
#include <string.h>

#include "Face.h"
#include "Cube.h"




/**
 * Allocates faces and stores them in the cube
 *
 * @param this - the cube to store faces in
 */
static void create_and_position_faces(Cube * this)
{
	int face_index;

	this->faces[LEFT_FACE] = create_face(RED);
	this->faces[FRONT_FACE] = create_face(BLUE);
	this->faces[RIGHT_FACE] = create_face(ORANGE);
	this->faces[TOP_FACE] = create_face(WHITE);
	this->faces[BOTTOM_FACE] = create_face(YELLOW);
	this->faces[BACK_FACE] = create_face(GREEN);

	for (face_index = 0; face_index < 6; face_index++)
	{
		if (this->faces[face_index] == NULL)
		{
			rubiks_cube_delete(& this);
			return;
		}
	}
}


Cube * rubiks_cube_create(void)
{
	Cube * this = calloc(1, sizeof(* this));
	if (this != NULL)
		create_and_position_faces(this);

	return this;
}


void rubiks_cube_delete(Cube ** this)
{
	FacePosition position;

	if ((this == NULL) || (* this == NULL))
		return;

	for (position = 0; position < 6; position++)
	{
		delete_face(& (* this)->faces[position]);
		(* this)->faces[position] = NULL;
	}

	free(* this);
	* this = NULL;
}


/**
 * Returns a face of the cube
 *
 * @param this - the cube to get a face from
 *
 * @param position - the face to get
 *
 * @return Face * - the requested face
 */
static Face * get_face(Cube const * this, FacePosition position)
{
	return this->faces[position];
}


Face * rubiks_cube_left_face(Cube const * this)
{
	return get_face(this, LEFT_FACE);
}


Face * rubiks_cube_front_face(Cube const * this)
{
	return get_face(this, FRONT_FACE);
}


Face * rubiks_cube_right_face(Cube const * this)
{
	return get_face(this, RIGHT_FACE);
}


Face * rubiks_cube_top_face(Cube const * this)
{
	return get_face(this, TOP_FACE);
}


Face * rubiks_cube_bottom_face(Cube const * this)
{
	return get_face(this, BOTTOM_FACE);
}


Face * rubiks_cube_back_face(Cube const * this)
{
	return get_face(this, BACK_FACE);
}
