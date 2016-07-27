#pragma once
#include "AllHeaders.h"
#include "Keyboard.h"
#include "GraphObject.h"
using namespace std;

class Physics {
private:
    list <GraphObject> *ObjList;
public:
  Physics(){
    cout<<"Phys"<<endl;
  }
  Physics(list <GraphObject> *Obj){
    ObjList = Obj;
  }

  void CalculatePhysics(Keyboard *k) {
    if (5*k->getup() && ObjList->begin()->isJump()) {
      ObjList->begin()->setvY(15);
      ObjList->begin()->setJump(false);
    }
    ObjList->begin()->setvX(5*k->getright() - 5*k->getleft());
    for (list<GraphObject> :: iterator i = ObjList->begin(); i != ObjList->end(); i++) {
      if (i->isFall())
        i->setvY(i->getvY() - 1);

       i->setX(i->getX() + i->getvX());
        for (list<GraphObject> :: iterator j = ObjList->begin(); j != ObjList->end(); j++){
          if (i == j)
            continue;
          if (i->cross(*j)) {
            i->setX(i->getX() - i->getvX());
            break;
          }
         
        }

        i->setY(i->getY() + i->getvY());
        for (list<GraphObject> :: iterator j = ObjList->begin(); j != ObjList->end(); j++){
          if (i == j)
            continue;
          if (i->cross(*j)) {
            i->setY(i->getY() - i->getvY());
            i->setvY(0);
            i->setJump(true);
            break;
          }
         
        }
         
        }
      }
  };
