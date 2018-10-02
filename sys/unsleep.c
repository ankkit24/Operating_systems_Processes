/* unsleep.c - unsleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 * unsleep  --  remove  process from the sleep queue prematurely
 *------------------------------------------------------------------------
 */
extern int ctr1000;
extern int tracetime[27][1];
extern int tracecount[27][1];
extern char *syscal[27];

SYSCALL	unsleep(int pid)
{
        int start = ctr1000;
	STATWORD ps;    
	struct	pentry	*pptr;
	struct	qent	*qptr;
	int	remain;
	int	next;

        disable(ps);
	if (isbadpid(pid) ||
	    ( (pptr = &proctab[pid])->pstate != PRSLEEP &&
	     pptr->pstate != PRTRECV) ) {
		restore(ps);
        int end = ctr1000;
        int time = (end-start);
        tracetime[26][1]+=time;
        tracecount[26][1]++;
        syscal[26] = "unsleep";

		return(SYSERR);
	}
	qptr = &q[pid];
	remain = qptr->qkey;
	if ( (next=qptr->qnext) < NPROC)
		q[next].qkey += remain;
	dequeue(pid);
	if ( (next=q[clockq].qnext) < NPROC)
		sltop = (int *) & q[next].qkey;
	else
		slnempty = FALSE;
        restore(ps);
        int end = ctr1000;
        int time = (end-start);
        tracetime[26][1]+=time;
        tracecount[26][1]++;
        syscal[26] = "unsleep";
	return(OK);
}
