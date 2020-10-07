RESOURCES += \
    $$PWD/resource.qrc

FORMS += \
	$$PWD/GraphicsNode/GraphicsAreaSeriesNode.ui \
	$$PWD/GraphicsNode/GraphicsChartNode.ui \
	$$PWD/GraphicsNode/GraphicsDataArrayNode.ui \
	$$PWD/GraphicsNode/GraphicsDataNode.ui \
	$$PWD/GraphicsNode/GraphicsLineSeriesNode.ui \
	$$PWD/GraphicsNode/GraphicsPieSeriesNode.ui \
	$$PWD/GraphicsNode/GraphicsScatterSeriesNode.ui \
	$$PWD/GraphicsNode/GraphicsStartNode.ui \
	$$PWD/GraphicsNode/NodeShowWindow.ui \
	$$PWD/GraphicsNode/Port.ui \
	$$PWD/GraphicsNode/ResizeTest.ui

HEADERS += \
	$$PWD/ConnectLine/ConnectLineItem.h \
	$$PWD/GraphicsNode/DualPortWidget.h \
	$$PWD/GraphicsNode/GraphicsAreaSeriesNode.h \
	$$PWD/GraphicsNode/GraphicsChartNode.h \
	$$PWD/GraphicsNode/GraphicsDataArrayNode.h \
	$$PWD/GraphicsNode/GraphicsDataNode.h \
	$$PWD/GraphicsNode/GraphicsLineSeriesNode.h \
	$$PWD/GraphicsNode/GraphicsPieSeriesNode.h \
	$$PWD/GraphicsNode/GraphicsScatterSeriesNode.h \
	$$PWD/GraphicsNode/GraphicsStartNode.h \
	$$PWD/GraphicsNode/InputPortWidget.h \
	$$PWD/GraphicsNode/NodeShowWindow.h \
	$$PWD/GraphicsNode/OutputPortWidget.h \
	$$PWD/GraphicsNode/Port.h \
	$$PWD/GraphicsNode/PortWidget.h \
	$$PWD/GraphicsNode/ResizeTest.h \
	$$PWD/GraphicsNode/ScalingGraphicsView.h \
	$$PWD/NodeShowInitializer.h \
	$$PWD/ProxyWidget/MovableDualPortProxyWidget.h \
	$$PWD/ProxyWidget/MovableInputPortProxyWidget.h \
	$$PWD/ProxyWidget/MovableOutputPortProxyWidget.h \
	$$PWD/ProxyWidget/MovableProxyWidget.h

SOURCES += \
	$$PWD/ConnectLine/ConnectLineItem.cpp \
	$$PWD/GraphicsNode/DualPortWidget.cpp \
	$$PWD/GraphicsNode/GraphicsAreaSeriesNode.cpp \
	$$PWD/GraphicsNode/GraphicsChartNode.cpp \
	$$PWD/GraphicsNode/GraphicsDataArrayNode.cpp \
	$$PWD/GraphicsNode/GraphicsDataNode.cpp \
	$$PWD/GraphicsNode/GraphicsLineSeriesNode.cpp \
	$$PWD/GraphicsNode/GraphicsPieSeriesNode.cpp \
	$$PWD/GraphicsNode/GraphicsScatterSeriesNode.cpp \
	$$PWD/GraphicsNode/GraphicsStartNode.cpp \
	$$PWD/GraphicsNode/InputPortWidget.cpp \
	$$PWD/GraphicsNode/NodeShowWindow.cpp \
	$$PWD/GraphicsNode/OutputPortWidget.cpp \
	$$PWD/GraphicsNode/Port.cpp \
	$$PWD/GraphicsNode/PortWidget.cpp \
	$$PWD/GraphicsNode/ResizeTest.cpp \
	$$PWD/GraphicsNode/ScalingGraphicsView.cpp \
	$$PWD/NodeShowInitializer.cpp \
	$$PWD/ProxyWidget/MovableDualPortProxyWidget.cpp \
	$$PWD/ProxyWidget/MovableInputPortProxyWidget.cpp \
	$$PWD/ProxyWidget/MovableOutputPortProxyWidget.cpp \
	$$PWD/ProxyWidget/MovableProxyWidget.cpp \

INCLUDEPATH += \
	$$PWD/ConnectLine \
	$$PWD/GraphicsNode \
	$$PWD/ProxyWidget \
	$$PWD/../../Interpreter


