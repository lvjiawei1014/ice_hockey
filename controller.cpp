#include "controller.h"

Controller::Controller(){
    motionManager=new MotionManager();
}

Controller::~Controller(){
    delete motionManager;
}

void Controller::newCommand(Command command){
    b2Body* batter;
//    b2Body*

    switch (command.id) {
    case 1:
        batter=motionManager->batter1;
        break;
    case 2:
        batter=motionManager->batter2;
        break;
    default:
        break;
    }
    float sx=command.positionX-batter->GetPosition().x;
    float sy=command.positionY-batter->GetPosition().y;



}
