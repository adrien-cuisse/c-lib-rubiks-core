
#ifndef CUBE_HEADER
#define CUBE_HEADER

#include "Face.h"

#define CUBE_SIZE 3




typedef struct Cube Cube;


typedef struct
{
	Cube * (* create)(void);
	void (* delete)(Cube ** this);

	Face * (* leftFace)(Cube const * this);
	Face * (* frontFace)(Cube const * this);
	Face * (* rightFace)(Cube const * this);
	Face * (* topFace)(Cube const * this);
	Face * (* bottomFace)(Cube const * this);
	Face * (* backFace)(Cube const * this);

	void (* rotateLeft)(Cube * this);
	void (* rotateRight)(Cube * this);
	void (* rotateUp)(Cube * this);
	void (* rotateDown)(Cube * this);
	void (* rotateClockwise)(Cube * this);
	void (* rotateAnticlockwise)(Cube * this);

	void (* turnTopSliceLeft)(Cube * this);

} CubeMethods;




extern CubeMethods const * const _Cube;




#endif /* CUBE_HEADER */
