#include "MyFunctions.h"
#include "HiddenNeuron.h"
#include "EnterNeuron.h"
#include "OutputNeuron.h"

OutputNeuron::OutputNeuron(const int& weightCount):HiddenNeuron(weightCount)
{
}

OutputNeuron::~OutputNeuron()
{
}

void OutputNeuron::CalculateAllWeights(const std::vector<HiddenNeuron>& prevLayerNeurons)
{
	double tmpValue = 0.;
	for (int i = 0; i < weight_count; ++i)
	{
		tmpValue += (prevLayerNeurons[i].value * weights[i]);
	}
	value = sigmoid(tmpValue);
}
void OutputNeuron::CalculateAllWeights(const std::vector<EnterNeuron>& prevLayerNeurons)
{
	double tmpValue = 0.;
	for (int i = 0; i < weight_count; ++i)
	{
		tmpValue += (prevLayerNeurons[i].value * weights[i]);
	}
	value = sigmoid(tmpValue);
}