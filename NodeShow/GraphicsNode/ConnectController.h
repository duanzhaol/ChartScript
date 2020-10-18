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
    AbstractGraphicsNode* inputOrigin=nullptr;
    AbstractGraphicsNode* outputOrigin=nullptr;

public slots:
	void ConnectLine(AbstractGraphicsNode*,AbstractGraphicsNode::PortType);


private:
    GraphicsDataArrayNode* arrayNode;
    QList<QPushButton*> twoList;
    ConnectController();
    static ConnectController* instance;

};

#endif // CONNECTCONTROLLER_H
