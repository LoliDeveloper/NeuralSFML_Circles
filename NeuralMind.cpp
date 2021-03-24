#define _USE_MATH_DEFINES
#include <math.h> 
#include "NeuralMind.h"
#include "MyFunctions.h"
#include <vector>


NeuralMind::NeuralMind(int enterNeurons, int hiddenWidth, int hiddenCount, int outputNeuronsCount):
	EnterNeuronsCount(enterNeurons),
	widthHiddenLayers(hiddenWidth),
	OutputNeuronsCount(outputNeuronsCount)
{
	EnterNeurons.reserve(EnterNeuronsCount);
	HiddenLayers.reserve(widthHiddenLayers);
	OutputNeurons.reserve(OutputNeuronsCount);
	for (int i = 0; i < EnterNeuronsCount; ++i)
	{
		EnterNeurons.push_back(EnterNeuron());
	}
	if (hiddenWidth > 0)
	{
		HiddenLayers.push_back(HiddenLayer(hiddenCount, EnterNeuronsCount));
		for (int i = 1; i < hiddenWidth; ++i)
		{
			HiddenLayers.push_back(HiddenLayer(hiddenCount, hiddenCount));
		}
		for (int i = 0; i < outputNeuronsCount; ++i)
		{
			OutputNeurons.push_back(OutputNeuron(hiddenCount));
		}
	}
	else {
		for (int i = 0; i < outputNeuronsCount; ++i)
		{
			OutputNeurons.push_back(OutputNeuron(EnterNeuronsCount));
		}
	}

}

NeuralMind::~NeuralMind()
{
}

int NeuralMind::CalculateDecision(double *values)
{
	for(int i = 0; i < EnterNeuronsCount; ++i) //SET VALUES TO ENTER NEURONS
	{
		EnterNeurons[i].value = values[i];
	}
	if(widthHiddenLayers > 0) // CALCULATE HIDDEN LAYER
	{
		HiddenLayers[0].CalculateAllNeurons(EnterNeurons);
		for (int i = 1; i < widthHiddenLayers; ++i)
		{
			HiddenLayers[i].CalculateAllNeurons(HiddenLayers[i-1].HiddenNeurons); // CALCULATE HIDDEN NEURONS
		}
		for (int i = 1; i < OutputNeuronsCount; ++i)
		{
			OutputNeurons[i].CalculateAllWeights(HiddenLayers[widthHiddenLayers - 1].HiddenNeurons);// CALCULATE OUTPUT NEURONS
		}
	}
	else {
		for (int i = 1; i < OutputNeuronsCount; ++i)
		{
			OutputNeurons[i].CalculateAllWeights(EnterNeurons); // CALCULATE OUTPUT NEURONS
		}
	}
	return CurrentAnswer();
}

int NeuralMind::CurrentAnswer()
{
	int maxIndex = -1;
	double maxValue = -20;
	for (int i = 0; i < OutputNeuronsCount; ++i)
	{
		if (OutputNeurons[i].value > maxValue)
		{
			maxValue = OutputNeurons[i].value;
			maxIndex = i;
		}
	}
	return maxIndex;
}