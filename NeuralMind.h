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
	int EnterNeuronsCount;
	HiddenLayer *HiddenLayers;
	int widthHiddenLayers;
	OutputNeuron *OutputNeurons;
	int OutputNeuronsCount;
};