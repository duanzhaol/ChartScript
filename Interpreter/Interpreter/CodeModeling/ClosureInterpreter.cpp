#include "ClosureInterpreter.h"



int ClosureInterpreter::interprete(CodeText &code, const QChar &closureChar)
{

	for(int index = 0;index<code.size();++index){
		if(code.front() != closureChar){
			return index;
		}
		else{
			code.right(code.size()-1);
		}
	}
	return 0;
}
