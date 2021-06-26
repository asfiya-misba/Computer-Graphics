#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
float ya = 50, xa = 10;
int yflag = 1, xflag = 1;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 500, 0, 500);
	glMatrixMode(GL_MODELVIEW);
}

void draw()
{
	float x[4], y1[4], y2[4], y3[4], y4[4];
	float xt[200], y1t[200], y2t[200], y3t[200], y4t[200];
	int i = 0;
	float u = 0;
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	x[0] = 100.0; x[1] = 200.0; x[2] = 200.0; x[3] = 300.0 + xa;
	y1[0] = 450.0; y1[1] = 450.0 + ya; y1[2] = 450.0 - ya; y1[3] = 450.0;
	y2[0] = 400.0; y2[1] = 400.0 + ya; y2[2] = 400.0 - ya; y2[3] = 400.0;
	y3[0] = 350.0; y3[1] = 350.0 + ya; y3[2] = 350.0 - ya; y3[3] = 350.0;
	y4[0] = 300.0; y4[1] = 300.0 + ya; y4[2] = 300.0 - ya; y4[3] = 300.0;
	for (u = 0; u <= 1; i++, u += 0.02)
	{
		xt[i] = x[0] * pow((1 - u), 3) + x[1] * 3 * u * pow((1 - u), 2) + x[2] * 3 * u * u * (1 - u) + x[3] * pow(u, 3);
		y1t[i] = y1[0] * pow((1 - u), 3) + y1[1] * 3 * u * pow((1 - u), 2) + y1[2] * 3 * u * u * (1 - u) + y1[3] * pow(u, 3);
		y2t[i] = y2[0] * pow((1 - u), 3) + y2[1] * 3 * u * pow((1 - u), 2) + y2[2] * 3 * u * u * (1 - u) + y2[3] * pow(u, 3);
		y3t[i] = y3[0] * pow((1 - u), 3) + y3[1] * 3 * u * pow((1 - u), 2) + y3[2] * 3 * u * u * (1 - u) + y3[3] * pow(u, 3);
		y4t[i] = y4[0] * pow((1 - u), 3) + y4[1] * 3 * u * pow((1 - u), 2) + y4[2] * 3 * u * u * (1 - u) + y4[3] * pow(u, 3);
	}
	glColor3f(1, 0.5, 0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i < 50; i++)
	{
		glVertex2f(xt[i], y1t[i]);
		glVertex2f(xt[i], y2t[i]);
	}
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i < 50; i++)
	{
		glVertex2f(xt[i], y2t[i]);
		glVertex2f(xt[i], y3t[i]);
	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_QUAD_STRIP);
	for (i = 0; i < 50; i++)
	{
		glVertex2f(xt[i], y3t[i]);
		glVertex2f(xt[i], y4t[i]);
	}
	glEnd();

	glColor3f(0, 0, 0);
	glRectf(90, 100, 100, 450);
	glFlush();

}

void idle()
{
	if (ya > -50 && yflag == 1)
		ya = ya - 0.01;
	if (ya <= -50 && yflag == 1)
		yflag = 0;

	if (ya < 50 && yflag == 0)
		ya = ya + 0.01;
	if (ya >= 50 && yflag == 0)
		yflag = 1;
	//xa values

	if (xa > -10 && xflag == 1)
		xa = xa - 0.002;
	if (xa <= -10 && xflag == 1)
		xflag = 0;

	if (xa < 10 && xflag == 0)
		xa = xa + 0.002;
	if (xa >= 10 && xflag == 0)
		xflag = 1;
	glutPostRedisplay();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Flag");
	myinit();
	glutDisplayFunc(draw);
	glutIdleFunc(idle);
	glutMainLoop();
}