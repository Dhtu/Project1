#pragma once
#ifndef _HEADER_H
#define _HEADER_H

#define MaxLength 20				//��󳤶�
#define Random_Point_count 5		//����������


#define Blocked 0					//ǽ
#define Available 1					//ͨ·
#define Passed 2					//�Ѿ�����·��

#define Start 1						//��ʼ��
#define End size-2					//�յ�

extern size_t size;					//�Թ��Ĵ�С
extern struct coordinate path[100];	//·������
extern int laby[MaxLength][MaxLength];//�Թ�����


struct coordinate					//����ṹ����
{
	size_t x;
	size_t y;
};

#endif
