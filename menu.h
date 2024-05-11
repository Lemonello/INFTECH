#pragma once

#include"Component.h"

enum Menu
{
	OPEN_FILE = 1,
	SHOW_DATA,
	WRITE_TO_FILE,
	WRITE_NEW_FILE,
	EXIT
};

enum Commands
{
	EXIT_MENU=-1,
	EDIT = 1,
	ADD,
	DEL,
	SORT,
	FIND,
	AVERAGE,
	EXIT_COM
};

void menu();
void show_menu();
int get_command();
int get_edit_command();
