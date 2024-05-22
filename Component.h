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
	// ��� �������. 0 - ������� �����, 1 - ��������, 
	//����� � ����������
	bool is_empty{ 0 }; 

	//���������� ���������� ����������� � ��������� ����� � ������
	friend ofstream&  operator<<(ofstream& stream, Component ob);
	friend ifstream& operator>>(ifstream& stream, Component& ob);

};