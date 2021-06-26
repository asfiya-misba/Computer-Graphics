//Circle drawing using pythagoras theorem
#include <stdio.h>
#include<math.h>
#include <GL/glut.h>
using namespace std;

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 50, 0, 50);
    glMatrixMode(GL_MODELVIEW);
}
void setPixel(float x, float y)
{
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}
void circ(float r, float xc, float yc)
{
    float x, y;
    for (x = -r; x <= r; x++)
    {
        y = sqrt(pow(r, 2) - pow(x, 2));
        setPixel(x + xc, y + yc);
        setPixel(x + xc, -y + yc);
    }
}
void display(void)
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    circ(10, 25, 25);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
}










