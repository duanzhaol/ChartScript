#include "GraphicsImageItem.h"


GraphicsImageItem::GraphicsImageItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
	AbstractGraphicsItem(parent),
	originImage(":/GraphShowImage/image/addPixmap.png"),
	scaledImage(originImage)
{
	setCoordinate(QRectF(x,y,width,height));
}


void GraphicsImageItem::SLOT_openAttributeWidget()
{
	dialog = new PixmapItemDialog(originImage);
	dialog->show();
	connect(dialog,&PixmapItemDialog::accepted,this,&GraphicsImageItem::setAttr);
}

void GraphicsImageItem::setCoordinate(const QRectF &pos)
{
	setRect(pos);
	scaledImage = originImage.scaled(pos.size().toSize(),
								Qt::AspectRatioMode::IgnoreAspectRatio,
								Qt::TransformationMode::SmoothTransformation
								);

}

void GraphicsImageItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	AbstractGraphicsItem::paint(painter,option,widget);
	painter->drawImage(boundingRect(),scaledImage,boundingRect());
}

void GraphicsImageItem::setAttr()
{
	originImage = dialog->getImage();
	setCoordinate(boundingRect());
	this->update();
}
