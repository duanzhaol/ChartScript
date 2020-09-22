SOURCES += \
	$$PWD/DataModel/AbstractArrayNode.cpp \
	$$PWD/DataModel/AbstractDataNode.cpp \
	$$PWD/DataModel/AbstractLineSeriesNode.cpp \
	$$PWD/DataModel/AbstractNode.cpp \
	$$PWD/DataModel/AbstractSeriesNode.cpp \
	$$PWD/DataModel/AbstractTwoDimensionStatisticalChartNode.cpp \
	$$PWD/DataModel/StartNode.cpp \
	$$PWD/Exception/ImplicitTypeConversion.cpp \
	$$PWD/Exception/InterpreterException.cpp \
	$$PWD/Exception/NodeNameConflictException.cpp \
	$$PWD/Exception/TypeUnconvertible.cpp \
	$$PWD/Interpreter/InterpreterController.cpp \
	$$PWD/Transmitter/GraphShowTransmitter.cpp

HEADERS += \
	$$PWD/DataModel/AbstractArrayNode.h \
	$$PWD/DataModel/AbstractDataNode.h \
	$$PWD/DataModel/AbstractLineSeriesNode.h \
	$$PWD/DataModel/AbstractNode.h \
	$$PWD/DataModel/AbstractSeriesNode.h \
	$$PWD/DataModel/AbstractTwoDimensionStatisticalChartNode.h \
	$$PWD/DataModel/StartNode.h \
	$$PWD/Exception/ImplicitTypeConversion.h \
	$$PWD/Exception/InterpreterErrorException.h \
	$$PWD/Exception/InterpreterException.h \
	$$PWD/Exception/InterpreterWarnningException.h \
	$$PWD/Exception/NodeNameConflictException.h \
	$$PWD/Exception/TypeUnconvertible.h \
	$$PWD/GraphicsNodeInterface/GraphicsArrayNodeInterface.h \
	$$PWD/GraphicsNodeInterface/GraphicsDataNodeInterface.h \
	$$PWD/GraphicsNodeInterface/GraphicsNodeInterface.h \
	$$PWD/GraphicsNodeInterface/GraphicsTwoDimensionStatisticalChartInterface.h \
	$$PWD/GraphicsNodeInterface/GraphicsXYNodeInterface.h \
	$$PWD/GraphicsShowInterface/GraphicsShowInterface.h \
	$$PWD/Interpreter/InterpreterController.h \
	$$PWD/Transmitter/GraphShowTransmitter.h

INCLUDEPATH += DataModel
