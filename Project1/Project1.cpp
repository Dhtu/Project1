// Project1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Project1.h"


int main()
{
	int32_t **pLaby = NULL;		                          //迷宫指针
	size_t ulSize, i;		                              //迷宫大小
	Point_S *p_astPath;                                   //最终输出的路径数组指针


	printf_s("请输入一个大于十的数：");
	scanf_s("%d", &ulSize);


	pLaby = (int32_t **)malloc(sizeof(int32_t*) * ulSize);//为迷宫数组动态分配空间


	Creat_laby(pLaby, ulSize);	                          //迷宫初始化
	Print_laby(pLaby, ulSize);		                      //打印迷宫

	p_astPath = Find_path(pLaby, ulSize);	              //寻找路径
	Print_path(p_astPath);		                          //打印路径

	return 0;
}

