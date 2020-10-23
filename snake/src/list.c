#include "list.h"		// #include <list.h>

//1,创建链表
Snake * Init_List()
{
	//1)申请一片空间给链表头节点 malloc (从内存的堆空间申请内存)
	Snake *list = (Snake *)malloc(sizeof(Snake));
	if(list == NULL)
	{
		perror("malloc failed");
		return NULL;
	}
	//2)对链表头结点中的内容进行赋值
	list->x = 20;
	list->y = 25;	//初始化蛇头位置
	
	list->next = NULL;
	list->prev = NULL;
	
	//3,返回这个链表节点的地址
	return list;	
}

//2,创建链表节点 (传参数：坐标)
Snake * Create_Node(int x, int y)
{
	//1)申请一片空间给链表节点 malloc
	Snake *node = (Snake *)malloc(sizeof(Snake));
	if(node == NULL)
	{
		perror("malloc node failed");
		return NULL;
	}
	
	//2)对链表头结点中的内容进行赋值
	node->x = x;
	node->y = y;
	node->next = NULL;
	node->prev = NULL;
	//3)返回链表节点
	return node;
}

//3,链表节点插入链表 (头插法)
void Insert_Node(Snake *list, Snake *newnode)
{
	if(list->next == NULL)	//只有一个节点的链表
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

//4,遍历链表
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

//5,删除链表
void Delete_List(Snake *list)
{
	//1,删除每一个节点
	Snake *p = list;
	Snake *q = p;	
	while(p != NULL)
	{
		q = p;
		p = p->next;
		free(q);	//释放q指针指向的节点
	}
}