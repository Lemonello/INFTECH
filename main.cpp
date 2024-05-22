#include"Component.h"
#include"menu.h"
#include"static.h"
#include"file.h"

Component comps[6]
{
	{"Lenovo", 120, 001, 10},
	{"Intel", 110, 002, 80},
	{"LG", 140, 003, 70},
	{"Samsung",135,004,90 },
	{"Oracle", 200, 005, 100},
	{"BIM",250, 006, 175}
};

int main()
{		
	system("chcp 1251");
	int size = 6;
	Component* arr = comps;
	save_data(SAVE, arr, size);
	while (true) menu();
	return 0;
}