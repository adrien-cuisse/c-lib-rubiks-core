
#ifndef LIB_RUBIKS_CORE_INTERNAL_CUBE_HEADER
#define LIB_RUBIKS_CORE_INTERNAL_CUBE_HEADER

#ifdef __cplusplus
extern "C" {
#endif

#include "../shared/attributes/attributes.h"
#include "../face/Face.h"




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
RUBIKS_API struct rbc_cube * rubiks_cube_create(void);


/**
 * Deletes the cube and sets its memory to NULL
 *
 * @param self - the cube to delete
 */
RUBIKS_API void rubiks_cube_delete(struct rbc_cube ** self);


/**
 * Returns the left face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the left face from
 *
 * @return Face * - the left face
 */
RUBIKS_API Face * rubiks_cube_left_face(struct rbc_cube const * self);


/**
 * Returns the front face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the front face from
 *
 * @return Face * - the front face
 */
RUBIKS_API Face * rubiks_cube_front_face(struct rbc_cube const * self);


/**
 * Returns the right face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the right face from
 *
 * @return Face * - the right face
 */
RUBIKS_API Face * rubiks_cube_right_face(struct rbc_cube const * self);


/**
 * Returns the top face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the top face from
 *
 * @return Face * - the top face
 */
RUBIKS_API Face * rubiks_cube_top_face(struct rbc_cube const * self);


/**
 * Returns the bottom face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the bottom face from
 *
 * @return Face * - the bottom face
 */
RUBIKS_API Face * rubiks_cube_bottom_face(struct rbc_cube const * self);


/**
 * Returns the back face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the back face from
 *
 * @return Face * - the back face
 */
RUBIKS_API Face * rubiks_cube_back_face(struct rbc_cube const * self);


/**
 * Rotates the whole cube to the left (like U but all slices)
 *
 * Offical notation: y
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void rubiks_cube_rotate_left(struct rbc_cube * self);


/**
 * Rotates the whole cube to the right (like U' but all slices)
 *
 * Offical notation: y'
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void rubiks_cube_rotate_right(struct rbc_cube * self);


/**
 * Rotates the whole cube up (like R but all slices)
 *
 * Offical notation: x
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void rubiks_cube_rotate_up(struct rbc_cube * self);


/**
 * Rotates the whole cube down (like R' but all slices)
 *
 * Offical notation: x'
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void rubiks_cube_rotate_down(struct rbc_cube * self);


/**
 * Rotates the whole cube clockwise (like F but all slices)
 *
 * Offical notation: z
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void rubiks_cube_rotate_clockwise(struct rbc_cube * self);


/**
 * Rotates the whole cube anticlockwise (like F' but all slices)
 *
 * Offical notation: z'
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void rubiks_cube_rotate_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slice to the left
 *
 * Official notation: U
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_top_slice_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slice to the right
 *
 * Official notation: U'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_top_slice_right(struct rbc_cube * self);


/**
 * Rotates the (horizontal) equator slice to the left
 *
 * Official notation: E
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_equator_slice_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) equator slice to the right
 *
 * Official notation: E'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_equator_slice_right(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slice to the left
 *
 * Official notation: D'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_bottom_slice_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slice to the right
 *
 * Official notation: D
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_bottom_slice_right(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slice up
 *
 * Official notation: L'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_left_slice_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slice down
 *
 * Official notation: L
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_left_slice_down(struct rbc_cube * self);


/**
 * Rotates the (vertical) middle slice up
 *
 * Official notation: M'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_middle_slice_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) middle slice down
 *
 * Official notation: M
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_middle_slice_down(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slice up
 *
 * Official notation: R
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_right_slice_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slice down
 *
 * Official notation: R'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_right_slice_down(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slice clockwise
 *
 * Official notation: F
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_front_slice_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slice anticlockwise
 *
 * Official notation: F'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_front_slice_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) standing slice clockwise
 *
 * Official notation: S
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_standing_slice_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) standing slice anticlockwise
 *
 * Official notation: S'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_standing_slice_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slice clockwise
 *
 * Official notation: B'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_back_slice_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slice anticlockwise
 *
 * Official notation: B
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void rubiks_cube_rotate_back_slice_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slices to the left (top and equator)
 *
 * Official notation: u
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_top_slices_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slices to the right (top and equator)
 *
 * Official notation: u'
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_top_slices_right(struct rbc_cube * self);


/**
 * Rotates the horizontal slices to the left, except the equator one
 *
 * Official notation: e
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_outer_slices_left(struct rbc_cube * self);


/**
 * Rotates the horizontal slices to the right, except the equator one
 *
 * Official notation: e'
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_outer_slices_right(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slices to the left (equator and bottom)
 *
 * Official notation: d'
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_bottom_slices_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slices to the right (equator and bottom)
 *
 * Official notation: d
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_bottom_slices_right(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slices up (left and middle)
 *
 * Official notation: l'
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_left_slices_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slices down (left and middle)
 *
 * Official notation: l
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_left_slices_down(struct rbc_cube * self);


/**
 * Rotates the vertical slices up, except the middle one
 *
 * Official notation: m'
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_outer_slices_up(struct rbc_cube * self);


/**
 * Rotates the vertical slices down, except the middle one
 *
 * Official notation: m
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_outer_slices_down(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slices up (middle and right)
 *
 * Official notation: r
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_right_slices_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slices down (middle and right)
 *
 * Official notation: r'
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_right_slices_down(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slices clockwise (front and standing)
 *
 * Official notation: f
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_front_slices_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slices anticlockwise (front and standing)
 *
 * Official notation: f'
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_front_slices_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the parallel slices clockwise, except the standing one
 *
 * Official notation: s
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_outer_slices_clockwise(struct rbc_cube * self);


/**
 * Rotates the parallel slices anticlockwise, except the standing one
 *
 * Official notation: s'
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_outer_slices_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slices clockwise (standing and back)
 *
 * Official notation: b'
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_back_slices_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slices anticlockwise (standing and back)
 *
 * Official notation: b
 *
 * @param self - the cube to rotate the slices from
 */
RUBIKS_API void rubiks_cube_rotate_back_slices_anticlockwise(struct rbc_cube * self);




/**
 * The position of each Face in the T-shaped 2D pattern of the unfolded 3D cube
 */
typedef enum
{
	LEFT_FACE,
	FRONT_FACE,
	RIGHT_FACE,
	BOTTOM_FACE,
	BACK_FACE,
	TOP_FACE
} FacePosition;


/**
 * A cycle of 4 faces
 */
typedef FacePosition Rotation[4];


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
 * Applies a rotation on the cube, faces are simply moved on the 2D pattern
 *
 * @param this - the cube to rotate
 *
 * @param rotation - the rotation to apply
 */
void rotate_cube(struct rbc_cube * this, Rotation rotation);


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
	struct rbc_cube * this,
	Slice slice,
	FacePosition const reversing_spans_face[],
	int reversing_count);




#ifdef __cplusplus
}
#endif

#endif /* LIB_RUBIKS_CORE_INTERNAL_CUBE_HEADER */
