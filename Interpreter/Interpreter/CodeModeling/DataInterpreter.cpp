#include "DataInterpreter.h"

#include <Interpreter/Exception/InterpreterErrorException.h>
#include <QDebug>

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
			numberText = code.left(index);
			code.remove(0,index + 1);
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
			numberText = code.left(index);
			code.remove(0,index + 1);
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
			stringData = code.left(index);
			code.remove(0,index + 1);
			return stringData;
		}
	}

	throw InterpreterErrorException("invalid string type data");

}

QVariant DataInterpreter::interprete(CodeText &code, const QVariant::Type dataType)
{
	switch (dataType) {
	case QVariant::Type::Int :return QVariant(DataInterpreter::intInterprete(code));
	case QVariant::Type::Double: return QVariant(DataInterpreter::doubleInterprete(code));
	case QVariant::Type::String: return QVariant(DataInterpreter::stringInterprete(code));
	default: return QVariant(QVariant::Type::Invalid);
	}
}
