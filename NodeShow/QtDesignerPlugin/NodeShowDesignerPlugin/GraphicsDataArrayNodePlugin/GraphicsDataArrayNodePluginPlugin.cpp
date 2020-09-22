#include "GraphicsDataArrayNodePlugin.h"
#include "GraphicsDataArrayNodePluginPlugin.h"
#include "../../NodeShow/GraphicsNode/GraphicsDataArrayNode.h"

#include <QtPlugin>

GraphicsDataArrayNodePluginPlugin::GraphicsDataArrayNodePluginPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void GraphicsDataArrayNodePluginPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool GraphicsDataArrayNodePluginPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *GraphicsDataArrayNodePluginPlugin::createWidget(QWidget *parent)
{
    return new GraphicsDataArrayNode(parent);
}

QString GraphicsDataArrayNodePluginPlugin::name() const
{
    return QLatin1String("GraphicsDataArrayNodePlugin");
}

QString GraphicsDataArrayNodePluginPlugin::group() const
{
    return QLatin1String("NodeShowPlugins");
}

QIcon GraphicsDataArrayNodePluginPlugin::icon() const
{
    return QIcon();
}

QString GraphicsDataArrayNodePluginPlugin::toolTip() const
{
    return QLatin1String("");
}

QString GraphicsDataArrayNodePluginPlugin::whatsThis() const
{
    return QLatin1String("数列节点插件");
}

bool GraphicsDataArrayNodePluginPlugin::isContainer() const
{
    return false;
}

QString GraphicsDataArrayNodePluginPlugin::domXml() const
{
    return QLatin1String("<widget class=\"GraphicsDataArrayNodePlugin\" name=\"graphicsDataArrayNodePlugin\">\n</widget>\n");
}

QString GraphicsDataArrayNodePluginPlugin::includeFile() const
{
    return QLatin1String("../../NodeShow/GraphicsNode/GraphicsDataArrayNode.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(graphicsdataarraynodepluginplugin, GraphicsDataArrayNodePluginPlugin)
#endif // QT_VERSION < 0x050000
