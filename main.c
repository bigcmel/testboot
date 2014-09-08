#include "proto.h"

#define GPBCON (*(volatile WORD*)0x56000010) // GPH control register address
#define GPBDAT (*(volatile WORD*)0x56000014) // GPH control register address
#define GPBUP (*(volatile WORD*)0x56000018) // GPH control register address
#define GPHCON (*(volatile WORD*)0x56000070) // GPH control register address
#define GPHUP (*(volatile WORD*)0x56000079) // GPH control register address

void __main()
{

  /* 各种初始化 */

  //  WT_init();
  
  //  CLK_init();

  //  MC_init();

  int i;

  GPBCON = 0x015551;
  GPBUP = 0x7ff;
  GPBDAT = 0x1e0;
  GPHCON = 0x00faaa;
  GPHUP = 0x7ff;

  Uart_init(115200);

  for(i=0;i<100;i++)
    Uart_SendByte('A');
  

  GPIO_init();

  LCD_init();
  LCD_EnvidOnOff(1);
  LCD_ClearScr(0x343434);

  while(1){}

}

// gcc 的静态库要求链接到的函数，为空就好
void raise()
{}

