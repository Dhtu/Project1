#pragma once
#include "stdafx.h"


static size_t sg_ulIndex= 0;	        //path������±�

int Find_path(size_t x, size_t y)
{
	size_t ulSign;

	g_astPath[sg_ulIndex].x = x;		//����ǰλ�ò���ջ��
	g_astPath[sg_ulIndex].y = y;
	sg_ulIndex++;
	ulSign = sg_ulIndex;			    //����index���������


	if (x == END && y == END)           //�ж��Ƿ񵽴��յ�
	{
		g_astPath[sg_ulIndex].x = '#';  //��ֹ����
		return AVAILABLE;
	}

	                                    /*ͨ�����ϳ��Ը�������ֱ������ͨ·��Available�����������·��Blocked�����ջ*/
	if (g_aLaby[x + 1][y] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		g_aLaby[x + 1][y] = PASSED;
		if (AVAILABLE == Find_path(x + 1, y))
		{
			return AVAILABLE;
		}
	}

	if (g_aLaby[x][y + 1] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		g_aLaby[x][y + 1] = PASSED;
		if (AVAILABLE == Find_path(x, y + 1))
		{
			return AVAILABLE;
		}
	}

	if (g_aLaby[x - 1][y] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		g_aLaby[x - 1][y] = PASSED;
		if (AVAILABLE == Find_path(x - 1, y))
		{
			return AVAILABLE;
		}
	}

	if (g_aLaby[x][y - 1] == AVAILABLE)
	{
		sg_ulIndex = ulSign;
		g_aLaby[x][y - 1] = PASSED;
		if (AVAILABLE == Find_path(x, y - 1))
		{
			return AVAILABLE;
		}
	}


	return BLOCKED;			            //���򣬷�����·

}