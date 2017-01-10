#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "motionmanager.h"


typedef struct{
    int id;
    float t;
    float positionX;
    float positionY;
    float velocityX;
    float velocityY;
    float acceleration;
    float deceleration;
    float viMax;

}Command;

class Controller {


public:
    MotionManager* motionManager;

    Controller();
    ~Controller();
    bool newCommand(Command command);
    void apply(b2Body* body,float ax,float ay);

};


#endif // CONTROLLER_H
