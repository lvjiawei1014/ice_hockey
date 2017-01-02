#include <Box2D/Box2D.h>
#ifndef MOTIONMANAGER_H
#define MOTIONMANAGER_H
class MotionManager{
public:

    static const int BODYTYPE_LINE=0;
    static const int BODYTYPE_CIRCLE=1;
    static const int BODYTYPE_RECTANGLE=2;

    MotionManager();
    ~MotionManager();

    struct BodyState{
        int type;
        b2Body* pBody;
        float32 x;
        float32 y;
    };

    b2World* world;
    BodyState bodyStates[100];
    int count;

    void build();//创建世界和物体
    void update();//更新物理世界状态
    struct BodyState* getBodyStates();
    int getBodyAmount();

    //void addBoundary()


};

#endif // MOTIONMANAGER_H


