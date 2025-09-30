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

// Buffer lưu dữ liệu hiển thị (mỗi phần tử là pattern cho 1 cột)
extern uint8_t matrix_buffer[MAX_LED_MATRIX];

// Chỉ số cột đang quét
extern int index_matrix;

// Prototype hàm update
void updateLEDMatrix(int index);

void shiftMatrixLeft();
#endif /* INC_LED_MATRIX_H_ */
