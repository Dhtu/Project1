#pragma once
#ifndef _HEADER_H
#define _HEADER_H

#define MAXLENGTH 20				        //��󳤶�
#define Random_Point_Count 5		        //����������


#define BLOCKED 0					        //ǽ
#define AVAILABLE 1					        //ͨ·
#define PASSED 2					        //�Ѿ�����·��

#define START 1						        //��ʼ��
#define END g_ulSize-2					    //�յ�

typedef signed int  int32_t;

extern size_t g_ulSize;					    //�Թ��Ĵ�С
extern struct Coordinate_S g_astPath[100];	//·������
extern int g_aLaby[MAXLENGTH][MAXLENGTH];   //�Թ�����


struct Coordinate_S					        //����ṹ����
{
	size_t x;
	size_t y;
};

#endif
