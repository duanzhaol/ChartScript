SOURCES += \
	$$PWD/DataModel/AbstractArrayNode.cpp \
	$$PWD/DataModel/AbstractChartNode.cpp \
	$$PWD/DataModel/AbstractDataNode.cpp \
	$$PWD/DataModel/SeriesModel/AbstractAreaSeries.cpp \
	$$PWD/DataModel/SeriesModel/AbstractLineSeriesNode.cpp \
	$$PWD/DataModel/AbstractNode.cpp \
	$$PWD/DataModel/SeriesModel/AbstractPieSeries.cpp \
	$$PWD/DataModel/SeriesModel/AbstractScatterSeriesNode.cpp \
	$$PWD/DataModel/SeriesModel/AbstractSeriesNode.cpp \
	$$PWD/DataModel/StartNode.cpp \
	$$PWD/Exception/ImplicitTypeConversion.cpp \
	$$PWD/Exception/InterpreterErrorException.cpp \
	$$PWD/Exception/InterpreterException.cpp \
	$$PWD/Exception/NodeNameConflictException.cpp \
	$$PWD/Exception/TypeUnconvertible.cpp \
	$$PWD/Interpreter/CodeModeling/ArrayInterpreter.cpp \
	$$PWD/Interpreter/CodeModeling/ClosureInterpreter.cpp \
	$$PWD/Interpreter/CodeModeling/CodeModelingInterpreter.cpp \
	$$PWD/Interpreter/CodeModeling/ConnectionAreaInterpreter.cpp \
	$$PWD/Interpreter/CodeModeling/ConnectionLineInterpreter.cpp \
	$$PWD/Interpreter/CodeModeling/DataInterpreter.cpp \
	$$PWD/Interpreter/CodeModeling/DataTypeInterpreter.cpp \
	$$PWD/Interpreter/CodeModeling/InitAreaInterpreter.cpp \
	$$PWD/Interpreter/CodeModeling/InitCodeLineInterpreter.cpp \
	$$PWD/Interpreter/CodeModeling/ModelNameInterpreter.cpp \
	$$PWD/Interpreter/CodeModeling/ModelTypeInterpreter.cpp \
	$$PWD/Interpreter/InterpreterController.cpp \
	$$PWD/Interpreter/ModelCodingInterpreter.cpp \
	$$PWD/Transmitter/GraphShowTransmitter.cpp

HEADERS += \
	$$PWD/DataModel/AbstractArrayNode.h \
	$$PWD/DataModel/AbstractChartNode.h \
	$$PWD/DataModel/AbstractDataNode.h \
	$$PWD/DataModel/SeriesModel/AbstractAreaSeries.h \
	$$PWD/DataModel/SeriesModel/AbstractLineSeriesNode.h \
	$$PWD/DataModel/AbstractNode.h \
	$$PWD/DataModel/SeriesModel/AbstractPieSeries.h \
	$$PWD/DataModel/SeriesModel/AbstractScatterSeriesNode.h \
	$$PWD/DataModel/SeriesModel/AbstractSeriesNode.h \
	$$PWD/DataModel/StartNode.h \
	$$PWD/Exception/ImplicitTypeConversion.h \
	$$PWD/Exception/InterpreterErrorException.h \
	$$PWD/Exception/InterpreterException.h \
	$$PWD/Exception/InterpreterWarnningException.h \
	$$PWD/Exception/NodeNameConflictException.h \
	$$PWD/Exception/TypeUnconvertible.h \
	$$PWD/GraphicsNodeInterface/GraphicsAreaNodeInterface.h \
	$$PWD/GraphicsNodeInterface/GraphicsArrayNodeInterface.h \
	$$PWD/GraphicsNodeInterface/GraphicsChartNodeInterface.h \
	$$PWD/GraphicsNodeInterface/GraphicsDataNodeInterface.h \
	$$PWD/GraphicsNodeInterface/GraphicsNodeInterface.h \
	$$PWD/GraphicsNodeInterface/GraphicsPieNodeInterface.h \
	$$PWD/GraphicsNodeInterface/GraphicsXYNodeInterface.h \
	$$PWD/GraphicsShowInterface/GraphicsShowInterface.h \
	$$PWD/Interpreter/CodeModeling/ArrayInterpreter.h \
	$$PWD/Interpreter/CodeModeling/ClosureInterpreter.h \
	$$PWD/Interpreter/CodeModeling/CodeModelingInterpreter.h \
	$$PWD/Interpreter/CodeModeling/ConnectionAreaInterpreter.h \
	$$PWD/Interpreter/CodeModeling/ConnectionLineInterpreter.h \
	$$PWD/Interpreter/CodeModeling/DataInterpreter.h \
	$$PWD/Interpreter/CodeModeling/DataTypeInterpreter.h \
	$$PWD/Interpreter/CodeModeling/InitAreaInterpreter.h \
	$$PWD/Interpreter/CodeModeling/InitCodeLineInterpreter.h \
	$$PWD/Interpreter/CodeModeling/ModelNameInterpreter.h \
	$$PWD/Interpreter/CodeModeling/ModelTypeInterpreter.h \
	$$PWD/Interpreter/InterpreterController.h \
	$$PWD/Interpreter/ModelCodingInterface.h \
	$$PWD/Interpreter/ModelCodingInterpreter.h \
	$$PWD/Transmitter/GraphShowTransmitter.h

INCLUDEPATH += DataModel
