#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H


#include <QGraphicsView>
#include <QObject>

QT_BEGIN_NAMESPACE
class QWheelEvent;
QT_END_NAMESPACE

class GraphicsView:public QGraphicsView
{
    Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = 0);

protected:
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
    qreal scale_m;
};

#endif // GRAPHICSVIEW_H
