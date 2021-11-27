#include "include/drivers/screen.h"
#include "include/system.h"

int timer_ticks = 0;
char seconds = 0 ;
char minutes = 0;
int hours = 0;
void timer_handler(struct regs *r) {
	char * stringval;
	/* Increment our 'tick count' */
	timer_ticks++;

	/* Every 18 clocks (approximately 1 second), we will
	*  display a message on the screen */
	if (timer_ticks % 18 == 0) {
	   print(itoa(hours, stringval, 10));
	   print(":");
	   print(itoa(minutes%60, stringval, 10));
	   print(":");
	   print(itoa(seconds%60, stringval, 10));
	   print("\n");
	   seconds++;
	   if(seconds == 60 ){
		  seconds = 0;
		  minutes++;
	   }
	   if (minutes == 60){
	   	minutes = 0;
		hours ++;
	   }
	}
}

void timer_wait(int ticks) {
	unsigned long eticks;

	eticks = timer_ticks + ticks;
	while (timer_ticks < eticks)
		;
}

void timer_install() {
	timer_ticks = 0;
	irq_install_handler(0, timer_handler); 
}
