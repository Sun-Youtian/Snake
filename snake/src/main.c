#include "list.h"
#include "func.h"
#include <pthread.h>
//ÿ����ʳ������һ��,һ������
//�����ٶ�ѡ������������1,2��3
int main()
{
	int i;
	//��ʼ������
	initscr();
		
	initGame();//���ع��
	
	diffcult();//�Ѷ�ѡ��
	show_diffcult();
	Snake *p = NULL;
	Snake *q = NULL;
	
	Main_Window();
	Snake *snake_list = Inin_Snake();	//��ʼ��̰������ʳ��

	//�����߳�ȥִ�к��� Get_Cmd
	pthread_t pid;
	pthread_create(&pid, NULL, Get_Cmd, NULL);

	pthread_t pid2;
	pthread_create(&pid2, NULL, showInformation, NULL);
	
	while(1)	//̰�����н�
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
	
		//ÿ���ƶ�֮���ж���Ϸ�Ƿ����
		if(Is_GameOver(snake_list))
		{
			break;
		}
		refresh();	//ˢ�½���
		usleep(j);	//��ʱһ��ʱ��	
	}
	
	return 0;
}