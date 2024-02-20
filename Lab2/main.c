#include "system.h"
#include <timers.h>

#define START_TASK_PRIO  4
#define START_STK_SIZE   256
TaskHandle_t StartTask_Handler;
TimerHandle_t xAutoTimer1;
void start_task(void *pvParameters);

int main(void){
    systemInit();
    
    xTaskCreate((TaskFunction_t ) start_task,
                (const char*    ) "start_task",
                (uint16_t       ) START_STK_SIZE,
                (void*          ) NULL,
                (UBaseType_t    ) START_TASK_PRIO,
                (TaskHandle_t*  ) &StartTask_Handler);
    xAutoTimer1 = xTimerCreate("timer1", F2T(RATE_1_HZ), pdTRUE, 0 , led_task);
    if(xTimerStart(xAutoTimer1,0) == pdPASS)
    vTaskStartScheduler();

}

void start_task(void *pvParameters)
{
    taskENTER_CRITICAL();
    //xTaskCreate(led_task, "led_task", LED_STK_SIZE, NULL, LED_TASK_PRIO, NULL);
    
    xTaskCreate(buzzer_task, "buz_task", BUZZER_STK_SIZE, NULL, BUZZER_TASK_PRIO, NULL);
    xTaskCreate(show_task, "show_task", SHOW_STK_SIZE , NULL, SHOW_TASK_PRIO, NULL);
    xTaskCreate(pbutton_task, "pbutton_task", SHOW_STK_SIZE , NULL, SHOW_TASK_PRIO, NULL);
    xTaskCreate(uart_task, "uart_task", UART_STK_SIZE, NULL, UART_TASK_PRIO, NULL);

    vTaskDelete(StartTask_Handler);
    taskEXIT_CRITICAL();
}