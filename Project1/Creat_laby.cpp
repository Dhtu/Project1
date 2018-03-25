#pragma once
#include "stdafx.h"
#define DEBUG 0
#if DEBUG
void Creat_laby(size_t g_ulSize)						//单元测试代码
{
	size_t i, j;
	for (i = 0; i < g_ulSize; i++) {
		for (j = 0; j < g_ulSize; j++) {
			g_aLaby[i][j] = 1;
		}
	}

	for (i = 0; i < g_ulSize; i++) {
		g_aLaby[0][i] = Blocked;
		g_aLaby[i][0] = Blocked;
		g_aLaby[g_ulSize - 1][i] = Blocked;
		g_aLaby[i][g_ulSize - 1] = Blocked;
	}

	g_aLaby[3][1] = g_aLaby[3][2] = g_aLaby[7][1] = g_aLaby[7][2] = Blocked;
	g_aLaby[5][3] = g_aLaby[6][3] = g_aLaby[2][4] = g_aLaby[3][4] = Blocked;
	g_aLaby[4][4] = g_aLaby[4][5] = g_aLaby[2][6] = g_aLaby[6][6] = Blocked;
	g_aLaby[2][7] = g_aLaby[3][7] = g_aLaby[4][7] = g_aLaby[6][7] = Blocked;
	g_aLaby[7][7] = g_aLaby[1][8] = Blocked;

}

#else


#include<stdlib.h>
#include<time.h>


#define CL_LEFT 0
#define CL_UP 1


static size_t sg_ulCount;					            /*用于控制循环结束*/
static int32_t **sg_pLaby;
static size_t sg_ulSize;

void CL_Create(int32_t Dest_X, int32_t Dest_Y)	            /*用于生成迷宫的函数*/
{
	int32_t lCurrent_X, lCurrent_Y, lDirector;
	lCurrent_X = Dest_X - 1;							/*每个点到（1，1）点，横坐标距离Dest_X-1，纵坐标距离Dest_Y-1*/
	lCurrent_Y = Dest_Y - 1;


	while (lCurrent_X > 0 || lCurrent_Y > 0) {
		lDirector = rand() % 2;				            /*每个点到（1，1）点，或者向上或者向左，通过lDirector选择向上，*/


		if (lCurrent_Y == 0) {						    /*向左，一个方向的距离为零时走另一个方向*/
			sg_pLaby[Dest_X - 1][Dest_Y] = AVAILABLE;
			CL_Create(Dest_X - 1, Dest_Y);
		}

		else if (lCurrent_X == 0) {
			sg_pLaby[Dest_X][Dest_Y - 1] = AVAILABLE;
			CL_Create(Dest_X, Dest_Y - 1);
		}

		else if (lDirector == CL_LEFT && lCurrent_X > 0) {
			sg_pLaby[Dest_X - 1][Dest_Y] = AVAILABLE;
			CL_Create(Dest_X - 1, Dest_Y);
		}

		else if (lDirector == CL_UP && lCurrent_Y > 0) {
			sg_pLaby[Dest_X][Dest_Y - 1] = AVAILABLE;
			CL_Create(Dest_X, Dest_Y - 1);
		}

		else;

		sg_ulCount++;
		if (sg_ulCount > lCurrent_X + lCurrent_Y)		/*每个点到（1，1）走lCurrent_X+lCurrent_Y次*/
		{
			break;
		}
	}


	return;
}

void Creat_laby(int32_t **pLaby,size_t ulSize) {
	int32_t i, j;					                    //循环变量
	int32_t ulRandom_X, ulRandom_Y;	                    //随机坐标
	sg_ulSize = ulSize;
	size_t ulSafety = 0;


	srand((unsigned int)time(NULL));
	

	for (i = 0; i<ulSize; i++)
		pLaby[i] = (int *)malloc(sizeof(int32_t) * ulSize);
	sg_pLaby = pLaby;


	for (i = 0; i < ulSize; i++)                      /*开始全是墙*/
		for (j = 0; j < ulSize; j++) {
			sg_pLaby[i][j] = BLOCKED;
		}
	sg_pLaby[END][END] = AVAILABLE;	                    /*设置终点*/

	sg_ulCount = 0;					                    /*打一条从（Start，Start）到（End，End）的路*/
	CL_Create(END, END);


	for (i = 0; i <= Random_Point_Count; i++) {         /*设置随机点到（1，1）的路线*/
		sg_ulCount = 0;

		do {
			ulRandom_X = rand() % (ulSize - 2)+1;
			ulRandom_Y = rand() % (ulSize - 2)+1;

			ulSafety++;
			if (200<ulSafety)//保护装置
			{
				break;
			}
		} while (ulRandom_X == AVAILABLE ||             //随机点不在边缘且周围是墙
				 ulRandom_Y == AVAILABLE ||
			  	 sg_pLaby[ulRandom_X][ulRandom_Y] == AVAILABLE ||
				 sg_pLaby[ulRandom_X + 1][ulRandom_Y] == AVAILABLE ||
				 sg_pLaby[ulRandom_X][ulRandom_Y + 1] == AVAILABLE ||
				 sg_pLaby[ulRandom_X - 1][ulRandom_Y] == AVAILABLE ||
				 sg_pLaby[ulRandom_X][ulRandom_Y - 1] == AVAILABLE);

				 CL_Create(ulRandom_X, ulRandom_Y);

	}


	return ;
}
#endif