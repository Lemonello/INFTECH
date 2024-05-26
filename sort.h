#pragma once

#include"Component.h"
#include"tasks.h"

void sort_data(Component* arr, int size_arr);
void decrease_order(Component* arr, int size_arr, int crit);
void increase_order(Component* arr, int size_arr, int crit);

void show_crits();
void show_order();

int get_order();
int get_criteria();