
#include "Face.h"

#include <stdlib.h>
#include <string.h>




/**
 * A 2D Face
 */
struct rbc_face
{
	/**
	 * A FACE_SIZE*FACE_SIZE arrays of cells, defined by their color
	 */
	enum rbc_color cells[FACE_SIZE][FACE_SIZE];
};




enum rbc_color rbc_face_color(struct rbc_face const * this)
{
	/* center cells are fixed */
	return rbc_face_equator_center_cell(this);
}


/**
 * Returns the color of a cell
 *
 * @param this - the face to get a the cell from
 *
 * @param row - the row where the cell is
 *
 * @param column - the column where the cell is
 *
 * @return enum rbc_color - the color of the requested cell
 */
static enum rbc_color cell(struct rbc_face const * this, enum rbc_row row, enum rbc_column column)
{
	return this->cells[row][column];
}


enum rbc_color rbc_face_top_left_cell(struct rbc_face const * this)
{
	return cell(this, TOP_ROW, LEFT_COLUMN);
}


enum rbc_color rbc_face_top_center_cell(struct rbc_face const * this)
{
	return cell(this, TOP_ROW, MIDDLE_COLUMN);
}


enum rbc_color rbc_face_top_right_cell(struct rbc_face const * this)
{
	return cell(this, TOP_ROW, RIGHT_COLUMN);
}


enum rbc_color rbc_face_equator_left_cell(struct rbc_face const * this)
{
	return cell(this, EQUATOR_ROW, LEFT_COLUMN);
}


enum rbc_color rbc_face_equator_center_cell(struct rbc_face const * this)
{
	return cell(this, EQUATOR_ROW, MIDDLE_COLUMN);
}


enum rbc_color rbc_face_equator_right_cell(struct rbc_face const * this)
{
	return cell(this, EQUATOR_ROW, RIGHT_COLUMN);
}


enum rbc_color rbc_face_bottom_left_cell(struct rbc_face const * this)
{
	return cell(this, BOTTOM_ROW, LEFT_COLUMN);
}


enum rbc_color rbc_face_bottom_center_cell(struct rbc_face const * this)
{
	return cell(this, BOTTOM_ROW, MIDDLE_COLUMN);
}


enum rbc_color rbc_face_bottom_right_cell(struct rbc_face const * this)
{
	return cell(this, BOTTOM_ROW, RIGHT_COLUMN);
}




/**
 * Paints a row
 *
 * @param this - the face containing the row to paint
 *
 * @param color - the color to apply
 *
 * @param row - the row to paint
 */
static void paint_row(struct rbc_face * this, enum rbc_color color, enum rbc_row row)
{
	int column_index;
	enum rbc_color cells[FACE_SIZE];

	for (column_index = LEFT_COLUMN; column_index <= RIGHT_COLUMN; column_index++)
		cells[column_index] = color;

	set_face_row(this, cells, row);
}


/**
 * Paints the face
 *
 * @param this - the face to paint
 *
 * @param color - the color to apply
 */
static void paint(struct rbc_face * this, enum rbc_color color)
{
	enum rbc_row row;
	for (row = TOP_ROW; row <= BOTTOM_ROW; row++)
		paint_row(this, color, row);
}


struct rbc_face * create_face(enum rbc_color color)
{
	struct rbc_face * this = calloc(1, sizeof(* this));
	if (this != NULL)
		paint(this, color);

	return this;
}


void delete_face(struct rbc_face ** this)
{
	if ((this == NULL) || (* this == NULL))
		return;

	free(* this);
	* this = NULL;
}


void copy_face_row(struct rbc_face const * this, enum rbc_color buffer[FACE_SIZE], enum rbc_row row)
{
	size_t row_size_in_bytes = FACE_SIZE * sizeof(this->cells[row][0]);
	memcpy(buffer, this->cells[row], row_size_in_bytes);
}


void set_face_row(struct rbc_face * face, enum rbc_color const cells[FACE_SIZE], enum rbc_row row)
{
	size_t row_size_in_bytes = FACE_SIZE * sizeof(cells[0]);
	memcpy(face->cells[row], cells, row_size_in_bytes);
}


void copy_face_column(struct rbc_face const * this, enum rbc_color buffer[FACE_SIZE], enum rbc_column column)
{
	enum rbc_row row;
	for (row = TOP_ROW; row <= BOTTOM_ROW; row++)
		buffer[row] = this->cells[row][column];
}


void set_face_column(struct rbc_face * face, enum rbc_color const cells[FACE_SIZE], enum rbc_column column)
{
	enum rbc_row row;
	for (row = TOP_ROW; row <= BOTTOM_ROW; row++)
		face->cells[row][column] = cells[row];
}


void rotate_face_clockwise(struct rbc_face * this)
{
	enum rbc_color new_right_column[FACE_SIZE];
	enum rbc_color new_middle_column[FACE_SIZE];
	enum rbc_color new_left_column[FACE_SIZE];

	copy_face_row(this, new_right_column, TOP_ROW);
	copy_face_row(this, new_middle_column, EQUATOR_ROW);
	copy_face_row(this, new_left_column, BOTTOM_ROW);

	set_face_column(this, new_right_column, RIGHT_COLUMN);
	set_face_column(this, new_middle_column, MIDDLE_COLUMN);
	set_face_column(this, new_left_column, LEFT_COLUMN);
}


void rotate_face_anticlockwise(struct rbc_face * this)
{
	enum rbc_color new_top_row[FACE_SIZE];
	enum rbc_color new_equator_row[FACE_SIZE];
	enum rbc_color new_bottom_row[FACE_SIZE];

	copy_face_column(this, new_top_row, RIGHT_COLUMN);
	copy_face_column(this, new_equator_row, MIDDLE_COLUMN);
	copy_face_column(this, new_bottom_row, LEFT_COLUMN);

	set_face_row(this, new_top_row, TOP_ROW);
	set_face_row(this, new_equator_row, EQUATOR_ROW);
	set_face_row(this, new_bottom_row, BOTTOM_ROW);
}
