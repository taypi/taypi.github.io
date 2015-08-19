#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

GLubyte tux[] = {
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x7f,  0xfe,  0x0, 
 0x0,  0xc4,  0x23,  0x0, 
 0x1,  0x83,  0x21,  0x80, 
 0x1,  0x7,  0xe0,  0x80, 
 0x1,  0x7,  0xf0,  0x80, 
 0x1,  0x8f,  0xf9,  0x80, 
 0x0,  0xff,  0xff,  0x0, 
 0x0,  0x4f,  0xf1,  0x0, 
 0x0,  0x6f,  0xf1,  0x0, 
 0x0,  0x2f,  0xf3,  0x0, 
 0x0,  0x27,  0xe2,  0x0, 
 0x0,  0x30,  0x66,  0x0, 
 0x0,  0x1b,  0x1c,  0x0, 
 0x0,  0xb,  0x88,  0x0, 
 0x0,  0xb,  0x98,  0x0, 
 0x0,  0x8,  0x18,  0x0, 
 0x0,  0xa,  0x90,  0x0, 
 0x0,  0x8,  0x10,  0x0, 
 0x0,  0xc,  0x30,  0x0, 
 0x0,  0x6,  0x60,  0x0, 
 0x0,  0x3,  0xc0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0
};

GLfloat rL[4], gL[4], bL[4], rF[4], gF[4], bF[4];
bool flagF;

void init(void);
void display(void);
void draw(GLint, GLint, GLint, GLint);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256); 
  glutInitWindowPosition (100, 100); 
  glutCreateWindow ("Preenchendo regiões");
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
  rL=0.0; gL=0.0; bL=0.0;
	rF=1.0; gF=1.0; bF=0.0;
	flagF=true;
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glDisable(GL_POLYGON_STIPPLE);

	draw(30,226,113,143);
	draw(143,226,226,143);
	draw(30,113,113,30);
	draw(143,113,226,30);

  glFlush();
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 98:
		flagF=false;
		break;
	case 102:
		flagF=true;
		break;
  }
}

void mouse(int button, int state, int x, int y){
  switch (button){
  case GLUT_LEFT_BUTTON:
	if (state == GLUT_DOWN){
		if (flagF==true){
			rF=(GLfloat)rand()/(RAND_MAX+1.0);
			gF=(GLfloat)rand()/(RAND_MAX+1.0);
			bF=(GLfloat)rand()/(RAND_MAX+1.0);
			glutPostRedisplay();
		}
		else{
			rL=(GLfloat)rand()/(RAND_MAX+1.0);
			gL=(GLfloat)rand()/(RAND_MAX+1.0);
			bL=(GLfloat)rand()/(RAND_MAX+1.0);
			glutPostRedisplay();
		}
	  //COLOCA AQUI A FUNÇÃAAÃAOOAOAAO
	}
	break;
  }
}

void draw(GLint xx, GLint xy, GLint yx, GLint yy){
	glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(rF, gF, bF);
  glBegin(GL_POLYGON);
  glVertex2i(xx,xy);  glVertex2i(yx,xy);
  glVertex2i(yx,yy); glVertex2i(xx,yy); 
  glEnd();

	glPolygonMode(GL_BACK, GL_LINE);
  glColor3f(rL, gL, bL);
  glBegin(GL_POLYGON);
  glVertex2i(xx,xy);  glVertex2i(yx,xy);
  glVertex2i(yx,yy); glVertex2i(xx,yy); 
  glEnd();
}
