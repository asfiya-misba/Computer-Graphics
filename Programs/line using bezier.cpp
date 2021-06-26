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
	x[0] = 100.0; x[1] = 200.0; x[2] = 200.0; x[3] = 300.0;
	y1[0] = 450.0; y1[1] = 450.0; y1[2] = 450.0; y1[3] = 450.0;

	for (u = 0; u <= 1; i++, u += 0.02)
	{
		xt[i] = x[0] * pow((1 - u), 3) + x[1] * 3 * u * pow((1 - u), 2) + x[2] * 3 * u * u * (1 - u) + x[3] * pow(u, 3);
		y1t[i] = y1[0] * pow((1 - u), 3) + y1[1] * 3 * u * pow((1 - u), 2) + y1[2] * 3 * u * u * (1 - u) + y1[3] * pow(u, 3);
	}
	glColor3f(0.57, 0.49, 0.73);
	glPointSize(6);
	glBegin(GL_POINTS);
	for (i = 0; i < 200; i++)
	{
		glVertex2f(xt[i], y1t[i]);
		//glVertex2f(xt[i], y2t[i]);
	}
	glEnd();

	glFlush();

}



void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Line using bezier");
	myinit();
	glutDisplayFunc(draw);
	//glutIdleFunc(idle);
	glutMainLoop();
}