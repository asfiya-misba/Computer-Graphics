#include<stdio.h>
#include<gl/GLUT.h>
#include<math.h>
int siz = 5, xmin = -100, xmax = 100, ymin = -100, ymax = 100;
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(xmin, xmax, ymin, ymax);
	glMatrixMode(GL_MODELVIEW);
}
void rectangle(int siz)
{
	glBegin(GL_POLYGON);
	glVertex2f(20 + siz, 5 + siz);
	glVertex2f(-(20 + siz), 5 + siz);
	glVertex2f(-(20 + siz), -(5 + siz));
	glVertex2f(20 + siz, -(5 + siz));
	glEnd();
}
void circle(int siz)
{
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(0, 0);
	for (float i = 0; i < 360; i += 1)
		glVertex2f(siz * cos(i), siz * sin(i));
	glEnd();
}
void polygon(int siz)
{
	glBegin(GL_POLYGON);
	glVertex2f(20 + siz, 20 + siz);
	glVertex2f(20 + siz, -(20 + siz));
	glVertex2f(-(20 + siz), -(20 + siz));
	//glVertex2f(-(20 + siz), 20 + siz);
	glEnd();
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
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
void sub_menu(int id)
{
	switch (id)
	{
	case 1:siz += 5;
		break;
	case 2:siz += 10;
		break;
	case 3:siz -= 5;
		break;
	case 4:siz -= 10;
		break;
	case 5:circle(siz);
		break;
	case 6:rectangle(siz);
		break;
	case 7:polygon(siz);
		break;
	case 8:glColor3f(0, 1, 1);
		break;
	case 9:glColor3f(1, 1, 0);
		break;
	case 10:glColor3f(1, 0, 1);
		break;
	}
	glutPostRedisplay();
}
void main(int argc, char* argv[])
{
	int id1, id2, id3, id4, id5;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(500, 500);
	glutInit(&argc, argv);
	glutCreateWindow("Menu");
	myinit();
	glColor3f(0, 0, 0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	id1 = glutCreateMenu(sub_menu);
	glutAddMenuEntry("Increase size by 5", 1);
	glutAddMenuEntry("Increase size by 10", 2);
	id2 = glutCreateMenu(sub_menu);
	glutAddMenuEntry("Decrease size by 5", 3);
	glutAddMenuEntry("Decrease size by 10", 4);
	id3 = glutCreateMenu(sub_menu);
	glutAddSubMenu("Increase", id1);
	glutAddSubMenu("Decrease", id2);
	id4 = glutCreateMenu(sub_menu);
	glutAddMenuEntry("Circle", 5);
	glutAddMenuEntry("Rectangle", 6);
	glutAddMenuEntry("polygon", 7);
	id5 = glutCreateMenu(sub_menu);
	glutAddMenuEntry("Cyan", 8);
	glutAddMenuEntry("Yellow", 9);
	glutAddMenuEntry("Magenta", 10);
	glutCreateMenu(sub_menu);
	glutAddSubMenu("Object", id4);
	glutAddSubMenu("Size", id3);
	glutAddSubMenu("Color", id5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}