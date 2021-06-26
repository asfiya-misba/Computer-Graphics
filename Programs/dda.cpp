// DDA (Digital Differential Analyzer)
#include <stdio.h>
#include<math.h>
#include <GL/glut.h>
using namespace std;
void myinit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 15, -10, 15);
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
void lineDDA(float x0, float y0, float xEnd, float yEnd)
{
    float dx = xEnd - x0, dy = yEnd - y0, steps, k;
    float xInc, yInc, x = x0, y = y0;
    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);
    xInc = float(dx) / float(steps);
    yInc = float(dy) / float(steps);
    setPixel(round(x), round(y));
    for (k = 0; k < steps; k++)
    {
        x += xInc;
        y += yInc;
        setPixel(round(x), round(y));
    }
}
void display(void)
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(5);
    lineDDA(5, 7, 12, 9);
    //lineDDA(-3, 2, 1, 5);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("DDA");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();
}