/*
 * fsm_machine.c
 *
 *  Created on: Sep 18, 2025
 *      Author: ADMIN
 */
#include "fsm_machine.h"

int status = 0;

void fsm_automatic_run(){
	Dot_state();
	switch(status){
	case INIT:
    LED7_OFF();
    status = EN0;
    setTimer1(50);
	break;
	case EN0:
		Enable(EN0);
		if(timer1_flag == 1){
			status = EN1;
			setTimer1(50);
		}
	break;
	case EN1:
	    Enable(EN1);
		if(timer1_flag == 1){
			status = EN2;
			setTimer1(50);
		}
	break;
	case EN2:
		Enable(EN2);
		if(timer1_flag == 1){
			status = EN3;
			setTimer1(50);
		}
	break;
	case EN3:
		Enable(EN3);
		if(timer1_flag == 1){
			status = EN0;
			setTimer1(50);
		}
	default:
	break;
	}
}
