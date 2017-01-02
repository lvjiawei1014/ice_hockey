#include "mainwindow.h"
#include <QtWidgets>

MotionManager mMotionManager=MotionManager();


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //painter=painter(this);
    //mGuiManager.setMotionManager(&mMotionManager);
    //mMotionManager=MotionManager();
    //resize(400,400);
    //MotionManager mMotionManager();
    //QPainter painter(this);
    update();
}

MainWindow::~MainWindow()
{

}
void MainWindow::paintEvent(QPaintEvent *event){


    static const QPoint hourHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -40)
    };
    static const QPoint minuteHand[3] = {
        QPoint(7, 8),
        QPoint(-7, 8),
        QPoint(0, -70)
    };

    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();

    QPainter painter(this);


    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / 200.0, side / 200.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.save();

    painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawConvexPolygon(hourHand, 3);
    painter.restore();

    //mGuiManager.updateGameDrawing();
    this->updateGameDrawing();
}

void MainWindow::updateGameDrawing(){
    //MotionManager mMotionManager=MotionManager();

    MotionManager::BodyState* pBodyState=mMotionManager.getBodyStates();
    for (int i=0;i<mMotionManager.getBodyAmount();i++){
        drawBody(*(pBodyState+i));
    }
}

void MainWindow::drawBody(MotionManager::BodyState bodyState){


    QPainter painter(this);
    QColor hourColor(127, 0, 127);
    QColor minuteColor(0, 127, 127, 191);

    int side = qMin(width(), height());
    QTime time = QTime::currentTime();




    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    //painter.scale(side / 200.0, side / 200.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.save();


    int x=0,y=0;
    switch (bodyState.type) {

    case 2:
        x=int(bodyState.pBody->GetPosition().x-bodyState.x/2);
        y=int(200-bodyState.pBody->GetPosition().y-bodyState.y/2);

        painter.drawRect(x,y,bodyState.x,bodyState.y);
        painter.restore();
        break;
    default:
        break;
    }
}
