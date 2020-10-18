#include "GraphicsEllipseItem.h"


GRAPHICS_SHAPDE_DEFINE_CPP(GraphicsEllipseItem)



void GraphicsEllipseItem::setCoordinate(const QRectF &pos)
{
	setRect(pos);
}
