#include <glut.h>   //Подключение библиотеки glut.h
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <random>
#include <cmath>
#include <list>
#include <iterator>
#include "GraphObject.h"
#include "Physics.h"
using namespace std;
list<GraphObject> ObjList;
Physics phys(ObjList);
int windH,windW;
void Initialize()
{
//Выбрать фоновый (очищающий) цвет
glClearColor(0.0,0.0,0.0,1.0);
 
//Установить проекцию
//glMatrixMode(GL_PROJECTION);
//glLoadIdentity();
glOrtho(0,windW,0,windH,-1.0,1.0);
}

void Draw()
{
glClear(GL_COLOR_BUFFER_BIT);
phys.CalculatePhysics();
for (auto i = ObjList.begin(); i != ObjList.end(); i++)
  i->paint();


/*
 rectX+=vX;
	rectY+=vY;
//Отрисовка квадрата 
glColor3f(((float)rectX)/400,1.0,1.0); //Выбираем белый цвет
glBegin(GL_POLYGON);
glVertex3f(rectX,rectY,0.0); 
glVertex3f(rectX+rectSize,rectY,0.0); 
glVertex3f(rectX+rectSize,rectY+rectSize,0.0); 
glVertex3f(rectX,rectY+rectSize,0.0); 



glEnd();
if((abs(rectX-foodX)<rectSize)&&(abs(rectY-foodY))<rectSize){
	foodX=rand()%400;
	foodY=rand()%400;
} 

glColor3f(1.0,0,0); //Выбираем белый цвет
glBegin(GL_POLYGON);
glVertex3f(foodX,foodY,0.0); 
glVertex3f(foodX+rectSize,foodY,0.0); 
glVertex3f(foodX+rectSize,foodY+rectSize,0.0); 
glVertex3f(foodX,foodY+rectSize,0.0); 


*/
glEnd();
glFlush();
Sleep(15);

glutSwapBuffers();
}
void key (unsigned char  key,int x,int y ){
  if(key=='w') ObjList.front().setVy(4);
	if(key=='s') ObjList.front().setVy(-4);
	if(key=='d') ObjList.front().setVx(4);
	if(key=='a') ObjList.front().setVy(-4);
	
}
void keyUp(unsigned char  key,int x,int y ){
	  if(key=='w') ObjList.front().setVy(0);
	if(key=='s') ObjList.front().setVy(0);
	if(key=='d') ObjList.front().setVx(0);
	if(key=='a') ObjList.front().setVy(0);
}
//Войти в главный цикл
int main(int argc, char **argv)
{
  ObjList.push_back(*(new GraphObject(windW/2, windH/2, 40, 40, true)));
  ObjList.push_back(*(new GraphObject(windW/2, 0, 200, 40, false)));

	windH=400;
	windW=400;


glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
glutInitWindowSize(windW,windH);		//Указываем размер окна
glutInitWindowPosition(300,100);	//Позиция окна
glutCreateWindow("test1");		//Имя окна
Initialize();			//Вызов функции Initialize
glutDisplayFunc(Draw);	
glutIdleFunc(Draw);
glutKeyboardFunc(key);
glutKeyboardUpFunc(keyUp);
glutMainLoop();
 
return 0;
}