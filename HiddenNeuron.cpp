#pragma once 
#include "EnterNeuron.cpp"
#include "MyFunctions.h"

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

HiddenNeuron::HiddenNeuron()
{
}

HiddenNeuron::~HiddenNeuron()
{
}


void HiddenNeuron::CalculateWeights(EnterNeuron* prevLayerNeurons)
{
	double tmpValue = 0.;
	for (int i = 0; i < weight_count; ++i)
	{
		tmpValue += (prevLayerNeurons[i].value * weights[i]);
	}
	value = sigmoid(tmpValue);
}

void HiddenNeuron::CalculateWeights(HiddenNeuron* prevLayerNeurons)
{
	double tmpValue = 0.;
	for (int i = 0; i < weight_count; ++i)
	{
		tmpValue += (prevLayerNeurons[i].value * weights[i]);
	}
	value = sigmoid(tmpValue);
}