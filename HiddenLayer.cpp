#include "HiddenNeuron.h"
#include "HiddenLayer.h"
#include "MyFunctions.h"

HiddenLayer::HiddenLayer(const int count_, int weightCount_):
	count(count_)
{
	HiddenNeurons[count];
	for (int i = 0; i < count; ++i)
	{
		HiddenNeurons[i] = HiddenNeuron(weightCount_);
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

HiddenLayer& HiddenLayer::operator = (const HiddenLayer& newValue)
{
	this->count = newValue.count;
	delete[] this->HiddenNeurons;
	this->HiddenNeurons[newValue.count];
	for (int i = 0; i < newValue.count; ++i)
	{
		HiddenNeurons[i] = HiddenNeuron(weightCount_);
		HiddenNeurons[i].rndWeights();
	}
}