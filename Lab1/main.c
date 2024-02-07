#include "system.h"

#define START_TASK_PRIO  4
#define START_STK_SIZE   256
TaskHandle_t StartTask_Handler;
void start_task(void *pvParameters);

int main(void){
    systemInit();
    
    xTaskCreate((TaskFunction_t ) start_task,
                (const char*    ) "start_task",
                (uint16_t       ) START_STK_SIZE,
                (void*          ) NULL,
                (UBaseType_t    ) START_TASK_PRIO,
                (TaskHandle_t*  ) &StartTask_Handler);
    
    vTaskStartScheduler();

}

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();
    xTaskCreate(led_task, "led_task", LED_STK_SIZE, NULL, LED_TASK_PRIO, NULL);
    xTaskCreate(buzzer_task, "buz_task", BUZZER_STK_SIZE, NULL, BUZZER_TASK_PRIO, NULL);
    xTaskCreate(show_task, "show_task", SHOW_STK_SIZE , NULL, SHOW_TASK_PRIO, NULL);

    vTaskDelete(StartTask_Handler);
    taskEXIT_CRITICAL();
}

/* Lab 2 Note

# this is play_button.h

#ifndef __PLAY_BUTTON_H
#define __PLAY_BUTTON_H
#include "sys.h"
#include "system.h"

#define PLAY_BUTTON_TASK_PRIO		3     //Task priority 
#define PLAY_BUTTON_STK_SIZE 		128   //Task stack size 

*/


/*--------Play Button control pin--------*/
/*
#define PLAY_BUTTON_PORT GPIOD
#define PLAY_BUTTON_PIN GPIO_Pin_8
#define PLAY_BUTTON PDin(8) 
*/
/*----------------------------------*/
/*
void Play_Button_Init(void);  
void pbutton_task(void *pvParameters);
extern int pbutton_Count;
#endif
*/



/*

# play_button.c

#include "play_button.h"
#include "show.h"

int pbutton_Count=5000;

//LED initialization
void Play_Button_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);    //Enable APB Clock
	
  GPIO_InitStructure.GPIO_Pin =  PLAY_BUTTON_PIN;                  //LED Pin
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;            //Push pull output
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;        //100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(PLAY_BUTTON_PORT, &GPIO_InitStructure);                    //Initialize LED GPIO
	GPIO_SetBits(PLAY_BUTTON_PORT,PLAY_BUTTON_PIN);
}

void pbutton_task(void *pvParameters)
{		
	
    while(1)
    {
    }
}  
*/

/*
if(PLAY_BUTTON)
		BUZ=~BUZ;
  currently when pressed the button will actually be 0
  not pressed = 1
*/




