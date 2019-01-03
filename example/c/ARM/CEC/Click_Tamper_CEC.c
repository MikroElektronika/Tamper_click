/*
Example for Tamper Click

    Date          : Nov 2017.
    Author        : MikroE Team

Test configuration CEC :
    
    MCU              : CEC1702
    Dev. Board       : Clicker 2 for CEC1702
    ARM Compiler ver : v5.1.0.0

---

Description :

The application is composed of three sections :

 - System Initialization - GPIO and UART initialization 
 - Application Initialization - Sends HAL pointers
 - Application Task - Detects ON state of Tamper click

Additional Functions :

-   
-

*/

#include "Click_Tamper_types.h"


uint8_t getINT()
{
     return GPIO_INPUT_030_037.B0;
}

typedef void    (*T_hal_gpioSetFp)(uint8_t);
typedef uint8_t (*T_hal_gpioGetFp)();

typedef struct
{
    T_hal_gpioSetFp      gpioSet[ 12 ];
    T_hal_gpioGetFp      gpioGet[ 12 ];

}T_hal_gpioObj;

const T_hal_gpioObj GPIO_BUS =
{
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, &getINT, 0, 0, 0, 0 }
};
void systemInit()
{
     GPIO_Digital_Output(&GPIO_PORT_130_137, _GPIO_PINMASK_5);
     GPIO_OUTPUT_130_137 = 0;
     GPIO_OUTPUT_130_137.B5 = 0;
     Delay_ms(100);
     GPIO_OUTPUT_130_137.B5 = 1;
     Delay_ms(100);
     UART0_Init(9600);
     GPIO_Digital_Input (&GPIO_PORT_030_037, _GPIO_PINMASK_0);
     Delay_ms( 100 );
}

void applicationInit()
{
     tamper_gpioDriverInit( (T_TAMPER_P)&GPIO_BUS );
}

void applicationTask()
{
    if(tamper_getState())
    {
        UART0_Write_text("Tamper click is in ON state\r\n");
		UART0_Write(13);
		UART0_Write(10);
    }
    Delay_ms(200);
}

void main()
{
    systemInit();
    applicationInit();

    while (1)
    {
            applicationTask();
    }
}
