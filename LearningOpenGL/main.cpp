#include "main.h"
#include <GL/glut.h>
#include <iostream>
using namespace std;

void myPoints(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(3);
	glBegin(GL_POINTS);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(-3,3);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2i(10, 20);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2i(0, -15);
	glEnd();
	glFlush();
}

void init(){
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char* argv[]){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(200,300);
	glutInitWindowSize(300,300);
	glutCreateWindow("Display Points");


	init();
	glutDisplayFunc(myPoints);
	glutMainLoop();
	cout << "ddd" << endl;
	return 0;
}
