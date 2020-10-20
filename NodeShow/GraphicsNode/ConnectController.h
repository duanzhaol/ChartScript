#ifndef CONNECTCONTROLLER_H
#define CONNECTCONTROLLER_H
#include <ConnectLineItem.h>
#include <QObject>
#include <GraphicsDataArrayNode.h>

class ConnectController:public QObject
{
    Q_OBJECT
public:

    static ConnectController* getInstance();
    void connectLineWuhu(Inputable* input,Outputable* output);
    QList<ConnectLineItem*> LineList;
	void drawLine();

    Inputable* input=nullptr;
    Outputable* output=nullptr;
//    void* inputOrigin=nullptr;
//    void* outputOrigin=nullptr;

public slots:
    void ConnectLine(QPushButton*,AbstractGraphicsNode::PortType);
    void clearPort();

private:
    GraphicsDataArrayNode* arrayNode;
    QList<QPushButton*> twoList;
    ConnectController();
    static ConnectController* instance;

};

#endif // CONNECTCONTROLLER_H
