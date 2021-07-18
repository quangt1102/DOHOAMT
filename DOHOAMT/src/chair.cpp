#include "chair.h"

//------------------------------------------------------------Load texture--------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------
void Chair::drawChair(GLuint chairTexture) {


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, chairTexture);
	glBegin(GL_QUADS);

	//Front
	//
	glTexCoord3f(-2.0f, -0.2f, 2.0f); glVertex3f(-2.0f, -0.2f, 2.0f);
	glTexCoord3f(2.0f, -0.2f, 2.0f); glVertex3f(2.0f, -0.2f, 2.0f);
	glTexCoord3f(2.0f, 0.2f, 2.0f); glVertex3f(2.0f, 0.2f, 2.0f);
	glTexCoord3f(-2.0f, 0.2f, 2.0f); glVertex3f(-2.0f, 0.2f, 2.0f);
	
	//Right
	//
	glTexCoord3f(2.0f, -0.2f, -2.0f); glVertex3f(2.0f, -0.2f, -2.0f);
	glTexCoord3f(2.0f, 0.2f, -2.0f); glVertex3f(2.0f, 0.2f, -2.0f);
	glTexCoord3f(2.0f, 0.2f, 2.0f); glVertex3f(2.0f, 0.2f, 2.0f);
	glTexCoord3f(2.0f, -0.2f, 2.0f); glVertex3f(2.0f, -0.2f, 2.0f);

	//Back
	//;
	glTexCoord3f(-2.0f, -0.2f, -2.0f); glVertex3f(-2.0f, -0.2f, -2.0f);
	glTexCoord3f(-2.0f, 0.2f, -2.0f); glVertex3f(-2.0f, 0.2f, -2.0f);
	glTexCoord3f(2.0f, 0.2f, -2.0f); glVertex3f(2.0f, 0.2f, -2.0f);
	glTexCoord3f(2.0f, -0.2f, -2.0f); glVertex3f(2.0f, -0.2f, -2.0f);

	//Left
	;
	glTexCoord3f(-2.0f, -0.2f, -2.0f); glVertex3f(-2.0f, -0.2f, -2.0f);
	glTexCoord3f(-2.0f, -0.2f, 2.0f); glVertex3f(-2.0f, -0.2f, 2.0f);
	glTexCoord3f(-2.0f, 0.2f, 2.0f); glVertex3f(-2.0f, 0.2f, 2.0f);
	glTexCoord3f(-2.0f, 0.2f, -2.0f); glVertex3f(-2.0f, 0.2f, -2.0f);

	//top
	//

	glTexCoord3f(0.0f, 0.0f, 2.0f); glVertex3f(2.0f, 0.2f, 2.0f);
	glTexCoord3f(1.0f, 0.0f, 2.0f); glVertex3f(-2.0f, 0.2f, 2.0f);
	glTexCoord3f(1.0f, 1.0f, -2.0f); glVertex3f(-2.0f, 0.2f, -2.0f);
	glTexCoord3f(0.0f, 1.0f, -2.0f); glVertex3f(2.0f, 0.2f, -2.0f);

	//bottom
	;

	glTexCoord3f(2.0f, -0.2f, 2.0f); glVertex3f(2.0f, -0.2f, 2.0f);
	glTexCoord3f(-2.0f, -0.2f, 2.0f); glVertex3f(-2.0f, -0.2f, 2.0f);
	glTexCoord3f(-2.0f, -0.2f, -2.0f); glVertex3f(-2.0f, -0.2f, -2.0f);
	glTexCoord3f(2.0f, -0.2f, -2.0f); glVertex3f(2.0f, -0.2f, -2.0f);

	//table front leg
	//front
	//

	glTexCoord3f(1.8f, -0.2f, 1.6f); glVertex3f(1.8f, -0.2f, 1.6f);
	glTexCoord3f(1.4f, -0.2f, 1.6f); glVertex3f(1.4f, -0.2f, 1.6f);
	glTexCoord3f(1.4f, -3.0f, 1.6f); glVertex3f(1.4f, -3.0f, 1.6f);
	glTexCoord3f(1.8f, -3.0f, 1.6f); glVertex3f(1.8f, -3.0f, 1.6f);

	//back
	//;

	glTexCoord3f(1.8f, -0.2f, 1.2f); glVertex3f(1.8f, -0.2f, 1.2f);
	glTexCoord3f(1.4f, -0.2f, 1.2f); glVertex3f(1.4f, -0.2f, 1.2f);
	glTexCoord3f(1.4f, -3.0f, 1.2f); glVertex3f(1.4f, -3.0f, 1.2f);
	glTexCoord3f(1.8f, -3.0f, 1.2f); glVertex3f(1.8f, -3.0f, 1.2f);

	//right
	//

	glTexCoord3f(1.8f, -0.2f, 1.6f); glVertex3f(1.8f, -0.2f, 1.6f);
	glTexCoord3f(1.8f, -0.2f, 1.2f); glVertex3f(1.8f, -0.2f, 1.2f);
	glTexCoord3f(1.8f, -3.0f, 1.2f); glVertex3f(1.8f, -3.0f, 1.2f);
	glTexCoord3f(1.8f, -3.0f, 1.6f); glVertex3f(1.8f, -3.0f, 1.6f);

	//left
	//;

	glTexCoord3f(1.4f, -0.2f, 1.6f); glVertex3f(1.4f, -0.2f, 1.6f);
	glTexCoord3f(1.4f, -0.2f, 1.2f); glVertex3f(1.4f, -0.2f, 1.2f);
	glTexCoord3f(1.4f, -3.0f, 1.2f); glVertex3f(1.4f, -3.0f, 1.2f);
	glTexCoord3f(1.4f, -3.0f, 1.6f); glVertex3f(1.4f, -3.0f, 1.6f);

	//back leg back
	//front
	//;

	glTexCoord3f(1.8f, -0.2f, -1.2f); glVertex3f(1.8f, -0.2f, -1.2f);
	glTexCoord3f(1.4f, -0.2f, -1.2f); glVertex3f(1.4f, -0.2f, -1.2f);
	glTexCoord3f(1.4f, -3.0f, -1.2f); glVertex3f(1.4f, -3.0f, -1.2f);
	glTexCoord3f(1.8f, -3.0f, -1.2f); glVertex3f(1.8f, -3.0f, -1.2f);

	//back
	//;

	glTexCoord3f(1.8f, -0.2f, -1.6f); glVertex3f(1.8f, -0.2f, -1.6f);
	glTexCoord3f(1.4f, -0.2f, -1.6f); glVertex3f(1.4f, -0.2f, -1.6f);
	glTexCoord3f(1.4f, -3.0f, -1.6f); glVertex3f(1.4f, -3.0f, -1.6f);
	glTexCoord3f(1.8f, -3.0f, -1.6f); glVertex3f(1.8f, -3.0f, -1.6f);

	//right
	//

	glTexCoord3f(1.8f, -0.2f, -1.6f); glVertex3f(1.8f, -0.2f, -1.6f);
	glTexCoord3f(1.8f, -0.2f, -1.2f); glVertex3f(1.8f, -0.2f, -1.2f);
	glTexCoord3f(1.8f, -3.0f, -1.2f); glVertex3f(1.8f, -3.0f, -1.2f);
	glTexCoord3f(1.8f, -3.0f, -1.6f); glVertex3f(1.8f, -3.0f, -1.6f);

	//left
	//

	glTexCoord3f(1.4f, -0.2f, -1.6f); glVertex3f(1.4f, -0.2f, -1.6f);
	glTexCoord3f(1.4f, -0.2f, -1.2f); glVertex3f(1.4f, -0.2f, -1.2f);
	glTexCoord3f(1.4f, -3.0f, -1.2f); glVertex3f(1.4f, -3.0f, -1.2f);
	glTexCoord3f(1.4f, -3.0f, -1.6f); glVertex3f(1.4f, -3.0f, -1.6f);

	//leg left front
	//

	glTexCoord3f(-1.8f, -0.2f, 1.6f); glVertex3f(-1.8f, -0.2f, 1.6f);
	glTexCoord3f(-1.4f, -0.2f, 1.6f); glVertex3f(-1.4f, -0.2f, 1.6f);
	glTexCoord3f(-1.4f, -3.0f, 1.6f); glVertex3f(-1.4f, -3.0f, 1.6f);
	glTexCoord3f(-1.8f, -3.0f, 1.6f); glVertex3f(-1.8f, -3.0f, 1.6f);

	//back
	//;

	glTexCoord3f(-1.8f, -0.2f, 1.2f); glVertex3f(-1.8f, -0.2f, 1.2f);
	glTexCoord3f(-1.4f, -0.2f, 1.2f); glVertex3f(-1.4f, -0.2f, 1.2f);
	glTexCoord3f(-1.4f, -3.0f, 1.2f); glVertex3f(-1.4f, -3.0f, 1.2f);
	glTexCoord3f(-1.8f, -3.0f, 1.2f); glVertex3f(-1.8f, -3.0f, 1.2f);

	//right


	glTexCoord3f(-1.8f, -0.2f, 1.6f); glVertex3f(-1.8f, -0.2f, 1.6f);
	glTexCoord3f(-1.8f, -0.2f, 1.2f); glVertex3f(-1.8f, -0.2f, 1.2f);
	glTexCoord3f(-1.8f, -3.0f, 1.2f); glVertex3f(-1.8f, -3.0f, 1.2f);
	glTexCoord3f(-1.8f, -3.0f, 1.6f); glVertex3f(-1.8f, -3.0f, 1.6f);

	//left
	;

	glTexCoord3f(-1.4f, -0.2f, 1.6f); glVertex3f(-1.4f, -0.2f, 1.6f);
	glTexCoord3f(-1.4f, -0.2f, 1.2f); glVertex3f(-1.4f, -0.2f, 1.2f);
	glTexCoord3f(-1.4f, -3.0f, 1.2f); glVertex3f(-1.4f, -3.0f, 1.2f);
	glTexCoord3f(-1.4f, -3.0f, 1.6f); glVertex3f(-1.4f, -3.0f, 1.6f);

	//left leg back front

	//front
	;

	glTexCoord3f(-1.8f, -0.2f, -1.2f); glVertex3f(-1.8f, -0.2f, -1.2f);
	glTexCoord3f(-1.4f, -0.2f, -1.2f); glVertex3f(-1.4f, -0.2f, -1.2f);
	glTexCoord3f(-1.4f, -3.0f, -1.2f); glVertex3f(-1.4f, -3.0f, -1.2f);
	glTexCoord3f(-1.8f, -3.0f, -1.2f); glVertex3f(-1.8f, -3.0f, -1.2f);

	//back
	;

	glTexCoord3f(-1.8f, -0.2f, -1.6f); glVertex3f(-1.8f, -0.2f, -1.6f);
	glTexCoord3f(-1.4f, -0.2f, -1.6f); glVertex3f(-1.4f, -0.2f, -1.6f);
	glTexCoord3f(-1.4f, -3.0f, -1.6f); glVertex3f(-1.4f, -3.0f, -1.6f);
	glTexCoord3f(-1.8f, -3.0f, -1.6f); glVertex3f(-1.8f, -3.0f, -1.6f);

	//right


	glTexCoord3f(-1.8f, -0.2f, -1.6f); glVertex3f(-1.8f, -0.2f, -1.6f);
	glTexCoord3f(-1.8f, -0.2f, -1.2f); glVertex3f(-1.8f, -0.2f, -1.2f);
	glTexCoord3f(-1.8f, -3.0f, -1.2f); glVertex3f(-1.8f, -3.0f, -1.2f);
	glTexCoord3f(-1.8f, -3.0f, -1.6f); glVertex3f(-1.8f, -3.0f, -1.6f);

	//left

	glTexCoord3f(-1.4f, -0.2f, -1.6f); glVertex3f(-1.4f, -0.2f, -1.6f);
	glTexCoord3f(-1.4f, -0.2f, -1.2f); glVertex3f(-1.4f, -0.2f, -1.2f);
	glTexCoord3f(-1.4f, -3.0f, -1.2f); glVertex3f(-1.4f, -3.0f, -1.2f);
	glTexCoord3f(-1.4f, -3.0f, -1.6f); glVertex3f(-1.4f, -3.0f, -1.6f);
	

	

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

