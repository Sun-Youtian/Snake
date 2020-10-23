#include "func.h"

void diffcult()//速度选择界面
{
	
	mvprintw(0, 0, "*********************************************************************************");
	mvprintw(2, 27, "please choose!");
	mvprintw(5, 0, "*********************************************************************************");
	int i;
	for(i=0; i<30; i++)
	{
		mvprintw(i, 0, "*");
		mvprintw(i, 80, "*");
	}
	mvprintw(30, 0, "*********************************************************************************");	
	mvprintw(15, 30, "1:easy");
	mvprintw(17, 30, "2:middle");
	mvprintw(19, 30, "3:high");
	
	while(1)
	{
		ch1=getch();
		if(ch1=='1'||ch1=='2'||ch1=='3')
			break;
	}
	mvprintw(2, 27, "                     ");
	mvprintw(15, 30, "                     ");
	mvprintw(17, 30, "                     ");
	mvprintw(19, 30, "                   ");
	if(ch1 == '1')
	{
		j = 500*1000;	
	}
	
	if(ch1 == '2')
	{
		j = 300*1000;
	}
	
	if(ch1 == '3')
	{
		j = 200*1000;
	}
	
	refresh();
}
void show_diffcult()
{
	if( ch1 == '1')
	{
		mvprintw(3,63,"diffcult: ");
		mvprintw(3,73,"easy  ");
	}
	else if(ch1 == '2')
	{
		mvprintw(3,63,"diffcult: ");
		mvprintw(3,73,"middle  ");
	}
	else
	{
		mvprintw(3,63,"diffcult: ");
		mvprintw(3,73,"high  ");
	}
	
}
void being_dif()//速度自动升级
{
	if(Grade==3)
	{
		j=300*1000;
		mvprintw(3,63,"diffcult: ");
		mvprintw(3,73,"middle ");
	}
	if(Grade==6)
	{
		j=200*1000;
		mvprintw(3,63,"diffcult: ");
		mvprintw(3,73,"high  ");	
	}
}

void Main_Window()	//主界面
{	
	mvprintw(0, 0, "*********************************************************************************");
	mvprintw(1, 25, "Welcome to Eating Sneak !!!");
	mvprintw(5, 0, "*********************************************************************************");
	int i;
	for(i=0; i<30; i++)
	{
		mvprintw(i, 0, "*");
		mvprintw(i, 80, "*");
	}
	mvprintw(30, 0, "*********************************************************************************");
	refresh();
}

int hour, minute, second;            //时分秒
int Grade, Time, Diffcult;            //得分，计时器，难度

void *showInformation(void *arg)
{
	while(1)
	{
		move(3, 1);   
	    //显示时间	
	    printw("Time: %d:%d:%d ", hour, minute, second);
	    second++;
	    if(second >= NUM)
	    {
	        second = 0;
	        minute++;
	    }
	    if(minute >= NUM)
	    {
	        minute = 0;
	        hour++;
	    }
	    //显示分数
	    move(3, 33);
	    printw("Grade: %d", Grade);
	    
		refresh();
		sleep(1);
	}
}

bool Get_Food(Snake *list)
{
	//获取随机值赋值给 My_Food
	MyFood.x = (rand() % 79) + 1 ;
	MyFood.y = (rand() % 24) + 6 ;	
	Snake *p = list;	
	while(p != NULL)
	{
		if(MyFood.x == p->x && MyFood.y == p->y)	//食物刷新在蛇身上，不符合要求
		{
			return false;
		}
		p = p->next;
	}	
	return true;
}

void Show_Food()
{
	mvprintw(MyFood.y, MyFood.x, "$");
}

Snake * Inin_Snake()	//初始化贪吃蛇与食物,返回链表头的地址
{
	Walk_Falg = UP; //默认行进方向向上
	
	Snake *snake_list = Init_List();//初始化贪吃蛇
	Snake *node = NULL;	//防止野指针	
	while(Get_Food(snake_list) == 0);	//食物刷新
	Show_Food();		
	//把这条链表显示在界面上
	Show_Snake(snake_list);	
	return snake_list;
}

void Snake_Walk_UP(Snake *snake_list)	//贪吃蛇往上走
{
	if(MyFood.x == snake_list->x && MyFood.y == (snake_list->y-1))	//判断食物是否被吃：判断蛇头运动会不会跟食物重叠
	{
		Grade++;
		//1,新建一个链表节点，将当前蛇头的坐标信息，放入这个节点
		Snake *node = Create_Node(snake_list->x, snake_list->y);
		
		//2,把新的链表节点 头插法，插入链表
		Insert_Node(snake_list, node);
		
		//3,蛇头往上运动一格
		snake_list->y--;
		
		//4,把新的链表显示出来
		Show_Snake(snake_list);
		
		//5,刷新食物
		while(Get_Food(snake_list) == 0);	//食物刷新
		being_dif();//难度自增
		Show_Food();
	}
	else	//没吃到食物
	{
		if(snake_list->next != NULL)
		{	
			//1,断开最后一个节点，用指针p指向它
			Snake * p = snake_list;
			while(p->next != NULL)
			{
				p = p->next;	//找出最后一个节点 p
			}
			
			p->prev->next = NULL;	//切断最后一个节点
			
			mvprintw(p->y, p->x, " ");
			//2,将链表头的坐标信息赋值给最后一个节点
			p->x = snake_list->x;
			p->y = snake_list->y;
			
			//3,头插法插入节点 p 到 链表
			Insert_Node(snake_list, p);
		}
		//清除走过的痕迹
		mvprintw(snake_list->y, snake_list->x, " ");
		
		//4,改变头结点的位置
		snake_list->y--;
		Show_Snake(snake_list);	//将改变后的位置显示到界面上
	}
}

void Snake_Walk_DOWN(Snake *snake_list)	//贪吃蛇往下走
{
	if(MyFood.x == snake_list->x && MyFood.y == (snake_list->y+1))	
	//判断食物是否被吃：判断蛇头运动会不会跟食物重叠
	{
		Grade++;
		//1,新建一个链表节点，将当前蛇头的坐标信息，放入这个节点
		Snake *node = Create_Node(snake_list->x, snake_list->y);
		
		//2,把新的链表节点 头插法，插入链表
		Insert_Node(snake_list, node);
		
		//3,蛇头往下运动一格
		snake_list->y++;
		
		//4,把新的链表显示出来
		Show_Snake(snake_list);

		//5,刷新食物
		while(Get_Food(snake_list) == 0);	//食物刷新
		Show_Food();
		being_dif();//难度自增
	}
	else	//没吃到食物
	{
		if(snake_list->next != NULL)
		{	
			//1,断开最后一个节点，用指针p指向它
			Snake * p = snake_list;
			while(p->next != NULL)
			{
				p = p->next;	//找出最后一个节点 p
			}
			
			p->prev->next = NULL;	//切断最后一个节点
			
			mvprintw(p->y, p->x, " ");
			//2,将链表头的坐标信息赋值给最后一个节点
			p->x = snake_list->x;
			p->y = snake_list->y;
			
			//3,头插法插入节点 p 到 链表
			Insert_Node(snake_list, p);
		}
		//清除走过的痕迹
		mvprintw(snake_list->y, snake_list->x, " ");
		
		//4,改变头结点的位置
		snake_list->y++;
		Show_Snake(snake_list);	//将改变后的位置显示到界面上
	}
}

void Snake_Walk_LEFT(Snake *snake_list)	//贪吃蛇往左走
{
	if(MyFood.y == snake_list->y && MyFood.x == (snake_list->x-1))	//判断食物是否被吃：判断蛇头运动会不会跟食物重叠
	{
		Grade++;
		//1,新建一个链表节点，将当前蛇头的坐标信息，放入这个节点
		Snake *node = Create_Node(snake_list->x, snake_list->y);
		
		//2,把新的链表节点 头插法，插入链表
		Insert_Node(snake_list, node);
		
		//3,蛇头往左运动一格
		snake_list->x--;
		
		//4,把新的链表显示出来
		Show_Snake(snake_list);

		//5,刷新食物
		while(Get_Food(snake_list) == 0);	//食物刷新
		Show_Food();
		being_dif();//难度自增
	}
	else	//没吃到食物
	{
		if(snake_list->next != NULL)
		{	
			//1,断开最后一个节点，用指针p指向它
			Snake * p = snake_list;
			while(p->next != NULL)
			{
				p = p->next;	//找出最后一个节点 p
			}
			
			p->prev->next = NULL;	//切断最后一个节点
			
			mvprintw(p->y, p->x, " ");
			//2,将链表头的坐标信息赋值给最后一个节点
			p->x = snake_list->x;
			p->y = snake_list->y;
			
			//3,头插法插入节点 p 到 链表
			Insert_Node(snake_list, p);
		}
		//清除走过的痕迹
		mvprintw(snake_list->y, snake_list->x, " ");
		
		//4,改变头结点的位置
		snake_list->x--;
		Show_Snake(snake_list);	//将改变后的位置显示到界面上
	}
}

void Snake_Walk_RIGHT(Snake *snake_list)	//贪吃蛇往右走
{
	if(MyFood.y == snake_list->y && MyFood.x == (snake_list->x+1))	//判断食物是否被吃：判断蛇头运动会不会跟食物重叠
	{
		Grade++;
		//1,新建一个链表节点，将当前蛇头的坐标信息，放入这个节点
		Snake *node = Create_Node(snake_list->x, snake_list->y);
		
		//2,把新的链表节点 头插法，插入链表
		Insert_Node(snake_list, node);
		
		//3,蛇头往右运动一格
		snake_list->x++;
		
		//4,把新的链表显示出来
		Show_Snake(snake_list);

		//5,刷新食物
		while(Get_Food(snake_list) == 0);	//食物刷新
		Show_Food();
		being_dif();//难度自增
	}
	else	//没吃到食物
	{
		if(snake_list->next != NULL)
		{	
			//1,断开最后一个节点，用指针p指向它
			Snake * p = snake_list;
			while(p->next != NULL)
			{
				p = p->next;	//找出最后一个节点 p
			}
			
			p->prev->next = NULL;	//切断最后一个节点
			
			mvprintw(p->y, p->x, " ");
			//2,将链表头的坐标信息赋值给最后一个节点
			p->x = snake_list->x;
			p->y = snake_list->y;
			
			//3,头插法插入节点 p 到 链表
			Insert_Node(snake_list, p);
		}
		//清除走过的痕迹
		mvprintw(snake_list->y, snake_list->x, " ");
		
		//4,改变头结点的位置
		snake_list->x++;
		Show_Snake(snake_list);	//将改变后的位置显示到界面上
	}	
}

bool Is_GameOver(Snake *snake_list)	//判断游戏是否结束，如果结束返回真 true ，否则返回假 false
{
	if(snake_list->x == 0 || snake_list->x == 80 || snake_list->y == 5 || snake_list->y == 30)
	{
		mvprintw(15,26, "Crash the wall. Game over");
		refresh();
		sleep(3);	
		endwin();
		return true;
	}
	else
	{
		Snake *p = snake_list->next;
		if(p == NULL)
		{
			return false;
		}
		while(p != NULL)
		{
			if(snake_list->x == p->x && snake_list->y == p->y)
			{
				mvprintw(15,26, "Crash itself. Game over");
				refresh();
				sleep(3);	
				endwin();
				return true;
			}	
			p = p->next;
		}
		return false;
	}
}

//设计一个循环获取获取键盘数据的函数
void *Get_Cmd(void *arg)
{
	int ch;
	while(1)
	{
		//获取字符，并且判断
		ch = getch();
		if(ch == 'w')	//改变方向，将方向变成向上
		{
			if(Walk_Falg == DOWN)
			{
				Walk_Falg = DOWN;
			}
			else
			{
				Walk_Falg = UP;
			}
		}
		else if(ch == 'a')
		{
			if(Walk_Falg == RIGHT)
			{
				Walk_Falg = RIGHT;
			}
			else
			{
				Walk_Falg = LEFT;
			}
		}
		else if(ch == 's')
		{
			if(Walk_Falg == UP)
			{
				Walk_Falg = UP;
			}
			else
			{
				Walk_Falg = DOWN;
			}
			
		}
		else if(ch == 'd')
		{
			if(Walk_Falg == LEFT)
			{
				Walk_Falg = LEFT;
			}
			else
			{
				Walk_Falg = RIGHT;
			}
			
		}
	}
}

void initGame()
{
    cbreak();                    //把终端的CBREAK模式打开
    noecho();                    //关闭回显
    curs_set(0);                //把光标置为不可见
    hour = minute = second = Time = 0;
    Grade = 0;
}