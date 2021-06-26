#include <stdio.h>
#include <GL/glut.h>
using namespace std;

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 30, -15, 30);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(10);

    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(-5, -5);
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(GL_POINTS);
    glVertex2f(5, 5);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_POINTS);
    glVertex2f(15, 15);
    glEnd();

    glLineWidth(5);

    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(-3, 5);
    glVertex2f(-3, 26);
    glEnd();

    glColor3f(0, 0, 1);
    glBegin(GL_LINES);
    glVertex2f(-3, 26);
    glVertex2f(18, 26);
    glEnd();

    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-3, 5);
    glVertex2f(18, 26);
    glEnd();

    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Lines & Points");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}