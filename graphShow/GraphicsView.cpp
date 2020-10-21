#include "GraphicsScene.h"
#include "GraphicsView.h"
#include <QWheelEvent>
#include <QPoint>
#include <QDebug>
#include <QtMath>
GraphicsView::GraphicsView(QWidget *parent): QGraphicsView(parent)
{
    setDragMode(QGraphicsView::NoDrag);//(QGraphicsView::RubberBandDrag);//QGraphicsView::ScrollHandDrag
    scale_m = 1;//图形原始比例
	//setStyleSheet("padding: 0px; border: 0px;");//无边框
    setMouseTracking(true);//跟踪鼠标位置
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
	setViewportUpdateMode(ViewportUpdateMode::FullViewportUpdate);
	setAlignment(Qt::AlignLeft | Qt::AlignTop);
	QBrush brush;
	brush.setColor(Qt::GlobalColor::white);
	brush.setStyle(Qt::BrushStyle::NoBrush);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏水平条
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//隐藏竖条
	setBackgroundBrush(brush);
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() == Qt::CTRL)
    {//按住ctrl键 可以放大缩小
        if((event->delta() > 0)&&(scale_m >= 50))//最大放大到原始图像的50倍
        {
            return;
        }
        else if((event->delta() < 0)&&(scale_m <= 0.01))//图像缩小到自适应大小之后就不继续缩小
        {
            return;//重置图片大小和位置，使之自适应控件窗口大小
        }
        else
        {
            // 当前放缩倍数;
            qreal scaleFactor = this->matrix().m11();
            scale_m = scaleFactor;

            int wheelDeltaValue = event->delta();
            // 向上滚动，放大;
            if (wheelDeltaValue > 0)
            {
                this->scale(1.2, 1.2);
            }
            else
            {// 向下滚动，缩小;
                this->scale(1.0 / 1.2, 1.0 / 1.2);
            }
            update();
        }
    }
}

std::optional<QImage> GraphicsView::getImage() const
{
	return image;
}

void GraphicsView::setImage(const std::optional<QImage> &value)
{
	image = value->scaled(this->size());
}

QPixmap *GraphicsView::getPixmap()
{
	QPixmap *pixmap = new QPixmap(size());
	pixmap->fill(Qt::white);
	QPainter painter = QPainter(pixmap);

	this->render(&painter);

	return pixmap;
}


void GraphicsView::drawBackground(QPainter *painter, const QRectF &rect)
{
	QGraphicsView::drawBackground(painter,rect);

	if(image.has_value()){
		const QRectF drawRect(QPointF(0,0),size());
		painter->drawImage(drawRect,image.value(),drawRect);
	}
}
