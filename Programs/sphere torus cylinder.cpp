#include<stdio.h>
#include<GL/glut.h>
using namespace std;
void myInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    //glutSolidSphere(0.4, 20.0, 10.0);
    //glutWireTorus(0.2, 0.4, 10, 20);
    glutSolidTorus(0.2, 0.4, 10, 20);
    glFlush();
}

void main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Sphere, Torus, Cylinder");
    glutDisplayFunc(display);
    myInit();
    glutMainLoop();
}