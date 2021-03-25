#pragma once
#include "EnterNeuron.h"
#include "HiddenLayer.h"
#include "OutputNeuron.h"
#include "Circle.h"
#include <vector>

class NeuralMind
{
public:
	explicit NeuralMind(int enterNeurons, int hiddenWidth, int hiddenCount, int outputNeuronsCount);
	int CalculateDecision(double *EnterValues);
	void RecalculateWeights(int rightAnswer);
	double getError(int rightAnswer);
	~NeuralMind();
	void RandomMutation();
	NeuralMind& operator = (const NeuralMind& newNeural);
	int EnterNeuronsCount;
	int widthHiddenLayers;
	int OutputNeuronsCount;
	int HiddenCount;

private:
	std::vector<EnterNeuron> EnterNeurons;
	std::vector<HiddenLayer> HiddenLayers;
	std::vector<OutputNeuron> OutputNeurons;
	int CurrentAnswer();
};