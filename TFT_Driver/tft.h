#ifndef __TFT_H
#define __TFT_H
/* Define to prevent recursive inclusion -------------------------------------*/
//#define RED	  0XF800
//#define GREEN 0X07E0
//#define BLUE  0X001F  
//#define BRED  0XF81F
//#define GRED  0XFFE0
//#define GBLUE 0X07FF;
//#define BLACK 0;  
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "delay.h"

/*Ӳ����صĺ궨��*/
#define Set_Cs  GPIOD->BSRR  = 0x00001000;
#define Clr_Cs  GPIOD->BRR   = 0x00001000;

#define Set_Rs  GPIOD->BSRR  = 0x00002000;
#define Clr_Rs  GPIOD->BRR   = 0x00002000;

#define Set_nWr GPIOD->BSRR  = 0x00004000;
#define Clr_nWr GPIOD->BRR   = 0x00004000;

#define Set_nRd GPIOD->BSRR  = 0x00008000;
#define Clr_nRd GPIOD->BRR   = 0x00008000;

/*TFT��ɫ�궨��*/
#define TFT_BLACK	0X0000	//����
#define TFT_NAVY	0X0010	//���� 
#define TFT_GREEN	0X0400	//����
#define TFT_TEAL	0X0410	//����
#define TFT_MAROON	0X8000	//���
#define TFT_PURPLE	0X8010	//����
#define TFT_OLIVE	0X8400	//�ֻ�
#define TFT_GRAY	0X8410	//���
#define TFT_SILVER	0XC618	//ǳ��
#define TFT_BLUE	0X001F	//ǳ��
#define TFT_LIME	0X07E0	//ǳ��
#define TFT_AQUA	0X07FF	//����
#define TFT_RED		0XF800	//���
#define TFT_FUCHSIA	0XF81F	//Ʒ��
#define TFT_YELLOW	0XFFE0	//����
#define TFT_WHITE	0XFFFF	//����
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
__inline void WriteRegister(u16 index,u16 dat);

void TFT_Configuration(void);
void LCD_Initialization(void);

void TFT_Touch_Init(void);
unsigned char SPI_WriteByte(unsigned char data);
void SpiDelay(unsigned int DelayCnt);
u16 TPReadX(void);
u16 TPReadY(void);

/****************************************************************************
* ��    �ƣ�void TFT_DrawPoint(int x, int y, int PixelIndex)
* ��    �ܣ����㺯��
* ��ڲ�����x��y	����
*         ��PixelIndex 16λ��ɫֵ
* ���ڲ�������
****************************************************************************/
void TFT_DrawPoint(int x, int y, int PixelIndex);

/****************************************************************************
* ��    �ƣ�void TFT_DrawHLine(int x0, int y,  int x1, int color)
* ��    �ܣ���ˮƽ��
* ��ڲ�����x0��x1	ˮƽ�����յ�����
*         ��y  		��ֱ����
*           color  ����ɫ
* ���ڲ�������
****************************************************************************/
void TFT_DrawHLine(int x0, int y,  int x1, int color);

/****************************************************************************
* ��    �ƣ�void TFT_DrawVLine(int x, int y0,  int y1, int color)
* ��    �ܣ�����ֱ��
* ��ڲ�����y0��y1	��ֱ�����յ�����
*         ��x  		ˮƽ����
*           color  ����ɫ
* ���ڲ�������
****************************************************************************/
void TFT_DrawVLine(int x, int y0,  int y1, int color);

/****************************************************************************
* ��    �ƣ�void TFT_DrawLine(u16 x0, u16 y0, u16 x1, u16 y1,u16 color)
* ��    �ܣ���ָ�����껭ֱ��
* ��ڲ�����x0     A��������
*           y0     A��������
*           x1     B��������
*           y1     B��������
*           color  ����ɫ
* ���ڲ�������
* ���÷�����TFT_DrawLine(0,0,240,320,0x0000);
****************************************************************************/
void TFT_DrawLine(u16 x0, u16 y0, u16 x1, u16 y1,u16 color);

/****************************************************************************
* ��    �ƣ�void TFT_FillRect(int x0, int y0, int x1, int y1)
* ��    �ܣ�������
* ��ڲ�����x0��y0	�������
*         ��x1��y1  �յ�����
*           color  ����ɫ
* ���ڲ�������
****************************************************************************/
void TFT_FillRect(int x0, int y0, int x1, int y1, int color);

/****************************************************************************
* ��    �ƣ�void TFT_DispCharAt(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor)
* ��    �ܣ���ָ��������ʾһ��8x16�����ascii�ַ�
* ��ڲ�����x          ������
*           y          ������
*           charColor  �ַ�����ɫ
*           bkColor    �ַ�������ɫ
* ���ڲ�������
* ˵    ������ʾ��Χ�޶�Ϊ����ʾ��ascii��
* ���÷�����TFT_DispCharAt(10,10,'a',TFT_BLACK,TFT_WHITE);
****************************************************************************/
void TFT_DispCharAt(u16 x,u16 y,u8 c,u16 charColor,u16 bkColor);

/****************************************************************************
* ��    �ƣ�void TFT_DispString(u16 x, u16 y, u8 *str, u16 len,u16 Color, u16 bkColor)
* ��    �ܣ���ָ��������ʾ�ַ���
* ��ڲ�����x      ������
*           y      ������
*           *str   �ַ���
*           len    �ַ�������
*           Color  �ַ���ɫ
*           bkColor�ַ�������ɫ
* ���ڲ�������
* ���÷�����TFT_DispString(0,0,"0123456789",10,TFT_BLACK,TFT_WHITE);
****************************************************************************/
void TFT_DispString(u16 x, u16 y, u8 *str, u16 len,u16 Color, u16 bkColor);

/****************************************************************************
* ��    �ƣ�TFT_ShowNum(u16 x,u16 y,u32 num,u16 Color, u16 bkColor)
* ��    �ܣ���ָ��������ʾ����
* ��ڲ�����x      ������
*           y      ������
*			num	   ����
*           Color  �ַ���ɫ
*           bkColor�ַ�������ɫ
* ���ڲ�������
* ���÷�����TFT_ShowNum(0,0,16,TFT_BLACK,TFT_WHITE);
****************************************************************************/
void TFT_ShowNum(u16 x,u16 y,u32 num,u16 Color, u16 bkColor);

/****************************************************************************
* ��    �ƣ�TFT_RightShowNum(u16 x,u16 y,u32 num,u16 Color, u16 bkColor)
* ��    �ܣ���ָ��������ʾ���� (�Ҷ���)
* ��ڲ�����x      ������
*           y      ������
*			num	   ����
*           Color  �ַ���ɫ
*           bkColor�ַ�������ɫ
* ���ڲ�������
* ���÷�����TFT_RightShowNum(320,0,16,TFT_BLACK,TFT_WHITE);
****************************************************************************/
void TFT_RightShowNum(u16 x,u16 y,u32 num,u16 Color, u16 bkColor);

/****************************************************************************
* ��    �ƣ�u16 TFT_Color565(u32 RGB)
* ��    �ܣ���RGB��ɫת��Ϊ16λ��ɫ��
* ��ڲ�����RGB  ��ɫֵ
* ���ڲ���������16λRGB��ɫֵ��
* ���÷�����i=TFT_Color565(0xafafaf);
****************************************************************************/
u16 TFT_Color565(u32 RGB);

/****************************************************************************
* ��    �ƣ�void TFT_Test(void)
* ��    �ܣ����ԡ�
****************************************************************************/
void TFT_Test(void);


#endif /* __TFT_H */
