#pragma once
#include "stdafx.h"
#include <comdef.h>

#define SIZE_OF_WINDOWS 960,960
#define START_POINT 0,0
size_t Input_size()
{

	//��ʼ��ͼ�δ���
	initgraph(SIZE_OF_WINDOWS);

	setbkcolor(RGB(238, 238, 85));
	cleardevice();

	//�����ַ������������������û�����
	TCHAR s[10];
	InputBox(s, 10, _T("�������Թ���С(10-30)��"));

	//������ת��������
	int32_t lSize;
	_bstr_t b(s);
	char* as = b;
	sscanf_s(as, "%d", &lSize);


	RECT r = { START_POINT, SIZE_OF_WINDOWS };
	drawtext(_T("�����������"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	_getch();
	cleardevice();
	return lSize;

}