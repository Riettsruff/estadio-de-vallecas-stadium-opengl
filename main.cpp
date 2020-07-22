#include <GL/freeglut.h>
#include "Stadium.h"

// TOPIC - RAYO VALLECANO STADIUM

Stadium rayoVallecano;

void handleMouseButtonWrapper(int button, int state, int x, int y) {
	rayoVallecano.handleMouseButton(button, state, x, y);
}

void handleMouseMoveWrapper(int x, int y) {
	rayoVallecano.handleMouseMove(x, y);
}

void handleKeyboardWrapper(unsigned char key, int x, int y) {
	rayoVallecano.handleKeyboard(key, x, y);
}

void reshapeWrapper(int w, int h) {
	rayoVallecano.reshape(w, h);
}

void displayWrapper() {
	rayoVallecano.display();
}

void handleTimerWrapper(int x) {
	rayoVallecano.handleTimer(x);
	glutTimerFunc(600, handleTimerWrapper, 0);
}

void initGL() {
	glClearColor(0.3, 0.6, 0.5, 1.0);
	glLineWidth(2);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutCreateWindow("TR GRAFIKA KOMPUTER ASDOS");
	initGL();
	glutDisplayFunc(displayWrapper);
	glutReshapeFunc(reshapeWrapper);
	glutKeyboardFunc(handleKeyboardWrapper);
	glutMouseFunc(handleMouseButtonWrapper);
	glutMotionFunc(handleMouseMoveWrapper);
	glutTimerFunc(600, handleTimerWrapper, 0);

	glutMainLoop();
	return 0;
}