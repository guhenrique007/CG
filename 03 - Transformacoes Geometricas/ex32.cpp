#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

/*
float angle = 0, angleParcial = 0, scale = 1.0, scaleParcial = 1.0;
float xtrans = 0, ytrans = 0, ztrans = 0;
float xtransParcial = 0, ytransParcial = 0;
*/

float parametros [4] = {0};
float parametros_parciais [4] = {0};

int desiredFPS = 15;

void display(void);
void init (void);
void desenhaEixos();
void showMenu();
void idle();

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE|GLUT_DEPTH|GLUT_RGB);
   glutInitWindowSize (300, 300);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");
   glutIdleFunc( idle);
   init ();
   printf("Posicione as janelas e clique na janela do OpenGL para habilitar o menu.\n");
   glutDisplayFunc(display);
   glutMainLoop();

   return 0;
}

void showMenu()
{
   int op;
   system("cls");
   printf("\n=== MENU ===");
   printf("\n1 - Translacao");
   printf("\n2 - Rotacao");
   printf("\n3 - Escala");
   printf("\n4 - Sair");
   printf("\nOpcao: ");

   scanf("%d", &op);
   switch(op)
   {
      case 1:
         printf("\n\nInforme o vetor de translacao (entre -100.0 e 100.0)");
         printf("\nX : ");
         scanf("%f", &parametros[0]);
         printf("Y : ");
         scanf("%f", &parametros[1]);
      break;
      case 2:
         printf("\n\nInforme o angulo de rotacao (em graus): ");
         scanf("%f", &parametros[2]);
      break;
      case 3:
         printf("\n\nInforme o fator de escala: ");
         scanf("%f", &parametros[3]);
      break;
      case 4:
         exit(1);
      break;
      default:
         printf("\n\nOpcao invalida\n\n");
      break;
   }
}

void desenhaEixos()
{
   glColor3f (0.0, 1.0, 0.0);
   glBegin(GL_LINES);
      glVertex2f (0.0, -100.0);
      glVertex2f (0.0, 100.0);
      glVertex2f (-100.0, 0.0);
      glVertex2f (100.0, 0.0);
   glEnd();
}

void display(void)
{
   // Limpar todos os pixels
   glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity(); // Inicializa com matriz identidade

   desenhaEixos();

   glColor3f (1.0, 0.0, 0.0);

   glPushMatrix();
      glTranslatef(parametros_parciais[0], parametros_parciais[1], 0.0);
      glRotatef(parametros_parciais[2], 0.0, 0.0, 1.0);
      glScalef(parametros_parciais[3], parametros_parciais[3], parametros_parciais[3]);
      glutWireCube(10);
   glPopMatrix();

   glutSwapBuffers ();

   bool mudanca = false;
   for(int i=0; i<4; i++){ if(parametros[i] != parametros_parciais[i]){ mudanca = true; break; }
   }
   if(!mudanca){showMenu();};
}

void init (void)
{
   // selecionar cor de fundo (preto)
   glClearColor (0.0, 0.0, 0.0, 0.0);

   // inicializar sistema de viz.
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void atualizarEstadoQuadrado () {
	for(int i=0; i<4; i++){ 
		if(parametros_parciais[i] < parametros[i]) {parametros_parciais[i] += 0.5;}
		else if(parametros_parciais[i] > parametros[i]) {parametros_parciais[i] -= 0.5;}
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
     atualizarEstadoQuadrado();

    /* Update tLast for next time, using static local variable */
    tLast = t;

    glutPostRedisplay();

}
