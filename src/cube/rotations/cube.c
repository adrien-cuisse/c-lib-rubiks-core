
#include "../../face/face.h"
#include "../cube.h"




void rbc_rotate_cube_left(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ RBC_FRONT_FACE, RBC_LEFT_FACE, RBC_BACK_FACE, RBC_RIGHT_FACE }};

	rotate_face_clockwise(rbc_cube_bottom_face(this));
	rotate_face_anticlockwise(rbc_cube_top_face(this));

	rotate_cube(this, & rotation);
}


void rbc_rotate_cube_right(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ RBC_FRONT_FACE, RBC_RIGHT_FACE, RBC_BACK_FACE, RBC_LEFT_FACE }};

	rotate_face_anticlockwise(rbc_cube_bottom_face(this));
	rotate_face_clockwise(rbc_cube_top_face(this));

	rotate_cube(this, & rotation);
}


void rbc_rotate_cube_up(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ RBC_FRONT_FACE, RBC_TOP_FACE, RBC_BACK_FACE, RBC_BOTTOM_FACE }};

	rotate_face_anticlockwise(rbc_cube_left_face(this));
	rotate_face_clockwise(rbc_cube_right_face(this));

	rotate_cube(this, & rotation);
}


void rbc_rotate_cube_down(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ RBC_FRONT_FACE, RBC_BOTTOM_FACE, RBC_BACK_FACE, RBC_TOP_FACE }};

	rotate_face_clockwise(rbc_cube_left_face(this));
	rotate_face_anticlockwise(rbc_cube_right_face(this));

	rotate_cube(this, & rotation);
}


void rbc_rotate_cube_clockwise(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ RBC_TOP_FACE, RBC_RIGHT_FACE, RBC_BOTTOM_FACE, RBC_LEFT_FACE }};

	rotate_face_clockwise(rbc_cube_front_face(this));
	rotate_face_anticlockwise(rbc_cube_back_face(this));

	rotate_cube(this, & rotation);
}


void rbc_rotate_cube_anticlockwise(struct rbc_cube * this)
{
	struct rbc_faces_cycle rotation = {{ RBC_TOP_FACE, RBC_LEFT_FACE, RBC_BOTTOM_FACE, RBC_RIGHT_FACE }};

	rotate_face_anticlockwise(rbc_cube_front_face(this));
	rotate_face_clockwise(rbc_cube_back_face(this));

	rotate_cube(this, & rotation);
}
