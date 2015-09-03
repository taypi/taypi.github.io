#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

GLfloat rL[4], gL[4], bL[4], rF[4], gF[4], bF[4];
GLint x[4], y[4];
bool flagF;

void init(void);
void display(void);
void defineColor(GLint, GLint);
void draw();
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (256, 256);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Quadradinhos");
  init();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMainLoop();
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glOrtho (0, 256, 0, 256, -1 ,1);
  for (int i=0; i<4; i++){
    rL[i]=0.0; gL[i]=0.0; bL[i]=0.0;
    rF[i]=1.0; gF[i]=1.0; bF[i]=0.0;
  }
  x[0]=30; x[1]=143; x[2]=30; x[3]=143;
  y[0]=226; y[1]=226; y[2]=113; y[3]=113;
  flagF=true;
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  glDisable(GL_POLYGON_STIPPLE);

  draw();

  glFlush();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
    case 'b':
      flagF=false;
      break;
    case 'f':
      flagF=true;
      break;
  }
}

void mouse(int button, int state, int px, int py){
  switch (button){
  case GLUT_LEFT_BUTTON:
  if (state == GLUT_DOWN){
    defineColor(px,(py*-1)+256);
  }
  break;
  }
}

void draw(){
  for (int i=0; i<4; i++){
    glPolygonMode(GL_BACK, GL_FILL);
    glColor3f(rF[i], gF[i], bF[i]);
    glBegin(GL_POLYGON);
    glVertex2i(x[i],y[i]);  glVertex2i(x[i]+83,y[i]);
    glVertex2i(x[i]+83,y[i]-83); glVertex2i(x[i],y[i]-83);
    glEnd();

    glPolygonMode(GL_BACK, GL_LINE);
    glColor3f(rL[i], gL[i], bL[i]);
    glBegin(GL_POLYGON);
    glVertex2i(x[i],y[i]);  glVertex2i(x[i]+83,y[i]);
    glVertex2i(x[i]+83,y[i]-83); glVertex2i(x[i],y[i]-83);
    glEnd();
  }
}

void defineColor(GLint px, GLint py){
  for (int i=0; i<4; i++){
    if (px>=x[i] && px<=x[i]+83 && py>=y[i]-83 && py<=y[i]){
      if (flagF==true){
        rF[i]=(GLfloat)rand()/(RAND_MAX+1.0);
        gF[i]=(GLfloat)rand()/(RAND_MAX+1.0);
        bF[i]=(GLfloat)rand()/(RAND_MAX+1.0);
        glutPostRedisplay();
      }
      else{
        rL[i]=(GLfloat)rand()/(RAND_MAX+1.0);
        gL[i]=(GLfloat)rand()/(RAND_MAX+1.0);
        bL[i]=(GLfloat)rand()/(RAND_MAX+1.0);
        glutPostRedisplay();
      }
    }
  }
}
