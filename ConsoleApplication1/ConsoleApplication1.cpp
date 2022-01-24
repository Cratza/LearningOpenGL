#include <GL/glut.h>
#include <iostream>

GLint w = 600, h = 500;
int xd = 0, yd = 0;

void polygonTriangle() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.8, 0.5, 0.6);
	glPointSize(3);
	glBegin(GL_POLYGON);
	glVertex2i(10 + xd, 10 + yd);
	glVertex2i(10 + xd, 100 + yd);
	glVertex2i(100 + xd, 100 + yd);
	glVertex2i(100 + xd, 10 + yd);
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

void mouseMotion(GLint button, GLint state, GLint x, GLint y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		xd = x; yd = h-y;
		glutPostRedisplay();
	}
}

void init() {
	glClearColor(1, 1, 1, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-20, w, -20, h);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(200, 100);
	glutInitWindowSize(w, h);
	glutCreateWindow("Mouse Interaction");

	init();
	glutDisplayFunc(polygonTriangle);
	glutKeyboardFunc(myKeyBoard);
	glutMouseFunc(mouseMotion);
	glutMainLoop();
	return 0;
}