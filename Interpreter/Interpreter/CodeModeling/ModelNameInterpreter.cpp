#include "ModelNameInterpreter.h"
#include "../../Exception/InterpreterErrorException.h"
#include <QDebug>

ModelNameInterpreter::ModelNameInterpreter()
{

}

CodeText ModelNameInterpreter::interprete(CodeText &code)
{
	CodeText nodeName;
	if(code.front() != "\""){
		throw InterpreterErrorException("do not find model name after model type");
	}
	code.remove(0,1);

	for(int index = 0;index<code.size();++index){
		if(code[index] == "\""){
			nodeName = code.left(index);
			code.remove(0,index + 1);
			return nodeName;
		}
	}



	throw InterpreterErrorException("model name without close double quotation");

}
