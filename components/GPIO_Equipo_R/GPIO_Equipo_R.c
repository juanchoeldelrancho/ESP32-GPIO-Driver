#include "GPIO_Equipo_R.h"


/*****************************************************************************
 * Function: GPIO_Set_Otput
 * Preconditions: None.
 * Overview: Habilita el pin seleccionado como salida.
 * Input: __UINT32_TYPE__ PIN
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Set_Output(__UINT32_TYPE__ PIN){

    SET_PIN_FUNCTION(PIN,Function2);

    if (PIN<=31)
    { GPIO_ENABLE_W1TS_REG |= (BIT(PIN)); }
    else
    { /*LEFT BLANK ON PURPUSE*/ }

    IO_MUX_REG(PIN) &= ~FUN_PD;
    IO_MUX_REG(PIN) &= ~FUN_PU;
    IO_MUX_REG(PIN) &= ~FUN_IE;
}

/*****************************************************************************
 * Function: GPIO_Set_Input
 * Preconditions: None.
 * Overview: Habilita el pin seleccionado como entrada.
 * Input: __UINT32_TYPE__ PIN
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Set_Input(__UINT32_TYPE__ PIN){

    SET_PIN_FUNCTION(PIN,Function2);

    if (PIN<=31)
    { GPIO_ENABLE_W1TC_REG |= (BIT(PIN)); }
    else
    { GPIO_ENABLE1_W1TC_REG |= (BIT(PIN-31)); }

    IO_MUX_REG(PIN) &= ~FUN_PD;
    IO_MUX_REG(PIN) |= FUN_PU;
    IO_MUX_REG(PIN) |= FUN_IE;
}

/*****************************************************************************
 * Function: GPIO_Set_Input_Pull_Up
 * Preconditions: None.
 * Overview: Habilita la resisitencia de Pull-up en el pin seleccionado.
 * Input: __UINT32_TYPE__ PIN
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Set_Input_Pull_Up(__UINT32_TYPE__ PIN){
    SET_PIN_FUNCTION(PIN,Function2);
    if (PIN<=31)
    { GPIO_ENABLE_W1TC_REG |= (BIT(PIN)); }
    else
    { GPIO_ENABLE1_W1TC_REG |= (BIT(PIN-31)); }
    IO_MUX_REG(PIN) &= ~FUN_PD;
    IO_MUX_REG(PIN) |= FUN_PU;
    IO_MUX_REG(PIN) |= FUN_IE;
}

/*****************************************************************************
 * Function: GPIO_Set_Input_Pull_Down
 * Preconditions: None.
 * Overview: Habilita la resisitencia de Pull-down en el pin seleccionado.
 * Input: __UINT32_TYPE__ PIN
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Set_Input_Pull_Down(__UINT32_TYPE__ PIN){

    SET_PIN_FUNCTION(PIN,Function2);

    if (PIN<=31)
    { GPIO_ENABLE_W1TC_REG |= (BIT(PIN)); }
    else
    { GPIO_ENABLE1_W1TC_REG |= (BIT(PIN-31)); }

    IO_MUX_REG(PIN) &= ~FUN_PU;
    IO_MUX_REG(PIN) |= FUN_PD;
    IO_MUX_REG(PIN) |= FUN_IE;
}

/*****************************************************************************
 * Function: GPIO_Set_Level_Low
 * Preconditions: GPIO_Set_Otput().
 * Overview: Configura el nivel de salida en bajo (0).
 * Input: __UINT32_TYPE__ PIN
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Set_Level_Low(__UINT32_TYPE__ PIN){

    GPIO_OUT_W1TC_REG |= (BIT(PIN));

}

/*****************************************************************************
 * Function: GPIO_Set_Level_High
 * Preconditions: GPIO_Set_Otput().
 * Overview: Configura el nivel de salida en alto (1).
 * Input: __UINT32_TYPE__ PIN
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Set_Level_High(__UINT32_TYPE__ PIN){

    GPIO_OUT_W1TS_REG |= (BIT(PIN));

}

/*****************************************************************************
 * Function: GPIO_Get_Pin_Value
 * Preconditions: GPIO_Set_Input().
 * Overview:  Retorna el valor de entrada en pin seleccionado.
 * Input: __UINT32_TYPE__ PIN.
 * Output: __UINT8_TYPE__.
 *
 *****************************************************************************/

__UINT8_TYPE__ GPIO_Get_Pin_Value(__UINT32_TYPE__ PIN){
    __UINT_FAST32_TYPE__ pinValue;
    if (PIN<=31){ pinValue = GPIO_IN_REG & (BIT(PIN));}
    else { pinValue = GPIO_IN1_REG & (BIT(PIN-31)); }
    if (pinValue>0){ return (0x01); }
    else{ return(0x00); }
}

/*****************************************************************************
 * Function: GPIO_Enable_RGB
 * Preconditions: None.
 * Overview:  Configura los pines encargdos del control del LED RGB.
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Enable_RGB(void){

    SET_PIN_FUNCTION(LED_RGB_R,Function2);
    SET_PIN_FUNCTION(LED_RGB_G,Function2);
    SET_PIN_FUNCTION(LED_RGB_B,Function2);

    GPIO_ENABLE_W1TS_REG |= (BIT(LED_RGB_R));
    GPIO_ENABLE_W1TS_REG |= (BIT(LED_RGB_G));
    GPIO_ENABLE_W1TS_REG |= (BIT(LED_RGB_B));

    IO_MUX_REG(LED_RGB_R) &= ~FUN_IE;
    IO_MUX_REG(LED_RGB_G) &= ~FUN_IE;
    IO_MUX_REG(LED_RGB_B) &= ~FUN_IE;

    IO_MUX_REG(LED_RGB_R) &= ~FUN_PU;
    IO_MUX_REG(LED_RGB_R) &= ~FUN_PD;

    IO_MUX_REG(LED_RGB_G) &= ~FUN_PU;
	IO_MUX_REG(LED_RGB_G) &= ~FUN_PD;

	IO_MUX_REG(LED_RGB_B) &= ~FUN_PU;
	IO_MUX_REG(LED_RGB_B) &= ~FUN_PD;
}

/*****************************************************************************
 * Function: GPIO_Set_RGB_Level_High
 * Preconditions: GPIO_Enable_RGB().
 * Overview:  Enciende el segmento selecionado del RGB del LED.
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Set_RGB_Level_High(__UINT32_TYPE__ PIN){

    GPIO_OUT_W1TC_REG |= (BIT(PIN));

}

/*****************************************************************************
 * Function: GPIO_Set_RGB_Level_High
 * Preconditions: GPIO_Enable_RGB().
 * Overview:  Enciende el segmento selecionado del RGB del LED.
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Set_RGB_Level_Low(__UINT32_TYPE__ PIN){

    GPIO_OUT_W1TS_REG |= (BIT(PIN));

}

/*****************************************************************************
 * Function: GPIO_Enable_APP_CPU_Interrup
 * Preconditions: None.
 * Overview:  Habilita la interrupción de aplicación en el pin seleccionado
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Enable_APP_CPU_Interrup(__UINT32_TYPE__ PIN){
    GPIO_PIN_REG(PIN) &= ~(BIT(13) | BIT(14) | BIT(15) | BIT(16) | BIT(17));
    GPIO_PIN_REG(PIN) |= BIT(13);
}

/*****************************************************************************
 * Function: GPIO_Enable_APP_CPU_NMI_Interrup
 * Preconditions: None.
 * Overview:  Habilita la interrupción de aplicación en el pin seleccionado tipo NON-MASKABLE
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Enable_APP_CPU_NMI_Interrup(__UINT32_TYPE__ PIN){
    GPIO_PIN_REG(PIN) &= ~(BIT(13) | BIT(14) | BIT(15) | BIT(16) | BIT(17));
    GPIO_PIN_REG(PIN) |= BIT(14);
}

/*****************************************************************************
 * Function: GPIO_Enable_PRO_CPU_Interrup
 * Preconditions: None.
 * Overview:  Habilita la interrupción de tipo PRO CPU del pinseleccionado
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Enable_PRO_CPU_Interrup(__UINT32_TYPE__ PIN){
    GPIO_PIN_REG(PIN) &= ~(BIT(13) | BIT(14) | BIT(15) | BIT(16) | BIT(17));
    GPIO_PIN_REG(PIN) |= BIT(15);
}

/*****************************************************************************
 * Function: GPIO_Enable_PRO_CPU_NMI_Interrup
 * Preconditions: None.
 * Overview:  Habilita la interrupción de tipo PRO CPU del pinseleccionado tipo NON-MASKABLE
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Enable_PRO_CPU_NMI_Interrup(__UINT32_TYPE__ PIN){
    GPIO_PIN_REG(PIN) &= ~(BIT(13) | BIT(14) | BIT(15) | BIT(16) | BIT(17));
    GPIO_PIN_REG(PIN) |= BIT(16);
}

/*****************************************************************************
 * Function: GPIO_Disable_Interrup
 * Preconditions: None.
 * Overview:  Deshabilita todas las inetrrupciones del pin
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Disable_Interrup(__UINT32_TYPE__ PIN){
    GPIO_PIN_REG(PIN) &= ~(BIT(13) | BIT(14) | BIT(15) | BIT(16) | BIT(17));
}

/*****************************************************************************
 * Function: GPIO_Rising_Edge_interrup
 * Preconditions: None.
 * Overview:  Configuracion para que la interrupcion ocurra en un cambio de negativo a positivo
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Rising_Edge_Interrup(__UINT32_TYPE__ PIN){
    GPIO_PIN_REG(PIN) &= ~(BIT(9) | BIT(7)  | BIT(8));
    GPIO_PIN_REG(PIN) |= BIT(7);
}

/*****************************************************************************
 * Function: GPIO_Falling_Edge_interrup
 * Preconditions: None.
 * Overview:  Configuracion para que la interrupcion ocurra en un cambio de positivo a negativo
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Falling_Edge_Interrup(__UINT32_TYPE__ PIN){
    GPIO_PIN_REG(PIN) &= ~(BIT(9) | BIT(7)  | BIT(8));
    GPIO_PIN_REG(PIN) |= BIT(8);
}

/*****************************************************************************
 * Function: GPIO_Any_Edge_interrup
 * Preconditions: None.
 * Overview:  Configuracion para que la interrupcion ocurra con cualquier cambio
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Any_Edge_Interrup(__UINT32_TYPE__ PIN){
    GPIO_PIN_REG(PIN) &= ~(BIT(9) | BIT(7)  | BIT(8));
    GPIO_PIN_REG(PIN) |= BIT(7) | BIT(8);
}

/*****************************************************************************
 * Function: GPIO_Clear_Interrup
 * Preconditions: None.
 * Overview:  Limpia la bandera de interrupcion del pin seleccionado.
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Clear_Interrup(__UINT32_TYPE__ PIN){
    if (PIN<=32){ GPIO_STATUS_W1TC_REG |= (BIT(PIN));}
    else { GPIO_STATUS1_W1TC_REG |= (BIT(PIN-32)); }
}

/*****************************************************************************
 * Function: GPIO_Clear_All_Interrup
 * Preconditions: None.
 * Overview:  Limpia todas las banderas de interrupcion.
 * Input: __UINT32_TYPE__ PIN.
 * Output: None.
 *
 *****************************************************************************/

void GPIO_Clear_All_Interrup(void){
    GPIO_STATUS_W1TC_REG    |= 0xFFFFFFFF;
    GPIO_STATUS1_W1TC_REG   |= 0xFF;
}

/*****************************************************************************
 * Function: GPIO_APP_CPU_Interrup_Status
 * Preconditions: GPIO_Enable_APP_CPU_Interrup().
 * Overview:  Recupera el valor de la bandera de interrupcion APP CPU
 * Input: __UINT32_TYPE__ PIN.
 * Output: __UINT8_TYPE__.
 *
 *****************************************************************************/

__UINT8_TYPE__ GPIO_APP_CPU_Interrup_Status(__UINT32_TYPE__ PIN){
    __UINT_FAST32_TYPE__ pinValue;
    if (PIN<=31){ pinValue = GPIO_ACPU_INT_REG & (BIT(PIN));}
    else { pinValue = GPIO_ACPU_INT1_REG & (BIT(PIN-31)); }
    if (pinValue>0){ return (0x01); }
    else{ return(0x00); }
}

/*****************************************************************************
 * Function: GPIO_APP_CPU_NMI_Interrup_Status
 * Preconditions: GPIO_Enable_APP_CPU_NMI_Interrup().
 * Overview:  Recupera el valor de la bandera de interrupcion APP CPU NON-MASKABLE
 * Input: __UINT32_TYPE__ PIN.
 * Output: __UINT8_TYPE__.
 *
 *****************************************************************************/

__UINT8_TYPE__ GPIO_APP_CPU_NMI_Interrup_Status(__UINT32_TYPE__ PIN){
    __UINT_FAST32_TYPE__ pinValue;
    if (PIN<=31){ pinValue = GPIO_ACPU_NMI_INT_REG & (BIT(PIN)); }
    else{ pinValue = GPIO_ACPU_NMI_INT1_REG & (BIT(PIN-31)); }
    if (pinValue>0){ return (0x01); }
    else{ return(0x00); }
}

/*****************************************************************************
 * Function: GPIO_PRO_CPU_Interrup_Status
 * Preconditions: GPIO_Enable_PRO_CPU_Interrup().
 * Overview:  Recupera el valor de la bandera de interrupcion PRO CPU
 * Input: __UINT32_TYPE__ PIN.
 * Output: __UINT8_TYPE__.
 *
 *****************************************************************************/

__UINT8_TYPE__ GPIO_PRO_CPU_Interrup_Status(__UINT32_TYPE__ PIN){
    __UINT_FAST32_TYPE__ pinValue;
    if (PIN<=31){ pinValue = GPIO_PCPU_INT_REG & (BIT(PIN)); }
    else{ pinValue = GPIO_PCPU_INT1_REG & (BIT(PIN-31)); }
    if (pinValue>0){ return (0x01); }
    else{ return(0x00); }
}

/*****************************************************************************
 * Function: GPIO_PRO_CPU_NMI_Interrup_Status
 * Preconditions: GPIO_Enable_PRO_CPU_NMI_Interrup().
 * Overview:  Recupera el valor de la bandera de interrupcion PRO CPU NON-MASKABLE
 * Input: __UINT32_TYPE__ PIN.
 * Output: __UINT8_TYPE__.
 *
 *****************************************************************************/

__UINT8_TYPE__ GPIO_PRO_CPU_NMI_Interrup_Status(__UINT32_TYPE__ PIN){
    __UINT_FAST32_TYPE__ pinValue;
    if (PIN<=31){ pinValue = GPIO_PCPU_NMI_INT_REG & (BIT(PIN)); }
    else{ pinValue = GPIO_PCPU_NMI_INT1_REG & (BIT(PIN-31)); }
    if (pinValue>0){ return (0x01); }
    else{ return(0x00); }
}

