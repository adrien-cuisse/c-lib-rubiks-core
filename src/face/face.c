
#include "face.h"

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




enum rbc_color rbc_face_color(struct rbc_face const * self)
{
	/* center cells are fixed */
	return rbc_face_equator_center_cell(self);
}


/**
 * Returns the color of a cell
 *
 * @param self - the face to get a the cell from
 *
 * @param row - the row where the cell is
 *
 * @param column - the column where the cell is
 *
 * @return enum rbc_color - the color of the requested cell
 */
static enum rbc_color cell(struct rbc_face const * self, enum rbc_span_location row, enum rbc_span_location column)
{
	return self->cells[row][column];
}


enum rbc_color rbc_face_top_left_cell(struct rbc_face const * self)
{
	return cell(self, RBC_TOP_ROW, RBC_LEFT_COLUMN);
}


enum rbc_color rbc_face_top_center_cell(struct rbc_face const * self)
{
	return cell(self, RBC_TOP_ROW, RBC_MIDDLE_COLUMN);
}


enum rbc_color rbc_face_top_right_cell(struct rbc_face const * self)
{
	return cell(self, RBC_TOP_ROW, RBC_RIGHT_COLUMN);
}


enum rbc_color rbc_face_equator_left_cell(struct rbc_face const * self)
{
	return cell(self, RBC_EQUATOR_ROW, RBC_LEFT_COLUMN);
}


enum rbc_color rbc_face_equator_center_cell(struct rbc_face const * self)
{
	return cell(self, RBC_EQUATOR_ROW, RBC_MIDDLE_COLUMN);
}


enum rbc_color rbc_face_equator_right_cell(struct rbc_face const * self)
{
	return cell(self, RBC_EQUATOR_ROW, RBC_RIGHT_COLUMN);
}


enum rbc_color rbc_face_bottom_left_cell(struct rbc_face const * self)
{
	return cell(self, RBC_BOTTOM_ROW, RBC_LEFT_COLUMN);
}


enum rbc_color rbc_face_bottom_center_cell(struct rbc_face const * self)
{
	return cell(self, RBC_BOTTOM_ROW, RBC_MIDDLE_COLUMN);
}


enum rbc_color rbc_face_bottom_right_cell(struct rbc_face const * self)
{
	return cell(self, RBC_BOTTOM_ROW, RBC_RIGHT_COLUMN);
}




/**
 * Paints a row
 *
 * @param self - the face containing the row to paint
 *
 * @param color - the color to apply
 *
 * @param row - the row to paint
 */
static void rbc_paint_row(struct rbc_face * self, enum rbc_color color, enum rbc_span_location row)
{
	int column_index;
	enum rbc_color cells[FACE_SIZE];

	for (column_index = RBC_LEFT_COLUMN; column_index <= RBC_RIGHT_COLUMN; column_index++)
		cells[column_index] = color;

	rbc_set_face_row(self, cells, row);
}


/**
 * Paints the face
 *
 * @param self - the face to paint
 *
 * @param color - the color to apply
 */
static void rbc_paint(struct rbc_face * self, enum rbc_color color)
{
	enum rbc_span_location row;
	for (row = RBC_TOP_ROW; row <= RBC_BOTTOM_ROW; row++)
		rbc_paint_row(self, color, row);
}


struct rbc_face * rbc_create_face(enum rbc_color color)
{
	struct rbc_face * self = calloc(1, sizeof(* self));
	if (self != NULL)
		rbc_paint(self, color);

	return self;
}


void rbc_delete_face(struct rbc_face ** self)
{
	if ((self == NULL) || (* self == NULL))
		return;

	free(* self);
	* self = NULL;
}


void rbc_copy_face_row(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE], enum rbc_span_location row)
{
	size_t row_size_in_bytes = FACE_SIZE * sizeof(face->cells[row][0]);
	memcpy(buffer, face->cells[row], row_size_in_bytes);
}


void rbc_set_face_row(struct rbc_face * face, enum rbc_color const cells[FACE_SIZE], enum rbc_span_location row)
{
	size_t row_size_in_bytes = FACE_SIZE * sizeof(cells[0]);
	memcpy(face->cells[row], cells, row_size_in_bytes);
}


void rbc_copy_face_column(struct rbc_face const * face, enum rbc_color buffer[FACE_SIZE], enum rbc_span_location column)
{
	enum rbc_span_location row;
	for (row = RBC_TOP_ROW; row <= RBC_BOTTOM_ROW; row++)
		buffer[row] = face->cells[row][column];
}


void rbc_set_face_column(struct rbc_face * face, enum rbc_color const cells[FACE_SIZE], enum rbc_span_location column)
{
	enum rbc_span_location row;
	for (row = RBC_TOP_ROW; row <= RBC_BOTTOM_ROW; row++)
		face->cells[row][column] = cells[row];
}


void rbc_rotate_face_clockwise(struct rbc_face * self)
{
	enum rbc_color new_right_column[FACE_SIZE];
	enum rbc_color new_middle_column[FACE_SIZE];
	enum rbc_color new_left_column[FACE_SIZE];

	rbc_copy_face_row(self, new_right_column, RBC_TOP_ROW);
	rbc_copy_face_row(self, new_middle_column, RBC_EQUATOR_ROW);
	rbc_copy_face_row(self, new_left_column, RBC_BOTTOM_ROW);

	rbc_set_face_column(self, new_right_column, RBC_RIGHT_COLUMN);
	rbc_set_face_column(self, new_middle_column, RBC_MIDDLE_COLUMN);
	rbc_set_face_column(self, new_left_column, RBC_LEFT_COLUMN);
}


void rbc_rotate_face_anticlockwise(struct rbc_face * self)
{
	enum rbc_color new_top_row[FACE_SIZE];
	enum rbc_color new_equator_row[FACE_SIZE];
	enum rbc_color new_bottom_row[FACE_SIZE];

	rbc_copy_face_column(self, new_top_row, RBC_RIGHT_COLUMN);
	rbc_copy_face_column(self, new_equator_row, RBC_MIDDLE_COLUMN);
	rbc_copy_face_column(self, new_bottom_row, RBC_LEFT_COLUMN);

	rbc_set_face_row(self, new_top_row, RBC_TOP_ROW);
	rbc_set_face_row(self, new_equator_row, RBC_EQUATOR_ROW);
	rbc_set_face_row(self, new_bottom_row, RBC_BOTTOM_ROW);
}
