#include "stdafx.h"


void Print_path() {
	size_t i;

	for (i = 0; g_astPath[i].x!='#'; i++)
	{
		printf_s("(%d,%d) -> ", g_astPath[i].x, g_astPath[i].y);
	}
}