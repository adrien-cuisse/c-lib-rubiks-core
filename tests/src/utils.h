
#ifndef RUBIKS_CORE_TESTS_UTILS_HEADER
#define RUBIKS_CORE_TESTS_UTILS_HEADER

#include "../../include/Cube.h"




Cube * create_scrambled_cube(void);


void top_row(Face const * face, Color buffer[FACE_SIZE]);
void equator_row(Face const * face, Color buffer[FACE_SIZE]);
void bottom_row(Face const * face, Color buffer[FACE_SIZE]);


void left_column(Face const * face, Color buffer[FACE_SIZE]);
void middle_column(Face const * face, Color buffer[FACE_SIZE]);
void right_column(Face const * face, Color buffer[FACE_SIZE]);


void read_face(Face const * face, Color buffer[FACE_SIZE][FACE_SIZE]);


void reverse_span(Color buffer[FACE_SIZE]);




#endif /* RUBIKS_CORE_TESTS_UTILS_HEADER */
