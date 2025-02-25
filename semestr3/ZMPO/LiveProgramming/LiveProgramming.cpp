// LiveProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Value.h"
#include <iostream>

int main()
{
	Value val0, val1, val2, val3;

	int int_val = 21;
	int* pi_int_val = new int(21);
	bool b_bool_val = false;

	val0.SetValue(&int_val, false);
	val1.SetValue(pi_int_val, true);
	val2.SetValue(pi_int_val, false);
	val3.SetValue(&b_bool_val, false);

	std::cout << val0.Equals(&val1) << std::endl;
	std::cout << val0.Equals(&val3) << std::endl;
	std::cout << val1.Equals(&val2) << std::endl;

	Value val4(val1);
	Value val5(val0);

	std::cout << val4.Equals(&val1) << std::endl;
	std::cout << val5.Equals(&val0) << std::endl;
}