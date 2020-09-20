#include "PortPlugin.h"
#include "PortPluginPlugin.h"
#include "../../NodeShow/GraphicsNode/Port.h"
#include <QtPlugin>

PortPluginPlugin::PortPluginPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void PortPluginPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool PortPluginPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *PortPluginPlugin::createWidget(QWidget *parent)
{
    return new Port(parent);
}

QString PortPluginPlugin::name() const
{
    return QLatin1String("PortPlugin");
}

QString PortPluginPlugin::group() const
{
    return QLatin1String("NodeShowPlugins");
}

QIcon PortPluginPlugin::icon() const
{
    return QIcon();
}

QString PortPluginPlugin::toolTip() const
{
    return QLatin1String("");
}

QString PortPluginPlugin::whatsThis() const
{
    return QLatin1String("Port ui插件");
}

bool PortPluginPlugin::isContainer() const
{
    return false;
}

QString PortPluginPlugin::domXml() const
{
    return QLatin1String("<widget class=\"PortPlugin\" name=\"portPlugin\">\n</widget>\n");
}

QString PortPluginPlugin::includeFile() const
{
    return QLatin1String("../../NodeShow/GraphicsNode/Port.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(portpluginplugin, PortPluginPlugin)
#endif // QT_VERSION < 0x050000
