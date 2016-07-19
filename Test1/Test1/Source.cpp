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
Physics phys(List);
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
	for (list<GraphObject>::iterator i = List.begin(); i != List.end(); i++)
		i->draw();

	Sleep(15);
	glutSwapBuffers();
}
void key (unsigned char  key,int x,int y ){
	if(key=='w') List.front().setVy(4);
	if(key=='s') List.front().setVy(-4);
	if(key=='d') List.front().setVx(4);
	if(key=='a') List.front().setVy(-4);
	
}
void keyUp(unsigned char  key,int x,int y ){
	if(key=='w') List.front().setVy(0);
	if(key=='s') List.front().setVy(0);
	if(key=='d') List.front().setVx(0);
	if(key=='a') List.front().setVy(0);
}
//Войти в главный цикл
int main(int argc, char **argv)
{

  List.push_back(*(new GraphObject(windW/2, windH/2, 40, 40, true)));
  List.push_back(*(new GraphObject(windW/2, 0, 200, 40, false)));


	windH=400;
	windW=400;


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