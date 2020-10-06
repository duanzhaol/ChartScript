#ifndef ZHUGRAPHICSVIEW_H
#define ZHUGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QObject>

QT_BEGIN_NAMESPACE
class QWheelEvent;
QT_END_NAMESPACE

class ZhuGraphicsView:public QGraphicsView
{
    Q_OBJECT
public:
    explicit ZhuGraphicsView(QWidget *parent = 0);
    ~ZhuGraphicsView();

protected:
    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;
    void magnify();
    void shrink();
    void scaling(qreal scaleFactor);

private:
    qreal m_scalingOffset;
};

#endif // ZHUGRAPHICSVIEW_H


