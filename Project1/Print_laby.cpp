#pragma once
#include "stdafx.h"


void Print_laby()
{
	size_t i, j;
	for (j = 0; j < g_ulSize; j++)
	{
		for (i = 0; i < g_ulSize; i++)
		{
			printf_s("%d ", g_aLaby[i][j]);

		}
		printf_s("\n");
	}
}