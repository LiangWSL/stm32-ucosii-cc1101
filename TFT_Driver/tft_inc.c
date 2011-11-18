/* Includes ------------------------------------------------------------------*/
#include "tft.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void TFT_GPIOConfig(void);
/* Private functions ---------------------------------------------------------*/

/**
  * @ժҪ  ��ʼ��TFT
  * @����  None 
  * @����ֵ  None
  */
void TFT_Configuration()
{
	/*����TFT�ܽ�*/
	TFT_GPIOConfig();
//	/*��ʼ��LCD*/
//	LCD_Initialization();
}
/**
  * @ժҪ  ����TFT�Ĺܽ�
  * @����  None 
  * @����ֵ  None
  */
void TFT_GPIOConfig()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	/*������Ӧʱ�� */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB|
							RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD|RCC_APB2Periph_GPIOE| RCC_APB2Periph_AFIO, ENABLE);  
	/*����Lcd��������Ϊ�������*/
	/*16λ����*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
	/*���ƽ�*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14|GPIO_Pin_15;
	GPIO_Init(GPIOD, &GPIO_InitStructure);
		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;	 //TP_CS
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}
