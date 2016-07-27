#pragma once
#include "AllHeaders.h"
using namespace std;
class Keyboard {
private:
int left, right, up, down;
public:
  Keyboard() {
    left = 0;
    right = 0;
    up = 0;
    down = 0;
  }

void key (unsigned char  key,int x,int y ){
	if(key=='w') up = 1;
	if(key=='s') down = 1;
	if(key=='d') right = 1;
	if(key=='a') left = 1;
	
}

void keyUp(unsigned char  key,int x,int y ){
	if(key=='w') up = 0;
	if(key=='s') down = 0;
	if(key=='d') right = 0;
	if(key=='a') left = 0;
}
int getup() {
  return up;
}
int getdown() {
  return down;
}
int getright() {
  return right;
}
int getleft() {
  return left;
}

};
