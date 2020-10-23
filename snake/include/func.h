#ifndef _FUNC_H_
#define _FUNC_H_

//函数头文件声明
#include "list.h"

void diffcult();//难度选择
void being_dif();//难度自增


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



