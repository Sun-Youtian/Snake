#ifndef _LIST_H_
#define _LIST_H_

//1,系统头文件
#include "curses.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/time.h>

//2,宏定义
#define NUM 60
#define UP 0 
#define DOWN 1
#define LEFT 2
#define RIGHT 3

//3,结构体，全局变量（全局变量定义不能赋值）

int Walk_Falg;	//贪吃蛇行进方向

int ch1;//速度选择
int j;

int hour, minute, second;            //时分秒
int Grade, Time, Diffcult;            //得分，计时器，难度

typedef struct food{
	int x;
	int y;
}Food;

Food MyFood;

typedef struct snake_node{
	int x;
	int y;
	struct snake_node *next;
	struct snake_node *prev;
}Snake;	

//4,函数声明
Snake * Init_List();
Snake * Create_Node(int x, int y);
void Insert_Node(Snake *list, Snake *newnode);
void Show_Snake(Snake *list);
void Delete_List(Snake *list);

#endif
