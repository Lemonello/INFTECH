#include"Component.h"
#include"menu.h"
#include"file.h"

Component comps[10]
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
	setlocale(LC_ALL, "Russian");
	int size_arr = 10;
	while (true) menu(comps, size_arr);
	return 0;
}