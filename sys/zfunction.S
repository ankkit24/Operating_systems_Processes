.globl zfunction
zfunction:
		pushl %ebp
		movl %esp, %ebp
		
		#loop count is added in the ecx register
		movl $8, %ecx
		#storing the esi and edi registers
		pushl %esi
		pushl %edi
		#assiging argument value to the esi register
		movl 16(%esp), %esi
		#clear the 9th to 17th bits
		movl $0xfffc01ff, %edi
		and %edi, %esi
		#moving the value to ebx for shifting and adding bits
		movl $0xff000000, %ebx
l1:
		#shifting one bit to the right
		shrl %esi
		loop l1
		#adding 1 at the beginning
		addl %ebx, %esi
		#loop l1
		#move the result to eax and popping esi,edi and ebp
		movl %esi, %eax
		popl %esi
		popl %edi

		movl %ebp, %esp
		popl %ebp
		ret
