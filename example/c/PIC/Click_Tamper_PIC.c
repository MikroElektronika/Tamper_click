/*
Example for Tamper Click

    Date          : Nov 2017.
    Author        : MikroE Team

Test configuration PIC :
    
    MCU             : P18F87K22
    Dev. Board      : EasyPIC PRO v7
    PIC Compiler ver : v7.1.0.0

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

sbit Tamper_STATE at PORTB.B0;
sbit Tamper_STATE_Direction at TRISB.B0;

uint8_t getINT()
{
     return PORTB.B0;
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
     ANCON0 = 0x00;
     ANCON1 = 0x00;
     ANCON2 = 0x00;
     Tamper_STATE_Direction = 1;
     UART1_Init(9600);
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
        UART1_Write_text("Tamper click is in ON state\r\n");
		UART1_Write(13);
		UART1_Write(10);
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