#ifndef _LIST_H_
#define _LIST_H_

//1,ϵͳͷ�ļ�
#include "curses.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/time.h>

//2,�궨��
#define NUM 60
#define UP 0 
#define DOWN 1
#define LEFT 2
#define RIGHT 3

//3,�ṹ�壬ȫ�ֱ�����ȫ�ֱ������岻�ܸ�ֵ��

int Walk_Falg;	//̰�����н�����

int ch1;//�ٶ�ѡ��
int j;

int hour, minute, second;            //ʱ����
int Grade, Time, Diffcult;            //�÷֣���ʱ�����Ѷ�

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

//4,��������
Snake * Init_List();
Snake * Create_Node(int x, int y);
void Insert_Node(Snake *list, Snake *newnode);
void Show_Snake(Snake *list);
void Delete_List(Snake *list);

#endif
