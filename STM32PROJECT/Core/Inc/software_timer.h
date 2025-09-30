/*
 * software_timer.h
 *
 *  Created on: Sep 17, 2025
 *      Author: ADMIN
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define MAX_COUNTER 10
#define MAX_TICK    10
int timer_count[MAX_COUNTER];
int timer_flag [MAX_COUNTER];
int timer_use  [MAX_COUNTER];

void setTimer(int index, int value);
int isTimerExpired(int num);
int allocateTimer();
void freeTimer(int id);
void runTimer();

#endif /* INC_SOFTWARE_TIMER_H_ */
