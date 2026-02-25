
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
struct rbc_face;




/**
 * Returns the color of the face
 *
 * @param self - the face to get the color from
 *
 * @return enum rbc_color - the color of the face
 */
RUBIKS_API enum rbc_color rubiks_face_color(struct rbc_face const * self);


/**
 * Returns the color of the [top row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RUBIKS_API enum rbc_color rubiks_face_top_left_cell(struct rbc_face const * self);


/**
 * Returns the color of the [top row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RUBIKS_API enum rbc_color rubiks_face_top_center_cell(struct rbc_face const * self);


/**
 * Returns the color of the [top row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RUBIKS_API enum rbc_color rubiks_face_top_right_cell(struct rbc_face const * self);


/**
 * Returns the color of the [equator row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RUBIKS_API enum rbc_color rubiks_face_equator_left_cell(struct rbc_face const * self);


/**
 * Returns the color of the [equator row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RUBIKS_API enum rbc_color rubiks_face_equator_center_cell(struct rbc_face const * self);


/**
 * Returns the color of the [equator row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RUBIKS_API enum rbc_color rubiks_face_equator_right_cell(struct rbc_face const * self);


/**
 * Returns the color of the [bottom row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RUBIKS_API enum rbc_color rubiks_face_bottom_left_cell(struct rbc_face const * self);


/**
 * Returns the color of the [bottom row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RUBIKS_API enum rbc_color rubiks_face_bottom_center_cell(struct rbc_face const * self);


/**
 * Returns the color of the [bottom row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RUBIKS_API enum rbc_color rubiks_face_bottom_right_cell(struct rbc_face const * self);




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
 * @return struct rbc_face * - the created face
 */
struct rbc_face * create_face(enum rbc_color color);


/**
 * Deletes the face and sets it to NULL
 *
 * @param this - the face to delete
 */
void delete_face(struct rbc_face ** this);


/**
 * Applies a clockwise rotation on the face
 *
 * @param this - the face to rotate
 */
void rotate_face_clockwise(struct rbc_face * this);


/**
 * Applies an anticlockwise rotation on the face
 *
 * @param this - the face to rotate
 */
void rotate_face_anticlockwise(struct rbc_face * this);


/**
 * Reads a row of the face
 *
 * @param this - the face containing the row to read
 *
 * @param buffer - buffer where to write the row
 *
 * @param row - the row to read
 */
void copy_face_row(struct rbc_face const * this, enum rbc_color buffer[FACE_SIZE], Row row);


/**
 * Writes a row on the face
 *
 * @param this - the face containing the row where to write
 *
 * @param cells - the cells to write
 *
 * @param row - the row where to write the cells
 */
void set_face_row(struct rbc_face * this, enum rbc_color const cells[FACE_SIZE], Row row);


/**
 * Reads a column of the face
 *
 * @param this - the face containing the column to read
 *
 * @param buffer - buffer where to write the column
 *
 * @param column - the column to read
 */
void copy_face_column(struct rbc_face const * this, enum rbc_color buffer[FACE_SIZE], Column column);


/**
 * Writes a column on the face
 *
 * @param this - the face containing the column where to write
 *
 * @param cells - the cells to write
 *
 * @param column - the column where to write the cells
 */
void set_face_column(struct rbc_face * face, enum rbc_color const cells[FACE_SIZE], Column column);




#ifdef __cplusplus
}
#endif

#endif /* LIB_RUBIKS_CORE_INTERNAL_FACE_HEADER */
