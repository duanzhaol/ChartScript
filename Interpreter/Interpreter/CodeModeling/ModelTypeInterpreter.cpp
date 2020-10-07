#include "ModelTypeInterpreter.h"
#include "ClosureInterpreter.h"
#include <QDebug>

ModelTypeInterpreter::ModelTypeInterpreter()
{

}

ModelType ModelTypeInterpreter::interprete(CodeText &code)
{
	CodeText typeName;
	for(int index = 0;index<code.size();++index){
		if(code[index] == ' '){
			typeName = code.left(index);
			code.remove(0,index);
			break;
		}
	}
	return AbstractNode::nameToType(typeName);
}
