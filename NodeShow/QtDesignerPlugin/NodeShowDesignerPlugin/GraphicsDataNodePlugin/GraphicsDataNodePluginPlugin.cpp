#include "../../NodeShow/GraphicsNode/GraphicsDataNode.h"
#include "GraphicsDataNodePluginPlugin.h"

#include <QtPlugin>

GraphicsDataNodePluginPlugin::GraphicsDataNodePluginPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void GraphicsDataNodePluginPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool GraphicsDataNodePluginPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *GraphicsDataNodePluginPlugin::createWidget(QWidget *parent)
{
    return new GraphicsDataNode(parent);
}

QString GraphicsDataNodePluginPlugin::name() const
{
    return QLatin1String("GraphicsDataNodePlugin");
}

QString GraphicsDataNodePluginPlugin::group() const
{
    return QLatin1String("NodeShowPlugins");
}

QIcon GraphicsDataNodePluginPlugin::icon() const
{
    return QIcon();
}

QString GraphicsDataNodePluginPlugin::toolTip() const
{
    return QLatin1String("");
}

QString GraphicsDataNodePluginPlugin::whatsThis() const
{
    return QLatin1String("放数据节点，端口ui插件的组");
}

bool GraphicsDataNodePluginPlugin::isContainer() const
{
    return false;
}

QString GraphicsDataNodePluginPlugin::domXml() const
{
    return QLatin1String("<widget class=\"GraphicsDataNodePlugin\" name=\"graphicsDataNodePlugin\">\n</widget>\n");
}

QString GraphicsDataNodePluginPlugin::includeFile() const
{
    return QLatin1String("../../NodeShow/GraphicsNode/GraphicsDataNode.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(graphicsdatanodepluginplugin, GraphicsDataNodePluginPlugin)
#endif // QT_VERSION < 0x050000
