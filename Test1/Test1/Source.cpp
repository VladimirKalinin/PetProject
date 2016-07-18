#include <glut.h>   //Подключение библиотеки glut.h
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <random>
#include <cmath>
using namespace std;
int rectX,rectY,rectSize;
int foodX,foodY;
int vX,vY;

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
void loop(){
	cout<<"asd"<<endl;
}
void Draw()
{
glClear(GL_COLOR_BUFFER_BIT);
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



glEnd();
glFlush();
Sleep(15);

glutSwapBuffers();
}
void key (unsigned char  key,int x,int y ){
	if(key=='w') vY=4;
	if(key=='s') vY=-4;
	if(key=='d') vX=4;
	if(key=='a') vX=-4;
	
	cout<<"Key Down"<<endl<<rectX<<" ; "<<rectY<<endl;
}
void keyUp(unsigned char  key,int x,int y ){
	if(key=='w') vY=0;
	if(key=='s') vY=0;
	if(key=='d') vX=0;
	if(key=='a') vX=0;
	cout<<"Key Up"<<endl<<vX<<" ; "<<vY<<endl;
}
//Войти в главный цикл
int main(int argc, char **argv)
{
	vX=0;
	vY=0;
	rectX=0;
	rectY=0;
	windH=400;
	windW=400;
	rectSize=25;

	srand(time(NULL));

	


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