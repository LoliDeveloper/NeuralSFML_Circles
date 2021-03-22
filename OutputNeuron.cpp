#pragma once
#include "MyFunctions.cpp"
#include "EnterNeuron.cpp"

class OutputNeuron
{
public:
	double value;
	double *weights;
	int weight_count;
	OutputNeuron();
	void CalculateWeights(EnterNeuron*);
	~OutputNeuron();

private:

};

OutputNeuron::OutputNeuron()
{
}

OutputNeuron::~OutputNeuron()
{
}

void OutputNeuron::CalculateWeights(EnterNeuron* prevLayerNeurons)
{
	double tmpValue = 0.;
	for (int i = 0; i < weight_count; ++i)
	{
		tmpValue += (prevLayerNeurons[i].value * weights[i]);
	}
	value = sigmoid(tmpValue);
}