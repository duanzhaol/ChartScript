#ifndef MODELCODINGINTERFACE_H
#define MODELCODINGINTERFACE_H

#include <QString>

using CodeText = QString;

class ModelCodingInterface{
public:
    virtual CodeText getModelName()const = 0;
	virtual CodeText dataTexting()const = 0;
	virtual CodeText getModelTypeName()const = 0;
};

#endif // MODELCODINGINTERFACE_H
