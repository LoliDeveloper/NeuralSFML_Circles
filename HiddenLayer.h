#pragma once
#include "HiddenNeuron.h"

class HiddenLayer
{
public:
	HiddenLayer(int count, int weight_count_);
	void CalculateAllNeurons(EnterNeuron *values);
	void CalculateAllNeurons(HiddenNeuron *values);
	~HiddenLayer();
	HiddenNeuron *HiddenNeurons;
	int count;
	HiddenLayer& operator = (const HiddenLayer& newValue);
private:
};