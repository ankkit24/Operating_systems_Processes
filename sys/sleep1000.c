/* sleep1000.c - sleep1000 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * sleep1000 --  delay the caller for a time specified in 1/100 of seconds
 *------------------------------------------------------------------------
 */
extern int ctr1000;
extern int tracetime[27][1];
extern int tracecount[27][1];
extern char *syscal[27];

SYSCALL sleep1000(int n)
{
        int start = ctr1000;
	STATWORD ps;    

	if (n < 0  || clkruns==0){
	        int end = ctr1000;
        int time = (end-start);
        tracetime[22][1]+=time;
        tracecount[22][1]++;
        syscal[22] = "sleep1000";

	         return(SYSERR);}
	disable(ps);
	if (n == 0) {		/* sleep1000(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
        int end = ctr1000;
        int time = (end-start);
        tracetime[22][1]+=time;
        tracecount[22][1]++;
        syscal[22] = "sleep1000";
	return(OK);
}
