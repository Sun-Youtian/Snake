#include "list.h"		// #include <list.h>

//1,��������
Snake * Init_List()
{
	//1)����һƬ�ռ������ͷ�ڵ� malloc (���ڴ�Ķѿռ������ڴ�)
	Snake *list = (Snake *)malloc(sizeof(Snake));
	if(list == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	//2)������ͷ����е����ݽ��и�ֵ
	list->x = 20;
	list->y = 25;	//��ʼ����ͷλ��
	
	list->next = NULL;
	list->prev = NULL;
	
	//3,�����������ڵ�ĵ�ַ
	return list;	
}

//2,��������ڵ� (������������)
Snake * Create_Node(int x, int y)
{
	//1)����һƬ�ռ������ڵ� malloc
	Snake *node = (Snake *)malloc(sizeof(Snake));
	if(node == NULL)
	{
		perror("malloc node failed");
		return NULL;
	}
	
	//2)������ͷ����е����ݽ��и�ֵ
	node->x = x;
	node->y = y;
	node->next = NULL;
	node->prev = NULL;
	//3)��������ڵ�
	return node;
}

//3,����ڵ�������� (ͷ�巨)
void Insert_Node(Snake *list, Snake *newnode)
{
	if(list->next == NULL)	//ֻ��һ���ڵ������
	{
		list->next = newnode;
		newnode->prev = list;
	}
	else
	{
		newnode->next = list->next;
		list->next = newnode;
		newnode->prev = list;
		newnode->next->prev = newnode;	
	}
}

//4,��������
void Show_Snake(Snake *list)
{
	Snake *p = list->next;
	mvprintw(list->y, list->x, "@");
	while(p != NULL)
	{
		//printf("(%d,%d)\n", p->x, p->y);
		mvprintw(p->y, p->x, "O");
		
		p = p->next;
	}
	refresh();
}

//5,ɾ������
void Delete_List(Snake *list)
{
	//1,ɾ��ÿһ���ڵ�
	Snake *p = list;
	Snake *q = p;	
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);	//�ͷ�qָ��ָ��Ľڵ�
	}
}