#ifndef ScalingGraphicsView_H
#define ScalingGraphicsView_H

#include <QGraphicsView>
#include <QObject>

QT_BEGIN_NAMESPACE
class QWheelEvent;
QT_END_NAMESPACE

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


