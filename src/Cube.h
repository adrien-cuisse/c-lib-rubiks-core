
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

void Cube_turnTopSliceLeft(Cube * this);
void Cube_turnTopSliceRight(Cube * this);
void Cube_turnEquatorSliceLeft(Cube * this);
void Cube_turnEquatorSliceRight(Cube * this);
void Cube_turnBottomSliceLeft(Cube * this);
void Cube_turnBottomSliceRight(Cube * this);

void Cube_turnLeftSliceUp(Cube * this);
void Cube_turnLeftSliceDown(Cube * this);
void Cube_turnMiddleSliceUp(Cube * this);
void Cube_turnMiddleSliceDown(Cube * this);
void Cube_turnRightSliceUp(Cube * this);
void Cube_turnRightSliceDown(Cube * this);

void Cube_turnFrontSliceClockwise(Cube * this);
void Cube_turnFrontSliceAnticlockwise(Cube * this);
void Cube_turnStandingSliceClockwise(Cube * this);
void Cube_turnStandingSliceAnticlockwise(Cube * this);
void Cube_turnBackSliceClockwise(Cube * this);
void Cube_turnBackSliceAnticlockwise(Cube * this);




#endif /* CUBE_HEADER */
