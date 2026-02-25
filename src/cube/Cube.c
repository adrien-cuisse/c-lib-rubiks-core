
#include "../face/Face.h"
#include "Cube.h"

#include <stdlib.h>




/**
 * A 3D cube made of 6 2D faces
 */
struct rbc_cube
{
	/**
	 * The 2D faces composing the cube
	 */
	struct rbc_face * faces[6];
};




/**
 * Allocates faces and stores them in the cube
 *
 * @param this - the cube to store faces in
 */
static void create_and_position_faces(struct rbc_cube * this)
{
	int face_index;

	this->faces[LEFT_FACE] = create_face(RED);
	this->faces[FRONT_FACE] = create_face(BLUE);
	this->faces[RIGHT_FACE] = create_face(ORANGE);
	this->faces[TOP_FACE] = create_face(WHITE);
	this->faces[BOTTOM_FACE] = create_face(YELLOW);
	this->faces[BACK_FACE] = create_face(GREEN);

	for (face_index = 0; face_index < 6; face_index++)
	{
		if (this->faces[face_index] == NULL)
		{
			rbc_delete_cube(& this);
			return;
		}
	}
}


struct rbc_cube * rbc_create_cube(void)
{
	struct rbc_cube * this = calloc(1, sizeof(* this));
	if (this != NULL)
		create_and_position_faces(this);

	return this;
}


void rbc_delete_cube(struct rbc_cube ** this)
{
	enum rbc_face_location position;

	if ((this == NULL) || (* this == NULL))
		return;

	for (position = 0; position < 6; position++)
	{
		delete_face(& (* this)->faces[position]);
		(* this)->faces[position] = NULL;
	}

	free(* this);
	* this = NULL;
}


/**
 * Returns a face of the cube
 *
 * @param this - the cube to get a face from
 *
 * @param position - the face to get
 *
 * @return struct rbc_face * - the requested face
 */
static struct rbc_face * get_face(struct rbc_cube const * this, enum rbc_face_location position)
{
	return this->faces[position];
}


struct rbc_face * rbc_cube_left_face(struct rbc_cube const * this)
{
	return get_face(this, LEFT_FACE);
}


struct rbc_face * rbc_cube_front_face(struct rbc_cube const * this)
{
	return get_face(this, FRONT_FACE);
}


struct rbc_face * rbc_cube_right_face(struct rbc_cube const * this)
{
	return get_face(this, RIGHT_FACE);
}


struct rbc_face * rbc_cube_top_face(struct rbc_cube const * this)
{
	return get_face(this, TOP_FACE);
}


struct rbc_face * rbc_cube_bottom_face(struct rbc_cube const * this)
{
	return get_face(this, BOTTOM_FACE);
}


struct rbc_face * rbc_cube_back_face(struct rbc_cube const * this)
{
	return get_face(this, BACK_FACE);
}




void rotate_cube(struct rbc_cube * this, struct rbc_faces_cycle const * rotation)
{
	struct rbc_face * backup = this->faces[rotation->faces_location[3]];

	this->faces[rotation->faces_location[3]] = this->faces[rotation->faces_location[2]];
	this->faces[rotation->faces_location[2]] = this->faces[rotation->faces_location[1]];
	this->faces[rotation->faces_location[1]] = this->faces[rotation->faces_location[0]];
	this->faces[rotation->faces_location[0]] = backup;
}


/**
 * Reads a span on the cube
 *
 * @param this - the cube to get a span from
 *
 * @param span - the coords of the span to read
 *
 * @param buffer - the buffer where to write the span
 */
static void get_span(struct rbc_cube const * this, struct rbc_span span, enum rbc_color buffer[FACE_SIZE])
{
	int is_row = (span.column == (Column) -1);
	if (is_row)
		copy_face_row(this->faces[span.face_location], buffer, span.row);
	else
		copy_face_column(this->faces[span.face_location], buffer, span.column);
}


/**
 * Writes a span on the cube
 *
 * @param this - the cube to write a span to
 *
 * @param span - the coords of the span to write
 *
 * @param content - the content of the span to write
 */
static void set_span(struct rbc_cube * this, struct rbc_span span, enum rbc_color const content[FACE_SIZE])
{
	int is_row = (span.column == (Column) -1);
	if (is_row)
		set_face_row(this->faces[span.face_location], content, span.row);
	else
		set_face_column(this->faces[span.face_location], content, span.column);
}


/**
 * Checks if the span must be reversed, ie., if its face is in [reversing_faces]
 *
 * @param span - the span to check
 *
 * @param reversing_faces - the faces where spans should be reversed
 *
 * @param faces_count - the number of faces in [reversing_faces]
 *
 * @return int - 1 if span's face is in [reversing_faces], 0 otherwise
 */
static int must_reverse_span(
	struct rbc_span span,
	enum rbc_face_location const reversing_faces[],
	int faces_count)
{
	int index;

	for (index = 0; index < faces_count; index++)
	{
		if (span.face_location == reversing_faces[index])
			return 1;
	}

	return 0;
}


/**
 * Copies a span and pastes it on another location
 *
 * @param this - the cube to read/write spans from
 *
 * @param from - the span to copy
 *
 * @param to - where to write the copied span
 */
static void move_span(struct rbc_cube * this, struct rbc_span from, struct rbc_span to)
{
	enum rbc_color span[FACE_SIZE];
	get_span(this, from, span);
	set_span(this, to, span);
}


/**
 * Reverses a span
 *
 * @param span - the span to reverse
 */
static void reverse_span(enum rbc_color span[FACE_SIZE])
{
	enum rbc_color swap = span[0];
	span[0] = span[2];
	span[2] = swap;
}


/**
 * Copies, reverses and pastes a span
 *
 * @param this - the cube to read/write spans from
 *
 * @param from - the span to copy
 *
 * @param to - where to write the copied span
 */
static void move_reversed_span(struct rbc_cube * this, struct rbc_span from, struct rbc_span to)
{
	enum rbc_color span_content[FACE_SIZE];
	get_span(this, from, span_content);
	reverse_span(span_content);
	set_span(this, to, span_content);
}


/**
 * Applies a slice rotation on the cube
 *
 * @param this - the cube containing the slice to rotate
 *
 * @param slice - the slice to rotate
 *
 * @param reversing_spans_face - array of enum rbc_face_location, any span in the slice
 * 	having its face in that array will be reversed
 *
 * @param reversing_count - the number of faces in [reversing_spans_face]
 * 	(ie., the number of spans to reverse in the slice)
 */
void rotate_slice(
	struct rbc_cube * this,
	struct rbc_slice const * slice,
	enum rbc_face_location const reversing_spans_face[],
	int reversing_count)
{
	int span_index;

	struct rbc_span source_span, destination_span;

	enum rbc_color span_backup[FACE_SIZE];
	get_span(this, slice->spans[3], span_backup);

	for (span_index = 3; span_index > 0; span_index--)
	{
		source_span = slice->spans[span_index - 1];
		destination_span = slice->spans[span_index];

		if (must_reverse_span(source_span, reversing_spans_face, reversing_count))
			move_reversed_span(this, source_span, destination_span);
		else
			move_span(this, source_span, destination_span);
	}

	source_span = slice->spans[3];
	if (must_reverse_span(source_span, reversing_spans_face, reversing_count))
		reverse_span(span_backup);

	destination_span = slice->spans[0];
	set_span(this, destination_span, span_backup);
}
