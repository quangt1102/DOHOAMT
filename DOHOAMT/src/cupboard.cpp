#include "cupboard.h"

void Cupboard::drawCupboard(GLuint textTure) {

	glColor3f(1.0f, 1.0f, 0.302f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textTure);
	glBegin(GL_QUADS);

	// Back
	//glTexCoord3f
	glTexCoord3f(-1.5f, 0.5f, -1.5f);
	glVertex3f(-1.5f, 0.5f, -1.5f);
	glTexCoord3f(-1.5f, 4.5f, -1.5f);
	glVertex3f(-1.5f, 4.5f, -1.5f);
	glTexCoord3f(1.5, 4.5f, -1.5f);
	glVertex3f(1.5, 4.5f, -1.5f);
	glTexCoord3f(1.5f, 0.5f, -1.5f);
	glVertex3f(1.5f, 0.5f, -1.5f);

	// Left Side
	glColor3f(1.0f, 0.8f, 0.6f);
	glTexCoord3f(0.0f, 0.0f, -1.5f);glVertex3f(-1.5f, 0.5f, -1.5f);
	glTexCoord3f(1.0f, 0.0f, -1.5f);glVertex3f(-1.5f, 4.5f, -1.5f);
	glTexCoord3f(1.0f, 1.0f, 0.5f);glVertex3f(-1.5, 4.5f, 0.5f);
	glTexCoord3f(0.0f, 1.0f, 0.5f);glVertex3f(-1.5f, 0.5f, 0.5f);

	// Right Side + texture

	glTexCoord3f(0.0f, 0.0f, -1.5f);glVertex3f(1.5f, 0.5f, -1.5f);
	glTexCoord3f(1.0f, 0.0f, -1.5f);glVertex3f(1.5f, 4.5f, -1.5f);
	glTexCoord3f(1.0, 1.0f, 0.5f);glVertex3f(1.5, 4.5f, 0.5f);
	glTexCoord3f(0.0f, 1.0f, 0.5f);glVertex3f(1.5f, 0.5f, 0.5f);

	// Front
	glColor3f(1.0f, 1.0f, 0.302f);
	glTexCoord3f(-1.5f, 0.5f, 0.5f);
	glVertex3f(-1.5f, 0.5f, 0.5f);
	glTexCoord3f(-1.5f, 4.5f, 0.5f);
	glVertex3f(-1.5f, 4.5f, 0.5f);
	glTexCoord3f(1.5, 4.5f, 0.5f);
	glVertex3f(1.5, 4.5f, 0.5f);
	glTexCoord3f(1.5f, 0.5f, 0.5f);
	glVertex3f(1.5f, 0.5f, 0.5f);

	glColor3f(0.2f, 0.0f, 0.2f);
	// Left Support
	glTexCoord3f(-1.5f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.0f, -1.5f);
	glTexCoord3f(-1.5f, 0.5f, -1.5f);
	glVertex3f(-1.5f, 0.5f, -1.5f);
	glTexCoord3f(-1.2, 0.5f, -1.5f);
	glVertex3f(-1.2, 0.5f, -1.5f);
	glTexCoord3f(-1.2f, 0.0f, -1.5f);
	glVertex3f(-1.2f, 0.0f, -1.5f);

	glTexCoord3f(-1.5f, 0.0f, -1.5f);
	glVertex3f(-1.5f, 0.0f, -1.5f);
	glTexCoord3f(-1.5f, 0.5f, -1.5f);
	glVertex3f(-1.5f, 0.5f, -1.5f);
	glTexCoord3f(-1.5, 0.5f, 0.5f);
	glVertex3f(-1.5, 0.5f, 0.5f);
	glTexCoord3f(-1.5f, 0.0f, 0.5f);
	glVertex3f(-1.5f, 0.0f, 0.5f);

	glTexCoord3f(-1.2f, 0.0f, -1.5f);
	glVertex3f(-1.2f, 0.0f, -1.5f);
	glTexCoord3f(-1.2f, 0.5f, -1.5f);
	glVertex3f(-1.2f, 0.5f, -1.5f);
	glTexCoord3f(-1.2, 0.5f, 0.5f);
	glVertex3f(-1.2, 0.5f, 0.5f);
	glTexCoord3f(-1.2f, 0.0f, 0.5f);
	glVertex3f(-1.2f, 0.0f, 0.5f);

	glTexCoord3f(-1.5f, 0.0f, 0.5f);
	glVertex3f(-1.5f, 0.0f, 0.5f);
	glTexCoord3f(-1.5f, 0.5f, 0.5f);
	glVertex3f(-1.5f, 0.5f, 0.5f);
	glTexCoord3f(-1.2, 0.5f, 0.5f);
	glVertex3f(-1.2, 0.5f, 0.5f);
	glTexCoord3f(-1.2f, 0.0f, 0.5f);
	glVertex3f(-1.2f, 0.0f, 0.5f);

	// Right Support
	glTexCoord3f(1.5f, 0.0f, -1.5f);
	glVertex3f(1.5f, 0.0f, -1.5f);
	glTexCoord3f(1.5f, 0.5f, -1.5f);
	glVertex3f(1.5f, 0.5f, -1.5f);
	glTexCoord3f(1.2f, 0.5f, -1.5f);
	glVertex3f(1.2f, 0.5f, -1.5f);
	glTexCoord3f(1.2f, 0.0f, -1.5f);
	glVertex3f(1.2f, 0.0f, -1.5f);

	glTexCoord3f(1.5f, 0.0f, -1.5f);
	glVertex3f(1.5f, 0.0f, -1.5f);
	glTexCoord3f(1.5f, 0.5f, -1.5f);
	glVertex3f(1.5f, 0.5f, -1.5f);
	glTexCoord3f(1.5f, 0.5f, 0.5f);
	glVertex3f(1.5f, 0.5f, 0.5f);
	glTexCoord3f(1.5f, 0.0f, 0.5f);
	glVertex3f(1.5f, 0.0f, 0.5f);

	glTexCoord3f(1.2f, 0.0f, -1.5f);
	glVertex3f(1.2f, 0.0f, -1.5f);
	glTexCoord3f(1.2f, 0.5f, -1.5f);
	glVertex3f(1.2f, 0.5f, -1.5f);
	glTexCoord3f(1.2f, 0.5f, 0.5f);
	glVertex3f(1.2f, 0.5f, 0.5f);
	glTexCoord3f(1.2f, 0.0f, 0.5f);
	glVertex3f(1.2f, 0.0f, 0.5f);

	glTexCoord3f(1.5f, 0.0f, 0.5f);
	glVertex3f(1.5f, 0.0f, 0.5f);
	glTexCoord3f(1.5f, 0.5f, 0.5f);
	glVertex3f(1.5f, 0.5f, 0.5f);
	glTexCoord3f(1.2f, 0.5f, 0.5f);
	glVertex3f(1.2f, 0.5f, 0.5f);
	glTexCoord3f(1.2f, 0.0f, 0.5f);
	glVertex3f(1.2f, 0.0f, 0.5f);

	glEnd();

	//lines
	glColor3f(0.149f, 0.149f, 0.149f);
	glLineWidth(5.0f);
	glBegin(GL_LINES);

	glVertex3f(-1.4f, 0.6f, 0.501f);
	glVertex3f(-1.4f, 4.4f, 0.501f);

	glVertex3f(-1.4f, 4.4f, 0.501f);
	glVertex3f(1.4f, 4.4f, 0.501f);

	glVertex3f(1.4f, 0.6f, 0.501f);
	glVertex3f(1.4f, 4.4f, 0.501f);

	glVertex3f(-1.4f, 0.6f, 0.501f);
	glVertex3f(1.4f, 0.6f, 0.501f);

	//middle line
	glVertex3f(0.0f, 0.6f, 0.501f);
	glVertex3f(0.0f, 4.4f, 0.501f);

	glEnd();
	glDisable(GL_TEXTURE_2D);

	// Handles
	glColor3f(0.5f, 0.5f, 0.5f);
	glPushMatrix();
	glTranslatef(0.1f, 2.5f, 0.5f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glutSolidTorus(0.03f, 0.1f, 100, 100);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.1f, 2.5f, 0.5f);
	glRotatef(90.0, 0.0, 1.0, 0.0);
	glutSolidTorus(0.03f, 0.1f, 100, 100);
	glPopMatrix();
}

