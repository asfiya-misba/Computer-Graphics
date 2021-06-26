//Circle drawing using mid-point theorem
#include <stdio.h>
#include<math.h>
#include <GL/glut.h>
using namespace std;

void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
}
void setPixel(float x, float y)
{
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}
void eight_way_sym(float x, float y)
{
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glVertex2f(y, x);
    glVertex2f(-x, y);
    glVertex2f(-y, x);
    glVertex2f(-x, -y);
    glVertex2f(-y, -x);
    glVertex2f(x, -y);
    glVertex2f(y, -x);
    glEnd();
    glFlush();
}
void midpoint(float r, float xc, float yc)
{
    int x = 0;
    int y = r;
    float decision = 1 - r;
    setPixel(x + xc, y + yc);

    while (y > x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2 * x + 1;
        }
        else
        {
            y--;
            x++;
            decision += 2 * (x - y) + 1;
        }
        setPixel(x + xc, y + yc);
        setPixel(x + xc, -y + yc);
        setPixel(-x + xc, y + yc);
        setPixel(-x + xc, -y + yc);
        setPixel(y + xc, x + yc);
        setPixel(-y + xc, x + yc);
        setPixel(y + xc, -x + yc);
        setPixel(-y + xc, -x + yc);
    }
}
void display(void)
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    midpoint(5, 0, 0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Circle");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
}

