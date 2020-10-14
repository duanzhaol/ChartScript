#include "ConnectController.h"
#include <QDebug>

ConnectController *ConnectController::getInstance()
{
    return instance;
}

ConnectController::ConnectController()
{

}

void ConnectController::ConnectLine(PortWidget*, PortWidget::PortType)
{
    qDebug()<<"wuhuqifei";
    //    qDebug()<<twoList.length();
    //    twoList.append(port);
    //    qDebug()<<twoList.length();
}


ConnectController* ConnectController::instance=new ConnectController();
