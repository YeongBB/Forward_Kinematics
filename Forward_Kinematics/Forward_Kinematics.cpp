#include <GL/glut.h>

GLint x1 = 0, x2 = 0;


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(-1.0, -1.2, 0.0);
	glColor3f(0.4, 0.5, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, 0.3, 0);
	glVertex3f(-0.5, -0.3, 0);
	glVertex3f(0.5, -0.3, 0);
	glVertex3f(0.5, 0.3, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.0, -0.6, 0.0);
	glColor3f(0.4, 0.5, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.2, 0.3, 0);
	glVertex3f(-0.2, -0.3, 0);
	glVertex3f(0.2, -0.3, 0);
	glVertex3f(0.2, 0.3, 0);
	glEnd();
	glTranslatef(0.0, 0.6, 0.0);
	glColor3f(0.3, 0.6, 0.5);
	glutWireSphere(0.3, 100, 100);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef(x1, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_POLYGON);
	glVertex3f(-0.7, 0.2, 0);
	glVertex3f(-0.7, -0.2, 0);
	glVertex3f(0.7, -0.2, 0);
	glVertex3f(0.7, 0.2, 0);
	glEnd();
	glPopMatrix();

	glTranslatef(1.0, 0, 0);
	glPushMatrix();
	glColor3f(0.3, 0.6, 0.5);
	glutWireSphere(0.3, 100, 100);
	glPopMatrix();
	glRotatef(x2, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(0.4, 0.4, 0.4);
	glBegin(GL_POLYGON);
	glVertex3f(-0.7, 0.2, 0);
	glVertex3f(-0.7, -0.2, 0);
	glVertex3f(0.7, -0.2, 0);
	glVertex3f(0.7, 0.2, 0);
	glEnd();
	glPopMatrix();

	glTranslatef(0.7, 0.0, 0.0);
	glColor3f(0.02, 0.4, 0.5);
	glPushMatrix();
	glBegin(GL_POLYGON);

	glVertex3f(0.0, 0.3, 0);
	glVertex3f(0.4, 0.3, 0);
	glVertex3f(0.4, 0.1, 0);
	glVertex3f(0.2, 0.1, 0);
	glVertex3f(0.2, 0.0, 0);
	glVertex3f(0.0, 0.0, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(0.0, -0.3, 0);
	glVertex3f(0.4, -0.3, 0);
	glVertex3f(0.4, -0.1, 0);
	glVertex3f(0.2, -0.1, 0);
	glVertex3f(0.2, 0.0, 0);
	glVertex3f(0.0, 0.0, 0);
	glEnd();
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glTranslatef(0.0, 0.0, -7.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		x1 = x1 + 5;
		break;
	case 'a':
		x1 = x1 - 5;
		break;
	case 'w':
		x2 = x2 + 5;
		break;
	case 's':
		x2 = x2 - 5;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Foward Kinematocs");
	glClearColor(6.0, 0.6, 0.6, 0.0);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}