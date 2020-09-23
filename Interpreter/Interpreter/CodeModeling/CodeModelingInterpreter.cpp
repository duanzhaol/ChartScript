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

	QList<PortWidget*> portWidgets;

	QPair<InterpreterController*,QHash<AbstractNode*,QList<AbstractNode*>>>
			connectionResult = ConnectionAreaInterpreter::interprete(code,initResult.first);

	return CodeModelingResult{
		initResult.second,
		connectionResult.first,
		connectionResult.second
	};
}
