#include "stdafx.h"
#include"labyrinth.h"


void Print_path() {
	size_t i;

	for (i = 0; i < index; i++)
	{
		printf_s("(%d,%d) -> ", path[i].x, path[i].y);
	}
}