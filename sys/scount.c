/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
extern int ctr1000;
extern int tracetime[27][1];
extern int tracecount[27][1];
extern char *syscal[27];

SYSCALL scount(int sem)
{
        int start = ctr1000;
	extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE){
        int end = ctr1000;
        int time = (end-start);
        tracetime[11][1]+=time;
        tracecount[11][1]++;
        syscal[11] = "scount";
	return (SYSERR);
	}
	
	int end = ctr1000;
        int time = (end-start);
        tracetime[11][1]+=time;
        tracecount[11][1]++;
        syscal[11] = "scount";

	return(semaph[sem].semcnt);
}
