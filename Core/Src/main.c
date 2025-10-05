#include "main.h"
#include "st7789.h"
#include "delay.h"

int main(void)
{
    if (SYSCLK == 72000000UL)
        SystemClock_72_Config(); // включаем 72 МГц

    UART2_DMA_Init();
    printf("__________________\r\n");

    ST7789_Init();

    printf("START.\r\n");
    printf("SYSCLK = %d\r\n", (int)SYSCLK);

    while (1)
    {
        ST7789_Test();
        delay(500);
    }
}