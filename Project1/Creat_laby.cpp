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
static int count;				/*用于控制循环结束*/

void create(int n, int m)		/*用于生成迷宫的函数*/
{
	int x, y, dir;

	x = n - 1;					/*每个点到（1，1）点，横坐标距离n-1，纵坐标距离m-1*/
	y = m - 1;
	while (x > 0 || y > 0) {
		dir = rand() % 2;       /*每个点到（1，1）点，或者向上或者向左，通过dir选择向上，*/
		if (y == 0) {			/*向左，一个方向的距离为零时走另一个方向*/
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
		if (count > x + y)		/*每个点到（1，1）走x+y次*/
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
	for (i = 0; i < size; i++)  /*开始全是墙*/
		for (j = 0; j < size; j++) {
			laby[i][j] = Blocked;
		}
	laby[End][End] = Available; /*设置终点*/

	count = 0;                  /*打一条从（Start，Start）到（End，End）的路*/
	create(End, End);


	/*设置随机点到（1，1）的路线,随机点不在边缘且周围是墙*/
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