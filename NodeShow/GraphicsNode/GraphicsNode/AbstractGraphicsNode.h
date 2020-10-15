#ifndef ABSTRACTGRAPHICSNODE_H
#define ABSTRACTGRAPHICSNODE_H

#include <QWidget>
#include <MovableProxyWidget.h>

class AbstractGraphicsNode:public QWidget{
    Q_OBJECT
public:

	AbstractGraphicsNode(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    enum class PortType{InputPort,OutputPort};

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    void connectToLineController();


signals:
	void PortClicked(AbstractGraphicsNode*,PortType);
};



#endif // ABSTRACTGRAPHICSNODE_H
