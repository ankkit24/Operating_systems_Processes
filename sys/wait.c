/* wait.c - wait */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * wait  --  make current process wait on a semaphore
 *------------------------------------------------------------------------
 */
extern int ctr1000;
extern int tracetime[27][1];
extern int tracecount[27][1];
extern char *syscal[27];

SYSCALL	wait(int sem)
{
        int start = ctr1000;
	STATWORD ps;    
	struct	sentry	*sptr;
	struct	pentry	*pptr;

	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		restore(ps);
        int end = ctr1000;
        int time = (end-start);
        tracetime[27][1]+=time;
        tracecount[27][1]++;
        syscal[27] = "wait";
		return(SYSERR);
	}
	
	if (--(sptr->semcnt) < 0) {
		(pptr = &proctab[currpid])->pstate = PRWAIT;
		pptr->psem = sem;
		enqueue(currpid,sptr->sqtail);
		pptr->pwaitret = OK;
		resched();
		restore(ps);
        int end = ctr1000;
        int time = (end-start);
        tracetime[27][1]+=time;
        tracecount[27][1]++;
        syscal[27] = "wait";
		return pptr->pwaitret;
	}
	restore(ps);
	        int end = ctr1000;
        int time = (end-start);
        tracetime[27][1]+=time;
        tracecount[27][1]++;
        syscal[27] = "wait";
	return(OK);
}
