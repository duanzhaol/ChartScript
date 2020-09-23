#include "CodeModelingInterpreter.h"
#include <QDebug>

CodeModelingInterpreter::CodeModelingInterpreter()
{

}

CodeModelingResult CodeModelingInterpreter::interprete(CodeText &code)
{
	code = code.trimmed();

	CodeModelingResult result;

	QPair<QHash<CodeText, AbstractNode *>, QList<AbstractNode *> > initResult =
			InitAreaInterpreter::interpreter(code);

	return CodeModelingResult{
		initResult.second,
		ConnectionAreaInterpreter::interprete(code,initResult.first)
	};
}
