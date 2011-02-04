#include<OpenGl/Gl.h>
#include<OpenGl/Glu.h>
#include<GLUT/glut.h>
#include<iostream>

class GLIntPoint{
public:
  GLint x, y;
};

void myInit();
void myDisplay();
void myReshape(int, int);
void myMouse(int, int, int, int);
void myKeyboard(unsigned char, int, int);
void drawDot(GLIntPoint p);
const int HEIGHT = 480;
const int WIDTH = 640;
int main(int argc, char** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,150);
  glutCreateWindow("Template");

  glutDisplayFunc(myDisplay);
  glutReshapeFunc(myReshape);
  glutMouseFunc(myMouse);
  glutKeyboardFunc(myKeyboard);

  myInit();

  glutMainLoop();
  return 0;
}
void myInit(){
  glClearColor(0.0,0.0,0.0,0.0);
  glColor3f(1.0f, 1.0f, 1.0f);
  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void myDisplay(){
  glClear(GL_COLOR_BUFFER_BIT);
  //glBegin(GL_POINTS);
  //glEnd();
  glFlush();
}

void drawDot(GLIntPoint p){
  glBegin(GL_POINTS);
  glVertex2i(p.x, p.y);
  glEnd();
  glFlush();

}

void myReshape(int i, int j){

}

void myMouse(int button, int state, int x, int y){

}

void myKeyboard(unsigned char c, int i, int j){

}

