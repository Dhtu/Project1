#include "stdafx.h"


void Print_path(Point_S *p_astPath)
{
	size_t i;

	for (i = 0; p_astPath[i].x!=-1; i++)
	{
		printf_s("(%d,%d) -> ", p_astPath[i].x, p_astPath[i].y);
	}
}