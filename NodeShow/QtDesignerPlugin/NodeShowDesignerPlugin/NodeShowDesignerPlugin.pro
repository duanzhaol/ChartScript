CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(portplugin)
TEMPLATE    = lib

HEADERS     = PortPlugin.h \
	Port.h
SOURCES     = PortPlugin.cpp \
	Port.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(port.pri)

FORMS += \
	Port.ui
