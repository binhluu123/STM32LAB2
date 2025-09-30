/*
 * software_timer.c
 *
 *  Created on: Sep 17, 2025
 *      Author: ADMIN
 */
#include "software_timer.h"

int timer_count[MAX_COUNTER];
int timer_flag [MAX_COUNTER];
void setTimer(int index, int value){
	timer_count[index] = value;
	timer_flag [index] = 0;
}
int isTimerExpired(int index){
	if(timer_flag[index]){
		timer_flag[index] = 0;
		return 1;
	}
	return 0;
}

void runTimer(){
	for(int i = 0; i < MAX_COUNTER; i++){
		if(timer_count[i] > 0){
			timer_count[i] --;
			if(timer_count[i] <= 0){
				timer_flag[i] = 1;
			}
		}
	}
}

