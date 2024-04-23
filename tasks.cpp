#include"tasks.h"
#include"static.h"
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
		int number = get_line_number(size_arr);
		del_data(arr, number);
		shrink_to_left(arr, size_arr, number);
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
	std::cout << "Введите строку:" << std::endl;
	int number = max_size;
	//Защита от ввода неправильной строки
	//Выход из программы при вводе -1
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
	std::cout << "Введите новые данные" << std::endl;
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

void del_data(Component* arr, int index)
{	
	null_el(arr[index]);
}

void null_el(Component& ob)
{
	char null_arr[16]{ "00000000000" };
	for (int i = 0; i < 16; i++)
	{
		ob.maker[i] = null_arr[i];
	}
	ob.count = NULL;
	ob.code = NULL;
	ob.price = NULL;
}

void shrink_to_left(Component* arr, int size_arr, int index)
{
	//i+1 для предотвращения выхода за пределы массива
	for (int i = index; (i+1) < size_arr; i++)
	{
		arr[i] = arr[i + 1];
	}
	//Обнуляем последний элемент массива, чтобы не было дублирований
	int null_element = (size_arr - 1);
	null_el(arr[null_element]);
}