#pragma once
#include "HiddenNeuron.h"

class HiddenLayer
{
public:
	HiddenLayer(int count);
	void CalculateAllNeurons(EnterNeuron *values);
	void CalculateAllNeurons(HiddenNeuron *values);
	~HiddenLayer();
	HiddenNeuron *HiddenNeurons;

private:
	int count;
};