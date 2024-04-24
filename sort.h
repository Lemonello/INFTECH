#pragma once

#include"Component.h"
#include"tasks.h"


bool inc_comp_maker(Component ob1, Component ob2);
bool inc_comp_count(Component ob1, Component ob2);
bool inc_comp_code(Component ob1, Component ob2);
bool inc_comp_price(Component ob1, Component ob2);

bool dec_comp_maker(Component ob1, Component ob2);
bool dec_comp_count(Component ob1, Component ob2);
bool dec_comp_code(Component ob1, Component ob2);
bool dec_comp_price(Component ob1, Component ob2);

void sort_data(Component* arr, int size_arr);
void decrease_order(Component* arr, int size_arr, int crit);
void increase_order(Component* arr, int size_arr, int crit);

void show_crits();
void show_order();

int get_order();
int get_criteria();