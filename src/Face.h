
#ifndef FACE_HEADER
#define FACE_HEADER

#include "Color.h"




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

	Color * (* topSlice)(Face const * this);
	Color * (* middleSlice)(Face const * this);
	Color * (* bottomSlice)(Face const * this);

} FaceMethods;




extern FaceMethods const * const _Face;




#endif /* FACE_HEADER */
