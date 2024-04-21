#pragma once

#include<fstream>

namespace streams
{
	using std::istream;
	using std::ostream;
	using std::ifstream;
	using std::ofstream;
}

const int MAKER_SIZE = 16;

using namespace streams;

struct Component
{
	char maker[MAKER_SIZE];
	int count{}, code{}, price;
	// Для массива. 0 - элемент занят, 1 - свободен, 
	//готов к заполнению
	bool is_empty{ 0 }; 

	//Перегрузка операторов консольного и файлового ввода и вывода
	friend ostream& operator<<(ostream& stream, Component ob);
	friend istream& operator>>(istream& stream, Component& ob);
	friend ofstream&  operator<<(ofstream& stream, Component ob);
	friend ifstream& operator>>(ifstream& stream, Component& ob);

};