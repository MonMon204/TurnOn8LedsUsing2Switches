/*
 * main.c
 *
 *  Created on: Sep 23, 2023
 *      Author: Mina Waguih
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"


void delay(void);
void TurnOnLeds(void);
void TurnOffLeds(void);

int main(){
	MRCC_voidInit();
	MRCC_voidEnablePeripheral(RCC_BUS_APB2 , 2);
	for(u8 i=0; i<8; i++){
		MGPIO_voidSetPinDirection(PORTA, i, GPIOA_OUTPUT_2MHZ,GPIOA_OUTPUT_PUSH_PULL);
	}
	MGPIO_voidSetPinDirection(PORTA, 8, GPIOA_INPUT, GPIOA_INPUT_PULLUP);
	MGPIO_voidSetPinDirection(PORTA, 9, GPIOA_INPUT, GPIOA_INPUT_PULLUP);

	while(1){
		if(MGPIO_u8GetPinValue(PORTA,8) == 0 &&  MGPIO_u8GetPinValue(PORTA,0)==0){
			TurnOnLeds();
		}

		if(MGPIO_u8GetPinValue(PORTA,9) == 0 && MGPIO_u8GetPinValue(PORTA,0)==1){
			TurnOffLeds();
		}
	}
}

void delay(void)
{
	for ( u32 i= 0;  i<10000; i++ )
	{
		asm("nop");
	}
}

void TurnOnLeds(void){
	for(u8 i=0; i<8; i++){
		MGPIO_voidSetPinValue(PORTA,i,1);
		delay();
	}
}

void TurnOffLeds(void){
	for(s8 i=7; i>=0; i--){
		MGPIO_voidSetPinValue(PORTA,i,0);
		delay();
	}
}


