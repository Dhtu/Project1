#pragma once
#include "stdafx.h"


static size_t sg_ulIndex= 0;	        //path数组的下标

int Find_path(size_t x, size_t y)
{
	size_t ulSign;

	g_astPath[sg_ulIndex].x = x;		//将当前位置插入栈顶
	g_astPath[sg_ulIndex].y = y;
	sg_ulIndex++;
	ulSign = sg_ulIndex;			    //储存index，方便回退


	if (x == END && y == END)           //判断是否到达终点
	{
		g_astPath[sg_ulIndex].x = '#';  //终止符号
		return AVAILABLE;
	}

	                                    /*通过不断尝试各个方向，直到遇到通路（Available）如果遇到死路（Blocked）则出栈*/
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


	return BLOCKED;			            //否则，返回死路

}