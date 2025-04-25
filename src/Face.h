
#ifndef FACE_HEADER
#define FACE_HEADER

#include "Color.h"

#define FACE_SIZE 3




typedef struct Face Face;




Face * Face_create(Color color);
void Face_delete(Face ** this);

Color Face_color(Face const * this);

Color Face_topLeftCell(Face const * this);
Color Face_topCenterCell(Face const * this);
Color Face_topRightCell(Face const * this);
Color Face_equatorLeftCell(Face const * this);
Color Face_equatorCenterCell(Face const * this);
Color Face_equatorRightCell(Face const * this);
Color Face_bottomLeftCell(Face const * this);
Color Face_bottomCenterCell(Face const * this);
Color Face_bottomRightCell(Face const * this);

void Face_topRow(Face const * this, Color storage[FACE_SIZE]);
void Face_equatorRow(Face const * this, Color storage[FACE_SIZE]);
void Face_bottomRow(Face const * this, Color storage[FACE_SIZE]);

void Face_leftColumn(Face const * this, Color storage[FACE_SIZE]);
void Face_middleColumn(Face const * this, Color storage[FACE_SIZE]);
void Face_rightColumn(Face const * this, Color storage[FACE_SIZE]);

void Face_rotateClockwise(Face * this);
void Face_rotateAnticlockwise(Face * this);




#endif /* FACE_HEADER */
