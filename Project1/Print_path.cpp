#include "stdafx.h"
#define SIZE_OF_RECTANCLE 7
#define RADIUS 5


void Print_path(Point_S *p_astPath)
{
	size_t i;//循环变量
	BeginBatchDraw();

	//画图
	for (i = 0; p_astPath[i].x!=-1; i++)
	{
		if (i<=255)
		{
			setfillcolor(RGB(255,255-i,34));//设置路径颜色
		}
		solidcircle(p_astPath[i].x * 2 * SIZE_OF_RECTANCLE + SIZE_OF_RECTANCLE,
					p_astPath[i].y * 2 * SIZE_OF_RECTANCLE + SIZE_OF_RECTANCLE,
					SIZE_OF_RECTANCLE);
	}
	EndBatchDraw();
}