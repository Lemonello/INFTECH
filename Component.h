#pragma once

#include<fstream>

namespace streams
{
	using std::istream;
	using std::ostream;
	using std::ifstream;
	using std::ofstream;
}

const int MAX_SIZE = 16;

using namespace streams;

struct Component
{
	char maker[MAX_SIZE];
	int count{}, code{}, price;
	// Для массива. 0 - элемент занят, 1 - свободен, 
	//готов к заполнению
	bool is_empty{ 0 }; 

	//Перегрузка операторов консольного и файлового ввода и вывода
	friend ofstream&  operator<<(ofstream& stream, Component ob);
	friend ifstream& operator>>(ifstream& stream, Component& ob);

};