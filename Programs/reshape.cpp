#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<GL/glut.h>
int xmin = -10, xmax = 10, ymin = -10, ymax = 10;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xmin, xmax, ymin, ymax);
	glMatrixMode(GL_MODELVIEW);
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w > h)
		gluOrtho2D(xmin * (float)w / (float)h, xmax * (float)w / (float)h, ymin, ymax);
	else
		gluOrtho2D(xmin, xmax, ymin * (float)h / (float)w, ymax * (float)h / (float)w);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-3, 1);
	glVertex2f(-2, 4);
	glVertex2f(-1, 1);
	glVertex2f(2, 1);
	glVertex2f(0, -1);
	glVertex2f(1, -4);
	glVertex2f(-2, -2);
	glVertex2f(-5, -4);
	glVertex2f(-4, -1);
	glVertex2f(-6, 1);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(6, 0);
	glVertex2f(5, 3);
	glVertex2f(6, 3);
	glVertex2f(7, 0);
	glVertex2f(6, -3);
	glVertex2f(5, -3);
	glEnd();
	glFlush();
}
int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutInit(&argc, argv);
	glutCreateWindow("Reshape");
	myinit();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
