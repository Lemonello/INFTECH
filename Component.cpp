#include"Component.h"

const char symb = '|';

istream& operator>>(istream& stream, Component& ob)
{
	return stream;
}

ostream& operator<<(ostream& stream, Component ob)
{	
	stream << symb;
	stream.setf(std::ios::left);
	stream.width(15);
	stream << ob.maker << symb;
	stream.width(15);
	stream << ob.count << symb;
	stream.width(15);
	stream << ob.code << symb;
	stream.width(15);
	stream << ob.price << symb << std::endl;
	stream.unsetf(std::ios::left);
	return stream;
}

ifstream& operator>>(ifstream& stream, Component& ob)
{	
	stream >> ob.maker;
	stream >> ob.count;
	stream >> ob.code;
	stream >> ob.price;
	return stream;
}

ofstream& operator<<(ofstream& stream, Component ob)
{
	return stream;
}