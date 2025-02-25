#pragma once

#include "CMenuItem.h"
#include "CMenuCommand.h"
#include "Utils1.h"
#include <vector>
#include <string>
#include <queue>

#define BACK "back"
#define EXIT "exit"
#define HELP "help"
#define SEARCH "search"
#define REMOVED "Removed "
#define NO_SUCH_POSITION "No such position\n"
#define NO_COMMAND "No such command\n"
#define NO_HELP "Menus don't have descriptions\n"
#define SAME_OBJECT "Already here!\n"
#define NO_SUCH_PATH "Path doesnt't exist: "
#define ALREADY_EXISTS "Object with the same command already exists: "
#define EXPECTED "Error reading data: expected: "

#define ARROW "->"
#define SPACE_LEFT_BRACKET " ("
#define TERMINATOR ". "

#define LEFT_BRACKET '('
#define RIGHT_BRACKET ')'
#define LEFT_CRACKET_SQ '['
#define COMMA ','
#define SEMICOLON ';'
#define HASH '#'

class CMenu : public CMenuItem {
public:
	CMenu(std::string name, std::string command);
	~CMenu();
	void Add(CMenuItem* item);
	void Add(std::string path, CMenuItem* item);
	void Remove(std::string name);
	int Run() override;
	void ShowHelp() override;
	void Search(std::string command);
protected:
	CMenuItem* GetItemByName(std::string name);
	CMenuItem* GetItemByCommand(std::string command);
	std::vector<CMenuItem*> items;
};