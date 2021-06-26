//Circle drawing using 8 way symmetry
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
void setPixel(float x, float y)
{
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}
void eight_way_sym(float x, float y)
{
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glVertex2f(y, x);
    glVertex2f(-x, y);
    glVertex2f(-y, x);
    glVertex2f(-x, -y);
    glVertex2f(-y, -x);
    glVertex2f(x, -y);
    glVertex2f(y, -x);
    glEnd();
    glFlush();
}
void circledrawing_using_theta_eightway(float r, float xc, float yc)
{
    float theta, x, y;
    glColor3f(1, 0, 0);
    for (theta = 0; theta < 45; theta++)
    {
        x = r * cos(theta);
        y = r * sin(theta);
        eight_way_sym(x, y);
    }
    glEnd();
}
void display(void)
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    circledrawing_using_theta_eightway(5, 0, 0);
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

