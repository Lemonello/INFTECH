#include"static.h"

#include<string.h>

//������� ��� ���������� � �������� ����� �����

void save_data(bool parameter, char* file)
{
	//static ��� ���������� ������ ��� ������
	static char filename[16];
	//true, ���� ����� ��������� ����
	if (parameter == SAVE)
		strcpy_s(filename, 16, file);
	//false, ���� ����� �������� ��� �����
	if (parameter == GET)
		strcpy_s(file, 16, filename);
}

//������� ��� ���������� � �������� ������� ���������� ��-��

void save_data(bool parameter, int& index)
{	
	//6 - ������� ������ �������, ����� ���������� ��������
	static int empty_index{5};
	//true, ���� ����� ��������� ������ 
	if (parameter == SAVE) empty_index = index;
	//false, ���� ����� �������� ������
	if (parameter == GET) index = empty_index;
}
