#include "InitCodeLineInterpreter.h"
#include "DataInterpreter.h"
#include "ModelNameInterpreter.h"
#include "ModelTypeInterpreter.h"
#include"ClosureInterpreter.h"
#include "DataTypeInterpreter.h"
#include "ArrayInterpreter.h"
#include "../../NodeShow/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsDataNode.h"
#include "../../NodeShow/GraphicsNode/GraphicsNode/GraphicsTopNode/GraphicsStartNode.h"
#include "../../NodeShow/GraphicsNode/GraphicsNode/GraphicsInnerNode/GraphicsDataArrayNode.h"
#include <QDebug>

InitCodeLineInterpreter::InitCodeLineInterpreter()
{

}

AbstractNode *InitCodeLineInterpreter::interprete(CodeText &code)
{
	ClosureInterpreter::interprete(code);
	ModelType modelType = ModelTypeInterpreter::interprete(code);
	ClosureInterpreter::interprete(code);
	QString modelName = ModelNameInterpreter::interprete(code);
	ClosureInterpreter::interprete(code);
	switch (modelType) {
	case ModelType::Data:{
		QVariant modelData(DataTypeInterpreter::interprete(code));
		ClosureInterpreter::interprete(code);
		modelData.setValue(DataInterpreter::interprete(code,modelData.type()));
		ClosureInterpreter::interprete(code);
		GraphicsDataNode*node = new GraphicsDataNode;
		node->setNodeData(modelData);
		node->setNodeName(modelName);
		return static_cast<AbstractNode*>(node);
	}
	case ModelType::Array:{
		QVariant::Type elementType = DataTypeInterpreter::interprete(code);
		ClosureInterpreter::interprete(code);
		QVariant modelData((QList<QVariant>()));
		GraphicsDataArrayNode*node = new GraphicsDataArrayNode;
		node->setElementType(elementType);
		node->setNodeData(ArrayInterpreter::interprete(code,elementType));
		ClosureInterpreter::interprete(code);
		node->setNodeName(modelName);
		return static_cast<AbstractNode*>(node);
	}
	case ModelType::Chart:{
		return nullptr;
	}
	case ModelType::Start:{
		GraphicsStartNode*node = new GraphicsStartNode(new MovableProxyWidget);
		node->setNodeName(modelName);
		return static_cast<AbstractNode*>(node);
	}
	case ModelType::Invalid:{
		throw InterpreterErrorException("read invalid type!");
	}
	case ModelType::PieSeries:{

	}
	case ModelType::AreaSeries:{

	}
	case ModelType::LineSeries:{
	case ModelType::ScatterSeries:{


		}
	}
	}
	return nullptr;

}
