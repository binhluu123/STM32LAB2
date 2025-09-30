/*
 * global.h
 *
 *  Created on: Sep 18, 2025
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#define LED_1  0
#define LED_2  1
#define LED_3  2
#define LED_4  3
#define LED_ALL (EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin)
#include "software_timer.h"

extern int segCode[10];
extern int led_buffer[4];
extern int MAX_LED;
extern int index_led;

void LED_BLINKY();
void display7SEG(int num);
void LED7_OFF();
void Enable(int index);
void Dot_state();
void update7SEG(int index);
void Excute_Led7(int index, int flag, int timer);

#endif /* INC_GLOBAL_H_ */
