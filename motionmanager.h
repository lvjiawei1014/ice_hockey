
#ifndef MOTIONMANAGER_H
#define MOTIONMANAGER_H
#include <Box2D/Box2D.h>
#include <psyentity.h>


/*
 * 类motionManager表示物理引擎模块，它在Box2d的基础上封装了所需的功能
 *
 */
class MotionManager{

public:

    static const int BODYTYPE_LINE=0;
    static const int BODYTYPE_CIRCLE=1;
    static const int BODYTYPE_RECTANGLE=2;

    float timeStep;

    MotionManager();
    ~MotionManager();

    b2World* world;//Box2d中的世界，负责处理物理仿真中的各种计算及相关事务
    b2Body* batter1;//计球器实体
    b2Body* batter2;
    b2Body* ball;//冰球实体


    int count;

    void build();//创建世界和物体
    void update();//更新物理世界状态
    int getBodyAmount();
    PsyEntity* getEneity(int i);
    void addBoundary(float x,float y,float width,float height);
    void addBall(float x,float y,float vx,float vy,float r);
    void addbatter(float r);
    void step();
    void applyAcceleration(b2Body* body,float ax,float ay);
    void launch();

};






#endif // MOTIONMANAGER_H


