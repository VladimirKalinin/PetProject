#include "AllHeaders.h"
#include "GraphObject.h"
#include <SOIL.h>
using namespace std;
list<GraphObject> List;
Physics phys;
int windH,windW;
int worldX, worldY;
GLuint   texture[2];// массив для  текстур

int LoadGLTextures()                                

{
	texture[0] = SOIL_load_OGL_texture("Data/NeHe.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,
             SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB
             | SOIL_FLAG_COMPRESS_TO_DXT );

         

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	texture[1] = SOIL_load_OGL_texture("Data/Mario.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,
             SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB
             | SOIL_FLAG_COMPRESS_TO_DXT );
	

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
		texture[2] = SOIL_load_OGL_texture("Data/Fire.png",SOIL_LOAD_AUTO,SOIL_CREATE_NEW_ID,
             SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB
             | SOIL_FLAG_COMPRESS_TO_DXT );
	

	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	if(texture[0] == 0)
		return false;
    if(texture[1] == 0)
		return false;
	return true;    
}
void Initialize()
{


	glOrtho(0,windW,0,windH,-1.0,1.0);
	LoadGLTextures();             // Загрузка текстур
    glShadeModel(GL_SMOOTH); // Type of shading for the polygons
    glEnable(GL_DEPTH_TEST); // We enable the depth test (also called z buffer)
    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL); // Polygon rasterization mode (polygon filled)
    glEnable(GL_TEXTURE_2D); // This Enable the Texture mapping
    glMatrixMode(GL_MODELVIEW);
}

void Draw()
{

	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
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
	windH=600;
	windW=800;
 worldX = 0;
 worldY = 0;
  List.push_back(*(new GraphObject(windW/2, windH-300, 32, 32, true,2)));
  int n, x, y, w, h;
  int c = 500;          //константа смещения

  char buff[50]; // буфер промежуточного хранения считываемого из файла текста
  ifstream fin("map.txt"); // открыли файл для чтения
 
  fin >> n; // считали первое слово из файла
  cout << n << endl; // напечатали это слово
  for (int i = 0; i < n; i++) {
    fin >> x;
    fin >> y;
    fin >> w;
    fin >> h;
    List.push_back(*(new GraphObject(x, y + c, w, h, false,1)));
  }

  fin.close(); // закрываем файл 

  List.push_back(*(new GraphObject(677, c+4, 32, 32, false,3)));
 // List.push_back(*(new GraphObject(windW/2 +50, 50, 400, 100, false)));
   phys= *(new Physics(&List));


	glutInit(&argc,argv);
    glutInitDisplayMode( GLUT_DOUBLE|GLUT_RGBA |GLUT_DEPTH );
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