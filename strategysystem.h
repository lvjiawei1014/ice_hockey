#ifndef STRATEGYSYSTEM_H
#define STRATEGYSYSTEM_H
#include "motionmanager.h"
#include "controller.h"

class StrategySystem{
public:
    MotionManager* motionManager;
    Controller* controller;


    StrategySystem();
    ~StrategySystem();
    void sendNewCommand(Command cmd);
    void calculate();

};


#endif // STRATEGYSYSTEM_H
