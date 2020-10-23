#include "func.h"

void diffcult()//�ٶ�ѡ�����
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
void being_dif()//�ٶ��Զ�����
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

void Main_Window()	//������
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

int hour, minute, second;            //ʱ����
int Grade, Time, Diffcult;            //�÷֣���ʱ�����Ѷ�

void *showInformation(void *arg)
{
	while(1)
	{
		move(3, 1);   
	    //��ʾʱ��	
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
	    //��ʾ����
	    move(3, 33);
	    printw("Grade: %d", Grade);
	    
		refresh();
		sleep(1);
	}
}

bool Get_Food(Snake *list)
{
	//��ȡ���ֵ��ֵ�� My_Food
	MyFood.x = (rand() % 79) + 1 ;
	MyFood.y = (rand() % 24) + 6 ;	
	Snake *p = list;	
	while(p != NULL)
	{
		if(MyFood.x == p->x && MyFood.y == p->y)	//ʳ��ˢ���������ϣ�������Ҫ��
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

Snake * Inin_Snake()	//��ʼ��̰������ʳ��,��������ͷ�ĵ�ַ
{
	Walk_Falg = UP; //Ĭ���н���������
	
	Snake *snake_list = Init_List();//��ʼ��̰����
	Snake *node = NULL;	//��ֹҰָ��	
	while(Get_Food(snake_list) == 0);	//ʳ��ˢ��
	Show_Food();		
	//������������ʾ�ڽ�����
	Show_Snake(snake_list);	
	return snake_list;
}

void Snake_Walk_UP(Snake *snake_list)	//̰����������
{
	if(MyFood.x == snake_list->x && MyFood.y == (snake_list->y-1))	//�ж�ʳ���Ƿ񱻳ԣ��ж���ͷ�˶��᲻���ʳ���ص�
	{
		Grade++;
		//1,�½�һ������ڵ㣬����ǰ��ͷ��������Ϣ����������ڵ�
		Snake *node = Create_Node(snake_list->x, snake_list->y);
		
		//2,���µ�����ڵ� ͷ�巨����������
		Insert_Node(snake_list, node);
		
		//3,��ͷ�����˶�һ��
		snake_list->y--;
		
		//4,���µ�������ʾ����
		Show_Snake(snake_list);
		
		//5,ˢ��ʳ��
		while(Get_Food(snake_list) == 0);	//ʳ��ˢ��
		being_dif();//�Ѷ�����
		Show_Food();
	}
	else	//û�Ե�ʳ��
	{
		if(snake_list->next != NULL)
		{	
			//1,�Ͽ����һ���ڵ㣬��ָ��pָ����
			Snake * p = snake_list;
			while(p->next != NULL)
			{
				p = p->next;	//�ҳ����һ���ڵ� p
			}
			
			p->prev->next = NULL;	//�ж����һ���ڵ�
			
			mvprintw(p->y, p->x, " ");
			//2,������ͷ��������Ϣ��ֵ�����һ���ڵ�
			p->x = snake_list->x;
			p->y = snake_list->y;
			
			//3,ͷ�巨����ڵ� p �� ����
			Insert_Node(snake_list, p);
		}
		//����߹��ĺۼ�
		mvprintw(snake_list->y, snake_list->x, " ");
		
		//4,�ı�ͷ����λ��
		snake_list->y--;
		Show_Snake(snake_list);	//���ı���λ����ʾ��������
	}
}

void Snake_Walk_DOWN(Snake *snake_list)	//̰����������
{
	if(MyFood.x == snake_list->x && MyFood.y == (snake_list->y+1))	
	//�ж�ʳ���Ƿ񱻳ԣ��ж���ͷ�˶��᲻���ʳ���ص�
	{
		Grade++;
		//1,�½�һ������ڵ㣬����ǰ��ͷ��������Ϣ����������ڵ�
		Snake *node = Create_Node(snake_list->x, snake_list->y);
		
		//2,���µ�����ڵ� ͷ�巨����������
		Insert_Node(snake_list, node);
		
		//3,��ͷ�����˶�һ��
		snake_list->y++;
		
		//4,���µ�������ʾ����
		Show_Snake(snake_list);

		//5,ˢ��ʳ��
		while(Get_Food(snake_list) == 0);	//ʳ��ˢ��
		Show_Food();
		being_dif();//�Ѷ�����
	}
	else	//û�Ե�ʳ��
	{
		if(snake_list->next != NULL)
		{	
			//1,�Ͽ����һ���ڵ㣬��ָ��pָ����
			Snake * p = snake_list;
			while(p->next != NULL)
			{
				p = p->next;	//�ҳ����һ���ڵ� p
			}
			
			p->prev->next = NULL;	//�ж����һ���ڵ�
			
			mvprintw(p->y, p->x, " ");
			//2,������ͷ��������Ϣ��ֵ�����һ���ڵ�
			p->x = snake_list->x;
			p->y = snake_list->y;
			
			//3,ͷ�巨����ڵ� p �� ����
			Insert_Node(snake_list, p);
		}
		//����߹��ĺۼ�
		mvprintw(snake_list->y, snake_list->x, " ");
		
		//4,�ı�ͷ����λ��
		snake_list->y++;
		Show_Snake(snake_list);	//���ı���λ����ʾ��������
	}
}

void Snake_Walk_LEFT(Snake *snake_list)	//̰����������
{
	if(MyFood.y == snake_list->y && MyFood.x == (snake_list->x-1))	//�ж�ʳ���Ƿ񱻳ԣ��ж���ͷ�˶��᲻���ʳ���ص�
	{
		Grade++;
		//1,�½�һ������ڵ㣬����ǰ��ͷ��������Ϣ����������ڵ�
		Snake *node = Create_Node(snake_list->x, snake_list->y);
		
		//2,���µ�����ڵ� ͷ�巨����������
		Insert_Node(snake_list, node);
		
		//3,��ͷ�����˶�һ��
		snake_list->x--;
		
		//4,���µ�������ʾ����
		Show_Snake(snake_list);

		//5,ˢ��ʳ��
		while(Get_Food(snake_list) == 0);	//ʳ��ˢ��
		Show_Food();
		being_dif();//�Ѷ�����
	}
	else	//û�Ե�ʳ��
	{
		if(snake_list->next != NULL)
		{	
			//1,�Ͽ����һ���ڵ㣬��ָ��pָ����
			Snake * p = snake_list;
			while(p->next != NULL)
			{
				p = p->next;	//�ҳ����һ���ڵ� p
			}
			
			p->prev->next = NULL;	//�ж����һ���ڵ�
			
			mvprintw(p->y, p->x, " ");
			//2,������ͷ��������Ϣ��ֵ�����һ���ڵ�
			p->x = snake_list->x;
			p->y = snake_list->y;
			
			//3,ͷ�巨����ڵ� p �� ����
			Insert_Node(snake_list, p);
		}
		//����߹��ĺۼ�
		mvprintw(snake_list->y, snake_list->x, " ");
		
		//4,�ı�ͷ����λ��
		snake_list->x--;
		Show_Snake(snake_list);	//���ı���λ����ʾ��������
	}
}

void Snake_Walk_RIGHT(Snake *snake_list)	//̰����������
{
	if(MyFood.y == snake_list->y && MyFood.x == (snake_list->x+1))	//�ж�ʳ���Ƿ񱻳ԣ��ж���ͷ�˶��᲻���ʳ���ص�
	{
		Grade++;
		//1,�½�һ������ڵ㣬����ǰ��ͷ��������Ϣ����������ڵ�
		Snake *node = Create_Node(snake_list->x, snake_list->y);
		
		//2,���µ�����ڵ� ͷ�巨����������
		Insert_Node(snake_list, node);
		
		//3,��ͷ�����˶�һ��
		snake_list->x++;
		
		//4,���µ�������ʾ����
		Show_Snake(snake_list);

		//5,ˢ��ʳ��
		while(Get_Food(snake_list) == 0);	//ʳ��ˢ��
		Show_Food();
		being_dif();//�Ѷ�����
	}
	else	//û�Ե�ʳ��
	{
		if(snake_list->next != NULL)
		{	
			//1,�Ͽ����һ���ڵ㣬��ָ��pָ����
			Snake * p = snake_list;
			while(p->next != NULL)
			{
				p = p->next;	//�ҳ����һ���ڵ� p
			}
			
			p->prev->next = NULL;	//�ж����һ���ڵ�
			
			mvprintw(p->y, p->x, " ");
			//2,������ͷ��������Ϣ��ֵ�����һ���ڵ�
			p->x = snake_list->x;
			p->y = snake_list->y;
			
			//3,ͷ�巨����ڵ� p �� ����
			Insert_Node(snake_list, p);
		}
		//����߹��ĺۼ�
		mvprintw(snake_list->y, snake_list->x, " ");
		
		//4,�ı�ͷ����λ��
		snake_list->x++;
		Show_Snake(snake_list);	//���ı���λ����ʾ��������
	}	
}

bool Is_GameOver(Snake *snake_list)	//�ж���Ϸ�Ƿ������������������� true �����򷵻ؼ� false
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

//���һ��ѭ����ȡ��ȡ�������ݵĺ���
void *Get_Cmd(void *arg)
{
	int ch;
	while(1)
	{
		//��ȡ�ַ��������ж�
		ch = getch();
		if(ch == 'w')	//�ı䷽�򣬽�����������
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
    cbreak();                    //���ն˵�CBREAKģʽ��
    noecho();                    //�رջ���
    curs_set(0);                //�ѹ����Ϊ���ɼ�
    hour = minute = second = Time = 0;
    Grade = 0;
}