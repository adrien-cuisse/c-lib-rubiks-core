
#ifndef RUBIKS_CORE_FACE_HEADER
#define RUBIKS_CORE_FACE_HEADER

#ifdef __cplusplus
extern "C" {
#endif

#include "../include/Color.h"

#define FACE_SIZE 3




/**
 * A face of the 3D cube
 */
struct rbc_face;




/**
 * Returns the color of the face
 *
 * @param self - the face to get the color from
 *
 * @return enum rbc_color - the color of the face
 */
enum rbc_color rubiks_face_color(struct rbc_face const * self);


/**
 * Returns the color of the [top row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
enum rbc_color rubiks_face_top_left_cell(struct rbc_face const * self);


/**
 * Returns the color of the [top row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
enum rbc_color rubiks_face_top_center_cell(struct rbc_face const * self);


/**
 * Returns the color of the [top row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
enum rbc_color rubiks_face_top_right_cell(struct rbc_face const * self);


/**
 * Returns the color of the [equator row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
enum rbc_color rubiks_face_equator_left_cell(struct rbc_face const * self);


/**
 * Returns the color of the [equator row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
enum rbc_color rubiks_face_equator_center_cell(struct rbc_face const * self);


/**
 * Returns the color of the [equator row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
enum rbc_color rubiks_face_equator_right_cell(struct rbc_face const * self);


/**
 * Returns the color of the [bottom row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
enum rbc_color rubiks_face_bottom_left_cell(struct rbc_face const * self);


/**
 * Returns the color of the [bottom row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
enum rbc_color rubiks_face_bottom_center_cell(struct rbc_face const * self);


/**
 * Returns the color of the [bottom row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
enum rbc_color rubiks_face_bottom_right_cell(struct rbc_face const * self);




#ifdef __cplusplus
}
#endif

#endif /* RUBIKS_CORE_FACE_HEADER */
