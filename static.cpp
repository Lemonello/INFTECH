#include"static.h"

//Функция для сохранения и хранения имени файла

void save_data(bool is_save, char* file)
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

//Функция для сохранения и хранения индекса свободного эл-та

void save_data(bool is_save, int& index)
{	
	static int empty_index;
	//true, если нужно сохранить индекс 
	if (is_save == true) empty_index = index;
	//false, если нужно получить индекс
	if (is_save == false) index = empty_index;
}
