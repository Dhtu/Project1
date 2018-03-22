#include "stdafx.h"


void Print_path() {
	size_t i;

	for (i = 0; path[i].x!='#'; i++)
	{
		printf_s("(%d,%d) -> ", path[i].x, path[i].y);
	}
}