#include <stdio.h>
#include <GL/glut.h>
using namespace std;

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 50, 0, 50);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);

    //left leg
    glBegin(GL_LINE_LOOP);
    glVertex2f(10, 7);
    glVertex2f(13, 7);
    glVertex2f(13, 15);
    glVertex2f(10, 15);
    glEnd();

    //right leg
    glBegin(GL_LINE_LOOP);
    glVertex2f(22, 7);
    glVertex2f(25, 7);
    glVertex2f(25, 15);
    glVertex2f(22, 15);
    glEnd();

    //body
    glBegin(GL_LINE_LOOP);
    glVertex2f(10, 15);
    glVertex2f(25, 15);
    glVertex2f(25, 30); 
    glVertex2f(10, 30);
    glEnd();

    //left hand
    glBegin(GL_LINE_LOOP);
    glVertex2f(5, 28);
    glVertex2f(10, 28);
    glVertex2f(10, 30);
    glVertex2f(5, 30);
    glEnd();

    //right hand
    glBegin(GL_LINE_LOOP);
    glVertex2f(25, 28);
    glVertex2f(30, 28);
    glVertex2f(30, 30);
    glVertex2f(25, 30);
    glEnd();


    //neck
    glBegin(GL_LINE_LOOP);
    glVertex2f(17, 30);
    glVertex2f(18, 30);
    glVertex2f(18, 32);
    glVertex2f(17, 32);
    glEnd();

    //head
    glBegin(GL_LINE_LOOP);
    glVertex2f(15, 32);
    glVertex2f(20, 32);
    glVertex2f(20, 37);
    glVertex2f(15, 37);
    glEnd();

    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Robot");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
