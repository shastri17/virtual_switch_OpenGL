#ifdef __APPLE__
#include <GLUT/glut.h>
#include<OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif
#include<iostream>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define title 0
#define circuit 1
#define packet 2
#define quit 3
int obj;
int posX,posY,posZ;
char str[50];
using namespace std;
void menu_select(int item){
    obj = item;
    glutPostRedisplay();
}

void drawstring (float x,float y,const char *s) {
 const char *c;
    glRasterPos2f(x, y);
    for (c=s; *c != '\0'; c++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);

};
void drawchar (float x,float y,const char *s) {
 const char *c;
    glRasterPos2f(x, y);
    for (c=s; *c != '\0'; c++)
    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);

};
 void frontscreen(void)
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0,0.6,0.9);
 drawstring(30.0,90.0,"PES INSTITUTE OF TECHNOLOGY, BANGALORE SOUTH CAMPUS");
 glColor3f(0.7,0,1);
 drawstring(32,82,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
 glColor3f(1,0.5,0);
 drawstring(42,70,"A MINI PROJECT ON");
 glColor3f(1,0,0);
 drawstring(35,60,"VIRTUAL CIRCUIT SWITCHING NETWORK");
 glColor3f(1,0.5,0);
 drawstring(27,50,"BY:");
 glColor3f(0.9,0,0.5);
 drawstring(27,45,"GANESHPRASAD 1PE14CS041");
 drawstring(27,40,"HARSHA VAMSI 1PE14CS047");
 glColor3f(1,0.5,0);
 drawstring(63,50,"UNDER THE GUIDANCE OF: ");
 glColor3f(0.9,0,0.5);
 drawstring(63,45,"MS.SHUBHA RAJ");
 drawstring(63,40,"DR.SARASVATHI");

 glColor3f(1,0.1,1);

 drawstring(39,18,"PRESS ENTER TO START");
 glFlush();
}
string input = "";
void fdisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);

}
void computer(void){
    glClear(GL_COLOR_BUFFER_BIT);
    //sender
    glColor3f(0.7,0.2,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(10,45);
    glVertex2f(10,55);
    glVertex2f(20,55);
    glVertex2f(20,45);
    glEnd();
    glColor3f(1,0.1,1);
    drawstring(13,50,"Sender");
    glColor3f(0.7,0.2,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(10.5,46);
    glVertex2f(10.5,54);
    glVertex2f(19.5,54);
    glVertex2f(19.5,46);
    glEnd();
    glColor3f(0.7,0.0,0.2);
    glBegin(GL_LINES);
    glVertex2f(14,45);
    glVertex2f(14,43);
    glVertex2f(16,43);
    glVertex2f(16,45);
    glEnd();
    glColor3f(0.7,0.3,0.2);
    glBegin(GL_QUADS);
    glVertex2f(13,42);
    glVertex2f(13,43);
    glVertex2f(17,43);
    glVertex2f(17,42);
    glEnd();

//drawing switch
glColor3f(0.7,0.0,0.2);
glBegin(GL_QUADS);
glVertex2f(30,70);
glVertex2f(30,75);
glVertex2f(35,75);
glVertex2f(35,70);
glEnd();

glColor3f(0.7,0.0,0.2);
glBegin(GL_QUADS);
glVertex2f(30,30);
glVertex2f(30,35);
glVertex2f(35,35);
glVertex2f(35,30);
glEnd();

glColor3f(0.7,0.0,0.2);
glBegin(GL_QUADS);
glVertex2f(60,70);
glVertex2f(60,75);
glVertex2f(65,75);
glVertex2f(65,70);
glEnd();

glColor3f(0.7,0.0,0.2);
glBegin(GL_QUADS);
glVertex2f(60,30);
glVertex2f(60,35);
glVertex2f(65,35);
glVertex2f(65,30);
glEnd();

//reciever
glColor3f(0.7,0.2,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(75,45);
glVertex2f(75,55);
glVertex2f(85,55);
glVertex2f(85,45);
glEnd();
glColor3f(1,0.1,1);
drawstring(78,50,"Receiver");
glColor3f(0.7,0.2,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(75.5,46);
glVertex2f(75.5,54);
glVertex2f(84.5,54);
glVertex2f(84.5,46);
glEnd();

glColor3f(0.7,0.0,0.2);
glBegin(GL_LINES);
glVertex2f(79,45);
glVertex2f(79,43);
glVertex2f(81,43);
glVertex2f(81,45);
glEnd();

glColor3f(0.7,0.3,0.2);
glBegin(GL_QUADS);
glVertex2f(78,42);
glVertex2f(78,43);
glVertex2f(82,43);
glVertex2f(82,42);
glEnd();

//draw lines
glColor3f(0.7,0.6,0.2);
glBegin(GL_LINES);
glVertex2f(15,42);
glVertex2f(15,32.5);
glVertex2f(15,32.5);
glVertex2f(30,32.5);
glVertex2f(32.5,35);
glVertex2f(32.5,70);
glVertex2f(35,72.5);
glVertex2f(60,72.5);
glVertex2f(62.5,70);
glVertex2f(62.5,35);
glVertex2f(35,32.5);
glVertex2f(60,32.5);
glVertex2f(65,32.5);
glVertex2f(80,32.5);
glVertex2f(80,32.5);
glVertex2f(80,42);
glVertex2f(35,70);
glVertex2f(60,35);
glVertex2f(35,35);
glVertex2f(60,70);
glEnd();

glFlush();
}

void path1(){ //bottom
for(int j=0;j<strlen(str);j++){
    float toplx=15.3;
    float topty=42;
    float toprx=16.3;
    float topby=40;
for(int i=0;i<7;i++)
{
    computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx,topby-i);
glVertex2f(toplx,topty-i);
glVertex2f(toprx,topty-i);
glVertex2f(toprx,topby-i);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(15.4,topty-1.4-i,&x);
glFlush();
usleep(10);
}
 toplx=15.3;
 topty=35;
 toprx=16.3;
 topby=33;
for(int i=0;i<63;i++)
{
    computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx+i,topby);
glVertex2f(toplx+i,topty);
glVertex2f(toprx+i,topty);
glVertex2f(toprx+i,topby);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(toprx-0.8+i,33.5,&x);
glFlush();
usleep(10);
}
toplx=78.7;
topty=35;
toprx=79.7;
topby=33;
for(int i=0;i<8;i++)
{
    computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx,topby+i);
glVertex2f(toplx,topty+i);
glVertex2f(toprx,topty+i);
glVertex2f(toprx,topby+i);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(79,topty-1.5+i,&x);
glFlush();
usleep(10);
}
computer();
}
}

void path2(){ //top
for(int j=0;j<strlen(str);j++){
    float toplx=15.3;
    float topty=42;
    float toprx=16.3;
    float topby=40;
for(int i=0;i<7;i++)
{
    computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx,topby-i);
glVertex2f(toplx,topty-i);
glVertex2f(toprx,topty-i);
glVertex2f(toprx,topby-i);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(15.4,topty-1.4-i,&x);
glFlush();
usleep(10);
}
 toplx=15.3;
 topty=35;
 toprx=16.3;
 topby=33;
for(int i=0;i<16;i++)
{
    computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx+i,topby);
glVertex2f(toplx+i,topty);
glVertex2f(toprx+i,topty);
glVertex2f(toprx+i,topby);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(toprx-0.8+i,33.5,&x);
glFlush();
usleep(1);
}
toplx=31.3;
topty=35;
toprx=32.3;
topby=33;
for(int i=0;i<40;i++)
{
    computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx,topby+i);
glVertex2f(toplx,topty+i);
glVertex2f(toprx,topty+i);
glVertex2f(toprx,topby+i);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(31.5,topty-1.3+i,&x);
glFlush();
usleep(1);
}

toplx=31.3;
topty=75;
toprx=32.3;
topby=73;
for(int i=0;i<31;i++)
{
   computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx+i,topby);
glVertex2f(toplx+i,topty);
glVertex2f(toprx+i,topty);
glVertex2f(toprx+i,topby);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(toplx+0.2+i,73.6,&x);
glFlush();
usleep(1);
}


toplx=62.8;
topty=75;
toprx=63.8;
topby=73;
for(int i=0;i<40;i++)
{
computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx,topby-i);
glVertex2f(toplx,topty-i);
glVertex2f(toprx,topty-i);
glVertex2f(toprx,topby-i);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(63,topby+0.2-i,&x);
glFlush();
usleep(1);
}
toplx=63;
topty=35;
toprx=64;
topby=33;
for(int i=0;i<16;i++)
{
   computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx+i,topby);
glVertex2f(toplx+i,topty);
glVertex2f(toprx+i,topty);
glVertex2f(toprx+i,topby);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(toplx+0.2+i,33.5,&x);
glFlush();
usleep(1);
}
toplx=78.7;
topty=35;
toprx=79.7;
topby=33;
for(int i=0;i<8;i++)
{
    computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx,topby+i);
glVertex2f(toplx,topty+i);
glVertex2f(toprx,topty+i);
glVertex2f(toprx,topby+i);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(79,topty-1.5+i,&x);
glFlush();
usleep(10);
}
computer();
}
}

void path3()// top-diagonal
{

  for(int j=0;j<strlen(str);j++){
      float counter = 1.0;
      float toplx=15.3;
      float topty=42;
      float toprx=16.3;
      float topby=40;
  for(int i=0;i<7;i++)
  {
      computer();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_QUADS);
  glVertex2f(toplx,topby-i);
  glVertex2f(toplx,topty-i);
  glVertex2f(toprx,topty-i);
  glVertex2f(toprx,topby-i);
  glEnd();
  glFlush();
  char x = str[j];
  glColor3f(1.0,0.0,0.0);
  drawchar(15.4,topty-1.4-i,&x);
  glFlush();
  usleep(10);
  }
   toplx=15.3;
   topty=35;
   toprx=16.3;
   topby=33;
  for(int i=0;i<16;i++)
  {
      computer();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_QUADS);
  glVertex2f(toplx+i,topby);
  glVertex2f(toplx+i,topty);
  glVertex2f(toprx+i,topty);
  glVertex2f(toprx+i,topby);
  glEnd();
  glFlush();
  char x = str[j];
  glColor3f(1.0,0.0,0.0);
  drawchar(toprx-0.8+i,33.5,&x);
  glFlush();
  usleep(1);
  }
  toplx=31.3;
  topty=35;
  toprx=32.3;
  topby=33;
  for(int i=0;i<40;i++)
  {
      computer();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_QUADS);
  glVertex2f(toplx,topby+i);
  glVertex2f(toplx,topty+i);
  glVertex2f(toprx,topty+i);
  glVertex2f(toprx,topby+i);
  glEnd();
  glFlush();
  char x = str[j];
  glColor3f(1.0,0.0,0.0);
  drawchar(31.5,topty-1.3+i,&x);
  glFlush();
  usleep(1);
  }
//diagonal
  toplx=32.3;
  topty=75;
  toprx=33.3;
  topby=73;

  for(int i=0; i<41;i++)
  {
      computer();

  glColor3f(1.0,1.0,1.0);
  glBegin(GL_QUADS);
  glVertex2f(toplx+(counter),topby-i);
  glVertex2f(toplx+(counter),topty-i);
  glVertex2f(toprx+(counter),topty-i);
  glVertex2f(toprx+(counter),topby-i);
  glEnd();
  glFlush();
  char x = str[j];
  glColor3f(1.0,0.0,0.0);
  drawchar(toprx+(counter)-0.8,topty-1.5-i,&x);
  glFlush();
  counter +=0.7;
  usleep(1);
  }
  toplx=63;
  topty=35;
  toprx=64;
  topby=33;
  for(int i=0;i<16;i++)
  {
     computer();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_QUADS);
  glVertex2f(toplx+i,topby);
  glVertex2f(toplx+i,topty);
  glVertex2f(toprx+i,topty);
  glVertex2f(toprx+i,topby);
  glEnd();
  glFlush();
  char x = str[j];
  glColor3f(1.0,0.0,0.0);
  drawchar(toplx+0.2+i,33.5,&x);
  glFlush();
  usleep(1);
  }
  toplx=78.7;
  topty=35;
  toprx=79.7;
  topby=33;
  for(int i=0;i<8;i++)
  {
      computer();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_QUADS);
  glVertex2f(toplx,topby+i);
  glVertex2f(toplx,topty+i);
  glVertex2f(toprx,topty+i);
  glVertex2f(toprx,topby+i);
  glEnd();
  glFlush();
  char x = str[j];
  glColor3f(1.0,0.0,0.0);
  drawchar(79,topty-1.5+i,&x);
  glFlush();
  usleep(10);
}



}
computer();
}

void path4() {

  for(int j=0;j<strlen(str);j++){
      float counter = 1.0;
      float toplx=15.3;
      float topty=42;
      float toprx=16.3;
      float topby=40;
  for(int i=0;i<7;i++)
  {
      computer();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_QUADS);
  glVertex2f(toplx,topby-i);
  glVertex2f(toplx,topty-i);
  glVertex2f(toprx,topty-i);
  glVertex2f(toprx,topby-i);
  glEnd();
  glFlush();
  char x = str[j];
  glColor3f(1.0,0.0,0.0);
  drawchar(15.4,topty-1.4-i,&x);
  glFlush();
  usleep(10);
  }
   toplx=15.3;
   topty=35;
   toprx=16.3;
   topby=33;
  for(int i=0;i<16;i++)
  {
      computer();
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_QUADS);
  glVertex2f(toplx+i,topby);
  glVertex2f(toplx+i,topty);
  glVertex2f(toprx+i,topty);
  glVertex2f(toprx+i,topby);
  glEnd();
  glFlush();
  char x = str[j];
  glColor3f(1.0,0.0,0.0);
  drawchar(toprx-0.8+i,33.5,&x);
  glFlush();
  usleep(1);
  }
//bottom diagonal

toplx=31.3;
topty=35;
toprx=32.3;
topby=33;

for(int i=0; i<40;i++)
{

    computer();

glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx+counter,topby+i);
glVertex2f(toplx+counter,topty+i);
glVertex2f(toprx+counter,topty+i);
glVertex2f(toprx+counter,topby+i);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(toprx+(counter)-0.7,topty-1.2+i,&x);
glFlush();
counter +=0.7;
usleep(1000);
}

toplx=62.8;
topty=75;
toprx=63.8;
topby=73;
for(int i=0;i<40;i++)
{
computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx,topby-i);
glVertex2f(toplx,topty-i);
glVertex2f(toprx,topty-i);
glVertex2f(toprx,topby-i);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(63,topby+0.2-i,&x);
glFlush();
usleep(1);
}
toplx=63;
topty=35;
toprx=64;
topby=33;
for(int i=0;i<16;i++)
{
   computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx+i,topby);
glVertex2f(toplx+i,topty);
glVertex2f(toprx+i,topty);
glVertex2f(toprx+i,topby);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(toplx+0.2+i,33.5,&x);
glFlush();
usleep(1);
}
toplx=78.7;
topty=35;
toprx=79.7;
topby=33;
for(int i=0;i<8;i++)
{
    computer();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2f(toplx,topby+i);
glVertex2f(toplx,topty+i);
glVertex2f(toprx,topty+i);
glVertex2f(toprx,topby+i);
glEnd();
glFlush();
char x = str[j];
glColor3f(1.0,0.0,0.0);
drawchar(79,topty-1.5+i,&x);
glFlush();
usleep(10);
}




  }

  computer();

}



void packettransfer(){
    int x = rand()%4;
    if(x==0)
    path1();
    else if(x==1)
    path2();
    else if(x==2)
    path3();
    else
    path4();

}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    switch(obj){
        case title:
            frontscreen();
            break;
        case circuit:
            computer();
            break;
        case packet:
            packettransfer();
            break;


    }

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
    cout<<"Enter string: ";
    gets(str);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Virtual Circuit Switch Network");
    myinit();
    glutDisplayFunc(display);
    glutCreateMenu(menu_select);

      // Add menu items
      glutAddMenuEntry("title", title);
      glutAddMenuEntry("circuit", circuit);
      glutAddMenuEntry("packettransfer", packet);
      glutAddMenuEntry("quit", quit);

      // Associate a mouse button with menu
      glutAttachMenu(GLUT_RIGHT_BUTTON);


//	glutKeyboardFunc(keys);
	glutMainLoop();
    glFlush();
	return 0;
	}
