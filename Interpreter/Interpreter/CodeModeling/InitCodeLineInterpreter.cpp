#include "InitCodeLineInterpreter.h"
#include "DataInterpreter.h"
#include "ModelNameInterpreter.h"
#include "ModelTypeInterpreter.h"
#include"ClosureInterpreter.h"
#include "DataTypeInterpreter.h"

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

	}
	case ModelType::Array:{

	}
	case ModelType::Chart:{

	}
	case ModelType::Start:{

	}
	case ModelType::Invalid:{

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
