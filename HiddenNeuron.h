#pragma once
#include "EnterNeuron.h"

class HiddenNeuron : public EnterNeuron
{
public:
	double value = 0;
	const int weight_count;
	double *weights;
	HiddenNeuron(const int weightCount);
	void CalculateWeights(EnterNeuron*);
	void CalculateWeights(HiddenNeuron*);
	HiddenNeuron& operator = (const HiddenNeuron& newValue);
	~HiddenNeuron();
	void rndWeights();

private:
};