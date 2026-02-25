
#include "../face/Face.h"
#include "Cube.h"

#include <stdlib.h>

/**
 * Some functions rely on how we unfold the 3D cube, switching to another
 * 2D pattern will affect the marked functions
 * On the current pattern, 4 faces are vertically aligned, and only 3 are
 * horizontally aligned, so when doing horizontal slice rotations back face is
 * flipped, and parallel slices are switching axis on every span
 */
#define PATTERN_DEPENDANT




/**
 * Rotates an horizontal slice to the left
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_left(struct rbc_cube * this, struct rbc_slice const * slice)
{
	enum rbc_face_location reversing_spans_face[2] = { LEFT_FACE, BACK_FACE };
	rotate_slice(this, slice, reversing_spans_face, 2);
}


/**
 * Rotates an horizontal slice to the right
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_right(struct rbc_cube * this, struct rbc_slice const * slice)
{
	enum rbc_face_location reversing_spans_face[2] = { RIGHT_FACE, BACK_FACE };
	rotate_slice(this, slice, reversing_spans_face, 2);
}


void rbc_rotate_cube_top_slice_left(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ FRONT_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, TOP_ROW, -1 },
		{ BACK_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, TOP_ROW, -1 }
	}};
	rotate_slice_left(this, & slice);
	rotate_face_clockwise(rbc_cube_top_face(this));
}


void rbc_rotate_cube_top_slice_right(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ FRONT_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, TOP_ROW, -1 },
		{ BACK_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, TOP_ROW, -1 }
	}};
	rotate_slice_right(this, & slice);
	rotate_face_anticlockwise(rbc_cube_top_face(this));
}


void rbc_rotate_cube_equator_slice_left(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ FRONT_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, EQUATOR_ROW, -1 },
		{ BACK_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, EQUATOR_ROW, -1 }
	}};
	rotate_slice_left(this, & slice);
}


void rbc_rotate_cube_equator_slice_right(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ FRONT_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, EQUATOR_ROW, -1 },
		{ BACK_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, EQUATOR_ROW, -1 }
	}};
	rotate_slice_right(this, & slice);
}


void rbc_rotate_cube_bottom_slice_left(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ FRONT_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, BOTTOM_ROW, -1 },
		{ BACK_FACE, TOP_ROW, -1},
		{ RIGHT_FACE, BOTTOM_ROW, -1 }
	}};
	rotate_slice_left(this, & slice);
	rotate_face_anticlockwise(rbc_cube_bottom_face(this));
}


void rbc_rotate_cube_bottom_slice_right(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ FRONT_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, BOTTOM_ROW, -1 },
		{ BACK_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, BOTTOM_ROW, -1 }
	}};
	rotate_slice_right(this, & slice);
	rotate_face_clockwise(rbc_cube_bottom_face(this));
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
static void rotate_vertical_slice(struct rbc_cube * this, Column column, struct rbc_faces_cycle const * rotation)
{
	int span_index;
	struct rbc_slice slice;

	for (span_index = 0; span_index < 4; span_index++)
	{
		slice.spans[span_index].face_location = rotation->faces_location[span_index];
		slice.spans[span_index].row = -1;
		slice.spans[span_index].column = column;
	}

	rotate_slice(this, & slice, NULL, 0);
}


/**
 * Applies a vertical slice up rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param column - the column of the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_up(struct rbc_cube * this, Column column)
{
	struct rbc_faces_cycle rotation = {{ FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE }};
	rotate_vertical_slice(this, column, & rotation);
}


/**
 * Applies a vertical slice down rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param column - the column of the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_down(struct rbc_cube * this, Column column)
{
	struct rbc_faces_cycle rotation = {{ FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE }};
	rotate_vertical_slice(this, column, & rotation);
}


void rbc_rotate_cube_left_slice_up(struct rbc_cube * this)
{
	rotate_slice_up(this, LEFT_COLUMN);
	rotate_face_anticlockwise(rbc_cube_left_face(this));
}


void rbc_rotate_cube_left_slice_down(struct rbc_cube * this)
{
	rotate_slice_down(this, LEFT_COLUMN);
	rotate_face_clockwise(rbc_cube_left_face(this));
}


void rbc_rotate_cube_middle_slice_up(struct rbc_cube * this)
{
	rotate_slice_up(this, MIDDLE_COLUMN);
}


void rbc_rotate_cube_middle_slice_down(struct rbc_cube * this)
{
	rotate_slice_down(this, MIDDLE_COLUMN);
}


void rbc_rotate_cube_right_slice_up(struct rbc_cube * this)
{
	rotate_slice_up(this, RIGHT_COLUMN);
	rotate_face_clockwise(rbc_cube_right_face(this));
}


void rbc_rotate_cube_right_slice_down(struct rbc_cube * this)
{
	rotate_slice_down(this, RIGHT_COLUMN);
	rotate_face_anticlockwise(rbc_cube_right_face(this));
}


/**
 * Applies a parallel slice clockwise rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_clockwise(struct rbc_cube * this, struct rbc_slice const * slice)
{
	enum rbc_face_location reversing_spans_face[2] = { RIGHT_FACE, LEFT_FACE };
	rotate_slice(this, slice, reversing_spans_face, 2);
}


void rbc_rotate_cube_front_slice_clockwise(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN }
	}};
	rotate_slice_clockwise(this, & slice);
	rotate_face_clockwise(rbc_cube_front_face(this));
}


/**
 * Applies a parallel slice anticlockwise rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_anticlockwise(struct rbc_cube * this, struct rbc_slice const * slice)
{
	enum rbc_face_location reversing_spans_face[2] = { TOP_FACE, BOTTOM_FACE };
	rotate_slice(this, slice, reversing_spans_face, 2);
}


void rbc_rotate_cube_front_slice_anticlockwise(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN }
	}};
	rotate_slice_anticlockwise(this, & slice);
	rotate_face_anticlockwise(rbc_cube_front_face(this));
}


void rbc_rotate_cube_standing_slice_clockwise(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN }
	}};
	rotate_slice_clockwise(this, & slice);
}


void rbc_rotate_cube_standing_slice_anticlockwise(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN }
	}};
	rotate_slice_anticlockwise(this, & slice);
}


void rbc_rotate_cube_back_slice_clockwise(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ TOP_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN }
	}};
	rotate_slice_clockwise(this, & slice);
	rotate_face_anticlockwise(rbc_cube_back_face(this));
}


void rbc_rotate_cube_back_slice_anticlockwise(struct rbc_cube * this)
{
	struct rbc_slice slice =
	{{
		{ TOP_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN }
	}};
	rotate_slice_anticlockwise(this, & slice);
	rotate_face_clockwise(rbc_cube_back_face(this));
}


void rbc_rotate_cube_top_slices_left(struct rbc_cube * this)
{
	rbc_rotate_cube_top_slice_left(this);
	rbc_rotate_cube_equator_slice_left(this);
}


void rbc_rotate_cube_top_slices_right(struct rbc_cube * this)
{
	rbc_rotate_cube_top_slice_right(this);
	rbc_rotate_cube_equator_slice_right(this);
}


void rbc_rotate_cube_outer_slices_left(struct rbc_cube * this)
{
	rbc_rotate_cube_top_slice_left(this);
	rbc_rotate_cube_bottom_slice_left(this);
}


void rbc_rotate_cube_outer_slices_right(struct rbc_cube * this)
{
	rbc_rotate_cube_top_slice_right(this);
	rbc_rotate_cube_bottom_slice_right(this);
}


void rbc_rotate_cube_bottom_slices_left(struct rbc_cube * this)
{
	rbc_rotate_cube_equator_slice_left(this);
	rbc_rotate_cube_bottom_slice_left(this);
}


void rbc_rotate_cube_bottom_slices_right(struct rbc_cube * this)
{
	rbc_rotate_cube_equator_slice_right(this);
	rbc_rotate_cube_bottom_slice_right(this);
}


void rbc_rotate_cube_left_slices_up(struct rbc_cube * this)
{
	rbc_rotate_cube_left_slice_up(this);
	rbc_rotate_cube_middle_slice_up(this);
}


void rbc_rotate_cube_left_slices_down(struct rbc_cube * this)
{
	rbc_rotate_cube_left_slice_down(this);
	rbc_rotate_cube_middle_slice_down(this);
}


void rbc_rotate_cube_outer_slices_up(struct rbc_cube * this)
{
	rbc_rotate_cube_left_slice_up(this);
	rbc_rotate_cube_right_slice_up(this);
}


void rbc_rotate_cube_outer_slices_down(struct rbc_cube * this)
{
	rbc_rotate_cube_left_slice_down(this);
	rbc_rotate_cube_right_slice_down(this);
}


void rbc_rotate_cube_right_slices_up(struct rbc_cube * this)
{
	rbc_rotate_cube_middle_slice_up(this);
	rbc_rotate_cube_right_slice_up(this);
}


void rbc_rotate_cube_right_slices_down(struct rbc_cube * this)
{
	rbc_rotate_cube_middle_slice_down(this);
	rbc_rotate_cube_right_slice_down(this);
}


void rbc_rotate_cube_front_slices_clockwise(struct rbc_cube * this)
{
	rbc_rotate_cube_front_slice_clockwise(this);
	rbc_rotate_cube_standing_slice_clockwise(this);
}


void rbc_rotate_cube_front_slices_anticlockwise(struct rbc_cube * this)
{
	rbc_rotate_cube_front_slice_anticlockwise(this);
	rbc_rotate_cube_standing_slice_anticlockwise(this);
}


void rbc_rotate_cube_outer_slices_clockwise(struct rbc_cube * this)
{
	rbc_rotate_cube_front_slice_clockwise(this);
	rbc_rotate_cube_back_slice_clockwise(this);
}


void rbc_rotate_cube_outer_slices_anticlockwise(struct rbc_cube * this)
{
	rbc_rotate_cube_front_slice_anticlockwise(this);
	rbc_rotate_cube_back_slice_anticlockwise(this);
}


void rbc_rotate_cube_back_slices_clockwise(struct rbc_cube * this)
{
	rbc_rotate_cube_standing_slice_clockwise(this);
	rbc_rotate_cube_back_slice_clockwise(this);
}


void rbc_rotate_cube_back_slices_anticlockwise(struct rbc_cube * this)
{
	rbc_rotate_cube_standing_slice_anticlockwise(this);
	rbc_rotate_cube_back_slice_anticlockwise(this);
}
