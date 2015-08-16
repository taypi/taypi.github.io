/* programa teste-make.c */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);

/* cores do quadrado */
GLfloat r=1.0, g=1.0, b=1.0, r1=1.0, g1=0.0, b1=0.0, r2=0.0, g2=1.0, b2=0.0, r3=0.0, g3=0.0, b3=1.0, tempR, tempG, tempB;
bool bigR = false, bigG = false, bigB = false;

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow (argv[0]);
  // inicia um temporizador. após 33ms ativa a funcao timer
  glutTimerFunc(75, timer, 1);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glOrtho (0, 1, 0, 1, -1 ,1);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void timer(int value){
  glutPostRedisplay();
  glutTimerFunc(100, timer, 1);
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
	glColor3f (r, g, b);
  glVertex2f(0.25,0.25);
	glColor3f (r1, g1, b1);
  glVertex2f(0.75,0.25);
	glColor3f (r2, g2, b2);
  glVertex2f(0.75,0.75);
	glColor3f (r3, g3, b3 );
  glVertex2f(0.25,0.75);
  glEnd();
  glFlush();
	glutSwapBuffers();
  tempR=r3;
  tempG=g3;
  tempB=b3;
  r3=r2;
  g3=g2;
  b3=b2;
  r2=r1;
  g2=g1;
  b2=b1;
  r1=r;
  g1=g;
  b1=b;
  r=tempR;
  g=tempG;
  b=tempB;
}
