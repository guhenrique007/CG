#include <GL/glut.h>
#include <stdio.h>

void init(void);
void a(void);
void b(void);
void c(void);
void d(void);
void eixo(void);
//void keyboard(unsigned char key, int x, int y);
void keyboard2(unsigned char key, int x, int y);

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100,100);
	glViewport(-2,-2, 100, 100);
	glutCreateWindow("Ex:1 - a: triangulo");
	init();
	//glutKeyboardFunc(keyboard);
	glutKeyboardFunc(keyboard2);
	glutDisplayFunc(a);

	printf("Pressione ESC para fechar \n");

	glutMainLoop();

	return 0;
}

void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);// Seleciona a cor de fundo(preto)
	
	//Inicializa sistema de vizualização
	glMatrixMode(GL_PROJECTION); // Seleciona Matriz de projeção
	glLoadIdentity();
	//glOrtho(0.0, 1.0, 0.0,1.0, -1.0, 1.0);
	gluOrtho2D(-1,1,-1,1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	//Inicializa com Matriz identidade
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27:
			exit(0);
		break;
	}
}

void keyboard2(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 97:
			a();
		break;
		case 98:
			b();
		break;
		case 99:
			c();
		break;
		case 100:
			d();
		break;
		case 27:
			exit(0);
		break;
	}
}

void a(void)
{

	glClear(GL_COLOR_BUFFER_BIT);// Limpar todos os pixels
	eixo();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.3, 0.6, 0.0);
		glVertex3f(0.6, 0.0, 0.0);
	glEnd();

	glutSwapBuffers();
}

void b(void)
{

	glClear(GL_COLOR_BUFFER_BIT);// Limpar todos os pixels
	eixo();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.3, 0.6, 0.0);
		glVertex3f(0.6, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.3, 0.6, 0.0);
		glVertex3f(0.6, 0.0, 0.0);
	glEnd();

	glutSwapBuffers();
}

void c(void)
{

	glClear(GL_COLOR_BUFFER_BIT);// Limpar todos os pixels
	eixo();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.3, 0.6, 0.0);
		glVertex3f(0.6, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.3, 0.6, 0.0);
		glVertex3f(0.6, 0.0, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(-0.3, -0.6, 0.0);
		glVertex3f(-0.6, 0.0, 0.0);
	glEnd();


	glutSwapBuffers();
}

void d(void)
{

	glClear(GL_COLOR_BUFFER_BIT);// Limpar todos os pixels
	eixo();
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex3f(-0.1, 0.2, 0.0);// L1
		glVertex3f(-0.2, 0.0, 0.0);
		glVertex3f(0.1, 0.2, 0.0);// L2
		glVertex3f(0.2, 0.0, 0.0);
		glVertex3f(-0.2, 0.0, 0.0);// L3
		glVertex3f(-0.1, -0.2, 0.0);
		glVertex3f(0.2, 0.0, 0.0);// L4
		glVertex3f(0.1, -0.2, 0.0);
		glVertex3f(-0.1, -0.2, 0.0);// L5
		glVertex3f(0.1, -0.2, 0.0);
	glEnd();

	glutSwapBuffers();
}

void eixo(void)
{
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(-2.0,0.0,0.0);
		glVertex3f(2.0,0.0,0.0);
		glVertex3f(0.0,2.0,0.0);
		glVertex3f(0.0,-2.0,0.0);
	glEnd();

}