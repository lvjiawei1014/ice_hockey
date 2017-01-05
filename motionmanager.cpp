#include<motionmanager.h>

PsyEntity psyEntitys[100];//实体状态对象的数组
float32 timeStep=1.0f/60.0f;//仿真世界每次计算间隔时间
int32 velocityIterations = 6;//box2d速度计算迭代次数
int32 positionIterations = 2;//box2d位置计算迭代次数

MotionManager::MotionManager(){
    build();//初始构造
}
MotionManager::~MotionManager(){
    delete world;
}

//
void MotionManager::build(){

    b2Vec2 gravity(0.0f,0.0f);//重力，俯视视角，重力设为零
    world=(new b2World(gravity));
    count=0;

    addBoundary(-0.1f,-0.1f,0.1f,20.2f);//添加边界实体
    addBoundary(-0.1f,-0.1f,12.2f,0.1f);
    addBoundary(0.0f,20.0f,12.1f,0.1f);
    addBoundary(12.0f,-0.1f,0.1f,20.2f);
    addBall(2.0f,12.0f,2.0f,-3.0f,0.6f);//添加冰球

    //addBall(0.8f,1.0f,-0.1f,0.0f,0.06f);
}


//获取实体数量的方法
int MotionManager::getBodyAmount(){
    return count;
}


//添加边界的方法
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

//添加球的方法
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
    ballFixtureDef.density=1.0f;//密度
    ballFixtureDef.friction=0.0f;
    ballFixtureDef.restitution=0.7;//弹性碰撞恢复系数
    ball->CreateFixture(&ballFixtureDef);
    PsyEntity ballEntity(1,ball);
    ballEntity.r=r;
    psyEntitys[count]=ballEntity;
    count++;
}

//获取实体对象的方法
PsyEntity* MotionManager::getEneity(int i){
    return &psyEntitys[i];
};

//仿真世界向前演算的方法，调用Box2的step方法
void MotionManager::step(){
    world->Step(timeStep,velocityIterations,positionIterations);
}


