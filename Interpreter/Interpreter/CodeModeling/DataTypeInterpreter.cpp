#include "DataTypeInterpreter.h"

DataTypeInterpreter::DataTypeInterpreter()
{

}

QVariant::Type DataTypeInterpreter::interprete(CodeText &code)
{
	CodeText typeName;
	for(int index = 0;index < code.size(); ++index){
		if(code[index] == ' '){
			typeName = code.left(index - 1);
			code.remove(0,index);
		}
	}
	return QVariant::nameToType(typeName.toLatin1());
}
