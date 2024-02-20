#ifndef __PLAY_BUTTON_H
#define __PLAY_BUTTON_H
#include "sys.h"
#include "system.h"

#define PLAY_BUTTON_TASK_PRIO		3     //Task priority 
#define PLAY_BUTTON_STK_SIZE 		128   //Task stack size 




/*--------Play Button control pin--------*/

#define PLAY_BUTTON_PORT GPIOD
#define PLAY_BUTTON_PIN GPIO_Pin_8
#define PLAY_BUTTON PDin(8) 

/*----------------------------------*/

void Play_Button_Init(void);  
void pbutton_task(void *pvParameters);
extern int pbutton_Count;
#endif