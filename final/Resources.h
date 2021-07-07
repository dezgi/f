/* Ezgi Diþbudak – 2243400
I read and accept the submission rules and the important section specified in assignment file.
This is my own work that is done by myself and my team-mate only */

#ifndef RESOURCES_H
#define RESOURCES_H
#include "Entities.h"
using namespace std;

class Resources : public Entities {
private:
    int effect;
public:
    Resources() :Entities() {
        effect = 0;
    }

    Resources(int size, int character, int effect,int x,int y) : Entities(size, character,x,y) {
        this->effect = effect;
    }

    int getEffect() {
        return this->effect;
    }
    void setEffect(int effect) {
        this->effect = effect;
    }
};

class Large_Medicine_Kit : public Resources {
public:
    Large_Medicine_Kit(): Resources(){}

    Large_Medicine_Kit(int size, int character, int effect,int x , int y) : Resources(size, character, effect,x,y){
        effect = 20;
    }

};

class Small_Medicine_Kit : public Resources {
public:
    Small_Medicine_Kit():Resources(){}

    Small_Medicine_Kit(int size, int character, int effect,int x,int y) : Resources(size, character, effect,x,y) {
       effect = 10;
    }

};

class Ammunition : public Resources {
public:

    Ammunition():Resources(){}
    Ammunition(int size, int character, int effect,int x,int y) : Resources(size, character, effect,x,y) {
       effect = 10;
    }

};



#endif 
