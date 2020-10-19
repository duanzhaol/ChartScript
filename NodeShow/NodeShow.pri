RESOURCES += \
    $$PWD/resource.qrc

FORMS += \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsAreaSeriesNode.ui \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsDataArrayNode.ui \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsDataNode.ui \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsLineSeriesNode.ui \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsPieSeriesNode.ui \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsScatterSeriesNode.ui \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/GraphicsChartNode.ui \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/GraphicsStartNode.ui \
	$$PWD/GraphicsNode/NodeShowWindow.ui \
	$$PWD/GraphicsNode/Port.ui \
	$$PWD/GraphicsNode/ResizeTest.ui

HEADERS += \
	$$PWD/ConnectLine/ConnectLineItem.h \
	$$PWD/GraphicsNode/ConnectController.h \
	$$PWD/GraphicsNode/GraphicsNode/AbstractGraphicsNode.h \
	$$PWD/GraphicsNode/GraphicsNode/ArrayInterface.h \
	$$PWD/GraphicsNode/GraphicsNode/Dualputable.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/AbstractGraphicsInnerDualputNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/AbstractGraphicsInnerNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsAreaSeriesNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsDataArrayNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsDataNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsLineSeriesNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsPieSeriesNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsScatterSeriesNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/AbstractGraphicsTopDualoutNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/AbstractGraphicsTopNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/GraphicsChartNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/GraphicsStartNode.h \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/GraphicsTopArrayNode.h \
	$$PWD/GraphicsNode/GraphicsNode/Inputable.h \
	$$PWD/GraphicsNode/GraphicsNode/Outputable.h \
	$$PWD/GraphicsNode/NodeListWidget.h \
	$$PWD/GraphicsNode/NodeListWidgetItem.h \
	$$PWD/GraphicsNode/NodeShowWindow.h \
	$$PWD/GraphicsNode/Port.h \
	$$PWD/GraphicsNode/ResizeTest.h \
	$$PWD/GraphicsNode/ScalingGraphicsView.h \
	$$PWD/NodeShowInitializer.h \
	$$PWD/ProxyWidget/MovableProxyWidget.h

SOURCES += \
	$$PWD/ConnectLine/ConnectLineItem.cpp \
	$$PWD/GraphicsNode/ConnectController.cpp \
	$$PWD/GraphicsNode/GraphicsNode/AbstractGraphicsNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/DualPortWidget.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/AbstractGraphicsInnerDualputNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/AbstractGraphicsInnerNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsAreaSeriesNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsDataArrayNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsDataNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsLineSeriesNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsPieSeriesNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsScatterSeriesNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/AbstractGraphicsTopDualoutNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/AbstractGraphicsTopNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/GraphicsChartNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/GraphicsStartNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsTopNode/GraphicsTopArrayNode.cpp \
	$$PWD/GraphicsNode/GraphicsNode/InputPortWidget.cpp \
	$$PWD/GraphicsNode/GraphicsNode/OutputPortWidget.cpp \
	$$PWD/GraphicsNode/NodeListWidget.cpp \
	$$PWD/GraphicsNode/NodeListWidgetItem.cpp \
	$$PWD/GraphicsNode/NodeShowWindow.cpp \
	$$PWD/GraphicsNode/Port.cpp \
	$$PWD/GraphicsNode/ResizeTest.cpp \
	$$PWD/GraphicsNode/ScalingGraphicsView.cpp \
	$$PWD/NodeShowInitializer.cpp \
	$$PWD/ProxyWidget/MovableProxyWidget.cpp

INCLUDEPATH += \
	$$PWD/ConnectLine \
	$$PWD/GraphicsNode \
	$$PWD/ProxyWidget \
	$$PWD/../../Interpreter \
	$$PWD/GraphicsNode \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode \
	$$PWD/GraphicsNode/GraphicsNOde/GraphicsTopNode

DEPENDPATH += \
	$$PWD/GraphicsNode/GraphicsNode/GraphicsInnerNode
