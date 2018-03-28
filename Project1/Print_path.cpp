#include "stdafx.h"
#define SIZE_OF_RECTANCLE 15
#define RADIUS 13
void Print_path(Point_S *p_astPath)
{
	size_t i;
	setfillcolor(GREEN);

	BeginBatchDraw();
	for (i = 0; p_astPath[i].x!=-1; i++)
	{
		solidcircle(p_astPath[i].x * 2 * SIZE_OF_RECTANCLE + SIZE_OF_RECTANCLE,
					p_astPath[i].y * 2 * SIZE_OF_RECTANCLE + SIZE_OF_RECTANCLE,
					SIZE_OF_RECTANCLE);
	}
	EndBatchDraw();
}