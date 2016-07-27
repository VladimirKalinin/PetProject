#pragma once
#include "AllHeaders.h"

using namespace std; 
class GraphObject {
private:
  int X, Y, vRight, vLeft, vY, W, H;
  GLuint *texture;
  bool FALL,JUMP;
  
public:
  GraphObject(int x, int y, int w, int h, bool fall,GLuint *t) {
    X = x;
    Y = y;
    W = w;
    H = h;
    vRight = 0;
    vLeft = 0;
    vY = 0;
    FALL = fall;
	texture=t;
	
  }
  bool isFall() {
    return FALL;
  }
  bool  isJump(){
    return JUMP;
  }
  void setJump(bool j){
    JUMP=j;
  }
  void setVLeft(int i){
    vLeft=i;
  }
  void setVRight(int i){
    vRight=i;
  }
		int getX(){
			return X;
		}

		void setX(int i){
			X=i;
		}
		void setY(int i){
			Y=i;
		}

  int getY(){
    return Y;
  }

		void setVy(int i){
			vY=i;
		}
		int getVLeft(){
			return vLeft;
		}
  int getVRight(){
			return vRight;
		}
  		int getVy(){
			return vY;
		}


		int getW(){
			return W;
		}
		int getH(){
			return H;
		}
		bool cross(GraphObject go){
			return(
				(
					(
						( X>=go.getX() && X<=go.getX() + go.getW())||( X+W>=go.getX() && getX()+getW()<=go.getX()+go.getW()  )
					) && (
						( Y>=go.getY() && Y<=go.getY() + go.getH() )||( Y+H>=go.getY() && Y+H<=go.getY() + go.getH() )
						)
				)||(
					(
						( go.getX()>=X && go.getX()<=X+W )||( go.getX()+go.getW()>=X && go.getX()+go.getW()<=X+W  )
					) && (
						( go.getY()>=Y && go.getY()<=Y+H )||( go.getY() + go.getH()>=Y && go.getY() + go.getH()<=Y+H )
					)
				)
				)||(
				(
					(
						( X>=go.getX() && X<=go.getX()+go.getW() )||( X+W>=go.getX() && X+W<=go.getX()+go.getW()  )
					) && (
						( go.getY()>=Y && go.getY()<=Y+H )||( go.getY() + go.getH()>=Y && go.getY() + go.getH()<=Y+H )
					)
				)||(
					(
						( go.getX()>=X && go.getX()<=X+W )||( go.getX()+go.getW()>=X && go.getX()+go.getW()<=X+W )
					) && (
						( Y>=go.getY() && Y<=go.getY() + go.getH() )||( Y+H>=go.getY() && Y + H<=go.getY() + go.getH() )
					)
				)
  );
}
		void draw(int worldX, int worldY) {
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBindTexture(GL_TEXTURE_2D,*texture);
			glColor4f(1,1,1,1); //Выбираем белый цвет
			glBegin(GL_POLYGON);
				glTexCoord3i(0,0,0); glVertex3i(X + worldX, Y + worldY, 0.0); 
				glTexCoord3i(((double)W)/32,0,0); glVertex3i(X + W + worldX, Y + worldY, 0.0); 
				glTexCoord3i(((double)W)/32,((double)H)/32,0); ;glVertex3i(X + W + worldX,Y + H + worldY,0.0); 
				glTexCoord3i(0,((double)H)/32,0); ;glVertex3i(X + worldX,Y + H + worldY, 0.0); 
			glEnd();
		}

};
