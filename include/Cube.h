
#ifndef LIB_RUBIKS_CORE_CUBE_HEADER
#define LIB_RUBIKS_CORE_CUBE_HEADER

#ifdef __cplusplus
extern "C" {
#endif

#include "Face.h"




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
struct rbc_cube * rbc_create_cube(void);


/**
 * Deletes the cube and sets its memory to NULL
 *
 * @param self - the cube to delete
 */
void rbc_delete_cube(struct rbc_cube ** self);


/**
 * Returns the left face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the left face from
 *
 * @return struct rbc_face * - the left face
 */
struct rbc_face * rbc_cube_left_face(struct rbc_cube const * self);


/**
 * Returns the front face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the front face from
 *
 * @return struct rbc_face * - the front face
 */
struct rbc_face * rbc_cube_front_face(struct rbc_cube const * self);


/**
 * Returns the right face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the right face from
 *
 * @return struct rbc_face * - the right face
 */
struct rbc_face * rbc_cube_right_face(struct rbc_cube const * self);


/**
 * Returns the top face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the top face from
 *
 * @return struct rbc_face * - the top face
 */
struct rbc_face * rbc_cube_top_face(struct rbc_cube const * self);


/**
 * Returns the bottom face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the bottom face from
 *
 * @return struct rbc_face * - the bottom face
 */
struct rbc_face * rbc_cube_bottom_face(struct rbc_cube const * self);


/**
 * Returns the back face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the back face from
 *
 * @return struct rbc_face * - the back face
 */
struct rbc_face * rbc_cube_back_face(struct rbc_cube const * self);


/**
 * Rotates the whole cube to the left (like U but all slices)
 *
 * Official notation: y
 *
 * @param self - the cube to rotate
 */
void rbc_rotate_cube_left(struct rbc_cube * self);


/**
 * Rotates the whole cube to the right (like U' but all slices)
 *
 * Official notation: y'
 *
 * @param self - the cube to rotate
 */
void rbc_rotate_cube_right(struct rbc_cube * self);


/**
 * Rotates the whole cube up (like R but all slices)
 *
 * Official notation: x
 *
 * @param self - the cube to rotate
 */
void rbc_rotate_cube_up(struct rbc_cube * self);


/**
 * Rotates the whole cube down (like R' but all slices)
 *
 * Official notation: x'
 *
 * @param self - the cube to rotate
 */
void rbc_rotate_cube_down(struct rbc_cube * self);


/**
 * Rotates the whole cube clockwise (like F but all slices)
 *
 * Official notation: z
 *
 * @param self - the cube to rotate
 */
void rbc_rotate_cube_clockwise(struct rbc_cube * self);


/**
 * Rotates the whole cube anticlockwise (like F' but all slices)
 *
 * Official notation: z'
 *
 * @param self - the cube to rotate
 */
void rbc_rotate_cube_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slice to the left
 *
 * Official notation: U
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_top_slice_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slice to the right
 *
 * Official notation: U'
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_top_slice_right(struct rbc_cube * self);


/**
 * Rotates the (horizontal) equator slice to the left
 *
 * Official notation: E
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_equator_slice_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) equator slice to the right
 *
 * Official notation: E'
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_equator_slice_right(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slice to the left
 *
 * Official notation: D'
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_bottom_slice_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slice to the right
 *
 * Official notation: D
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_bottom_slice_right(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slice up
 *
 * Official notation: L'
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_left_slice_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slice down
 *
 * Official notation: L
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_left_slice_down(struct rbc_cube * self);


/**
 * Rotates the (vertical) middle slice up
 *
 * Official notation: M'
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_middle_slice_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) middle slice down
 *
 * Official notation: M
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_middle_slice_down(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slice up
 *
 * Official notation: R
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_right_slice_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slice down
 *
 * Official notation: R'
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_right_slice_down(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slice clockwise
 *
 * Official notation: F
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_front_slice_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slice anticlockwise
 *
 * Official notation: F'
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_front_slice_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) standing slice clockwise
 *
 * Official notation: S
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_standing_slice_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) standing slice anticlockwise
 *
 * Official notation: S'
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_standing_slice_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slice clockwise
 *
 * Official notation: B'
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_back_slice_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slice anticlockwise
 *
 * Official notation: B
 *
 * @param self - the cube to rotate the slice from
 */
void rbc_rotate_cube_back_slice_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slices to the left (top and equator)
 *
 * Official notation: u
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_top_slices_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) top slices to the right (top and equator)
 *
 * Official notation: u'
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_top_slices_right(struct rbc_cube * self);


/**
 * Rotates the horizontal slices to the left, except the equator one
 *
 * Official notation: e
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_outer_slices_left(struct rbc_cube * self);


/**
 * Rotates the horizontal slices to the right, except the equator one
 *
 * Official notation: e'
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_outer_slices_right(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slices to the left (equator and bottom)
 *
 * Official notation: d'
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_bottom_slices_left(struct rbc_cube * self);


/**
 * Rotates the (horizontal) bottom slices to the right (equator and bottom)
 *
 * Official notation: d
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_bottom_slices_right(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slices up (left and middle)
 *
 * Official notation: l'
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_left_slices_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) left slices down (left and middle)
 *
 * Official notation: l
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_left_slices_down(struct rbc_cube * self);


/**
 * Rotates the vertical slices up, except the middle one
 *
 * Official notation: m'
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_outer_slices_up(struct rbc_cube * self);


/**
 * Rotates the vertical slices down, except the middle one
 *
 * Official notation: m
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_outer_slices_down(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slices up (middle and right)
 *
 * Official notation: r
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_right_slices_up(struct rbc_cube * self);


/**
 * Rotates the (vertical) right slices down (middle and right)
 *
 * Official notation: r'
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_right_slices_down(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slices clockwise (front and standing)
 *
 * Official notation: f
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_front_slices_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) front slices anticlockwise (front and standing)
 *
 * Official notation: f'
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_front_slices_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the parallel slices clockwise, except the standing one
 *
 * Official notation: s
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_outer_slices_clockwise(struct rbc_cube * self);


/**
 * Rotates the parallel slices anticlockwise, except the standing one
 *
 * Official notation: s'
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_outer_slices_anticlockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slices clockwise (standing and back)
 *
 * Official notation: b'
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_back_slices_clockwise(struct rbc_cube * self);


/**
 * Rotates the (parallel) back slices anticlockwise (standing and back)
 *
 * Official notation: b
 *
 * @param self - the cube to rotate the slices from
 */
void rbc_rotate_cube_back_slices_anticlockwise(struct rbc_cube * self);




#ifdef __cplusplus
}
#endif

#endif /* LIB_RUBIKS_CORE_CUBE_HEADER */
