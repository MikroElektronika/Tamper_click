/*
Example for Tamper Click

    Date          : Nov 2017.
    Author        : MikroE Team

Test configuration dsPIC :
    
    MCU                : P33FJ256GP710A
    Dev. Board         : EasyPIC Fusion v7
    dsPIC Compiler ver : v7.0.1.0

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
    return RE8_bit;
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
     ANSELA = 0x00;    // Convert all I/O pins to digital
     ANSELB = 0x00;
     ANSELC = 0x00;
     ANSELD = 0x00;
     ANSELE = 0x00;
     ANSELG = 0x00;

     PPS_Mapping(100, _INPUT,  _U1RX);    // Sets pin RP100 to be Input, and maps U1RX to it
     PPS_Mapping(101, _OUTPUT, _U1TX);    // Sets pin RP101 to be Output, and maps U1TX to it
     TRISE8_bit = 1;    // RE0 input
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