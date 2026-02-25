
#include "../face/Face.h"
#include "Cube.h"




void rubiks_cube_rotate_left(Cube * this)
{
	Rotation rotation = { FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE };

	rotate_face_clockwise(rubiks_cube_bottom_face(this));
	rotate_face_anticlockwise(rubiks_cube_top_face(this));

	rotate_cube(this, rotation);
}


void rubiks_cube_rotate_right(Cube * this)
{
	Rotation rotation = { FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE };

	rotate_face_anticlockwise(rubiks_cube_bottom_face(this));
	rotate_face_clockwise(rubiks_cube_top_face(this));

	rotate_cube(this, rotation);
}


void rubiks_cube_rotate_up(Cube * this)
{
	Rotation rotation = { FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE };

	rotate_face_anticlockwise(rubiks_cube_left_face(this));
	rotate_face_clockwise(rubiks_cube_right_face(this));

	rotate_cube(this, rotation);
}


void rubiks_cube_rotate_down(Cube * this)
{
	Rotation rotation = { FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE };

	rotate_face_clockwise(rubiks_cube_left_face(this));
	rotate_face_anticlockwise(rubiks_cube_right_face(this));

	rotate_cube(this, rotation);
}


void rubiks_cube_rotate_clockwise(Cube * this)
{
	Rotation rotation = { TOP_FACE, RIGHT_FACE, BOTTOM_FACE, LEFT_FACE };

	rotate_face_clockwise(rubiks_cube_front_face(this));
	rotate_face_anticlockwise(rubiks_cube_back_face(this));

	rotate_cube(this, rotation);
}


void rubiks_cube_rotate_anticlockwise(Cube * this)
{
	Rotation rotation = { TOP_FACE, LEFT_FACE, BOTTOM_FACE, RIGHT_FACE };

	rotate_face_anticlockwise(rubiks_cube_front_face(this));
	rotate_face_clockwise(rubiks_cube_back_face(this));

	rotate_cube(this, rotation);
}
