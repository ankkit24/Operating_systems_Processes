#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  *  main  --  user main program
 *   *------------------------------------------------------------------------
 *    */

extern unsigned long   ctr1000;        /* counts in 1000ths of second 0-INF    */
int tracecount[27][1];
int tracetime[27][1];
char *syscal[27];

int syscallsummary_start(){
	//return clktime;
	return ctr1000;
}

int syscallsummary_stop(){
	//return clktime;
	return ctr1000;
}


void printsyscallsummary()
{
	printf("Task 5: \nvoid printsyscallsummary()\n");		
	printf("Process [pid:%d]\n", currpid);
	int i;	
	int avg_ext;
	for (i=1; i<=27; i++){
		if(tracecount[i][1]!=0){	
			avg_ext=tracetime[i][1]/tracecount[i][1];
			printf("	Syscall: %s, count:%d, average execution time: %d(ms)\n",syscal[i],tracecount[i][1],avg_ext);
		}
	}
        //printf("trace count sleep: %d\n",tracecount[1][1]);
}

