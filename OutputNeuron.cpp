#pragma once
#include "MyFunctions.cpp"
#include "HiddenNeuron.cpp"
#include "EnterNeuron.cpp"

class OutputNeuron : HiddenNeuron
{
public:
	static int indexMax;
	static double MaxValue;
	OutputNeuron(); 
	void CalculateWeights(HiddenNeuron* prevLayerNeurons);
	~OutputNeuron();

private:

};

OutputNeuron::OutputNeuron()
{
}

OutputNeuron::~OutputNeuron()
{
}

void OutputNeuron::CalculateWeights(HiddenNeuron* prevLayerNeurons)
{
	double tmpValue = 0.;
	for (int i = 0; i < weight_count; ++i)
	{
		tmpValue += (prevLayerNeurons[i].value * weights[i]);
	}
	value = sigmoid(tmpValue);
}