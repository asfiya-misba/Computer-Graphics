#include<stdio.h>
#include<GL/GLUT.h>
#include<math.h>
int xmin = -200, xmax = 200, ymin = -200, ymax = 200, n = 60;
float theta = 0;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xmin, xmax, ymin, ymax);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.86, 0.7, 0.93);
	glBegin(GL_POLYGON);
	glVertex2f(75 * cos(theta), 75 * sin(theta));
	glVertex2f(-75 * sin(theta), 75 * cos(theta));
	glVertex2f(-75 * cos(theta), -75 * sin(theta));
	glVertex2f(75 * sin(theta), -75 * cos(theta));
	glEnd();
	glutSwapBuffers();
	glFlush();
}
void idle()
{
	theta++;
	if (theta >= 360)
		theta -= 360;
	glutPostRedisplay();
}
void myTimer(int v)
{
	theta++;
	if (theta >= 360)
		theta -= 360;
	glutPostRedisplay();
	glutTimerFunc(10, myTimer, v);
}
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		//glutTimerFunc(10, myTimer, n);
		glutIdleFunc(idle);
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		glutIdleFunc(NULL);
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
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Rotate a Square");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutMainLoop();
}