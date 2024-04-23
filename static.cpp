#include"static.h"

//������� ��� ���������� � �������� ����� �����

void save_data(bool is_save, char* file)
{
	//static ��� ���������� ������ ��� ������
	static char filename[16];
	//true, ���� ����� ��������� ����
	if (is_save == true)
	{
		for (int i = 0; i < 16; i++)
		{
			filename[i] = file[i];
		}
	}
	//false, ���� ����� �������� ��� �����
	if (is_save == false)
	{
		for (int i = 0; i < 16; i++)
		{
			file[i] = filename[i];
		}
	}
}

//������� ��� ���������� � �������� ������� ���������� ��-��

void save_data(bool is_save, int& index)
{	
	static int empty_index;
	//true, ���� ����� ��������� ������ 
	if (is_save == true) empty_index = index;
	//false, ���� ����� �������� ������
	if (is_save == false) index = empty_index;
}
