CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(graphicsdatanodepluginplugin)
TEMPLATE    = lib

HEADERS     = GraphicsDataNodePluginPlugin.h
SOURCES     = GraphicsDataNodePluginPlugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(graphicsdatanodeplugin.pri)
include(../../../NodeShow.pri)
include(../../../../Interpreter/Interpreter.pri)

INCLUDEPATH += C:\MyApplication\QTProject\ChartScript2\Interpreter\ChartScript \
               D:\QtProjects\NodeShow\ChartScript


