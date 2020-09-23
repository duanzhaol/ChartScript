#include "SpaceClosureInterpreter.h"



int SpaceClosureInterpreter::interprete(CodeText &code)
{

	for(int index = 0;index<code.size();++index){
		if(code.front() != ' '){
			return index;
		}
		else{
			code.right(code.size()-1);
		}
	}
	return 0;
}
