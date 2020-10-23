#include "list.h"
#include "func.h"
#include <pthread.h>
//每三个食物增加一级,一共三级
//进入速度选择界面后，请输入1,2，3
int main()
{
	int i;
	//初始化界面
	initscr();
		
	initGame();//隐藏光标
	
	diffcult();//难度选择
	show_diffcult();
	Snake *p = NULL;
	Snake *q = NULL;
	
	Main_Window();
	Snake *snake_list = Inin_Snake();	//初始化贪吃蛇与食物

	//创建线程去执行函数 Get_Cmd
	pthread_t pid;
	pthread_create(&pid, NULL, Get_Cmd, NULL);

	pthread_t pid2;
	pthread_create(&pid2, NULL, showInformation, NULL);
	
	while(1)	//贪吃蛇行进
	{
		switch(Walk_Falg)
		{
			case UP:
				Snake_Walk_UP(snake_list);
				break;
				
			case DOWN:
				Snake_Walk_DOWN(snake_list);
				break;
				
			case LEFT:
				Snake_Walk_LEFT(snake_list);
				break;
			
			case RIGHT:
				Snake_Walk_RIGHT(snake_list);
				break;
			
			default:
				break;
		}
	
		//每次移动之后，判断游戏是否结束
		if(Is_GameOver(snake_list))
		{
			break;
		}
		refresh();	//刷新界面
		usleep(j);	//延时一段时间	
	}
	
	return 0;
}