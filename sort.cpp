#include"sort.h"
#include<iostream>
#include<algorithm>
#include<tuple>

enum ORDER
{
	DECREASE,
	INCREASE
};

//��� �������-����������� ��� ���������� � ������� �����������

bool inc_comp_maker(Component ob1, Component ob2)
{
	int result = strcmp(ob1.maker, ob2.maker);
	if (result == NULL) return false;
	if (result < NULL) return  false;
	if (result > NULL) return true;
}

bool inc_comp_count(Component ob1, Component ob2)
{
	return ob1.count < ob2.count;
}

bool inc_comp_code(Component ob1, Component ob2)
{
	return ob1.code < ob2.code;
}

bool inc_comp_price(Component ob1, Component ob2)
{
	return ob1.price < ob2.price;
}

//��� �������-����������� ��� ��������� � ������� ��������

bool dec_comp_maker(Component ob1, Component ob2)
{
	int result = strcmp(ob1.maker, ob2.maker);
	if (result == NULL) return false;
	if (result < NULL) return  true;
	if (result > NULL) return false;
}

bool dec_comp_count(Component ob1, Component ob2)
{
	return ob1.count > ob2.count;
}

bool dec_comp_code(Component ob1, Component ob2)
{
	return ob1.code > ob2.code;
}

bool dec_comp_price(Component ob1, Component ob2)
{
	return ob1.price > ob2.price;
}

//������� ��� ����������� �������� � ������� ����������

void sort_data(Component* arr, int size_arr)
{
	int criteria = get_criteria();
	system("cls");
	int order = get_order();
	system("cls");

	switch (order)
	{
	case DECREASE:
	{
		decrease_order(arr, size_arr, criteria);
		break;
	}
	case INCREASE:
	{
		increase_order(arr, size_arr, criteria);
		break;
	}
	}
}

//������� ��� ���������� ������� �� ���������� �������� 
//� ������� ��������

void decrease_order(Component* arr, int size_arr, int crit)
{
	switch (crit)
	{
	case MAKER:
	{
		std::sort(arr,arr+size_arr, dec_comp_maker);
		return;
	}
	case COUNT:
	{
		std::sort(arr, arr + size_arr, dec_comp_count);
		return;
	}
	case CODE:
	{
		std::sort(arr, arr + size_arr, dec_comp_code);
		return;
	}
	case PRICE:
	{
		std::sort(arr, arr + size_arr, dec_comp_price);
		return;
	}
	}
}

//������� ��� ���������� ������� �� �������� � ������� �����������

void increase_order(Component* arr, int size_arr, int crit)
{
	switch (crit)
	{
	case MAKER:
	{
		std::sort(arr, arr + size_arr, inc_comp_maker);
		return;
	}
	case COUNT:
	{
		std::sort(arr, arr + size_arr, inc_comp_count);
		return;
	}
	case CODE:
	{
		std::sort(arr, arr + size_arr, inc_comp_code);
		return;
	}
	case PRICE:
	{
		std::sort(arr, arr + size_arr, inc_comp_price);
		return;
	}
	}
}

void show_crits()
{
	std::cout << "������� �������� ����������" << std::endl;
	std::cout << MAKER << ".�������������" << std::endl;
	std::cout << COUNT << ".����������" << std::endl;
	std::cout << CODE << ".���" << std::endl;
	std::cout << PRICE << ".����" << std::endl;
}

void show_order()
{
	std::cout << "�� ����������� ��� ��������" << std::endl;
	std::cout << DECREASE << ".�� ��������" << std::endl;
	std::cout << INCREASE << ".�� �����������" << std::endl;
}

int get_order()
{	

	show_order();
	while (true)
	{	
		int order;
		std::cin >> order;
		switch (order)
		{
		case INCREASE:
		{
			return INCREASE;
		}
		case DECREASE:
		{
			return DECREASE;
		}
		default:
		{
			std::cout << "������� ������������ �������" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			system("pause");
			break;
		}
		}
	}
}

int get_criteria()
{
	show_crits();
	int criteria;
	std::cin >> criteria;
	return criteria;
}