// Project1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "labyrinth.h"
/*
#include "Creat_laby.cpp"	//调用函数
#include "Print_laby.cpp"
#include "Find_path.cpp"
#include "print_path.cpp"
*/
void Creat_laby();
void Print_laby();
int Find_path(size_t x, size_t y);
void Print_path();

size_t size;			//迷宫的大小

struct coordinate path[64];//最终输出的路径数组

size_t index;			//path数组的下标

int laby[MaxLength][MaxLength];	//迷宫数组



int main()
{
	printf_s("请输入迷宫的大小：");
	scanf_s("%d", &size);
	index = 0;
	Creat_laby();	//迷宫初始化
	
	Print_laby();		//打印迷宫

	Find_path(Start, Start);	//寻找路径
	Print_path();		//打印路径
    return 0;
}

