#pragma once
#include "stdafx.h"


void Print_laby(int32_t **pLaby, size_t ulSize)
{
	size_t i, j;
	for (j = 0; j < ulSize; j++)
	{
		for (i = 0; i < ulSize; i++)
		{
			printf_s("%d ", pLaby[i][j]);

		}
		printf_s("\n");
	}
}