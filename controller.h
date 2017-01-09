#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "motionmanager.h"


typedef struct{
    int id;
    float positionX;
    float positionY;
    float velocityX;
    float velocityY;
    float acceleration;
    float deceleration;
    float viMax;

}Command;

class Controller {
private:
    MotionManager* motionManager;

public:
    Controller();
    ~Controller();
    void newCommand(Command command);

};


#endif // CONTROLLER_H
