/* signal.c - signal */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * signal  --  signal a semaphore, releasing one waiting process
 *------------------------------------------------------------------------
 */
extern int ctr1000;
extern int tracetime[27][1];
extern int tracecount[27][1];
extern char *syscal[27];

SYSCALL signal(int sem)
{
        int start = ctr1000;
	STATWORD ps;    
	register struct	sentry	*sptr;

	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		restore(ps);
		return(SYSERR);
	        int end = ctr1000;
        	int time = (end-start);
	        tracetime[17][1]+=time;
        	tracecount[17][1]++;
        	syscal[17] = "signal";

	}
	if ((sptr->semcnt++) < 0)
		ready(getfirst(sptr->sqhead), RESCHYES);
	restore(ps);
        int end = ctr1000;
        int time = (end-start);
        tracetime[17][1]+=time;
        tracecount[17][1]++;
        syscal[17] = "signal";

	return(OK);
}
