//Circle drawing using theta reference
#include <stdio.h>
#include<math.h>
#include <GL/glut.h>
using namespace std;

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}
void circleDrawing_using_theta(float r, float xc, float yc)
{
    float theta, x, y;
    glBegin(GL_LINE_STRIP);
    for (theta = 0; theta <= 360; theta+=0.5)
    {
        x = r * cos(theta);
        y = r * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
    glFlush();
}
void display(void)
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(1);

    glColor3f(1, 0, 0);
    circleDrawing_using_theta(2, 0, 0);

    glColor3f(0, 1, 0);
    circleDrawing_using_theta(5, 0, 0);

    glColor3f(0, 0, 1);
    circleDrawing_using_theta(8, 0, 0);
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
