#include <GL/glut.h>
#include <stdlib.h>

void init(void);
void display(void);

int x1=40, y1=200, x2=200, y2=10, x, y, delta_x, delta_y, s1, s2, temp;
bool troca=0;
float new_e;

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Desenhando uma linha verde");
  init();
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f (0.0, 1.0, 0.0);
  glBegin(GL_POINTS);
  x = x1;
  y = y1;
  delta_x = abs(x2 - x1);
  delta_y = abs(y2 - y1);
  if (x2 < x1) s1=-1;
  else s1=1;
  if (y2 < y1) s2=-1;
  else s2=1;
  if(delta_y > delta_x){
    temp = delta_x;
    delta_x = delta_y;
    delta_y = temp;
    troca = 1;
  }
  else{
    troca = 0;
  }
  new_e = 2*delta_y - delta_x;
  for(int i=1; i<= delta_x; i++){
    glVertex2i(x,y);
    while (new_e >= 0){
      if(troca == 1){
        x = x + s1;
      }
      else{
        y = y + s2;
      }
      new_e = new_e - 2*delta_x;
    }
    if(troca == 1){
      y = y + s2;
    }
    else{
      x = x + s1;
    }
    new_e= new_e + 2*delta_y;
  }
  glEnd();
  glFlush();
}
