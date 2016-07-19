#pragma once
#include <iostream>
#include <list>
#include <iterator>
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

  void CalculatePhysics() {
   
    for (list<GraphObject> :: iterator i = ObjList->begin(); i != ObjList->end(); i++) {
      if (i->isFall())
          i->setVy(i->getVy() - 1);

       i->setX(i->getX() + i->getVx());
        for (list<GraphObject> :: iterator j = ObjList->begin(); j != ObjList->end(); j++){
          if (i == j)
            continue;
          if (i->cross(*j)) {
            i->setX(i->getX() - i->getVx());
            break;
          }
         
        }
        i->setY(i->getY() + i->getVy());

        for (list<GraphObject> :: iterator j = ObjList->begin(); j != ObjList->end(); j++){
          if (i == j)
            continue;
          if (i->cross(*j)) {
            i->setY(i->getY() - i->getVy());
            i->setVy(0);
            i->setJump(true);
            break;
          }
         
        }
         

      }
    }
  };
