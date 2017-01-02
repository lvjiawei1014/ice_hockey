#include<motionmanager.h>

MotionManager::MotionManager(){
    build();
}
MotionManager::~MotionManager(){

}
void MotionManager::build(){
    b2Vec2 gravity(0.0f, 0.0f);
    this->world=&b2World(gravity);
    count=0;

    b2BodyDef leftBoundaryDef;
    leftBoundaryDef.position.Set(10.0f,10.0f);

    b2Body* leftBoundaryBody=&(*world->CreateBody(&leftBoundaryDef));
    b2PolygonShape boundaryShape;
    boundaryShape.SetAsBox(1.0f,5.0f);
    b2FixtureDef boundaryFixtureDef;
    boundaryFixtureDef.shape=&boundaryShape;
    leftBoundaryBody->CreateFixture(&boundaryFixtureDef);

    struct BodyState leftBoundaryState={2,leftBoundaryBody,2.0f,10.0f};
    bodyStates[count]=leftBoundaryState;
    count++;

}


struct MotionManager::BodyState* MotionManager::getBodyStates(){
    return &bodyStates[0];
}

int MotionManager::getBodyAmount(){
    return count;
}
