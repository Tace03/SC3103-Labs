#include "show.h"

int count_second = 0;

void show_task(void *pvParameters)
{
   u32 lastWakeTime = getSysTickCnt();
   while(1)
    {	

			vTaskDelayUntil(&lastWakeTime, F2T(RATE_50_HZ));

			oled_show();    
    }
}  

void oled_show(void)
{  
     //To DO
	 
     // name task
	 uint8_t word[20] = "Ta Anh Trung";
     uint8_t timer[20] = "";
	 //call some function in oled to display something
     OLED_ShowString(10, 10, word);
     sprintf(timer, "%2d:%2d", count_second/60, count_second%60);
     OLED_ShowString(10, 20, timer);
    count_second++;
	 OLED_Refresh_Gram(); //refresh the OLED RAM
     vTaskDelay(1000);

	  		
}

