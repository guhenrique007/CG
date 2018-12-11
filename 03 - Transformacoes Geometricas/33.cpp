#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int desiredFPS = 15;

float parametros [2] = {-2.5, -2.5};
float parametros_parciais [2] = {-2.5, -2.5};

void display(void);
void init (void);
void idle();
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (480, 480);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");
   glutIdleFunc( idle);
   glutMouseFunc( mouse );
   init ();
   glutDisplayFunc(display);
   glutMainLoop();

   return 0;
}

void desenharTabuleiro () {
	bool preto = true;	
	for (int linha = -3; linha < 3; linha++) {
    	for (int coluna = -3; coluna < 3; coluna ++) {
			if(preto) glColor3f (255.0, 255.0, 255.0);
			else glColor3f (0.0, 0.0, 0.0); 
			if(coluna != 2){preto = !preto; }
            glBegin(GL_POLYGON);
            glVertex3f(linha, coluna, 0);
            glVertex3f(linha + 1, coluna, 0);
            glVertex3f(linha + 1, coluna + 1, 0);
            glVertex3f(linha, coluna + 1, 0);
			glEnd();
      }
   }
}

void display(void)
{
   // Limpar todos os pixels
   glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity(); // Inicializa com matriz identidade

   desenharTabuleiro();

   glPushMatrix();
      glColor3f(255.0, 0.0, 0.0);
      glTranslatef(parametros_parciais[0], parametros_parciais[1], 0.0);
      glutSolidSphere(0.5, 20, 20);
   glPopMatrix();

   glutSwapBuffers ();
}

void init (void)
{
   // selecionar cor de fundo (preto)
   glClearColor (0.0, 0.0, 0.0, 0.0);

   // inicializar sistema de viz.
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-3, 3, -3, 3, -3 , 3);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void atualizarPosicaoCirculo () {
	for(int i=0; i<2; i++){ 
		if(parametros_parciais[i] < parametros[i]) {parametros_parciais[i] += 0.25;}
		else if(parametros_parciais[i] > parametros[i]) {parametros_parciais[i] -= 0.25;}
	}
}

void idle()
{
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
     atualizarPosicaoCirculo();

    /* Update tLast for next time, using static local variable */
    tLast = t;

    glutPostRedisplay();

}

float definirCoordenada (int p) {
  if (p == 0) return - 2.5;
  else if (p == 1) return - 1.5;
  else if (p == 2) return - 0.5;
  else if (p == 3) return 0.5;
  else if (p == 4) return 1.5;
  else return 2.5;
}

void mouse(int button, int state, int x, int y)
{
  // Inverte mouse para que origem fique no canto inferior esquerdo da janela
  // (por default, a origem é no canto superior esquerdo)
  if (parametros[0] ==  parametros_parciais[0] && parametros[0] == parametros_parciais[1]) {
    int novo_x = x / 80, novo_y = (480 - y) / 80;
    parametros[0] = definirCoordenada(novo_x);
    parametros[1] = definirCoordenada(novo_y);
  }

}
