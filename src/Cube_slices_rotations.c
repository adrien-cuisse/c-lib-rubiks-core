
#include <stdlib.h>
#include <string.h>

#include "Face.h"
#include "Cube.h"

/**
 * Some functions rely on how we unfold the 3D cube, switching to another
 * 2D pattern will affect the marked functions
 * On the current pattern, 4 faces are vertically aligned, and only 3 are
 * horizontally aligned, so when doing horizontal slice rotations back face is
 * flipped, and parallel slices are switching axis on every span
 */
#define PATTERN_DEPENDANT




/**
 * Coords of a 2D span, a row or a column on a face
 *
 * One coord must be set to -1, i
 */
typedef struct
{
	FacePosition face;

	/**
	 * -1 if the span is a column
	 */
	Row row;

	/**
	 * -1 if the span is a row
	 */
	Column column;
} Span;


/**
 * A 3D Slice is made of 4 2D Spans
 */
typedef Span Slice[4];




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
static void rotate_slice(
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


/**
 * Rotates an horizontal slice to the left
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_left(Cube * this, Slice slice)
{
	FacePosition reversing_spans_face[2] = { LEFT_FACE, BACK_FACE };
	rotate_slice(this, slice, reversing_spans_face, 2);
}


/**
 * Rotates an horizontal slice to the right
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_right(Cube * this, Slice slice)
{
	FacePosition reversing_spans_face[2] = { RIGHT_FACE, BACK_FACE };
	rotate_slice(this, slice, reversing_spans_face, 2);
}


void rubiks_cube_rotate_top_slice_left(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, TOP_ROW, -1 },
		{ BACK_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, TOP_ROW, -1 }
	};
	rotate_slice_left(this, slice);
	rotate_face_clockwise(rubiks_cube_top_face(this));
}


void rubiks_cube_rotate_top_slice_right(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, TOP_ROW, -1 },
		{ BACK_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, TOP_ROW, -1 }
	};
	rotate_slice_right(this, slice);
	rotate_face_anticlockwise(rubiks_cube_top_face(this));
}


void rubiks_cube_rotate_equator_slice_left(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, EQUATOR_ROW, -1 },
		{ BACK_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, EQUATOR_ROW, -1 }
	};
	rotate_slice_left(this, slice);
}


void rubiks_cube_rotate_equator_slice_right(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, EQUATOR_ROW, -1 },
		{ BACK_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, EQUATOR_ROW, -1 }
	};
	rotate_slice_right(this, slice);
}


void rubiks_cube_rotate_bottom_slice_left(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, BOTTOM_ROW, -1 },
		{ BACK_FACE, TOP_ROW, -1},
		{ RIGHT_FACE, BOTTOM_ROW, -1 }
	};
	rotate_slice_left(this, slice);
	rotate_face_anticlockwise(rubiks_cube_bottom_face(this));
}


void rubiks_cube_rotate_bottom_slice_right(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, BOTTOM_ROW, -1 },
		{ BACK_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, BOTTOM_ROW, -1 }
	};
	rotate_slice_right(this, slice);
	rotate_face_clockwise(rubiks_cube_bottom_face(this));
}


/**
 * Applies a vertical slice rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param column - the column of the slice to rotate
 *
 * @param rotation - the rotation to apply
 */
static void rotate_vertical_slice(Cube * this, Column column, Rotation rotation)
{
	int span_index;
	Slice slice;

	for (span_index = 0; span_index < 4; span_index++)
	{
		slice[span_index].face = rotation[span_index];
		slice[span_index].row = -1;
		slice[span_index].column = column;
	}

	rotate_slice(this, slice, NULL, 0);
}


/**
 * Applies a vertical slice up rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param column - the column of the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_up(Cube * this, Column column)
{
	Rotation rotation = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };
	rotate_vertical_slice(this, column, rotation);
}


/**
 * Applies a vertical slice down rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param column - the column of the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_down(Cube * this, Column column)
{
	Rotation rotation = { FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE };
	rotate_vertical_slice(this, column, rotation);
}


void rubiks_cube_rotate_left_slice_up(Cube * this)
{
	rotate_slice_up(this, LEFT_COLUMN);
	rotate_face_anticlockwise(rubiks_cube_left_face(this));
}


void rubiks_cube_rotate_left_slice_down(Cube * this)
{
	rotate_slice_down(this, LEFT_COLUMN);
	rotate_face_clockwise(rubiks_cube_left_face(this));
}


void rubiks_cube_rotate_middle_slice_up(Cube * this)
{
	rotate_slice_up(this, MIDDLE_COLUMN);
}


void rubiks_cube_rotate_middle_slice_down(Cube * this)
{
	rotate_slice_down(this, MIDDLE_COLUMN);
}


void rubiks_cube_rotate_right_slice_up(Cube * this)
{
	rotate_slice_up(this, RIGHT_COLUMN);
	rotate_face_clockwise(rubiks_cube_right_face(this));
}


void rubiks_cube_rotate_right_slice_down(Cube * this)
{
	rotate_slice_down(this, RIGHT_COLUMN);
	rotate_face_anticlockwise(rubiks_cube_right_face(this));
}


/**
 * Applies a parallel slice clockwise rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_clockwise(Cube * this, Slice slice)
{
	FacePosition reversing_spans_face[2] = { RIGHT_FACE, LEFT_FACE };
	rotate_slice(this, slice, reversing_spans_face, 2);
}


void rubiks_cube_rotate_front_slice_clockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN }
	};
	rotate_slice_clockwise(this, slice);
	rotate_face_clockwise(rubiks_cube_front_face(this));
}


/**
 * Applies a parallel slice anticlockwise rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_anticlockwise(Cube * this, Slice slice)
{
	FacePosition reversing_spans_face[2] = { TOP_FACE, BOTTOM_FACE };
	rotate_slice(this, slice, reversing_spans_face, 2);
}


void rubiks_cube_rotate_front_slice_anticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN }
	};
	rotate_slice_anticlockwise(this, slice);
	rotate_face_anticlockwise(rubiks_cube_front_face(this));
}


void rubiks_cube_rotate_standing_slice_clockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN }
	};
	rotate_slice_clockwise(this, slice);
}


void rubiks_cube_rotate_standing_slice_anticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN }
	};
	rotate_slice_anticlockwise(this, slice);
}


void rubiks_cube_rotate_back_slice_clockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN }
	};
	rotate_slice_clockwise(this, slice);
	rotate_face_anticlockwise(rubiks_cube_back_face(this));
}


void rubiks_cube_rotate_back_slice_anticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN }
	};
	rotate_slice_anticlockwise(this, slice);
	rotate_face_clockwise(rubiks_cube_back_face(this));
}


void rubiks_cube_rotate_top_slices_left(Cube * this)
{
	rubiks_cube_rotate_top_slice_left(this);
	rubiks_cube_rotate_equator_slice_left(this);
}


void rubiks_cube_rotate_top_slices_right(Cube * this)
{
	rubiks_cube_rotate_top_slice_right(this);
	rubiks_cube_rotate_equator_slice_right(this);
}


void rubiks_cube_rotate_outer_slices_left(Cube * this)
{
	rubiks_cube_rotate_top_slice_left(this);
	rubiks_cube_rotate_bottom_slice_left(this);
}


void rubiks_cube_rotate_outer_slices_right(Cube * this)
{
	rubiks_cube_rotate_top_slice_right(this);
	rubiks_cube_rotate_bottom_slice_right(this);
}


void rubiks_cube_rotate_bottom_slices_left(Cube * this)
{
	rubiks_cube_rotate_equator_slice_left(this);
	rubiks_cube_rotate_bottom_slice_left(this);
}


void rubiks_cube_rotate_bottom_slices_right(Cube * this)
{
	rubiks_cube_rotate_equator_slice_right(this);
	rubiks_cube_rotate_bottom_slice_right(this);
}


void rubiks_cube_rotate_left_slices_up(Cube * this)
{
	rubiks_cube_rotate_left_slice_up(this);
	rubiks_cube_rotate_middle_slice_up(this);
}


void rubiks_cube_rotate_left_slices_down(Cube * this)
{
	rubiks_cube_rotate_left_slice_down(this);
	rubiks_cube_rotate_middle_slice_down(this);
}


void rubiks_cube_rotate_outer_slices_up(Cube * this)
{
	rubiks_cube_rotate_left_slice_up(this);
	rubiks_cube_rotate_right_slice_up(this);
}


void rubiks_cube_rotate_outer_slices_down(Cube * this)
{
	rubiks_cube_rotate_left_slice_down(this);
	rubiks_cube_rotate_right_slice_down(this);
}


void rubiks_cube_rotate_right_slices_up(Cube * this)
{
	rubiks_cube_rotate_middle_slice_up(this);
	rubiks_cube_rotate_right_slice_up(this);
}


void rubiks_cube_rotate_right_slices_down(Cube * this)
{
	rubiks_cube_rotate_middle_slice_down(this);
	rubiks_cube_rotate_right_slice_down(this);
}


void rubiks_cube_rotate_front_slices_clockwise(Cube * this)
{
	rubiks_cube_rotate_front_slice_clockwise(this);
	rubiks_cube_rotate_standing_slice_clockwise(this);
}


void rubiks_cube_rotate_front_slices_anticlockwise(Cube * this)
{
	rubiks_cube_rotate_front_slice_anticlockwise(this);
	rubiks_cube_rotate_standing_slice_anticlockwise(this);
}


void rubiks_cube_rotate_outer_slices_clockwise(Cube * this)
{
	rubiks_cube_rotate_front_slice_clockwise(this);
	rubiks_cube_rotate_back_slice_clockwise(this);
}


void rubiks_cube_rotate_outer_slices_anticlockwise(Cube * this)
{
	rubiks_cube_rotate_front_slice_anticlockwise(this);
	rubiks_cube_rotate_back_slice_anticlockwise(this);
}


void rubiks_cube_rotate_back_slices_clockwise(Cube * this)
{
	rubiks_cube_rotate_standing_slice_clockwise(this);
	rubiks_cube_rotate_back_slice_clockwise(this);
}


void rubiks_cube_rotate_back_slices_anticlockwise(Cube * this)
{
	rubiks_cube_rotate_standing_slice_anticlockwise(this);
	rubiks_cube_rotate_back_slice_anticlockwise(this);
}
