/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */

extern int syscallsummary_start();
extern int syscallsummary_stop();
extern long zfunction(long);
extern void printsegaddress();
extern void printtos();
extern void printprocstks(int);
extern void printsyscallsummary();

int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");

	//1. calling zfunction
	long var =0xaabbccdd;
	kprintf("Task 1: \nzfunction output: 0x%X\n",zfunction(var));
	kprintf("\n");

	//2. Calling printsegaddress 
	printsegaddress();
	kprintf("\n");

	//3. Calling printos
	printtos();
	kprintf("\n");

	//4. Calling printprocstks
	printprocstks(5);
	kprintf("\n");

	//5. calling printsyscallsummary
	syscallsummary_start();
	sleep(1);
	syscallsummary_stop();	
	printsyscallsummary();


	return 0;
}
