/***********************************************************************************************//**
 * \file   usart_sp.c
 * \brief  USART Special Functions
 ***************************************************************************************************
 *      Author: Matthew Fonken
 **************************************************************************************************/
#include <stdio.h>
#include <math.h>
/* em headers */
#include "em_usart.h"
#include "em_i2c.h"

// reverses a string 'str' of length 'len'
void reverse(uint8_t *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}

 // Converts a given integer x to string str[].  d is the number
 // of digits required in output. If d is more than the number
 // of digits in x, then 0s are added at the beginning.
int intToStr(int x, uint8_t str[], int d, bool neg)
{
    int i = 0;
    while (x)
    {
    	x %= 10;
        str[i++] = x + '0';
        x /= 10;
    }

    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';


    reverse(str, i);

    str[i] = '\0';
    if(neg)
    {
		for(int j = 0; j < i; j++ )
		{
			str[j + 1] = str[j];
		}
		str[0] = '-';
    }
    return i;
}

// Converts a floating point number to string.
void dtoa (double n, uint8_t *res, int afterpoint)
{
	bool neg = false;
    if( n < 0 )
    {
    	n = -n;
    	neg = true;
    }

    // Extract integer part
    int ipart = (int)n;

    // Extract floating part
    double dpart = n - (double)ipart;

    // convert integer part to string
    int i = intToStr(ipart, res, 0, neg);

    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.';  // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007
        dpart = dpart * pow(10, afterpoint);

        intToStr((int)dpart, res + i + 1, afterpoint, false);
    }
}
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
void Print_Double_Ascii( double v )
{
	uint8_t output[9];
	dtoa( v, output, 3 );
	for( int i = 0; i < 9; i++ )
	{
//		if( output[i] == '.' || ( output[i] >= 0x30 && output[i] < 0x40 ) )
		{
			USART_Tx( USART0, output[i] );
		}
	}
	Print_Char( 0x00 );
//	bool pad = true;
//	for( int i = 4; i >= 0; i-- )
//	{
//		uint16_t power = 1;
//		for( int p = 0; p < i; p++ )
//		{
//			power *= 10;
//		}
//		uint8_t digit = ( uint8_t )v / power;
//		if( pad && digit != 0 )
//		{
//			pad = false;
//		}
//		if( pad == false )
//		{
//			USART_Tx( USART0, digit | 0x30 );
//		}
//		v -= ( digit * power );
//	}
}

/***********************************************************************************************//**
 *  \brief  Print IMU Data
 *  \param[in] motion_data IMU data to print
 **************************************************************************************************/
void Print_IMU( double motion_data[6], bool stripped )
{
	if( !stripped )
		Print_String( "IMU: g(", 7 );
	Print_Char( '0' );
	Print_Double_Ascii( motion_data[0] );
	Print_Char( ',' );
	Print_Double_Ascii( motion_data[1] );
	Print_Char( ',' );
	Print_Double_Ascii( motion_data[2] );
	if( !stripped )
		Print_String( ") | a(", 6 );
	else
		Print_Char( ',' );
	Print_Double_Ascii( motion_data[3] );
	Print_Char( ',' );
	Print_Double_Ascii( motion_data[4] );
	Print_Char( ',' );
	Print_Double_Ascii( motion_data[5] );
	if( !stripped )
		Print_Char( ')' );
	Print_Char( '\n' );
	Print_Char( 0x00 );
}



/** @} (end addtogroup sp) */
/** @} (end addtogroup Application) */
