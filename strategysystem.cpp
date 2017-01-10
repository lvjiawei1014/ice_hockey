#include "strategysystem.h"


StrategySystem::StrategySystem(){

}

StrategySystem::~StrategySystem(){

}

void StrategySystem::sendNewCommand(Command cmd){
    controller->newCommand(cmd);

}

void StrategySystem::calculate(){
    b2Vec2 vball=motionManager->ball->GetLinearVelocity();
    b2Vec2 vbatter=motionManager->batter1->GetLinearVelocity();
    b2Vec2 pball=motionManager->ball->GetPosition();
    b2Vec2 pbatter=motionManager->batter1->GetPosition();

    Command cmd;

    cmd.id=1;
    cmd.acceleration=4.0f;
    cmd.positionX=6.0f;
    cmd.positionY=4.0f;
    cmd.velocityX=0.0f;
    cmd.velocityY=0.0f;
    cmd.t=5.0f;
    cmd.viMax=10.0f;

    if(vball.y<0){


    }


}
