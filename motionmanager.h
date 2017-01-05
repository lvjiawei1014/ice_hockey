
#ifndef MOTIONMANAGER_H
#define MOTIONMANAGER_H
#include <Box2D/Box2D.h>
#include <psyentity.h>
class MotionManager{

public:

    static const int BODYTYPE_LINE=0;
    static const int BODYTYPE_CIRCLE=1;
    static const int BODYTYPE_RECTANGLE=2;

    MotionManager();
    ~MotionManager();

    b2World* world;
    b2Body* batter1;
    b2Body* batter2;
    b2Body* ball;

    int count;

    void build();//创建世界和物体
    void update();//更新物理世界状态
    struct BodyState* getBodyStates();
    struct BodyState* getBodyStates(int i);
    int getBodyAmount();
    PsyEntity* getEneity(int i);
    void addBoundary(float x,float y,float width,float height);
    void addBall(float x,float y,float vx,float vy,float r);
    void step();

};






#endif // MOTIONMANAGER_H


