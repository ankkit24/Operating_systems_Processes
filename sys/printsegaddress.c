#include <stdio.h>

extern char etext, edata, end;

void printsegaddress(){	
	char *x=&etext;
	char *y=&edata;
	char *z=&end;
/*
	printf("End of text segment address  		    : 0x%lx\n", x);
	printf("Value at the end of text segment address    : %d\n",*x);
	printf("4-byte Hex content of the next address      : 0x%lx\n", *(++x));
	--x;
	printf("4-byte Hex content of the previous address  : 0x%d\n\n", *(--x));
	
	printf("End of data segment address                 : 0x%lx\n", y);
	printf("Value at the end of data segment address    : %d\n",*y);
	printf("4-byte Hex content of the next address      : 0x%lx\n", *(++y));
        --y;
	printf("4-byte Hex content of the previous address  : 0x%lx\n\n", *(--y));

        printf("End of BSS segment address                  : 0x%lx\n", z);
	printf("Value at the end of BSS segment address     : %d\n",*z);
	printf("4-byte Hex content of the next address      : 0x%lx\n", *(++z));
        --z;
	printf("4-byte Hex content of the previous address  : 0x%lx\n\n", *(--z));
	*/
	printf("Task 2: \nvoid printsegaddress()\n");
	printf("Current: etext[0x%x]=0x%x ,edata[0x%x]=0x%x ,ebss[0x%x]=0x%x\n",x,*x,y,*y,z,*z);
	--x,--y,--z;
	printf("Preceding: etext[0x%x]=0x%x ,edata[0x%x]=0x%x ,ebss[0x%x]=0x%x\n",x,*x,y,*y,z,*z);
	++x,++y,++z;
	++x,++y,++z;
	printf("After: etext[0x%x]=0x%x ,edata[0x%x]=0x%x ,ebss[0x%x]=0x%x\n",x,*x,y,*y,z,*z);	

}



