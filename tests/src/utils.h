
#ifndef TEMP_HEADER
#define TEMP_HEADER

#include "../../include/Cube.h"




Cube * createScrambledCube(void);


void topRow(Face const * face, Color buffer[FACE_SIZE]);
void equatorRow(Face const * face, Color buffer[FACE_SIZE]);
void bottomRow(Face const * face, Color buffer[FACE_SIZE]);


void leftColumn(Face const * face, Color buffer[FACE_SIZE]);
void middleColumn(Face const * face, Color buffer[FACE_SIZE]);
void rightColumn(Face const * face, Color buffer[FACE_SIZE]);


void readFace(Face const * face, Color buffer[FACE_SIZE][FACE_SIZE]);


void reverseSpan(Color buffer[FACE_SIZE]);




#endif /* TEMP_HEADER */
