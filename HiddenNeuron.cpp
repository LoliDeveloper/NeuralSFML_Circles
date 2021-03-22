#include "EnterNeuron.h"
#include "MyFunctions.h"
#include "HiddenNeuron.h"

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