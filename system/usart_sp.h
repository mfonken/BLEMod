/*
 * usart_sp.h
 *
 *  Created on: Nov 14, 2016
 *      Author: Matthew Fonken
 */

#ifndef USART_SP_H_
#define USART_SP_H_



void Print_String( uint8_t *s, uint8_t len );
void Print_Double_Ascii( uint16_t v );
void Print_IMU( uint16_t motion_data[6] );

#endif /* USART_SP_H_ */
