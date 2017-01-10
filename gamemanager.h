#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "motionmanager.h"
class GameManager{
public:
    int mode;
    MotionManager* motionManager;

    GameManager();
    ~GameManager();
    void setMode(int m);
    void reStart();

};

#endif // GAMEMANAGER_H
