#include "MyFunctions.h"
#include "HiddenNeuron.h"
#include "EnterNeuron.h"
#include "OutputNeuron.h"

OutputNeuron::OutputNeuron(int weightCount)
{
	weights = new double[weightCount]();
	rndWeights();
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