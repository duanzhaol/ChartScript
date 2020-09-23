#include "ModelTypeInterpreter.h"
#include "ClosureInterpreter.h"

ModelTypeInterpreter::ModelTypeInterpreter()
{

}

ModelType ModelTypeInterpreter::interprete(CodeText &code)
{
	CodeText typeName;
	for(int index = 0;index<code.size();++index){
		if(code[index] != ' '){
			typeName = code.left(index - 1);
			break;
		}
	}
	return AbstractNode::nameToType(typeName);
}
