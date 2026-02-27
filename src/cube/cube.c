
#include "../face/face.h"
#include "cube.h"

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
 * @param self - the cube to store faces in
 */
static void create_and_position_faces(struct rbc_cube * self)
{
	int face_index;

	self->faces[RBC_LEFT_FACE] = create_face(RBC_RED);
	self->faces[RBC_FRONT_FACE] = create_face(RBC_BLUE);
	self->faces[RBC_RIGHT_FACE] = create_face(RBC_ORANGE);
	self->faces[RBC_TOP_FACE] = create_face(RBC_WHITE);
	self->faces[RBC_BOTTOM_FACE] = create_face(RBC_YELLOW);
	self->faces[RBC_BACK_FACE] = create_face(RBC_GREEN);

	for (face_index = 0; face_index < 6; face_index++)
	{
		if (self->faces[face_index] == NULL)
		{
			rbc_delete_cube(& self);
			return;
		}
	}
}


struct rbc_cube * rbc_create_cube(void)
{
	struct rbc_cube * self = calloc(1, sizeof(* self));
	if (self != NULL)
		create_and_position_faces(self);

	return self;
}


void rbc_delete_cube(struct rbc_cube ** self)
{
	enum rbc_face_location position;

	if ((self == NULL) || (* self == NULL))
		return;

	for (position = 0; position < 6; position++)
	{
		delete_face(& (* self)->faces[position]);
		(* self)->faces[position] = NULL;
	}

	free(* self);
	* self = NULL;
}


/**
 * Checks if the given color is valid
 *
 * @param color - the color to check
 *
 * @return - 1 if, and only if, color is not in the rbc_color enum
 */
static int color_is_invalid(enum rbc_color color)
{
	return (color != RBC_BLUE)
		&& (color != RBC_GREEN)
		&& (color != RBC_ORANGE)
		&& (color != RBC_RED)
		&& (color != RBC_WHITE)
		&& (color != RBC_YELLOW);
}


/**
 * Returns the color opposing the given one, in standard disposition
 * If an invalid color is given, RBC_WHITE is returned
 *
 * @param color - the color to get the opposite one from
 *
 * @return - the color of the face opposing the given one
 */
static enum rbc_color standard_opposite_color(enum rbc_color color)
{
	switch (color)
	{
		case RBC_BLUE: return RBC_GREEN;
		case RBC_WHITE: return RBC_YELLOW;
		case RBC_RED: return RBC_ORANGE;
		case RBC_GREEN: return RBC_BLUE;
		case RBC_ORANGE: return RBC_RED;
		default: return RBC_WHITE;
	}
}


void rbc_orientate_cube(struct rbc_cube * cube, enum rbc_color front_face_color, enum rbc_color top_face_color)
{
	if (front_face_color == top_face_color)
		return;
	if (color_is_invalid(front_face_color) || color_is_invalid(top_face_color))
		return;
	if (standard_opposite_color(front_face_color) == top_face_color)
		return;

	if (rbc_face_color(rbc_cube_left_face(cube)) == front_face_color)
		rbc_rotate_cube_right(cube);

	if (rbc_face_color(rbc_cube_right_face(cube)) == front_face_color)
		rbc_rotate_cube_left(cube);

	while (rbc_face_color(rbc_cube_front_face(cube)) != front_face_color)
		rbc_rotate_cube_up(cube);

	while (rbc_face_color(rbc_cube_top_face(cube)) != top_face_color)
		rbc_rotate_cube_clockwise(cube);
}


/**
 * Returns a face of the cube
 *
 * @param self - the cube to get a face from
 *
 * @param position - the face to get
 *
 * @return struct rbc_face * - the requested face
 */
static struct rbc_face * get_face(struct rbc_cube const * self, enum rbc_face_location position)
{
	return self->faces[position];
}


struct rbc_face * rbc_cube_left_face(struct rbc_cube const * self)
{
	return get_face(self, RBC_LEFT_FACE);
}


struct rbc_face * rbc_cube_front_face(struct rbc_cube const * self)
{
	return get_face(self, RBC_FRONT_FACE);
}


struct rbc_face * rbc_cube_right_face(struct rbc_cube const * self)
{
	return get_face(self, RBC_RIGHT_FACE);
}


struct rbc_face * rbc_cube_top_face(struct rbc_cube const * self)
{
	return get_face(self, RBC_TOP_FACE);
}


struct rbc_face * rbc_cube_bottom_face(struct rbc_cube const * self)
{
	return get_face(self, RBC_BOTTOM_FACE);
}


struct rbc_face * rbc_cube_back_face(struct rbc_cube const * self)
{
	return get_face(self, RBC_BACK_FACE);
}




void rotate_cube(struct rbc_cube * self, struct rbc_faces_cycle const * rotation)
{
	struct rbc_face * backup = self->faces[rotation->faces_location[3]];

	self->faces[rotation->faces_location[3]] = self->faces[rotation->faces_location[2]];
	self->faces[rotation->faces_location[2]] = self->faces[rotation->faces_location[1]];
	self->faces[rotation->faces_location[1]] = self->faces[rotation->faces_location[0]];
	self->faces[rotation->faces_location[0]] = backup;
}


/**
 * Reads a span on the cube
 *
 * @param self - the cube to get a span from
 *
 * @param span - the coords of the span to read
 *
 * @param buffer - the buffer where to write the span
 */
static void get_span(struct rbc_cube const * self, struct rbc_span span, enum rbc_color buffer[FACE_SIZE])
{
	if (span.type == RBC_ROW)
		copy_face_row(self->faces[span.face_location], buffer, span.location);
	else
		copy_face_column(self->faces[span.face_location], buffer, span.location);
}


/**
 * Writes a span on the cube
 *
 * @param self - the cube to write a span to
 *
 * @param span - the coords of the span to write
 *
 * @param content - the content of the span to write
 */
static void set_span(struct rbc_cube * self, struct rbc_span span, enum rbc_color const content[FACE_SIZE])
{
	if (span.type == RBC_ROW)
		set_face_row(self->faces[span.face_location], content, span.location);
	else
		set_face_column(self->faces[span.face_location], content, span.location);
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
 * @param self - the cube to read/write spans from
 *
 * @param from - the span to copy
 *
 * @param to - where to write the copied span
 */
static void move_span(struct rbc_cube * self, struct rbc_span from, struct rbc_span to)
{
	enum rbc_color span[FACE_SIZE];
	get_span(self, from, span);
	set_span(self, to, span);
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
 * @param self - the cube to read/write spans from
 *
 * @param from - the span to copy
 *
 * @param to - where to write the copied span
 */
static void move_reversed_span(struct rbc_cube * self, struct rbc_span from, struct rbc_span to)
{
	enum rbc_color span_content[FACE_SIZE];
	get_span(self, from, span_content);
	reverse_span(span_content);
	set_span(self, to, span_content);
}


/**
 * Applies a slice rotation on the cube
 *
 * @param self - the cube containing the slice to rotate
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
	struct rbc_cube * self,
	struct rbc_slice const * slice,
	enum rbc_face_location const reversing_spans_face[],
	int reversing_count)
{
	int span_index;

	struct rbc_span source_span, destination_span;

	enum rbc_color span_backup[FACE_SIZE];
	get_span(self, slice->spans[3], span_backup);

	for (span_index = 3; span_index > 0; span_index--)
	{
		source_span = slice->spans[span_index - 1];
		destination_span = slice->spans[span_index];

		if (must_reverse_span(source_span, reversing_spans_face, reversing_count))
			move_reversed_span(self, source_span, destination_span);
		else
			move_span(self, source_span, destination_span);
	}

	source_span = slice->spans[3];
	if (must_reverse_span(source_span, reversing_spans_face, reversing_count))
		reverse_span(span_backup);

	destination_span = slice->spans[0];
	set_span(self, destination_span, span_backup);
}
