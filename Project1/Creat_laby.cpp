#pragma once
#include "stdafx.h"
#include<stdlib.h>
#include<time.h>


static int32_t **sg_pLaby;                                             //�Թ�ָ��
static size_t sg_ulSize;                                               //�Թ���С
static int32_t **sg_pPath;                                             /*���ڴ���߹�������*/
static int32_t sg_sCount;



void maze(int32_t x, int32_t y) {
	int32_t sDir[4][2] = { 0,1,1,0,0,-1,-1,0 };                        /*�ĸ�����*/
	int32_t i, j,sFlag = 0;
	int32_t count = 0;
	for (i = 0; i<sg_ulSize; i++)
		for (j = 0; j<sg_ulSize; j++) {                                /*��������û��2ʱ����*/
			if (sg_pLaby[i][j] == 2)
				sFlag = 1;
		}
	if (sFlag == 0) {
		return;
	}
	do {                                                               /*ѡ���򣬲��ڱ�Ե������������1*/
		j = rand() % 4;
		count++;
		if (count>25) {                                                /*�����Χû��1���˳�ѭ��*/
			break;
		}
	} while (x + 2 * sDir[j][0] <= 0 || y + 2 * sDir[j][1] <= 0 || x + 2 * sDir[j][0] >= sg_ulSize - 1 || y + 2 * sDir[j][1] >= sg_ulSize - 1 || sg_pLaby[x + 2 * sDir[j][0]][y + 2 * sDir[j][1]] != 2);
	if (count <= 25) {                                                 /*�����Χ��1����ͨ1��1֮���·����¼�߹���·���ݹ�*/
		sg_pLaby[x][y] = AVAILABLE;
		sg_pLaby[x + sDir[j][0]][y + sDir[j][1]] = AVAILABLE;
		sg_pLaby[x + 2 * sDir[j][0]][y + 2 * sDir[j][1]] = AVAILABLE;
		sg_sCount++;
		sg_pPath[sg_sCount][0] = x + 2 * sDir[j][0];
		sg_pPath[sg_sCount][1] = y + 2 * sDir[j][1];


		maze(x + 2 * sDir[j][0], y + 2 * sDir[j][1]);
	}
	else {                                                             /*�����Χû��1���˵���һλ�õݹ�*/

		sg_sCount--;
		maze(sg_pPath[sg_sCount][0], sg_pPath[sg_sCount][1]);

	}
}

void Creat_laby(int32_t **pLaby, size_t ulSize) {
	int32_t i, j;					                                   //ѭ������                        //�������
	sg_ulSize = ulSize;
	size_t ulSafety = 0;
	sg_sCount = 0;


	srand((unsigned int)time(NULL));
	sg_pLaby = pLaby;
	sg_pPath = (int32_t**)malloc(sizeof(int32_t*) * ulSize*ulSize);
	for (i = 0; i < ulSize*ulSize; i++)
	{
		sg_pPath[i] = (int32_t*)malloc(sizeof(int32_t) * 2);
	}


	for (i = 0; i<sg_ulSize; i++)                                      /*��ʼ��Χ��ǽ�����������������н��ĵ���1*/
		for (j = 0; j<sg_ulSize; j++) {
			if (i == 0 || j == 0 || i == sg_ulSize - 1 || j == sg_ulSize - 1) {
				sg_pLaby[i][j] = BLOCKED;
			}
			else if ((i + 1) % 2 == 0 && (j + 1) % 2 == 0) {
				sg_pLaby[i][j] = 2;
			}
			else {
				sg_pLaby[i][j] = BLOCKED;
			}
		}
	maze(1, 1);                                                        /*�ӣ�1��1���ݹ�*/
	sg_pLaby[1][0] = AVAILABLE;
	sg_pLaby[sg_ulSize - 2][sg_ulSize - 1] = AVAILABLE;                /*��ͨ��㣬�յ�*/
	sg_pLaby[sg_ulSize - 2][sg_ulSize - 2] = AVAILABLE;
	sg_pLaby[sg_ulSize - 3][sg_ulSize - 2] = AVAILABLE;



	for (i = 0; i < ulSize*ulSize; i++)
	{
		free(sg_pPath[i]);
	}
	free(sg_pPath);
	

	return;
}