#include "proto.h"

#define LOADER_BASE_ADDR 0x33000000 // loader.bin 加载到内存中的地址

BYTE* __main()
{

  /* 各种初始化 */

  //  WT_init();
  
  //  CLK_init();

  //  MC_init();

  int i;
  char* ptr = 0x33100000;

  GPIO_init();

  Uart_init(115200);
  Uart_SendString("Boot!\n",6);

  LCD_init();
  LCD_EnvidOnOff(1);
  LCD_ClearScr(0x343434);

  //  while(1){}

  NF_init();

  Uart_SendString( (char*)NF_CheckId(), 4);
  Uart_SendString( "\n" , 1);

  if( NF_ReadPage(0, 0, ptr) )
    {
      Uart_SendString(ptr,100);
      Uart_SendString("\n",1);
    }
  else
    Uart_SendString("Read Fail!\n",11);


  return (BYTE*)LOADER_BASE_ADDR;
}

// gcc 的静态库要求链接到的函数，为空就好
void raise()
{}

