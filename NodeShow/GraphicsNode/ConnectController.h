﻿#ifndef CONNECTCONTROLLER_H
#define CONNECTCONTROLLER_H
#include <ConnectLineItem.h>
#include <QObject>
#include <GraphicsDataArrayNode.h>
#include <PortWidget.h>

class ConnectController:public QObject
{
    Q_OBJECT
public:

    static ConnectController* getInstance();
    void connectLineWuhu(InputPortWidget* input,OutputPortWidget* output);
    QList<ConnectLineItem*> LineList;
    void ConnectController::drawLine();

    InputPortWidget* input=nullptr;
    OutputPortWidget* output=nullptr;

public slots:
	void ConnectLine(PortWidget*,PortWidget::PortType);


private:
    GraphicsDataArrayNode* arrayNode;
    QList<QPushButton*> twoList;
    ConnectController();
    static ConnectController* instance;

};

#endif // CONNECTCONTROLLER_H
