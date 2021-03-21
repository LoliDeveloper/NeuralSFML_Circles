#pragma once
#include "Neurons.cpp"
#define _USE_MATH_DEFINES
#include <math.h> 
#include <chrono>
#include <ctime>
#define ENTER_NEURONS 6

extern int widthWindow;
extern int heightWindow;
extern float maxSpeed;

class NeuralhiddenLayer
{
public:
	Neuron* neurons;
	int neuronCount;
	NeuralhiddenLayer()
	{}
	NeuralhiddenLayer(const int& neurons_, const int& enterNeurons_)
	{
		neuronCount = neurons_;
		neurons = new Neuron[neurons_]();
		for (int i = 0; i < neuronCount; ++i)
		{
			neurons[i].lenghtOfWeigt = enterNeurons_;
			neurons[i].weight = new double[enterNeurons_]();
			neurons[i].rndWeight();
		}
	}
	NeuralhiddenLayer(const int& neurons_) : NeuralhiddenLayer(neurons_, neurons_){}

	~NeuralhiddenLayer()
	{
		for (int i = 0; i < neuronCount; ++i)
		{
			delete[] neurons[i].weight;
		}
		delete[] neurons; 
	}
};

class NeuralMind
{
	void randomHiddenWeight()
	{
		//::cout << "Hidden MUTATION" << std::endl;
		int randHiddenLayer = (int)((double)widthHidden * (double)rand() / (RAND_MAX + 5));
		int randHiddenNeuron = (int)((double)hiddenLayers[randHiddenLayer].neuronCount * (double)rand() / (RAND_MAX + 5));
		int randHiddenWeight = (int)(hiddenLayers[randHiddenLayer].neurons[randHiddenNeuron].lenghtOfWeigt * (double)rand() / (RAND_MAX + 5));

		hiddenLayers[randHiddenLayer].neurons[randHiddenNeuron].weight[randHiddenWeight] = (double)rand() / RAND_MAX;
	}
	void randomOutputWeight()
	{
		//std::cout << "Output MUTATION" << std::endl;
		int randOutPutNeuron = (int)((double)countOutput * (double)rand() / (RAND_MAX + 5));
		int randOutPuWeight = (int)((double)outputNeurons[randOutPutNeuron].lenghtOfWeigt * (double)rand() / (RAND_MAX + 5));
		outputNeurons[randOutPutNeuron].weight[randOutPuWeight] = (double)rand() / RAND_MAX;
	}
	double sigmoid(const double& value) const
	{
		return 1.f / (1.f + (double)pow(M_E, -1 * value));
	}
	int Calculate()
	{
		for (int c = 0; c < hiddenLayers[0].neuronCount; ++c) //NEURON
		{
			double tmpValue = 0;
			for (int j = 0; j < hiddenLayers[0].neurons[c].lenghtOfWeigt; ++j) {    //WEIGHTS
				tmpValue += hiddenLayers[0].neurons[c].weight[j] * enterNeurons[j].value;
			}
			hiddenLayers[0].neurons[c].value = sigmoid(tmpValue);
		}
		for (int k = 1; k < widthHidden; ++k) // LAYER
		{
			for (int c = 0; c < hiddenLayers[k].neuronCount; ++c) //NEURON
			{
				double tmpValue = 0;
				for (int j = 0; j < hiddenLayers[k].neurons[c].lenghtOfWeigt; ++j)    //WEIGHTS
					tmpValue += hiddenLayers[k].neurons[c].weight[j] * hiddenLayers[k - 1].neurons[j].value;
				hiddenLayers[k].neurons[c].value = sigmoid(tmpValue);
			}
		}
		int IndexMaxOutPut = -1;
		double ValueMaxOutPut = -1.f;
		for (int i = 0; i < countOutput; ++i)
		{
			double tmpValue = 0;
			for (int j = 0; j < hiddenLayers[widthHidden - 1].neuronCount; ++j)
			{    //WEIGHTS
				tmpValue += outputNeurons[i].weight[j] * hiddenLayers[widthHidden - 1].neurons[j].value;
			}
			outputNeurons[i].value = sigmoid(tmpValue);
			if (ValueMaxOutPut < outputNeurons[i].value)
			{
				ValueMaxOutPut = outputNeurons[i].value;
				IndexMaxOutPut = i;
			}
		}
		return IndexMaxOutPut;


	}
public:
	int widthHidden;
	int countOutput;
	NeuralMind(const int& widthHiddenNeurons, const int& neurons_, const int& outputNeurons_);
	~NeuralMind();
	NeuralMind& operator = (const NeuralMind& newMind);
	EnterNeuron* enterNeurons;
	NeuralhiddenLayer* hiddenLayers;
	OutputNeuron* outputNeurons;

	void RandomMutation()
	{
		int randomLayer = (int)(((double)rand() / (RAND_MAX + 5)) * ((double)widthHidden + 1));
		if (randomLayer == widthHidden)randomOutputWeight();
		else {
			randomHiddenWeight();
		}
	}

	
	int CalculateDecision(const double& xPos, const double& yPos, const double& widthWindow, const double& heightWindow, const double& speed, const double& angle)
	{
		enterNeurons[0].value = (double)xPos / (double)widthWindow;
		enterNeurons[1].value = (double)yPos / (double)heightWindow;
		enterNeurons[2].value = (double)(widthWindow - xPos) / (double)widthWindow;
		enterNeurons[3].value = (double)(heightWindow - yPos) / (double)heightWindow;
		enterNeurons[4].value = (double)speed / (double)maxSpeed;
		enterNeurons[5].value = (double)fmod(angle, 2 * M_PI) / (2 * M_PI);
		return Calculate();
	}
	

	NeuralMind& operator = (const NeuralMind& newMind)
	{
		delete[] enterNeurons;
		delete[] hiddenLayers;
		delete[] outputNeurons;
	}
};

NeuralMind::NeuralMind(const int& widthHiddenNeurons, const int& neurons_, const int& outputNeurons_)
{
	countOutput = outputNeurons_;
	widthHidden = widthHiddenNeurons;
	enterNeurons = new EnterNeuron[ENTER_NEURONS]();
	hiddenLayers = new NeuralhiddenLayer[widthHiddenNeurons]();

	if (widthHiddenNeurons > 0) { hiddenLayers[0] = NeuralhiddenLayer(neurons_, ENTER_NEURONS); }

	for (int i = 1; i < widthHiddenNeurons; ++i)
	{
		hiddenLayers[i] = NeuralhiddenLayer(neurons_);
	}

	outputNeurons = new OutputNeuron[outputNeurons_]();
	for (int i = 0; i < outputNeurons_; ++i)
	{
		outputNeurons[i] = OutputNeuron(hiddenLayers[widthHidden - 1].neuronCount);

	}
}

NeuralMind::~NeuralMind()
{
	delete[] enterNeurons;
	delete[] hiddenLayers;
	delete[] outputNeurons;
}