#include "mainwindow.h"
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    mMotionManager=new MotionManager();
    controller=new Controller();
    controller->motionManager=mMotionManager;
    strategySystem=new StrategySystem();
    strategySystem->motionManager=mMotionManager;
    strategySystem->controller=this->controller;

//    gameManager=new GameManager();
//    gameManager->motionManager=mMotionManager;
//    gameManager->setMode(0);
    resize(800,680);
    startButton=new QPushButton("Start",this);
    connect(startButton,SIGNAL(clicked(bool)),this,SLOT(launch()));
    //update();

    //暂时用qt的计时器触发绘图
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(step()));
    timer->start(16);
}

MainWindow::~MainWindow()
{
//    delete gameManager;
    delete mMotionManager;
    delete controller;
    delete strategySystem;

}


void MainWindow::paintEvent(QPaintEvent *event){
    this->updateGameDrawing();//更新游戏图形
}

void MainWindow::updateGameDrawing(){
    //绘制所有实体
    for (int t=0;t<mMotionManager->getBodyAmount();t++){
        drawBody(mMotionManager->getEneity(t));
    }

    float x=mMotionManager->ball->GetPosition().x;
    float y=mMotionManager->ball->GetPosition().y;

    QPainter painter(this);
    painter.drawText(600,100,QString("x:%1").arg(x));
    painter.drawText(600,150,QString("y:%1").arg(y));
}


void MainWindow::drawBody(PsyEntity *psyEntity){

    //设置qt画笔
    if(psyEntity->body->IsActive()==false){
        return;
    }

    QPainter painter(this);
    QColor hourColor(127, 0, 127);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.save();

    int x=0,y=0,r=0;

    //根据实体类型进行绘图
    switch (psyEntity->type) {
    case 1:

        x=int((psyEntity->body->GetPosition().x)*30+60);
        y=int(640-(psyEntity->body->GetPosition().y)*30);
        r=int(psyEntity->r*30);
        painter.drawEllipse(x-r,y-r,2*r,2*r);
        painter.restore();
        break;

    case 2:
        x=int((psyEntity->body->GetPosition().x-psyEntity->w/2)*30+60);
        y=int(640-(psyEntity->body->GetPosition().y+psyEntity->h/2)*30);

        painter.drawRect(x,y,psyEntity->w*30,psyEntity->h*30);
        painter.restore();

        break;
    default:
        break;
    }
}
//调用motion manager的step方法
void MainWindow::step(){



    mMotionManager->step();
    update();
    strategySystem->calculate();
}

void MainWindow::launch(){
    this->mMotionManager->launch();
}

