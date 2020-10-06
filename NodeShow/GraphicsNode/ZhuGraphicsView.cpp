#include "ZhuGraphicsView.h"
#include <QWheelEvent>
#include <QPoint>
#include <QDebug>

ZhuGraphicsView::ZhuGraphicsView(QWidget *parent): QGraphicsView(parent)
{
    m_scalingOffset=1;
}

ZhuGraphicsView::~ZhuGraphicsView()
{

}

void ZhuGraphicsView::magnify()
{
    if(m_scalingOffset>2)
        return;

    m_scalingOffset+=0.1;
    scaling(m_scalingOffset);
}

void ZhuGraphicsView::shrink()
{
    if(m_scalingOffset<0.1)
        return;

    m_scalingOffset-=0.1;
    scaling(m_scalingOffset);
}

void ZhuGraphicsView::scaling(qreal scaleFactor)
{
    qDebug()<<this->sceneRect();
    scale(scaleFactor,scaleFactor);
}

void ZhuGraphicsView::wheelEvent(QWheelEvent *event)
{
    QPoint sroll=event->angleDelta();
    sroll.y()>0?magnify():shrink();
}
