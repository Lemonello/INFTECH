#include"Component.h"
#include"file.h"
#include"tasks.h"
#include"static.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include <string>

void show_name_file()
{
	std::cout << "Enter filename" << std::endl;
}

void get_filename(char* filename)
{	
	const int size = 16;
	char file[50];
	std::cin.ignore(INT_MAX, '\n');
	std::cin.getline(file, 16);
	char extension[5]{ ".txt" };
	strcat_s(file, extension);
	strcpy_s(filename, 16, file);
}

void open_file(char* filename)
{
	bool is_open_file = is_open(filename);
	if (!is_open_file)
	{
		std::cout << "��������� ������� ����" << std::endl;
		return;
	}
}

bool is_open(char* filename)
{
	std::ifstream fin;
	fin.open(filename);
	bool open = fin.is_open();
	return open;
}

void read_data(char* filename)
{	
	Component* arr = nullptr;
	int size_arr;
	save_data(GET, arr, size_arr);
	std::ifstream fin;
	fin.open(filename);
	for (int i = 0; !fin.eof() && i < size_arr; i++)
	{	
		fin>> arr[i].maker;
		fin>> arr[i].count;
		fin>> arr[i].code;
		fin>> arr[i].price;
	}
	fin.close();
}

void show_top()
{
	std::cout << std::endl;
	std::cout.setf(std::ios::left);
	std::cout << "�����" << "|";
	std::cout.width(15);
	std::cout << "��������������" << "|";
	std::cout.width(15);
	std::cout << "����������" << "|";
	std::cout.width(15);
	std::cout << "���" << "|";
	std::cout.width(15);
	std::cout << "����" << "|";
	std::cout.unsetf(std::ios::left);
	std::cout << std::endl;
}

void show_data()
{	
	int size;
	Component* arr_adr = nullptr;
	save_data(GET,arr_adr ,size);
	for (int i = 0; i < 70; i++) std::cout << "-";
	show_top();
	for (int i = 0; i < size; i++)
	{	
		if (arr_adr[i].count == NULL && arr_adr[i].price == NULL) break;
		std::cout.width(5);
		std::cout << (i+1);
		cout_Component(arr_adr[i]);
	}
	for (int i = 0; i < 70; i++) std::cout << "-";
	std::cout << std::endl;
}


void data_to_file(char* filename)
{	
	Component* arr = nullptr;
	int size_arr;
	save_data(GET, arr, size_arr);
	std::ofstream fout;
	fout.open(filename);
	for (int i = 0; i < size_arr; i++)
	{
		if (arr[i].count == NULL && arr[i].price == NULL) break;
		std::ostringstream out_str;
		generate_str(arr[i], out_str);
		fout << out_str.str();
	}
	fout.close();
}

void clear_arr()
{	
	Component* arr = nullptr;
	int size_arr;
	save_data(GET, arr, size_arr);
	for (int i = 0; i < size_arr; i++)
	{
		null_el(arr[i]);
	}
}

const char symb = '|';

void cout_Component(const Component& ob)
{
	std::cout<< symb;
	std::cout.setf(std::ios::left);
	std::cout.width(15);
	std::cout<< ob.maker << symb;
	std::cout.width(15);
	std::cout<< ob.count << symb;
	std::cout.width(15);
	std::cout<< ob.code << symb;
	std::cout.width(15);
	std::cout<< ob.price << symb << std::endl;
	std::cout.unsetf(std::ios::left);
}

void cin_Component(Component& ob)
{	
	std::cout << "������� ��������:" << std::endl;
	std::cin >> ob.maker;
	std::cout << "������� ����������:" << std::endl;
	std::cin >> ob.count;
	std::cout << "������� ���:" << std::endl;
	std::cin >> ob.code;
	std::cout << "������� ����:" << std::endl;
	std::cin >> ob.price;
}

void generate_str(const Component& ob, std::ostringstream& str)
{			
	str << ob.maker << " " << ob.count << " " <<
		ob.code << " " << ob.price << std::endl;
}