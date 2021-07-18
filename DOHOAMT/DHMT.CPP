#include <iostream>
#include <math.h>
#include <string.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/GLAUX.H>
#include "src/chair.h"
#include "src/table.h"
#include "src/cupboard.h"
#include "src/window.h"
#include "src/fan.h"
// 128x192
float WINDOW_WIDTH = 1000;
float WINDOW_HEIGHT = 1000;
float M_PI = 3.14159265358979323846;
using namespace std;

// angle of rotation for the camera direction
float angle = 0.0, yAngle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = -5.0f, z = 18.0f;
float roll = 0.0f;

//for mouse movements
float halfWidth = (float)(WINDOW_WIDTH / 2.0);
float halfHeight = (float)(WINDOW_HEIGHT / 2.0);
float mouseX = 0.0f, mouseY = 0.0f;

//Fan
Fan f;

//------------------------------------------------------------Load texture--------------------------------------------
GLuint texture;
GLuint chairTexture;
GLuint tableTexture;
GLuint tableTexture1;

GLuint texture1;
int LoadBitmap(char *filename)
{
	FILE* file;
	char temp;
	long i;

	BITMAPINFOHEADER infoheader;
	unsigned char* infoheader_data;

	GLuint num_texture;

	if ((file = fopen(filename, "rb")) == NULL) return (-1); // Open the file for reading

	fseek(file, 18, SEEK_CUR);  /* start reading width & height */
	fread(&infoheader.biWidth, sizeof(int), 1, file);

	fread(&infoheader.biHeight, sizeof(int), 1, file);

	fread(&infoheader.biPlanes, sizeof(short int), 1, file);
	if (infoheader.biPlanes != 1) {
		printf("Planes from %s is not 1: %u\n", filename, infoheader.biPlanes);
		return 0;
	}

	// read the bpp
	fread(&infoheader.biBitCount, sizeof(unsigned short int), 1, file);
	if (infoheader.biBitCount != 24) {
		printf("Bpp from %s is not 24: %d\n", filename, infoheader.biBitCount);
		return 0;
	}

	fseek(file, 24, SEEK_CUR);

	// read the data
	if (infoheader.biWidth < 0) {
		infoheader.biWidth = -infoheader.biWidth;
	}
	if (infoheader.biHeight < 0) {
		infoheader.biHeight = -infoheader.biHeight;
	}
	infoheader_data = (unsigned char*)malloc(infoheader.biWidth * infoheader.biHeight * 3);
	if (infoheader_data == NULL) {
		printf("Error allocating memory for color-corrected image data\n");
		return 0;
	}

	if ((i = fread(infoheader_data, infoheader.biWidth * infoheader.biHeight * 3, 1, file)) != 1) {
		printf("Error reading image data from %s.\n", filename);
		return 0;
	}

	for (i = 0; i < (infoheader.biWidth * infoheader.biHeight * 3); i += 3) { // reverse all of the colors. (bgr -> rgb)
		temp = infoheader_data[i];
		infoheader_data[i] = infoheader_data[i + 2];
		infoheader_data[i + 2] = temp;
	}


	fclose(file); // Closes the file stream

	glGenTextures(1, &num_texture);
	glBindTexture(GL_TEXTURE_2D, num_texture); // Bind the ID texture specified by the 2nd parameter

	// The next commands sets the texture parameters
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // If the u,v coordinates overflow the range 0,1 the image is repeated
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // The magnification function ("linear" produces better results)
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); //The minifying function

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	// Finally we define the 2d texture
	glTexImage2D(GL_TEXTURE_2D, 0, 3, infoheader.biWidth, infoheader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, infoheader_data);

	// And create 2d mipmaps for the minifying function
	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, infoheader.biWidth, infoheader.biHeight, GL_RGB, GL_UNSIGNED_BYTE, infoheader_data);

	free(infoheader_data); // Free the memory we used to load the texture

	return (num_texture); // Returns the current texture OpenGL ID
}
//-----------------------------------------------------------------------------------------------------------------------
void renderScene(void) {

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, 2.5f, z, x + lx, 2.5f + ly, z + lz, roll + 0.0f, 2.5f, 0.0f);

	;
	glDisable(GL_LIGHTING);
	// Draw floor
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0f, 0.0f, -10.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.0f, 0.0f, 10.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0f, 0.0f, 10.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	//wall
	glColor3f(0.9294f, 0.9216f, 0.8353f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();

	//wall
	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glEnd();

	//wall with door
	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-3.0f, 0.0f, 10.0f);
	glVertex3f(-3.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(-6.0f, 7.0f, 10.0f);
	glVertex3f(-6.0f, 5.0f, 10.0f);
	glVertex3f(-3.0f, 5.0f, 10.0f);
	glVertex3f(-3.0f, 7.0f, 10.0f);
	glEnd();

	glColor3f(0.4f, 0.2f, 0.0f);
	glLineWidth(30.0f);
	glBegin(GL_LINES);
	glVertex3f(-6.0f, 5.0f, 10.01f);
	glVertex3f(-3.0f, 5.0f, 10.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-6.0f, 5.0f, 10.01f);
	glVertex3f(-6.0f, 0.0f, 10.01f);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(-3.0f, 0.0f, 10.01f);
	glVertex3f(-3.0f, 5.0f, 10.01f);
	glEnd();


	//wall
	glColor3f(1.0f, 0.851f, 0.702f);
	glBegin(GL_QUADS);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glEnd();

	//ceiling
	glColor3f(0.95f, 0.95f, 0.95f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glEnd();

	// Draw prof's chair
	Chair profChair;
	glColor3f(1.0f, 0.851f, 0.702f);
	glPushMatrix();
	glTranslatef(6.0f, 1.0f, -9.0f);
	glScalef(0.32f, 0.32f, 0.32f);
	glRotatef(-30.0, 0.0, 1.0, 0.0);
	profChair.drawChair(chairTexture);
	glPopMatrix();

	// Draw prof's table
	Table profTable;
	glColor3f(1.0f, 0.851f, 0.702f);
	glPushMatrix();
	glTranslatef(6.0f, 1.4f, -7.6f);
	glScalef(0.5f, 0.5f, 0.5f);
	glRotatef(-30.0, 0.0, 1.0, 0.0);
	profTable.drawTable(tableTexture, tableTexture1);
	glPopMatrix();
	
	// Draw student chairs
	
	Chair studentChair[4][4];
	for (int i = -3; i <= 3; i += 2) {
		for (int j = -3; j <= 3; j += 2) {
			glPushMatrix();
			glTranslatef(i * 2.0, 0.8f, j * 2.0 + 2.2f);
			glScalef(0.25f, 0.25f, 0.25f);
			glRotatef(180.0, 0.0, 1.0, 0.0);
			studentChair[i][j].drawChair(chairTexture);
			glPopMatrix();
		}
	}

	
	// Draw student tables

	Table studentTable[4][4];
	for (int i = -3; i <= 3; i += 2) {
		for (int j = -3; j <= 3; j += 2) {
			glPushMatrix();
			glTranslatef(i * 2.0 + 0.3f, 1.2f, j * 2.0 + 1.2f);
			glScalef(0.4f, 0.4f, 0.4f);
			// glRotatef(180.0, 0.0, 1.0, 0.0);
			studentTable[i][j].drawTable(tableTexture, tableTexture1);
			glPopMatrix();
		}
	}
	
	// Draw cupboard
	Cupboard cupboard;
	glPushMatrix();
	glTranslatef(8.49f, 0.0f, -3.5f);
	glRotatef(-90.0, 0.0, 1.0, 0.0);
	cupboard.drawCupboard(tableTexture);
	glPopMatrix();

	// Draw blackboard
	glColor3f(0.4f, 0.2f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-6.0f, 2.0f, -9.99f);
	glVertex3f(-6.0f, 5.5f, -9.99f);
	glVertex3f(6.0f, 5.5f, -9.99f);
	glVertex3f(6.0f, 2.0f, -9.99f);
	glEnd();

	glColor3f(0.149f, 0.149f, 0.149f);
	glBegin(GL_QUADS);
	glVertex3f(-5.8f, 2.2f, -9.98f);
	glVertex3f(-5.8f, 5.3f, -9.98f);
	glVertex3f(5.8f, 5.3f, -9.98f);
	glVertex3f(5.8f, 2.2f, -9.98f);
	glEnd();

	//---------------------------------------Ảnh Bác Hồ------------------------------
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(0.0f, 5.6f, -9.97f);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	//glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
	
	glTexCoord2f(0.0, 0.0); glVertex3f(0.0, 0.0, 0.0);
	glTexCoord2f(1, 0.0); glVertex3f(1.0, 0.0, 0.0);
	glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
	glTexCoord2f(0.0, 1.0); glVertex3f(0.0, 1.0, 0.0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	

	// 	   -------------------------------
	//Floor pattern
	glColor3f(0.149f, 0.149f, 0.149f);
	/*glLineWidth(3.0f);
	for (int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f + i, 0.001f, -10.01f);
		glVertex3f(-10.0f + i, 0.001f, 10.01f);
		glEnd();
	}
	for (int i = 0; i < 20; i += 2)
	{
		glBegin(GL_LINES);
		glVertex3f(-10.0f, 0.001f, -10.01f + i);
		glVertex3f(10.0f, 0.001f, -10.01f + i);
		glEnd();
	}*/

	//windows

	Window w;
	w.drawWindow1();
	w.drawWindow2();
	w.drawWindowSill();
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, 8.0f);
	w.drawWindowSill();
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(0.0f, 6.0f, 0.0);
	glScalef(0.3f, 0.3f, 0.3f);
	f.drawFan();
	glPopMatrix();
	
	glEnable(GL_LIGHTING);
	glutSwapBuffers();
}

// Handles the events triggered when one of the arrow keys are pressed.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		x += sin(angle - M_PI / 2.0) * fraction;
		z += -cos(angle - M_PI / 2.0) * fraction;
		break;
	case GLUT_KEY_RIGHT:
		x += sin(M_PI / 2.0 + angle) * fraction;
		z += -cos(M_PI / 2.0 + angle) * fraction;
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}


// Handles the events triggered when any key on the keyboard is pressed.
//Specifically, handles w,a,s,d and Esc.
// moves the camera frward, backward and sideways.
// @param key : key pressed
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processNormalKeys(unsigned char key, int xx, int yy) {
	float fraction = 0.1f;
	if (key == 'w') {
		x += lx * fraction;
		z += lz * fraction;
	}
	else if (key == 'a') {
		x += sin(angle - M_PI / 2.0) * fraction;
		z += -cos(angle - M_PI / 2.0) * fraction;
	}
	else if (key == 's') {
		x -= lx * fraction;
		z -= lz * fraction;
	}
	else if (key == 'd') {
		x += sin(M_PI / 2.0 + angle) * fraction;
		z += -cos(M_PI / 2.0 + angle) * fraction;
	}
	else if (key == 'x') {
		roll += 0.5f;
	}
	else if (key == 'z') {
		roll -= 0.5f;
	}

	if (key == 27)
		exit(0);
}

// Handles the events triggered when the mouse is moved in the window area. 
// Handles yaw and pitch of the camera.
// @param xx : x coordinate of mouse position
// @param yy : y coordinate of mouse position
void processMouseMovement(int xx, int yy) {

	mouseX = (float)(halfWidth - xx) / halfWidth;
	mouseY = (float)(halfHeight - yy) / halfHeight;
	angle -= (0.005f * mouseX);
	lx = sin(angle);
	lz = -cos(angle);

	if (abs(yAngle) < (M_PI / 2)) {
		yAngle += (0.005f * mouseY);
	}
	ly = sin(yAngle);

}

// Adjusts the viewport sie when the window size is changed and sets the projection.
// @param w : new width of window
// @param h : new height of window
void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	halfWidth = (float)(w / 2.0);
	halfHeight = (float)(h / 2.0);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void animate() {

	f.rotateFan();

	/* refresh screen */
	glutPostRedisplay();
}

void Init(void)
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	
	//---------------------------------------------

	texture = LoadBitmap("anhbac.bmp"); //load the texture for image Bac Ho
	chairTexture = LoadBitmap("vango2.bmp");
	tableTexture = LoadBitmap("vango.bmp");
	tableTexture1 = LoadBitmap("vango.bmp");
	texture1 = LoadBitmap("gach2.bmp");
	//-----------------------------------------------

	GLfloat light_pos[] = { 1.0f, 1.0f, 0.0f, 0.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

	GLfloat ambient[] = { 1.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);

	GLfloat diff_use[] = { 0.0, 0.5, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);

	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);

	GLfloat shininess = 50.0f;
	glMateriali(GL_FRONT, GL_SHININESS, shininess);
}
int main(int argc, char** argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Classroom");
	Init();
	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(animate);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
	glutPassiveMotionFunc(processMouseMovement);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}


