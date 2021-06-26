#include<stdio.h>
#include<GL/glut.h>
int ww = 500, wh = 500, press1 = 0, press2 = 0, res;
int num1 = 22;
int num2 = 22;
char str1[10];
char str2[10];
char str3[10];
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, ww, 0, wh);
	glMatrixMode(GL_MODELVIEW);
}
void outputhorizontal(int x, int y, const char* string)
{
	y = wh - y;
	int len, i;
	glRasterPos2f(x, y);
	len = (int)strlen(string);
	for (i = 0; i < len; i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
	glFlush();
}
void display()
{
	_itoa_s(num1, str1, 10);
	_itoa_s(num2, str2, 10);
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.41, 0.52, 0.8);
	glRectf(50, 150, 150, 200);
	glRectf(50, 225, 150, 275);
	glRectf(50, 300, 150, 350);

	glColor3f(0.7, 0.7, 0.7);
	glRectf(200, 150, 300, 200);
	glRectf(200, 225, 300, 275);
	glRectf(200, 300, 300, 350);

	glColor3f(1, 0.7, 0.7);
	glRectf(350, 150, 450, 200);
	glRectf(350, 225, 450, 275);
	glRectf(350, 300, 450, 350);

	glColor3f(1, 1, 1);
	outputhorizontal(74, 175, "Input 1");
	outputhorizontal(74, 250, "Input 2");
	outputhorizontal(74, 325, "Result");

	glColor3f(1, 0, 0);
	outputhorizontal(240, 175, str1);
	outputhorizontal(240, 250, str2);
	outputhorizontal(240, 325, str3);

	glColor3f(0, 0, 0);
	outputhorizontal(400, 175, "+");
	outputhorizontal(400, 250, "-");
	outputhorizontal(400, 325, "/");
	glFlush();
}
void mouse(int button, int state, int x, int y)
{
	y = wh - y;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (x > 350 && y > 300 && x < 450 && y < 350)
		{
			res = num1 + num2;
		}
		if (x > 350 && y > 225 && x < 450 && y < 275)
		{
			res = num1 - num2;
		}
		if (x > 350 && y > 150 && x < 450 && y < 200)
		{
			res = num1 / num2;
		}
		_itoa_s(res, str3, 10);
		glutPostRedisplay();
	}
}
int main(int argc, char* argv[])
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(ww, wh);
	glutInit(&argc, argv);
	glutCreateWindow("Simple Calculator");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}