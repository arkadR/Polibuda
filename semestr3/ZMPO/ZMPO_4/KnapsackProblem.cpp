#include "KnapsackProblem.h"

template <class T>
KnapsackProblem<T>::~KnapsackProblem()
{
	for (size_t i = 0; i < items.size(); i++)
		delete items[i];
}

template<>
double KnapsackProblem<bool>::CalculateFitness(std::vector<bool> genotype)
{
	int currValue = 0;
	int currWeight = 0;
	for (size_t i = 0; i < items.size(); i++) {
		if (genotype[i]) {
			currValue += items[i]->GetValue();
			currWeight += items[i]->GetWeight();
			if (currWeight > capacity) {
				return 0;
			}
		}
	}
	return currValue;
}

template<>
double KnapsackProblem<int>::CalculateFitness(std::vector<int> genotype)
{
	int currValue = 0;
	int currWeight = 0;
	for (size_t i = 0; i < items.size(); i++) {
		currValue += genotype[i] * items[i]->GetValue();
		currWeight += genotype[i] * items[i]->GetWeight();
		if (currWeight > capacity) {
			return 0;
		}
	}
	return currValue;
}

template<>
double KnapsackProblem<double>::CalculateFitness(std::vector<double> genotype)
{
	double currValue = 0;
	double currWeight = 0;
	for (size_t i = 0; i < items.size(); i++) {
		currValue += genotype[i] * items[i]->GetValue();
		currWeight += genotype[i] * items[i]->GetWeight();
		if (currWeight > capacity) {
			return 0;
		}
	}
	return currValue;
}

template <class T>
size_t KnapsackProblem<T>::GetProblemSize()
{
	return items.size();
}

template <class T>
void KnapsackProblem<T>::Initiate(int capacity, int itemCount, errorCode* errCode) 
{
	if (itemCount <= 0) {
		*errCode = NOT_ENOUGH_ITEMS;
		return;
	}
	this->capacity = capacity;
	for (int i = 0; i < itemCount; i++)
		items.push_back(new Item(Utils::RandInt(1, 100), Utils::RandInt(0, 100)));
}

template <class T>
void KnapsackProblem<T>::ReadFromFile(std::string path, errorCode* errCode) {
	std::ifstream fcapacity(path + CAPACITY_EXTENSION);
	std::ifstream weights(path + WEIGHTS_EXTENSION);
	std::ifstream values(path + VALUES_EXTENSION);
	if (!fcapacity.is_open() || !weights.is_open() || !values.is_open()) {
		*errCode = FILE_NOT_FOUND;
		return;
	}
	fcapacity >> capacity;
	fcapacity.close();

	int weight;
	int value;
	while (weights >> weight) {
		values >> value;
		items.push_back(new Item(weight, value));
	}
	weights.close();
	values.close();
	if (items.size() == 0) {
		*errCode = NOT_ENOUGH_ITEMS;
	}
}

template class KnapsackProblem<bool>;
template class KnapsackProblem<int>;
template class KnapsackProblem<double>;