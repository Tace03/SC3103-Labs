#ifndef __BUZZER_H
#define __BUZZER_H
#include "sys.h"
#include "system.h"

#define BUZZER_TASK_PRIO		3     //Task priority 
#define BUZZER_STK_SIZE 		128   //Task stack size 


/*--------BUZZERR control pin--------*/
#define BUZ_PORT GPIOB
#define BUZ_PIN GPIO_Pin_10
#define BUZ PBout(10) 
/*----------------------------------*/

void Buzzer_Init(void);  
void buzzer_task(void *pvParameters);
extern int buzzer_Count;
#endif
