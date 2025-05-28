
#ifndef FACE_HEADER
#define FACE_HEADER

#include "../include/Color.h"

#define FACE_SIZE 3




/**
 * A face of the 3D cube
 */
typedef struct Face Face;




/**
 * Returns the color of the face
 *
 * @param this - the face to get the color from
 *
 * @return Color - the color of the face
 */
Color Face_color(Face const * this);


/**
 * Returns the color of the [top row, left column] cell
 *
 * @param this - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
Color Face_topLeftCell(Face const * this);


/**
 * Returns the color of the [top row, center column] cell
 *
 * @param this - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
Color Face_topCenterCell(Face const * this);


/**
 * Returns the color of the [top row, right column] cell
 *
 * @param this - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
Color Face_topRightCell(Face const * this);


/**
 * Returns the color of the [equator row, left column] cell
 *
 * @param this - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
Color Face_equatorLeftCell(Face const * this);


/**
 * Returns the color of the [equator row, center column] cell
 *
 * @param this - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
Color Face_equatorCenterCell(Face const * this);


/**
 * Returns the color of the [equator row, right column] cell
 *
 * @param this - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
Color Face_equatorRightCell(Face const * this);


/**
 * Returns the color of the [bottom row, left column] cell
 *
 * @param this - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
Color Face_bottomLeftCell(Face const * this);


/**
 * Returns the color of the [bottom row, center column] cell
 *
 * @param this - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
Color Face_bottomCenterCell(Face const * this);


/**
 * Returns the color of the [bottom row, right column] cell
 *
 * @param this - the face to get the cell color from
 *
 * @return Color - the color of the cell
 */
Color Face_bottomRightCell(Face const * this);




#endif /* FACE_HEADER */
