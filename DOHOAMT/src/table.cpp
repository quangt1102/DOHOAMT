# include "table.h"
#include <iostream>
void Table::drawTable(GLuint tableTexture, GLuint tableTexture1) {

	// glTranslatef(0.0f, 0.0f, -14.0f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, tableTexture);
	glBegin(GL_QUADS);

	//Front
	//
	glColor3f(1.0f, 0.851f, 0.702f);
	glTexCoord2f(-4.0, -0.2); glVertex3f(-4.0f, -0.2f, 2.0f);
	glTexCoord2f(2.0f, -0.2f); glVertex3f(2.0f, -0.2f, 2.0f);
	glTexCoord2f(2.0f, 0.2f); glVertex3f(2.0f, 0.2f, 2.0f);
	glTexCoord2f(-4.0f, 0.2f); glVertex3f(-4.0f, 0.2f, 2.0f);

	//Back
	//;
	glTexCoord2f(-4.0f, -0.2f); glVertex3f(-4.0f, -0.2f, -2.0f);
	glTexCoord2f(-4.0f, 0.2f); glVertex3f(-4.0f, 0.2f, -2.0f);
	glTexCoord2f(2.0f, 0.2f); glVertex3f(2.0f, 0.2f, -2.0f);
	glTexCoord2f(2.0f, -0.2f); glVertex3f(2.0f, -0.2f, -2.0f);

	//Right
	//
	glTexCoord2f(2.0f, -0.2f); glVertex3f(2.0f, -0.2f, -2.0f);
	glTexCoord2f(2.0f, 0.2f); glVertex3f(2.0f, 0.2f, -2.0f);
	glTexCoord2f(2.0f, 0.2f); glVertex3f(2.0f, 0.2f, 2.0f);
	glTexCoord2f(2.0f, -0.2f); glVertex3f(2.0f, -0.2f, 2.0f);


	//Left
	;
	glTexCoord2f(-4.0f, -0.2f); glVertex3f(-4.0f, -0.2f, -2.0f);
	glTexCoord2f(-4.0f, -0.2f); glVertex3f(-4.0f, -0.2f, 2.0f);
	glTexCoord2f(-4.0f, 0.2f); glVertex3f(-4.0f, 0.2f, 2.0f);
	glTexCoord2f(-4.0f, 0.2f); glVertex3f(-4.0f, 0.2f, -2.0f);

	//top
	//
	//glScalef(0, -0.5, 0);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f, 0.2f, 2.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-4.0f, 0.2f, 2.0f);
	glTexCoord2f(1.0f, 1.02f); glVertex3f(-4.0f, 0.2f, -2.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f, 0.2f, -2.0f);

	//bottom
	;

	glVertex3f(2.0f, -0.2f, 2.0f);
	glVertex3f(-4.0f, -0.2f, 2.0f);
	glVertex3f(-4.0f, -0.2f, -2.0f);
	glVertex3f(2.0f, -0.2f, -2.0f);

	//table front leg
	//front
	//
	glColor3f(.8f, .6f, 0.0f);
	glTexCoord2f(1.8f, -0.2f); glVertex3f(1.8f, -0.2f, 1.6f);
	glTexCoord2f(1.4f, -0.2f); glVertex3f(1.4f, -0.2f, 1.6f);
	glTexCoord2f(1.4f, -3.0f); glVertex3f(1.4f, -3.0f, 1.6f);
	glTexCoord2f(1.8f, -3.0f); glVertex3f(1.8f, -3.0f, 1.6f);

	//back
	//;

	glTexCoord2f(1.8f, -0.2f); glVertex3f(1.8f, -0.2f, 1.2f);
	glTexCoord2f(1.4f, -0.2f); glVertex3f(1.4f, -0.2f, 1.2f);
	glTexCoord2f(1.4f, -3.0f); glVertex3f(1.4f, -3.0f, 1.2f);
	glTexCoord2f(1.8f, -3.0f); glVertex3f(1.8f, -3.0f, 1.2f);

	//right
	//

	glTexCoord2f(1.8f, -0.2f); glVertex3f(1.8f, -0.2f, 1.6f);
	glTexCoord2f(1.8f, -0.2f); glVertex3f(1.8f, -0.2f, 1.2f);
	glTexCoord2f(1.8f, -3.0f); glVertex3f(1.8f, -3.0f, 1.2f);
	glTexCoord2f(1.8f, -3.0f); glVertex3f(1.8f, -3.0f, 1.6f);

	//left
	//;

	glTexCoord2f(1.4f, -0.2f); glVertex3f(1.4f, -0.2f, 1.6f);
	glTexCoord2f(1.4f, -0.2f); glVertex3f(1.4f, -0.2f, 1.2f);
	glTexCoord2f(1.4f, -3.0f); glVertex3f(1.4f, -3.0f, 1.2f);
	glTexCoord2f(1.4f, -3.0f); glVertex3f(1.4f, -3.0f, 1.6f);

	//back leg back
	//front
	//;
	glTexCoord2f(1.8f, -0.2f); glVertex3f(1.8f, -0.2f, -1.2f);
	glTexCoord2f(1.4f, -0.2f); glVertex3f(1.4f, -0.2f, -1.2f);
	glTexCoord2f(1.4f, -3.0f); glVertex3f(1.4f, -3.0f, -1.2f);
	glTexCoord2f(1.8f, -3.0f); glVertex3f(1.8f, -3.0f, -1.2f);

	//back
	//;

	glTexCoord2f(1.8f, -0.2f); glVertex3f(1.8f, -0.2f, -1.6f);
	glTexCoord2f(1.4f, -0.2f); glVertex3f(1.4f, -0.2f, -1.6f);
	glTexCoord2f(1.4f, -3.0f); glVertex3f(1.4f, -3.0f, -1.6f);
	glTexCoord2f(1.8f, -3.0f); glVertex3f(1.8f, -3.0f, -1.6f);

	//right
	//

	glTexCoord2f(1.8f, -0.2f); glVertex3f(1.8f, -0.2f, -1.6f);
	glTexCoord2f(1.8f, -0.2f); glVertex3f(1.8f, -0.2f, -1.2f);
	glTexCoord2f(1.8f, -3.0f); glVertex3f(1.8f, -3.0f, -1.2f);
	glTexCoord2f(1.8f, -3.0f); glVertex3f(1.8f, -3.0f, -1.6f);

	//left
	//

	glTexCoord2f(1.4f, -0.2f); glVertex3f(1.4f, -0.2f, -1.6f);
	glTexCoord2f(1.4f, -0.2f); glVertex3f(1.4f, -0.2f, -1.2f);
	glTexCoord2f(1.4f, -3.0f); glVertex3f(1.4f, -3.0f, -1.2f);
	glTexCoord2f(1.4f, -3.0f); glVertex3f(1.4f, -3.0f, -1.6f);

	//leg left front
	//


	glTexCoord2f(-3.8f, -0.2f); glVertex3f(-3.8f, -0.2f, 1.6f);
	glTexCoord2f(-3.4f, -0.2f); glVertex3f(-3.4f, -0.2f, 1.6f);
	glTexCoord2f(-3.4f, -3.0f); glVertex3f(-3.4f, -3.0f, 1.6f);
	glTexCoord2f(-3.8f, -3.0f); glVertex3f(-3.8f, -3.0f, 1.6f);

	//back
	//;

	glTexCoord2f(-3.8f, -0.2f); glVertex3f(-3.8f, -0.2f, 1.2f);
	glTexCoord2f(-3.4f, -0.2f); glVertex3f(-3.4f, -0.2f, 1.2f);
	glTexCoord2f(-3.4f, -3.0f); glVertex3f(-3.4f, -3.0f, 1.2f);
	glTexCoord2f(-3.8f, -3.0f); glVertex3f(-3.8f, -3.0f, 1.2f);

	//right


	glTexCoord2f(-3.8f, -0.2f); glVertex3f(-3.8f, -0.2f, 1.6f);
	glTexCoord2f(-3.8f, -0.2f); glVertex3f(-3.8f, -0.2f, 1.2f);
	glTexCoord2f(-3.8f, -3.0f); glVertex3f(-3.8f, -3.0f, 1.2f);
	glTexCoord2f(-3.8f, -3.0f); glVertex3f(-3.8f, -3.0f, 1.6f);

	//left
	;

	glTexCoord2f(-3.4f, -0.2f); glVertex3f(-3.4f, -0.2f, 1.6f);
	glTexCoord2f(-3.4f, -0.2f); glVertex3f(-3.4f, -0.2f, 1.2f);
	glTexCoord2f(-3.4f, -3.0f); glVertex3f(-3.4f, -3.0f, 1.2f);
	glTexCoord2f(-3.4f, -3.0f); glVertex3f(-3.4f, -3.0f, 1.6f);

	//left leg back front

	//front
	;
	//glColor3f(1,1,1);
	glTexCoord2f(-3.8f, -0.2f); glVertex3f(-3.8f, -0.2f, -1.2f);
	glTexCoord2f(-3.4f, -0.2f); glVertex3f(-3.4f, -0.2f, -1.2f);
	glTexCoord2f(-3.4f, -3.0f); glVertex3f(-3.4f, -3.0f, -1.2f);
	glTexCoord2f(-3.8f, -3.0f); glVertex3f(-3.8f, -3.0f, -1.2f);

	//back
	;

	glTexCoord2f(-3.8f, -0.2f); glVertex3f(-3.8f, -0.2f, -1.6f);
	glTexCoord2f(-3.4f, -0.2f); glVertex3f(-3.4f, -0.2f, -1.6f);
	glTexCoord2f(-3.4f, -3.0f); glVertex3f(-3.4f, -3.0f, -1.6f);
	glTexCoord2f(-3.8f, -3.0f); glVertex3f(-3.8f, -3.0f, -1.6f);

	//right


	glTexCoord2f(-3.8f, -0.2f); glVertex3f(-3.8f, -0.2f, -1.6f);
	glTexCoord2f(-3.8f, -0.2f); glVertex3f(-3.8f, -0.2f, -1.2f);
	glTexCoord2f(-3.8f, -3.0f); glVertex3f(-3.8f, -3.0f, -1.2f);
	glTexCoord2f(-3.8f, -3.0f); glVertex3f(-3.8f, -3.0f, -1.6f);

	//left


	glVertex3f(-3.4f, -0.2f, -1.6f);
	glVertex3f(-3.4f, -0.2f, -1.2f);
	glVertex3f(-3.4f, -3.0f, -1.2f);
	glVertex3f(-3.4f, -3.0f, -1.6f);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}
