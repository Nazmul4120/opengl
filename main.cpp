#include <windows.h>
#include <GL\glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int r, key, x, y, p, xc, yc;

void myInit (void)

{

     glClearColor(0.0,0.0,0.0,0.0); // sets background color to white

     // sets a point to be 4x4 pixels

     glMatrixMode(GL_PROJECTION);

     glLoadIdentity();

     gluOrtho2D(0.0, 500.0, 0.0, 400.0); // the display area in world coordinates.

}

void midpoint(int r)
{
    int xc = 250;
    int yc = 200;
    p = 1-r;
    int x = 0;
    int y = r;
    while(x <= y)
    {
        if(p < 0)
        {
            x++;
            p = p+(2*x)+3;
        }
        else
        {
            x++;
            y--;
            p = p+(2*x)-(2*y)+5;
        }
        glVertex2i(xc+x, yc+y);
        glVertex2i(xc+y, yc+x);
        glVertex2i(xc-y, yc+x);
        glVertex2i(xc-x, yc+y);
        glVertex2i(xc-x, yc-y);
        glVertex2i(xc-y, yc-x);
        glVertex2i(xc+y, yc-x);
        glVertex2i(xc+x, yc-y);
    }

}
void myKeboard(unsigned char key, int x, int y)
{

}
void myDisplay(void)

{

     glClear(GL_COLOR_BUFFER_BIT); // clears the screen
     glColor3ub(255, 0, 0) ;// sets the drawing background color colour

     glPointSize(8.0);
     glColor3ub(255, 126, 0) ;
     glBegin(GL_LINES);
        glVertex2i(0, 200);
        glVertex2i(500, 200);
        glVertex2i(250, 400);
        glVertex2i(250, 0);
     glEnd();

     glColor3ub(255, 200, 255) ;
     glBegin(GL_POINTS);
        midpoint(r);

     glEnd();




     glFlush(); // sends all output to display;

}
int main (int argc, char **argv)
{

     printf("Please Enter r (radious) value : ");
     scanf("%d", &r);

     glutInit (&argc, argv); // to initialize the toolkit;

     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); // sets the display mode

     glutInitWindowSize (640, 480); // sets the window size

     glutInitWindowPosition (10, 10); // sets the starting position for the window

     glutCreateWindow ("Midpoint Algo!"); // creates the window and sets the title

     glutDisplayFunc (myDisplay);
     glutKeyboardFunc(myKeboard);
     myInit(); // additional initializations as necessary
     glutMainLoop(); // go into a loop until event occurs
     return 0;
}
