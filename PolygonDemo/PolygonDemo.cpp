#include <GL/glut.h>
#include <iostream>
using namespace std;

void polygonTriangle() {
	int p1[] = { 1,3 };
	int p2[] = { 3,0 };
	int p3[] = { 6,0 };
	int p4[] = { 7,3 };
	int p5[] = { 6,6 };
	int p6[] = { 3,6 };
	int p7[] = { 4,8 };
	int p8[] = { 5,8 };

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.6, 0.5, 0.2);
	glPointSize(3);
	//glBegin(GL_TRIANGLES);
	//glBegin(GL_POLYGON);
	glBegin(GL_QUADS);

	glVertex2iv(p1);
	glVertex2iv(p2);
	glVertex2iv(p3);
	glVertex2iv(p4);
	glVertex2iv(p5);
	glVertex2iv(p6);
	glVertex2iv(p7);
	glVertex2iv(p8);

	glEnd();
	glFlush();
}

void init() {
	glClearColor(1, 1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-10, 20, -10, 20);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(200, 300);
	glutInitWindowSize(300, 300);
	glutCreateWindow("Display Points");


	init();
	glutDisplayFunc(polygonTriangle);
	glutMainLoop();
	cout << "ddd" << endl;
	return 0;
}