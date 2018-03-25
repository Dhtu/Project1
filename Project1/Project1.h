#pragma once


/*==============================迷宫创建函数=================================*/
/**
*  \brief 将迷宫数组初始化为迷宫
*
*  
*  \param[in][out]  迷宫指针，迷宫大小
*/
void Creat_laby(int32_t **pLaby, size_t ulSize);

/*==============================迷宫打印函数=================================*/
/**
*  \brief		打印迷宫
*
*  
*  \param[in][out]  迷宫指针，迷宫大小
*/
void Print_laby(int32_t **pLaby, size_t ulSize);

/*==============================迷宫寻址函数=================================*/
/**
*  \brief		输出迷宫路径数组
*
*  \param[in][out]  迷宫指针，迷宫大小    一条通路
*  \retval		Point_S *，指向存储的路径
*/
Point_S *Find_path(int32_t **pLaby, size_t ulSize);
/*==============================路径打印函数=================================*/
/**
*  \brief		打印迷宫路径
*
*
*  \param[in][out]   迷宫路径   
*/
void Print_path(Point_S *p_astPath);

