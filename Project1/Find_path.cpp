#pragma once
#include "stdafx.h"
#include "labyrinth.h"


int Find_path(size_t x, size_t y)
{
	size_t sign;

	path[index].x = x;		//将当前位置插入栈顶
	path[index].y = y;
	index++;
	sign = index;			//储存index，方便回退

	
	if (x == End && y == End)//判断是否到达终点
	{
		path[index].x = '#';//终止符号
		return Available;
	}

	/*通过不断尝试各个方向，直到遇到通路（Available）如果遇到死路（Blocked）则出栈*/
	if (laby[x + 1][y] == Available)
	{
		index = sign;
		laby[x + 1][y] = Passed;
		if (Available == Find_path(x + 1, y))
		{
			return Available;
		}
	}

	if (laby[x][y + 1] == Available)
	{
		index = sign;
		laby[x][y + 1] = Passed;
		if (Available == Find_path(x, y + 1))
		{
			return Available;
		}
	}

	if (laby[x - 1][y] == Available)
	{
		index = sign;
		laby[x - 1][y] = Passed;
		if (Available == Find_path(x - 1, y))
		{
			return Available;
		}
	}

	if (laby[x][y - 1] == Available)
	{
		index = sign;
		laby[x][y - 1] = Passed;
		if (Available == Find_path(x, y - 1))
		{
			return Available;
		}
	}


	return Blocked;			//否则，返回死路

}