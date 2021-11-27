#include "include/system.h"
#include "include/drivers/screen.h"
#include "include/system.h"

void printi(){
	print("OS Aung Naing Oo\n");
	print("kernel 0.1v\n");
}

void main(){
	screen_init(); // init vga driver
	clear_screen(); // clear the entire screen

	//init IDT
	idt_install();

	//init ISRs
	isrs_install();

	//init IRQ
	irq_install();
	__asm__ __volatile__ ("sti");

	//keyboard_install();
	print("Aung Naing Oo\n");
	print("I <3 creating cool software. \n");
	timer_install();	

	while(1);
}

