#pragma once
#ifndef _HEADER_H
#define _HEADER_H

#define Random_Point_Count 5		    //����������


#define BLOCKED 0					    //ǽ
#define AVAILABLE 1					    //ͨ·
#define PASSED 2                        //�Ѿ�����·��

#define START 1				            //��ʼ��
#define END sg_ulSize-2			        //�յ�


typedef signed int  int32_t;


typedef struct Coordinate_S		        //����ṹ����
{
	size_t x;
	size_t y;
}Point_S;

#endif
