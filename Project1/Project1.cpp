 // Project1.cpp: 定义控制台应用程序的入口点。
 //

#include "stdafx.h"
#include "Project1.h"


int main()
{
	int32_t **pLaby = NULL;		                              //迷宫指针
	size_t ulSize, i;                                         //迷宫大小
	Point_S *p_astPath;                                       //最终输出的路径数组指针

	ulSize = Input_size();

								                              //为迷宫数组动态分配空间
	pLaby = (int32_t **)malloc(sizeof(int32_t*) * ulSize);    
	for (i = 0; i < ulSize; i++)
		pLaby[i] = (int *)malloc(sizeof(int32_t) * ulSize);


	Creat_laby(pLaby, ulSize);                                //迷宫初始化
	Print_laby(pLaby, ulSize);                                //打印迷宫

	p_astPath = Find_path(pLaby, ulSize);                      //寻找路径
	Print_path(p_astPath);		                              //打印路径



	
	for (i = 0; i < ulSize; i++)                              //释放内存，防止泄露
		free(pLaby[i]);
	free(pLaby);
	free(p_astPath);

	_getch();                                                          //关闭窗口
	closegraph();                                           
	return 0;
}

