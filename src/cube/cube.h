
#ifndef LIB_RUBIKS_CORE_INTERNAL_CUBE_HEADER
#define LIB_RUBIKS_CORE_INTERNAL_CUBE_HEADER

#ifdef __cplusplus
extern "C" {
#endif

#include "../shared/attributes/attributes.h"
#include "../face/face.h"




/**
 * A 3D rubik's cube
 *
 * Official terminology uses letters like B, which means to move Back face
 * clockwise as if it was the front one, resulting visually in a back slice
 * anticlockwise rotation, here we are only using visual notation (relative to
 * front face) to keep it understandable
 */
struct rbc_cube;




/**
 * Creates a cube and returns it, in its solved state
 *
 * Official disposition states that:
 * - blue face opposes green,
 * - white face opposes yellow,
 * - red face opposes orange,
 * - blue, white & red are in anti-clockwise order around a corner
 *
 * The caller is in charge of the memory
 *
 * @return struct rbc_cube * - the allocated cube
 */
RBC_API struct rbc_cube * rbc_create_cube(void);


/**
 * Deletes the cube and sets its memory to NULL
 *
 * @param self - the cube to delete
 */
RBC_API void rbc_delete_cube(struct rbc_cube ** self);


/**
 * Rotates the cube to have given front face color and top face color
 * If invalid colors are supplied or if colors are opposite, nothing is done
 *
 * @param cube - the cube to orientate
 *
 * @param front_face_color - the color of the face to put on front
 *
 * @param top_face_color - the color of the face to put on top
 */
RBC_API void rbc_orientate_cube(struct rbc_cube * cube, enum rbc_color front_face_color, enum rbc_color top_face_color);


/**
 * Returns the left face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the left face from
 *
 * @return struct rbc_face * - the left face
 */
RBC_API struct rbc_face * rbc_cube_left_face(struct rbc_cube const * self);


/**
 * Returns the front face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the front face from
 *
 * @return struct rbc_face * - the front face
 */
RBC_API struct rbc_face * rbc_cube_front_face(struct rbc_cube const * self);


/**
 * Returns the right face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the right face from
 *
 * @return struct rbc_face * - the right face
 */
RBC_API struct rbc_face * rbc_cube_right_face(struct rbc_cube const * self);


/**
 * Returns the top face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the top face from
 *
 * @return struct rbc_face * - the top face
 */
RBC_API struct rbc_face * rbc_cube_top_face(struct rbc_cube const * self);


/**
 * Returns the bottom face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the bottom face from
 *
 * @return struct rbc_face * - the bottom face
 */
RBC_API struct rbc_face * rbc_cube_bottom_face(struct rbc_cube const * self);


/**
 * Returns the back face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the back face from
 *
 * @return struct rbc_face * - the back face
 */
RBC_API struct rbc_face * rbc_cube_back_face(struct rbc_cube const * self);


/**
 * Rotates the whole cube to the left (like U but all slices)
 *
 * Singmaster notation: y
 *
 * @param self - the cube to rotate
 */
RBC_API void rbc_rotate_cube_left(struct rbc_cube * self);


/**
 * Rotates the whole cube to the right (like U' but all slices)
 *
 * Singmaster notation: y'
 *
 * @param self - the cube to rotate
 */
RBC_API void rbc_rotate_cube_right(struct rbc_cube * self);


/**
 * Rotates the whole cube up (like R but all slices)
 *
 * Singmaster notation: x
 *
 * @param self - the cube to rotate
 */
RBC_API void rbc_rotate_cube_up(struct rbc_cube * self);


/**
 * Rotates the whole cube down (like R' but all slices)
 *
 * Singmaster notation: x'
 *
 * @param self - the cube to rotate
 */
RBC_API void rbc_rotate_cube_down(struct rbc_cube * self);


/**
 * Rotates the whole cube clockwise (like F but all slices)
 *
 * Singmaster notation: z
 *
 * @param self - the cube to rotate
 */
RBC_API void rbc_rotate_cube_clockwise(struct rbc_cube * self);


/**
 * Rotates the whole cube anticlockwise (like F' but all slices)
 *
 * Singmaster notation: z'
 *
 * @param self - the cube to rotate
 */
RBC_API void rbc_rotate_cube_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slice to the left
 *
 * Singmaster notation: U
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_top_slice_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slice to the right
 *
 * Singmaster notation: U'
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_top_slice_right(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slice twice
 *
 * Singmaster notation: U2
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_top_slice_twice(struct rbc_cube * self);


/**
 * Rotates the (horizontal) equator slice to the left
 *
 * Singmaster notation: E
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_equator_slice_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) equator slice to the right
 *
 * Singmaster notation: E'
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_equator_slice_right(struct rbc_cube * self);


/**
 * Rotates the (horizontal) equator slice twice
 *
 * Singmaster notation: E2
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_equator_slice_twice(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slice to the left
 *
 * Singmaster notation: D'
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_bottom_slice_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slice to the right
 *
 * Singmaster notation: D
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_bottom_slice_right(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slice twice
 *
 * Singmaster notation: D2
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_bottom_slice_twice(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slice up
 *
 * Singmaster notation: L'
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_left_slice_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slice down
 *
 * Singmaster notation: L
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_left_slice_down(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slice twice
 *
 * Singmaster notation: L2
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_left_slice_twice(struct rbc_cube * self);


/**
 * Rotates the (vertical) middle slice up
 *
 * Singmaster notation: M'
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_middle_slice_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) middle slice down
 *
 * Singmaster notation: M
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_middle_slice_down(struct rbc_cube * self);


/**
 * Rotates the (vertical) middle slice twice
 *
 * Singmaster notation: M2
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_middle_slice_twice(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slice up
 *
 * Singmaster notation: R
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_right_slice_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slice down
 *
 * Singmaster notation: R'
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_right_slice_down(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slice twice
 *
 * Singmaster notation: R2
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_right_slice_twice(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slice clockwise
 *
 * Singmaster notation: F
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_front_slice_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slice anticlockwise
 *
 * Singmaster notation: F'
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_front_slice_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slice twice
 *
 * Singmaster notation: F2
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_front_slice_twice(struct rbc_cube * self);


/**
 * Rotates the (parallel) standing slice clockwise
 *
 * Singmaster notation: S
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_standing_slice_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) standing slice anticlockwise
 *
 * Singmaster notation: S'
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_standing_slice_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) standing slice twice
 *
 * Singmaster notation: S2
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_standing_slice_twice(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slice clockwise
 *
 * Singmaster notation: B'
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_back_slice_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slice anticlockwise
 *
 * Singmaster notation: B
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_back_slice_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slice twice
 *
 * Singmaster notation: B2
 *
 * @param self - the cube to rotate the slice from
 */
RBC_API void rbc_rotate_cube_back_slice_twice(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slices to the left (top and equator)
 *
 * Singmaster notation: u
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_top_slices_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slices to the right (top and equator)
 *
 * Singmaster notation: u'
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_top_slices_right(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slices twice (top and equator)
 *
 * Singmaster notation: u2
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_top_slices_twice(struct rbc_cube * self);


/**
 * Rotates the horizontal slices to the left, except the equator one
 *
 * Singmaster notation: e
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_outer_slices_left(struct rbc_cube * self);


/**
 * Rotates the horizontal slices to the right, except the equator one
 *
 * Singmaster notation: e'
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_outer_slices_right(struct rbc_cube * self);


/**
 * Rotates the horizontal slices twice, except the equator one
 *
 * Singmaster notation: e2
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_horizontal_outer_slices_twice(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slices to the left (equator and bottom)
 *
 * Singmaster notation: d'
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_bottom_slices_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slices to the right (equator and bottom)
 *
 * Singmaster notation: d
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_bottom_slices_right(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slices twice (equator and bottom)
 *
 * Singmaster notation: d2
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_bottom_slices_twice(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slices up (left and middle)
 *
 * Singmaster notation: l'
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_left_slices_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slices down (left and middle)
 *
 * Singmaster notation: l
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_left_slices_down(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slices twice (left and middle)
 *
 * Singmaster notation: l2
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_left_slices_twice(struct rbc_cube * self);


/**
 * Rotates the vertical slices up, except the middle one
 *
 * Singmaster notation: m'
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_outer_slices_up(struct rbc_cube * self);


/**
 * Rotates the vertical slices down, except the middle one
 *
 * Singmaster notation: m
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_outer_slices_down(struct rbc_cube * self);


/**
 * Rotates the vertical slices twice, except the middle one
 *
 * Singmaster notation: m2
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_vertical_outer_slices_twice(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slices up (middle and right)
 *
 * Singmaster notation: r
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_right_slices_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slices down (middle and right)
 *
 * Singmaster notation: r'
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_right_slices_down(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slices twice (middle and right)
 *
 * Singmaster notation: r2
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_right_slices_twice(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slices clockwise (front and standing)
 *
 * Singmaster notation: f
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_front_slices_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slices anticlockwise (front and standing)
 *
 * Singmaster notation: f'
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_front_slices_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slices twice (front and standing)
 *
 * Singmaster notation: f2
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_front_slices_twice(struct rbc_cube * self);


/**
 * Rotates the parallel slices clockwise, except the standing one
 *
 * Singmaster notation: s
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_outer_slices_clockwise(struct rbc_cube * self);


/**
 * Rotates the parallel slices anticlockwise, except the standing one
 *
 * Singmaster notation: s'
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_outer_slices_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the parallel slices twice, except the standing one
 *
 * Singmaster notation: s2
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_parallel_outer_slices_twice(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slices clockwise (standing and back)
 *
 * Singmaster notation: b'
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_back_slices_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slices anticlockwise (standing and back)
 *
 * Singmaster notation: b
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_back_slices_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slices twice (standing and back)
 *
 * Singmaster notation: b2
 *
 * @param self - the cube to rotate the slices from
 */
RBC_API void rbc_rotate_cube_back_slices_twice(struct rbc_cube * self);




/**
 * The position of each Face in the T-shaped 2D pattern of the unfolded 3D cube
 */
enum rbc_face_location
{
	RBC_LEFT_FACE,
	RBC_FRONT_FACE,
	RBC_RIGHT_FACE,
	RBC_BOTTOM_FACE,
	RBC_BACK_FACE,
	RBC_TOP_FACE
};


/**
 * A cycle of 4 faces
 */
struct rbc_faces_cycle
{
	enum rbc_face_location const faces_location[4];
};


/**
 * Whether the span is a row or a column
 */
enum rbc_span_type
{
	RBC_ROW,
	RBC_COLUMN
};


/**
 * Coords of a 2D span, a row or a column on a face
 */
struct rbc_span
{
	enum rbc_face_location face_location;

	enum rbc_span_location location;

	enum rbc_span_type type;
};


/**
 * A 3D Slice is made of 4 2D Spans
 */
struct rbc_slice
{
	struct rbc_span spans[4];
};




/**
 * Applies a rotation on the cube, faces are simply moved on the 2D pattern
 *
 * @param self - the cube to rotate
 *
 * @param rotation - the rotation to apply
 */
void rbc_rotate_cube(struct rbc_cube * self, struct rbc_faces_cycle const * rotation);


/**
 * Applies a slice rotation on the cube
 *
 * @param self - the cube containing the slice to rotate
 *
 * @param slice - the slice to rotate
 *
 * @param reversing_spans_face - array of rbc_face_location, any span in the slice
 * 	having its face in that array will be reversed
 *
 * @param reversing_count - the number of faces in [reversing_spans_face]
 * 	(ie., the number of spans to reverse in the slice)
 */
void rbc_rotate_slice(
	struct rbc_cube * self,
	struct rbc_slice const * slice,
	enum rbc_face_location const reversing_spans_face[],
	int reversing_count);




#ifdef __cplusplus
}
#endif

#endif /* LIB_RUBIKS_CORE_INTERNAL_CUBE_HEADER */
