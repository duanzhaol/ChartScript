#include "DataTypeInterpreter.h"
#include <QDebug>

DataTypeInterpreter::DataTypeInterpreter()
{

}

QVariant::Type DataTypeInterpreter::interprete(CodeText &code)
{
	CodeText typeName;
	for(int index = 0;index < code.size(); ++index){
		if(code[index] == ' '){
			typeName = code.left(index);
			code.remove(0,index);
			break;
		}
	}

	return QVariant::nameToType(typeName.toLatin1());
}
