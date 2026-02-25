
#include "../face/Face.h"
#include "Cube.h"




void rbc_rotate_cube_left(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ FRONT_FACE, LEFT_FACE, BACK_FACE, RIGHT_FACE }};

	rotate_face_clockwise(rbc_cube_bottom_face(this));
	rotate_face_anticlockwise(rbc_cube_top_face(this));

	rotate_cube(this, & rotation);
}


void rbc_rotate_cube_right(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ FRONT_FACE, RIGHT_FACE, BACK_FACE, LEFT_FACE }};

	rotate_face_anticlockwise(rbc_cube_bottom_face(this));
	rotate_face_clockwise(rbc_cube_top_face(this));

	rotate_cube(this, & rotation);
}


void rbc_rotate_cube_up(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ FRONT_FACE, TOP_FACE, BACK_FACE, BOTTOM_FACE }};

	rotate_face_anticlockwise(rbc_cube_left_face(this));
	rotate_face_clockwise(rbc_cube_right_face(this));

	rotate_cube(this, & rotation);
}


void rbc_rotate_cube_down(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ FRONT_FACE, BOTTOM_FACE, BACK_FACE, TOP_FACE }};

	rotate_face_clockwise(rbc_cube_left_face(this));
	rotate_face_anticlockwise(rbc_cube_right_face(this));

	rotate_cube(this, & rotation);
}


void rbc_rotate_cube_clockwise(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ TOP_FACE, RIGHT_FACE, BOTTOM_FACE, LEFT_FACE }};

	rotate_face_clockwise(rbc_cube_front_face(this));
	rotate_face_anticlockwise(rbc_cube_back_face(this));

	rotate_cube(this, & rotation);
}


void rbc_rotate_cube_anticlockwise(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ TOP_FACE, LEFT_FACE, BOTTOM_FACE, RIGHT_FACE }};

	rotate_face_anticlockwise(rbc_cube_front_face(this));
	rotate_face_clockwise(rbc_cube_back_face(this));

	rotate_cube(this, & rotation);
}
