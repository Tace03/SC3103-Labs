#ifndef __UART_H
#define __UART_H
#include "sys.h"
#include "system.h"

#define UART_TASK_PRIO		3     //Task priority 
#define UART_STK_SIZE 		128   //Task stack size 


/*--------UART control pin--------*/
#define UART_PORT GPIOC
#define UART_TX_PIN GPIO_Pin_11
#define UART_RX_PIN GPIO_Pin_10
#define UART_TX PCout(11) 
#define UART_RX PCin(10) 
/*----------------------------------*/

u8 Usart_Receive;

void uart3_Init(u32 bound);  
void uart_task();
void usart3_send(u8 data);
int USART3_IRQHandler();
#endif