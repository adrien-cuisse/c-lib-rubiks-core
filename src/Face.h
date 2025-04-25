
#ifndef FACE_INTERNAL_HEADER
#define FACE_INTERNAL_HEADER

#include "../include/Face.h"

/** The rows composing the face (Y axis), based on FACE_SIZE */
#define TOP_ROW 0
#define EQUATOR_ROW 1
#define BOTTOM_ROW 2


/** The columns composing the face (X axis), based on FACE_SIZE */
#define LEFT_COLUMN 0
#define MIDDLE_COLUMN 1
#define RIGHT_COLUMN 2




Face * Face_create(Color color);
void Face_delete(Face ** this);

void Face_rotateClockwise(Face * this);
void Face_rotateAnticlockwise(Face * this);

void Face_copyRow(Face const * this, Color buffer[FACE_SIZE], int rowIndex);
void Face_setRow(Face * this, Color buffer[FACE_SIZE], int rowIndex);

void Face_copyColumn(Face const * this, Color buffer[FACE_SIZE], int columnIndex);
void Face_setColumn(Face * face, Color column[FACE_SIZE], int columnIndex);

void Face_topRow(Face const * this, Color storage[FACE_SIZE]);
void Face_equatorRow(Face const * this, Color storage[FACE_SIZE]);
void Face_bottomRow(Face const * this, Color storage[FACE_SIZE]);

void Face_leftColumn(Face const * this, Color storage[FACE_SIZE]);
void Face_middleColumn(Face const * this, Color storage[FACE_SIZE]);
void Face_rightColumn(Face const * this, Color storage[FACE_SIZE]);




#endif /* FACE_INTERNAL_HEADER */
