
#ifndef PSYENTITY_H
#define PSYENTITY_H
#include <Box2D/Box2D.h>

/*
 * 类PsyEntity表示的是物理世界中的一个实体，比如冰球，边界等，它保存有一些状态数据，Gui
 * 模块可以通过MotionManager获取，用于绘制图形。
 */

class PsyEntity{
public:
    int type;//实体类型
    b2Body* body;//指向body实体的指针
    float x,y;//位置坐标
    float w,h;//宽高，仅矩形对象
    float r;//半径，仅圆形对象


    PsyEntity();
    PsyEntity(int type,b2Body* body);
    ~PsyEntity();

};



#endif // PSYENTITY_H
