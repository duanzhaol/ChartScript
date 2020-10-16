CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(graphicsdataarraynodepluginplugin)
TEMPLATE    = lib

HEADERS     = GraphicsDataArrayNodePluginPlugin.h
SOURCES     = GraphicsDataArrayNodePluginPlugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(graphicsdataarraynodeplugin.pri)
include(../../../NodeShow.pri)
include(../../../../Interpreter/Interpreter.pri)

INCLUDEPATH += C:\MyApplication\QTProject\ChartScript2\Interpreter\ChartScript \
 D:\QtProjects\NodeShow\ChartScript
