#include"Component.h"
#include"file.h"
#include<iostream>
#include<fstream>


void show_name_file()
{
	std::cout << "Enter filename" << std::endl;
}

void get_filename(char* filename)
{	
	const int size = 16;
	char file[16];
	std::cin >> file;
	for (int i = 0; i < size; i++)
	{
		filename[i] = file[i];
	}
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

void read_data(Component* arr, char* filename)
{	
	std::ifstream fin;
	fin.open(filename);
	int index = 0;
	while (!fin.eof())
	{
		fin >> arr[index];
		++index;
	}
	fin.close();
}

void show_data(Component* arr, int size_arr)
{	
	for (int i = 0; i < 65; i++) std::cout << "-";
	std::cout << std::endl;
	for (int i = 0; i < size_arr; i++)
	{
		std::cout << arr[i];
	}
	for (int i = 0; i < 65; i++) std::cout << "-";
	std::cout << std::endl;
}


void save_filename(int is_save, char* file)
{	
	//static для сохранения данных при работе
	static char filename[16];
	//true, если нужно сохранить файл
	if (is_save == true)
	{
		for (int i = 0; i < 16; i++)
		{
			filename[i] = file[i];
		}
	}
	//false, если нужно получить имя файла
	if (is_save == false)
	{
		for (int i = 0; i < 16; i++)
		{
			file[i] = filename[i];
		}
	}
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