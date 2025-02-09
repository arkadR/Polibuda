// ZMPO_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Error.h"
#include "CMenu.h"
#include "CMenuCommand.h"
#include "Commands.h"

#define N_MAIN_MENU "Main Menu"
#define C_MAIN_MENU "Main Menu"
#define N_KNAPSACK "Knapsack Problem"
#define C_KNAPSACK "knap"
#define N_KNAP_BOOL "Boolean Knapsack Problem"
#define C_KNAP_BOOL "bool"
#define H_KNAP_BOOL "empty"
#define N_KNAP_INT "Integer Knapsack Problem"
#define C_KNAP_INT "int"
#define H_KNAP_INT "empty"
#define N_KNAP_DOUBLE "Double Knapsack Problem"
#define C_KNAP_DOUBLE "double"
#define H_KNAP_DOUBLE "empty"
#define N_ONEMAX "One Max Problem"
#define C_ONEMAX "max"
#define H_ONEMAX "empty"
#define N_LEADINGONES "Leading Ones Problem"
#define C_LEADINGONES "ones"
#define H_LEADINGONES "empty"

int main()
{
	CMenu mainMenu(N_MAIN_MENU, C_MAIN_MENU);
	mainMenu.Add(new CMenu(N_KNAPSACK, C_KNAPSACK));
	mainMenu.Add(new CMenuCommand(N_ONEMAX, C_ONEMAX, H_ONEMAX, new CommandRunOneMax()));
	mainMenu.Add(new CMenuCommand(N_LEADINGONES, C_LEADINGONES, H_LEADINGONES, new CommandRunLeadingOnes()));
	mainMenu.Add(C_KNAPSACK, new CMenuCommand(N_KNAP_BOOL, C_KNAP_BOOL, H_KNAP_BOOL, new CommandRunKnapBool()));
	mainMenu.Add(C_KNAPSACK, new CMenuCommand(N_KNAP_INT, C_KNAP_INT, H_KNAP_INT, new CommandRunKnapInt()));
	mainMenu.Add(C_KNAPSACK, new CMenuCommand(N_KNAP_DOUBLE, C_KNAP_DOUBLE, H_KNAP_DOUBLE, new CommandRunKnapDouble()));

	mainMenu.Run();	
}
