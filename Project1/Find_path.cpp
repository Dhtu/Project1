#pragma once
#include "stdafx.h"
#define MAX 5

static size_t sg_ulIndex, sg_ulMin;	        //path������±�
static size_t sg_ulSize;
static Point_S *sg_astPath;
static int32_t **sg_pLaby;
static Point_S *sg_astTest;


int32_t Finding(size_t x, size_t y)
{
	size_t ulSign;

	sg_astTest[sg_ulIndex].x = x;		//����ǰλ�ò���ջ��
	sg_astTest[sg_ulIndex].y = y;
	sg_ulIndex++;
	ulSign = sg_ulIndex;			    //����index���������


	if (x == END && y == END)           //�ж��Ƿ񵽴��յ�
	{
		if (sg_ulIndex<sg_ulMin)//�ж��Ƿ������·��
		{
			sg_ulMin = sg_ulIndex;
			for (size_t i = 0; i < sg_ulIndex; i++)
			{
				sg_astPath[i] = sg_astTest[i];
			}
			sg_astPath[sg_ulIndex].x = -1;
		}
	}

	//ͨ�����ϳ��Ը�������ֱ������ͨ·��Available�����������·��Blocked�����ջ
	if (sg_pLaby[x + 1][y] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		sg_pLaby[x + 1][y] = PASSED;
		Finding(x + 1, y);
		sg_pLaby[x + 1][y] = AVAILABLE;
	}

	if (sg_pLaby[x][y + 1] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		sg_pLaby[x][y + 1] = PASSED;
		Finding(x, y + 1);
		sg_pLaby[x][y + 1] = AVAILABLE;
	}

	if (sg_pLaby[x - 1][y] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		sg_pLaby[x - 1][y] = PASSED;
		Finding(x - 1, y);
		sg_pLaby[x - 1][y] = AVAILABLE;
	}

	if (sg_pLaby[x][y - 1] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		sg_pLaby[x][y - 1] = PASSED;
		Finding(x, y - 1);
		sg_pLaby[x][y - 1] = AVAILABLE;
	}


	return BLOCKED;			            //���򣬷�����·

}



Point_S *Find_path(int32_t **pLaby, size_t ulSize)
{
	sg_ulIndex = 0;
	sg_ulSize = ulSize;
	sg_pLaby = pLaby;
	sg_astPath = (Point_S *)malloc(sizeof(Point_S) * ulSize * ulSize);
	sg_astTest = (Point_S *)malloc(sizeof(Point_S) * ulSize * ulSize);
	sg_ulMin = ulSize * ulSize;
	Finding(START, START);


	return sg_astPath;
}

