#include "proto.h"

#define LOADER_BASE_ADDR 0x31000000 // loader.bin 加载到内存中的地址

void print_nand_id();

BYTE* __main()
{

  /* 各种初始化 */

  //  WT_init();
  
  //  CLK_init();

  //  MC_init();

  int i;
  BYTE* ptr;
  BYTE* str;

  ptr = (BYTE*)0x31100011;
  str = "HELLO";

  GPIO_init();

  Uart_init(115200);
  Uart_SendString("Boot!\n",6);

  while(1){}

  /*
  NF_init();

  print_nand_id();


  if( NF_WritePage(0, 1, str) == 0 )
    Uart_SendString("Write Fail!\n",12);

  if( NF_ReadPage(0, 1, ptr) )
    {
      Uart_SendString(ptr,100);
      Uart_SendString("\n",1);
    }
  else
    Uart_SendString("Read Fail!\n",11);

  Uart_SendString(ptr,2048);
  Uart_SendString("\n",1);
  */

  return (BYTE*)LOADER_BASE_ADDR;
}

// gcc 的静态库要求链接到的函数，为空就好
void raise()
{}

void print_nand_id()
{
  HWORD id;
  BYTE maker, device;

  /*
  device = (BYTE)id;
  maker = (BYTE)(id >> 8);
  Uart_SendByte(maker);
  Uart_SendByte(device);
  Uart_SendByte('\n');
  */

  id = NF_CheckId();
  device = (BYTE)id;
  maker = (BYTE)(id >> 8);

  Uart_SendByte(maker);
  Uart_SendByte(device);
  Uart_SendByte('\n');
}
