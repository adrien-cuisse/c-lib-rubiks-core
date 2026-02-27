
#ifndef LIB_RUBIKS_CORE_INTERNAL_FACE_HEADER
#define LIB_RUBIKS_CORE_INTERNAL_FACE_HEADER

#ifdef __cplusplus
extern "C" {
#endif

#include "../shared/attributes/attributes.h"
#include "../color/color.h"

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
RBC_API enum rbc_color rbc_face_color(struct rbc_face const * self);


/**
 * Returns the color of the [top row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RBC_API enum rbc_color rbc_face_top_left_cell(struct rbc_face const * self);


/**
 * Returns the color of the [top row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RBC_API enum rbc_color rbc_face_top_center_cell(struct rbc_face const * self);


/**
 * Returns the color of the [top row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RBC_API enum rbc_color rbc_face_top_right_cell(struct rbc_face const * self);


/**
 * Returns the color of the [equator row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RBC_API enum rbc_color rbc_face_equator_left_cell(struct rbc_face const * self);


/**
 * Returns the color of the [equator row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RBC_API enum rbc_color rbc_face_equator_center_cell(struct rbc_face const * self);


/**
 * Returns the color of the [equator row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RBC_API enum rbc_color rbc_face_equator_right_cell(struct rbc_face const * self);


/**
 * Returns the color of the [bottom row, left column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RBC_API enum rbc_color rbc_face_bottom_left_cell(struct rbc_face const * self);


/**
 * Returns the color of the [bottom row, center column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RBC_API enum rbc_color rbc_face_bottom_center_cell(struct rbc_face const * self);


/**
 * Returns the color of the [bottom row, right column] cell
 *
 * @param self - the face to get the cell color from
 *
 * @return enum rbc_color - the color of the cell
 */
RBC_API enum rbc_color rbc_face_bottom_right_cell(struct rbc_face const * self);




enum rbc_span_location
{
	RBC_TOP_ROW = 0,
	RBC_EQUATOR_ROW = 1,
	RBC_BOTTOM_ROW = 2,

	RBC_LEFT_COLUMN = 0,
	RBC_MIDDLE_COLUMN = 1,
	RBC_RIGHT_COLUMN = 2
};




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
 * @param self - the face to delete
 */
void delete_face(struct rbc_face ** self);


/**
 * Applies a clockwise rotation on the face
 *
 * @param self - the face to rotate
 */
void rotate_face_clockwise(struct rbc_face * self);


/**
 * Applies an anticlockwise rotation on the face
 *
 * @param self - the face to rotate
 */
void rotate_face_anticlockwise(struct rbc_face * self);


/**
 * Reads a row of the face
 *
 * @param self - the face containing the row to read
 *
 * @param buffer - buffer where to write the row
 *
 * @param row - the row to read
 */
void copy_face_row(struct rbc_face const * self, enum rbc_color buffer[FACE_SIZE], enum rbc_span_location row);


/**
 * Writes a row on the face
 *
 * @param self - the face containing the row where to write
 *
 * @param cells - the cells to write
 *
 * @param row - the row where to write the cells
 */
void set_face_row(struct rbc_face * self, enum rbc_color const cells[FACE_SIZE], enum rbc_span_location row);


/**
 * Reads a column of the face
 *
 * @param self - the face containing the column to read
 *
 * @param buffer - buffer where to write the column
 *
 * @param column - the column to read
 */
void copy_face_column(struct rbc_face const * self, enum rbc_color buffer[FACE_SIZE], enum rbc_span_location column);


/**
 * Writes a column on the face
 *
 * @param self - the face containing the column where to write
 *
 * @param cells - the cells to write
 *
 * @param column - the column where to write the cells
 */
void set_face_column(struct rbc_face * self, enum rbc_color const cells[FACE_SIZE], enum rbc_span_location column);




#ifdef __cplusplus
}
#endif

#endif /* LIB_RUBIKS_CORE_INTERNAL_FACE_HEADER */
