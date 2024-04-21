#include"Component.h"
#include"menu.h"
#include"file.h"

Component comps[3]
{
	{"Lenovo", 120, 44, 10},
	{"Intel", 110, 44, 80},
	{"LG", 140, 66, 70}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int size_arr = 3;
	while (true) menu(comps, size_arr);
	return 0;
}