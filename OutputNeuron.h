#pragma once
#include "HiddenNeuron.h"
#include "EnterNeuron.h"

class OutputNeuron : public HiddenNeuron
{
public:
	OutputNeuron(const int& weightCount);
	void CalculateAllWeights(const std::vector<EnterNeuron>& prevLayerNeurons);
	void CalculateAllWeights(const std::vector<HiddenNeuron>& prevLayerNeurons);
	~OutputNeuron();

private:

};