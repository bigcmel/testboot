#include "proto.h"

int __main()
{

  /* 各种初始化 */

  //  WT_init();
  
  //  CLK_init();

  //  MC_init();


  GPIO_init();

  LCD_init();
  LCD_EnvidOnOff(1);
  LCD_ClearScr(0x343434);


  while(1){}

  return 0;
};
