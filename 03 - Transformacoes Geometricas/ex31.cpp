#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

float angle = 0, scale = 1.0;
float xtrans = 0, ytrans = 0, ztrans = 0;

void desenhaEixos(){
	glColor3f (0.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f (0.0, -100.0);
	glVertex2f (0.0, 100.0);
	glVertex2f (-100.0, 0.0);
	glVertex2f (100.0, 0.0);
	glEnd();
}

void display(void){
	glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	desenhaEixos();

	glColor3f (1.0, 0.0, 0.0);

	glPushMatrix();
	glTranslatef(xtrans, ytrans, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glScalef(scale, scale, scale);
	glutWireCube(10);
	glPopMatrix();

	glutSwapBuffers ();
	glutPostRedisplay();
}

void init (void) {
	glClearColor (0.0, 0.0, 0.0, 0.0); glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();
}

void evento_tecla_seta(int tecla, int x, int y) {
   float r = (10*scale)/2;
   switch(tecla) {
      case GLUT_KEY_LEFT:
         xtrans = xtrans - r - 1 < -100? xtrans : xtrans - 1;
         break;
      case GLUT_KEY_RIGHT:
         xtrans = xtrans + r + 1 > 100? xtrans : xtrans + 1;
         break;
      case GLUT_KEY_UP:
         ytrans = ytrans + r + 1 > 100? ytrans : ytrans + 1;
         break;
      case GLUT_KEY_DOWN:
         ytrans = ytrans - r - 1 < -100? ytrans : ytrans - 1;
         break;
   } glutPostRedisplay();
}

void teclado(unsigned char tecla, int x, int y){
	switch(tecla){
       case 43: scale += 1; break;
       case 45: scale =  scale - 1 <= 0 ? scale : scale - 1; break;
       case 114: angle += 1; break;
    } glutPostRedisplay();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
	glutInitWindowSize (400, 400); glutInitWindowPosition (20, 20);
	glutCreateWindow (""); init ();
	glutDisplayFunc(display); glutKeyboardFunc(teclado);
	glutSpecialFunc(evento_tecla_seta);
	glutMainLoop();
}
