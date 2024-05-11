#include"tasks.h"
#include"static.h"
#include"sort.h"
#include<iostream>

const char dot_space[3] = ". ";

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
		add_data(arr, size_arr);
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
		sort_data(arr, size_arr);
		break;
	}
	case FIND:
	{
		find_ob(arr, size_arr);
		break;
	}
	case AVERAGE:
	{	
		double av_price=0;
		average_price(arr, size_arr, av_price);
		show_average(av_price);
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
	int number = max_size+2;
	//Защита от ввода неправильной строки
	//Выход из программы при вводе -1
	while (number >= (max_size+1) && number != -1)
	{
		std::cin >> number;
	}
	return (number-1);
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
		std::cin.ignore(INT_MAX, '\n');
		std::cin.getline(new_maker,16);
		strcpy_s(ob.maker, 16, new_maker);
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

void add_data(Component* arr, int size_arr)
{
	auto index = std::find_if(arr, arr + size_arr, [](Component ob) {
		if (ob.code == NULL && ob.count == NULL && ob.price == NULL)
			return true;
		return false;
		});
	if (index != (arr + size_arr))
	{
		std::cin >> *index;
		return;
	}
	std::cout << "Нет места в массиве" << std::endl;
}

void null_el(Component& ob)
{
	char null_arr[16]{ "" };
	strcpy_s(ob.maker, 16, null_arr);
	ob.count = NULL;
	ob.code = NULL;
	ob.price = NULL;
}

//Функция сдвигает все элементы массива влево после удаления элемента

void shrink_to_left(Component* arr, int size_arr, int index)
{
	//i+1 для предотвращения выхода за пределы массива
	for (int i = index; (i+1) < size_arr; i++)
	{
		arr[i] = arr[i + 1];
	}		
	int null_index = --size_arr;
	null_el(arr[null_index]);
}

void show_maker_enter()
{
	std::cout << "Введите искомую строку" << std::endl;
}

void get_find(char* find, int size_arr)
{
	char get[20];
	std::cin.ignore(INT_MAX, '\n');
	std::cin.getline(get, 20);
	strcpy_s(find,20 ,get);
}

void find_ob(Component* arr, int size_arr)
{
	show_maker_enter();
	char find[20];
	get_find(find, 20);
	auto it = std::find_if(arr, arr + size_arr, [find](Component ob)
		{
			int result = strcmp(ob.maker, find);
			if (result == NULL) return true;
			return false;
		});
	if (it == (arr + size_arr))
	{	
		system("cls");
		std::cout << "Значение не найдено"<<std::endl;
		return;
	}
	std::cout << *it;
}

void average_price(Component* arr, int size_arr, double& average)
{	
	int count = 0;
	for (int i = 0; i < size_arr; i++)
	{
		if (arr[i].price != NULL && arr[i].code!=NULL)
		{
			count++;
			average += arr[i].price;
		}
	}
	average /= count;
}

void show_average(double average)
{
	std::cout << "Среднее арифметическое цен: " <<
		average <<  std::endl;
}