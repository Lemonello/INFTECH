#pragma once

void show_name_file();
void get_filename(char* filename);
void open_file(char* filename);
bool is_open(char* filename);
void read_data(Component* arr, char* filename);

void show_data(Component* arr, int size_arr);