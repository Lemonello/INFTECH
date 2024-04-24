#include"static.h"

//������� ��� ���������� � �������� ����� �����

void save_data(bool parameter, char* file)
{
	//static ��� ���������� ������ ��� ������
	static char filename[16];
	//true, ���� ����� ��������� ����
	if (parameter == SAVE)
	{
		for (int i = 0; i < 16; i++)
		{
			filename[i] = file[i];
		}
	}
	//false, ���� ����� �������� ��� �����
	if (parameter == GET)
	{
		for (int i = 0; i < 16; i++)
		{
			file[i] = filename[i];
		}
	}
}

//������� ��� ���������� � �������� ������� ���������� ��-��

void save_data(bool parameter, int& index)
{	
	//6 - ������� ������ �������, ����� ���������� ��������
	static int empty_index{6};
	//true, ���� ����� ��������� ������ 
	if (parameter == SAVE) empty_index = index;
	//false, ���� ����� �������� ������
	if (parameter == GET) index = empty_index;
}
