/*
Any comment,idea and complaining please feel free to contact me at here and twitter/fahriyardimci
*/
#include <stdio.h>
#include <stdlib.h>	
#include <string.h>
#include <math.h>
#include <iostream>
#include <windows.h>
#include <GL/GLUT>    //in windows and dont have this lib try adding manually "c:\\glut.h"
using namespace std;

static GLfloat spin = 0.0;
static int donus= 0;
static int asd = rand()%5 , wasd = rand()%5;
static GLfloat joyx=0,joyy=-40,joyz = 0,sc=1,mavi=0,kirmizi=0,r=1,g,b;
static GLfloat hx=53,hy=52,hizDS1=0.1,hizDS2=0.3,konumDS1=-hx,konumDS2=-hx;
int   button1 = 0;
void init(void)
{
	glClearColor(0,1,1,1);
	glShadeModel(GL_FLAT);
}
bool ekranIcindeMi(GLfloat konum , GLfloat ek)
{
	if(konum+ek > hx || konum+ek <-hx)
	return false;

	else
	return true;
	
	
}
void sifirla()
{
	asd = (rand()%4)+1;
	wasd = (rand()%4)+1;
	hizDS1=(float)((rand()%6)+1)/10;
	donus=rand()%1+1;
	r=(float)(rand()%10)/10;
	g=(float)(rand()%10)/10;
	b=(float)(rand()%10)/10;
	hizDS2=(float)((rand()%6)+1)/10;
	joyy=-40;
	joyx=0;
	glutPostRedisplay();
}

void random(int sayi)
{
	switch(sayi)
	{
	case 1:
		glColor3f(r,g,b);
		glRectf(-5.0, -5.0, 5.0, 5.0); // kare
		break;

	case 2:
		 glBegin(GL_TRIANGLES); // üçgen 1
		 glColor3f(r,g,b);
        glVertex3f(0, 0, 0);
        glVertex3f(10, 0, 0);
        glVertex3f(0, 10, 0);
        glEnd();
		break;

	case 3:
		glBegin(GL_TRIANGLES);
		glColor3f(r,g,b);// üçgen 2
        glVertex3f(0, 0, 0);
        glVertex3f(10, 0, 0);
        glVertex3f(5, 10, 0);
        glEnd();
		break;

	case 4:
		glColor3f(r,g,b);
	glutSolidTeapot(5.0);
		break;

	}
}
void kontrol()
{
	//if(joyy-5 >2.5 || joyy-5 < -2.5 ||joyx-konumDS1 >2.5 || joyx-konumDS1 < -2.5 )
	if(joyy > -12*sc && joyy < 5*sc && joyx-konumDS1 <10*sc && joyx-konumDS1 > -10*sc )
	{
		glColor3f(1.0,0,0);
		joyx=0;
		joyy=-40;
		cout<<"DUSMAN 1 CARPTI"<<endl;
	}
	else
		glColor3f(1.1,1,1);
	if(joyx-konumDS2 <10*sc && joyx-konumDS2 > -10*sc && joyy-30 <10*sc  && joyy-30 > -10*sc)
		{
		glColor3f(1.0,0,0);
		joyx=0;
		joyy=-40;
		cout<<"DUSMAN 2 CARPTI"<<endl;
	}
	else
		glColor3f(1.1,1,1);
	if(joyy>41)
	{
		glColor3f(1,0,1);
		sifirla();
	}

}
void ds1()
{
	glPushMatrix();
	glTranslatef(konumDS1,-5,1);
	random(asd);
	glPopMatrix();
	if(ekranIcindeMi(konumDS1,hizDS1))
	konumDS1+=hizDS1;
	else
	{
		if(hizDS1 < 0 )
		hizDS1=abs(hizDS1);
		else
			hizDS1=-(hizDS1);
	}
}
void ds2()
{
	glPushMatrix();
	glTranslatef(konumDS2,30,1);
	if(donus)
	glRotatef(spin++, 0.0, 0.0, 1.0);
	//glRectf(-5.0, -5.0, 5.0, 5.0);
	random(wasd);
	glPopMatrix();
	if(ekranIcindeMi(konumDS2,hizDS2))
	konumDS2+=hizDS2;
	else
	{
		if(hizDS2 < 0 )
		hizDS2=abs(hizDS2);
		else
			hizDS2=-(hizDS2);
	}
}
void display(void)
{
	kontrol();
	glClear(GL_COLOR_BUFFER_BIT);
	ds1();
	ds2();
	
	glPushMatrix();
	
	glTranslatef(joyx,joyy,joyz);
	glColor3f(kirmizi,0,mavi);
	glScalef(sc,sc,1);
	glRectf(-5.0, -5.0, 5.0, 5.0);
	
	glutForceJoystickFunc();
	glPopMatrix();
	spin += donus;
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void keyboard(unsigned char key,int x, int y)
{

}

int   button2 = 0;
int   button3 = 0;
int   button4 = 0;
int   button5 = 0;
int   button6 = 0;
int   button7 = 0;
int   button8 = 0;
int   x_axis  = 0;
int   y_axis  = 0;
int   z_axis  = 0;
void joystick(unsigned int buttonmask, int x, int y, int z)
{
	 //donus  = x%360;
	if (buttonmask & 0x01) 
		sc+=0.1;
	if (buttonmask & 0x02)
		 sc-=0.1;
	if (buttonmask & 0x03)
		kirmizi=1;
	else
		kirmizi=0;
	if (buttonmask & 0x05) 
		mavi=1;
	else
		mavi=0;
	float tmp1=(float)x/1000;
	float tmp2=(float)y/1000;
		if(joyx+tmp1 > hx || joyx+tmp1 <-hx)
		{}
		else
	 joyx+=(float)x/2000;
	 if(joyy+tmp2 > hy || joyy+tmp2 <-hy )
	 {}
	 else
	 joyy+=(float)y/2000;
	 joyz+=(float)z/1000;
     cout<<endl;
     cout<<endl;
     cout<<endl;
     cout<<endl;
     cout<<endl;cout<<endl;
 	 cout<<"X EKSENİ "<<joyx<<endl<<"Y EKSENİ "<<joyy<<endl<<"Z EKSENİ "<<joyz<<endl;
	 cout<<hizDS1<<endl<<cout<<hizDS2<<endl;
	 //cout<<"DS 1 HIZ = "<<hizDS1<<endl<<"DS 2 HIZ = "<<hizDS2<<endl;
	 
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("FREEGLUT OYUN");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutForceJoystickFunc();
	glutJoystickFunc(joystick,25);
	glutForceJoystickFunc();
	glutMainLoop();
	return 0;
}
