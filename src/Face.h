
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
	Color (* equatorLeftCell)(Face const * this);
	Color (* equatorCenterCell)(Face const * this);
	Color (* equatorRightCell)(Face const * this);
	Color (* bottomLeftCell)(Face const * this);
	Color (* bottomCenterCell)(Face const * this);
	Color (* bottomRightCell)(Face const * this);

	void (* topRow)(Face const * this, Color storage[FACE_SIZE]);
	void (* equatorRow)(Face const * this, Color storage[FACE_SIZE]);
	void (* bottomRow)(Face const * this, Color storage[FACE_SIZE]);

	void (* leftColumn)(Face const * this, Color storage[FACE_SIZE]);
	void (* middleColumn)(Face const * this, Color storage[FACE_SIZE]);
	void (* rightColumn)(Face const * this, Color storage[FACE_SIZE]);

	void (* rotateClockwise)(Face * this);
	void (* rotateAnticlockwise)(Face * this);

} FaceMethods;




extern FaceMethods const * const _Face;




#endif /* FACE_HEADER */
