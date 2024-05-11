#include"static.h"
#include"Component.h"

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

void save_data(bool parameter, Component* &arr_adr, int &length)
{
	static Component* adreess_array;
	static int len_stat;
	if (parameter == SAVE && arr_adr != nullptr)
	{
		adreess_array = arr_adr;
		len_stat = length;
	}
	if (parameter == GET)
	{
		arr_adr = adreess_array;
		length = len_stat;
	}
}
