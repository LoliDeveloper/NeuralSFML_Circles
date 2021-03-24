#pragma once
#include "EnterNeuron.h"
#include "HiddenLayer.h"
#include "OutputNeuron.h"
#include <vector>

class NeuralMind
{
public:
	NeuralMind(int enterNeurons, int hiddenWidth, int hiddenCount, int outputNeuronsCount);
	int CalculateDecision(double *EnterValues);
	~NeuralMind();

private:
	std::vector<EnterNeuron> EnterNeurons;
	const int EnterNeuronsCount;
	std::vector<HiddenLayer> HiddenLayers;
	const int widthHiddenLayers;
	std::vector<OutputNeuron> OutputNeurons;
	const int OutputNeuronsCount;
	int CurrentAnswer();
};