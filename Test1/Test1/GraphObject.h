

class GraphObject {
private:
  int X, Y, vX, vY, W, H;

public:
  GraphObject(int x, int y, int w, int h) {
    X = x;
    Y = y;
    W = w;
    H = h;
    vX = 0;
    vY = 0;
    
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
  void draw() {
    
  }

};
