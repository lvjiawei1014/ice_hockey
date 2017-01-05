
#ifndef PSYENTITY_H
#define PSYENTITY_H
#include <Box2D/Box2D.h>
class PsyEntity{
public:
    int type;
    b2Body* body;
    float x,y;
    float w,h;
    float r;


    PsyEntity();
    PsyEntity(int type,b2Body* body);
    ~PsyEntity();

};



#endif // PSYENTITY_H
