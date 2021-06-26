#include<stdio.h>
#include<gl/GLUT.h>
#include<math.h>
int xmin = -50, xmax = 50, ymin = -50, ymax = 50;
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
void display2()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	glVertex2f(10, 10);
	glVertex2f(10, -10);
	glVertex2f(-10, -10);
	glVertex2f(-10, 10);
	glEnd();
	glFlush();
}
void display1()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 1);
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, 0);
	for (int theta = 0; theta <= 360; theta++)
		glVertex2f(10 * cos(theta), 10 * sin(theta));
	glEnd();
	glFlush();
}
void main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutInit(&argc, argv);
	glutCreateWindow("First Window");
	myinit();
	glutDisplayFunc(display1);
	glutReshapeFunc(reshape);
	glutInitWindowPosition(600, 0);
	glutCreateWindow("Second Window");
	myinit();
	glutDisplayFunc(display2);
	glutReshapeFunc(reshape);
	glutMainLoop();
}