#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <GL/gl.h>
#include <GL/glut.h>
void display(void)
{
/* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3f (1,1,1);
    glBegin(GL_POLYGON);
    glVertex3f (0.00, 0.50, 0.0);
    glVertex3f (0.50, 0.0, 0.0);
    glVertex3f (1.0, 0.50, 0.0);
    glVertex3f (0.50, 1.0, 0.0);
    glEnd();


  //1
    glColor3f (0,128,0);
    glBegin(GL_POLYGON);
    glVertex3f (0, 0.50, 0.0);
    glVertex3f (0.40, 0.10, 0.0);
    glVertex3f (0.40, 0.60, 0.0);
    glVertex3f (0.10, 0.60, 0.0);
    glEnd();


//2
  glColor3f (1,0,0);
    glBegin(GL_POLYGON);
    glVertex3f (0.40, 0.10, 0.0);
    glVertex3f (0.50, 0.0, 0.0);
    glVertex3f (0.90, 0.40, 0.0);
    glVertex3f (0.40, 0.40, 0.0);
    glEnd();

    //3
      glColor3f (1,0,1);
    glBegin(GL_POLYGON);
    glVertex3f (0.60, 0.40, 0.0);
    glVertex3f (0.90, 0.40, 0.0);
    glVertex3f (1.0, 0.50, 0.0);
    glVertex3f (0.60, 0.90, 0.0);
    glEnd();

    //4
      glColor3f (1,1,0);
    glBegin(GL_POLYGON);
    glVertex3f (0.10, 0.60, 0.0);
    glVertex3f (0.60, 0.60, 0.0);
    glVertex3f (0.60, 0.90, 0.0);
    glVertex3f (0.50, 1.0, 0.0);
    glEnd();

    glFlush ();
}
void init (void)
{
/* select clearing (background) color */
glClearColor (0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("hello");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}
