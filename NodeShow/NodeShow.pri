RESOURCES += \
    $$PWD/resource.qrc

FORMS += \
	$$PWD/GraphicsDataNode.ui \
	$$PWD/GraphicsStartNode.ui

HEADERS += \
    $$PWD/ConnectLineItem.h \
    $$PWD/DualPortInterface.h \
    $$PWD/GraphicsDataNode.h \
    $$PWD/GraphicsStartNode.h \
    $$PWD/InputPortInterface.h \
    $$PWD/MovableProxyWidget.h \
    $$PWD/MovableSinglePortProxyWidget.h \
    $$PWD/OutputPortInterface.h \
    $$PWD/PortInterface.h

SOURCES += \
    $$PWD/ConnectLineItem.cpp \
    $$PWD/GraphicsDataNode.cpp \
    $$PWD/GraphicsStartNode.cpp \
    $$PWD/MovableProxyWidget.cpp \
    $$PWD/MovableSinglePortProxyWidget.cpp \
    $$PWD/main.cpp
