#include"static.h"

//Функция для сохранения и хранения имени файла

void save_data(bool parameter, char* file)
{
	//static для сохранения данных при работе
	static char filename[16];
	//true, если нужно сохранить файл
	if (parameter == SAVE)
	{
		for (int i = 0; i < 16; i++)
		{
			filename[i] = file[i];
		}
	}
	//false, если нужно получить имя файла
	if (parameter == GET)
	{
		for (int i = 0; i < 16; i++)
		{
			file[i] = filename[i];
		}
	}
}

//Функция для сохранения и хранения индекса свободного эл-та

void save_data(bool parameter, int& index)
{	
	//6 - текущий размер массива, далее переменная меняется
	static int empty_index{6};
	//true, если нужно сохранить индекс 
	if (parameter == SAVE) empty_index = index;
	//false, если нужно получить индекс
	if (parameter == GET) index = empty_index;
}
