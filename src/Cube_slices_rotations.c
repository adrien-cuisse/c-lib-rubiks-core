
#include <stdlib.h>
#include <string.h>

#include "Face.h"
#include "Cube.h"

/**
 * Some functions rely on how we unfold the 3D cube, switching to another
 * 2D pattern will affect the marked functions
 * On the current pattern, 4 faces are vertically aligned, and only 3 are
 * horizontally aligned, so when doing horizontal slice rotations back face is
 * flipped, and parallel slices are switching axis on every span
 */
#define PATTERN_DEPENDANT




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
 * Reads a span on the cube
 *
 * @param this - the cube to get a span from
 *
 * @param span - the coords of the span to read
 *
 * @param buffer - the buffer where to write the span
 */
static void getSpan(Cube const * this, Span span, Color buffer[FACE_SIZE])
{
	int isRow = (span.column == (Column) -1);
	if (isRow)
		Face_copyRow(this->faces[span.face], buffer, span.row);
	else
		Face_copyColumn(this->faces[span.face], buffer, span.column);
}


/**
 * Writes a span on the cube
 *
 * @param this - the cube to write a span to
 *
 * @param span - the coords of the span to write
 *
 * @param content - the content of the span to write
 */
static void setSpan(Cube * this, Span span, Color const content[FACE_SIZE])
{
	int isRow = (span.column == (Column) -1);
	if (isRow)
		Face_setRow(this->faces[span.face], content, span.row);
	else
		Face_setColumn(this->faces[span.face], content, span.column);
}


/**
 * Checks if the span must be reversed, ie., if its face is in [reversingFaces]
 *
 * @param span - the span to check
 *
 * @param reversingFaces - the faces where spans should be reversed
 *
 * @param facesCount - the number of faces in [reversingFaces]
 *
 * @return int - 1 if span's face is in [reversingFaces], 0 otherwise
 */
static int mustReverseSpan(
	Span span,
	FacePosition const reversingFaces[],
	int facesCount)
{
	size_t bytesCount = facesCount * sizeof(* reversingFaces);
	return memchr(reversingFaces, span.face, bytesCount) != NULL;
}


/**
 * Copies a span and pastes it on another location
 *
 * @param this - the cube to read/write spans from
 *
 * @param from - the span to copy
 *
 * @param to - where to write the copied span
 */
static void moveSpan(Cube * this, Span from, Span to)
{
	Color span[FACE_SIZE];
	getSpan(this, from, span);
	setSpan(this, to, span);
}


/**
 * Reverses a span
 *
 * @param span - the span to reverse
 */
static void reverseSpan(Color span[FACE_SIZE])
{
	Color swap = span[0];
	span[0] = span[2];
	span[2] = swap;
}


/**
 * Copies, reverses and pastes a span
 *
 * @param this - the cube to read/write spans from
 *
 * @param from - the span to copy
 *
 * @param to - where to write the copied span
 */
static void moveReversedSpan(Cube * this, Span from, Span to)
{
	Color span[FACE_SIZE];
	getSpan(this, from, span);
	reverseSpan(span);
	setSpan(this, to, span);
}


/**
 * Applies a slice rotation on the cube
 *
 * @param this - the cube containing the slice to rotate
 *
 * @param slice - the slice to rotate
 *
 * @param reversingSpansFace - array of FacePosition, any span in the slice
 * 	having its face in that array will be reversed
 *
 * @param reversingCount - the number of faces in [reversingSpansFace]
 * 	(ie., the number of spans to reverse in the slice)
 */
static void rotateSlice(
	Cube * this,
	Slice slice,
	FacePosition const reversingSpansFace[],
	int reversingCount)
{
	int spanIndex;

	Span sourceSpan, destinationSpan;

	Color spanBackup[FACE_SIZE];
	getSpan(this, slice[3], spanBackup);

	for (spanIndex = 3; spanIndex > 0; spanIndex--)
	{
		sourceSpan = slice[spanIndex - 1];
		destinationSpan = slice[spanIndex];

		if (mustReverseSpan(sourceSpan, reversingSpansFace, reversingCount))
			moveReversedSpan(this, sourceSpan, destinationSpan);
		else
			moveSpan(this, sourceSpan, destinationSpan);
	}

	sourceSpan = slice[3];
	if (mustReverseSpan(sourceSpan, reversingSpansFace, reversingCount))
		reverseSpan(spanBackup);

	destinationSpan = slice[0];
	setSpan(this, destinationSpan, spanBackup);
}


/**
 * Rotates an horizontal slice to the left
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotateSliceLeft(Cube * this, Slice slice)
{
	FacePosition reversingSpansFace[2] = { LEFT_FACE, BACK_FACE };
	rotateSlice(this, slice, reversingSpansFace, 2);
}


/**
 * Rotates an horizontal slice to the right
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotateSliceRight(Cube * this, Slice slice)
{
	FacePosition reversingSpansFace[2] = { RIGHT_FACE, BACK_FACE };
	rotateSlice(this, slice, reversingSpansFace, 2);
}


void Cube_rotateTopSliceLeft(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, TOP_ROW, -1 },
		{ BACK_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, TOP_ROW, -1 }
	};
	rotateSliceLeft(this, slice);
	Face_rotateClockwise(Cube_topFace(this));
}


void Cube_rotateTopSliceRight(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, TOP_ROW, -1 },
		{ BACK_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, TOP_ROW, -1 }
	};
	rotateSliceRight(this, slice);
	Face_rotateAnticlockwise(Cube_topFace(this));
}


void Cube_rotateEquatorSliceLeft(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, EQUATOR_ROW, -1 },
		{ BACK_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, EQUATOR_ROW, -1 }
	};
	rotateSliceLeft(this, slice);
}


void Cube_rotateEquatorSliceRight(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, EQUATOR_ROW, -1 },
		{ BACK_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, EQUATOR_ROW, -1 }
	};
	rotateSliceRight(this, slice);
}


void Cube_rotateBottomSliceLeft(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, BOTTOM_ROW, -1 },
		{ BACK_FACE, TOP_ROW, -1},
		{ RIGHT_FACE, BOTTOM_ROW, -1 }
	};
	rotateSliceLeft(this, slice);
	Face_rotateAnticlockwise(Cube_bottomFace(this));
}


void Cube_rotateBottomSliceRight(Cube * this)
{
	Slice slice =
	{
		{ FRONT_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, BOTTOM_ROW, -1 },
		{ BACK_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, BOTTOM_ROW, -1 }
	};
	rotateSliceRight(this, slice);
	Face_rotateClockwise(Cube_bottomFace(this));
}


/**
 * Applies a vertical slice rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param column - the column of the slice to rotate
 *
 * @param rotation - the rotation to apply
 */
static void rotateVerticalSlice(Cube * this, Column column, Rotation rotation)
{
	int spanIndex;
	Slice slice;

	for (spanIndex = 0; spanIndex < 4; spanIndex++)
	{
		slice[spanIndex].face = rotation[spanIndex];
		slice[spanIndex].row = -1;
		slice[spanIndex].column = column;
	}

	rotateSlice(this, slice, NULL, 0);
}


/**
 * Applies a vertical slice up rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param column - the column of the slice to rotate
 */
PATTERN_DEPENDANT static void rotateSliceUp(Cube * this, Column column)
{
	Rotation rotation = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };
	rotateVerticalSlice(this, column, rotation);
}


/**
 * Applies a vertical slice down rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param column - the column of the slice to rotate
 */
PATTERN_DEPENDANT static void rotateSliceDown(Cube * this, Column column)
{
	Rotation rotation = { FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE };
	rotateVerticalSlice(this, column, rotation);
}


void Cube_rotateLeftSliceUp(Cube * this)
{
	rotateSliceUp(this, LEFT_COLUMN);
	Face_rotateAnticlockwise(Cube_leftFace(this));
}


void Cube_rotateLeftSliceDown(Cube * this)
{
	rotateSliceDown(this, LEFT_COLUMN);
	Face_rotateClockwise(Cube_leftFace(this));
}


void Cube_rotateMiddleSliceUp(Cube * this)
{
	rotateSliceUp(this, MIDDLE_COLUMN);
}


void Cube_rotateMiddleSliceDown(Cube * this)
{
	rotateSliceDown(this, MIDDLE_COLUMN);
}


void Cube_rotateRightSliceUp(Cube * this)
{
	rotateSliceUp(this, RIGHT_COLUMN);
	Face_rotateClockwise(Cube_rightFace(this));
}


void Cube_rotateRightSliceDown(Cube * this)
{
	rotateSliceDown(this, RIGHT_COLUMN);
	Face_rotateAnticlockwise(Cube_rightFace(this));
}


/**
 * Applies a parallel slice clockwise rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotateSliceClockwise(Cube * this, Slice slice)
{
	FacePosition reversingSpansFace[2] = { RIGHT_FACE, LEFT_FACE };
	rotateSlice(this, slice, reversingSpansFace, 2);
}


void Cube_rotateFrontSliceClockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN }
	};
	rotateSliceClockwise(this, slice);
	Face_rotateClockwise(Cube_frontFace(this));
}


/**
 * Applies a parallel slice anticlockwise rotation on the cube
 *
 * @param this - the cube containing the slice
 *
 * @param slice - the slice to rotate
 */
PATTERN_DEPENDANT static void rotateSliceAnticlockwise(Cube * this, Slice slice)
{
	FacePosition reversingSpansFace[2] = { TOP_FACE, BOTTOM_FACE };
	rotateSlice(this, slice, reversingSpansFace, 2);
}


void Cube_rotateFrontSliceAnticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, LEFT_COLUMN }
	};
	rotateSliceAnticlockwise(this, slice);
	Face_rotateAnticlockwise(Cube_frontFace(this));
}


void Cube_rotateStandingSliceClockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN }
	};
	rotateSliceClockwise(this, slice);
}


void Cube_rotateStandingSliceAnticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, EQUATOR_ROW, -1 },
		{ LEFT_FACE, -1, MIDDLE_COLUMN },
		{ BOTTOM_FACE, EQUATOR_ROW, -1 },
		{ RIGHT_FACE, -1, MIDDLE_COLUMN }
	};
	rotateSliceAnticlockwise(this, slice);
}


void Cube_rotateBackSliceClockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN }
	};
	rotateSliceClockwise(this, slice);
	Face_rotateAnticlockwise(Cube_backFace(this));
}


void Cube_rotateBackSliceAnticlockwise(Cube * this)
{
	Slice slice =
	{
		{ TOP_FACE, TOP_ROW, -1 },
		{ LEFT_FACE, -1, LEFT_COLUMN },
		{ BOTTOM_FACE, BOTTOM_ROW, -1 },
		{ RIGHT_FACE, -1, RIGHT_COLUMN }
	};
	rotateSliceAnticlockwise(this, slice);
	Face_rotateClockwise(Cube_backFace(this));
}
