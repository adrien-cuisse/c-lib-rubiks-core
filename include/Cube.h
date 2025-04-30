
#ifndef CUBE_HEADER
#define CUBE_HEADER

#include "Face.h"




typedef struct Cube Cube;




Cube * Cube_create(void);
void Cube_delete(Cube ** this);

Face * Cube_leftFace(Cube const * this);
Face * Cube_frontFace(Cube const * this);
Face * Cube_rightFace(Cube const * this);
Face * Cube_topFace(Cube const * this);
Face * Cube_bottomFace(Cube const * this);
Face * Cube_backFace(Cube const * this);

void Cube_rotateLeft(Cube * this);
void Cube_rotateRight(Cube * this);
void Cube_rotateUp(Cube * this);
void Cube_rotateDown(Cube * this);
void Cube_rotateClockwise(Cube * this);
void Cube_rotateAnticlockwise(Cube * this);

void Cube_rotateTopSliceLeft(Cube * this);
void Cube_rotateTopSliceRight(Cube * this);
void Cube_rotateEquatorSliceLeft(Cube * this);
void Cube_rotateEquatorSliceRight(Cube * this);
void Cube_rotateBottomSliceLeft(Cube * this);
void Cube_rotateBottomSliceRight(Cube * this);

void Cube_rotateLeftSliceUp(Cube * this);
void Cube_rotateLeftSliceDown(Cube * this);
void Cube_rotateMiddleSliceUp(Cube * this);
void Cube_rotateMiddleSliceDown(Cube * this);
void Cube_rotateRightSliceUp(Cube * this);
void Cube_rotateRightSliceDown(Cube * this);

void Cube_rotateFrontSliceClockwise(Cube * this);
void Cube_rotateFrontSliceAnticlockwise(Cube * this);
void Cube_rotateStandingSliceClockwise(Cube * this);
void Cube_rotateStandingSliceAnticlockwise(Cube * this);
void Cube_rotateBackSliceClockwise(Cube * this);
void Cube_rotateBackSliceAnticlockwise(Cube * this);




#endif /* CUBE_HEADER */
