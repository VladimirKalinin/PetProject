#pragma once
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
list<GraphObject> List;
Physics phys;
int windH,windW;
int worldX, worldY;
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

 if (List.front().getX() + worldX > windW - 100)
   worldX-=List.front().getVx();
 if (List.front().getX() + worldX < 100)
   worldX-=List.front().getVx();
 if (List.front().getY() + worldY > windH - 100)
   worldY-=List.front().getVy();
 if (List.front().getY() + worldY < 100)
   worldY-=List.front().getVy();

	for (list<GraphObject>::iterator i = List.begin(); i != List.end(); i++)
		i->draw(worldX, worldY);

	Sleep(15);
	glutSwapBuffers();
}
void key (unsigned char  key,int x,int y ){
	if(key=='w') {
   if( List.front().isJump()){
     List.front().setVy(12);
      List.front().setJump(false);
   }
 }
	if(key=='s') List.front().setVy(-4);
	if(key=='d') List.front().setVx(4);
	if(key=='a') List.front().setVx(-4);
	
}
void keyUp(unsigned char  key,int x,int y ){
	if(key=='w') List.front().setVy(0);

	if(key=='s') List.front().setVy(0);
	if(key=='d') List.front().setVx(0);
	if(key=='a') List.front().setVx(0);
}
//Войти в главный цикл
int main(int argc, char **argv)
{
	windH=400;
	windW=400;
 worldX = 0;
 worldY = 0;
  List.push_back(*(new GraphObject(windW/2, windH/2, 40, 40, true)));
  List.push_back(*(new GraphObject(windW/2, 0, 200, 40, false)));
  List.push_back(*(new GraphObject(0, 0, 170, 40, false)));
  List.push_back(*(new GraphObject(380, 40, 300, 40, false)));
  List.push_back(*(new GraphObject(300, 45, 50, 5, false)));
   phys= *(new Physics(&List));


	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(windW,windH);		//Указываем размер окна
	glutInitWindowPosition(300,100);	//Позиция окна
	glutCreateWindow("test2");		//Имя окна
	Initialize();			//Вызов функции Initialize
	glutDisplayFunc(Draw);	
	glutIdleFunc(Draw);
	glutKeyboardFunc(key);
	glutKeyboardUpFunc(keyUp);
	glutMainLoop();
 
	return 0;
};