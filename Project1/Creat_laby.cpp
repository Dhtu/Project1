#pragma once
#include "stdafx.h"
#include<stdlib.h>
#include<time.h>


#define CL_LEFT 0
#define CL_UP 1


static size_t sg_ulCount;					                  /*���ڿ���ѭ������*/
static int32_t **sg_pLaby;                                    //�Թ�ָ��
static size_t sg_ulSize;                                      //�Թ���С

void CL_Create(int32_t Dest_X, int32_t Dest_Y)	              /*���������Թ��ĺ���*/
{
	int32_t lCurrent_X, lCurrent_Y, lDirector;
	lCurrent_X = Dest_X - 1;							      /*ÿ���㵽��1��1���㣬���������Dest_X-1�����������Dest_Y-1*/
	lCurrent_Y = Dest_Y - 1;


	while (lCurrent_X > 0 || lCurrent_Y > 0) {
		lDirector = rand() % 2;				                  /*ÿ���㵽��1��1���㣬�������ϻ�������ͨ��lDirectorѡ�����ϣ�*/


		if (lCurrent_Y == 0) {						          /*����һ������ľ���Ϊ��ʱ����һ������*/
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
		if (sg_ulCount > lCurrent_X + lCurrent_Y)		      /*ÿ���㵽��1��1����lCurrent_X+lCurrent_Y��*/
		{
			break;
		}
	}


	return;
}

void Creat_laby(int32_t **pLaby, size_t ulSize) {
	int32_t i, j;					                          //ѭ������
	int32_t ulRandom_X, ulRandom_Y;	                          //�������
	sg_ulSize = ulSize;
	size_t ulSafety = 0;


	srand((unsigned int)time(NULL));


	for (i = 0; i < ulSize; i++)
		pLaby[i] = (int *)malloc(sizeof(int32_t) * ulSize);
	sg_pLaby = pLaby;


	for (i = 0; i < ulSize; i++)                              /*��ʼȫ��ǽ*/
		for (j = 0; j < ulSize; j++) {
			sg_pLaby[i][j] = BLOCKED;
		}
	sg_pLaby[END][END] = AVAILABLE;	                          /*�����յ�*/

	sg_ulCount = 0;					                          /*��һ���ӣ�Start��Start������End��End����·*/
	CL_Create(END, END);


	for (i = 0; i <= Random_Point_Count; i++) {               /*��������㵽��1��1����·��*/
		sg_ulCount = 0;

		do {
			ulRandom_X = rand() % (ulSize - 2) + 1;
			ulRandom_Y = rand() % (ulSize - 2) + 1;

			ulSafety++;
			if (200 < ulSafety)                               //����װ��
			{
				break;
			}
		} while (ulRandom_X == AVAILABLE ||                   //����㲻�ڱ�Ե����Χ��ǽ
			ulRandom_Y == AVAILABLE ||
			sg_pLaby[ulRandom_X][ulRandom_Y] == AVAILABLE ||
			sg_pLaby[ulRandom_X + 1][ulRandom_Y] == AVAILABLE ||
			sg_pLaby[ulRandom_X][ulRandom_Y + 1] == AVAILABLE ||
			sg_pLaby[ulRandom_X - 1][ulRandom_Y] == AVAILABLE ||
			sg_pLaby[ulRandom_X][ulRandom_Y - 1] == AVAILABLE);

		CL_Create(ulRandom_X, ulRandom_Y);

	}


	return;
}