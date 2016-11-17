/***********************************************************************************************//**
 * \file   app_hw.c
 * \brief  Hardware specific application code
 ***************************************************************************************************
 * <b> (C) Copyright 2015 Silicon Labs, http://www.silabs.com</b>
 ***************************************************************************************************
 * This file is licensed under the Silabs License Agreement. See the file
 * "Silabs_License_Agreement.txt" for details. Before using this software for
 * any purpose, you must agree to the terms of that agreement.
 **************************************************************************************************/

/* BG stack headers */
#include "bg_types.h"

/* STK header files. */

/* Temp sensor and I2c*/
#include "em_usart.h"
#include "app_ui.h"
#include "kinetic.h"
#include "app_hw.h"
#include "usart_sp.h"

/***********************************************************************************************//**
 * @addtogroup Application
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup app_hw
 * @{
 **************************************************************************************************/


/***************************************************************************************************
  Local Macros and Definitions
 **************************************************************************************************/

/* Text definitions*/
#define APP_HW_IMU_FAIL_TEXT         "Failed to detect imu sensor."


/***************************************************************************************************
 Local Variables
 **************************************************************************************************/

/** I2C init structure. */

/***************************************************************************************************
 Static Function Declarations
 **************************************************************************************************/

/***************************************************************************************************
 Public Function Definitions
 **************************************************************************************************/

void appHwInit(void)
{
	initKinetics();
}


/***************************************************************************************************
 Static Function Definitions
 **************************************************************************************************/



/** @} (end addtogroup app_hw) */
/** @} (end addtogroup Application) */
