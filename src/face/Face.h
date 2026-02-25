
#ifndef LIB_RUBIKS_CORE_INTERNAL_FACE_HEADER
#define LIB_RUBIKS_CORE_INTERNAL_FACE_HEADER

#ifdef __cplusplus
extern "C" {
#endif

#include "../shared/attributes/attributes.h"
#include "../color/Color.h"

#define FACE_SIZE 3




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




/**
 * The rows composing the 2D Face (Y axis), based on FACE_SIZE
 */
typedef enum
{
	TOP_ROW,
	EQUATOR_ROW,
	BOTTOM_ROW
} Row;


/**
 * The columns composing the 2D Face (X axis), based on FACE_SIZE
 */
typedef enum
{
	LEFT_COLUMN,
	MIDDLE_COLUMN,
	RIGHT_COLUMN
} Column;




/**
 * Creates a face and returns it
 *
 * The caller is in charge of the memory
 *
 * @param color - the color of the face to create
 *
 * @return Face * - the created face
 */
Face * create_face(Color color);


/**
 * Deletes the face and sets it to NULL
 *
 * @param this - the face to delete
 */
void delete_face(Face ** this);


/**
 * Applies a clockwise rotation on the face
 *
 * @param this - the face to rotate
 */
void rotate_face_clockwise(Face * this);


/**
 * Applies an anticlockwise rotation on the face
 *
 * @param this - the face to rotate
 */
void rotate_face_anticlockwise(Face * this);


/**
 * Reads a row of the face
 *
 * @param this - the face containing the row to read
 *
 * @param buffer - buffer where to write the row
 *
 * @param row - the row to read
 */
void copy_face_row(Face const * this, Color buffer[FACE_SIZE], Row row);


/**
 * Writes a row on the face
 *
 * @param this - the face containing the row where to write
 *
 * @param cells - the cells to write
 *
 * @param row - the row where to write the cells
 */
void set_face_row(Face * this, Color const cells[FACE_SIZE], Row row);


/**
 * Reads a column of the face
 *
 * @param this - the face containing the column to read
 *
 * @param buffer - buffer where to write the column
 *
 * @param column - the column to read
 */
void copy_face_column(Face const * this, Color buffer[FACE_SIZE], Column column);


/**
 * Writes a column on the face
 *
 * @param this - the face containing the column where to write
 *
 * @param cells - the cells to write
 *
 * @param column - the column where to write the cells
 */
void set_face_column(Face * face, Color const cells[FACE_SIZE], Column column);




#ifdef __cplusplus
}
#endif

#endif /* LIB_RUBIKS_CORE_INTERNAL_FACE_HEADER */
