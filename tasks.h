#pragma once

#include"Component.h"
#include"menu.h"

void tasks(Component* arr, int command, int size_arr);

int get_line_number(int max_size);
int get_edit();
void edit_ob(Component& ob, int type);
void edit_data(Component* arr, int size_arr);
void del_data(Component* arr, int index);
void null_el(Component& ob);
void shrink_to_left(Component* arr, int size_arr, int index);
