#include <GL/glut.h>
#include <iostream>
using namespace std;

int xd = 0, yd = 0;
void polygonTriangle() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.8, 0.5, 0.6);
	glPointSize(3);
	glBegin(GL_POLYGON);
	glVertex2i(10 + xd, 10 + yd);
	glVertex2i(20 + xd, 10 + yd);
	glVertex2i(20 + xd, 0 + yd);
	glVertex2i(10 + xd, 0 + yd);
	glEnd();
	glFlush();
}

void myKeyBoard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 'w':yd++; break;
	case 's':yd--; break;
	case 'a':xd--; break;
	case 'd':xd++; break;
	}
	glutPostRedisplay();
}

void init() {
	glClearColor(1, 1, 1, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20, 30, -20, 30);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 100);
	glutInitWindowSize(600, 500);
	glutCreateWindow("Key Motion");

	init();
	glutDisplayFunc(polygonTriangle);
	glutKeyboardFunc(myKeyBoard);
	glutMainLoop();
	cout << "ddd" << endl;
	return 0;
}