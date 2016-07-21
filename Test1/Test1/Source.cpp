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
#include <fstream>
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

 if (List.front().getX() + worldX > windW - 300)
   worldX = worldX + List.front().getVLeft() - List.front().getVRight();
 if (List.front().getX() + worldX < 300)
   worldX = worldX + List.front().getVLeft() - List.front().getVRight();
 if (List.front().getY() + worldY > windH - 300)
   worldY-=List.front().getVy();
 if (List.front().getY() + worldY < 300)
   worldY-=List.front().getVy();

	for (list<GraphObject>::iterator i = List.begin(); i != List.end(); i++)
		i->draw(worldX, worldY);

	Sleep(15);
	glutSwapBuffers();
}
void key (unsigned char  key,int x,int y ){
	if(key=='w') {
   if( List.front().isJump()){
     List.front().setVy(15);
      List.front().setJump(false);
   }
 }
	if(key=='s') List.front().setVy(-4);
	if(key=='d') List.front().setVRight(4);
	if(key=='a') List.front().setVLeft(4);
	
}
void keyUp(unsigned char  key,int x,int y ){
	if(key=='w') List.front().setVy(0);
	if(key=='s') List.front().setVy(0);
	if(key=='d') List.front().setVRight(0);
	if(key=='a') List.front().setVLeft(0);
}
//Войти в главный цикл
int main(int argc, char **argv)
{
	windH=800;
	windW=800;
 worldX = 0;
 worldY = 0;
  List.push_back(*(new GraphObject(windW/2, windH-300, 40, 40, true)));
  int n, x, y, w, h;
  int c = 600;          //константа смещения

  char buff[50]; // буфер промежуточного хранения считываемого из файла текста
  ifstream fin("map.txt"); // открыли файл для чтения
 
  fin >> n; // считали первое слово из файла
  cout << n << endl; // напечатали это слово
  for (int i = 0; i < n; i++) {
    fin >> x;
    fin >> y;
    fin >> w;
    fin >> h;
    List.push_back(*(new GraphObject(x, y + c, w, h, false)));
  }

  fin.close(); // закрываем файл 
  
//  List.push_back(*(new GraphObject(windW/2-100, 0, 400, -40, false)));
//  List.push_back(*(new GraphObject(windW/2 +50, 50, 400, 100, false)));
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