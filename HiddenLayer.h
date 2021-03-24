#pragma once
#include "HiddenNeuron.h"
#include <vector>

class HiddenLayer
{
public:
	HiddenLayer(int count, int weight_count_);
	void CalculateAllNeurons(const std::vector<EnterNeuron>& values);
	void CalculateAllNeurons(const std::vector<HiddenNeuron>& values);
	~HiddenLayer();
	std::vector<HiddenNeuron> HiddenNeurons;
	const int count;
private:
};