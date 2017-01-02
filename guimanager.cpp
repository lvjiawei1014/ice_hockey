#include "guimanager.h"

GuiManager::GuiManager()
{
    //QPainter painter(pMainWindow);
    //QColor hourColor(127, 0, 127);

    //(*painter).setRenderHint(QPainter::Antialiasing);
    //painter.translate(width() / 2, height() / 2);
    //painter.scale(side / 200.0, side / 200.0);
    //(*painter).setPen(Qt::NoPen);
    //(*painter).setBrush(hourColor);
    //(*painter).save();

    //painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    //painter.restore();
}
GuiManager::~GuiManager(){

}

void GuiManager::updateGameDrawing(){
    MotionManager::BodyState* pBodyState=(*pMotionManager).getBodyStates();
    for (int i=0;i<(*pMotionManager).getBodyAmount();i++){
        drawBody(*(pBodyState+i));
    }
}

void GuiManager::drawBody(MotionManager::BodyState bodyState){
    int x=0,y=0;
    switch (bodyState.type) {

    case 2:
        x=int(bodyState.pBody->GetPosition().x-bodyState.x/2);
        y=int(200-bodyState.pBody->GetPosition().y-bodyState.y/2);
        //painter.translate(x,y);
        //(*painter).drawRect(x,y,bodyState.x,bodyState.y);
        //(*painter).restore();
        break;
    default:
        break;
    }
}

void GuiManager::setMotionManager(MotionManager *pMotionManager){
    this->pMotionManager=pMotionManager;
}
void GuiManager::setPainter(QPainter* painter){
    this->painter=painter;
}
