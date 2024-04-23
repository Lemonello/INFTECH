#pragma once

enum SAVES
{
	GET,
	SAVE
};

void save_data(bool is_save, char* file);
void save_data(bool is_save, int &index);
