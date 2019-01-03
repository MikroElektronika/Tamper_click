![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Tamper Click

- **CIC Prefix**  : TAMPER
- **Author**      : MikroE Team

---

### Software Support

We provide a library for the Tamper Click on our [LibStock](http://libstock.mikroe.com/projects/view/2222/tamper-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

Key functions :

- ``` uint8_t tamper_getState() ```  - Function detects ON state of the switch.

**Examples Description**

Detects ON state of Tamper click. 

```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](http://libstock.mikroe.com/projects/view/2222/tamper-click) page.

Other mikroE Libraries used in the example:

- UART

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
