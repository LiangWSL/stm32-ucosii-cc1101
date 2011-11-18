/* Includes ------------------------------------------------------------------*/
#include "usart.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*����1����*/
void USART1_Configuration()
{  	
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	/*ʹ������ʱ��*/
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA, ENABLE);
	/*��GPIO_InitStruct�е�ÿһ��������ȱʡֵ����*/
	GPIO_StructInit(&GPIO_InitStructure);
	/*����PA9Ϊ�������*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA , &GPIO_InitStructure);
	/*����PA10Ϊ��������*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*��USART_InitStruct��ÿһ��������ȱʡֵд��*/
	USART_StructInit(&USART_InitStructure);
	/*���ô��ڲ�����Ϊ115200��һ֡8λ��һ��ֹͣλ��û����żλ�����͡�����ʹ�ܣ�Ӳ��������ʧ��*/
	USART_InitStructure.USART_BaudRate = 57600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_HardwareFlowControl =	USART_HardwareFlowControl_None;
	USART_Init(USART1 , &USART_InitStructure);
	/*ʹ��USART1����*/
	USART_Cmd(USART1 , ENABLE);
	/*ʹ��USART1�ж�*/
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_ITConfig(USART1, USART_IT_TXE, ENABLE);
}
/*******************************
���ƣ����ڷ��ͺ���
����1��USART1��USART2��USART3
����2���ַ�������\n��β
�������
����USART_SendString(USART1,"��ӭʹ��stm32ϵͳ�����Ǵ��ڲ��Գ���\n")
*******************************/
void USART_SendString(USART_TypeDef *  USARTx, char * format)
{
    while(*format)
	{
	   USART_SendData(USARTx,*format);//����һ���ֽ�
	   while(USART_GetFlagStatus(USARTx,USART_FLAG_TXE)==RESET);//����Ƿ��ͳɹ�  
	   format++;
	}
}
/*****************************************************************************/
//	USART1_Configuration();
//	USART_SendString(USART1,"��ӭʹ��stm32ϵͳ�����Ǵ��ڲ��Գ���\n");
//while (1)
//{
//	Delay(10000);
//	USART_SendData(USART1 , ADC1ConvertedValue>>8);
//	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
//	USART_SendData(USART1 , ADC1ConvertedValue);
//	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
//}
