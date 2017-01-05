#include<motionmanager.h>



PsyEntity psyEntitys[100];
float32 timeStep=1.0f/60.0f;
int32 velocityIterations = 6;
int32 positionIterations = 2;

MotionManager::MotionManager(){
    build();
}
MotionManager::~MotionManager(){
    delete world;
}

//
void MotionManager::build(){

    b2Vec2 gravity(0.0f,0.0f);
    world=(new b2World(gravity));
    count=0;

    addBoundary(-0.1f,-0.1f,0.1f,20.2f);
    addBoundary(-0.1f,-0.1f,12.2f,0.1f);
    addBoundary(0.0f,20.0f,12.1f,0.1f);
    addBoundary(12.0f,-0.1f,0.1f,20.2f);
    addBall(2.0f,12.0f,2.0f,-3.0f,0.6f);

    //addBall(0.8f,1.0f,-0.1f,0.0f,0.06f);
}



int MotionManager::getBodyAmount(){
    return count;
}

void MotionManager::addBoundary(float x,float y,float width,float height){

    b2BodyDef boundaryBodyDef;
    boundaryBodyDef.position.Set(x+width/2,y+height/2);
    b2Body* boundaryBody=(world->CreateBody(&boundaryBodyDef));


    b2PolygonShape boundaryShape;
    boundaryShape.SetAsBox(width,height);
    b2FixtureDef boundaryFixtureDef;
    boundaryFixtureDef.shape=&boundaryShape;
    boundaryFixtureDef.density=1;
    boundaryFixtureDef.restitution=0.8;
    boundaryBody->CreateFixture(&boundaryFixtureDef);

    PsyEntity psyEntity(2,boundaryBody);
    psyEntity.w=width;
    psyEntity.h=height;
    psyEntitys[count]=psyEntity;
    count++;
}

void  MotionManager::addBall(float x,float y,float vx,float vy,float r){
    b2BodyDef ballBodyDef;
    ballBodyDef.position.Set(x,y);
    ballBodyDef.type=b2_dynamicBody;
    ball=world->CreateBody(&ballBodyDef);
    b2Vec2 velocity(vx,vy);
    ball->SetLinearVelocity(velocity);

    b2CircleShape ballShape;
    ballShape.m_p.Set(r,-r);
    ballShape.m_radius=r;

    b2FixtureDef ballFixtureDef;
    ballFixtureDef.shape=&ballShape;
    ballFixtureDef.density=1.0f;
    ballFixtureDef.friction=0.0f;
    ballFixtureDef.restitution=0.7;
    ball->CreateFixture(&ballFixtureDef);
    PsyEntity ballEntity(1,ball);
    ballEntity.r=r;
    psyEntitys[count]=ballEntity;
    count++;
}


PsyEntity* MotionManager::getEneity(int i){
    return &psyEntitys[i];
};

void MotionManager::step(){
    world->Step(timeStep,velocityIterations,positionIterations);
}


