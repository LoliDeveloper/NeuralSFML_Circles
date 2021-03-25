#pragma once
#include "HiddenNeuron.h"
#include <vector>

class HiddenLayer
{
public:
	explicit HiddenLayer(int count, int weight_count_);
	void CalculateAllNeurons(const std::vector<EnterNeuron>& values);
	void CalculateAllNeurons(const std::vector<HiddenNeuron>& values);
	HiddenLayer& operator = (const HiddenLayer& newOutputNeuron);
	~HiddenLayer();
	std::vector<HiddenNeuron> HiddenNeurons;
	int count;
private:
};