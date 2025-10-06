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

    PINB_2_INIT();

    while (1)
    {
        ST7789_Fill_Color(BLACK);
        delay(3000);

        GPIOB->BSRR = GPIO_BSRR_BS2;
        ST7789_Fill_Color(RED);
        delay(500);
        GPIOB->BSRR = GPIO_BSRR_BR2;
        delay(3000);

        GPIOB->BSRR = GPIO_BSRR_BS2;
        ST7789_WriteString(10, 10, "Rect./Line.", Font_11x18, YELLOW, BLACK);
        delay(500);
        GPIOB->BSRR = GPIO_BSRR_BR2;
        delay(3000);

        GPIOB->BSRR = GPIO_BSRR_BS2;
        ST7789_DrawRectangle(30, 30, 100, 100, WHITE);
        delay(500);
        GPIOB->BSRR = GPIO_BSRR_BR2;
        delay(3000);
        //--------------------------------
        GPIOB->BSRR = GPIO_BSRR_BS2;
        ST7789_DrawRectangle(0, 0, 50, 50, GREEN);
        delay(500);
        GPIOB->BSRR = GPIO_BSRR_BR2;
        delay(3000);

        GPIOB->BSRR = GPIO_BSRR_BS2;
        ST7789_DrawRectangle(0, 230, 50, 279, GREEN);
        delay(500);
        GPIOB->BSRR = GPIO_BSRR_BR2;
        delay(3000);

        GPIOB->BSRR = GPIO_BSRR_BS2;
        ST7789_DrawRectangle(190, 0, 239, 50, GREEN);
        delay(500);
        GPIOB->BSRR = GPIO_BSRR_BR2;
        delay(3000);

        GPIOB->BSRR = GPIO_BSRR_BS2;
        ST7789_DrawRectangle(190, 230, 239, 279, GREEN);
        delay(500);
        GPIOB->BSRR = GPIO_BSRR_BR2;
        delay(3000);
        //----------------------------------
        printf("ST7789_DrawRectangle(30, 30, 100, 100, WHITE);\r\n");
        delay(10000);

        ST7789_Test();
        delay(500);
    }
}