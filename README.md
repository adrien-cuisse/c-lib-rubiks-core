

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
void (* scramblings[])(struct rbc_cube *) =
{
	rubiks_cube_rotate_top_slice_left,
	rubiks_cube_rotate_top_slice_right,
	rubiks_cube_rotate_equator_slice_left,
	rubiks_cube_rotate_equator_slice_right,
	rubiks_cube_rotate_bottom_slice_left,
	rubiks_cube_rotate_bottom_slice_right,
	rubiks_cube_rotate_left_slice_up,
	rubiks_cube_rotate_left_slice_down,
	rubiks_cube_rotate_middle_slice_up,
	rubiks_cube_rotate_middle_slice_down,
	rubiks_cube_rotate_right_slice_up,
	rubiks_cube_rotate_right_slice_down,
	rubiks_cube_rotate_front_slice_clockwise,
	rubiks_cube_rotate_front_slice_anticlockwise,
	rubiks_cube_rotate_standing_slice_clockwise,
	rubiks_cube_rotate_standing_slice_anticlockwise,
	rubiks_cube_rotate_back_slice_clockwise,
	rubiks_cube_rotate_back_slice_anticlockwise,
};

/* Display labels */
char const colors[] = { 'R', 'B', 'O', 'Y', 'G', 'W' };

static void print_face(Face const * face)
{
	printf("          | %c %c %c |\n",
		colors[rubiks_face_top_left_cell(face)],
		colors[rubiks_face_top_center_cell(face)],
		colors[rubiks_face_top_right_cell(face)]);
	printf("          | %c %c %c |\n",
		colors[rubiks_face_equator_left_cell(face)],
		colors[rubiks_face_color(face)],
		colors[rubiks_face_equator_right_cell(face)]);
	printf("          | %c %c %c |\n",
		colors[rubiks_face_bottom_left_cell(face)],
		colors[rubiks_face_bottom_center_cell(face)],
		colors[rubiks_face_bottom_right_cell(face)]);
}

static void print_cube(struct rbc_cube const * cube)
{
	Face * left = rubiks_cube_left_face(cube);
	Face * front = rubiks_cube_front_face(cube);
	Face * right = rubiks_cube_right_face(cube);
	printf("   +------+--------+-----+\n");
	printf("    %c %c %c | %c %c %c | %c %c %c\n",
		colors[rubiks_face_top_left_cell(left)], colors[rubiks_face_top_center_cell(left)], colors[rubiks_face_top_right_cell(left)],
		colors[rubiks_face_top_left_cell(front)], colors[rubiks_face_top_center_cell(front)], colors[rubiks_face_top_right_cell(front)],
		colors[rubiks_face_top_left_cell(right)], colors[rubiks_face_top_center_cell(right)], colors[rubiks_face_top_right_cell(right)]);
	printf("    %c %c %c | %c %c %c | %c %c %c\n",
		colors[rubiks_face_equator_left_cell(left)], colors[rubiks_face_color(left)], colors[rubiks_face_equator_right_cell(left)],
		colors[rubiks_face_equator_left_cell(front)], colors[rubiks_face_color(front)], colors[rubiks_face_equator_right_cell(front)],
		colors[rubiks_face_equator_left_cell(right)], colors[rubiks_face_color(right)], colors[rubiks_face_equator_right_cell(right)]);
	printf("    %c %c %c | %c %c %c | %c %c %c\n",
		colors[rubiks_face_bottom_left_cell(left)], colors[rubiks_face_bottom_center_cell(left)], colors[rubiks_face_bottom_right_cell(left)],
		colors[rubiks_face_bottom_left_cell(front)], colors[rubiks_face_bottom_center_cell(front)], colors[rubiks_face_bottom_right_cell(front)],
		colors[rubiks_face_bottom_left_cell(right)], colors[rubiks_face_bottom_center_cell(right)], colors[rubiks_face_bottom_right_cell(right)]);
	printf("   +------+--------+-----+\n");

	Face * bottom = rubiks_cube_bottom_face(cube);
	print_face(bottom);
	printf("          +-------+\n");

	Face * back = rubiks_cube_back_face(cube);
	print_face(back);
	printf("          +-------+\n");

	Face * top = rubiks_cube_top_face(cube);
	print_face(top);
	printf("          +-------+\n");
}

void * create_scrambled_cube(size_t scramble_length)
{
	int function_index;

	struct rbc_cube * cube = rubiks_cube_create();

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
	struct rbc_cube * cube;

	srand(time(NULL));

	cube = create_scrambled_cube(42);
	print_cube(cube);
	rubiks_cube_delete(& cube);

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
pointers doesn't really help readability, plus we have to `#define` the call to our functions
to keep track of `__FILE__` and `__LINE__`
- There are maaaany tests: yes, every spec is tested


## 😨 Found a bug ?

Create a pull request with a failing test, I'll make it pass
