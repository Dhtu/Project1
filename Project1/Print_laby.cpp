#pragma once
#include "stdafx.h"
#include"labyrinth.h"


void Print_laby()
{
	size_t i, j;
	for (j = 0; j < size; j++)
	{
		for (i = 0; i < size; i++)
		{
			printf_s("%d ", laby[i][j]);

		}
		printf_s("\n");
	}
}