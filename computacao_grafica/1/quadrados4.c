/* programa teste-make.c */

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);

/* cores do quadrado */
GLfloat r=0.8, g=0.5, b=0.3;
bool bigR = false, bigG = false, bigB = false;

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  // inicia um temporizador. após 33ms ativa a funcao timer
  glutTimerFunc(50, timer, 1);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glShadeModel (GL_FLAT);
  glOrtho (0, 1, 0, 1, -1 ,1);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void timer(int value){
	if(r>1) bigR = true;
	else if(r<0) bigR = false;
	if(g>1) bigG = true;
	else if(g<0) bigG = false;
	if(b>1) bigB = true;
	else if(b<0) bigB = false;

	if(bigR == false) r=r+0.01;
	else r=r-0.01;
	if(bigG == false) g=g+0.03;
	else g=g-0.03;
	if(bigB == false) b=b+0.05;
	else b=b-0.05;
  glutPostRedisplay();
  glutTimerFunc(50, timer, 1);
}

void display(void){
		glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < 4; i++){
		glColor3f (r+i*0.2, g+i*0.2, b+i*0.2);
		glBegin(GL_POLYGON);
		glVertex2f(0.10+i*0.1,0.10+i*0.1);
		glVertex2f(0.60+i*0.1,0.10+i*0.1);
		glVertex2f(0.60+i*0.1,0.60+i*0.1);
		glVertex2f(0.10+i*0.1,0.60+i*0.1);
		glEnd();
		glFlush();
	}
	glutSwapBuffers();
}
