
#include "Image.h"



void Image::drawImage()
{
    glPushMatrix();// vẽ hình vuông trên cùng của quạt
    glColor3f(1, 0, 0);
    glScalef(1, 1.2, 1);
    glScalef(.5, .4, .5);
    glTranslatef(0, -2.0, 0);
    glScalef(1.0f, 0.7f, 1.0f);
    glTranslatef(0, -0.5, 0);
    glutSolidCube(1);
    glPopMatrix();

    
}
