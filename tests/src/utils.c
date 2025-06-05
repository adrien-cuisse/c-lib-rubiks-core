
#include "../../include/Cube.h"




Cube * createScrambledCube(void)
{
	Cube * cube = Cube_create();

#if 1

	// official terminology:
	// D2 F2 R2 D2 L2 U F2 U' F' U F2 U' R2 B' F R' D2 F' D' L
	//
	// D2
	Cube_rotateBottomSliceRight(cube);
	Cube_rotateBottomSliceRight(cube);
	// F2
	Cube_rotateFrontSliceClockwise(cube);
	Cube_rotateFrontSliceClockwise(cube);
	// R2
	Cube_rotateRightSliceUp(cube);
	Cube_rotateRightSliceUp(cube);
	// D2
	Cube_rotateBottomSliceRight(cube);
	Cube_rotateBottomSliceRight(cube);
	// L2
	Cube_rotateLeftSliceDown(cube);
	Cube_rotateLeftSliceDown(cube);
	// U
	Cube_rotateTopSliceLeft(cube);
	// F2
	Cube_rotateFrontSliceClockwise(cube);
	Cube_rotateFrontSliceClockwise(cube);
	// U'
	Cube_rotateTopSliceRight(cube);
	// F'
	Cube_rotateFrontSliceAnticlockwise(cube);
	// U
	Cube_rotateTopSliceLeft(cube);
	// F2
	Cube_rotateFrontSliceClockwise(cube);
	Cube_rotateFrontSliceClockwise(cube);
	// U'
	Cube_rotateTopSliceRight(cube);
	// R2
	Cube_rotateRightSliceUp(cube);
	Cube_rotateRightSliceUp(cube);
	// B'
	Cube_rotateBackSliceClockwise(cube);
	// F
	Cube_rotateFrontSliceClockwise(cube);
	// R'
	Cube_rotateRightSliceDown(cube);
	// D2
	Cube_rotateBottomSliceRight(cube);
	Cube_rotateBottomSliceRight(cube);
	// F'
	Cube_rotateFrontSliceAnticlockwise(cube);
	// D'
	Cube_rotateBottomSliceLeft(cube);
	// L
	Cube_rotateLeftSliceDown(cube);

    //	+-------+-------+-------+
    //	| G W Y | R Y W | R W B |
    //	| B R O | W B G | Y O G |
    //	| O Y G | Y R O | W B Y |
    //	+-------+-------+-------+
    //	        | O W G |
    //	        | R Y R |
    //	        | B G O |
    //	        +-------+
    //	        | W R B |
    //	        | Y G O |
    //	        | W B R |
    //	        +-------+
    //	        | R O Y |
    //	        | B W G |
    //	        | G O B |
	//		    +-------+

	//	        +-------+
    //	        | R O Y |
    //	        | B W G |
    //	        | G O B |
    //	+-------+-------+-------+-------+
    //	| G W Y | R Y W | R W B | R B W |
    //	| B R O | W B G | Y O G | O G Y |
    //	| O Y G | Y R O | W B Y | B R W |
    //	+-------+-------+-------+-------+
    //	        | O W G |
    //	        | R Y R |
    //	        | B G O |
    //	        +-------+

#elif 1

	// https://rubikscu.be/
	//
	// x x z z D2 F2 R2
	//
	// blue face in front, orange to the right, white above

	// D2
	Cube_rotateBottomSliceRight(cube);
	/*Cube_rotateBottomSliceRight(cube);
	// F2
	Cube_rotateFrontSliceClockwise(cube);
	Cube_rotateFrontSliceClockwise(cube);
	// R2
	Cube_rotateRightSliceUp(cube);
	Cube_rotateRightSliceUp(cube);*/

#else

	int rotationsLeft = 7;
	while (rotationsLeft--)
	{
		Cube_rotateTopSliceLeft(cube);
		Cube_rotateLeftSliceUp(cube);
		Cube_rotateFrontSliceClockwise(cube);

		Cube_rotateBottomSliceRight(cube);
		Cube_rotateRightSliceDown(cube);
		Cube_rotateBackSliceAnticlockwise(cube);
	}

#endif

	return cube;
}


void topRow(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topLeftCell(face);
	buffer[1] = Face_topCenterCell(face);
	buffer[2] = Face_topRightCell(face);
}


void equatorRow(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_equatorLeftCell(face);
	buffer[1] = Face_equatorCenterCell(face);
	buffer[2] = Face_equatorRightCell(face);
}


void bottomRow(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_bottomLeftCell(face);
	buffer[1] = Face_bottomCenterCell(face);
	buffer[2] = Face_bottomRightCell(face);
}


void leftColumn(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topLeftCell(face);
	buffer[1] = Face_equatorLeftCell(face);
	buffer[2] = Face_bottomLeftCell(face);
}


void middleColumn(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topCenterCell(face);
	buffer[1] = Face_equatorCenterCell(face);
	buffer[2] = Face_bottomCenterCell(face);
}


void rightColumn(Face const * face, Color buffer[FACE_SIZE])
{
	buffer[0] = Face_topRightCell(face);
	buffer[1] = Face_equatorRightCell(face);
	buffer[2] = Face_bottomRightCell(face);
}


void readFace(Face const * face, Color buffer[FACE_SIZE][FACE_SIZE])
{
	topRow(face, buffer[0]);
	equatorRow(face, buffer[1]);
	bottomRow(face, buffer[2]);
}


void reverseSpan(Color buffer[FACE_SIZE])
{
	Color swap = buffer[0];
	buffer[0] = buffer[2];
	buffer[2] = swap;
}
