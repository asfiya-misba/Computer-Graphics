//House using lines
#include <stdio.h>
#include <GL/glut.h>
using namespace std;

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 60, 0, 25);
	glMatrixMode(GL_MODELVIEW);
}
void display(void)
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	glColor3f(0, 0, 0);

	glBegin(GL_LINE_LOOP);
	glVertex2i(5, 5);
	glVertex2i(20, 5);
	glVertex2i(20, 10);
	glVertex2i(5, 10);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glVertex2i(20, 5);
	glVertex2i(35, 5);
	glVertex2i(35, 10);
	glVertex2i(20, 10);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(5, 10);
	glVertex2i(20, 10);
	glVertex2i(13, 15);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2i(20, 10);
	glVertex2i(35, 10);
	glVertex2i(30, 15);
	glVertex2i(13, 15);
	glEnd();


	glBegin(GL_LINE_LOOP);
	glVertex2i(10, 5);
	glVertex2i(15, 5);
	glVertex2i(15, 8);
	glVertex2i(10, 8);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(25, 6.5);
	glVertex2f(30, 6.5);
	glVertex2f(30, 8.5);
	glVertex2f(25, 8.5);
	glEnd();

	glFlush();
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("House");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}