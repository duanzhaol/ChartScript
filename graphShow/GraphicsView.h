#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H


#include <QGraphicsView>
#include <QObject>
#include <QtCharts/QChartView>

QT_BEGIN_NAMESPACE
class QWheelEvent;
QT_END_NAMESPACE

class GraphicsView:public QGraphicsView
{
    Q_OBJECT
public:
	explicit GraphicsView(QWidget *parent = nullptr);

protected:
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

private:
    qreal scale_m;
};

#endif // GRAPHICSVIEW_H
