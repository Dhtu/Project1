#pragma once
#include "stdafx.h"
#define DEBUG 0
#if DEBUG
void Creat_laby(size_t g_ulSize)						//��Ԫ���Դ���
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
static size_t sg_ulCount;					            /*���ڿ���ѭ������*/

void CL_Create(int32_t Dest_X, int32_t Dest_Y)	            /*���������Թ��ĺ���*/
{
	int32_t lCurrent_X, lCurrent_Y, lDirector;
	lCurrent_X = Dest_X - 1;							/*ÿ���㵽��1��1���㣬���������Dest_X-1�����������Dest_Y-1*/
	lCurrent_Y = Dest_Y - 1;


	while (lCurrent_X > 0 || lCurrent_Y > 0) {
		lDirector = rand() % 2;				            /*ÿ���㵽��1��1���㣬�������ϻ�������ͨ��lDirectorѡ�����ϣ�*/


		if (lCurrent_Y == 0) {						    /*����һ������ľ���Ϊ��ʱ����һ������*/
			g_aLaby[Dest_X - 1][Dest_Y] = AVAILABLE;
			CL_Create(Dest_X - 1, Dest_Y);
		}

		else if (lCurrent_X == 0) {
			g_aLaby[Dest_X][Dest_Y - 1] = AVAILABLE;
			CL_Create(Dest_X, Dest_Y - 1);
		}

		else if (lDirector == CL_LEFT && lCurrent_X > 0) {
			g_aLaby[Dest_X - 1][Dest_Y] = AVAILABLE;
			CL_Create(Dest_X - 1, Dest_Y);
		}

		else if (lDirector == CL_UP && lCurrent_Y > 0) {
			g_aLaby[Dest_X][Dest_Y - 1] = AVAILABLE;
			CL_Create(Dest_X, Dest_Y - 1);
		}

		else;

		sg_ulCount++;
		if (sg_ulCount > lCurrent_X + lCurrent_Y)		/*ÿ���㵽��1��1����lCurrent_X+lCurrent_Y��*/
		{
			break;
		}
	}


	return;
}

void Creat_laby() {
	int32_t i, j;					                    //ѭ������
	int32_t ulRandom_X, ulRandom_Y;	                    //�������
	srand((unsigned int)time(NULL));


	for (i = 0; i < g_ulSize; i++)                      /*��ʼȫ��ǽ*/
		for (j = 0; j < g_ulSize; j++) {
			g_aLaby[i][j] = BLOCKED;
		}
	g_aLaby[END][END] = AVAILABLE;	                    /*�����յ�*/


	sg_ulCount = 0;					                    /*��һ���ӣ�Start��Start������End��End����·*/
	CL_Create(END, END);


	for (i = 0; i <= Random_Point_Count; i++) {         /*��������㵽��1��1����·��*/
		sg_ulCount = 0;

		do {
			ulRandom_X = rand() % (g_ulSize - 1);
			ulRandom_Y = rand() % (g_ulSize - 1);
		} while (ulRandom_X == AVAILABLE ||             //����㲻�ڱ�Ե����Χ��ǽ
				 ulRandom_Y == AVAILABLE ||
			  	 g_aLaby[ulRandom_X][ulRandom_Y] == AVAILABLE ||
				 g_aLaby[ulRandom_X + 1][ulRandom_Y] == AVAILABLE ||
				 g_aLaby[ulRandom_X][ulRandom_Y + 1] == AVAILABLE ||
				 g_aLaby[ulRandom_X - 1][ulRandom_Y] == AVAILABLE ||
				 g_aLaby[ulRandom_X][ulRandom_Y - 1] == AVAILABLE);

				 CL_Create(ulRandom_X, ulRandom_Y);

	}


	return ;
}
#endif