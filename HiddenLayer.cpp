#include "HiddenNeuron.h"
#include "HiddenLayer.h"
#include "MyFunctions.h"

HiddenLayer::HiddenLayer(int count)
{
	HiddenNeurons[count];
	for (int i = 0; i < count; ++i)
	{
		HiddenNeurons[i].rndWeights();
	}
}

HiddenLayer::~HiddenLayer()
{
}

void HiddenLayer::CalculateAllNeurons(EnterNeuron *values)
{
	for (int i = 0; i < count; ++i)
	{
		double tmpValue = 0;
		for (int j = 0; j < HiddenNeurons[i].weight_count; ++j)
		{
			tmpValue += HiddenNeurons[i].weights[j] * values[j].value;
		}
		HiddenNeurons[i].value = sigmoid(tmpValue);
	}
}

void HiddenLayer::CalculateAllNeurons(HiddenNeuron *values)
{
	for (int i = 0; i < count; ++i)
	{
		double tmpValue = 0;
		for (int j = 0; j < HiddenNeurons[i].weight_count; ++j)
		{
			tmpValue += HiddenNeurons[i].weights[j] * values[j].value;
		}
		HiddenNeurons[i].value = sigmoid(tmpValue);
	}
}