#pragma once
#include "HiddenNeuron.h"
#include "EnterNeuron.h"

class OutputNeuron : HiddenNeuron
{
public:
	static int indexMax;
	static double MaxValue;
	OutputNeuron(int weightCount);
	void CalculateWeights(HiddenNeuron *prevLayerNeurons);
	void CalculateWeights(EnterNeuron *prevLayerNeurons);
	~OutputNeuron();

private:

};