#pragma once
#ifndef _HEADER_H
#define _HEADER_H

#define MaxLength 20				//最大长度
#define Random_Point_count 5		//随机点的数量


#define Blocked 0					//墙
#define Available 1					//通路
#define Passed 2					//已经过的路线

#define Start 1						//起始点
#define End size-2					//终点

extern size_t size;					//迷宫的大小
extern struct coordinate path[100];	//路径数组
extern int laby[MaxLength][MaxLength];//迷宫数组


struct coordinate					//坐标结构定义
{
	size_t x;
	size_t y;
};

#endif
