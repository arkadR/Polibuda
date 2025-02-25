// ZMPO_2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include "CMenu.h"
#include "CMenuCommand.h"
#include "CCommand_Ala.h"
#include "CCommand_Internet.h"
#include "CCommands.h"

#define N_MAIN_MENU "Main Menu"
#define N_SUBMENU1 "Submenu1"
#define N_SUBMENU2 "Submenu2"
#define N_SUBMENU3 "Submenu3"
#define N_ALA "Write \"ala ma kota\""
#define N_DEFAULT "Default command"
#define N_BROWSER "Launch internet"
#define N_TAB_MENU "Table menu"
#define N_TAB_LIST "List CTables"
#define N_TAB_CREATE "Create new CTable"
#define N_TAB_CLONE "Clone CTable"
#define N_TAB_DELETE "Delete CTable"
#define N_TAB_DELALL "Delete All"
#define N_TAB_RENAME "Rename CTable"
#define N_TAB_RESIZE "Resize CTable"
#define N_TAB_DISPLAY "Display CTable"
#define N_TAB_SETVAL "Set value"
#define N_TAB_BEZP "Bezparametrowa"
#define N_TAB_PAR "Z parametrem"

#define C_MAIN_MENU "main"
#define C_SUBMENU1 "sub1"
#define C_SUBMENU2 "sub2"
#define C_SUBMENU3 "sub3"
#define C_ALA "ala"
#define C_DEFAULT "defcom"
#define C_BROWSER "internet"
#define C_TAB_MENU "tables"
#define C_TAB_LIST "list"
#define C_TAB_CREATE "create"
#define C_TAB_CLONE "clone"
#define C_TAB_DELETE "delete"
#define C_TAB_DELALL "deleteall"
#define C_TAB_RENAME "rename"
#define C_TAB_RESIZE "resize"
#define C_TAB_DISPLAY "display"
#define C_TAB_SETVAL "setval"
#define C_TAB_BEZP "bezp"
#define C_TAB_PAR "par"

#define H_ALA "Displays \"Ala ma kota\" on the screen"
#define H_DEFAULT "Displays the default command"
#define H_BROWSER "Opens the internet browser"
#define H_TAB_LIST "Lists all created CTables"
#define H_TAB_CLONE "Clones an existing CTable and store it"
#define H_TAB_DELETE "Deletes a chosen CTable"
#define H_TAB_DELALL "Deletes all created CTables"
#define H_TAB_RENAME "Renames a chosen CTable"
#define H_TAB_RESIZE "Resizes a chosen CTable"
#define H_TAB_DISPLAY "Displays all created CTables"
#define H_TAB_SETVAL "Sets the value of a cell in chosen CTable"
#define H_TAB_BEZP "Creates CTable with specified name and length"
#define H_TAB_PAR "Creates CTable with no parameters"

#define P_CREATE "tables->create"
#define P_SUB3 "sub1->sub3"

#define FILE_PATH "data2.txt"


void SaveToFile(std::string path, CMenuItem* item) {
	std::ofstream file;
	file.open(FILE_PATH);
	file << item->ToString();
	file.close();
}

CMenuItem* ReadFromFile(std::string path) {
	std::ifstream file;
	file.open(path);
	std::string serialized;
	size_t index = 0;
	errorCode errCode = NO_ERROR;
	CMenuItem* ret = NULL;
	if (std::getline(file, serialized)) {
		if (serialized[0] == LEFT_BRACKET)
			ret = new CMenu(serialized, index, &errCode);
		else if (serialized[0] == LEFT_CRACKET_SQ)
			ret = new CMenuCommand(serialized, index, &errCode);
		else {
			errCode = EXPECTED_BRACKET_RIGHT;
		}
		if (errCode != NO_ERROR) {
			Utils::DisplayError(errCode, (int)index);
			return NULL;
		}
	}
	else {
		errCode = EMPTY_FILE;
		Utils::DisplayError(errCode);
	}
	return ret;
}

int main()
{
	if (0) {
		CMenu mainMenu(N_MAIN_MENU, C_MAIN_MENU);
		mainMenu.Add(new CMenu(N_SUBMENU1, C_SUBMENU1));
		mainMenu.Add(new CMenu(N_SUBMENU2, C_SUBMENU2));
		mainMenu.Add(new CMenuCommand(N_ALA, C_ALA, H_ALA, new CCommand_Ala()));
		mainMenu.Add(C_SUBMENU1, new CMenu(N_SUBMENU3, C_SUBMENU3));
		mainMenu.Add(C_SUBMENU2, new CMenuCommand(N_DEFAULT, C_DEFAULT, H_DEFAULT, new CCommand()));
		mainMenu.Add(P_SUB3, new CMenuCommand(N_BROWSER, C_BROWSER, H_BROWSER, new CCommand_Internet()));
		mainMenu.Add(P_SUB3, new CMenuCommand(N_ALA, C_ALA, H_ALA, new CCommand_Ala()));

		std::vector<CTable*> tables;
		mainMenu.Add(new CMenu(N_TAB_MENU, C_TAB_MENU));
		mainMenu.Add(C_TAB_MENU, new CMenuCommand(N_TAB_LIST, C_TAB_LIST, H_TAB_LIST, new CCommand_List(&tables)));
		mainMenu.Add(C_TAB_MENU, new CMenu(N_TAB_CREATE, C_TAB_CREATE));
		mainMenu.Add(P_CREATE, new CMenuCommand(N_TAB_BEZP, C_TAB_BEZP, H_TAB_BEZP, new CCommand_Create_Bezp(&tables)));
		mainMenu.Add(P_CREATE, new CMenuCommand(N_TAB_PAR, C_TAB_PAR, H_TAB_PAR, new CCommand_Create_Par(&tables)));
		mainMenu.Add(C_TAB_MENU, new CMenuCommand(N_TAB_CLONE, C_TAB_CLONE, H_TAB_CLONE, new CCommand_Clone(&tables)));
		mainMenu.Add(C_TAB_MENU, new CMenuCommand(N_TAB_DELETE, C_TAB_DELETE, H_TAB_DELETE, new CCommand_Delete(&tables)));
		mainMenu.Add(C_TAB_MENU, new CMenuCommand(N_TAB_DELALL, C_TAB_DELALL, H_TAB_DELALL, new CCommand_DeleteAll(&tables)));
		mainMenu.Add(C_TAB_MENU, new CMenuCommand(N_TAB_RENAME, C_TAB_RENAME, H_TAB_RENAME, new CCommand_Rename(&tables)));
		mainMenu.Add(C_TAB_MENU, new CMenuCommand(N_TAB_RESIZE, C_TAB_RESIZE, H_TAB_RESIZE, new CCommand_Resize(&tables)));
		mainMenu.Add(C_TAB_MENU, new CMenuCommand(N_TAB_DISPLAY, C_TAB_DISPLAY, H_TAB_DISPLAY, new CCommand_Display(&tables)));
		mainMenu.Add(C_TAB_MENU, new CMenuCommand(N_TAB_SETVAL, C_TAB_SETVAL, H_TAB_SETVAL, new CCommand_SetVal(&tables)));

		mainMenu.Run();

		SaveToFile(FILE_PATH, &mainMenu);

		for (int i = 0; i < tables.size(); i++)
			delete tables[i];
	}
	else {
		CMenuItem * it = ReadFromFile(FILE_PATH);
		if (it != NULL) {
			it->Run();
			delete it;
		}
	}
	
}
