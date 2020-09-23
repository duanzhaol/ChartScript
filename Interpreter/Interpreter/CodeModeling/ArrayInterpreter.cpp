#include "ArrayInterpreter.h"
#include "DataInterpreter.h"
#include "../../Exception/InterpreterErrorException.h"

ArrayInterpreter::ArrayInterpreter()
{

}

QVariant ArrayInterpreter::interprete(CodeText &code, const QVariant::Type elementType)
{

	if(code.front() != '['){
		throw InterpreterErrorException("invalid array type data without \"[\"");
	}

	QList<QVariant> nodeData;

	forever{
		nodeData.append(DataInterpreter::interprete(code,elementType));
		if(code.isEmpty()){
			throw InterpreterErrorException("invalid array type data!");
		}
		else if(code.front() == ','){
			code.remove(0,1);
			continue;
		}
		else if(code.front() == "]"){
			break;
		}
		else{
			throw InterpreterErrorException("invalid array type data!");
		}
	}

	return nodeData;
}
