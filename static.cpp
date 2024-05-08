#include"static.h"

#include<string.h>

//Функция для сохранения и хранения имени файла

void save_data(bool parameter, char* file)
{
	//static для сохранения данных при работе
	static char filename[16];
	//true, если нужно сохранить файл
	if (parameter == SAVE)
		strcpy_s(filename, 16, file);
	//false, если нужно получить имя файла
	if (parameter == GET)
		strcpy_s(file, 16, filename);
}

//Функция для сохранения и хранения индекса свободного эл-та

void save_data(bool parameter, int& index)
{	
	//6 - текущий размер массива, далее переменная меняется
	static int empty_index{5};
	//true, если нужно сохранить индекс 
	if (parameter == SAVE) empty_index = index;
	//false, если нужно получить индекс
	if (parameter == GET) index = empty_index;
}
