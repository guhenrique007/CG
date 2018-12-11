#include <iostream>
#include <GL/glut.h>
#include <stdio.h>

using namespace std;

float desiredFPS = 2;

float xVerde = 0.3, yVerde = 0.5,
    dirXVerde = 0.1, dirYVerde = 0.1;

const float maiorXVerde = 0.7, maiorYVerde = 0.5,
    menorXVerde = 0.2, menorYVerde = 0.2;

float xVermelho = 0.2, yVermelho = 0.2,
    dirXVermelho = 0.1, dirYVermelho = 0.1;

const float maiorXVermelho = 0.8, maiorYVermelho = 0.8,
    menorXVermelho = 0.4, menorYVermelho = 0.5;

void display(void);
void init (void);
void idle();

void idle(){

    float t, desiredFrameTime, frameTime;
    static float tLast = 0.0;

    // Get elapsed time
    t = glutGet(GLUT_ELAPSED_TIME);
    // convert milliseconds to seconds
    t /= 1000.0;

    // Calculate frame time
    frameTime = t - tLast;
    // Calculate desired frame time
    desiredFrameTime = 1.0 / (float) (desiredFPS);

    // Check if the desired frame time was achieved. If not, skip animation.
    if( frameTime <= desiredFrameTime)
        return;

    /*
     *UPDATE ANIMATION VARIABLES
     */

    if(maiorXVerde + xVerde >= 1 || menorXVerde + xVerde <= 0.1)
        dirXVerde *= -1;
    if(maiorYVerde + yVerde >= 1 || menorYVerde + yVerde <= 0.1)
        dirYVerde *= -1;
    //else if ()
    xVerde += dirXVerde;
    yVerde += dirYVerde;

    if(maiorXVermelho + xVermelho >= 1 || menorXVermelho + xVermelho <= 0) 
        dirXVermelho *= -1;
    if(maiorYVermelho + yVermelho >= 1 || menorYVermelho + yVermelho <= 0) 
        dirYVermelho *= -1;
    //else if ()
    xVermelho += dirXVermelho;
    yVermelho += dirYVermelho;

   /* Update tLast for next time, using static local variable */
    tLast = t;

    glutPostRedisplay();

}

void plotTriangle (float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
        glVertex2f (x1, y1);
        glVertex2f (x2, y2);
        glVertex2f (x3, y3);
    glEnd();
}

void display(void){
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    
    glColor3f (0.0, 1.0, 0.0);

    glPushMatrix();
        glTranslatef(xVerde, yVerde, 0);
        glBegin(GL_TRIANGLES);
            plotTriangle(0.5, menorYVerde, maiorXVerde, 0.4, menorXVerde, maiorYVerde);
        glEnd();
    glPopMatrix();

    glColor3f (1.0, 0.0, 0.0);

    glPushMatrix();
        glTranslatef(xVermelho, yVermelho, 0);
        plotTriangle(0.6, maiorYVermelho, maiorXVermelho, menorYVermelho, menorXVermelho, 0.6);
    glPopMatrix();
    
    glutSwapBuffers ();
}

void init (void){
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);

    glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
    glutInitWindowSize (400, 400);
    glutInitWindowPosition (0, 0);
    glutCreateWindow ("Animacoes - Ex.1");
    glutFullScreen();
    glutIdleFunc( idle);
    init ();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
