// ZMPO_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CMenu.h"
#include "CMenuCommand.h"
#include "CCommand_Ala.h"
#include "CCommand_Internet.h"

int main()
{
    std::cout << "Hello World!\n"; 
	CMenu mainMenu("Menu główne", "main");
	mainMenu.Add(new CMenu("Podmenu1", "create"));
	mainMenu.Add(new CMenu("Podmenu2", "delete"));
	mainMenu.Add(new CMenuCommand("Napisz \"ala ma kota", "ala", new CCommand_Ala()));
	((CMenu*)mainMenu.Get("Podmenu1"))->Add(new CMenuCommand("Uruchom przeglądarkę", "internet", new CCommand_Internet()));
	((CMenu*)mainMenu.Get("Podmenu1"))->Add(mainMenu.Get("Podmenu1"));
	((CMenu*)mainMenu.Get("Podmenu2"))->Add(new CMenuCommand("Default command", "defcom", new CCommand()));
	
	mainMenu.Run();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
