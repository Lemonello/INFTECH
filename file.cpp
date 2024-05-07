#include"Component.h"
#include"file.h"
#include"tasks.h"
#include"static.h"
#include<iostream>
#include<fstream>

#include <string>

void show_name_file()
{
	std::cout << "Enter filename" << std::endl;
}

void get_filename(char* filename)
{	
	const int size = 16;
	char file[16];
	std::cin.ignore(INT_MAX, '\n');
	std::cin.getline(file, 16);
	strcpy_s(filename, 16, file);
}

void open_file(char* filename)
{
	bool is_open_file = is_open(filename);
	if (!is_open_file)
	{
		std::cout << "Неудалось открыть файл" << std::endl;
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

void read_data(Component* arr, char* filename, int size_arr)
{	
	std::ifstream fin;
	fin.open(filename);
	int index{-1};
	for (int i = 0; !fin.eof() && i < size_arr; i++)
	{	
		fin >> arr[i];
		index = i;
	}
	save_data(SAVE, index);
	fin.close();
}

void show_data(Component* arr, int size_arr)
{	
	for (int i = 0; i < 70; i++) std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < size_arr; i++)
	{	
		std::cout.width(5);
		std::cout << i;
		std::cout << arr[i];
	}
	for (int i = 0; i < 70; i++) std::cout << "-";
	std::cout << std::endl;
}


void data_to_file(Component* arr, char* filename, int size_arr)
{
	std::ofstream fout;
	fout.open(filename);
	for (int i = 0; i < size_arr; i++)
	{
		fout << arr[i];
	}
	fout.close();
}

void clear_arr(Component* arr, int size_arr)
{
	for (int i = 0; i < size_arr; i++)
	{
		null_el(arr[i]);
	}
}