#ifndef ScalingGraphicsView_H
#define ScalingGraphicsView_H

#include <QGraphicsView>
#include <QObject>

QT_BEGIN_NAMESPACE
class QWheelEvent;
QT_END_NAMESPACE
/**
 * @brief
 * 重写QGraphicsView，对图节点模块的显示实现放缩功能
 */
class ScalingGraphicsView:public QGraphicsView
{
    Q_OBJECT
public:
    explicit ScalingGraphicsView(QWidget *parent = 0);
    ~ScalingGraphicsView();
    int b;

protected:
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
    qreal scale_m;
};

#endif // ScalingGraphicsView_H


