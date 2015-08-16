#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);

GLfloat r[5]={1.0,0.0,0.0,0.5,0.0}, g[5]={0.0,1.0,0.0,0.5,0.0}, b[5]={0.0,0.0,1.0,0.5,0.0};

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
	glColor3f (r[0], g[0], b[0]);
  glVertex2f(0.25,0.25);
	glColor3f (r[1], g[1], b[1]);
  glVertex2f(0.75,0.25);
	glColor3f (r[2], g[2], b[2]);
  glVertex2f(0.75,0.75);
	glColor3f (r[3], g[3], b[3]);
  glVertex2f(0.25,0.75);
  glEnd();
  glFlush();
	glutSwapBuffers();
  r[4]=r[0];
  g[4]=g[0];
  b[4]=b[0];
  for (int i=0; i<4; i++){
    r[i]=r[i+1];
    g[i]=g[i+1];
    b[i]=b[i+1];
  }
}
