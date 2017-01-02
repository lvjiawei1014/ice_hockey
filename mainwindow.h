#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "guimanager.h"
#include "motionmanager.h"
#include<QtWidgets>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    //MotionManager mMotionManager;
    //QPainter painter;

public:


    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //GuiManager mGuiManager;

    void updateGameDrawing();
    void drawBody(MotionManager::BodyState bodyState);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // MAINWINDOW_H
