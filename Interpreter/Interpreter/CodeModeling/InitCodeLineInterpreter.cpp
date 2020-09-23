#include "InitCodeLineInterpreter.h"
#include "DataInterpreter.h"
#include "ModelNameInterpreter.h"
#include "ModelTypeInterpreter.h"
#include"SpaceClosureInterpreter.h"

InitCodeLineInterpreter::InitCodeLineInterpreter()
{

}

AbstractNode *InitCodeLineInterpreter::interprete(CodeText &code)
{
	SpaceClosureInterpreter::interprete(code);
	ModelType modelType = ModelTypeInterpreter::interprete(code);
	SpaceClosureInterpreter::interprete(code);

	switch (modelType) {
	case ModelType::Data:{

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
