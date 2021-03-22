#define _USE_MATH_DEFINES
#include <math.h> 
#include "NeuralMind.h"


NeuralMind::NeuralMind(int enterNeurons, int hiddenWidth, int hiddenCount, int outputNeuronsCount)
{

}

NeuralMind::~NeuralMind()
{
}

int NeuralMind::CalculateDecision(double *values)
{
	for(int i = 0; i < EnterNeuronsCount; ++i)
	{
		EnterNeurons[i].value = values[i];
	}
	if(widthHiddenLayers > 0)
	{
		HiddenLayers[0].CalculateAllNeurons(EnterNeurons);
		for (int i = 1; i < widthHiddenLayers; ++i)
		{
			HiddenLayers[i].CalculateAllNeurons(HiddenLayers[i-1].HiddenNeurons);
		}
	}
}