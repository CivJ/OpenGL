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
void drawSierpinski(GLIntPoint*, int);
const int HEIGHT = 480;
int main(int argc, char** argv){

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640,HEIGHT);
  glutInitWindowPosition(100,150);
  glutCreateWindow("Sierpinski");

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

void drawSierpinski(GLIntPoint* points, int length){

  int index = random() % length;

  GLIntPoint point = points[index];

  drawDot(point);
  for(int i =0; i<10000; i++){
    index = random() % length;
    point.x = (point.x + points[index].x)/2;
    point.y = (point.y + points[index].y)/2;
    drawDot(point);
  }
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

  const int size = 3;
  static int clickCount = 0;
  static GLIntPoint points[size];
  
  if(button == GLUT_LEFT_BUTTON && 
     state == GLUT_DOWN &&
     clickCount < size){
    
    points[clickCount].x = x;
    points[clickCount].y = HEIGHT - y;
    drawDot(points[clickCount]);
    clickCount++;
    if(clickCount == size){
      drawSierpinski(points,size);
    }
  }
}

void myKeyboard(unsigned char c, int i, int j){

}

