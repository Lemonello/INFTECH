#pragma once

#include"Component.h"
#include"menu.h"

enum EDITS
{
	MAKER = 1,
	COUNT,
	CODE,
	PRICE
};

void tasks(Component* arr, int command, int size_arr);

int get_line_number(int max_size);
int get_edit();
void edit_ob(Component& ob, int type);
void edit_data(Component* arr, int size_arr);
void del_data(Component* arr, int index);
void add_data(Component* arr, int size_arr);

void null_el(Component& ob);
void shrink_to_left(Component* arr, int size_arr, int index);

void show_maker_enter();
void get_find(char* find, int size_arr);
void find_ob(Component* arr, int size_arr);

void average_price(Component* arr, int size_arr, double& average);
void show_average(double average);

