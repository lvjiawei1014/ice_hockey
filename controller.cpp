#include "controller.h"
#include <math.h>

Controller::Controller(){
//    motionManager=new MotionManager();
}

Controller::~Controller(){
//    delete motionManager;
}

bool Controller::newCommand(Command command){
    b2Body* batter;

    float ax=0;
    float ay=0;
    switch (command.id) {
    case 1:
        batter=motionManager->batter1;
        break;
    case 2:
        batter=motionManager->batter2;
        break;
    default:
        break;
    }
    float sx=command.positionX-batter->GetPosition().x;
    float sy=command.positionY-batter->GetPosition().y;

    if(fabs(command.velocityX)>command.viMax || fabs(command.velocityY)>command.viMax){
        return false;
    }

    float xp=(batter->GetLinearVelocity().x+command.velocityX)*command.t/2;
    float axp=(command.velocityX-batter->GetLinearVelocity().x)/command.t;
    float cvx=command.velocityX-batter->GetLinearVelocity().x;
    float kx=(sx-xp)/((command.t-fabs(cvx)/command.acceleration)*fabs(cvx)/2);

    if(axp>=0){
        ax=axp+kx*(command.acceleration-axp);
    }else{
        ax=axp+kx*(command.acceleration+axp);
    }


    float yp=(batter->GetLinearVelocity().y+command.velocityY)*command.t/2;
    float ayp=(command.velocityY-batter->GetLinearVelocity().y)/command.t;
    float cvy=command.velocityY-batter->GetLinearVelocity().y;
    float ky=(sy-yp)/((command.t-fabs(cvy)/command.acceleration)*fabs(cvy)/2);

    if(ayp>=0){
        ay=ayp+ky*(command.acceleration-ayp);
    }else{
        ay=ayp+ky*(command.acceleration+ayp);
    }

    apply(batter,ax,ay);



}

void Controller::apply(b2Body* body,float ax, float ay){
    motionManager->applyAcceleration(body,ax,ay);
//    motionManager->applyAcceleration(body,1.0f,1.0f);
}
