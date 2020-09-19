#include "Port.h"
#include "PortPlugin.h"

#include <QtPlugin>

PortPlugin::PortPlugin(QObject *parent)
	: QObject(parent)
{
	m_initialized = false;
}

void PortPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
	if (m_initialized)
		return;

	// Add extension registrations, etc. here

	m_initialized = true;
}

bool PortPlugin::isInitialized() const
{
	return m_initialized;
}

QWidget *PortPlugin::createWidget(QWidget *parent)
{
	return new Port(parent);
}

QString PortPlugin::name() const
{
	return QLatin1String("Port");
}

QString PortPlugin::group() const
{
	return QLatin1String("GraphicsShow");
}

QIcon PortPlugin::icon() const
{
	return QIcon();
}

QString PortPlugin::toolTip() const
{
	return QLatin1String("");
}

QString PortPlugin::whatsThis() const
{
	return QLatin1String("Input and Output Port");
}

bool PortPlugin::isContainer() const
{
	return false;
}

QString PortPlugin::domXml() const
{
	return QLatin1String("<widget class=\"Port\" name=\"port\">\n</widget>\n");
}

QString PortPlugin::includeFile() const
{
	return QLatin1String("Port.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(portplugin, PortPlugin)
#endif // QT_VERSION < 0x050000
