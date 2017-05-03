#ifdef __APPLE__
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#else
#include <GL/glut.h>
#endif
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//menu items

#define title 0
#define circuit 1
#define packet 2
#define quit 3

int obj;
int posX,posY,posZ;
char str[50]; //input string
int complete = 0; //check if path is completed
using namespace std;

void menu_select(int item){
        obj = item;
        glutPostRedisplay();
}

int transfer[30] = {0}; // check if line is completed
int switchcolor[4] = {0}; //check if switch is completed

void drawstring (float x,float y,const char *s) { //draw text
        const char *c;
        glRasterPos2f(x, y);
        for (c=s; *c != '\0'; c++)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);

};

void drawchar (float x,float y,const char *s) { //draw individual character
        const char *c;
        glRasterPos2f(x, y);
        for (c=s; *c != '\0'; c++)
                glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);

};

void frontscreen(void)  //display title text
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
        drawstring(39,18,"RIGHT CLICK FOR OPTIONS");
        glFlush();
}

void computer(void){
        glClear(GL_COLOR_BUFFER_BIT);
        int ll = 1;
        if(complete == 0) { // check if circuit is completed
                for(int j=0; j<strlen(str); j++) {
                        glColor3f(1.0,1.0,1.0);
                        glBegin(GL_QUADS);
                        glVertex2f(9+ll,56);
                        glVertex2f(9+ll,58);
                        glVertex2f(10+ll,58);
                        glVertex2f(10+ll,56);
                        glEnd();
                        char x = str[j];
                        glColor3f(1.0,0.0,0.0);
                        drawchar(9.2+ll,56.2,&x);
                        ll+=2;
                }
        }
        // display title
        glColor3f(0,0.6,0.9);
        drawstring(42.0,90.0,"PACKET TRANSFER");

        // draw sender computer
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

//draw switch 1
        if(switchcolor[1] == 0) {
                glColor3f(0.7,0.0,0.2); //s1
                glBegin(GL_QUADS);
                glVertex2f(30,70);
                glVertex2f(30,75);
                glVertex2f(35,75);
                glVertex2f(35,70);
                glEnd();
        }
        else{
                glColor3f(0,0.6,0.9); //s1
                glBegin(GL_QUADS);
                glVertex2f(30,70);
                glVertex2f(30,75);
                glVertex2f(35,75);
                glVertex2f(35,70);
                glEnd();
        }
//draw switch 2
        if(switchcolor[2] == 0) {
                glColor3f(0.7,0.0,0.2);//s2
                glBegin(GL_QUADS);
                glVertex2f(30,30);
                glVertex2f(30,35);
                glVertex2f(35,35);
                glVertex2f(35,30);
                glEnd();
        }
        else{
                glColor3f(0,0.6,0.9);//s2
                glBegin(GL_QUADS);
                glVertex2f(30,30);
                glVertex2f(30,35);
                glVertex2f(35,35);
                glVertex2f(35,30);
                glEnd();
        }
//draw switch 3
        if(switchcolor[3] == 0) {
                glColor3f(0.7,0.0,0.2);//s3
                glBegin(GL_QUADS);
                glVertex2f(60,70);
                glVertex2f(60,75);
                glVertex2f(65,75);
                glVertex2f(65,70);
                glEnd();
        }
        else{
                glColor3f(0,0.6,0.9);//s3
                glBegin(GL_QUADS);
                glVertex2f(60,70);
                glVertex2f(60,75);
                glVertex2f(65,75);
                glVertex2f(65,70);
                glEnd();
        }
//draw switch 4
        if(switchcolor[4] == 0) {
                glColor3f(0.7,0.0,0.2);//s4
                glBegin(GL_QUADS);
                glVertex2f(60,30);
                glVertex2f(60,35);
                glVertex2f(65,35);
                glVertex2f(65,30);
                glEnd();
        }
        else{
                glColor3f(0,0.6,0.9);//s4
                glBegin(GL_QUADS);
                glVertex2f(60,30);
                glVertex2f(60,35);
                glVertex2f(65,35);
                glVertex2f(65,30);
                glEnd();
        }
        int jj=1;
        if(complete == 1) { // check if receiver is complete
                for(int j=0; j<strlen(str); j++) {
                        glColor3f(1.0,1.0,1.0);
                        glBegin(GL_QUADS);
                        glVertex2f(74+jj,56);
                        glVertex2f(74+jj,58);
                        glVertex2f(75+jj,58);
                        glVertex2f(75+jj,56);
                        glEnd();
                        char x = str[j];
                        glColor3f(1.0,0.0,0.0);
                        drawchar(74.2+jj,56.2,&x);
                        jj+=2;
                }
        }

//draw reciever
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

//line 1
        if(transfer[1] == 0) {
                glColor3f(0.7,0.6,0.2);
                glBegin(GL_LINES);
                glVertex2f(15,42);
                glVertex2f(15,32.5);
                glEnd();
        }
        else{
                glColor3f(0,0,1);
                glBegin(GL_LINES);
                glVertex2f(15,42);
                glVertex2f(15,32.5);
                glEnd();
        }
//line 2
        if(transfer[2] == 0) {
                glColor3f(0.7,0.6,0.2);
                glBegin(GL_LINES);
                glVertex2f(15,32.5);
                glVertex2f(30,32.5);
                glEnd();
        }
        else{
                glColor3f(0,0,1);
                glBegin(GL_LINES);
                glVertex2f(15,32.5);
                glVertex2f(30,32.5);
                glEnd();
        }
//line 3
        if(transfer[3] == 0) {
                glColor3f(0.7,0.6,0.2);
                glBegin(GL_LINES);
                glVertex2f(35,32.5);
                glVertex2f(60,32.5);
                glEnd();
        }
        else{
                glColor3f(0,0,1);
                glBegin(GL_LINES);
                glVertex2f(35,32.5);
                glVertex2f(60,32.5);
                glEnd();
        }
//line 4
        if(transfer[4] == 0) {
                glColor3f(0.7,0.6,0.2);
                glBegin(GL_LINES);
                glVertex2f(65,32.5);
                glVertex2f(80,32.5);
                glEnd();
        }
        else{
                glColor3f(0,0,1);
                glBegin(GL_LINES);
                glVertex2f(65,32.5);
                glVertex2f(80,32.5);
                glEnd();
        }
//line 5
        if(transfer[5] == 0) {
                glColor3f(0.7,0.6,0.2);
                glBegin(GL_LINES);
                glVertex2f(80,32.5);
                glVertex2f(80,42);
                glEnd();
        }
        else{
                glColor3f(0,0,1);
                glBegin(GL_LINES);
                glVertex2f(80,32.5);
                glVertex2f(80,42);
                glEnd();
        }
//line 6
        if(transfer[6] == 0) {
                glColor3f(0.7,0.6,0.2);
                glBegin(GL_LINES);
                glVertex2f(32.5,35);
                glVertex2f(32.5,70);
                glEnd();
        }
        else{
                glColor3f(0,0,1);
                glBegin(GL_LINES);
                glVertex2f(32.5,35);
                glVertex2f(32.5,70);
                glEnd();
        }
//line 7
        if(transfer[7] == 0) {
                glColor3f(0.7,0.6,0.2);
                glBegin(GL_LINES);
                glVertex2f(35,72.5);
                glVertex2f(60,72.5);
                glEnd();
        }
        else{
                glColor3f(0,0,1);
                glBegin(GL_LINES);
                glVertex2f(35,72.5);
                glVertex2f(60,72.5);
                glEnd();
        }
//line 8
        if(transfer[8] == 0) {
                glColor3f(0.7,0.6,0.2);
                glBegin(GL_LINES);
                glVertex2f(62.5,70);
                glVertex2f(62.5,35);
                glEnd();
        }
        else{
                glColor3f(0,0,1);
                glBegin(GL_LINES);
                glVertex2f(62.5,70);
                glVertex2f(62.5,35);
                glEnd();
        }
//line 9
        if(transfer[9] == 0) {
                glColor3f(0.7,0.6,0.2);
                glBegin(GL_LINES);
                glVertex2f(35,70);
                glVertex2f(60,35);
                glEnd();
        }
        else{
                glColor3f(0,0,1);
                glBegin(GL_LINES);
                glVertex2f(35,70);
                glVertex2f(60,35);
                glEnd();
        }
//line 10
        if(transfer[10] == 0) {
                glColor3f(0.7,0.6,0.2);
                glBegin(GL_LINES);
                glVertex2f(35,35);
                glVertex2f(60,70);
                glEnd();
        }
        else{
                glColor3f(0,0,1);
                glBegin(GL_LINES);
                glVertex2f(35,35);
                glVertex2f(60,70);
                glEnd();
        }
        glFlush();
}

void path1(){ //bottom
        complete = 0;
        for(int j=0; j<strlen(str); j++) { //for length of string
                float toplx=15.3;
                float topty=42;
                float toprx=16.3;
                float topby=40;

                for(int i=0; i<7; i++) //length of line
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
                        drawchar(15.4,topty-1.4-i,&x); //draw the character
                        glFlush();
                        usleep(900); //delay
                }

                transfer[1] = 1;
                toplx=15.3;
                topty=35;
                toprx=16.3;
                topby=33;

                for(int i=0; i<63; i++)
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
                        usleep(900);
                }

                transfer[2] = 1;
                transfer[3] =1;
                transfer[4] =1;
                switchcolor[2] = switchcolor[4] = 1;

                toplx=78.7;
                topty=35;
                toprx=79.7;
                topby=33;

                for(int i=0; i<8; i++)
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
                        usleep(900);
                }
                transfer[5] = 1;
                computer();
        }
        transfer[1] = transfer[2] = transfer[3] = transfer[4] = transfer[5] =0;
        switchcolor[2] = switchcolor[4] = 0;
        complete = 1;
        computer();
}

void path2(){ //top
        complete = 0;
        for(int j=0; j<strlen(str); j++) {
                float toplx=15.3;
                float topty=42;
                float toprx=16.3;
                float topby=40;

                for(int i=0; i<7; i++)
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
                        usleep(900);
                }

                transfer[1] = 1;
                toplx=15.3;
                topty=35;
                toprx=16.3;
                topby=33;

                for(int i=0; i<16; i++)
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
                        usleep(900);
                }

                transfer[2] = 1;
                switchcolor[2] = 1;
                toplx=31.3;
                topty=35;
                toprx=32.3;
                topby=33;

                for(int i=0; i<40; i++)
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
                        usleep(900);
                }

                transfer[6] = 1;
                switchcolor[1] = 1;
                toplx=31.3;
                topty=75;
                toprx=32.3;
                topby=73;

                for(int i=0; i<31; i++)
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
                        usleep(900);
                }

                transfer[7] = 1;
                switchcolor[3] = 1;
                toplx=62.8;
                topty=75;
                toprx=63.8;
                topby=73;

                for(int i=0; i<40; i++)
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
                        usleep(900);
                }

                transfer[8] =1;
                switchcolor[4] = 1;
                toplx=63;
                topty=35;
                toprx=64;
                topby=33;

                for(int i=0; i<16; i++)
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
                        usleep(900);
                }

                transfer[4] = 1;
                toplx=78.7;
                topty=35;
                toprx=79.7;
                topby=33;

                for(int i=0; i<8; i++)
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
                        usleep(900);
                }
                transfer[5] = 1;
                computer();
        }
        transfer[1] = transfer[2] = transfer[6] = transfer[7] = transfer[8] = transfer[4] = transfer[5] = 0;
        switchcolor[2] = switchcolor[4] = switchcolor[1] = switchcolor[3]= 0;
        complete = 1;
        computer();
}

void path3()// top-diagonal
{
        complete = 0;
        for(int j=0; j<strlen(str); j++) {
                float counter = 1.0;
                float toplx=15.3;
                float topty=42;
                float toprx=16.3;
                float topby=40;

                for(int i=0; i<7; i++)
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
                        usleep(900);
                }

                transfer[1] = 1;
                toplx=15.3;
                topty=35;
                toprx=16.3;
                topby=33;

                for(int i=0; i<16; i++)
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
                        usleep(900);
                }

                transfer[2] = 1;
                switchcolor[2] =1;
                toplx=31.3;
                topty=35;
                toprx=32.3;
                topby=33;

                for(int i=0; i<40; i++)
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
                        usleep(900);
                }

                transfer[6] = 1;
                switchcolor[1] =1;
//diagonal
                toplx=32.3;
                topty=75;
                toprx=33.3;
                topby=73;

                for(int i=0; i<41; i++)
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
                        usleep(900);
                }

                transfer[9] = 1;
                switchcolor[4] = 1;
                toplx=63;
                topty=35;
                toprx=64;
                topby=33;

                for(int i=0; i<16; i++)
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
                        usleep(900);
                }

                transfer[4] = 1;
                toplx=78.7;
                topty=35;
                toprx=79.7;
                topby=33;

                for(int i=0; i<8; i++)
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
                        usleep(900);
                }

                transfer[5] = 1;
        }
        computer();
        transfer[1] = transfer[2] = transfer[6] = transfer[9] = transfer[4] = transfer[5] = 0;
        switchcolor[2] =switchcolor[1] =switchcolor[3] =switchcolor[4] =0;
        complete = 1;
        computer();
}

void path4() {

        complete = 0;
        for(int j=0; j<strlen(str); j++) {
                float counter = 1.0;
                float toplx=15.3;
                float topty=42;
                float toprx=16.3;
                float topby=40;

                for(int i=0; i<7; i++)
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
                        usleep(900);
                }

                transfer[1] = 1;
                toplx=15.3;
                topty=35;
                toprx=16.3;
                topby=33;

                for(int i=0; i<16; i++)
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
                        usleep(900);
                }

                transfer[2] = 1;
                switchcolor[2] =1;
//bottom diagonal

                toplx=31.3;
                topty=35;
                toprx=32.3;
                topby=33;

                for(int i=0; i<40; i++)
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
                        usleep(900);
                }

                transfer[10] = 1;
                switchcolor[3] =1;
                toplx=62.8;
                topty=75;
                toprx=63.8;
                topby=73;

                for(int i=0; i<40; i++)
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
                        usleep(900);
                }

                transfer[8] = 1;
                switchcolor[4] =1;
                toplx=63;
                topty=35;
                toprx=64;
                topby=33;

                for(int i=0; i<16; i++)
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
                        usleep(900);
                }

                transfer[4] = 1;
                toplx=78.7;
                topty=35;
                toprx=79.7;
                topby=33;

                for(int i=0; i<8; i++)
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
                        usleep(900);
                }

                transfer[5] = 1;
        }
        computer();
        transfer[1] = transfer[2] = transfer[10] = transfer[8] = transfer[4] = transfer[5] = 0;
        switchcolor[2] =switchcolor[1] =switchcolor[3] =switchcolor[4] = 0;
        complete = 1;
        computer();
}

void packettransfer(){
        int v = rand()%4; //call any path randomly
        if(v == 0)
                path1();
        else if(v == 1)
                path2();
        else if(v == 2)
                path3();
        else
                path4();
}

void display(void)
{
        glClear(GL_COLOR_BUFFER_BIT);
        switch(obj) {
        case title:
                frontscreen(); //call on right click select
                break;
        case circuit:
                complete = 0;
                computer();
                break;
        case packet:
                packettransfer();
                break;
        case quit:
                exit(0);
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
        cout<<"Enter string: "; //take string input
        gets(str);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(500,500);
        glutInitWindowPosition(0,0);
        glutCreateWindow("Virtual Circuit Switch Network");
        myinit();
        glutDisplayFunc(display);
        glutCreateMenu(menu_select);
        glutAddMenuEntry("title", title);
        glutAddMenuEntry("circuit", circuit);
        glutAddMenuEntry("packettransfer", packet);
        glutAddMenuEntry("quit", quit);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutMainLoop();
        glFlush();
        return 0;
}
