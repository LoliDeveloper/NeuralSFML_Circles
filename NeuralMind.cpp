#define _USE_MATH_DEFINES
#include <math.h> 
#include "NeuralMind.h"
#include "MyFunctions.h"
#include <vector>
#include <iostream>


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
	if (widthHiddenLayers > 0)
	{
		HiddenLayers.push_back(HiddenLayer(hiddenCount, EnterNeuronsCount));
		for (int i = 1; i < widthHiddenLayers; ++i)
		{
			HiddenLayers.push_back(HiddenLayer(hiddenCount, hiddenCount));
		}
		for (int i = 0; i < OutputNeuronsCount; ++i)
		{
			OutputNeurons.push_back(OutputNeuron(hiddenCount));
		}
	}
	else {
		for (int i = 0; i < OutputNeuronsCount; ++i)
		{
			OutputNeurons.push_back(OutputNeuron(EnterNeuronsCount));
		}
	}

}

NeuralMind::NeuralMind() : NeuralMind(4, 4, 4, 4) {};

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

void NeuralMind::RandomMutation()
{
	if (widthHiddenLayers > 0)
	{
		if (get_rand_double() * 4 < 3)
		{
			int randlayer = (get_rand_double() - 0.01) * widthHiddenLayers;
			int randNeuron = HiddenLayers[randlayer].count * (get_rand_double() - 0.01);
			HiddenLayers[randlayer].HiddenNeurons[randNeuron].value = get_rand_double();
		}
		else {
			int randNeuron = OutputNeuronsCount * (get_rand_double() - 0.01);
			OutputNeurons[randNeuron].value = get_rand_double();
		}
	}
	else {
		int randNeuron = OutputNeuronsCount * (get_rand_double() - 0.01);
		OutputNeurons[randNeuron].value = get_rand_double();
	}
}

NeuralMind& NeuralMind::operator = (const NeuralMind& newNeural)
{

	/*EnterNeurons.clear();
	if (widthHiddenLayers > 0)
	{
		for (int i = 0; i < widthHiddenLayers; ++i)
		{
			HiddenLayers[i].HiddenNeurons.clear();
		}
		HiddenLayers.clear();
	}
	OutputNeurons.clear();*/
	

	this->EnterNeuronsCount = newNeural.EnterNeuronsCount;
	this->widthHiddenLayers = newNeural.widthHiddenLayers;
	this->OutputNeuronsCount = newNeural.OutputNeuronsCount;

	this->EnterNeurons.reserve(EnterNeuronsCount);
	this->HiddenLayers.reserve(widthHiddenLayers);
	this->OutputNeurons.reserve(OutputNeuronsCount);

	this->EnterNeurons.clear();
	this->HiddenLayers.clear();
	this->OutputNeurons.clear();

	for (int i = 0; i < EnterNeuronsCount; ++i)
	{
		this->EnterNeurons.push_back(newNeural.EnterNeurons[i]);
	}
	
	if (widthHiddenLayers > 0)
	{
		for (int i = 0; i < widthHiddenLayers; ++i)
		{
			this->HiddenLayers.push_back(newNeural.HiddenLayers[i]);
		}
	}
	for (int i = 0; i < OutputNeuronsCount; ++i)
	{
		this->OutputNeurons.push_back(newNeural.OutputNeurons[i]);
	}

	return *this;
}

void NeuralMind::RecalculateWeights(int rightAnswer)
{

}

double NeuralMind::getError(int rightAnswer)
{
	double summ = 0;
	for (int i = 0; i < OutputNeuronsCount; ++i)
	{
		if (i != rightAnswer)
		{
			summ += pow((OutputNeurons[i].value - 0),2);
		}
		else {
			summ += pow((OutputNeurons[i].value - 1), 2);
		}
	}
	return summ;
}