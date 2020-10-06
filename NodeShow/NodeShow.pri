RESOURCES += \
    $$PWD/resource.qrc

FORMS += \
	$$PWD/GraphicsNode/GraphicsDataArrayNode.ui \
	$$PWD/GraphicsNode/GraphicsDataNode.ui \
	$$PWD/GraphicsNode/GraphicsStartNode.ui \
	$$PWD/GraphicsNode/Port.ui

HEADERS += \
	$$PWD/ConnectLine/ConnectLineItem.h \
	$$PWD/GraphicsNode/DualPortWidget.h \
	$$PWD/GraphicsNode/GraphicsDataArrayNode.h \
	$$PWD/GraphicsNode/GraphicsDataNode.h \
	$$PWD/GraphicsNode/GraphicsStartNode.h \
	$$PWD/GraphicsNode/InputPortWidget.h \
	$$PWD/GraphicsNode/OutputPortWidget.h \
	$$PWD/GraphicsNode/Port.h \
	$$PWD/GraphicsNode/PortWidget.h \
	$$PWD/ProxyWidget/MovableDualPortProxyWidget.h \
	$$PWD/ProxyWidget/MovableInputPortProxyWidget.h \
	$$PWD/ProxyWidget/MovableOutputPortProxyWidget.h \
	$$PWD/ProxyWidget/MovableProxyWidget.h

SOURCES += \
	$$PWD/ConnectLine/ConnectLineItem.cpp \
	$$PWD/GraphicsNode/DualPortWidget.cpp \
	$$PWD/GraphicsNode/GraphicsDataArrayNode.cpp \
	$$PWD/GraphicsNode/GraphicsDataNode.cpp \
	$$PWD/GraphicsNode/GraphicsStartNode.cpp \
	$$PWD/GraphicsNode/InputPortWidget.cpp \
	$$PWD/GraphicsNode/OutputPortWidget.cpp \
	$$PWD/GraphicsNode/Port.cpp \
	$$PWD/GraphicsNode/PortWidget.cpp \
	$$PWD/ProxyWidget/MovableDualPortProxyWidget.cpp \
	$$PWD/ProxyWidget/MovableInputPortProxyWidget.cpp \
	$$PWD/ProxyWidget/MovableOutputPortProxyWidget.cpp \
	$$PWD/ProxyWidget/MovableProxyWidget.cpp \

INCLUDEPATH += \
	$$PWD/ConnectLine \
	$$PWD/GraphicsNode \
	$$PWD/ProxyWidget
	$$PWD/../../Interpreter


