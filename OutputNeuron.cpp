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

OutputNeuron& OutputNeuron::operator = (const OutputNeuron& newOutputNeuron)
{
	this->value = newOutputNeuron.value;
	this->weight_count = newOutputNeuron.weight_count;
	delete[] this->weights;

	this->weights = new double[this->weight_count]();
	for (int i = 0; i < weight_count; ++i)
	{
		this->weights[i] = newOutputNeuron.weights[i];
	}

	return *this;
}