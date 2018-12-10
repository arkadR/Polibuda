#pragma once
#include "Problem.h"
#include <fstream>
#include <iostream>
#include <string>

#define CAPACITY_EXTENSION "_c.txt"
#define WEIGHTS_EXTENSION "_w.txt"
#define VALUES_EXTENSION "_p.txt"
#define IMPLEMENTATION_PROBLEM "B��d implementacji: d�ugo�ci genotyp�w nie s� takie same"


class KnapsackProblem : public Problem {

	class Item {
	public:
		Item(int weight, int value) : weight(weight), value(value) {}
		int GetValue() { return value; }
		int GetWeight() { return weight; }
	private:
		int weight;
		int value;
	};


public:
	double CalculateFitness(Creature* creature) override;
	size_t GetProblemSize() override;
	void Initiate(int capacity, int itemCount);
	void ReadFromFile(std::string path);
private:
	int capacity;
	std::vector<Item*> items;
};