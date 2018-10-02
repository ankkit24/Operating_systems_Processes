/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
extern int ctr1000;
extern int tracetime[27][1];
extern int tracecount[27][1];
extern char *syscal[27];

SYSCALL getpid()
{
	int start = ctr1000;
	int end = ctr1000;
	int time = end - start;
        tracetime[3][1]+=time;
        tracecount[3][1]++;
        syscal[3] = "getpid";	
	return(currpid);
}
