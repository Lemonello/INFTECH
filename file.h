#pragma once

void show_name_file();
void get_filename(char* filename);
void open_file(char* filename);
bool is_open(char* filename);
void read_data(Component* arr, char* filename, int size_arr);
void show_data(Component* arr);
void show_top();

void clear_arr(Component* arr, int size_arr);
void data_to_file(Component* arr, char* filename, int size_arr);