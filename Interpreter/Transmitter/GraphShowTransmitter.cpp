#include "GraphShowTransmitter.h"

GraphShowTransmitter::GraphShowTransmitter()
{

}

GraphShowTransmitter &GraphShowTransmitter::getInstance()
{
	return instancce;
}

GraphShowTransmitter GraphShowTransmitter::instancce;
