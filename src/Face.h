
#ifndef FACE_HEADER
#define FACE_HEADER

#include "Color.h"

#define FACE_SIZE 3




typedef struct Face Face;


typedef struct
{
	Face * (* create)(Color color);
	void (* delete)(Face ** this);

	Color (* color)(Face const * this);

	Color (* topLeftCell)(Face const * this);
	Color (* topCenterCell)(Face const * this);
	Color (* topRightCell)(Face const * this);
	Color (* middleLeftCell)(Face const * this);
	Color (* middleCenterCell)(Face const * this);
	Color (* middleRightCell)(Face const * this);
	Color (* bottomLeftCell)(Face const * this);
	Color (* bottomCenterCell)(Face const * this);
	Color (* bottomRightCell)(Face const * this);

	void (* topSlice)(Face const * this, Color storage[FACE_SIZE]);
	void (* middleSlice)(Face const * this, Color storage[FACE_SIZE]);
	void (* bottomSlice)(Face const * this, Color storage[FACE_SIZE]);
	void (* leftSlice)(Face const * this, Color storage[FACE_SIZE]);

} FaceMethods;




extern FaceMethods const * const _Face;




#endif /* FACE_HEADER */
