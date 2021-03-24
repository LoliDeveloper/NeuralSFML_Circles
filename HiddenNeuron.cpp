#include "EnterNeuron.h"
#include "MyFunctions.h"
#include "HiddenNeuron.h"
#include <random>

HiddenNeuron::HiddenNeuron(const int& weightCount):
	weight_count(weightCount)
{
	weights = new double[weight_count]();
	rndWeights();
}

HiddenNeuron::~HiddenNeuron()
{
}


void HiddenNeuron::CalculateWeights(const std::vector<EnterNeuron>& prevLayerNeurons)
{
	double tmpValue = 0.;
	for (int i = 0; i < weight_count; ++i)
	{
		tmpValue += (prevLayerNeurons[i].value * weights[i]);
	}
	value = sigmoid(tmpValue);
}

void HiddenNeuron::CalculateWeights(const std::vector<HiddenNeuron>& prevLayerNeurons)
{
	double tmpValue = 0.;
	for (int i = 0; i < weight_count; ++i)
	{
		tmpValue += (prevLayerNeurons[i].value * weights[i]);
	}
	value = sigmoid(tmpValue);
}

void HiddenNeuron::rndWeights()
{
	for(int i = 0; i < weight_count; ++i)
	{
		weights[i] = (double)rand() / RAND_MAX;
	}
}