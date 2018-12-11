#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

int partes = 0;

void exibe(){
	glClear (GL_COLOR_BUFFER_BIT);

	glColor3f (1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	  glVertex3f (0.0, -2.0, 0.0);
	  glVertex3f (0.0, 2.0, 0.0);
	glEnd();

	glBegin(GL_LINES);
	  glVertex3f (-10.0, 0.0, 0.0);
	  glVertex3f (390.0, 0.0, 0.0);
	glEnd();

	glColor3f (0.0, 255.0, 0.0);

	const float volta = 360.0;
	float discretizacao;

	glBegin(GL_LINE_STRIP);

	if (partes == 0) discretizacao = volta / 6.0;   
	else if (partes == 1) discretizacao = volta / 12.0;
	else discretizacao = volta / 180.0;

	float fatorConversao = M_PI / 180.0;

	for (float i = 0.0; i <= volta; i += discretizacao) {
	  glVertex3f(i, sin(i * fatorConversao), 0.0);
	}

	glEnd();

	glutSwapBuffers ();
}

void inicio(void){
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 390, -2, 2, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(20,20);
	glutCreateWindow("Exercício 2 - Aula 2");
	inicio(); glutDisplayFunc(exibe);
	glutMainLoop();
}
