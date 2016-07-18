

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

  void setVy(int i){
    vY=i;
  }
  int getVx(){
    return vX;
  }

  int getVy(){
    return vY;
  }
  void setX(int i){
    X=i;
  }

  void setY(int i){
    Y=i;
  }
  int getX(){
    return X;
  }

  int getY(){
    return Y;
  }
  void draw() {
    
  }

};
