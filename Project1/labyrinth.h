#pragma once
#ifndef _HEADER_H
#define _HEADER_H

#define MaxLength 20			//��󳤶�
#define Random_Point_count 5					/*����������*/


#define Blocked 0
#define Available 1
#define Passed 2

#define Start 1
#define End size-2

extern size_t size;
extern struct coordinate path[64];
extern int laby[MaxLength][MaxLength];


struct coordinate	//����ṹ����
{
	size_t x;
	size_t y;
};

#endif
