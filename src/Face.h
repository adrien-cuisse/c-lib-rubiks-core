
#ifndef FACE_INTERNAL_HEADER
#define FACE_INTERNAL_HEADER

#include "../include/Face.h"




/** The rows composing the 2D Face (Y axis), based on FACE_SIZE */
typedef enum
{
	TOP_ROW,
	EQUATOR_ROW,
	BOTTOM_ROW
} Row;


/** The columns composing the 2D Face (X axis), based on FACE_SIZE */
typedef enum
{
	LEFT_COLUMN,
	MIDDLE_COLUMN,
	RIGHT_COLUMN
} Column;




Face * Face_create(Color color);
void Face_delete(Face ** this);

void Face_rotateClockwise(Face * this);
void Face_rotateAnticlockwise(Face * this);

void Face_copyRow(Face const * this, Color buffer[FACE_SIZE], Row row);
void Face_setRow(Face * this, Color const cells[FACE_SIZE], Row row);

void Face_copyColumn(Face const * this, Color buffer[FACE_SIZE], Column column);
void Face_setColumn(Face * face, Color const cells[FACE_SIZE], Column column);




#endif /* FACE_INTERNAL_HEADER */
