/*

    __tamper_driver.h

----------------------------------------------------------------------------- */

/**
@file   __tamper_driver.h
@brief    Tamper Driver
@mainpage Tamper Click
@{

Tamper click holds switch detector SPST-NO 100MA SDS001R SMD and library can detect press of the switch.

@}

@defgroup   TAMPER
@brief      Tamper Click Driver
@{

| Global Library Prefix | **TAMPER** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **Nov 2017.**      |
| Developer             | **MikroE Team**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _TAMPER_H_
#define _TAMPER_H_

/** 
 * @macro T_TAMPER_P
 * @brief Driver Abstract type 
 */
#define T_TAMPER_P    const uint8_t*

/** @defgroup TAMPER_COMPILE Compilation Config */              /** @{ */

//  #define   __TAMPER_DRV_SPI__                            /**<     @macro __TAMPER_DRV_SPI__  @brief SPI driver selector */
//  #define   __TAMPER_DRV_I2C__                            /**<     @macro __TAMPER_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __TAMPER_DRV_UART__                           /**<     @macro __TAMPER_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup TAMPER_VAR Variables */                           /** @{ */



                                                                       /** @} */
/** @defgroup TAMPER_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup TAMPER_INIT Driver Initialization */              /** @{ */

#ifdef   __TAMPER_DRV_SPI__
void tamper_spiDriverInit(T_TAMPER_P gpioObj, T_TAMPER_P spiObj);
#endif
#ifdef   __TAMPER_DRV_I2C__
void tamper_i2cDriverInit(T_TAMPER_P gpioObj, T_TAMPER_P i2cObj, uint8_t slave);
#endif
#ifdef   __TAMPER_DRV_UART__
void tamper_uartDriverInit(T_TAMPER_P gpioObj, T_TAMPER_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void tamper_gpioDriverInit(T_TAMPER_P gpioObj);
                                                                       /** @} */
/** @defgroup TAMPER_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Button press detect
 *
 *  This function detects press of the button
 *  Returns 1 if the button is pressed.
 */
uint8_t tamper_getState();



                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Tamper_STM.c
    @example Click_Tamper_TIVA.c
    @example Click_Tamper_CEC.c
    @example Click_Tamper_KINETIS.c
    @example Click_Tamper_MSP.c
    @example Click_Tamper_PIC.c
    @example Click_Tamper_PIC32.c
    @example Click_Tamper_DSPIC.c
    @example Click_Tamper_AVR.c
    @example Click_Tamper_FT90x.c
    @example Click_Tamper_STM.mbas
    @example Click_Tamper_TIVA.mbas
    @example Click_Tamper_CEC.mbas
    @example Click_Tamper_KINETIS.mbas
    @example Click_Tamper_MSP.mbas
    @example Click_Tamper_PIC.mbas
    @example Click_Tamper_PIC32.mbas
    @example Click_Tamper_DSPIC.mbas
    @example Click_Tamper_AVR.mbas
    @example Click_Tamper_FT90x.mbas
    @example Click_Tamper_STM.mpas
    @example Click_Tamper_TIVA.mpas
    @example Click_Tamper_CEC.mpas
    @example Click_Tamper_KINETIS.mpas
    @example Click_Tamper_MSP.mpas
    @example Click_Tamper_PIC.mpas
    @example Click_Tamper_PIC32.mpas
    @example Click_Tamper_DSPIC.mpas
    @example Click_Tamper_AVR.mpas
    @example Click_Tamper_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __tamper_driver.h

    This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.

----------------------------------------------------------------------------- */