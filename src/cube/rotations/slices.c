
#include "../../face/face.h"
#include "../cube.h"

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
 * @param self - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_left(struct rbc_cube * self, struct rbc_slice const * slice)
{
	enum rbc_face_location reversing_spans_face[2] = { RBC_LEFT_FACE, RBC_BACK_FACE };
	rotate_slice(self, slice, reversing_spans_face, 2);
}


/**
 * Rotates an horizontal slice to the right
 *
 * @param self - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_right(struct rbc_cube * self, struct rbc_slice const * slice)
{
	enum rbc_face_location reversing_spans_face[2] = { RBC_RIGHT_FACE, RBC_BACK_FACE };
	rotate_slice(self, slice, reversing_spans_face, 2);
}


void rbc_rotate_cube_top_slice_left(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_FRONT_FACE, RBC_TOP_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_TOP_ROW, RBC_ROW },
		{ RBC_BACK_FACE, RBC_BOTTOM_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_TOP_ROW, RBC_ROW }
	}};
	rotate_slice_left(self, & slice);
	rotate_face_clockwise(rbc_cube_top_face(self));
}


void rbc_rotate_cube_top_slice_right(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_FRONT_FACE, RBC_TOP_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_TOP_ROW, RBC_ROW },
		{ RBC_BACK_FACE, RBC_BOTTOM_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_TOP_ROW, RBC_ROW }
	}};
	rotate_slice_right(self, & slice);
	rotate_face_anticlockwise(rbc_cube_top_face(self));
}


void rbc_rotate_cube_equator_slice_left(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_FRONT_FACE, RBC_EQUATOR_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_EQUATOR_ROW, RBC_ROW },
		{ RBC_BACK_FACE, RBC_EQUATOR_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_EQUATOR_ROW, RBC_ROW }
	}};
	rotate_slice_left(self, & slice);
}


void rbc_rotate_cube_equator_slice_right(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_FRONT_FACE, RBC_EQUATOR_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_EQUATOR_ROW, RBC_ROW },
		{ RBC_BACK_FACE, RBC_EQUATOR_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_EQUATOR_ROW, RBC_ROW }
	}};
	rotate_slice_right(self, & slice);
}


void rbc_rotate_cube_bottom_slice_left(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_FRONT_FACE, RBC_BOTTOM_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_BOTTOM_ROW, RBC_ROW },
		{ RBC_BACK_FACE, RBC_TOP_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_BOTTOM_ROW, RBC_ROW }
	}};
	rotate_slice_left(self, & slice);
	rotate_face_anticlockwise(rbc_cube_bottom_face(self));
}


void rbc_rotate_cube_bottom_slice_right(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_FRONT_FACE, RBC_BOTTOM_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_BOTTOM_ROW, RBC_ROW },
		{ RBC_BACK_FACE, RBC_TOP_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_BOTTOM_ROW, RBC_ROW }
	}};
	rotate_slice_right(self, & slice);
	rotate_face_clockwise(rbc_cube_bottom_face(self));
}


/**
 * Applies a vertical slice rotation on the cube
 *
 * @param self - the cube containing the slice
 *
 * @param column - the column of the slice to rotate
 *
 * @param rotation - the rotation to apply
 */
static void rotate_vertical_slice(struct rbc_cube * self, enum rbc_span_location column, struct rbc_faces_cycle const * rotation)
{
	int span_index;
	struct rbc_slice slice;

	for (span_index = 0; span_index < 4; span_index++)
	{
		slice.spans[span_index].face_location = rotation->faces_location[span_index];
		slice.spans[span_index].location = column;
		slice.spans[span_index].type = RBC_COLUMN;
	}

	rotate_slice(self, & slice, NULL, 0);
}


/**
 * Applies a vertical slice up rotation on the cube
 *
 * @param self - the cube containing the slice
 *
 * @param column - the column of the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_up(struct rbc_cube * self, enum rbc_span_location column)
{
	struct rbc_faces_cycle rotation = {{ RBC_FRONT_FACE, RBC_TOP_FACE, RBC_BACK_FACE, RBC_BOTTOM_FACE }};
	rotate_vertical_slice(self, column, & rotation);
}


/**
 * Applies a vertical slice down rotation on the cube
 *
 * @param self - the cube containing the slice
 *
 * @param column - the column of the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_down(struct rbc_cube * self, enum rbc_span_location column)
{
	struct rbc_faces_cycle rotation = {{ RBC_FRONT_FACE, RBC_BOTTOM_FACE, RBC_BACK_FACE, RBC_TOP_FACE }};
	rotate_vertical_slice(self, column, & rotation);
}


void rbc_rotate_cube_left_slice_up(struct rbc_cube * self)
{
	rotate_slice_up(self, RBC_LEFT_COLUMN);
	rotate_face_anticlockwise(rbc_cube_left_face(self));
}


void rbc_rotate_cube_left_slice_down(struct rbc_cube * self)
{
	rotate_slice_down(self, RBC_LEFT_COLUMN);
	rotate_face_clockwise(rbc_cube_left_face(self));
}


void rbc_rotate_cube_middle_slice_up(struct rbc_cube * self)
{
	rotate_slice_up(self, RBC_MIDDLE_COLUMN);
}


void rbc_rotate_cube_middle_slice_down(struct rbc_cube * self)
{
	rotate_slice_down(self, RBC_MIDDLE_COLUMN);
}


void rbc_rotate_cube_right_slice_up(struct rbc_cube * self)
{
	rotate_slice_up(self, RBC_RIGHT_COLUMN);
	rotate_face_clockwise(rbc_cube_right_face(self));
}


void rbc_rotate_cube_right_slice_down(struct rbc_cube * self)
{
	rotate_slice_down(self, RBC_RIGHT_COLUMN);
	rotate_face_anticlockwise(rbc_cube_right_face(self));
}


/**
 * Applies a parallel slice clockwise rotation on the cube
 *
 * @param self - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_clockwise(struct rbc_cube * self, struct rbc_slice const * slice)
{
	enum rbc_face_location reversing_spans_face[2] = { RBC_RIGHT_FACE, RBC_LEFT_FACE };
	rotate_slice(self, slice, reversing_spans_face, 2);
}


void rbc_rotate_cube_front_slice_clockwise(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_TOP_FACE, RBC_BOTTOM_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_LEFT_COLUMN, RBC_COLUMN },
		{ RBC_BOTTOM_FACE, RBC_TOP_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_RIGHT_COLUMN, RBC_COLUMN }
	}};
	rotate_slice_clockwise(self, & slice);
	rotate_face_clockwise(rbc_cube_front_face(self));
}


/**
 * Applies a parallel slice anticlockwise rotation on the cube
 *
 * @param self - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotate_slice_anticlockwise(struct rbc_cube * self, struct rbc_slice const * slice)
{
	enum rbc_face_location reversing_spans_face[2] = { RBC_TOP_FACE, RBC_BOTTOM_FACE };
	rotate_slice(self, slice, reversing_spans_face, 2);
}


void rbc_rotate_cube_front_slice_anticlockwise(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_TOP_FACE, RBC_BOTTOM_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_RIGHT_COLUMN, RBC_COLUMN },
		{ RBC_BOTTOM_FACE, RBC_TOP_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_LEFT_COLUMN, RBC_COLUMN }
	}};
	rotate_slice_anticlockwise(self, & slice);
	rotate_face_anticlockwise(rbc_cube_front_face(self));
}


void rbc_rotate_cube_standing_slice_clockwise(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_TOP_FACE, RBC_EQUATOR_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_MIDDLE_COLUMN, RBC_COLUMN },
		{ RBC_BOTTOM_FACE, RBC_EQUATOR_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_MIDDLE_COLUMN, RBC_COLUMN }
	}};
	rotate_slice_clockwise(self, & slice);
}


void rbc_rotate_cube_standing_slice_anticlockwise(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_TOP_FACE, RBC_EQUATOR_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_MIDDLE_COLUMN, RBC_COLUMN },
		{ RBC_BOTTOM_FACE, RBC_EQUATOR_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_MIDDLE_COLUMN, RBC_COLUMN }
	}};
	rotate_slice_anticlockwise(self, & slice);
}


void rbc_rotate_cube_back_slice_clockwise(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_TOP_FACE, RBC_TOP_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_RIGHT_COLUMN, RBC_COLUMN },
		{ RBC_BOTTOM_FACE, RBC_BOTTOM_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_LEFT_COLUMN, RBC_COLUMN }
	}};
	rotate_slice_clockwise(self, & slice);
	rotate_face_anticlockwise(rbc_cube_back_face(self));
}


void rbc_rotate_cube_back_slice_anticlockwise(struct rbc_cube * self)
{
	struct rbc_slice slice =
	{{
		{ RBC_TOP_FACE, RBC_TOP_ROW, RBC_ROW },
		{ RBC_LEFT_FACE, RBC_LEFT_COLUMN, RBC_COLUMN },
		{ RBC_BOTTOM_FACE, RBC_BOTTOM_ROW, RBC_ROW },
		{ RBC_RIGHT_FACE, RBC_RIGHT_COLUMN, RBC_COLUMN }
	}};
	rotate_slice_anticlockwise(self, & slice);
	rotate_face_clockwise(rbc_cube_back_face(self));
}


void rbc_rotate_cube_top_slices_left(struct rbc_cube * self)
{
	rbc_rotate_cube_top_slice_left(self);
	rbc_rotate_cube_equator_slice_left(self);
}


void rbc_rotate_cube_top_slices_right(struct rbc_cube * self)
{
	rbc_rotate_cube_top_slice_right(self);
	rbc_rotate_cube_equator_slice_right(self);
}


void rbc_rotate_cube_outer_slices_left(struct rbc_cube * self)
{
	rbc_rotate_cube_top_slice_left(self);
	rbc_rotate_cube_bottom_slice_left(self);
}


void rbc_rotate_cube_outer_slices_right(struct rbc_cube * self)
{
	rbc_rotate_cube_top_slice_right(self);
	rbc_rotate_cube_bottom_slice_right(self);
}


void rbc_rotate_cube_bottom_slices_left(struct rbc_cube * self)
{
	rbc_rotate_cube_equator_slice_left(self);
	rbc_rotate_cube_bottom_slice_left(self);
}


void rbc_rotate_cube_bottom_slices_right(struct rbc_cube * self)
{
	rbc_rotate_cube_equator_slice_right(self);
	rbc_rotate_cube_bottom_slice_right(self);
}


void rbc_rotate_cube_left_slices_up(struct rbc_cube * self)
{
	rbc_rotate_cube_left_slice_up(self);
	rbc_rotate_cube_middle_slice_up(self);
}


void rbc_rotate_cube_left_slices_down(struct rbc_cube * self)
{
	rbc_rotate_cube_left_slice_down(self);
	rbc_rotate_cube_middle_slice_down(self);
}


void rbc_rotate_cube_outer_slices_up(struct rbc_cube * self)
{
	rbc_rotate_cube_left_slice_up(self);
	rbc_rotate_cube_right_slice_up(self);
}


void rbc_rotate_cube_outer_slices_down(struct rbc_cube * self)
{
	rbc_rotate_cube_left_slice_down(self);
	rbc_rotate_cube_right_slice_down(self);
}


void rbc_rotate_cube_right_slices_up(struct rbc_cube * self)
{
	rbc_rotate_cube_middle_slice_up(self);
	rbc_rotate_cube_right_slice_up(self);
}


void rbc_rotate_cube_right_slices_down(struct rbc_cube * self)
{
	rbc_rotate_cube_middle_slice_down(self);
	rbc_rotate_cube_right_slice_down(self);
}


void rbc_rotate_cube_front_slices_clockwise(struct rbc_cube * self)
{
	rbc_rotate_cube_front_slice_clockwise(self);
	rbc_rotate_cube_standing_slice_clockwise(self);
}


void rbc_rotate_cube_front_slices_anticlockwise(struct rbc_cube * self)
{
	rbc_rotate_cube_front_slice_anticlockwise(self);
	rbc_rotate_cube_standing_slice_anticlockwise(self);
}


void rbc_rotate_cube_outer_slices_clockwise(struct rbc_cube * self)
{
	rbc_rotate_cube_front_slice_clockwise(self);
	rbc_rotate_cube_back_slice_clockwise(self);
}


void rbc_rotate_cube_outer_slices_anticlockwise(struct rbc_cube * self)
{
	rbc_rotate_cube_front_slice_anticlockwise(self);
	rbc_rotate_cube_back_slice_anticlockwise(self);
}


void rbc_rotate_cube_back_slices_clockwise(struct rbc_cube * self)
{
	rbc_rotate_cube_standing_slice_clockwise(self);
	rbc_rotate_cube_back_slice_clockwise(self);
}


void rbc_rotate_cube_back_slices_anticlockwise(struct rbc_cube * self)
{
	rbc_rotate_cube_standing_slice_anticlockwise(self);
	rbc_rotate_cube_back_slice_anticlockwise(self);
}
