/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>

/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */
extern int ctr1000;
extern int tracetime[27][1];
extern int tracecount[27][1];
extern char *syscal[27];

SYSCALL	setdev(int pid, int dev1, int dev2)
{
        int start = ctr1000;
	short	*nxtdev;

	if (isbadpid(pid)){
	int end = ctr1000;
        int time = (end-start);
        tracetime[14][1]+=time;
        tracecount[14][1]++;
        syscal[14] = "setdev";
		return(SYSERR);}
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
        int end = ctr1000;
        int time = (end-start);
        tracetime[14][1]+=time;
        tracecount[14][1]++;
        syscal[14] = "setdev";

	return(OK);
}
