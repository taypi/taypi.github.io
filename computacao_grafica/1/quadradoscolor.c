#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

void display(void);
void timer(int);
void keyboard(unsigned char key, int x, int y);
void HSItoRGB(int h, float s, float i);
float rad(float a);

/* cores do quadrado */
GLfloat r=0.0, g=0.0, b=0.0;
float s, i;
int h[4];

int main(int argc, char** argv){
  for (int k=0; k<4; k++)
    h[k] = 0;
  s = 1.0;
  i = 1.0;

  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  // inicia um temporizador. Após 100ms ativa a funcao timer
  glutTimerFunc(100, timer, 1);
  glClearColor(1.0, 1.0, 1.0, 0.0);
  //glShadeModel (GL_FLAT);
  glOrtho (0, 1, 0, 1, -1 ,1);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void timer(int value){
  h[0] = (h[0] + 80)%360;
  glutPostRedisplay();
  glutSwapBuffers();
  glutTimerFunc(100, timer, 1);
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);

  //vertice1
  HSItoRGB(h[0], s, i);
  glColor3f (r, g, b);
  glVertex2f(0.25,0.25);
  //vertice2
  HSItoRGB(h[1], s, i);
  glColor3f (r, g, b);
  glVertex2f(0.75,0.25);
  //vertice3
  HSItoRGB(h[2], s, i);
  glColor3f (r, g, b);
  glVertex2f(0.75,0.75);
  //vertice4
  HSItoRGB(h[3], s, i);
  glColor3f (r, g, b);
  glVertex2f(0.25,0.75);

  glEnd();
  glFlush();

  //troca das cores
  h[3]=h[2];
  h[2]=h[1];
  h[1]=h[0];
}

//função de HSI para RGB
void HSItoRGB(int h, float s, float i) {
  if (h>= 0 && h < 120)
  {
    b = i*(1-s)/3;
    r = i*(1+(s*cos(rad(h))/cos(rad(60-h))))/3;
    g = i*(1-(r+b));
  } else if (h < 240)
  {
    h = h-120;
    r = i*(1-s)/3;
    g = i*(1+(s*cos(rad(h))/cos(rad(60-h))))/3;
    b = i*(1-(r+g));
  } else if (h <= 360)
  {
    h = h-240;
    g = i*(1-s)/3;
    b = i*(1+(s*cos(rad(h))/cos(rad(60-h))))/3;
    r = i*(1-(g+b));
  }
}
float rad(float a) {
  return ((float)a)*M_PI/180.0;
}