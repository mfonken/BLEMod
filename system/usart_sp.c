/***********************************************************************************************//**
 * \file   usart_sp.c
 * \brief  USART Special Functions
 ***************************************************************************************************
 *      Author: Matthew Fonken
 **************************************************************************************************/

/* em headers */
#include "em_usart.h"
#include "em_i2c.h"

/***********************************************************************************************//**
 * @addtogroup Application
 * @{
 **************************************************************************************************/

/***********************************************************************************************//**
 * @addtogroup sp
 * @{
 **************************************************************************************************/

/***************************************************************************************************
 Function Declarations
 **************************************************************************************************/

/***********************************************************************************************//**
 *  \brief  Print character
 *  \param[in] c Character to print
 **************************************************************************************************/
void Print_Char( uint8_t c )
{
	USART_Tx( USART0, c );
}

/***********************************************************************************************//**
 *  \brief  Print string
 *  \param[in] s String to print
 *  \param[in] len Length of string
 **************************************************************************************************/
void Print_String( uint8_t *s, uint8_t len )
{
	for( int i = 0; i < len; i++ )
	{
		USART_Tx( USART0, s[i] );
	}
}

/***********************************************************************************************//**
 *  \brief  Print two byte integer
 *  \param[in] v integer to print
 **************************************************************************************************/
void Print_Double_Ascii( uint16_t v )
{
	bool pad = true;
	for( int i = 4; i >= 0; i-- )
	{
		uint16_t power = 1;
		for( int p = 0; p < i; p++ )
		{
			power *= 10;
		}
		uint8_t digit = v / power;
		if( pad && digit != 0 )
		{
			pad = false;
		}
		if( pad == false )
		{
			USART_Tx( USART0, digit | 0x30 );
		}
		v -= ( digit * power );
	}
}

/***********************************************************************************************//**
 *  \brief  Print IMU Data
 *  \param[in] motion_data IMU data to print
 **************************************************************************************************/
void Print_IMU( uint16_t motion_data[6] )
{
	Print_String( "IMU: g(", 7 );
	Print_Double_Ascii( motion_data[0] );
	Print_Char( ',' );
	Print_Double_Ascii( motion_data[1] );
	Print_Char( ',' );
	Print_Double_Ascii( motion_data[2] );
	Print_String( ") | a(", 6 );
	Print_Double_Ascii( motion_data[3] );
	Print_Char( ',' );
	Print_Double_Ascii( motion_data[4] );
	Print_Char( ',' );
	Print_Double_Ascii( motion_data[5] );
	Print_String( ")\r\n", 3 );
}

/** @} (end addtogroup sp) */
/** @} (end addtogroup Application) */
