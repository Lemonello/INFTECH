#pragma once
struct Component;

enum SAVES
{
	GET,
	SAVE
};

void save_data(bool is_save, char* file);
void save_data(bool parameter, Component* &arr_adr, int &length);
