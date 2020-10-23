#ifndef ABSTRACTGRAPHICSNODE_H
#define ABSTRACTGRAPHICSNODE_H

#include <QWidget>
#include <MovableProxyWidget.h>
#include <QPushButton>

/**
 * @brief
 * 所有可视化图节点的抽象父类，实现了发送端口点击信号
 */

class AbstractGraphicsNode:public QWidget{
    Q_OBJECT
public:

	AbstractGraphicsNode(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	//! 端口类型
	enum class PortType{
		InputPort, //!< 输入端口
		OutputPort //!<输出端口
	};

protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
    void connectToLineController();


signals:
    void PortClicked(QPushButton*,PortType);
};



#endif // ABSTRACTGRAPHICSNODE_H
