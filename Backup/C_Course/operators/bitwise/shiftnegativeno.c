/****  shifting negative no.s ****/

#include<stdio.h>

void printBits(int x)
{
	int i,j;
	for(i=7;i>=0;i--)
	{ 
		j=(x>>i) & 0x01;
		printf("%d",j);
	}	
}


main()
{
	char x=-4;
	int i,j;
	printBits(x);
		
	printf("\n");
	
	x=x>>4;
	printBits(x);
	printf("\n %d \n",x);
	
	x=x<<2;
	printBits(x);
	printf("\n %d \n",x);
	
}



