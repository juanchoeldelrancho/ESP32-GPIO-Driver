#include <stdio.h>
#include "GPIO_Equipo_R.h"

void app_main()
{
    GPIO_Enable_RGB();
    GPIO_Set_Output(LED1);
    GPIO_Set_Output(LED2);
    GPIO_Set_Output(LED3);
    GPIO_Set_Output(LED4);
    GPIO_Set_Output(LEDB);
    GPIO_Set_Input(SW1);
    GPIO_Set_Input(SW2);
    GPIO_Enable_APP_CPU_Interrup(SW1);
    GPIO_Falling_Edge_Interrup(SW1);

    while (1)
    {
        if (GPIO_Get_Pin_Value(SW1)!=1)
        {
            GPIO_Set_Level_High(LED1);
            GPIO_Set_Level_High(LED2);
            GPIO_Set_Level_High(LED3);
            GPIO_Set_Level_High(LED4);
        }
        else
        {
            GPIO_Set_Level_Low(LED1);
            GPIO_Set_Level_Low(LED2);
            GPIO_Set_Level_Low(LED3);
            GPIO_Set_Level_Low(LED4);
            
        }

        if (GPIO_Get_Pin_Value(SW2)!=1)
        {
            GPIO_Clear_Interrup(SW1);
            GPIO_Set_RGB_Level_High(LED_RGB_R);
            GPIO_Set_RGB_Level_High(LED_RGB_G);
            GPIO_Set_RGB_Level_High(LED_RGB_B);
        }
        else
        {
            GPIO_Set_RGB_Level_Low(LED_RGB_R);
            GPIO_Set_RGB_Level_Low(LED_RGB_G);
            GPIO_Set_RGB_Level_Low(LED_RGB_B);
        }

        if(GPIO_APP_CPU_Interrup_Status(SW1)!=1){
            GPIO_Set_Level_Low(LEDB);
        }

        if (GPIO_APP_CPU_Interrup_Status(SW1)!=0)
        {
            GPIO_Set_Level_High(LEDB);
        }
        
    }
}