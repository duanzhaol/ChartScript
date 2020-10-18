#include "GraphicsRectItem.h"

GRAPHICS_SHAPDE_DEFINE_CPP(GraphicsRectItem)



void GraphicsRectItem::setCoordinate(const QRectF &pos)
{
	setRect(pos);
}
