#pragma once
#ifndef _HEADER_H
#define _HEADER_H

#define MaxLength 20			//最大长度
#define Random_Point_count 5					/*随机点的数量*/


#define Blocked 0
#define Available 1
#define Passed 2

#define Start 1
#define End size-2

extern size_t size;
extern struct coordinate path[64];
extern int laby[MaxLength][MaxLength];


struct coordinate	//坐标结构定义
{
	size_t x;
	size_t y;
};

#endif
