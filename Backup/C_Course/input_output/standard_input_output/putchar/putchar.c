/*
 
Purpose	: Program to demonstrate the 'putchar' function.
  	    The prog will read data entered via the keyboard. And sends the data to console 
	    entered. 
Author	: Team  Veda
Usage 	: putchar(int);
Version	: 1.0
 
*/

#include <stdio.h>


main()
{
  char ch;
  puts("Please enter some text.");
  while ( ch != '\n') 
  {
	ch = getchar();
	putchar(ch);
  }
}
