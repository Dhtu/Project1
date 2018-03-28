#pragma once
#ifndef _HEADER_H
#define _HEADER_H

#define Random_Point_Count 5		    //随机点的数量


#define BLOCKED 0					    //墙
#define AVAILABLE 1					    //通路
#define PASSED 2                        //已经过的路线

#define START 1				            //起始点
#define END sg_ulSize-2			        //终点


typedef signed int  int32_t;


typedef struct Coordinate_S		        //坐标结构定义
{
	size_t x;
	size_t y;
}Point_S;

#endif
