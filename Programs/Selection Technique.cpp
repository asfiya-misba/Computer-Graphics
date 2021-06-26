#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
int xmin = -200, xmax = 200, ymin = -200, ymax = 200;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xmin, xmax, ymin, ymax);
	glMatrixMode(GL_MODELVIEW);
}
void reshapeFunc(int w, int h)
{
	glViewport(0, 0, w, h);
	if (w > h)
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xmin * w / h, xmax * w / h, ymin, ymax);
		glMatrixMode(GL_MODELVIEW);
	}
	else
	{
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluOrtho2D(xmin, xmax, ymin * h / w, ymax * h / w);
		glMatrixMode(GL_MODELVIEW);
	}
	glutPostRedisplay();
}
void process(int hit, GLuint sb[])
{
	int i; GLuint* ptr;
	ptr = (GLuint*)sb;
	for (i = 0; i < hit; i++)
	{
		ptr += 3;
		if (*ptr == 1) printf("RED BOX\n");
		if (*ptr == 2) printf("BLUE BOX\n");
	}
}
void d_obj(GLenum mode)
{
	if (mode == GL_SELECT) glLoadName(1);
	glColor3f(1, 0, 0);
	glRectf(-50, -50, 0, 0);

	if (mode == GL_SELECT) glLoadName(2);
	glColor3f(0, 0, 1);
	glRectf(0, 0, 50, 50);
}
void mousefunc(int button, int status, int x, int y)
{
	GLuint sb[20];
	int hit;
	int vp[4];
	if (button == GLUT_LEFT_BUTTON && status == GLUT_DOWN)
	{
		glGetIntegerv(GL_VIEWPORT, vp);

		glSelectBuffer(20, sb);
		glRenderMode(GL_SELECT);

		glInitNames();
		glPushName(0);

		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		gluPickMatrix(x, vp[3]-y, 1, 1, vp);
		d_obj(GL_SELECT);
		glPopMatrix();
		glFlush();

		hit = glRenderMode(GL_RENDER);
		process(hit, sb);

		glutPostRedisplay();
	}
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	d_obj(GL_RENDER);
	glFlush();
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(200, 200);
	glutCreateWindow("Selection Technique");

	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mousefunc);
	glutReshapeFunc(reshapeFunc);
	glutMainLoop();
}