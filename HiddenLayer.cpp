#include "HiddenNeuron.h"
#include "HiddenLayer.h"
#include "MyFunctions.h"

HiddenLayer::HiddenLayer(const int count_, int weightCount_):
	count(count_)
{
	HiddenNeurons.reserve(count);
	for (int i = 0; i < count; ++i)
	{
		HiddenNeurons.push_back(HiddenNeuron(weightCount_));
		HiddenNeurons[i].rndWeights();
	}
}

HiddenLayer::~HiddenLayer()
{
}

void HiddenLayer::CalculateAllNeurons(const std::vector<EnterNeuron>& values)
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

void HiddenLayer::CalculateAllNeurons(const std::vector<HiddenNeuron>& values)
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

HiddenLayer& HiddenLayer::operator = (const HiddenLayer& newHiddenLayer)
{
	this->HiddenNeurons.clear();

	this->count = newHiddenLayer.count;
	this->HiddenNeurons.reserve(count);
	this->HiddenNeurons = newHiddenLayer.HiddenNeurons;
	return *this;
}