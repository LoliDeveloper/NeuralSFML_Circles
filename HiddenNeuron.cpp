#include "EnterNeuron.h"
#include "MyFunctions.h"
#include "HiddenNeuron.h"
#include <random>

HiddenNeuron::HiddenNeuron(const int weightCount) :
	weight_count(weightCount)
{
	weights = new double[weight_count]();
	rndWeights();
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

void HiddenNeuron::rndWeights()
{
	for(int i = 0; i < weight_count; ++i)
	{
		weights[i] = (double)rand() / RAND_MAX;
	}
}

HiddenNeuron& HiddenNeuron::operator = (const HiddenNeuron& newValue)
{
	this->value = newValue.value;
	delete[] this->weights;
	this->weights = new double[newValue.weight_count]();
	for (int i = 0; i < newValue.weight_count; ++i)
	{
		this->weights[i] = newValue.weights[i];
	}

	return *this;
}