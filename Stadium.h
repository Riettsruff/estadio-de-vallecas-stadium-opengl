#include <GL/freeglut.h>
#include "dark_brown_object.h"
#include "dark_grey_object_part_1.h"
#include "dark_grey_object_part_2.h"
#include "green_object_part_1.h"
#include "green_object_part_2.h"
#include "green_object_part_3.h"
#include "green_object_part_4.h"
#include "red_object.h"
#include "smooth_brown_object_part_1.h"
#include "smooth_brown_object_part_2.h"
#include "smooth_grey_object_part_1.h"
#include "smooth_grey_object_part_2.h"
#include "smooth_grey_object_part_3.h"
#include "white_object_part_1.h"
#include "white_object_part_2.h"
#include "yellow_object.h"

class Stadium {
	float xrot = 0;
	float yrot = 0;
	float xdiff = 0;
	float ydiff = 0;
	bool mousedown = false;
	bool isColorOneActive = false;

	public:
		void handleMouseButton(int button, int state, int x, int y) {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
				mousedown = true;
				xdiff = x - yrot;
				ydiff = -y + xrot;
			} else {
				mousedown = false;
			}

			glutPostRedisplay();
		}

		void handleMouseMove(int x, int y) {
			if (mousedown) {
				yrot = x - xdiff;
				xrot = y + ydiff;

				glutPostRedisplay();
			}
		}

		void handleKeyboard(unsigned char key, int x, int y) {
			switch (key) {
				case 'a':
				case 'A':
					// bergeser ke kiri
					glTranslatef(-1.0, 0.0, 0.0);
					break;
				case 'd':
				case 'D':
					// bergeser ke kanan
					glTranslatef(1.0, 0.0, 0.0);
					break;
				case 'w':
				case 'W':
					// bergeser ke atas
					glTranslatef(0.0, 1.0, 0.0);
					break;
				case 's':
				case 'S':
					// bergeser ke bawah
					glTranslatef(0.0, -1.0, 0.0);
					break;
				case 'x':
				case 'X':
					// berotasi ke kanan
					glRotatef(1.0, 0.0, 0.0, -5.0);
					break;
				case 'z':
				case 'Z':
					// berotasi ke kiri
					glRotatef(1.0, 0.0, 0.0, 5.0);
					break;
				case 'c':
				case 'C':
					// perbesar
					glTranslatef(0.0, 0.0, 5.0);
					break;
				case 'v':
				case 'V':
					// perkecil
					glTranslatef(0.0, 0.0, -5.0);
					break;
			}

			glutPostRedisplay();
		}

		void reshape(int w, int h) {
			if (h == 0) h = 1;

			GLfloat aspect = (GLfloat)w / (GLfloat)h;
			glViewport(0, 25, w, h);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(45.0f, aspect, 0.1f, -1.0f);
		}

		void handleTimer(int) {
			isColorOneActive = !isColorOneActive;
			glutPostRedisplay();
		}

		void display() {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glPushMatrix();
			gluLookAt(-75, 75, 150, 0, 0, 0, 0, 1, 0);
			glRotatef(xrot, 1, 0, 0);
			glRotatef(yrot, 0, 1, 0);

			if (isColorOneActive) glClearColor(0.2, 0.6, 0.7, 1.0);
			else glClearColor(0.2, 0.4, 0.5, 1.0);

			darkBrownObject();
			darkGreyObjectPart1();
			darkGreyObjectPart2();
			greenObjectPart1();
			greenObjectPart2();
			greenObjectPart3();
			greenObjectPart4();
			redObject();
			smoothBrownObjectPart1();
			smoothBrownObjectPart2();
			smoothGreyObjectPart1();
			smoothGreyObjectPart2();
			smoothGreyObjectPart3();
			whiteObjectPart1();
			whiteObjectPart2();
			yellowObject();

			glPopMatrix();
			glutSwapBuffers();
		}
};