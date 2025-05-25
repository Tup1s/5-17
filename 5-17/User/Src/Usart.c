#include "Usart.h"
#include "stdio.h"
#define RX_BUFFER_SIZE 128
extern  uint8_t rx_buffer[RX_BUFFER_SIZE];
extern  uint8_t rx_buffer_uart2[1];
extern  uint8_t rx_buffer_uart3[1];
void USART_Init()
{
	__HAL_UART_ENABLE_IT(&huart1,UART_IT_IDLE);
	HAL_UART_Receive_DMA(&huart1,rx_buffer,RX_BUFFER_SIZE);
	printf("\r\nHost:\r\n");
	HAL_UART_Receive_IT(&huart2, rx_buffer_uart2,1);
    HAL_UART_Receive_IT(&huart3, rx_buffer_uart3,1);
}


int fputc(int ch, FILE *f)
{ 	
	uint8_t usart_tmp=(uint8_t)(ch);
	HAL_UART_Transmit(&huart1,&usart_tmp,1,1000);
//	HAL_UART_Transmit_DMA(&huart1,&usart_tmp,sizeof(usart_tmp));	
  return ch;
}