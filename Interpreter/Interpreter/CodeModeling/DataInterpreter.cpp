#include "DataInterpreter.h"

#include <Interpreter/Exception/InterpreterErrorException.h>

DataInterpreter::DataInterpreter()
{

}


int DataInterpreter::intInterprete(CodeText &code)
{

	CodeText numberText;

	bool isNegative = code.front() == "-";

	if(isNegative){
		code.remove(0,1);
	}

	for(int index = 0;index < code.size();++index){
		if(!code[index].isDigit()){
			numberText = code.left(index - 1);
			code.remove(0,index);
			break;
		}
	}

	bool*ok = new bool;

	int number = numberText.toInt(ok);

	if(!ok){
		delete ok;
		throw InterpreterErrorException("invalid int type data");
	}

	delete ok;

	return number *= (!isNegative);
}

double DataInterpreter::doubleInterprete(CodeText &code)
{
	CodeText numberText;

	bool isNegative = code.front() == "-";

	if(isNegative){
		code.remove(0,1);
	}

	for(int index = 0;index < code.size();++index){
		if(!code[index].isDigit()){
			numberText = code.left(index - 1);
			code.remove(0,index);
			break;
		}
	}

	bool*ok = new bool;

	double number = numberText.toDouble(ok);

	if(!ok){
		delete ok;
		throw InterpreterErrorException("invalid double type data");
	}

	delete ok;

	return number *= (!isNegative);
}

QString DataInterpreter::stringInterprete(CodeText &code)
{
	if(code.front() != "\""){
		throw InterpreterErrorException("invalid string type data");
	}

	code.remove(0,1);

	QString stringData;

	for(int index = 0;index<code.size();++index){
		if(code[index] == "\""){
			stringData = code.left(index - 1);
			code.remove(0,index);
			return stringData;
		}
	}

	throw InterpreterErrorException("invalid string type data");

}
