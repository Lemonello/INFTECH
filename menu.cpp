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
	cout << "����� " << endl;
	cout << 1 << "\t" << "������� ����" << endl;
	cout << 2 << "\t" << "�������� ������" << endl;
	cout << 3 << "\t" << "�������� ����" << endl;
	cout << 4 << "\t" << "�������� ����� ����" << endl;
	cout << 5 << "\t" << "�����" << endl;
}

void show_edit_menu()
{
	cout << "�����" << endl;
	cout << EDIT << "\t" << "�������������" << endl;
	cout << ADD << "\t" << "��������" << endl;
	cout << DEL << "\t" << "�������" << endl;
	cout << SORT << "\t" << "�����������" << endl;
	cout << FIND << "\t" << "�����" << endl;
	cout << EXIT_COM << "\t" << "�����" << endl;
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
			cout << "������� ������������ �������" << endl;
			system("pause");
			break;
		}
	}
}

int get_edit_command()
{
	show_edit_menu();
	while (true)
	{
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
		case EXIT_COM:
		{
			return EXIT_COM;
		}
		default:
		{
			cout << "������� ������������ �������" << endl;
			system("pause");
			break;
		}
		}
	}
}

void menu(Component* arr, int& size_arr)
{
	int command = get_command();
	switch (command)
	{
	case OPEN_FILE:
	{	
		clear_arr(arr, size_arr);
		show_name_file();
		char file_name[16];
		get_filename(file_name);
		open_file(file_name);
		read_data(arr, file_name, size_arr);
		save_data(SAVE, file_name);
		break;
	}
	case SHOW_DATA:
	{
		show_data(arr, size_arr);
		int command = get_edit_command();
		tasks(arr, command, size_arr);
		system("pause");
		break;
	}
	case WRITE_TO_FILE:
	{
		char file[16];
		save_data(GET, file);
		data_to_file(arr, file, size_arr);
		break;
	}
	case WRITE_NEW_FILE:
	{
		show_name_file();
		char filename[16];
		get_filename(filename);
		data_to_file(arr, filename, size_arr);
		save_data(SAVE, filename);
		break;
	}
	default:
	{
		cout << "���-�� ����� �� ���" << endl;
		exit(EXIT_FAILURE);
		break;
	}
	}
}