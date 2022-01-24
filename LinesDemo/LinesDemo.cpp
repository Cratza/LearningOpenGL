#include <GL/glut.h>
#include <iostream>
using namespace std;

void lines() {
	int p1[] = { 6,4 };
	int p2[] = { 1,1 };
	int p3[] = { 3,7 };
	int p4[] = { 5,1 };
	int p5[] = { 0,4 };

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3, 0.1, 0.8);
	glPointSize(3);
	//glBegin(GL_POINTS);
	//glBegin(GL_LINES);
	//glBegin(GL_LINE_STRIP);
	glBegin(GL_LINE_LOOP);
	
	glVertex2iv(p1);
	glVertex2iv(p2);
	glVertex2iv(p3);
	glVertex2iv(p4);
	glVertex2iv(p5);

	glEnd();
	glFlush();
}

void init() {
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10,20,-10,20);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(200, 300);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Display Points");


	init();
	glutDisplayFunc(lines);
	glutMainLoop();
	cout << "ddd" << endl;
	return 0;
}
