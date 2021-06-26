#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
int ww = 500, wh = 500, siz = 10, xm, ym, xmm, ymm, first, object = 0;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, ww, 0, wh);
	glMatrixMode(GL_MODELVIEW);
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(5);
}
void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		xm = x;
		ym = wh - y;
		glColor3f(0, 0, 1);
		first = 0;
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		glLogicOp(GL_XOR);
		if (object == 0)
			glRectf(xm, ym, xmm, ymm);
		else
		{
			glBegin(GL_LINES);
			glVertex2f(xm, ym);
			glVertex2f(xmm, ymm);
			glEnd();
		}
		glLogicOp(GL_COPY);
		glColor3f(0.54, 0.6, 0.99);
		xmm = x;
		ymm = wh - y;
		glLogicOp(GL_COPY);
		if (object == 0)
			glRectf(xm, ym, xmm, ymm);
		else
		{
			glBegin(GL_LINES);
			glVertex2f(xm, ym);
			glVertex2f(xmm, ymm);
			glEnd();
		}
		glFlush();
		first = 0;
	}
	glutPostRedisplay();
}
void move(int x, int y)
{
	if (first == 1)
	{
		if (object == 0)
			glRectf(xm, ym, xmm, ymm);
		else
		{
			glBegin(GL_LINES);
			glVertex2f(xm, ym);
			glVertex2f(xmm, ymm);
			glEnd();
		}
	}
	xmm = x;
	ymm = wh - y;
	glLogicOp(GL_XOR);
	if (object == 0)
		glRectf(xm, ym, xmm, ymm);
	else
	{
		glBegin(GL_LINES);
		glVertex2f(xm, ym);
		glVertex2f(xmm, ymm);
		glEnd();
	}
	glFlush();
	first = 1;
}
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'r' || key == 'R')
		object = 0;
	if (key == 'L' || key == 'l')
		object = 1;
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(ww, wh);
	glutCreateWindow("Rubber Band Technique");
	myinit();
	glEnable(GL_COLOR_LOGIC_OP);
	glutDisplayFunc(display);
	glutMotionFunc(move);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}