#ifndef _FUNC_H_
#define _FUNC_H_

//����ͷ�ļ�����
#include "list.h"

void diffcult();//�Ѷ�ѡ��
void being_dif();//�Ѷ�����


void Main_Window();
void *showInformation(void *arg);
bool Get_Food(Snake *list);
void Show_Food();
Snake * Inin_Snake();

void Snake_Walk_UP(Snake *snake_list);
void Snake_Walk_DOWN(Snake *snake_list);
void Snake_Walk_LEFT(Snake *snake_list);
void Snake_Walk_RIGHT(Snake *snake_list);

bool Is_GameOver(Snake *snake_list);
void *Get_Cmd(void *arg);
void initGame();
void show_diffcult();
#endif



