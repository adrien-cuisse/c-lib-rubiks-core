
#ifndef RUBIKS_CORE_FACE_HEADER
#define RUBIKS_CORE_FACE_HEADER

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RUBIKS_API
#define RUBIKS_API
#endif

#define FACE_SIZE 3

#include "../include/Color.h"




/**
 * A face of the 3D cube
 */
typedef struct Face Face;




/**
 * Returns the color of the face
 *
 * @param self - the face to get the color from
 *
 * @return Color - the color of the face
 */
RUBIKS_API Color rubiks_face_color(Face const * self);


/**
 * Returns the color of the [top row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color rubiks_face_top_left_cell(Face const * self);


/**
 * Returns the color of the [top row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color rubiks_face_top_center_cell(Face const * self);


/**
 * Returns the color of the [top row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color rubiks_face_top_right_cell(Face const * self);


/**
 * Returns the color of the [equator row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color rubiks_face_equator_left_cell(Face const * self);


/**
 * Returns the color of the [equator row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color rubiks_face_equator_center_cell(Face const * self);


/**
 * Returns the color of the [equator row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color rubiks_face_equator_right_cell(Face const * self);


/**
 * Returns the color of the [bottom row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color rubiks_face_bottom_left_cell(Face const * self);


/**
 * Returns the color of the [bottom row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color rubiks_face_bottom_center_cell(Face const * self);


/**
 * Returns the color of the [bottom row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color rubiks_face_bottom_right_cell(Face const * self);




#ifdef __cplusplus
}
#endif

#endif /* RUBIKS_CORE_FACE_HEADER */
