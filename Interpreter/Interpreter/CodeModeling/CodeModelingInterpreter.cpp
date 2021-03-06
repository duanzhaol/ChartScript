#include "CodeModelingInterpreter.h"
#include <QDebug>

CodeModelingInterpreter::CodeModelingInterpreter()
{

}

CodeModelingResult CodeModelingInterpreter::interprete(CodeText &code)
{
	code = code.trimmed();

	QPair<QHash<CodeText, AbstractNode *>, QList<AbstractNode *> > initResult =
			InitAreaInterpreter::interpreter(code);

	QList<AbstractGraphicsNode*> portWidgets;

	QPair<InterpreterController*,QHash<AbstractNode*,QList<AbstractNode*>>>
			connectionResult = ConnectionAreaInterpreter::interprete(code,initResult.first);

	return CodeModelingResult{
		initResult.second,
		connectionResult.first,
		connectionResult.second
	};
}
