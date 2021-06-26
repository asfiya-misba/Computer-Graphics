//display sqaure when left button is pressed, middle button to referesh and right to exit the program
#include <stdio.h>
#include<math.h>
#include <GL/glut.h>
using namespace std;
int h = 500, w = 500;
float sz = 10;
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, h, 0, w);
    glMatrixMode(GL_MODELVIEW);
}
void display(void)
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);  
}
void drawsq(int x, int y)
{
    y = h-y;
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(x + sz, y + sz);
    glVertex2f(x - sz, y + sz);
    glVertex2f(x - sz, y - sz);
    glVertex2f(x + sz, y - sz);
    glEnd();
    glFlush();
}
void myMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        drawsq(x, y);
    if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
        glClear(GL_COLOR_BUFFER_BIT);
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        exit(0);

}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Mouse");
    myinit();
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);
    glutMainLoop();
}
