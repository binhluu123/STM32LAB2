/*
 * software_timer.c
 *
 *  Created on: Sep 17, 2025
 *      Author: ADMIN
 */
#include "software_timer.h"

int timer1_count = 0;
int timer1_flag = 0;

int timer2_count = 0;
int timer2_flag = 0;

int timer3_count = 0;
int timer3_flag = 0;

void setTimer1(int duration){
	timer1_count = duration;
	timer1_flag  = 0;
}
void setTimer2(int duration){
	timer2_count = duration;
	timer2_flag  = 0;
}
void setTimer3(int duration){
	timer3_count = duration;
	timer3_flag  = 0;
}
void runTimer(){
	if(timer1_flag == 0){
		timer1_count--;
		if(timer1_count <= 0){
			timer1_flag = 1;
		}
	}
	if(timer2_flag == 0){
		timer2_count--;
		if(timer2_count <= 0){
			timer2_flag = 1;
		}
	}
	if(timer3_flag == 0){
		timer3_count--;
		if(timer3_count <= 0){
		    timer3_flag = 1;
		}
	}
}

