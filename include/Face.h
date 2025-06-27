
#ifndef FACE_HEADER
#define FACE_HEADER

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
RUBIKS_API Color Face_color(Face const * self);


/**
 * Returns the color of the [top row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color Face_topLeftCell(Face const * self);


/**
 * Returns the color of the [top row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color Face_topCenterCell(Face const * self);


/**
 * Returns the color of the [top row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color Face_topRightCell(Face const * self);


/**
 * Returns the color of the [equator row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color Face_equatorLeftCell(Face const * self);


/**
 * Returns the color of the [equator row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color Face_equatorCenterCell(Face const * self);


/**
 * Returns the color of the [equator row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color Face_equatorRightCell(Face const * self);


/**
 * Returns the color of the [bottom row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color Face_bottomLeftCell(Face const * self);


/**
 * Returns the color of the [bottom row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color Face_bottomCenterCell(Face const * self);


/**
 * Returns the color of the [bottom row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
RUBIKS_API Color Face_bottomRightCell(Face const * self);




#ifdef __cplusplus
}
#endif

#endif /* FACE_HEADER */
