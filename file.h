#pragma once
#include"Component.h"

void show_name_file();
void get_filename(char* filename);
void open_file(char* filename);
bool is_open(char* filename);
void read_data(char* filename);
void show_data();
void show_top();

void cout_Component(const Component& ob);
void cin_Component(Component& ob);

void clear_arr();
void data_to_file(char* filename);