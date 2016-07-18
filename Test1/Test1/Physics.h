#include <list>
#include <iterator>
#include "GraphObject.h"

class Physics {
private:
  list<GraphObject> ObjList;
public:
  Physics(list<GraphObject> Obj){
    ObjList = Obj;
  }

  void CalculatePhysics() {

  }

};
