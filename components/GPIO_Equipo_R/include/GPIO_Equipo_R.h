#ifndef GPIO_EQP_R_ 
#define GPIO_EQP_R_

#define BIT(dpmt)                 (1 << (dpmt))
#define GPIO_BASE_ADDRESS   ((__UINT32_TYPE__)0x3FF44000)
#define IO_MUX_BASE_ADDRESS ((__UINT32_TYPE__)0x3FF49000)
#define HWREG32(x)          (*((volatile __UINT32_TYPE__*)(x)))
/*\\\\\\\\\\\\\\\\\MACROFUNCIONES PARA ACCESO A REGISTROS\\\\\\\\\\*/

#define GPIO_OUT_REG            (HWREG32(GPIO_BASE_ADDRESS+0x0004))
#define GPIO_OUT_W1TS_REG       (HWREG32(GPIO_BASE_ADDRESS+0x0008))
#define GPIO_OUT_W1TC_REG       (HWREG32(GPIO_BASE_ADDRESS+0x000c))
#define GPIO_OUT1_REG           (HWREG32(GPIO_BASE_ADDRESS+0x0010))
#define GPIO_OUT1_W1TS_REG      (HWREG32(GPIO_BASE_ADDRESS+0x0014))
#define GPIO_OUT1_W1TC_REG      (HWREG32(GPIO_BASE_ADDRESS+0x0018))
#define GPIO_ENABLE_REG         (HWREG32(GPIO_BASE_ADDRESS+0x0020))
#define GPIO_ENABLE_W1TS_REG    (HWREG32(GPIO_BASE_ADDRESS+0x0024))
#define GPIO_ENABLE_W1TC_REG    (HWREG32(GPIO_BASE_ADDRESS+0x0028))
#define GPIO_ENABLE1_REG        (HWREG32(GPIO_BASE_ADDRESS+0x002c))
#define GPIO_ENABLE1_W1TS_REG   (HWREG32(GPIO_BASE_ADDRESS+0x0030))
#define GPIO_ENABLE1_W1TC_REG   (HWREG32(GPIO_BASE_ADDRESS+0x0034))
#define GPIO_IN_REG             (HWREG32(GPIO_BASE_ADDRESS+0x003c))
#define GPIO_IN1_REG            (HWREG32(GPIO_BASE_ADDRESS+0x0040))
#define GPIO_STATUS_REG         (HWREG32(GPIO_BASE_ADDRESS+0x0044))
#define GPIO_STATUS_W1TC_REG    (HWREG32(GPIO_BASE_ADDRESS+0x004c))
#define GPIO_STATUS1_REG        (HWREG32(GPIO_BASE_ADDRESS+0x0050))
#define GPIO_STATUS1_W1TC_REG   (HWREG32(GPIO_BASE_ADDRESS+0x0058))
#define GPIO_ACPU_INT_REG       (HWREG32(GPIO_BASE_ADDRESS+0x0060))
#define GPIO_ACPU_NMI_INT_REG   (HWREG32(GPIO_BASE_ADDRESS+0x0064))
#define GPIO_PCPU_INT_REG       (HWREG32(GPIO_BASE_ADDRESS+0x0068))
#define GPIO_PCPU_NMI_INT_REG   (HWREG32(GPIO_BASE_ADDRESS+0x006c))
#define GPIO_ACPU_INT1_REG      (HWREG32(GPIO_BASE_ADDRESS+0x0074))
#define GPIO_ACPU_NMI_INT1_REG  (HWREG32(GPIO_BASE_ADDRESS+0x0078))
#define GPIO_PCPU_INT1_REG      (HWREG32(GPIO_BASE_ADDRESS+0x007c))
#define GPIO_PCPU_NMI_INT1_REG  (HWREG32(GPIO_BASE_ADDRESS+0x0080))
#define GPIO_PIN_REG(_pin)      (HWREG32(GPIO_BASE_ADDRESS+0x0088+0x4*_pin))


#define IO_MUX_REG(_pin)        (HWREG32(IO_MUX_BASE_ADDRESS+IO_MUX_REG_OFFSET[_pin]))

#define SET_PIN_FUNCTION(_pin,_function)    (IO_MUX_REG(_pin) &= ~(0xF << 12), IO_MUX_REG(_pin) |= (_function<<12))
#define SET_PAD_STRENGHT(_pin,_strenght)    (IO_MUX_REG(_pin) &= ~(0x3 << 10), IO_MUX_REG(_pin) |= (_strenght<<10))

/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
/* Pulldown enable */
#define FUN_PD (BIT(7))
/* Pullup enable */
#define FUN_PU (BIT(8))
/* Input enable */
#define FUN_IE (BIT(9))


#define IRAM_ATTR _SECTION_ATTR_IMPL(".iram1", __COUNTER__)


// Definicion para cada uno de los puertos GPIO
enum IO{
    IO0,    IO1,    IO2,    IO3,    IO4,    IO5,    IO6,    IO7,
    IO8,    IO9,    IO10,   IO11,   IO12,   IO13,   IO14,   IO15,
    IO16,   IO17,   IO18,   IO19,   IO20,   IO21,   IO22,   IO23,
    IO24,   IO25,   IO26,   IO27,   IO28,   IO29,   IO30,   IO31,
    IO32,   IO33,   IO34,   IO35,   IO36,   IO37,   IO38,   IO39
};

//Redefifnicion de los puertos para uso de hardware
#define LED_RGB_R   IO14
#define LED_RGB_G   IO13
#define LED_RGB_B   IO12

#define LED1    IO17
#define LED2    IO16
#define LED3    IO4
#define LED4    IO2
#define LEDB    IO5

#define SW1 	IO18
#define SW2 	IO19

// Definicion para las funciones de los pines
enum Functions{
    Function0, Function1,
    Function2, Function3,
    Function4, Function5
};

// Definicion para el offset de cada pin en el registro IO_MUX
static const __UINT8_TYPE__ IO_MUX_REG_OFFSET[] = {
    0x44,
    0x88,
    0x40,
    0x84,
    0x48,
    0x6c,
    0x60,
    0x64,
    0x68,
    0x54,
    0x58,
    0x5c,
    0x34,
    0x38,
    0x30,
    0x3c,
    0x4c,
    0x50,
    0x70,
    0x74,
    0x78,
    0x7c,
    0x80,
    0x8c,
    0xFF, // 24
    0x24,
    0x28,
    0x2c,
    0xFF, // 28
    0xFF, // 29
    0xFF, // 30
    0xFF, // 31
    0x1c,
    0x20,
    0x14,
    0x18,
    0x04,
    0x08,
    0x0c,
    0x10,
};

extern void GPIO_Set_Output(__UINT32_TYPE__ PIN);

extern void GPIO_Set_Input(__UINT32_TYPE__ PIN);

extern void GPIO_Set_Level_Low(__UINT32_TYPE__ PIN);

extern void GPIO_Set_Level_High(__UINT32_TYPE__ PIN);

extern void GPIO_Enable_RGB(void);

extern void GPIO_Set_RGB_Level_Low(__UINT32_TYPE__ PIN);

extern void GPIO_Set_RGB_Level_High(__UINT32_TYPE__ PIN);

extern void GPIO_Clear_Interrup(__UINT32_TYPE__ PIN);

extern void GPIO_Clear_All_Interrup(void);

extern void GPIO_Enable_APP_CPU_Interrup(__UINT32_TYPE__ PIN);

extern void GPIO_Enable_APP_CPU__NMI_Interrup(__UINT32_TYPE__ PIN);

extern void GPIO_Enable_PRO_CPU_Interrup(__UINT32_TYPE__ PIN);

extern void GPIO_Enable_PRO_CPU_NMI_Interrup(__UINT32_TYPE__ PIN);

extern void GPIO_Enable_PRO_APP_CPU_Interrup(__UINT32_TYPE__ PIN);

extern void GPIO_Enable_PRO_APP_CPU_NMI_Interrup(__UINT32_TYPE__ PIN);

extern void GPIO_Rising_Edge_Interrup(__UINT32_TYPE__ PIN);

extern void GPIO_Falling_Edge_Interrup(__UINT32_TYPE__ PIN);

extern void GPIO_Any_Edge_Interrup(__UINT32_TYPE__ PIN);

extern __UINT8_TYPE__ GPIO_Get_Pin_Value(__UINT32_TYPE__ PIN);

extern __UINT8_TYPE__ GPIO_APP_CPU_Interrup_Status(__UINT32_TYPE__ PIN);

extern __UINT8_TYPE__ GPIO_APP_CPU_NMI_Interrup_Status(__UINT32_TYPE__ PIN);

extern __UINT8_TYPE__ GPIO_PRO_CPU_Interrup_Status(__UINT32_TYPE__ PIN);

extern __UINT8_TYPE__ GPIO_PRO_CPU_NMI_Interrup_Status(__UINT32_TYPE__ PIN);

#endif
