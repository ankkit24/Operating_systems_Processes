/* sleep10.c - sleep10 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * sleep10  --  delay the caller for a time specified in tenths of seconds
 *------------------------------------------------------------------------
 */
extern int ctr1000;
extern int tracetime[27][1];
extern int tracecount[27][1];
extern char *syscal[27];

SYSCALL	sleep10(int n)
{
        int start = ctr1000;
	STATWORD ps;    
	if (n < 0  || clkruns==0){
	        int end = ctr1000;
        int time = (end-start);
        tracetime[20][1]+=time;
        tracecount[20][1]++;
        syscal[20] = "sleep10";

	         return(SYSERR);}
	disable(ps);
	if (n == 0) {		/* sleep10(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n*100);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
        int end = ctr1000;
        int time = (end-start);
        tracetime[20][1]+=time;
        tracecount[20][1]++;
        syscal[20] = "sleep10";
	return(OK);
}
