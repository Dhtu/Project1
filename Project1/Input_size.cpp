#pragma once
#include "stdafx.h"
#include <comdef.h>

#define SIZE_OF_WINDOWS 960,960
#define START_POINT 0,0
size_t Input_size()
{

	//初始化图形窗口
	initgraph(SIZE_OF_WINDOWS);

	setbkcolor(RGB(238, 238, 85));
	cleardevice();

	//定义字符串缓冲区，并接受用户输入
	TCHAR s[10];
	InputBox(s, 10, _T("请输入迷宫大小(10-30)："));

	//将输入转换成数字
	int32_t lSize;
	_bstr_t b(s);
	char* as = b;
	sscanf_s(as, "%d", &lSize);


	RECT r = { START_POINT, SIZE_OF_WINDOWS };
	drawtext(_T("按任意键继续"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	_getch();
	cleardevice();
	return lSize;

}