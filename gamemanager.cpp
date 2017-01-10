#include "gamemanager.h"

void GameManager::setMode(int m){
    this->mode=m;
    switch (m) {
    case 0:
        motionManager->batter1->SetActive(false);
        break;
    default:
        break;
    }
}

void GameManager::reStart(){
    switch (mode) {
    case 0:
//        motionManager->ball
        motionManager->batter2->SetLinearVelocity(b2Vec2(0.0f,0.0f));
        motionManager->batter2->SetTransform(b2Vec2(6.0f,4.0f),0.0f);
        break;
    default:
        break;
    }
}

GameManager::GameManager(){

}
GameManager::~GameManager(){

}
