#pragma once
#include "stdafx.h"
#include "labyrinth.h"


int Find_path(size_t x, size_t y)
{
	size_t sign;

	path[index].x = x;		//����ǰλ�ò���ջ��
	path[index].y = y;
	index++;
	sign = index;			//����index���������

	
	if (x == End && y == End)//�ж��Ƿ񵽴��յ�
	{
		path[index].x = '#';//��ֹ����
		return Available;
	}

	/*ͨ�����ϳ��Ը�������ֱ������ͨ·��Available�����������·��Blocked�����ջ*/
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


	return Blocked;			//���򣬷�����·

}