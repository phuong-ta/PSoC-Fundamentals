/* ========================================
 *
 * Copyright Phuong.Ta, Metropolia UAS, Finland, 2023
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CC-NA/SA 4.0
 *
 * ========================================
*/
#include "project.h"
#include <string.h>

int main(void)
{
;
    CyGlobalIntEnable; /* Enable global interrupts. */
    uint8 counter  = 0; // For ex2  and ex4
    char value[10]; // ex4 buffer, converted counter to string
    UART_Start();
    UART_PutString("phuong\r\n");
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    for(;;)
    {   
        /* Place your application code here. */
        /* EX2
        LED1_Write(counter ++ % 2); // counter add 1 each round. If counter %2 ==1 led on, else led off
        CyDelay(500); // delay to enable to see
        */
        
        /* Ex3
        if (Button_Read() ==0) // if button pressed => LED blink. ON => delay => OFF
        {
            LED1_Write(1);
            CyDelay(500);
            LED1_Write(0);
        }
        */
        // Ex4
        if (Button_Read() ==0)
        {
            LED1_Write(1);
            CyDelay(500);
            LED1_Write(0);
            counter+=1;

        }
        if(UART_GetChar())
        {
            sprintf(value, "%d\r\n", counter);
            UART_PutString(value);
        }
        
    }
}

/* [] END OF FILE */
