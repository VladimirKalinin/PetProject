#pragma once

#include <list>
#include <iterator>
class Physics {
private:
    list< class GraphObject> ObjList;
   
public:

  Physics(list<GraphObject> Obj){
    ObjList = Obj;
  }

  void CalculatePhysics() {
   
    for (list<GraphObject> :: iterator i = ObjList.begin(); i != ObjList.end(); i++) {
        for (list<GraphObject> :: iterator j = ObjList.begin(); j != ObjList.end(); i++){
          if (i == j)
            break;
          i->setX(i->getX() + i->getVx());
          i->setY(i->getY() + i->getVy());
          if (i->cross(*j)) {
            i->setX(i->getX() - i->getVx());
            i->setY(i->getY() - i->getVy());
            break;
          }
        }
        if (i->isFall())
          i->setVy(i->getVy() - 3);
      }
    }
  };
