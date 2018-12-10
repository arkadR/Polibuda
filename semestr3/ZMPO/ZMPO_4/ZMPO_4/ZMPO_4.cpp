// ZMPO_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "KnapsackProblem.h"
#include "GeneticAlgorithmAgent.h"

#define FILE_NAME "p08"
#define CONSOLE_OUTPUT "Generation %d best: %d\n"	

int main()
{
	KnapsackProblem knapProblem;
	knapProblem.ReadFromFile(FILE_NAME);
	GeneticAlgorithmAgent agent(10, 0.25, 0.1, &knapProblem);
	long lastBest = -1;
	for (int i = 0; i < 10000; i++) { 
		agent.RunGeneration();
		long best = (long)agent.GetBestFitness();
		if (lastBest != best) {
			std::printf(CONSOLE_OUTPUT, i, best);
			lastBest = best;
		}
	}
}
