/*
 * Led_matrix.c
 *
 *  Created on: Oct 1, 2025
 *      Author: ADMIN
 */

#include "global.h"
#include "Led_matrix.h"

uint8_t animation_buffer[16] = {
    0x18,
    0x24,
    0x42,
    0x7E,
    0x42,
    0x42,
    0x42,
    0x00,
    // Thêm 8 cột trống để tạo khoảng cách khi scroll
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

uint8_t matrix_buffer[MAX_LED_MATRIX] = {0}; // cửa sổ hiển thị
int index_matrix = 0;
int offset = 0;

// Hàm nạp dữ liệu từ animation_buffer vào matrix_buffer
void shiftMatrixLeft(void){
    for(int i = 0; i < MAX_LED_MATRIX; i++){
        matrix_buffer[i] = animation_buffer[(offset + i) % 16];
    }
    offset++;
    if(offset >= 16) offset = 0;
}

void updateLEDMatrix(int index){
    if(index < 0 || index >= MAX_LED_MATRIX) return;

    // 1) Blank: tắt (disable) tất cả cột trước (ENM pins = SET để OFF với ULN active-low)
    HAL_GPIO_WritePin(GPIOA,
        ENM0_Pin|ENM1_Pin|ENM2_Pin|ENM3_Pin|
        ENM4_Pin|ENM5_Pin|ENM6_Pin|ENM7_Pin,
        GPIO_PIN_SET);

    // 2) Lấy pattern cột hiện tại (bit = 1 => muốn LED ON ở hàng tương ứng)
    uint8_t pattern = matrix_buffer[index];

    // 3) Viết ra các ROW (active-low: nếu bit = 1 => WRITE RESET để bật LED)
    HAL_GPIO_WritePin(GPIOB, ROW0_Pin, (pattern & (1<<0)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW1_Pin, (pattern & (1<<1)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW2_Pin, (pattern & (1<<2)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW3_Pin, (pattern & (1<<3)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW4_Pin, (pattern & (1<<4)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW5_Pin, (pattern & (1<<5)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW6_Pin, (pattern & (1<<6)) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, ROW7_Pin, (pattern & (1<<7)) ? GPIO_PIN_RESET : GPIO_PIN_SET);

    // 4) Bật cột hiện tại bằng switch-case (ENM = RESET để ON, vì active-low)
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
