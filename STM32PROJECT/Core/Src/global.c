/*
 * global.c
 *
 *  Created on: Sep 18, 2025
 *      Author: ADMIN
 */
#include "global.h"

int hour = 15, minute = 8, second = 50;
int led_buffer[4] = {0,0,0,0};
int index_led = 0;
int MAX_LED = 4;

int segCode[10] = {
		0xC0, // 0
		0xF9, // 1
		0xA4, // 2
		0xB0, // 3
		0x99, // 4
		0x92, // 5
		0x82, // 6
		0xF8, // 7
		0x80, // 8
		0x90  // 9
};
void LED_BLINKY(){
	HAL_GPIO_TogglePin(LED_BLINKY_GPIO_Port, LED_BLINKY_Pin);
}
void LED7_OFF(){
	GPIOA->BSRR = LED_ALL;
}
void display7SEG(int num){
	if(num > 9) return;
	int code = segCode[num];
	HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, (code & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, (code & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, (code & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, (code & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, (code & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, (code & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, (code & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void Enable(int index){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, (index == 0) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, (index == 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, (index == 2) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, (index == 3) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}
void Dot_state(){
	HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
}

void Excute_Led7(int index){
	Enable(index);
	display7SEG(led_buffer[index]);
}
void update7SEG(int index){
	if(index >= MAX_LED) index = 0;
    switch(index){
    case LED_1:
    	Excute_Led7(index);
    	break;
    case LED_2:
    	Excute_Led7(index);
       	break;
    case LED_3:
    	Excute_Led7(index);
       	break;
    case LED_4:
    	Excute_Led7(index);
       	break;
    default:
    	break;
    }
}
void updateClockBuffer(){
	led_buffer[0] = hour / 10;
	led_buffer[1] = hour % 10;
	led_buffer[2] = minute / 10;
	led_buffer[3] = minute % 10;
}


