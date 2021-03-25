#pragma once
#include "EnterNeuron.h"
#include <vector>

class HiddenNeuron : public EnterNeuron
{
public:
	double value = 0;
	int weight_count;
	double *weights;
	explicit HiddenNeuron(const int& weightCount);
	void CalculateWeights(const std::vector<EnterNeuron>& prevLayerNeurons);
	void CalculateWeights(const std::vector<HiddenNeuron>& prevLayerNeurons);
	HiddenNeuron& operator = (const HiddenNeuron&);
	~HiddenNeuron();
	void rndWeights();

private:
};