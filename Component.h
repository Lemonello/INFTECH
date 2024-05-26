#pragma once

#include<fstream>

const int MAX_SIZE = 16;

struct Component
{
	char maker[MAX_SIZE];
	int count{}, code{}, price;
};