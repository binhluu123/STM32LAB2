/*
 * Led_matrix.c
 *
 *  Created on: Oct 1, 2025
 *      Author: ADMIN
 */

#include "global.h"
#include "Led_matrix.h"

uint8_t matrix_buffer[8] = {
	    0x00,  // Column 0: 00000000
	    0x00,  // Column 1: 00000000
	    0x7E,  // Column 2: 01111110
	    0x09,  // Column 3: 00001001
		0x09,  // Column 4: 00001001
		0x7E,  // Column 5: 01111110
	    0x00,  // Column 6: 00000000
	    0x00   // Column 7: 00000000
};

int index_matrix = 0;

void shiftMatrixLeft(void){
	uint8_t temp = matrix_buffer[0];
    for(int i = 0; i < 7 ; i++){
    	matrix_buffer[i] = matrix_buffer[i + 1];
    }
    matrix_buffer[MAX_LED_MATRIX - 1] = temp;
}

void updateLEDMatrix(int index){
    if(index < 0 || index >= MAX_LED_MATRIX) return;

    HAL_GPIO_WritePin(GPIOA,
    ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin|
    ENM4_Pin|ENM5_Pin|ENM6_Pin|ENM7_Pin,
    GPIO_PIN_SET);

    uint8_t pattern = matrix_buffer[index];

    HAL_GPIO_WritePin(GPIOB, ROW0_Pin, (pattern & (1<<0)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW1_Pin, (pattern & (1<<1)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW2_Pin, (pattern & (1<<2)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW3_Pin, (pattern & (1<<3)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW4_Pin, (pattern & (1<<4)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW5_Pin, (pattern & (1<<5)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW6_Pin, (pattern & (1<<6)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW7_Pin, (pattern & (1<<7)) ? GPIO_PIN_RESET : GPIO_PIN_SET);

    switch(index){
        case 0: HAL_GPIO_WritePin(GPIOA, ENM0_Pin, GPIO_PIN_RESET); break;
        case 1: HAL_GPIO_WritePin(GPIOA, ENM1_Pin, GPIO_PIN_RESET); break;
        case 2: HAL_GPIO_WritePin(GPIOA, ENM2_Pin, GPIO_PIN_RESET); break;
        case 3: HAL_GPIO_WritePin(GPIOA, ENM3_Pin, GPIO_PIN_RESET); break;
        case 4: HAL_GPIO_WritePin(GPIOA, ENM4_Pin, GPIO_PIN_RESET); break;
        case 5: HAL_GPIO_WritePin(GPIOA, ENM5_Pin, GPIO_PIN_RESET); break;
        case 6: HAL_GPIO_WritePin(GPIOA, ENM6_Pin, GPIO_PIN_RESET); break;
        case 7: HAL_GPIO_WritePin(GPIOA, ENM7_Pin, GPIO_PIN_RESET); break;
        default: break;
    }
}
