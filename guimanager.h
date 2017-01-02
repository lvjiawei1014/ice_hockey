
#ifndef GUIMANAGER_H
#define GUIMANAGER_H
#include<QtWidgets>
#include "motionmanager.h"
class GuiManager{
public :

    GuiManager();
    ~GuiManager();

    //MainWindow* pMainWindow;
    MotionManager* pMotionManager;
    QPainter* painter;


    void setMotionManager(MotionManager *pMotionManager);
    MotionManager* getMotionManager();

    void updateGameDrawing();//更新图形
    void drawBody(MotionManager::BodyState bodyState);
    void setPainter(QPainter* painter);

};

#endif // GUIMANAGER_H
