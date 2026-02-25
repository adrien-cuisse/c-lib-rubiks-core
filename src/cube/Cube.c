
#include <stdlib.h>

#include "../face/Face.h"
#include "Cube.h"




/**
 * A 3D Cube made of 6 2D faces
 */
struct Cube
{
	/**
	 * The 2D faces composing the cube
	 */
	Face * faces[6];
};




/**
 * Allocates faces and stores them in the cube
 *
 * @param this - the cube to store faces in
 */
static void create_and_position_faces(Cube * this)
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
			rubiks_cube_delete(& this);
			return;
		}
	}
}


Cube * rubiks_cube_create(void)
{
	Cube * this = calloc(1, sizeof(* this));
	if (this != NULL)
		create_and_position_faces(this);

	return this;
}


void rubiks_cube_delete(Cube ** this)
{
	FacePosition position;

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
 * @return Face * - the requested face
 */
static Face * get_face(Cube const * this, FacePosition position)
{
	return this->faces[position];
}


Face * rubiks_cube_left_face(Cube const * this)
{
	return get_face(this, LEFT_FACE);
}


Face * rubiks_cube_front_face(Cube const * this)
{
	return get_face(this, FRONT_FACE);
}


Face * rubiks_cube_right_face(Cube const * this)
{
	return get_face(this, RIGHT_FACE);
}


Face * rubiks_cube_top_face(Cube const * this)
{
	return get_face(this, TOP_FACE);
}


Face * rubiks_cube_bottom_face(Cube const * this)
{
	return get_face(this, BOTTOM_FACE);
}


Face * rubiks_cube_back_face(Cube const * this)
{
	return get_face(this, BACK_FACE);
}




void rotate_cube(Cube * this, Rotation rotation)
{
	Face * backup = this->faces[rotation[3]];

	this->faces[rotation[3]] = this->faces[rotation[2]];
	this->faces[rotation[2]] = this->faces[rotation[1]];
	this->faces[rotation[1]] = this->faces[rotation[0]];
	this->faces[rotation[0]] = backup;
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
static void get_span(Cube const * this, Span span, Color buffer[FACE_SIZE])
{
	int is_row = (span.column == (Column) -1);
	if (is_row)
		copy_face_row(this->faces[span.face], buffer, span.row);
	else
		copy_face_column(this->faces[span.face], buffer, span.column);
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
static void set_span(Cube * this, Span span, Color const content[FACE_SIZE])
{
	int is_row = (span.column == (Column) -1);
	if (is_row)
		set_face_row(this->faces[span.face], content, span.row);
	else
		set_face_column(this->faces[span.face], content, span.column);
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
	Span span,
	FacePosition const reversing_faces[],
	int faces_count)
{
	int index;

	for (index = 0; index < faces_count; index++)
	{
		if (span.face == reversing_faces[index])
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
static void move_span(Cube * this, Span from, Span to)
{
	Color span[FACE_SIZE];
	get_span(this, from, span);
	set_span(this, to, span);
}


/**
 * Reverses a span
 *
 * @param span - the span to reverse
 */
static void reverse_span(Color span[FACE_SIZE])
{
	Color swap = span[0];
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
static void move_reversed_span(Cube * this, Span from, Span to)
{
	Color span_content[FACE_SIZE];
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
 * @param reversing_spans_face - array of FacePosition, any span in the slice
 * 	having its face in that array will be reversed
 *
 * @param reversing_count - the number of faces in [reversing_spans_face]
 * 	(ie., the number of spans to reverse in the slice)
 */
void rotate_slice(
	Cube * this,
	Slice slice,
	FacePosition const reversing_spans_face[],
	int reversing_count)
{
	int span_index;

	Span source_span, destination_span;

	Color span_backup[FACE_SIZE];
	get_span(this, slice[3], span_backup);

	for (span_index = 3; span_index > 0; span_index--)
	{
		source_span = slice[span_index - 1];
		destination_span = slice[span_index];

		if (must_reverse_span(source_span, reversing_spans_face, reversing_count))
			move_reversed_span(this, source_span, destination_span);
		else
			move_span(this, source_span, destination_span);
	}

	source_span = slice[3];
	if (must_reverse_span(source_span, reversing_spans_face, reversing_count))
		reverse_span(span_backup);

	destination_span = slice[0];
	set_span(this, destination_span, span_backup);
}
