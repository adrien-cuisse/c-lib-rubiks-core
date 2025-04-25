
#ifndef FACE_HEADER
#define FACE_HEADER

#include "../include/Color.h"

#define FACE_SIZE 3




typedef struct Face Face;




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




#endif /* FACE_HEADER */
