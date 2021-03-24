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
	void RandomMutation();
	NeuralMind& operator = (const NeuralMind& newNeural);

private:
	std::vector<EnterNeuron> EnterNeurons;
	int EnterNeuronsCount;
	std::vector<HiddenLayer> HiddenLayers;
	int widthHiddenLayers;
	std::vector<OutputNeuron> OutputNeurons;
	int OutputNeuronsCount;
	int CurrentAnswer();
};