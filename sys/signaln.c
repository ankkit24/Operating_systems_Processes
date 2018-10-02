/* signaln.c - signaln */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  signaln -- signal a semaphore n times
 *------------------------------------------------------------------------
 */
extern int ctr1000;
extern int tracetime[27][1];
extern int tracecount[27][1];
extern char *syscal[27];

SYSCALL signaln(int sem, int count)
{
        int start = ctr1000;
	STATWORD ps;    
	struct	sentry	*sptr;

	disable(ps);
	if (isbadsem(sem) || semaph[sem].sstate==SFREE || count<=0) {
		restore(ps);
        int end = ctr1000;
        int time = (end-start);
        tracetime[18][1]+=time;
        tracecount[18][1]++;
        syscal[18] = "signaln";
		return(SYSERR);
	}
	sptr = &semaph[sem];
	for (; count > 0  ; count--)
		if ((sptr->semcnt++) < 0)
			ready(getfirst(sptr->sqhead), RESCHNO);
	resched();
	restore(ps);
        int end = ctr1000;
        int time = (end-start);
        tracetime[2][1]+=time;
        tracecount[2][1]++;
        syscal[2] = "resume";

	return(OK);
}
