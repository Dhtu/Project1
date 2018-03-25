#pragma once
#include "stdafx.h"

static size_t sg_ulIndex;	        //path������±�
static size_t sg_ulSize;
static Point_S *sg_astPath;
static int32_t **sg_pLaby;



int32_t Finding(size_t x, size_t y)
{
	size_t ulSign;

	sg_astPath[sg_ulIndex].x = x;		//����ǰλ�ò���ջ��
	sg_astPath[sg_ulIndex].y = y;
	sg_ulIndex++;
	ulSign = sg_ulIndex;			    //����index���������


	if (x == END && y == END)           //�ж��Ƿ񵽴��յ�
	{
		sg_astPath[sg_ulIndex].x = '#';  //��ֹ����
		return AVAILABLE;
	}

	                                    //ͨ�����ϳ��Ը�������ֱ������ͨ·��Available�����������·��Blocked�����ջ
	if (sg_pLaby[x + 1][y] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		sg_pLaby[x + 1][y] = PASSED;
		if (AVAILABLE == Finding(x + 1, y))
		{
			return AVAILABLE;
		}
	}

	if (sg_pLaby[x][y + 1] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		sg_pLaby[x][y + 1] = PASSED;
		if (AVAILABLE == Finding(x, y + 1))
		{
			return AVAILABLE;
		}
	}

	if (sg_pLaby[x - 1][y] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		sg_pLaby[x - 1][y] = PASSED;
		if (AVAILABLE == Finding(x - 1, y))
		{
			return AVAILABLE;
		}
	}

	if (sg_pLaby[x][y - 1] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		sg_pLaby[x][y - 1] = PASSED;
		if (AVAILABLE == Finding(x, y - 1))
		{
			return AVAILABLE;
		}
	}


	return BLOCKED;			            //���򣬷�����·

}



Point_S *Find_path(int32_t **pLaby, size_t ulSize)
{
	sg_ulIndex = 0;
	sg_ulSize = ulSize;
	sg_pLaby = pLaby;
	sg_astPath = (Point_S *)malloc(sizeof(Point_S) * ulSize * 5);

	
	Finding(START, START);


	return sg_astPath;
}

