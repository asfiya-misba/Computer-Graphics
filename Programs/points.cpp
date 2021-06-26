//Display points with different color and point size
#include<stdio.h>
#include<GL/glut.h>
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

	glColor3f(1, 0, 0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(10, 10);
	glEnd();

	glColor3f(0, 1, 0);
	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex2i(20, 35);
	glEnd();


	glColor3f(0, 0, 1);
	glPointSize(30);
	glBegin(GL_POINTS);
	glVertex2i(12, 18);
	glEnd();

	glColor3f(0.5, 0.2, 0.8);
	glPointSize(40);
	glBegin(GL_POINTS);
	glVertex2i(40, 38);
	glEnd();

	glFlush();

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Points");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}



