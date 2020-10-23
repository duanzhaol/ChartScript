#ifndef CONNECTCONTROLLER_H
#define CONNECTCONTROLLER_H
#include <ConnectLineItem.h>
#include <QObject>
#include <GraphicsDataArrayNode.h>

/**
 * @brief
 * 图节点编程中的连接线控制器。
 * 监听图节点中输入输出端口的信号，判断连接的合法性并连接两个端口
 */

class ConnectController:public QObject
{
    Q_OBJECT
public:

    static ConnectController* getInstance();
    void connectLineWuhu(Inputable* input,Outputable* output);

    QHash<int,ConnectLineItem*> LineList;

	void drawLine();
    ConnectLineItem* getLineItem(int index);

    Inputable* input=nullptr;
    Outputable* output=nullptr;
//    void* inputOrigin=nullptr;
//    void* outputOrigin=nullptr;
    int indexForLines=20001;

public slots:
    void ConnectLine(QPushButton*,AbstractGraphicsNode::PortType);
    void clearPort();
    void removeLineItem(ConnectLineItem*);

private:
    GraphicsDataArrayNode* arrayNode;
    QList<QPushButton*> twoList;
    ConnectController();
    static ConnectController* instance;

};

#endif // CONNECTCONTROLLER_H
