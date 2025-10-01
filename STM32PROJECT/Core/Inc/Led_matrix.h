/*
 * Led_matrix.h
 *
 *  Created on: Oct 1, 2025
 *      Author: ADMIN
 */

#ifndef INC_LED_MATRIX_H_
#define INC_LED_MATRIX_H_

#include "main.h"

#define MAX_LED_MATRIX 8

extern uint8_t matrix_buffer[MAX_LED_MATRIX];
extern int index_matrix;
void updateLEDMatrix(int index);
void shiftMatrixLeft();
#endif /* INC_LED_MATRIX_H_ */
