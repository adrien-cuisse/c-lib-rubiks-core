
#include <criterion/criterion.h>

#include "asserts.h"
#include "utils.h"




void _assert_faceRotatedClockwise(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line)
{
	Color after[FACE_SIZE][FACE_SIZE];
	readFace(face, after);

	cr_assert_eq(
		before[1][1],
		after[1][1],
		"%s:%d :: %s face clockwise rotation: face changed color",
		file,
		line,
		facePosition);

	cr_assert_eq(
		before[0][0],
		after[0][2],
		"%s:%d :: %s face clockwise rotation -> top-left cell didn't go top-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[0][1],
		after[1][2],
		"%s:%d :: %s face clockwise rotation -> top-center cell didn't go equator-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[0][2],
		after[2][2],
		"%s:%d :: %s face clockwise rotation -> top-right cell didn't go bottom-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[1][0],
		after[0][1],
		"%s:%d :: %s face clockwise rotation -> equator-left cell didn't go top-center",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[1][2],
		after[2][1],
		"%s:%d :: %s face clockwise rotation -> equator-right cell didn't go bottom-center",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][0],
		after[0][0],
		"%s:%d :: %s face clockwise rotation -> bottom-left cell didn't go top-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][1],
		after[1][0],
		"%s:%d :: %s face clockwise rotation -> bottom-center cell didn't go equator-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][2],
		after[2][0],
		"%s:%d :: %s face clockwise rotation -> bottom-right cell didn't go bottom-left",
		file,
		line,
		facePosition);
}


void _assert_faceRotatedAnticlockwise(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line)
{
	Color after[FACE_SIZE][FACE_SIZE];
	readFace(face, after);

	cr_assert_eq(
		before[1][1],
		after[1][1],
		"%s:%d :: %s face anticlockwise rotation: face changed color",
		file,
		line,
		facePosition);

	cr_assert_eq(
		before[0][0],
		after[2][0],
		"%s:%d :: %s face anticlockwise rotation: top-left cell didn't go bottom-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[0][1],
		after[1][0],
		"%s:%d :: %s face anticlockwise rotation: top-center cell didn't go equator-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[0][2],
		after[0][0],
		"%s:%d :: %s face anticlockwise rotation: top-right cell didn't go top-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[1][0],
		after[2][1],
		"%s:%d :: %s face anticlockwise rotation: equator-left cell didn't bottom-center",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[1][2],
		after[0][1],
		"%s:%d :: %s face anticlockwise rotation: equator-right cell didn't go top-center",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][0],
		after[2][2],
		"%s:%d :: %s face anticlockwise rotation: bottom-left cell didn't go bottom-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][1],
		after[1][2],
		"%s:%d :: %s face anticlockwise rotation: bottom-center cell didn't equator-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][2],
		after[0][2],
		"%s:%d :: %s face anticlockwise rotation: bottom-right cell didn't go top-right",
		file,
		line,
		facePosition);
}


void _assert_faceFlipped(
	Color before[FACE_SIZE][FACE_SIZE],
	Face const * face,
	char const * facePosition,
	char const * file,
	int line)
{
	Color after[FACE_SIZE][FACE_SIZE];
	readFace(face, after);

	cr_assert_eq(
		before[1][1],
		after[1][1],
		"%s:%d :: %s face flip: face changed color",
		file,
		line,
		facePosition);

	cr_assert_eq(
		before[0][0],
		after[2][2],
		"%s:%d :: %s face flip: top-left cell didn't go bottom-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[0][1],
		after[2][1],
		"%s:%d :: %s face flip: top-middle cell didn't go bottom-middle",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[0][2],
		after[2][0],
		"%s:%d :: %s face flip: top-right cell didn't go bottom-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[1][0],
		after[1][2],
		"%s:%d :: %s face flip: equator-left cell didn't equator-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[1][2],
		after[1][0],
		"%s:%d :: %s face flip: equator-right cell didn't go equator-left",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][0],
		after[0][2],
		"%s:%d :: %s face flip: bottom-left cell didn't go top-right",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][1],
		after[0][1],
		"%s:%d :: %s face flip: bottom-middle cell didn't top-middle",
		file,
		line,
		facePosition);
	cr_assert_eq(
		before[2][2],
		after[0][0],
		"%s:%d :: %s face flip: bottom-right cell didn't go top-left",
		file,
		line,
		facePosition);
}