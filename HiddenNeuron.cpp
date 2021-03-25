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
	//delete[] weights;
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


HiddenNeuron& HiddenNeuron::operator = (const HiddenNeuron& newHiddenNeuron)
{
	this->value = newHiddenNeuron.value;
	this->weight_count = newHiddenNeuron.weight_count;
	delete[] weights;
	this->weights = new double[this->weight_count]();
	for (int i = 0; i < weight_count; ++i)
	{
		this->weights[i] = newHiddenNeuron.weights[i];
	}

	return *this;
}