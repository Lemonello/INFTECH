#include"tasks.h"
#include<iostream>

const char dot_space[3] = ". ";

enum EDITS
{
	MAKER = 1,
	COUNT,
	CODE,
	PRICE
};

void tasks(Component* arr, int command, int size_arr)
{
	switch (command)
	{
	case EDIT:
	{
		edit_data(arr, size_arr);
		break;
	}
	case ADD:
	{
		
		break;
	}
	case DEL:
	{
		
		break;
	}
	case SORT:
	{
		
		break;
	}
	case FIND:
	{
		
		break;
	}
	case EXIT_COM:
	{
		break;
	}
	}
}

int get_line_number(int max_size)
{
	std::cout << "¬ведите строку:" << std::endl;
	int number = max_size;
	while (number >= max_size && number != -1)
	{
		std::cin >> number;
	}
	return number;
}

int get_edit()
{
	std::cout << MAKER << dot_space << "Maker" << std::endl <<
		COUNT << dot_space << "Count" << std::endl <<
		CODE << dot_space << "Code" << std::endl <<
		PRICE << dot_space << "Price" << std::endl;
	int edit;
	std::cin >> edit;
	return edit;
}

void edit_ob(Component& ob, int type)
{
	std::cout << "¬ведите новые данные" << std::endl;
	if (type == MAKER)
	{
		char new_maker[16];
		std::cin >> new_maker;
		for (int i = 0; i < 16; i++)
		{
			ob.maker[i] = new_maker[i];
		}
		return;
	}
	int value;
	std::cin >> value;
	if (type == COUNT) ob.count = value;
	if (type == CODE) ob.code = value;
	if (type == PRICE)ob.price = value;
}

void edit_data(Component* arr, int size_arr)
{
	int max = size_arr;
	int number_line = get_line_number(max);
	system("cls");
	int edit_c = get_edit();
	edit_ob(arr[number_line], edit_c);
}

