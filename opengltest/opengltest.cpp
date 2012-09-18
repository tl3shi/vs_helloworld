#include "stdafx.h"
#include <iostream>
#include <GL/glut.h>
#include <math.h>

using namespace std;

void drawOneLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
	glBegin(GL_LINES); 
	glVertex2f(x1, y1); 
	glVertex2f(x2, y2); 
	glEnd();
}

void getLine(void)
{
	//�߶�1
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);//��ɫ�߶�
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0x0101); //����
	drawOneLine(50.0, 125.0, 150.0, 125.0);
	glLineStipple(1, 0x00FF); //�㻮��
	drawOneLine(150.0, 125.0, 250.0, 125.0);
	glLineStipple(1, 0x1C47); //���
	drawOneLine(250.0, 125.0, 350.0, 125.0);

	//�߶�2
	//�߶α��
	glLineWidth(5.0);
	glLineStipple(1, 0x0101); //����
	drawOneLine(50.0, 150.0, 150.0, 150.0);
	glLineStipple(1, 0x00FF); //�㻮��
	drawOneLine(150.0, 150.0, 250.0, 150.0);
	glLineStipple(1, 0x1C47); //���
	drawOneLine(250.0, 150.0, 350.0, 150.0);
	glLineWidth(1.0);
	//�߶�3
	glLineStipple(1, 0x1C47);
	glBegin(GL_LINE_STRIP);
	for (int i=0; i<7; ++i)
	{
		glVertex2f(50.0 + ((GLfloat)i * 50), 75.0);
	}
	glEnd();
	//�߶�4
	glLineStipple(5, 0x1C47);
	drawOneLine(50.0, 25.0, 350.0, 25.0);
	glDisable(GL_LINE_STIPPLE);
	glFlush();
}
void getCircle()
{
	int i;
	int n = 20;
	float R = 0.5f;
	float Pi = 3.1415f;
	glBegin(GL_POLYGON);
	for(i=0; i<n; ++i)
		glVertex2f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i));
	glEnd();
	glFlush();
}
void getRect(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	cout << "hello world" <<endl;
	glFlush();
}
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);//�������ɫ����Ϊ��ɫ
	glMatrixMode(GL_FLAT); 
}
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("OpenGL Demo");
	init();
	glutDisplayFunc(&getRect);
	//glutReshapeFunc(&reshape);//getLine��ʱ���reshape�������Ĳ�
	glutMainLoop();
	return 0;
}