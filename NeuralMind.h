#pragma once
#include "EnterNeuron.h"
#include "HiddenLayer.h"
#include "OutputNeuron.h"


class NeuralMind
{
public:
	NeuralMind(int enterNeurons, int hiddenWidth, int hiddenCount, int outputNeuronsCount);
	int CalculateDecision(double *EnterValues);
	~NeuralMind();

private:
	EnterNeuron *EnterNeurons;
	const int EnterNeuronsCount;
	HiddenLayer *HiddenLayers;
	const int widthHiddenLayers;
	OutputNeuron *OutputNeurons;
	const int OutputNeuronsCount;
};