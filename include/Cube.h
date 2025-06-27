
#ifndef CUBE_HEADER
#define CUBE_HEADER

#ifdef __cplusplus
extern "C" {
#endif

#ifndef RUBIKS_API
#define RUBIKS_API
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
typedef struct Cube Cube;




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
 * @return Cube * - the allocated cube
 */
RUBIKS_API Cube * Cube_create(void);


/**
 * Deletes the cube and sets its memory to NULL
 *
 * @param self - the cube to delete
 */
RUBIKS_API void Cube_delete(Cube ** self);


/**
 * Returns the left face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the left face from
 *
 * @return Face * - the left face
 */
RUBIKS_API Face * Cube_leftFace(Cube const * self);


/**
 * Returns the front face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the front face from
 *
 * @return Face * - the front face
 */
RUBIKS_API Face * Cube_frontFace(Cube const * self);


/**
 * Returns the right face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the right face from
 *
 * @return Face * - the right face
 */
RUBIKS_API Face * Cube_rightFace(Cube const * self);


/**
 * Returns the top face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the top face from
 *
 * @return Face * - the top face
 */
RUBIKS_API Face * Cube_topFace(Cube const * self);


/**
 * Returns the bottom face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the bottom face from
 *
 * @return Face * - the bottom face
 */
RUBIKS_API Face * Cube_bottomFace(Cube const * self);


/**
 * Returns the back face of the cube
 *
 * The caller is NOT in charge of the memory
 *
 * @param self - the cube to get the back face from
 *
 * @return Face * - the back face
 */
RUBIKS_API Face * Cube_backFace(Cube const * self);


/**
 * Rotates the whole cube to the left (like U but all slices)
 *
 * Offical notation: y
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void Cube_rotateLeft(Cube * self);


/**
 * Rotates the whole cube to the right (like U' but all slices)
 *
 * Offical notation: y'
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void Cube_rotateRight(Cube * self);


/**
 * Rotates the whole cube up (like R but all slices)
 *
 * Offical notation: x
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void Cube_rotateUp(Cube * self);


/**
 * Rotates the whole cube down (like R' but all slices)
 *
 * Offical notation: x'
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void Cube_rotateDown(Cube * self);


/**
 * Rotates the whole cube clockwise (like F but all slices)
 *
 * Offical notation: z
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void Cube_rotateClockwise(Cube * self);


/**
 * Rotates the whole cube anticlockwise (like F' but all slices)
 *
 * Offical notation: z'
 *
 * @param self - the cube to rotate
 */
RUBIKS_API void Cube_rotateAnticlockwise(Cube * self);


/**
 * Rotates the (horizontal) top slice to the left
 *
 * Official notation: U
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateTopSliceLeft(Cube * self);


/**
 * Rotates the (horizontal) top slice to the right
 *
 * Official notation: U'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateTopSliceRight(Cube * self);


/**
 * Rotates the (horizontal) equator slice to the left
 *
 * Official notation: E
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateEquatorSliceLeft(Cube * self);


/**
 * Rotates the (horizontal) equator slice to the right
 *
 * Official notation: E'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateEquatorSliceRight(Cube * self);


/**
 * Rotates the (horizontal) bottom slice to the left
 *
 * Official notation: D'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateBottomSliceLeft(Cube * self);


/**
 * Rotates the (horizontal) bottom slice to the right
 *
 * Official notation: D
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateBottomSliceRight(Cube * self);


/**
 * Rotates the (vertical) left slice up
 *
 * Official notation: L'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateLeftSliceUp(Cube * self);


/**
 * Rotates the (vertical) left slice down
 *
 * Official notation: L
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateLeftSliceDown(Cube * self);


/**
 * Rotates the (vertical) middle slice up
 *
 * Official notation: M'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateMiddleSliceUp(Cube * self);


/**
 * Rotates the (vertical) middle slice down
 *
 * Official notation: M
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateMiddleSliceDown(Cube * self);


/**
 * Rotates the (vertical) right slice up
 *
 * Official notation: R
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateRightSliceUp(Cube * self);


/**
 * Rotates the (vertical) right slice down
 *
 * Official notation: R'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateRightSliceDown(Cube * self);


/**
 * Rotates the (parallel) front slice clockwise
 *
 * Official notation: F
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateFrontSliceClockwise(Cube * self);


/**
 * Rotates the (parallel) front slice anticlockwise
 *
 * Official notation: F'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateFrontSliceAnticlockwise(Cube * self);


/**
 * Rotates the (parallel) standing slice clockwise
 *
 * Official notation: S
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateStandingSliceClockwise(Cube * self);


/**
 * Rotates the (parallel) standing slice anticlockwise
 *
 * Official notation: S'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateStandingSliceAnticlockwise(Cube * self);


/**
 * Rotates the (parallel) back slice clockwise
 *
 * Official notation: B'
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateBackSliceClockwise(Cube * self);


/**
 * Rotates the (parallel) back slice anticlockwise
 *
 * Official notation: B
 *
 * @param self - the cube to rotate the slice from
 */
RUBIKS_API void Cube_rotateBackSliceAnticlockwise(Cube * self);




#ifdef __cplusplus
}
#endif

#endif /* CUBE_HEADER */
