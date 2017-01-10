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
//    float rball=motionManager->ball->
    float rball=0.6f;
    float rbatter=0.5f;

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
//    if(false){
        float sx=pball.x+vball.x*(8.0f-pball.y)/vball.y;

        bool isin=false;
        while (!isin) {
            if(sx>(12.0f-rball)){
                sx=(12.0f-rball)-(sx-(12.0f-sx));
            }else if(sx<rball){
                sx=2*rball-sx;
            }else{
                isin=true;
            }
        }

        cmd.positionX=sx;
        cmd.positionY=8.0f;
        cmd.t=(8.0f-pball.y)/vball.y;


    }

    sendNewCommand(cmd);


}
