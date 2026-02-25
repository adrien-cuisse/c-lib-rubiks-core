
#ifndef LIB_RUBIKS_CORE_TESTS_UTILS_HEADER
#define LIB_RUBIKS_CORE_TESTS_UTILS_HEADER

#include "../../include/Cube.h"




struct rbc_cube * create_scrambled_cube(void);


void top_row(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE]);
void equator_row(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE]);
void bottom_row(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE]);


void left_column(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE]);
void middle_column(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE]);
void right_column(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE]);


void read_face(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE][FACE_SIZE]);


void reverse_span(enum rbc_color buffer[FACE_SIZE]);




#endif /* LIB_RUBIKS_CORE_TESTS_UTILS_HEADER */
