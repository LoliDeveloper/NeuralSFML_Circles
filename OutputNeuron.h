#pragma once
#include "HiddenNeuron.h"
#include "EnterNeuron.h"

class OutputNeuron : public HiddenNeuron
{
public:
	OutputNeuron(const int& weightCount);
	void CalculateAllWeights(HiddenNeuron *prevLayerNeurons);
	void CalculateAllWeights(EnterNeuron *prevLayerNeurons);
	~OutputNeuron();

private:

};