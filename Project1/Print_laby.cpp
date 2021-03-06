#pragma once
#include "stdafx.h"
#define SIZE_OF_RECTANGLR 14

void Print_laby(int32_t **pLaby, size_t ulSize)
{
	size_t i, j;

	BeginBatchDraw();
	for (j = 0; j < ulSize; j++)
	{
		for (i = 0; i < ulSize; i++)
		{
			if (AVAILABLE == pLaby[i][j]) {
				setfillcolor(RGB(204, 238, 255));
			}
			else if(BLOCKED == pLaby[i][j])
			{
				setfillcolor(RGB(34,119,204));
			}


			solidrectangle(SIZE_OF_RECTANGLR * (i), 
				           SIZE_OF_RECTANGLR * (j), 
				           SIZE_OF_RECTANGLR * (i+1), 
				           SIZE_OF_RECTANGLR * (j+1));

		}
	}
	EndBatchDraw();
}