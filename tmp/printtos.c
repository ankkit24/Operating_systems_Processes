#include <stdio.h>

static unsigned char *sptval,  *sptval1, *sptval2, *sptval3, *sptval4;
static unsigned char *sptadd,  *sptadd1, *sptadd2, *sptadd3, *sptadd4, *sptret;


void printtos(){

        asm("pushl %ebp");
        asm("movl %esp, %ebp");
	
	//asm("movl %ebp, bptadd");
	//printf("Base pointer: %X\n",bptadd);
	
	asm("movl $128, %esi");
	asm("movl $64, %edi");
	asm("movl $32, %ebx");
        asm("pushl %esi");
	asm("pushl %edi");
	asm("pushl %ebx");
        asm("movl %esp, sptadd");
	//printf("Stack pointer: %X\n",sptadd);
	
	asm("movl 4(%esp), %eax");
	asm("movl %eax, sptval1");
	asm("leal 4(%esp), %eax");
	asm("movl %eax, sptadd1");
        //printf("Value in stack in location 1 below the top: %X\n",sptval1);
	
        asm("movl 8(%esp), %eax");
        asm("movl %eax, sptval2");
        asm("leal 8(%esp), %eax");
        asm("movl %eax, sptadd2");
        //printf("Value in stack in location 2 below the top: %X\n",sptval2);

        asm("movl 12(%esp), %eax");
        asm("movl %eax, sptval3");
        asm("leal 12(%esp), %eax");
        asm("movl %eax, sptadd3");
        //printf("Value in stack in location 3 below the top: %X\n",sptval3);

        asm("movl 16(%esp), %eax");
        asm("movl %eax, sptval4");
	//the value in sptval is the return address pointing to the caller.
	asm("movl %eax, sptret");
        asm("leal 16(%esp), %eax");
        asm("movl %eax, sptadd4");
        //printf("Value in stack in location 4 below the top: %X\n",sptval4);

	//asm("movl $0, %eax");
        asm("popl %ebx");
	asm("movl %ebx, sptval");

	asm("popl %edi");
	asm("popl %esi");
        asm("popl %ebp");
	//asm("movl %ebp, bptval");
        //asm("movl %esp, sptret");
        asm("movl $0, %eax");

	/*printf("Stack pointer: %X\n",sptadd);
        printf("Value at the top of the stack: %X\n", sptval);
	printf("Base pointer: %X\n",bptadd);
	printf("Value at the base pointer address: %X\n", bptval);
	printf("Address of the stack location 1 below the top: %X\n", sptadd1);	
	printf("Value in stack in location 1 below the top: %X\n",sptval1);
	printf("Address of the stack location 2 below the top: %X\n", sptadd2);	
	printf("Value in stack in location 2 below the top: %X\n",sptval2);
	printf("Address of the stack location 3 below the top: %X\n", sptadd3);
	printf("Value in stack in location 3 below the top: %X\n",sptval3);
	printf("Address of the stack location 4 below the top: %X\n", sptadd4);
	printf("Value in stack in location 4 below the top: %X\n",sptval4);
        printf("Stack pointer of the returning address: %X\n", sptret);
	*/
	
	printf("Task 3: \nvoid printtos()\n");
	printf("Before[0x%x]: 0x%x\n",sptret,*sptret);
	printf("After[0x%x]: 0x%x\n",sptadd,sptval);
	printf("	element1[0x%x]:0x%x\n",sptadd1,sptval1);
	printf("        element2[0x%x]:0x%x\n",sptadd2,sptval2);
	printf("        element3[0x%x]:0x%x\n",sptadd3,sptval3);
	printf("        element4[0x%x]:0x%x\n",sptadd4,sptval4);	


}

