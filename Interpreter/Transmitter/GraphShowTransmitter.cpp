#include "GraphShowTransmitter.h"

GraphShowTransmitter::GraphShowTransmitter()
{

}

GraphShowTransmitter &GraphShowTransmitter::getInstance()
{
	return this->instancce;
}

GraphShowTransmitter GraphShowTransmitter::instancce;
