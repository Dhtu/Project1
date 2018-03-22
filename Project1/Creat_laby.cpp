#pragma once
#include "stdafx.h"
#define DEBUG 0
#if DEBUG
#include "labyrinth.h"


void Creat_laby(size_t size)
{
	size_t i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			laby[i][j] = 1;
		}
	}

	for (i = 0; i < size; i++) {
		laby[0][i] = Blocked;
		laby[i][0] = Blocked;
		laby[size - 1][i] = Blocked;
		laby[i][size - 1] = Blocked;
	}

	laby[3][1] = laby[3][2] = laby[7][1] = laby[7][2] = Blocked;
	laby[5][3] = laby[6][3] = laby[2][4] = laby[3][4] = Blocked;
	laby[4][4] = laby[4][5] = laby[2][6] = laby[6][6] = Blocked;
	laby[2][7] = laby[3][7] = laby[4][7] = laby[6][7] = Blocked;
	laby[7][7] = laby[1][8] = Blocked;

}
#else


#include<stdlib.h>
#include<time.h>
#define Left 0
#define Up 1
static int count;				/*���ڿ���ѭ������*/

void create(int n, int m)		/*���������Թ��ĺ���*/
{
	int x, y, dir;

	x = n - 1;					/*ÿ���㵽��1��1���㣬���������n-1�����������m-1*/
	y = m - 1;
	while (x > 0 || y > 0) {
		dir = rand() % 2;       /*ÿ���㵽��1��1���㣬�������ϻ�������ͨ��dirѡ�����ϣ�*/
		if (y == 0) {			/*����һ������ľ���Ϊ��ʱ����һ������*/
			laby[n - 1][m] = Available;
			create(n - 1, m);
		}
		else if (x == 0) {
			laby[n][m - 1] = Available;
			create(n, m - 1);
		}
		else if (dir == Left && x > 0) {
			laby[n - 1][m] = Available;
			create(n - 1, m);
		}

		else if (dir == Up && y > 0) {
			laby[n][m - 1] = Available;
			create(n, m - 1);
		}
		else;

		count++;
		if (count > x + y)		/*ÿ���㵽��1��1����x+y��*/
		{
			break;
		}
	}
	return;
}

void Creat_laby() {
	int i, j;
	int p, q;
	srand((unsigned int)time(NULL));
	for (i = 0; i < size; i++)  /*��ʼȫ��ǽ*/
		for (j = 0; j < size; j++) {
			laby[i][j] = Blocked;
		}
	laby[End][End] = Available; /*�����յ�*/

	count = 0;                  /*��һ���ӣ�Start��Start������End��End����·*/
	create(End, End);


	/*��������㵽��1��1����·��,����㲻�ڱ�Ե����Χ��ǽ*/
	for (i = 0; i <= Random_Point_count; i++) {  
		count = 0;
		do {
			p = rand() % (size - 1);
			q = rand() % (size - 1);
		} while (p == Available || q == Available || laby[p][q] == Available ||
			laby[p + 1][q] == Available || laby[p][q + 1] == Available ||
			laby[p - 1][q] == Available || laby[p][q - 1] == Available);
		create(p, q);

	}

	return ;
}

#endif