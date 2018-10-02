/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>

extern int getutim(unsigned long *);

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
extern int ctr1000;
extern int tracetime[27][1];
extern int tracecount[27][1];
extern char *syscal[27];

SYSCALL	gettime(long *timvar)
{
    /* long	now; */

	/* FIXME -- no getutim */
        int start = ctr1000;
        int end = ctr1000;
        int time = (end-start);
        tracetime[5][1]+=time;
        tracecount[5][1]++;
        syscal[5] = "gettime";

    return OK;
}
