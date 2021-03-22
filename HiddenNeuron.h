#pragma once
#include "EnterNeuron.h"

class HiddenNeuron : EnterNeuron
{
public:
	double value = 0;
	int weight_count;
	double *weights;
	HiddenNeuron();
	void CalculateWeights(EnterNeuron*);
	void CalculateWeights(HiddenNeuron*);
	~HiddenNeuron();

private:
};