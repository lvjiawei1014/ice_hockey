#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "motionmanager.h"
#include <QtWidgets>
#include "gamemanager.h"
#include "strategysystem.h"
#include "controller.h"

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QPushButton* startButton;
    MotionManager* mMotionManager;  //物理模块对象
    GameManager* gameManager;
    StrategySystem* strategySystem;
    Controller* controller;


public:


    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void updateGameDrawing();
    void drawBody(PsyEntity* psyEntity);

public slots:
    void step();
    void launch();

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
};

#endif // MAINWINDOW_H
