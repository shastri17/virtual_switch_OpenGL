#include<GL/glut.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;
int flag=0;

void drawstring (float x,float y,const char *s) {   
 const char *c;
    glRasterPos2f(x, y);
    for (c=s; *c != '\0'; c++) 
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);

};
 void frontscreen(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0,1);
 drawstring(45.0,90.0,"PESIT-BSC ");
 glColor3f(0.7,0,1);
 drawstring(35,82,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
 glColor3f(1,0.5,0);
 drawstring(43,70,"A MINI PROJECT ON");
 glColor3f(1,0,0);
 drawstring(38,60,"VIRTUAL CIRCUIT SWITCHING NETWORK");
 glColor3f(1,0.5,0);
 drawstring(35,50,"BY:");
 glColor3f(0.5,0,0.5);
 drawstring(40,45,"GANESHPRASAD 1PE14CS041");
 drawstring(40,40,"HARSHA VAMSI 1PE14CS047");
 glColor3f(1,0.5,0);
 
 glColor3f(1,0.1,1);
 drawstring(42,20,"PRESS ENTER TO START");
 glFlush();
}



void mydisplay(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 if(flag==0)
  frontscreen();
 if(flag==1)
  glClearColor(1.0,1.0,1.0,1.0); 
}

void key( unsigned char key, int x, int y )

{
 switch(key)
 {
 case 13:if(flag==0)
    flag=1;
  break;
       }
    mydisplay();
}

void myinit()
{
glClearColor(0.0,0.0,0.0,0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,100,0,100);
}

int main(int argc, char** argv)
	{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("ckt");
	glutDisplayFunc(mydisplay);
	glutKeyboardFunc(key);
	myinit();
	glutMainLoop();
	return 0;
	}
