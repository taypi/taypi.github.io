#include <GL/glut.h>
#include <stdlib.h>
#include <GL/glut.h>

void init(void);
void pontosDaCircunferencia(int, int);
void display(void);

int x0=128, y0=128, raio=50, d, x, y;

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Desenhando uma circunferência");
  init();
  glutDisplayFunc(display); 
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
}

void pontosDaCircunferencia(int x,int y){
  glVertex2i(x+x0,y+y0);
  glVertex2i(y+x0,x+y0);
  glVertex2i(-x+x0,y+y0);
  glVertex2i(-y+x0,x+y0);
  glVertex2i(-x+x0,-y+y0);
  glVertex2i(-y+x0,-x+y0);
  glVertex2i(x+x0,-y+y0);
  glVertex2i(y+x0,-x+y0);
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0.0, 0.0, 1.0);
  glBegin(GL_POINTS);
  x = 0;
  y = raio;
  d = 1 - y;
  pontosDaCircunferencia(x,y);
  while(y > x){
    if(d < 0){
      d = d + 2*x + 3;
      x = x + 1;
    }
    else{
      d = d + 2*(x-y) + 5;
      x = x + 1;
      y = y - 1;
    }
    pontosDaCircunferencia(x,y);
  }
  glEnd();
  glFlush();
}
