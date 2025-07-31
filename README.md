

# 📚 lib rubiks-core

A rubik's cube shared library writen in **C** and made in **TDD**


## 🧰 Features

- slices rotations
- camera rotations
- wide moves (2 slices at a time)


## 🫨 Why ?

This library is intended to be the foundation of a 3D rubik's cube solver (GUI),
it's responsible for modelizing the cube and applying moves (camera, slices rotations)


## 📦 Building it and checking

```
make lib
make run-tests
```


## 🤔 How to use

Include headers located in the `include/` directory in your project and link the library
```
gcc [your sources].c -Llib/ -lrubiks-core -o [your program]
LD_LIBRARY_PATH=lib/ ./[your program]
```


## 👇 Usage example, naive scrambling algorithm and cube display

```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "include/Cube.h"

/* Array of function pointers, every possible move */
void (* scramblings[])(Cube *) =
{
	Cube_rotateTopSliceLeft,
	Cube_rotateTopSliceRight,
	Cube_rotateEquatorSliceLeft,
	Cube_rotateEquatorSliceRight,
	Cube_rotateBottomSliceLeft,
	Cube_rotateBottomSliceRight,
	Cube_rotateLeftSliceUp,
	Cube_rotateLeftSliceDown,
	Cube_rotateMiddleSliceUp,
	Cube_rotateMiddleSliceDown,
	Cube_rotateRightSliceUp,
	Cube_rotateRightSliceDown,
	Cube_rotateFrontSliceClockwise,
	Cube_rotateFrontSliceAnticlockwise,
	Cube_rotateStandingSliceClockwise,
	Cube_rotateStandingSliceAnticlockwise,
	Cube_rotateBackSliceClockwise,
	Cube_rotateBackSliceAnticlockwise,
};

/* Display labels */
char const colors[] = { 'R', 'B', 'O', 'Y', 'G', 'W' };

static void print_face(Face const * face)
{
	printf("          | %c %c %c |\n",
		colors[Face_topLeftCell(face)],
		colors[Face_topCenterCell(face)],
		colors[Face_topRightCell(face)]);
	printf("          | %c %c %c |\n",
		colors[Face_equatorLeftCell(face)],
		colors[Face_color(face)],
		colors[Face_equatorRightCell(face)]);
	printf("          | %c %c %c |\n",
		colors[Face_bottomLeftCell(face)],
		colors[Face_bottomCenterCell(face)],
		colors[Face_bottomRightCell(face)]);
}

static void print_cube(Cube const * cube)
{
	Face * left = Cube_leftFace(cube);
	Face * front = Cube_frontFace(cube);
	Face * right = Cube_rightFace(cube);
	printf("   +------+--------+-----+\n");
	printf("    %c %c %c | %c %c %c | %c %c %c\n",
		colors[Face_topLeftCell(left)], colors[Face_topCenterCell(left)], colors[Face_topRightCell(left)],
		colors[Face_topLeftCell(front)], colors[Face_topCenterCell(front)], colors[Face_topRightCell(front)],
		colors[Face_topLeftCell(right)], colors[Face_topCenterCell(right)], colors[Face_topRightCell(right)]);
	printf("    %c %c %c | %c %c %c | %c %c %c\n",
		colors[Face_equatorLeftCell(left)], colors[Face_color(left)], colors[Face_equatorRightCell(left)],
		colors[Face_equatorLeftCell(front)], colors[Face_color(front)], colors[Face_equatorRightCell(front)],
		colors[Face_equatorLeftCell(right)], colors[Face_color(right)], colors[Face_equatorRightCell(right)]);
	printf("    %c %c %c | %c %c %c | %c %c %c\n",
		colors[Face_bottomLeftCell(left)], colors[Face_bottomCenterCell(left)], colors[Face_bottomRightCell(left)],
		colors[Face_bottomLeftCell(front)], colors[Face_bottomCenterCell(front)], colors[Face_bottomRightCell(front)],
		colors[Face_bottomLeftCell(right)], colors[Face_bottomCenterCell(right)], colors[Face_bottomRightCell(right)]);
	printf("   +------+--------+-----+\n");

	Face * bottom = Cube_bottomFace(cube);
	print_face(bottom);
	printf("          +-------+\n");

	Face * back = Cube_backFace(cube);
	print_face(back);
	printf("          +-------+\n");

	Face * top = Cube_topFace(cube);
	print_face(top);
	printf("          +-------+\n");
}

void * create_scrambled_cube(size_t scramble_length)
{
	int function_index;

	Cube * cube = Cube_create();

	while (scramble_length--)
	{
		/* naive algorithm for demo purpose */
		function_index = rand() % 18;
		scramblings[function_index](cube);
	}

	return cube;
}

int main(void)
{
	Cube * cube;

	srand(time(NULL));

	cube = create_scrambled_cube(42);
	print_cube(cube);
	Cube_delete(& cube);

	return EXIT_SUCCESS;
}
```
```bash
gcc example.c -o example -Llib/ -lrubiks-core && LD_LIBRARY_PATH=lib/ ./example
```


## 🧐 Why not using official notation / Why using this functions naming ?

Official terminology uses capital letters (first letter for Left, Front,
Right, Up, Down, Back) which mean "rotate that face clockwise as if it was the
front one", resulting visually in a counter-intuitive move
Here we are only using visual notation to keep code understandable,
eg., B means 'rotate back face clockwise', and without rotating the cube to
get the back face in front we get a visual anticlockwise rotation of the back
slice


## 🤓 How can I port this to another language ?
Just grab tests (specs) and follow the 3 TDD rules:
- Do not write any production code without a failing test first
- Write only enough test code as is sufficient enough to fail
- Only implement a minimal code that makes the failing test pass

One test a time: red, green, refactor

include/ directory contains public functions/method, everything in src/ is
implementation detail (might change in the future), you may want to do
things different


## Known issues

- Tests are repetitive: it's hard to refactor macro-based tests, providing function
pointers doesn't really help readability, plus we have to `#define`the call to our functions
to keep track of `__FILE__` and `__LINE__`
- There are maaaany tests: yes, every spec is tested


## 😨 Found a bug ?

Create a pull request with a failing test, I'll make it pass
