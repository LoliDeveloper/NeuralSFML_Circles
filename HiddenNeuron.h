#pragma once
#include "EnterNeuron.h"
#include <vector>

class HiddenNeuron : public EnterNeuron
{
public:
	double value = 0;
	const int weight_count;
	double *weights;
	HiddenNeuron(const int& weightCount);
	void CalculateWeights(const std::vector<EnterNeuron>& prevLayerNeurons);
	void CalculateWeights(const std::vector<HiddenNeuron>& prevLayerNeurons);
	~HiddenNeuron();
	void rndWeights();

private:
};