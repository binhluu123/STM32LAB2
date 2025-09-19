/*
 * global.h
 *
 *  Created on: Sep 18, 2025
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#define INIT 0
#define EN0  1
#define EN1  2
#define EN2  3
#define EN3  4
#define LED_ALL (SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin)
#include "software_timer.h"

extern int timer1_num;
extern int segCode[10];
extern int led_buffer[4];
extern int status;

void LED7_SEG(int num);
void display7SEG();
void LED7_OFF();
void Enable(int index);
void Dot_state();

#endif /* INC_GLOBAL_H_ */
