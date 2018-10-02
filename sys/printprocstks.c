#include <stdio.h>
#include<kernel.h>
#include <proc.h>

static unsigned long    *esp;

void printprocstks(int priority){
		
	unsigned long   *sp;
	printf("Task 4:\nvoid printprocstks(int priority)\n");
	//printf("Current Process details:\n");	
	asm("movl %esp,esp");
        sp = esp;
	printf("Process[%s]:\n",proctab[currpid].pname);
        printf("	Process ID: %d\n	Stack Pointer: %X\n	Priority: %d\n	Process Name: %s\n", currpid,sp,proctab[currpid].pprio, proctab[currpid].pname);
	printf("	Process limit: %X\n	Process base: %X\n	Stack Size: %d\n",proctab[currpid].plimit, proctab[currpid].pbase,proctab[currpid].pstklen);

	printf("Process higher than priority passed in argument:\n");	
	int i;
	for(i=0; i<NPROC; i++){
		if(proctab[i].pprio > priority&&i==currpid){
			printf("Process[%s]:\n",proctab[i].pname);
		        printf("	Process ID: %d\n	Stack Pointer: %X\n	Priority: %d\n	Process Name: %s\n",i, sp, proctab[i].pprio, proctab[i].pname);
        		printf("	Process limit: %X\n	Process base: %X\n	Stack Size: %d\n",proctab[i].plimit, proctab[i].pbase, proctab[i].pstklen);
		}	
		if(proctab[i].pprio > priority&&i!=currpid){
                        printf("Process[%s]:\n",proctab[i].pname);
			printf("	Process ID: %d\n	Stack Pointer: %X\n	Priority: %d\n	Process Name: %s\n",i, proctab[i].pesp, proctab[i].pprio, proctab[i].pname);
                        printf("	Process limit: %X\n	Process base: %X\n	Stack Size: %d\n",proctab[i].plimit, proctab[i].pbase, proctab[i].pstklen);			
		}
	}
	

}







