
#ifndef FACE_INTERNAL_HEADER
#define FACE_INTERNAL_HEADER

#include "attributes.h"

#include "../include/Face.h"




/**
 * The rows composing the 2D Face (Y axis), based on FACE_SIZE
 */
typedef enum
{
	TOP_ROW,
	EQUATOR_ROW,
	BOTTOM_ROW
} Row;


/**
 * The columns composing the 2D Face (X axis), based on FACE_SIZE
 */
typedef enum
{
	LEFT_COLUMN,
	MIDDLE_COLUMN,
	RIGHT_COLUMN
} Column;




/**
 * Creates a face and returns it
 *
 * The caller is in charge of the memory
 *
 * @param color - the color of the face to create
 *
 * @return Face * - the created face
 */
Face * Face_create(Color color);


/**
 * Deletes the face and sets it to NULL
 *
 * @param this - the face to delete
 */
void Face_delete(Face ** this);


/**
 * Applies a clockwise rotation on the face
 *
 * @param this - the face to rotate
 */
void Face_rotateClockwise(Face * this);


/**
 * Applies an anticlockwise rotation on the face
 *
 * @param this - the face to rotate
 */
void Face_rotateAnticlockwise(Face * this);


/**
 * Reads a row of the face
 *
 * @param this - the face containing the row to read
 *
 * @param buffer - buffer where to write the row
 *
 * @param row - the row to read
 */
void Face_copyRow(Face const * this, Color buffer[FACE_SIZE], Row row);


/**
 * Writes a row on the face
 *
 * @param this - the face containing the row where to write
 *
 * @param cells - the cells to write
 *
 * @param row - the row where to write the cells
 */
void Face_setRow(Face * this, Color const cells[FACE_SIZE], Row row);


/**
 * Reads a column of the face
 *
 * @param this - the face containing the column to read
 *
 * @param buffer - buffer where to write the column
 *
 * @param column - the column to read
 */
void Face_copyColumn(Face const * this, Color buffer[FACE_SIZE], Column column);


/**
 * Writes a column on the face
 *
 * @param this - the face containing the column where to write
 *
 * @param cells - the cells to write
 *
 * @param column - the column where to write the cells
 */
void Face_setColumn(Face * face, Color const cells[FACE_SIZE], Column column);




#endif /* FACE_INTERNAL_HEADER */
