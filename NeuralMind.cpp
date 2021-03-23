#define _USE_MATH_DEFINES
#include <math.h> 
#include "NeuralMind.h"
#include "MyFunctions.h"


NeuralMind::NeuralMind(int enterNeurons, int hiddenWidth, int hiddenCount, int outputNeuronsCount):
	OutputNeuronsCount(outputNeuronsCount),
	EnterNeuronsCount(enterNeurons),
	widthHiddenLayers(hiddenWidth)
{
	EnterNeurons[enterNeurons];
	HiddenLayers[hiddenWidth];
	OutputNeurons[outputNeuronsCount];
	for (int i = 0; i < enterNeurons; ++i)
	{
		EnterNeurons[i] = EnterNeuron();
	}
	if (hiddenWidth > 0)
	{
		HiddenLayers[0] = HiddenLayer(hiddenCount, enterNeurons);
		for (int i = 1; i < hiddenWidth; ++i)
		{
			HiddenLayers[i] = HiddenLayer(hiddenCount, hiddenCount);
		}
		for (int i = 0; i < outputNeuronsCount; ++i)
		{
			OutputNeurons[i] = OutputNeuron(hiddenCount);
		}
	}
	else {
		for (int i = 0; i < outputNeuronsCount; ++i)
		{
			OutputNeurons[i] = OutputNeuron(enterNeurons);
		}
	}

}

NeuralMind::~NeuralMind()
{
}

int NeuralMind::CalculateDecision(double *values)
{
	double tmpArr[OutputNeuronsCount];
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
	return maxDoubleArray(OutputNeuronsCount, OutputNeurons->value);
}