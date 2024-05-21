#include"menu.h"
#include"Component.h"
#include"file.h"
#include"tasks.h"
#include"static.h"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;


void show_menu()
{
	cout << "Выбор " << endl;
	cout << OPEN_FILE << "\t" << "Открыть файл" << endl;
	cout << SHOW_DATA << "\t" << "Просмотр данных" << endl;
	cout <<WRITE_TO_FILE << "\t" << "Записать файл" << endl;
	cout << WRITE_NEW_FILE << "\t" << "Записать новый файл" << endl;
	cout << EXIT << "\t" << "Выход" << endl;
}

void show_edit_menu()
{
	cout << "Выбор" << endl;
	cout << EDIT << "\t" << "Редактировать" << endl;
	cout << ADD << "\t" << "Добавить" << endl;
	cout << DEL << "\t" << "Удалить" << endl;
	cout << SORT << "\t" << "Сортировать" << endl;
	cout << FIND << "\t" << "Найти" << endl;
	cout << AVERAGE << "\t" << "Подсчет среднего для цены" << endl;
	cout << EXIT_COM << "\t" << "Выйти" << endl;
}

int get_command()
{
	while (true)
	{
		system("cls");
		show_menu();
		int command;
		cin >> command;
		switch (command)
		{
		case OPEN_FILE:
		{
			return OPEN_FILE;
		}
		case SHOW_DATA:
		{
			return SHOW_DATA;
		}
		case WRITE_TO_FILE:
		{
			return WRITE_TO_FILE;
		}
		case WRITE_NEW_FILE:
		{
			return WRITE_NEW_FILE;
		}
		case EXIT:
		{
			exit(EXIT_SUCCESS);
		}
		default:
			cout << "Введена неправильная команда" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("pause");
			break;
		}
	}
}

int get_edit_command()
{
	while (true)
	{	
		system("cls");
		show_data();
		show_edit_menu();
		int command;
		cin >> command;
		switch (command)
		{
		case EDIT:
		{
			return EDIT;
		}
		case ADD:
		{
			return ADD;
		}
		case DEL:
		{
			return DEL;
		}
		case SORT:
		{
			return SORT;
		}
		case FIND:
		{
			return FIND;
		}
		case AVERAGE:
		{
			return AVERAGE;
		}
		case EXIT_COM:
		{
			return EXIT_COM;
		}
		default:
		{
			cout << "Введена неправильная команда" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("pause");
			break;
		}
		}
	}
}

void menu()
{
	Component* adr_Arr=nullptr;
	int size_arr;
	save_data(GET, adr_Arr, size_arr);
	int command = get_command();
	switch (command)
	{
	case OPEN_FILE:
	{	
		clear_arr();
		show_name_file();
		char file_name[16];
		get_filename(file_name);
		open_file(file_name);
		read_data(file_name);
		save_data(SAVE, file_name);
		break;
	}
	case SHOW_DATA:
	{	
		system("cls");
		int command = get_edit_command();
		tasks(adr_Arr, command, size_arr);
		system("pause");
		break;
	}
	case WRITE_TO_FILE:
	{
		char file[16];
		save_data(GET, file);
		data_to_file(file);
		break;
	}
	case WRITE_NEW_FILE:
	{
		show_name_file();
		char filename[16];
		get_filename(filename);
		data_to_file(filename);
		save_data(SAVE, filename);
		break;
	}
	default:
	{
		cout << "Что-то пошло не так" << endl;
		exit(EXIT_FAILURE);
		break;
	}
	}
}