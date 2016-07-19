
class GraphObject {
private:
  int X, Y, vX, vY, W, H;
  bool FALL;
public:
  GraphObject(int x, int y, int w, int h, bool fall) {
    X = x;
    Y = y;
    W = w;
    H = h;
    vX = 0;
    vY = 0;
    FALL = fall;
  }
  bool isFall() {
    return FALL;
  }

  void setVx(int i){
    vX=i;
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
		int getVx(){
			return vX;
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
						( Y>=go.getY() && Y<=go.getY() + go.getH() )||( X+H>=go.getY() && X+H<=go.getY() + go.getH() )
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
		void draw() {
			glColor3f(1.0,1.0,1.0); //Выбираем белый цвет
			glBegin(GL_POLYGON);
				glVertex3f(X,Y,0.0); 
				glVertex3f(X+W,Y,0.0); 
				glVertex3f(X+W,Y+H,0.0); 
				glVertex3f(X,Y+H,0.0); 
			glEnd();
		}

};
