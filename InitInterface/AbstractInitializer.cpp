
#include "AbstractInitializer.h"


AbstractInitializer::AbstractInitializer()
{

}

QWidget *AbstractInitializer::getWidget()
{
	Q_ASSERT(widget != nullptr);
	return widget;
}
